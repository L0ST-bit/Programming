#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

template<class T>
void out(vector<T> type1) {
	int n = type1.size();
	for (int i = 0; i < n; i++) {
		cout << type1[i] << " ";
	}
	cout << endl;
}

template<class T>
bool Sort1(vector<T> type1, int n, bool check) {
	//int n = type1.size();
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

template<class T>
vector<T> BozoSort(vector <T> type1, int n, bool check = true) {
	int a = 0, random1, random2;
	//int n = type1.size();
	if (check) {
		while (Sort1(type1,n, check) == false) {
			for (int i = 0; i < n; i++) {
				random1 = rand() % n;
				random2 = rand() % n;
				T a = type1[random1];
				type1[random1] = type1[random2];
				type1[random2] = a;
			}
		}
		return type1;
	}

	else {
		while (Sort1(type1,n, check) == false) {
			random1 = rand() % n;
			random2 = rand() % n;
			T a = type1[random1];
			type1[random1] = type1[random2];
			type1[random2] = a;
		}
		return type1;
	}
}

template<class T>
vector<T> BozoSort(vector<vector<T>> type2, bool check = true) {
	//int n = type2.size();
	vector<T> temp;
	for (vector<T> mas : type2) {
		for (T num : mas) {
			temp.push_back(num);
		}
	}
	return BozoSort(temp, check);
}

template<class T>
vector<T> BozoSort(T a1, T a2, T a3, bool check = true) {
	vector<T> temp(3);
	temp[0] = a1;
	temp[1] = a2;
	temp[2] = a3;
	return BozoSort(temp, check);
}


int main() {
	srand(time(NULL));
	bool check = true;
	int n, count = 0;
	cin >> n;
	vector <double> type1(n);
	vector <vector<double>> type2(sqrt(n), vector<double>(sqrt(n)));
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
	int s;
	cin >> s;
	vector <string> type1_S(n);
	vector <vector<string>> type2_S(sqrt(s), vector<string>(sqrt(s)));
	count = 0;
	for (int i = 0; i < n; i++) {
		cin >> type1_S[i];
	}
	for (int i1 = 0; i1 < sqrt(s); i1++) {
		for (int i2 = 0; i2 < sqrt(s); i2++) {
			type2_S[i1][i2] = type1_S[count];
			count++;
		}
		if (count == s)
			break;
	}
	out(BozoSort(type1,n));
	out(BozoSort(type1,n, false));
	out(BozoSort(type2));
	out(BozoSort(type2, false));
	out(BozoSort(type1[0], type1[1], type1[2]));
	out(BozoSort(type1[0], type1[1], type1[2], false));
	out(BozoSort(type1_S,s));
	out(BozoSort(type1_S,s, false));
	out(BozoSort(type2_S));
	out(BozoSort(type2_S, false));
	out(BozoSort(type1_S[0], type1_S[1], type1_S[2]));
	out(BozoSort(type1_S[0], type1_S[1], type1_S[2], false));
}
