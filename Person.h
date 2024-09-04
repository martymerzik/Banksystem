#include <iostream>
#include <string>
#include "Validation.h"
using namespace std;
class Person{
protected:
    int id;
    string name, password;
public:
    //*construct
    Person() {
        id = 0;
    }
    Person(int id, string name, string password) {
        this->id = id;
        if (Validation::validationname(name))
            this->name = name;
        else cout << "invalid name\n";

        if (Validation::validationpassowrd(name))
            this->password = password;
        else cout << "invalid password\n";
    }
    //*setters
    void setName(string name) {
        if (Validation::validationname(name))
            this->name = name;
        else cout << "invalid name\n";
    }
    void setPassword(string password) {
        if (Validation::validationpassowrd(name))
            this->password = password;
        else cout << "invalid password\n";
    }
    void setId(int id) {
        this->id = id;
    }
    //*getters
    string getName() {
        return this->name;
    }
    string getPassword() {
        return this->password;
    }
      int  getId() {
        return this->id;
    }

    //*methods

    void Display() {
        cout << "name       :" << getName << endl;
        cout << "Id         :" << getId << endl;
        cout << "Password   :" << getPassword << endl;

    }


};
