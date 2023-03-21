// C++ Code Challenges, LinkedIn Learning

// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.
bool is_palindrome(std::string str){

    bool success = false;
    if (str.length() != 0)
    {
        if (str.length() == 1)
        {
            success = true;
        }
        else
        {
            //remove spaces
            str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());

            //convert to lower case
            std::transform(str.begin(), str.end(), str.begin(), tolower);

            //check if palindrome 
            for (int i = 0; i < str.length(); i++)
            {
                if (str.substr(str.length()-i-1, 1) == str.substr(i, 1))
                {
                    success = true;
                }
                else
                {
                    success = false;
                    break;
                }
            }
        }
    }
    return success;
}

// Main function
int main(){
    std::string s;
    std::string finish;
    while(true)
    {
        std::cout << "Enter a string: " << std::flush;
        std::getline(std::cin,s);
        std::cout << "\n\"" << s << (is_palindrome(s) ? "\" is" : "\" is not" ) << " a palindrome.\n\n";

        std::cout << "Continue? y or n: " << std::flush;
        std::getline(std::cin,finish);
        if (finish == "n")
        {
            break;
        }
    }
    return 0;
}
