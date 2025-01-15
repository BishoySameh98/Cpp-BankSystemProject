#pragma once
#include<vector>
#include"Validation.h"

class Person
{
private:
    string name, password;
    int id;

public:
    // Constructors:
    Person() {
        this->id = 0;
    }

    Person(string name, int id, string password) {
        setName(name);
        setId(id);
        setPassword(password);
    }

    // Setters:
    void setName(string name) {
        if (Validation::validateName(name)) {
            this->name = name;
        }
        else {
            cout << "Name is invalid." << endl;
            cout << "Please Enter new valid name : ";
            string new_name;
            cin >> new_name;
            setName(new_name);
        }

    }

    void setPassword(string password) {
        if (Validation::validatePassword(password)) {
            this->password = password;
        }
        else {
            cout << "Password is invalid." << endl;
            cout << "Please Enter new valid Password : ";
            string newPassword;
            cin >> newPassword;
            setPassword(newPassword);
        }

    }

    void setId(int id) {
        this->id = id;
    }

    // Getters:
    string getName() {
        return this->name;
    }

    string getPassword() {
        return this->password;
    }

    int getId() {
        return this->id;
    }

    // Method:
    virtual void DisplayInfo() = 0;

};

