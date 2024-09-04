#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include "Admin.h"
#include "Client.h"
#include "Person.h"
#include "Validation.h"
#include <vector>
#include <fstream>
#include <sstream>
#include "Parser.h"

using namespace std;
class FilesHelper{
public:
	static void saveLast(string& fileName,int id) {
		ofstream file(fileName, ios::out);
		if (!(file.is_open())) {
			cout << "Error";
		}
		else {
			file << id<<endl;
		}
	
	}

	static int getLast(string& fileName) {

		ifstream file(fileName, ios::in);
		if (!file.is_open() || file.peek() == ifstream::traits_type::eof()) {
			std::cerr << "Error: File is empty or cannot be opened." << std::endl;
			return -1;
		}

		string line;
		int id;
		while (getline(file, line)) {
			 id = stoi(line);
		}
		return id;
	}

	static void saveClient( Client& s) {
		ofstream file("Client.txt",ios::app);
		if (!file.is_open()) {
			std::cerr << "Error" << std::endl;
			return;
		}
		
			file << s.getId() << "&" << s.getName() << "&" << s.getPassword() << "&" << s.getBalance() << endl;
		
			file.close();
	}

	static void saveEmployee(string fileName, string lastIdFile, Employee& e) {
		saveLast(lastIdFile, e.getId());
		ofstream file(fileName, ios::app);
		if (!file.is_open()) {
			std::cerr << "Error" << std::endl;
			return;
		}

		file << e.getId() << "&" << e.getName() << "&" << e.getPassword() << "&" << e.getSalary() << endl;

		file.close();
	}


	vector <Client> getClient(string& client) {
		ifstream file("Client.txt");
		vector <Client> clients;
		string line;
		if (!file.is_open()) {
			cerr << "Error: Could not open Client.txt file." << endl;
			return clients;
		}
		while (getline(file, line)) {
			Client client = Parser::parseToClient(line);
			clients.push_back(client);
		}
		return clients;
	}

	vector<Employee> getAdmin(string& admin) {
		ifstream file("Admin.txt");
		vector<Employee> admins;
		if (!file.is_open()) {
			cerr << "Error: Could not open Client.txt file." << endl;
			return admins;
		}
		string line;
		while (getline(file, line)) {
			Admin admin = Parser::parseToAdmin(line);
			admins.push_back(admin);
		}
		return admins;
	}

	vector<Employee> getEmployee(string& employee) {
		ifstream file("Employee.txt");
		vector<Employee> employees;
		if (!file.is_open()) {
			cerr << "Error: Could not open Client.txt file." << endl;
			return employees;
		}
		string line;
		while (getline(file, line)) {
			Employee employee = Parser::parseToEmployee(line);
			employees.push_back(employee);
		}
		return employees;
	}

	static void clearFile(string fileName, string lastIdFile) {
		ofstream file(fileName, ios::out| ios::trunc);
		if (!file.is_open()) {
			cout << "Error: Could not clear file" << endl;
			return;
		}
		file.close();


		ofstream lastid(lastIdFile, ios::out | ios::trunc);
		if (!file.is_open()) {
			cout << "Error: Could not clear file" << endl;
			return;
		}
		lastid.close();
	}
};
