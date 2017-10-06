/*
 * Check-Prime
 *
 */

#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int main ( int argc, char *argv[] )
{
    assert ( argc == 2 );
    long number = atol(argv[1]);

    for ( long i=2; i<sqrt(number); ++i )
    {
        if ( 0 == number%i )
        {
            cout << "Not a prime" << endl;
            return 0;
        }
    }

    cout << "Prime" << endl;

    return 0;
}
