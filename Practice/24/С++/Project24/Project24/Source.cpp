#include <iostream>
#include "json.hpp"
#include <fstream>
#include <iomanip>
using namespace std;
using json = nlohmann::json;
int main() {
	ifstream input("in.json");
	json inj;
	input >> inj;
	int ftask, UserList = 10;
	json outj = json::array();
	
	for (int i = 1; i <= UserList; i++) {
		ftask = 0;
		for (int k = 0; k < inj.size(); k++) {
			if (inj[k]["completed"] == true and inj[k]["userId"] == i)
				ftask++;
		}
		json push;
		push["task_completed"] = ftask;
		push["userId"] = i;
		outj.push_back(push);
	}
	ofstream output("out.json");
	output <<setw(1) << outj << endl;



}

