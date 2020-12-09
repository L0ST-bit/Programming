#include <iostream>
#include <vector>
#include <ctime>
using namespace std;



void out(vector<int> Masiv, int n) {
	for (int i = 0; i < n; i++){
		cout << Masiv[i] << " ";
	}
	cout << endl;
}


vector<int> BozoSort(vector <int> type1, int n, bool check = true) {
	int count = 0, random1, random2;
	//Возрастание
	if (check) {
		while (int i = 1) {
			random1 = rand() % n;
			random2 = rand() % n;
			type1[random1] = type1[random2];
			for (int i = 0; i < n-1; i++) {
				if (type1[i] > type1[i+1]) {
					break;
					/*if (count == n-1) {
						i = 0;
						break;
					}*/
				}
				else
					continue;

				

			}
		}
	}
	//Убывание
	else {

	}


	for (int i = 0; i < n; i++) {
		cout << type1[i];
	}

	return type1;
}


int main() {
	srand(time(NULL));
	bool check = true;
	int n;
	cin >> n;
	vector <int> type1(n);
	for (int i = 0; i < n; i++) {
		cin >> type1[i];
		cout << type1[i];
	}
	BozoSort(type1, n, check);
}
