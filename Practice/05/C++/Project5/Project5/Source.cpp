#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Вычисляет по формуле: x0 + V0 * t - a*t*t/2 \nВведите x0, V0, t: \n";
	
	double(x0);
	double(V0);
	double(t);
	double (R);
	double a = 9.8;
	cin >> x0;
	cin >> V0;
	cin >> t;
	R = x0 + V0 * t - a*t*t/2;
	cout <<"Результат: "<< R;





}