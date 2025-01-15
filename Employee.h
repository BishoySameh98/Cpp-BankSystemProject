#pragma once
#include"Client.h"
#include "Person.h"

class Employee :
    public Person
{

protected:
    double salary;

public:

    // Constructors:
    Employee() : Person() {
        this->salary = 5000.0;
    }

    Employee(string name, int id, string password, double salary) : Person(name, id, password) {
        setSalary(salary);

    }

    // Setters:
    void setSalary(double salary) {
        if (Validation::validSalary(salary)) {
            this->salary = salary;

        }
        else {
            cout << "Min salary is 5000 " << endl;
            cout << "Please Enter Valid salary " << endl;
            double new_salary;
            cin >> new_salary;
            setSalary(new_salary);
        }

    }

    // Getters:
    double getSalary() {
        return this->salary;
    }

    // Methods:
    void DisplayInfo() override {
        cout << "Name : " << this->getName() << endl;
        cout << "Id : " << this->getId() << endl;
        cout << "Salary = " << this->getSalary() << endl;
        cout << "==============================\n";
    }

    void checkSalary() {
        cout << "Salary = " << this->getSalary() << endl;

    }

    void addClient(Client& client) {

        AllClients.push_back(client);
        cout << "Client added successfully!" << endl;
    }

    Client* searchClient(int id) {
        for (clIt = AllClients.begin(); clIt != AllClients.end(); clIt++) {
            	if (clIt->getId() == id) return clIt._Ptr;
           	}
            return NULL;
        cout << "Client not found!" << endl;
        
    }

    void listClients() {
        for (auto clIt = AllClients.begin(); clIt != AllClients.end(); clIt++) {
            clIt->DisplayInfo();
        }
    }

    void editClient(string name, int id, string password, double balance) {

        Client* clientToEdit = searchClient(id);

        if (clientToEdit != nullptr) {
            clientToEdit->setName(name);
            clientToEdit->setPassword(password);
            clientToEdit->setBalance(balance);
            cout << "Client information updated successfully!" << endl;
        }

        else {
            cout << "Client with ID " << id << " not found!" << endl;
        }

    }

};

static vector <Employee> AllEmployees;
static vector <Employee>::iterator eIt;