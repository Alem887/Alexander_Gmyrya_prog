#include <iostream>

int main() {
	int prog_size;
	std::cin >> prog_size;
	double progression[prog_size];
	for (int i = 0; i < prog_size; i++) {
		std::cout << "Введите " << i+1 << " элемент" << std::endl;
		std::cin >> progression[i];
	}
	
	int i = 0;
	bool is_increasing = true;
	while (i < prog_size - 1) {
		if (progression[i] > progression[i + 1]) {  
			is_increasing = false;
			break;
		
		}
		i++;
	}
	
	if (is_increasing) {
		std::cout << "Последовательность возрастает";
		std::cout << std::endl;
	}
	else {
		std::cout << "Последовательность не возрастает";
		std::cout << std::endl;
	}

	return 0;
}
