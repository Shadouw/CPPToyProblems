/*
 * Knight's-Tour
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;

// Rows:             0 -  7
// Columns:          0 -  7
int aCheckBoard[8][8] = { 0 };

void printboard ()
{
    static int solution = 0;

    cout << "Solution #" << ++solution << endl;

    for ( int row=0; row<8; ++row )
    {
        for ( int column=0; column<8; ++column )
            cout << setw(3) << aCheckBoard[row][column];
        cout << endl;
    }
    cout << endl;

    return;
}

void addKnight ( int number, int row, int column )
{
    assert ( 0<=row    && row<=7    );
    assert ( 0<=column && column<=7 );

    // A night can jump to one of eight fields from its current position:
    //   -2 -1  0  1  2
    // -2    x     x       -2/-1  -2/1
    // -1 x           x    -1/-2  -1/2
    //  0       X
    //  1 x           x     1/-2   1/2
    //  2    x     x        2/-1   2/1

    for ( int r = -2; r <= +2; ++r )
    {
        if ( 0 == r || row+r < 0 || row+r > 7 )
            continue;

        for ( int c = -2; c <= +2; ++c )
        {
            if ( 0 == c || column+c < 0 || column+c > 7 || abs(r)==abs(c) )
                continue;

            // Is the field r/c one the knight not entered so far?
            if ( 0 == aCheckBoard[row+r][column+c] )
            {
                aCheckBoard[row+r][column+c] = number + 1;

                // Is it the last queen in last row?
                if ( 64 == number+1 )
                    printboard ();
                else
                    addKnight ( number+1, row+r, column+c );

                aCheckBoard[row+r][column+c] =  0;
            }
        }
    }

}

int main()
{
    // Start with the first knight
    for ( int row=0; row<8; ++row )
        for ( int column=0; column<8; ++column )
        {
            aCheckBoard[row][column] = 1;
            addKnight ( 1, row, column );
            aCheckBoard[row][column] = 0;
        }


    return 0;
}
