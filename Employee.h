#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Validation.h"
#include "FilesHelper.h"
#include "FileManager.h"
class Employee :public Person{
protected: 
	double salary;
public:
	static vector<Employee>allEmployee;
	Employee() :Person() {
		salary = 0;
	}
	Employee( int id, string name, string password, double salary) : Person(id, name, password) {
		if (Validation::validatinsalary(salary)) {
			this->salary = salary;
		}
		else
			cout << "invalid salary\n";
	}
	void setSalary(double salary) {
		if (Validation::validatinsalary(salary)) {
			this->salary = salary;
		}
		else
			cout << "invalid salary\n";
	}
	double getSalary() {
		return this->salary;
	}

	void display() {
		Person::Display;
		cout << "salary   :" << getSalary<<endl;
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
		if (!(Employee::searchClient(id) == nullptr)) {
			Client::setName;
			Client::setBalance;
			Client::setPassword;
		}
			
	}

};

vector<Employee>allEmployee;

