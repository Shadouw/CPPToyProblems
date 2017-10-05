#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int main ( int argc, char *argv[] )
{
    assert ( argc == 2 );
    unsigned long maxnumber = atol(argv[1]);

    // Store all numbers in an array
    unsigned long *numbers = new unsigned long[maxnumber+1];
    for ( unsigned long n = 0; n<=maxnumber; ++n )
        numbers[n] = n;

    // Since we cannot easily delete positions I use 0 for a deletion.
    // Delete 1
    numbers[1] = 0;

    // Lets count the primes
    unsigned long count = 0;

    for ( unsigned long n = 2; n<=maxnumber; ++n )
    {
        if ( 0 != numbers[n] )
        {
            // We found a new prime
            cout << n << " ";

            // Count it
            if ( ++count % 10 == 0 )
                cout << endl;

            // Delete all multiples
            for ( unsigned long m = 2*n; m<=maxnumber; m+=n )
                numbers[m] = 0;
        }
    }
    cout << endl;
    cout << "We found " << count << " primes." << endl;

    delete [] numbers;

    return 0;
}
