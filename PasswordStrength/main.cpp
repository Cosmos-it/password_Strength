//
//  main.cpp
//
//  Created by Taban Cosmos on 12/8/16.
//  Copyright © 2016 Taban Cosmos. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <math.h>



void passwordProcessor(const std::string password);
int processPassword(const std::regex& digits, int digitSum,
                    const std::regex& lowerLetters, const std::regex& upperLetters,
                    const std::regex& specialCharacters, std::string& s, int& letterSum,
                    int& upperLettersSum, int& specialCharacterSum);

int main(int argc, const char * argv[])
{
    const int size = 9;
    std::string password;
    
    do {
        std::cout << "Enter a password with digits, "
        "\nupper or lower-case and a character\n";
        std::cout << "\nTo quit enter (alt z)\n\n:";
        
        getline(std::cin, password);
        
        if (password.compare("Ω")) {

        }
        
        if (password.length() > 1) {
            long spaces = password.find_first_of(' ');
            
            //Return error if there is a space.
            if (spaces == -1 && password.length() <= size && password.length() > 4)
            {
                passwordProcessor(password);
            }
            else
            {
                std::cout << "Characters must be 10 charactors long!\n\n";
            }
 
        }
   
 
    } while (password.compare("Ω"));
    std::cout << "Program ended";
    
    return 0;
    
}

void passwordProcessor(const std::string password)
{
    std::string passwordStr = password;
    std::regex digits("[0-9]");
    std::regex lowerLetters("[a-z]");
    std::regex upperLetters("[A-Z]");
    std::regex specialCharacters("[^$.*+?&#@_-!=]");
    
    auto length = passwordStr.length();
    int digitSum = 0;
    int letterSum = 0;
    int upperLettersSum = 0;
    int specialCharacterSum = 0;
    int total = 0;
    long result = 0;
    
    digitSum = processPassword(digits, digitSum, lowerLetters, upperLetters,
                               specialCharacters, passwordStr, letterSum, upperLettersSum,
                               specialCharacterSum);
    
    std::cout << "\nLength: " << passwordStr.length();
    std::cout << "\nDigit total: " << digitSum;
    std::cout << "\nLower letter total: " << letterSum;
    std::cout << "\nUpper letter: " << upperLettersSum;
    std::cout << "\nSpecial character total: " << specialCharacterSum;
    std::cout << "\nEntire sum: " << (total = digitSum + letterSum + specialCharacterSum + upperLettersSum);
    std::cout << "\nFinal results: " << (result = pow(total, length));
    std::cout << "\n\nEOP\n";

}


int processPassword(const std::regex& digits, int digitSum,
                    const std::regex& lowerLetters, const std::regex& upperLetters,
                    const std::regex& specialCharacters, std::string& passwordStr, int& letterSum,
                    int& upperLettersSum, int& specialCharacterSum)
{
    for (std::sregex_iterator i = std::sregex_iterator(passwordStr.begin(), passwordStr.end(),
                                                       digits); i != std::sregex_iterator(); ++i) {
        std::smatch match = *i;
        auto result = match.str();
        if (match.str().length() % 2 > 0) {
            digitSum = 10;
//            std::cout << std::stoi(result) << " at position " << match.position()
//            << '\n';
        }
    }
    for (std::sregex_iterator i = std::sregex_iterator(passwordStr.begin(), passwordStr.end(),
                                                       lowerLetters); i != std::sregex_iterator(); ++i) {
        std::smatch match = *i;
        auto result = match.str();
        if (match.str().length() % 2 == 1) {
            letterSum = 26;
//            std::cout << match.str() << " at position " << match.position() << '\n';
        }
    }
    for (std::sregex_iterator i = std::sregex_iterator(passwordStr.begin(), passwordStr.end(),
                                                       upperLetters); i != std::sregex_iterator(); ++i) {
        std::smatch match = *i;
        auto result = match.str();
        if (match.str().length() % 2 == 1) {
            upperLettersSum = 26;
//            std::cout << match.str() << " at position " << match.position() << '\n';
        }
    }
    for (std::sregex_iterator i = std::sregex_iterator(passwordStr.begin(), passwordStr.end(),
                                                       specialCharacters); i != std::sregex_iterator(); ++i) {
        std::smatch match = *i;
        auto result = match.str();
        if (match.str().length() % 2 > 0) {
            specialCharacterSum = 33;
//            std::cout << match.str() << " at position " << match.position() << '\n';
        }
    }
    return digitSum;
}












