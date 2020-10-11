#include <iostream>
using namespace std;
int main() {
	int a;
	int b;
	int c;
	cin >> a;
	cin >> b;
	c = a;
	a = b;
	b = c;
	setlocale(LC_ALL, "Russian");
	cout<<"Первый способ:"<<endl  << a << endl << b<<endl<<endl;
	int a1;
	int b1;
		cin >> a1;
		cin >> b1;
		a1 = a1 + b1;
		b1 = a1 - b1;
		a1 = a1 - b1;

		cout << "Второй способ:"<< endl << a1 << endl << b1;






}