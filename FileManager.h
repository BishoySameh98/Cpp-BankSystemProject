#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
class FileManager :
    public DataSourceInterface
{

protected:
    void addClient(Client client) {
        FilesHelper::saveClient(client);
    }
    void addEmployee(Employee employee)
    {
        FilesHelper::saveEmployee("EmployeeData.txt", "EmployeeLastID.txt", employee);
    }
    void addAdmin(Admin admin) {
        FilesHelper::saveEmployee("AdminData.txt", "AdminLastID.txt", admin);
    }
    void getAllClients() {
        FilesHelper::clientFileToVector();
    }
    void getAllEmployees() {
        FilesHelper::employeeFileToVector();
    }
    void getAllAdmins() {
        FilesHelper::adminFileToVector();
    }
    void removeAllClients() {
        FilesHelper::clearFile("ClientData.txt", "ClientLastID.txt");
    }
    void removeAllEmployees() {
        FilesHelper::clearFile("EmployeeData.txt", "EmployeeLastID.txt");
    }
    void removeAllAdmins() {
        FilesHelper::clearFile("AdminData.txt", "AdminLastData.txxt");
    }
public:

    void getAllData() {
        FileManager f;
         f.getAllClients();
         f.getAllEmployees();
         f.getAllAdmins();
    }

    void updateClient() {
        FileManager f;
        f.removeAllClients();
        for (clIt = AllClients.begin(); clIt != AllClients.end(); clIt++) f.addClient(*clIt);
    }
    void updateEmployee() {
        FileManager f;
        f.removeAllEmployees();

        for (eIt = AllEmployees.begin(); eIt != AllEmployees.end(); clIt++) f.addEmployee(*eIt);
        
    }
    void updateAdmin() {
        FileManager f;
        f.removeAllAdmins();
        for (auto& AdminIt : AllAdmins) {
            addAdmin(AdminIt);
        }
    }

};

