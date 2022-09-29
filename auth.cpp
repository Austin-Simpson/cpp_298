/// @author Austin Simpson
/// @date 2019-02-20
/// @brief This program will authenticate a message

#include <iostream>
#include <string>

using namespace std;

// main function
int main(){

    // PART I
    const int k_iValidCodeChecksum = 5;
    const char k_cAuthenticatorCodeCharacter1 = 'E';
    const char k_cAuthenticatorCodeCharacter2 = 'C';
    const char k_cAuthenticatorCodeCharacter3 = 'A';
    
    char character1;
    char character2;
    char character3;

    string authCode;
    authCode += k_cAuthenticatorCodeCharacter1;
    authCode += k_cAuthenticatorCodeCharacter2;
    authCode += k_cAuthenticatorCodeCharacter3;

    cout << "Enter the first character of the message code:\n";
    cin >> character1;

    cout << "Enter the second character of the message code:\n";
    cin >> character2;

    cout << "Enter the third character of the message code:\n";
    cin >> character3;

    string userCode;
    userCode += character1;
    userCode += character2;
    userCode += character3;
    
    cout << endl;

    cout << "Authenticator Code: " << authCode << endl;
    cout << "Message Code:       " << userCode << endl;

// PART II
    if (k_cAuthenticatorCodeCharacter1 == character1 && k_cAuthenticatorCodeCharacter2 == character2 && k_cAuthenticatorCodeCharacter3 == character3){
        cout << "Message is authentic.\n";
    } else {
        cout << "Message is invalid.\n";
    }


// PART III
    if (authCode == userCode){
        cout << "Concurrence: Message is authentic.\n";
    } else {
        cout << "Concurrence: Message is invalid.\n";
    }


// PART IV

    cout << "Characterization of Message Code\n";
    cout << "--------------------------------\n";

    cout << "ASCII Values of Message Code Characters: " << int(character1) << ", " << int(character2) << ", " << int(character3) << endl;
    cout << "Sum of ASCII values for Message Code Characters: " << int(character1) + int(character2) + int(character3) << endl;


    int checksum = (int(character1) + int(character2) + int(character3)) % 7;

    if (checksum == k_iValidCodeChecksum){
        cout << "Message Code Checksum is valid: 5\n";
    } else {
        cout << "Message Code Checksum is invalid: " << checksum << "; expected: 5\n";
    }    
 
    if(character1 != k_cAuthenticatorCodeCharacter1){
        cout << "First characters do not match: Message: " << character1 << "; Authenticator: " << k_cAuthenticatorCodeCharacter1 << endl;
    }
    if(character2 != k_cAuthenticatorCodeCharacter2){
        cout << "Second characters do not match: Message: " << character2 << "; Authenticator: " << k_cAuthenticatorCodeCharacter2 << endl;
    }
    if(character3 != k_cAuthenticatorCodeCharacter3){
        cout << "Third characters do not match: Message: " << character3 << "; Authenticator: " << k_cAuthenticatorCodeCharacter3 << endl;
    }

    if(userCode < authCode){
        cout << "Message Code is less than Authenticator Code.\n";
    } else if(userCode > authCode){
        cout << "Message Code is greater than Authenticator Code.\n";
    }


    return 0;
}