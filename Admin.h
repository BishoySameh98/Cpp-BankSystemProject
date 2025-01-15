#pragma once
#include"Employee.h"

class Admin :
    public Employee
{

public:

    // Constructors:
    Admin() : Employee() {
    }

    Admin(string name, int id, string password, double salary) : Employee(name, id, password, salary) {

    }

    // Methods:
    void DisplayInfo() {
        cout << "Name : " << this->getName() << endl;
        cout << "Id : " << this->getId() << endl;
        cout << "Salary = " << this->getSalary() << endl;
        cout << "==============================\n";
    }

    Employee* searchEmployee(int id) {
        for (eIt = AllEmployees.begin(); eIt != AllEmployees.end(); eIt++) {
            if (eIt->getId() == id) return eIt._Ptr;
        }
        return NULL;

        cout << "Employee with id : " << id << " not found!" << endl;
    }

    void addEmployee(Employee& employee) {

        AllEmployees.push_back(employee);
        cout << "Employee added successfully!" << endl;
    }

    void editEmployee(int id, string name, string password, double salary) {

        Employee* employeeToEdit = searchEmployee(id);

        if (employeeToEdit != nullptr) {
            employeeToEdit->setName(name);
            employeeToEdit->setPassword(password);
            employeeToEdit->setSalary(salary);
            cout << "Employee information updated successfully!" << endl;
        }

        else {
            cout << "Client with ID " << id << " not found!" << endl;
        }

    }
    void listEmployees() {
        for (auto eIt = AllEmployees.begin(); eIt != AllEmployees.end(); eIt++) {
            eIt->DisplayInfo();
            cout << "============================\n";
        }
    }

   
};

static vector <Admin> AllAdmins;
