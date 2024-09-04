#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include "Admin.h"
#include "Client.h"
#include "Person.h"
#include "Validation.h"
#include <vector>
#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include <fstream>

using namespace std;

class FileManager : public DataSourceInterface{
	void addClient(Client& client) {
		FilesHelper::saveClient(client);
	}

	void addAdmin(string fileName, string lastIdFile, Admin& admin) {
		FilesHelper::saveEmployee("Admin", "Adminlastid", admin);

	}

	void addEmplyee(string fileName, string lastIdFile, Employee& Employee) {
		FilesHelper::saveEmployee("Employee", "Employeelastid", Employee);

	}
	vector <Client> getAllClients() {
		string filename = "Client.txt";
	return FilesHelper().getClient(filename);
	}
	vector <Employee> getAllEmployees() {
		string filename = "Employee.txt";
		return FilesHelper().getEmployee(filename);
	}
	vector<Employee> getAllAdmins() {
		string filename = "Admin.txt";
		return FilesHelper().getAdmin(filename);
	}
	void removeAllClients() {
		FilesHelper::clearFile("Client.txt", "Clientlastid.txt");
	}
	void removeAllAdmin() {
		FilesHelper::clearFile("Admin.txt", "Adminlastid.txt");
	}
	void removeAllEmployee() {
		FilesHelper::clearFile("Employee.txt", "Employeelastid.txt");
	}
};

