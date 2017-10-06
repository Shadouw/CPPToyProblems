/*
 * Euclidean Algorithm
 *
 */

#include <iostream>

using namespace std;

int main ( int argc, char *argv[] )
{
    unsigned long long a = 0, b = 0;

    if ( 3 == argc )
    {
        a = atol(argv[1]);
        b = atol(argv[2]);
    }
    else
    {
        cout << "Enter two numbers, a and b: ";
        cin >> a >> b;
    }

    if ( 0 == a )
        cout << b << endl;
    else
        while ( 0 != b )
        {
            if ( a > b )
                a -= b;
            else
                b -= a;
        }

    cout << a << endl;


    return 0;
}
