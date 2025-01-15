#pragma once
#pragma once

#include "FileManager.h"
#include "AdminManager.h"
#include "EmployeeManager.h"
#include "ClientManager.h"
#include <iostream>
#include <string>
#include<windows.h> 
#include<chrono>
#include<thread>

using namespace std;


class Screens
{
private:

	static void bankName() {
		cout << "Route Bank" << endl;
		system("Color E4");
		this_thread::sleep_for(chrono::seconds(2));
	}

	static void welcome() {
		system("Color 0e");
		cout << "Welcome to ";
		bankName();
		Sleep(2000);
		system("cls");
		system("Color 2e");
	}

	static void loginOptions() {
		cout << "1.Admin" << endl;
		cout << "2.Employee" << endl;
		cout << "3.Client" << endl;
		cout << "\nLogin as: ";
	}

	static int loginAs() {
		int option;
		do {
			system("cls");
			loginOptions();
			cin >> option;
		} while (option < 1 || option > 3);
		system("cls");
		return option;
	}

	static void invalid(int option) {
		system("cls");
		cout << "\nInvalid ID or Password\n";
		loginScreen(option);
	}

	static void logout() {
		system("cls");
		loginScreen(loginAs());
	}

	static void loginScreen(int option) {
		loginOptions();
		int id;
		string password;
		cout << "\nPlease Enter Your ID: ";
		cin >> id;
		cin.ignore(); // Clear newline character left in input buffer
		cout << "\nPlease Enter Your Password: ";
		getline(cin, password);

		switch (option)
		{
		case 1:
			if (auto admin = AdminManager::login(id, password)) {
				system("cls");
				while (AdminManager::adminOptions(admin));
				logout();
			}
			else {
				invalid(1);
			}
			break;

		case 2:
			if (auto employee = EmployeeManager::login(id, password)) {
				system("cls");
				while (EmployeeManager::employeeOptions(employee));
				logout();
			}
			else {
				invalid(2);
			}
			break;

		case 3:
			if (auto client = ClientManager::ClientLogin(id, password)) {
				system("cls");
				while (ClientManager::clientOptions(client));
				logout();
			}
			else {
				invalid(3);
			}
			break;

		default:
			system("cls");
			loginOptions();
			break;
		}
	}

public:

	static void runApp() {
		FileManager f;
		f.getAllData();
		welcome();
		loginScreen(loginAs());
	}

};


