#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

using namespace std;

double approximate(int k);
int main()
{
    double pi = 0;
    int k = 0;

    cout << "Please enter a non-negative integer upper limit of summation for the Leibnitz formula for computing pi:\n";
    cin >> k;

    pi = approximate(k);
    cout << setprecision(DBL_DIG);
    cout << "PI (approx): " << pi << "; n: " << setw(7) << k << endl;
    cout << "PI (actual): " << "3.141592653589793" << endl;
    cout << "Decimal digits of precision: " << DBL_DIG << endl;
    cout << "Number of base 2 mantissa digits of double precision floating point value: "
         << DBL_MANT_DIG << endl;
    cout << "Next representable number from 3.141592653589793: "
         << nextafter(3.141592653589793, 3.14) << endl;
    
    return 0;
}

double approximate(int k){
    double pi = 0;
    for (int i = 0; i < k; i++){
        pi += pow(-1, i) / (2 * i + 1);
    }
    return pi * 4;
}