//
//  passwordChecker.cpp
//  Password Checker
//
//  Created by Faizan Bhagat on 12/16/21.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool checkSpecialCharacters(int minChar, string password);
bool checkLength(int minChar, string password);
bool checkCapitals(int minCap, string password);
bool checkNumbers(int minNum, string password);
void printValidity(int minChar, int minLen, int minCap, int minNum, int minLower, string password);

int main() {
    int minLength;
    int minSpecialCharacters;
    int minCapital;
    int minNumbers;
    int minLowercase;
    
    string userPassword;
    
    ifstream ins;
    ins.open("sample.txt");
    if (!ins.is_open()){
        cout << "File not opened correctly";
        exit(0);
    }
    
    cout << "Hello, welcome to the password strength checker" << endl <<  "-----------------------------------------------" << endl << endl;
    
    cout << "What is the minimum length for your password: ";
    cin >> minLength;
    cout << endl << endl;
    
    cout << "What is the minimum number of special characters for your password: ";
    cin >> minSpecialCharacters;
    cout << endl << endl;
    
    cout << "What is the minimum number of capital characters for your password: ";
    cin >> minCapital;
    cout << endl << endl;
    
    cout << "What is the minimum number of lowercase characters for your password: ";
    cin >> minLowercase;
    cout << endl << endl;

    cout << "What is the minimum number of numbers for your password: ";
    cin >> minNumbers;
    cout << endl << endl;
    
    cout << "******************************************************************************";
    cout << endl << endl;
    
    getline(ins, userPassword);
    
    while (!ins.eof()){
        printValidity(minSpecialCharacters, minLength, minCapital, minNumbers, minLowercase, userPassword);
        getline(ins, userPassword);
    }
    
    cout << "Thanks for using the password checker!" << endl << endl;
    
    return 0;
}

bool checkSpecialCharacters(int minChar, string password){
    string allSpecialCharacters = "~`! @#$%^&*()_-+={[}]|:;'<,>.?/";

    bool returnVal = false;
    int numSpecial = 0;
    
    for (int i = 0; i < password.size(); i++){
        for (int j = 0; j < allSpecialCharacters.size(); j++){
            if (password.at(i) == allSpecialCharacters.at(j)){
                numSpecial++;
            }
        }
    }
    if (numSpecial >= minChar){
        returnVal = true;
    }
    
    return returnVal;
}

bool checkLength(int minLen, string password){
    bool returnVal = false;
    
    if (password.size() >= minLen){
        returnVal = true;
    }
    
    return returnVal;
}

bool checkCapitals(int minCap, string password){
    bool returnVal = false;
    int numCaps = 0;
    
    for (int i = 0; i < password.size(); i++){
        if (isupper(password.at(i))){
            numCaps++;
        }
    }
    
    if(numCaps >= minCap){
        returnVal = true;
    }
    return returnVal;
}

bool checkNumbers(int minNum, string password){
    bool returnVal = false;
    int numNums = 0;
    
    for (int i = 0; i < password.size(); i++){
        if (isdigit(password.at(i))){
            numNums++;
        }
    }
    
    if(numNums >= minNum){
        returnVal = true;
    }
    return returnVal;
}

bool checkLowercase(int minLower, string password){
    bool returnVal = false;
    int numLower = 0;
    
    for (int i = 0; i < password.size(); i++){
        if (islower(password.at(i))){
            numLower++;
        }
    }
    
    if(numLower >= minLower){
        returnVal = true;
    }
    return returnVal;
}

void printValidity(int minChar, int minLen, int minCap, int minNum, int minLower, string password){
    bool allTrue = true;
    
    cout << "Running tests for password: " << password << endl << "----------------------------------------------------------------" << endl;
    
    string errorMessages[5] = {"Failed special characters test, password must have at least " + to_string(minChar) + " special characters.",
                               "Failed length test, password must be at least " + to_string(minLen) + " characters.",
                               "Failed capital test, password must hvae at least " + to_string(minCap) + " capital letters.",
                               "Failed numbers test, password must have at least " + to_string(minNum) + " numbers.",
                               "Failed lowercase test, password must have at least " + to_string(minLower) + " lowercase letters."
    };
    
    string allTrueMessage = "All tests passed, successful password!";
    
    bool allTests[5] = {checkSpecialCharacters(minChar, password),
                        checkLength(minLen, password),
                        checkCapitals(minCap, password),
                        checkNumbers(minNum, password),
                        checkLowercase(minLower, password)};
    
    for (int i = 0; i < 5; i++){
        if (allTests[i] == false){
            allTrue = false;
        }
    }
    
    if (allTrue){
        cout << allTrueMessage << endl;
    }
    else {
        for (int j = 0; j < 5; j++){
            if (allTests[j] == false){
                cout << errorMessages[j] << endl;
            }
        }
    }
    cout << endl << endl;
}

