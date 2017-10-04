#include <iostream>
#include <cassert>

using namespace std;

// discs: number of discs
// from:  Where to move from. Valid: 1-3
// to:    Where to move. Valid: 1-3
void towers ( int discs, int from, int to )
{
    assert ( 1 <= from && from <= 3 );
    assert ( 1 <= to   && to   <= 3 );
    assert ( 0 < discs );

    // The game has 3 positions 1-3.
    // We "know" only two positions in the function. The "temp" position is so far unknown.
    // Trick: Sum of positions is 6. Temp is 6-from-to

    int temp = 6 - from - to;

    // Count the moves
    static int steps = 0;

    if ( discs > 1 )
    {
        towers ( discs-1, from, temp );
        cout << "#" << ++steps << " " << from << " to " << to << endl;
        towers ( discs-1, temp, to );
    }
    else
        cout << "#" << ++steps << " " << from << " to " << to << endl;

    return;
}

int main()
{
    // Start with the first queen
    towers ( 8, 1, 2 );

    return 0;
}
