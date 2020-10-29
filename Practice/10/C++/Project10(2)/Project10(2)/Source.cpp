#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	long long s, l1, r1, l2, r2, x;
	cout << "¬ведите 5 целых чисел s, l1, r1, l2, r2 \n";
	cin >> s >> l1 >> r1 >> l2 >> r2;
	if (r1 + r2 < s and l1 + l2 > s)
		cout << "-1";
	else if (l1 + r2 == s)
		cout << l1 << " " << r2;
	else if (l1 + r2 < s) {
		x = s - (l1 + r2) + l1;
		cout << x << " " << r2;
	}
	else if (l1 + r2 > s) {
		x = s - (l1 + r2) + r2;
		cout << l1 << " " << x;
	}
	else cout << "-1";

}