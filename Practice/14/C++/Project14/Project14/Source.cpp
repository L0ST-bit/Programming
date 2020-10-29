#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long long int k, i, a, n;
	cin >> n;
	a = 2;
	i = 0;
	while (a <= n) {
		i++;
		a = 2;
		a = pow(a, i);
	}
	if (n == 0)
		cout << '0';
	else if (n == 1)
		cout << '1';
	else if (n == 2)
		cout << '2';
	else 
		cout << i ;

}