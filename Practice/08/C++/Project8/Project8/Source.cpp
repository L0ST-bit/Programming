#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	setlocale(LC_ALL, "Rus");
	cout << "¬ведите пример:\n";
	double a, b, Res;
	char c;
	cin >> a>> c>>b;
	if (c == '*')
		cout << a * b;
	if (c == '+')
		cout << a + b;
	if (c == '-')
		cout << a - b;
	if (c == '/') {
		if (b == 0)
			cout << "ќшибка: ƒеление на ноль";
		else cout << a / b;
	}
}