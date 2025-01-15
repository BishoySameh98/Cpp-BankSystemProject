#pragma once
#include "FilesHelper.h"
#include "FileManager.h"

class ClientManager
{
private:
    static void DisplayClientMenu() {
        cout << "1.Check Balance\n";
        cout << "2.Withraw\n";
        cout << "3.Deposit\n";
        cout << "4.Transfer Amount\n";
        cout << "5.Edit Password\n";
        cout << "6.Display Information\n";
        cout << "7.Back to Client Menu\n";
        cout << "8.Logout\n";
    }
public:

    static void updatePassword(Person* person) {

        string newPass;
        cout << "Please Enter new Password : ";
        getline(cin, newPass);
        person->setPassword(newPass);
        cout << "\nPassowrd Updated Successfully!\n";

    }
    static Client* ClientLogin(int id, string password) {

        for (clIt = AllClients.begin(); clIt != AllClients.end(); clIt++) {
            if (clIt->getId() == id) return clIt._Ptr;
        }
        return NULL;
        cout << "Client not found!" << endl;


    }

    static void back(Client* client) {
        system("pause");
        clientOptions(client);
    }

    static bool clientOptions(Client* client) {

        DisplayClientMenu();

        int option;
        cout << "\nPlease Choose an Option: ";
        cin >> option;

        Employee employee;
        double amount;

        FileManager F;

        switch (option) {

        case 1:
            system("cls");
            client->CheckBalance();
            break;
        case 2:
            system("cls");
            cout << "\nPlease Enter the Amount: ";
            cin >> amount;
            client->withdraw(amount);
            F.updateClient();
            break;
        case 3:
            system("cls");
            cout << "\nPlease Enter the Amount: ";
            cin >> amount;
            client->deposit(amount);
            F.updateClient();
            break;
        case 4:
            system("cls");
            cout << "\nPlease Enter the Recipient ID:";
            int id;
            cin >> id;
            while (employee.searchClient(id) == NULL) {
                cout << "Invalid ID\n";
                cout << "Please Enter a Valid ID: ";
                cin >> id;
            }
            cout << "\nPlease Enter the Amount: ";
            cin >> amount;
            client->transferTo(*employee.searchClient(id), amount);
            F.updateClient();
            break;

        case 5:
            system("cls");
            updatePassword(client);
            F.updateClient();
            break;
        case 6:
            system("cls");
            client->DisplayInfo();
            break;
        case 7:
            system("cls");
            back(client);
            break;
        case 8:
            system("cls");
            return false;
            break;
        default:
            system("cls");
            cout << "\nPlease Enter a Number Exists in the Menu!\n";
            clientOptions(client);
            break;
        }
        char flag = 'y';
        if (flag == 'y' || flag == 'Y') {
            cout << "\nDo you Want Another Operation?(Y/N)\n";
            cin >> flag;
            system("cls");
            if (flag == 'y' || flag == 'Y') {
                clientOptions(client);
            }
            else {
                return false;
            }
        }
        return true;

    }

};

