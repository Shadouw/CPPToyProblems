/*
 * Prime Factorization
 *
 */

#include <iostream>


using namespace std;

int main ( int argc, char *argv[] )
{
    unsigned long long number = 0;

    if ( 2 == argc )
        number = atol(argv[1]);
    else
    {
        cout << "Enter a number: ";
        cin >> number;
    }

    // Theory:
    //   Check if division is possible for 2,3..n/2
    //   Break if n > number
    // Remark:
    //   The prime factor of a prime is the prime itself, hence n/2 is a bad upper limit to find prime factors.
    // Practically:
    //   Divide the number by n (if it is dividable), hence reduce upper limit of for-loop

    for ( unsigned long long n = 2; n<=number; ++n )
    {
        while ( number % n == 0 )
        {
            cout << n << endl;
            number /= n;
        }
    }

    return 0;
}
