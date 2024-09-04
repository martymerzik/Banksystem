#pragma once
#include <iostream>
using namespace std;

class Validation
{
public:
	static bool validationname(string name) {
		if (!(name.size() >= 5 && name.size() <= 20)) {
			cout << "The size of name must be 5 : 20 " << endl;
			return false;
		}


		for (int i = 0; i < name.size(); i++)
		{
			if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z')) {
				return false;
			}
		}
		return true;
	}

	static bool validationpassowrd(string name) {
		if (!(name.size() >= 8 && name.size() <= 20)) {
			cout << "The size of name must be 8 : 20 " << endl;
			return false;
		}
		else
		return true;
	}

	static bool validationbalance(double balance) {
		if (balance < 1500) {
			return false;
		}
		else
			return true;
	}

	static bool validatinsalary(double salary) {
		if (salary < 5000) {
			return false;
		}
		else
			return true;
	
	}
};

