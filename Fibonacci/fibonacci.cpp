/*
 * Fibonacci
 *
 */

#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int main ( int argc, char *argv[] )
{
    unsigned long long maxnumber = 0;

    if ( 2 == argc )
        maxnumber = atol(argv[1]);
    else
    {
        cout << "How many Fibonacci numbers are needed: ";
        cin >> maxnumber;
    }

    // f1 = 1
    // f2 = 1
    // fn = fn-1 + fn-2

    unsigned long long fn  = 0,
                       fn1 = 1,
                       fn2 = 1;

    cout << fn1 << endl << fn2 << endl;


    for ( unsigned long long n = 3; n <= maxnumber; ++n )
    {
        fn = fn1 + fn2;
        cout << fn << endl;

        // shift the numbers
        fn2 = fn1;
        fn1 = fn;
    }

    return 0;
}
