#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>

using namespace std;

void CheckVowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        cout << "Character " << ch << " is a vowel." << endl; 
    }
    else
    {
        cout << "Character " << ch << " is not a vowel." << endl; 
    }
}


int main()
{
    char x = 0;
    cout << "Enter a character: " << endl;
    cin >> x;
    x = std::tolower(x); /* Make sure it's lower case */
    CheckVowel(x);
}