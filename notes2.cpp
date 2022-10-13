/// @author Austin Simpson
/// @date 2022-10-12
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
    // variables
    int nu = 0;
    int k = 0;
    double frequency;
    double wavelength;

    //fixed
    string noteName[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

    // print the table
    cout << endl;
    cout << "Reference Frequency: " << C0 << " Hz" << endl;
    cout << "Speed of Sound: " << SPEED_OF_SOUND << " m/s" << endl;
    


    // Note: C0
    nu = 0;
    k = 0;

    for(nu = 0; nu < 9; nu++){
        cout << endl << "Octave " << nu << endl;
        for(k = 0; k < 12; k++){
            cout << "Note: " << setw(2) << noteName[k] << nu << "  ";
            printInfo(nu, k);
        }
    }
    cout << endl;
    return 0;
}

void printInfo(int nu, int k){
    double frequency = calculateFrequency(nu, k);
    double wavelength = calculateWavelength(frequency);

    // cout << "nu: " << nu << ";  k: " << k << ";  Frequency (Hz): " << setPrecision() << frequency << "; Wavelength (cm): " << wavelength << ";\n";
    cout << right << setw(5) << "nu: " << nu << ";";
    cout << right << setw(6) << "k: " << setw(2) << k << ";";
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