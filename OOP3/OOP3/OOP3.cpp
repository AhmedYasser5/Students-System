// OOP3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS		//To operate something can't work on VS community
#include <stdc++.h>
using namespace std;


class validate {
public:
	bool isword(string x) {
		for (int i = 0; i < x.size(); i++) {
			if (!isalpha(x[i])) {
				return 0;
			}
		}
		return 1;
	}
	bool isnum(string x) {
		if (x[0] == '0')
			return 0;
		for (int i = 0; i < x.size(); i++) {
			if (!isdigit(x[i])) {
				return 0;
			}
		}
		return 1;
	}
	bool ismobile(string x) {
		if (x.size() != 11) {
			return 0;
		}
		if (!isnum(x.substr(1))) {	//substring
			return 0;
		}
		return 1;
	}
	long long convert_to_num(string x) {
		//1234
		int num = 0;
		for (int i = 0; i < x.size(); i++) {
			num = num * 10 + (x[i] - '0');
		}
	}
};

class worker : public validate {
	//Write them in separate lines:
	string name;
	string username;
	string password;
	long long mobile;
public:
	worker() {
		name = "";
		username = "";
		password = "";
		mobile = 0;
	}

	worker(string& name, string& username, string& password, long long& mobile) {
		name = this->name;
		username = this->username;
		password = this->password;
		mobile = this->mobile;
	}

	int set_data(string name, string username, string password, string mobile) {
		if (isword(name) == 0) {
			return 1;	//name is not valid
		}
		if (ismobile(mobile) == 0) {
			return 2;	//mobile is not valid
		}
		this->name = name;
		this->username = username;
		this->password = password;
		this->mobile = convert_to_num(mobile);
		return 0;	//Data are true
	}

	void get_data(string& name, string& username, string& password, long long& mobile) {
		name = this->name;
		username = this->username;
		password = this->password;
		mobile = this->mobile;
	}

	~worker() {
		this->~worker();
	}	//This is the Destructor
};

class workers : public validate {
private:
	vector<worker> data;
public:
	void add(worker w) {
		data.push_back(w);
	}

	int remove(long long mobile) {
		bool index = -1;
		for (int i = 0; i < data.size(); i++) {
			string name, username, password;
			long long mob;
			data[i].get_data(name, username, password, mob);
			if (mob == mobile) {
				index = i;
				break;
			}
		}
		if (index == -1) {
			return index;
		}
		data.erase(data.begin() + index);
	}

	pair<int, worker> search(string name1 = "", string username1 = "", long long mobile1 = 0) {
		if (name1 != "") {
			int index = -1;
			for (int i = 0; i < data.size(); i++) {
				string name, username, password;
				long long mob;
				data[i].get_data(name, username, password, mob);
				if (name1 == name) {
					index = i;
					break;
				}
			}
			worker ww;
			if (index == -1) {
				return { index, ww };
			}
			return { index, data[index] };
		}
		if (username1 != "") {
			int index = -1;
			for (int i = 0; i < data.size(); i++) {
				string name, username, password;
				long long mob;
				data[i].get_data(name, username, password, mob);
				if (username1 == username) {
					index = i;
					break;
				}
			}
			worker ww;
			if (index == -1) {
				return { index, ww };
			}
			return { index, data[index] };
		}
		if (mobile1 != 0) {
			int index = -1;
			for (int i = 0; i < data.size(); i++) {
				string name, username, password;
				long long mob;
				data[i].get_data(name, username, password, mob);
				if (mobile1 == mob) {
					index = i;
					break;
				}
			}
			worker ww;
			if (index == -1) {
				return { index, ww };
			}
			return { index, data[index] };
		}
	}

	~workers(){
		data.clear();
	}
};



int main()
{
	
	return 0;
}