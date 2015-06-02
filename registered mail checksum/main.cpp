#include <iostream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int main()
{
    bool result = false;
    
    const int multipliers[] = {8, 6, 4, 2, 3, 5, 9, 7};
    const int denominator = 11;
    const int minuend = 11;
    
    cout << "Please enter tracking number for Deutsche Post registered mail: ";
    //string input = "RR473124829DE113";
    string input;
    cin >> input;
    if (input.size() < 13)
    {
        cout << "A valid tracking number consists of a minimum of 2 letters followed by 9 digits followed by a 2 letter country code!" << endl;
        result = false;
    }
    else
    {
        const string digits = input.substr (2,8);
        
        if (digits.size() != 8 ||
            digits.find_first_not_of("0123456789") != std::string::npos ||
            !isdigit(input[10]))
        {
            cout << "Char 3 to 11 must be digits for a valid tracking number!" << endl;
            result = false;
        }
        else
        {
            int digits_array[8];
            const int checkdigit = input[10] - '0';
        
            int sum = 0;
            int remainder_as_subtrahend;
            int difference;
            int calculated_checkdigit;
            
            for(std::string::size_type i = 0; i < digits.size(); ++i) {
                digits_array[i] = digits[i] - '0';
                sum += digits_array[i] * multipliers[i];
            }
            
            remainder_as_subtrahend = sum % denominator;
            
            difference = minuend - remainder_as_subtrahend;
            
            switch(difference){
                case 10 :
                   calculated_checkdigit = 0;
                   break;
                case 11 :
                   calculated_checkdigit = 5;
                   break;
                default :
                   calculated_checkdigit = difference;
            }
            
            result = calculated_checkdigit == checkdigit;
        }
    }
    
    cout << (result == true ? "Check passed." : "Check failed!") << endl;
}