#pragma once
#include<iostream>
#include<string>
#include<regex>
using namespace std;

class Validation

{
public:
    static bool validateName(string& name) {
        regex Name("^[a-zA-Z]{5,20}$");

        if (!regex_match(name, Name)) {
            return false;
        }
        else {
            return true;
        }
    }

    static bool validatePassword(string& password) {
        regex Password("^[^\\s]{8,20}$");

        if (!regex_match(password, Password)) {
            return false;
        }
        else {
            return true;
        }
    }

    static bool validBalance(double balance) {
        if (balance < 1500) {
            return false;
        }
        else {
            return true;
        }
    }

    static bool validSalary(double salary) {
        if (salary < 5000) {
            return false;
        }
        else {
            return true;
        }
    }

};

