#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int main ( int argc, char *argv[] )
{
    unsigned long maxnumber = 0;

    if ( 2 == argc )
        maxnumber = atol(argv[1]);
    else
    {
        cout << "Enter the highest number to test: ";
        cin >> maxnumber;
    }



    // Create the sieve end initialize all numbers as prime (true)
    bool *numbers = new bool[maxnumber+1];
    for ( unsigned long n = 0; n<=maxnumber; ++n )
        numbers[n] = true;

    // Set 0 and 1 as not-prime
    numbers[0] = false;
    numbers[1] = false;

    // Lets count the found primes
    unsigned long count = 0;

    for ( unsigned long n = 2; n<=maxnumber; ++n )
    {
        if ( numbers[n] )
        {
            // We found a new prime
            cout << n << " " << endl;

            // Count it
            ++count;

            // Delete all multiples
            for ( unsigned long m = 2*n; m<=maxnumber; m+=n )
                numbers[m] = false;
        }
    }
    cout << endl;
    cout << "We found " << count << " primes." << endl;

    delete [] numbers;

    return 0;
}
