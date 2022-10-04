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

    cout << setprecision(DBL_DIG);
    
    for (int i = 1; i <= 20; i++){
        pi = approximate(i);
        cout << "PI: " << setw(16) << left << setfill('0') << pi << "; n: " << setw(7) << right << setfill(' ') << pow(2,i) << endl;        

    }

    return 0;
}
double approximate(int k){
    double pi = 0;
    k = pow(2, k);
    for (int i = 0; i < k; i++){
        pi += pow(-1, i) / (2 * i + 1);
    }
    return pi * 4;
}