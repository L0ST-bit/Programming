#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Чтобы считать через стороны треугольника введите: 1\nЧтобы считать через координпты вершин введите: 2\n";
	int k;
	cin >> k;
	if (k != 1 && k != 2) {
		cout << "Вписано неверное число";
		return 0;
	}
	int x1, y1, x2, y2, x3, y3;
	double a, b, c, p;
	if (k == 1) {
		cout << "Введите стороны треугольника a, b ,c:\n";
		cin >> a >> b >> c;
		p = (a + b + c) / 2;
		if (a < 0 || b < 0 || c < 0) 
			cout << "Длинна не может быть отрицательной";
		else if ( (a + b) < c or (a + c) < b or (c + b) < a)//Проверка существования треугоника
			cout << "Такого треугольника не существует";
		else 
			cout << "S = " << sqrt(p * (p - a) * (p - b) * (p - c));
		return 0;
	}
	if (k == 2) {
		cout << "Введите координаты:\n";
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	}
		if (((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) == 0) {
			cout << "Треугольник вырожденный";
			return 0;
		}
		cout << "S = " << (abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))/2);
		
	}
