#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void out(vector<int> type1) {
	int n = type1.size();
	for (int i = 0; i < n; i++){
		cout << type1[i] << " ";
	}
	cout << endl;
}

bool Sort1(vector<int> type1, int n, bool check) {
	if (check) {
		for (int i = 0; i < n - 1; i++)
			if (type1[i] > type1[i + 1])
				return false;
	}
	else
		for (int i = 0; i < n - 1; i++)
			if (type1[i] < type1[i + 1])
				return false;
	return true;
}

vector<int> BozoSort(vector <int> type1, int n, bool check = true) {
	int a = 0, random1, random2;

	if (check) {
		while (Sort1(type1, n, check) == false) {
			for (int i = 0; i < n; i++) {
				random1 = rand() % n;
				random2 = rand() % n;
				a = type1[random1];
				type1[random1] = type1[random2];
				type1[random2] = a;
			}
		}
		return type1;
	}

	else {
		while (Sort1(type1, n, check) == false) {
			random1 = rand() % n;
			random2 = rand() % n;
			a = type1[random1];
			type1[random1] = type1[random2];
			type1[random2] = a;
		}
		return type1;
	}
}

vector<int> BozoSort(vector<vector<int>> type2, int n, bool check = true) {
	vector<int> temp;
	for (vector<int> mas : type2) {
		for (int num : mas) {
			temp.push_back(num);
		}
	}
	return BozoSort(temp, n, check);
}

vector<int> BozoSort(int a1, int a2, int a3, bool check = true) {
	vector<int> temp(3);
	temp[0] = a1;
	temp[1] = a2;
	temp[2] = a3;
	return BozoSort(temp, 3, check);
}

int main() {
	srand(time(NULL));
	bool check = true;
	int n, count = 0;
	cin >> n;
	vector <int> type1(n);
	vector <vector<int>> type2(sqrt(n), vector<int>(sqrt(n)));
	for (int i = 0; i < n; i++) {
		cin >> type1[i];
	}
	for (int i1 = 0; i1 < sqrt(n); i1++) {
		for (int i2 = 0; i2 < sqrt(n); i2++) {
			type2[i1][i2] = type1[count];
			count++;
		}
		if (count == n)
			break;
	}
	cout << endl;
	out(BozoSort(type1, n));
	out(BozoSort(type1, n, false));
	out(BozoSort(type2, n));
	out(BozoSort(type2, n, false));
	out(BozoSort(type1[0], type1[1], type1[2]));
	out(BozoSort(type1[0], type1[1], type1[2], false));
}
