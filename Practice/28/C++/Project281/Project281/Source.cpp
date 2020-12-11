#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> ReshetoEratosfena(unsigned int n){
	vector<int> nums;
	int size = n;
	for (int count = 2; count <= size; count++) {
		
		if(n % count == 0){
			n = n / count;
			nums.push_back(count);
			count = 1;
		}
		else if (count == n) {
			nums.push_back(count);
			return nums;
		}
	}
	return nums;
}



void print_factorization(unsigned int n) {
	vector<int> nums;
	nums = ReshetoEratosfena(n);
	int size = nums.size();
	if (size == 1) {
		cout << nums[0];
		exit(1);
	}
	bool k = false;
	cout << nums[0];
	for (int i = 1; i < size; i++){
		if (nums[i - 1] == nums[i]){
			int degree = 1;
			
			for (int i1 = i; i1 < size;i1++) {
				if (k == true)
					break;
				else if(nums[i1 - 1] == nums[i1])
					degree++;

			}if(!k)
				cout << "^" << degree;
			k = true;
			if(size > 2 and nums[2] == nums[1] and n%8 != 0 and n%90 != 0)
				i++;

		}
		else {
			cout << "*" << nums[i];
			k = false;
		}
	}
}

int main() {
	unsigned int n;
	cin >> n;
	print_factorization(n);
}



