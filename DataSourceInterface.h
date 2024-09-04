#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include "Admin.h"
#include "Client.h"
#include "Person.h"
#include "Validation.h"
#include <vector>
using namespace std;

class DataSourceInterface{
public:
	virtual void addClient(Client& client) = 0;
	virtual void addEmployee(Employee& employee) = 0;
	virtual void addAdmin(Admin& admin) = 0;
	virtual vector<Client> getAllClients() = 0;
	virtual vector<Employee> getAllEmployees() = 0;
	virtual vector<Employee> getAllAdmins() = 0;
	virtual void removeAllClients() = 0;
	virtual void removeAllAdmin() = 0;
	virtual void removeAllEmployeee() = 0;



};

