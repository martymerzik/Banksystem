#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Validation.h"
#include "Employee.h"
#include "Client.h"
class Admin : public Employee {
private:
	double salary;
public:
	static std::vector<Admin> globalAdminVector;

	Admin(): Employee() {
	}
	Admin( int id, string name, string password,double salary) : Employee( id, name, password, salary) {
	
	}

	void addClient(Client& client) {
		Client::allClients.push_back(client);
	}
	Client* searchClient(int id) {
		for (auto client : Client::allClients) {
			if (client.getId() == id) {
				return &client;
			}
			else
				return nullptr;
		}
	}

	void listClient() {
		for (auto client : Client::allClients) {
			client.Display();
		}
	}

	void editClient(int id, string name, string password, double balance) {
		if (!(searchClient(id) == nullptr)) {
			Client::setBalance;
			Client::setName;
			Client::setPassword;
		}
	}

	void addEmployee(Employee& employee) {
		Employee::allEmployee.push_back(employee);
	}
	Employee* searchEmployee(int id) {
		for (auto employee : Employee::allEmployee) {
			if (employee.getId() == id)
				return &employee;
			else
				return nullptr;
		}

	}

	void editEmployee(int id, string name, string password, double salary) {
		if (!(searchEmployee == nullptr)) {
			Employee::setName;
			Employee::setPassword;
			Employee::setSalary;
		}
	}

	void listEmployee() {
		for (auto employee : Employee::allEmployee) {
			employee.Display();
		}
	}
};

