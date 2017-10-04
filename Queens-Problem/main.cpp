#include <iostream>
#include <cassert>

using namespace std;

// Rows:             0 -  7
// Columns:          0 -  7
// Diagonals NW-SE:  7 - -7  (Row - Column)
// Diagonals SW-NE:  0 - 14  (Row + Column)

// One queen per Row, no array needed
// But: Queen x must know it's row:
int  aQueen[8] = { -1 };

// Column array:
bool aColumns[8] = { false };

// NWSE array:
bool  aNWSEt[15] = { false }; // 15 indexes:  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
bool *aNWSE = &aNWSEt[7];     //             -7 -6 -5 -4 -3 -2 -1  0  1  2  3  4  5  6  7

// SWNE array:
bool aSWNE[15] = { false };

void printboard ()
{
    static int solution = 0;

    cout << "Solution #" << ++solution << endl;

    for ( int row=0; row<8; ++row )
    {
        for ( int column=0; column<8; ++column )
            cout << (aQueen[row]==column ? "*" : ".");
        cout << endl;
    }
    cout << endl;

    return;
}

bool isQueenSave(int row, int column)
{
    // calculate the diagonals
    int nSWNE = row + column;
    int nNWSE = row - column;
    assert (  0<=nSWNE && nSWNE<=14 );
    assert ( -7<=nNWSE && nNWSE<=7  );

    // Is it save to place the queen?
    return ( !aColumns[column] && !aNWSE[nNWSE] && !aSWNE[nSWNE] );
}

void placeQueen(int row, int column)
{
    assert ( 0<=row    && row<=7    );
    assert ( 0<=column && column<=7 );

    // calculate the diagonals
    int nSWNE = row + column;
    int nNWSE = row - column;
    assert (  0<=nSWNE && nSWNE<=14 );
    assert ( -7<=nNWSE && nNWSE<=7  );

    // Place the queen
    aQueen[row]      = column;
    aColumns[column] = true;
    aNWSE[nNWSE]     = true;
    aSWNE[nSWNE]     = true;
}

void freeQueen(int row)
{
    assert ( 0<=row && row<=7  );

    // get queens column
    int column = aQueen[row];
    assert ( 0<=column && column<=7  );

    // calculate the diagonals
    int nSWNE = row + column;
    int nNWSE = row - column;
    assert (  0<=nSWNE && nSWNE<=14 );
    assert ( -7<=nNWSE && nNWSE<=7  );

    // Free the place and everything the queen uses
    aQueen[row]      = -1;
    aColumns[column] = false;
    aNWSE[nNWSE]     = false;
    aSWNE[nSWNE]     = false;
}

void addQueen ( int row )
{
    assert ( 0<=row && row<=7  );

    for ( int column=0; column<8; ++column )
    {
        // Is it save to place the queen?
        if ( isQueenSave(row, column) )
        {
            placeQueen(row, column);

            // Is it the last queen in last row?
            if ( 7 == row )
                printboard ();
            else
                addQueen(row+1);

            freeQueen(row);
        }
    }

}

int main()
{
    // Start with the first queen
    addQueen ( 0 );

    return 0;
}
