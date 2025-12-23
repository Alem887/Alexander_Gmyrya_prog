#include <clocale>

#include "menu.hpp"
#include "menu_items.hpp"
#include "menu_functions.hpp"

int main() {
	std::setlocale(LC_ALL, "");
	
	const ga::menu_item* current = &ga::MAIN;
	do {
		current = current->func(current);
	} while (true);
}