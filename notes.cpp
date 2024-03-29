/// @author Austin Simpson
/// @date 2022-09-21
/// @brief This program calculates the frequency and wavelengths of various notes

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// constants
static const double SPEED_OF_SOUND = 345.0; // m/s

// this is the reference frequency
static const double C0 = 16.35;

// function prototypes
double calculateFrequency(int nu, int k);
double calculateWavelength(double frequency);
void printInfo(int nu, int k);

int main()
{
    // print the table
    cout << endl;
    cout << "Reference Frequency: " << C0 << " Hz" << endl;
    cout << "Speed of Sound: " << SPEED_OF_SOUND << " m/s" << endl;
    
    // Note: C0
    cout << "Note:  C0;  ";
    printInfo(0, 0);

    // Note: C#0  // nu = 0;  // k = 1;
    cout << "Note: C#0;  ";
    printInfo(0, 1);

    // Note: D0  // nu = 0; // k = 2;
    cout << "Note:  D0;  ";
    printInfo(0, 2);

    // Note: C4  // nu = 4; // k = 0;
    cout << "Note:  C4;  ";
    printInfo(4, 0);

    // Note: D#7  // nu = 7; // k = 3;
    cout << "Note: D#7;  ";
    printInfo(7, 3);

    // Note: C8  // nu = 8; // k = 0;
    cout << "Note:  C8;  ";
    printInfo(8, 0);

    cout << endl;
    return 0;
}

void printInfo(int nu, int k){
    double frequency = calculateFrequency(nu, k);
    double wavelength = calculateWavelength(frequency);

    // cout << "nu: " << nu << ";  k: " << k << ";  Frequency (Hz): " << setPrecision() << frequency << "; Wavelength (cm): " << wavelength << ";\n";
    cout << right << setw(5) << "nu: " << nu << ";";
    cout << right << setw(6) << "k: " << k << ";";
    cout << left << "  Frequency: " << setw(7) << frequency << " Hz;   ";
    cout << right << setw(12) << "Wavelength:  " << wavelength << " cm\n";
}

double calculateFrequency(int nu, int k){
    double frequency = C0 * pow(2, nu) * pow(2, k/12.0);
    return frequency;
}


double calculateWavelength(double frequency)
{
    return 100.0 * SPEED_OF_SOUND / frequency;
}