#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Расчеты выводит в следуйщем порядке:\n1)Сложение 2)Вычитание 3)Умножение 4)Деление " <<endl;
	cout << "Введите переменные a, b типа double, double:\n";
	double a;
	double b;
	cin >> a;
	cin >> b;
	double c1 = a + b;
	double c2 = a - b;
	double c3 = a * b;
	double c4 = a / b;
	
	cout << "Переменные типа double, double: \n" << "1)" << c1 << " 2)" << c2 << " 3)" << c3;
	if (b == 0) cout << " 4)" << "Деление на ноль" << endl;
	else cout <<" 4)"<< c4 << endl;
	cout << "Введите переменные типа int, double: \n";
	int z;
	double x;
	cin >> z;
	cin >> x;
	 c1 = z + x;
	 c2 = z - x;
	 c3 = z * x;
	 c4 = z / x;
	 
	 cout << "Переменные типа int, double: \n" << "1)" << c1 << " 2)" << c2 << " 3)" << c3;
	 if (x == 0) cout << " 4)" << "Деление на ноль" << endl;
	 else cout <<" 4)"<< c4 << endl;
	cout << "Введите переменные типа double, int: \n";
	double g;
	int j;
	cin >> g;
	cin >> j;
	 c1 = g + j;
	 c2 = g - j;
	 c3 = g * j;
	 c4 = g / j;
	
	 cout << "Переменные типа double, int: \n" << "1)" << c1 << " 2)" << c2 << " 3)" << c3;
	 if (j == 0) cout << " 4)" << "Деление на ноль" << endl;
	 else cout <<" 4)"<< c4 << endl;

}  