#pragma once
#include<fstream>
#include<sstream>
#include<vector>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"

class Parser
{

private:

	//id*name*Password*balance

	static vector<string> split(string line) {

		stringstream ss(line);
		string piece;
		vector<string> data;
		while (getline(ss, piece, '*'))
		{
			data.push_back(piece);
		}
		return data;

	}

public:

	static Client parseToClient(string line) {

		vector<string> data = split(line);
		Client client;
		client.setId(stoi(data[0]));
		client.setName(data[1]);
		client.setPassword(data[2]);
		client.setBalance(stod(data[3]));
		return client;
	}

	static Employee parseToEmployee(string line) {

		vector<string> data = split(line);
		Employee employee;
		employee.setId(stoi(data[0]));
		employee.setName(data[1]);
		employee.setPassword(data[2]);
		employee.setSalary(stod(data[3]));
		return employee;
	}

	static Admin parseToAdmin(string line) {

		vector<string> data = split(line);
		Admin admin;
		admin.setId(stoi(data[0]));
		admin.setName(data[1]);
		admin.setPassword(data[2]);
		admin.setSalary(stod(data[3]));
		return admin;
	}
};

