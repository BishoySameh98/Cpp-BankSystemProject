#pragma once
#include "FilesHelper.h"
#include "FileManager.h"
#include "ClientManager.h"

class EmployeeManager
{
private:
    static void DisplayEmployeeMenu() {

        cout << "1.Display Information\n";
        cout << "2.Check Salary\n";
        cout << "3.Edit Password\n";
        cout << "4.Add New Client\n";
        cout << "5.List All Clients\n";
        cout << "6.Search for a Client\n";
        cout << "7.Edit Client Information\n";
        cout << "8.Back to Employee Menu\n";
        cout << "9.Logout\n";
    }
public:

    static Employee* login(int id, string password) {
        for (eIt = AllEmployees.begin(); eIt != AllEmployees.end(); eIt++) {
            if (eIt->getId() == id) return eIt._Ptr;
        }
        return NULL;

        cout << "Employee with id : " << id << " not found!" << endl;
    }

    static void newClient(Employee* employee) {

        Client client;
        string name;
        cout << "\nPlease Enter Client's Name: ";
        getline(cin,name);

        string password;
        cout << "\nPlease Enter Client's Password: ";
        getline(cin,password);

        double balance;
        cout << "\nPlease Enter Client's Balance: ";
        cin >> balance;

        client.setName(name);
        client.setPassword(password);
        client.setBalance(balance);

        employee->addClient(client);

        FileManager F;
        F.updateClient();
        cout << "\nClient is Added Successfully\n";

    }

    static void listAllClients(Employee* employee) {
        employee->listClients();
    }
    static void searchForClient(Employee* employee) {

        cout << "Please Enter Client ID: ";
        int id;
        cin >> id;
        system("cls");

        if (employee->searchClient(id) == NULL) {
            cout << "\nClient is not Found\n";
        }
        else {
            employee->searchClient(id)->DisplayInfo();
        }
    }

    static void editClientInfo(Employee* employee) {

        int id;
        cout << "Please Enter Client ID: ";
        cin >> id;
        if (employee->searchClient(id) == NULL) {
            cout << "\nClient is not Found!" << endl;
        }
        else {

            string name;
            cout << "\nPlease Enter Your Name: ";
            getline(cin, name);

            string password;
            cout << "\nPlease Enter Your Password: ";
            getline(cin, password);

            double balance;
            cout << "\nPlease Enter Client's Balance: ";
            cin >> balance;

            employee->editClient(name, id, password, balance);
            FileManager F;
            F.updateClient();

            cout << "\nClient Information is Edited Successfully." << endl;
        }
        }

       
    static void back(Employee* employee) {
        system("pause");
        employeeOptions(employee);
    }

    static bool employeeOptions(Employee* employee) {

        DisplayEmployeeMenu();
        cout << "\nPlease Choose an Option: ";
        int option;
        cin >> option;
        FileManager F;
        switch (option)
        {
        case 1:
            system("cls");
            employee->DisplayInfo();
            break;
        case 2:
            system("cls");
            employee->checkSalary();
            break;
        case 3:
            system("cls");
            ClientManager::updatePassword(employee);
            F.updateEmployee();
            break;

        case 4:
            system("cls");
            newClient(employee);
            break;

        case 5:
            system("cls");
            listAllClients(employee);
            break;

        case 6:
            system("cls");
            searchForClient(employee);
            break;

        case 7:
            system("cls");
            editClientInfo(employee);
            break;

        case 8:
            system("cls");
            back(employee);
            break;

        case 9:
            system("cls");
            return false;
            break;

        default:
            system("cls");
            cout << "\nPlease Enter a Number Exists in the Menu!\n";
            employeeOptions(employee);
            break;
        }
        char flag = 'y';
        if (flag == 'y' || flag == 'Y') {
            cout << "\nDo you Want Another Operation?(Y/N)\n";
            cin >> flag;
            system("cls");
            if (flag == 'y' || flag == 'Y') {
                employeeOptions(employee);
            }
            else {
                return false;
            }
        }
        return true;
       
    }
};

