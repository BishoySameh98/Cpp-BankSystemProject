#pragma once
#include<fstream>
#include"Parser.h"
class FilesHelper
{

private:

    static void saveLastID(string lastIDfile, int id) {
        ofstream file(lastIDfile);
        file.open(lastIDfile);
        file << id;
        file.close();
        if (!file.is_open()) {
            cout << "Error, unable to open the file : " << lastIDfile << endl;
        }           

    }

public:

    static int getLastID(string lastIDfile) {
        int id;
        ifstream file(lastIDfile);
        file >> id;
        
        file.close();
        return id;
        if (!file.is_open()) {
            cout << "Error, unable to open the file : " << lastIDfile << endl;
            return -1;
        }

    }
    static void saveClient(Client client) {

        int id = getLastID("ClientLastID.txt");
        fstream file;
        file.open("ClientData.txt", ios::app);
        file << id + 1 << '*' << client.getName() << '*' << client.getPassword() << '*' <<
            client.getBalance() << '\n';
        file.close();
        saveLastID("ClientLastID.txt", id + 1);
    }

    static void saveEmployee(string dataFile, string lastIDfile, Employee employee) {


        int id = getLastID(lastIDfile);
        fstream file;
        file.open(dataFile, ios::app);
        file << id + 1 << '*' << employee.getName() << '*' <<
            employee.getPassword() << '*' << employee.getSalary() <<
            '\n';
        file.close();
        saveLastID(lastIDfile, id + 1);


    }
    static void clientFileToVector() {

        string line;
        ifstream file;
        file.open("ClientData.txt");
        while (getline(file, line)) {
            AllClients.push_back(Parser::parseToClient(line));  //line contain data of client that we will parse it in parser class using * as dalameter
        }
        file.close();
    }

    static void employeeFileToVector() {
        string line;
        ifstream file;
        file.open("EmployeeData.txt");
        while (getline(file, line)) {
            AllEmployees.push_back(Parser::parseToEmployee(line));
        }
        file.close();
    }
    static void adminFileToVector() {
        string line;
        ifstream file;
        file.open("AdminData.txt");
        while (getline(file, line)) {
            AllAdmins.push_back(Parser::parseToAdmin(line));
        }
        file.close();
    }
    static void clearFile(string dataFile, string lastIDfile) {
        fstream clearFile, zeroID;
        clearFile.open(dataFile, ios::out, ios::trunc);
        clearFile.close();
        zeroID.open(lastIDfile, ios::out);
        zeroID << 0;
        zeroID.close();
    }

};

