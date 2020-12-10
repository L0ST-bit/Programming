#include <iostream>
#include <vector>
using namespace std;

void Out(vector<int> signal, int n) {
	if (n > 5) {
		for(int i = n - 5; i <= n-1; i++)
			cout << signal[i] << " ";
		cout << endl;
	}
	else {
		for (int i = 0; i <= n-1; i++)
			cout << signal[i] << " ";
		cout << endl;
	}
}

vector<int> Sort(vector<int> insort , int n) {
	for (int i1 = 0; i1 <= n-1; i1++) {

		for (int i = 0; i < (n-1-i1); i++) {

			if (insort[i] < insort[i + 1]) {
				int a = insort[i];
				insort[i] = insort[i + 1];
				insort[i + 1] = a;
			}
		}
	}
	return insort;
}

int main() {
	int n,count = 0;
	cin >> n;
	vector<int> signal(n);
	vector<int> sorted;
	for (int s = 0; s < n; s++)
		cin >> signal[s];

	for (int i = 0; i < n; i++) {
		count++;
		sorted.push_back(signal[i]);
		sorted = Sort(signal, count);
		Out(sorted, count);
	}
}




