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
class Parser {
public:
    static vector <string> Split(string& line) {
            istringstream iss(line);
            string component;
            vector <string>components;
            while (getline(iss, component, '&')) {
                components.push_back(component);


            }
            return components;
        

    }

    static Client parseToClient(string& line) {
        vector <string> components = Split(line);
        int id = stoi(components[0]);
        string name(components[1]);
        string password(components[2]);
        double salary = stod(components[3]);

        return Client(id,name,password,salary);
    }

    static Employee parseToEmployee(string& line) {
        vector <string> components = Split(line);
        int id = stoi(components[0]);
        string name(components[1]);
        string password(components[2]);
        double salary = stod(components[3]);

        return Employee(id, name, password, salary);
    }

    static Admin parseToAdmin(string& line) {
        vector<string>components = Split(line);
        int id = stoi(components[0]);
        string name(components[1]);
        string password(components[2]);
        double salary = stod(components[3]);

        return Admin(id,name,password,salary);
    }


    


   
};


	
	


