#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	long long s, l1, r1, l2, r2;
	cout << "¬ведите 5 целых чисел s, l1, r1, l2, r2 \n";
	cin >> s >> l1 >> r1 >> l2 >> r2; 
	
	if (l1 + l2 > s or r1 + r2 < s or (r1 < s and s < l2) or (l1 < s and s < l2))
		cout << "-1";

	else if (l1 + l2 >= s)
		cout << s - l2 << " " << l2;

	else if (l1 + r2 >= s)
		cout << s- r2 << " " << r1;

	else if (r1 + l2 >= s)
		cout << s - l2 << " " << l2;

	else if (r1 + r2 >= s)
		cout << s - r2 << " " << r2;




}