#pragma once
#include"Person.h"
#include"EmployeeManager.h"

class AdminManager
{

private:
    static void AdminMenu() {
        cout << "1.Display Information\n";
        cout << "2.Check Salary\n";
        cout << "3.Edit Password\n";
        cout << "4.Add New Employee\n";
        cout << "5.Add New Client\n";
        cout << "6.List All Employees\n";
        cout << "7.List All Clients\n";
        cout << "8.Search for an Employee\n";
        cout << "9.Search for a Client\n";
        cout << "10.Edit Employee Information\n";
        cout << "11.Edit Client Information\n";
        cout << "12.Back to Admin Menu\n";
        cout << "13.Logout\n";
    }
public:

    static void newEmployee(Admin* admin) {

        Employee employee;

        string name;
        cout << "\nPlease Enter Your Name: ";
        getline(cin,name);

        string password;
        cout << "\nPlease Enter Your Password: ";
        getline(cin, password);

        double salary;
        cout << "\nPlease Enter Employee's Balance: ";
        cin >> salary;

        employee.setName(name);
        employee.setPassword(password);
        employee.setSalary(salary);
        admin->addEmployee(employee);
        FileManager F;
        F.updateEmployee();

        cout << "\nEmployee is Added Successfully\n";
    }

    static void listAllEmployees(Admin* admin) {
        admin->listEmployees();
    }

    static void searchForEmployee(Admin* admin) {

        cout << "Please Enter Employee ID:";
        int id;
        cin >> id;
        system("cls");

        if (admin->searchEmployee(id)) {
            admin->DisplayInfo();
        }
        else {
            return;
            admin->searchEmployee(id);
        }

    }
    static void editEmployeeInfo(Admin* admin) {

        cout << "Please Enter Employee ID: ";
        int id;
        cin >> id;
        system("cls");
        if (admin->searchEmployee(id) == NULL) {
            cout << "Employee not found!" << endl;
        }
        else {
            string name;
            cout << "\nPlease Enter Your Name: ";
            cin >> name;

            string password;
            cout << "\nPlease Enter Your Password: ";
            cin >> password;

            double salary;
            cout << "\nPlease Enter Employee's Salary: ";
            cin >> salary;

            admin->editEmployee(id, name, password, salary);
            FileManager F;
            F.updateEmployee();
            cout << "\nEmployee Information is Edited Successfully." << endl;

        }
    }
    static Admin* login(int id, string password) {
        for (auto& AdminIt : AllAdmins) {
            if (AdminIt.getId() == id && AdminIt.getPassword() == password) return &AdminIt;
        }
        cout << "Admin with id : " << id << " not found!" << endl;
        return nullptr;
    }

    static void back(Admin* admin) {
        AdminMenu();
    }

    static bool adminOptions(Admin* admin) {
        AdminMenu();
        cout << "\nPlease Choose an Option: ";
        int option;
        cin >> option;
        FileManager F;
        switch (option)
        {
        case 1:
            system("cls");
            admin->DisplayInfo();
            break;
        case 2:
            system("cls");
            admin->checkSalary();
            break;
        case 3:
            system("cls");
            ClientManager::updatePassword(admin);
            F.updateAdmin();
            break;
        case 4:
            system("cls");
            newEmployee(admin);
            break;
        case 5:
            system("cls");
            EmployeeManager::newClient(admin);
            break;
        case 6:
            system("cls");
            listAllEmployees(admin);
            break;
        case 7:
            system("cls");
            EmployeeManager::listAllClients(admin);
            break;
        case 8:
            system("cls");
            searchForEmployee(admin);
            break;
        case 9:
            system("cls");
            EmployeeManager::searchForClient(admin);
            break;
        case 10:
            system("cls");
            editEmployeeInfo(admin);
            break;
        case 11:
            system("cls");
            EmployeeManager::editClientInfo(admin);
            break;
        case 12:
            system("cls");
            back(admin);
            break;
        case 13:
            system("cls");
            return false;
            break;
        default:
            system("cls");
            cout << "\nPlease Enter a Number Exists in the Menu!\n";
            back(admin);
            break;
        }
        char flag = 'y';
        if (flag == 'y' || flag == 'Y') {
            cout << "\nDo you Want Another Operation?(Y/N)\n";
            cin >> flag;
            system("cls");
            if (flag == 'y' || flag == 'Y') {
                adminOptions(admin);
            }
            else {
                return false;
            }
        }
        return true;
       
    }
};
