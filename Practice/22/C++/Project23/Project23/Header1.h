#pragma once

int Header1(int a) {

	std::cout << "a   " << "a!\n";
	for (int i = 1; i <= 10; i++) {
		int a = 1;
		std::cout << "a   ";
		int i1 = i;
		for (int z = 1; z <= i1; z++) 
			a = a * z;
		std::cout << a << std::endl;
			

		
	}
	return 0;
}