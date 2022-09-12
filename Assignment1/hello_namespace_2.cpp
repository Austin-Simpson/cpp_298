/// @file hello_namespace_2.cpp
/// @brief A simple program using cin and cout
/// @author Austin Simpson

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strMessage;
	cout << "Please type a single word message: " << endl;
	cin >> strMessage;
	cout << "Message: " << strMessage << endl;
	return 0;
}