#include <iostream>
#include <cstdlib>

#include "menu.hpp"
#include "menu_functions.hpp"

namespace {
	const ga::menu_item* show_menu (const ga::menu_item* current) {
		for (int i = 1; i < current->children_count; i++) {
			std::cout << current->children[i]->title << std::endl;
		}
		std::cout << current->children[0]->title << std::endl;
		
		int user_input;
		std::cin >> user_input;
		std::cout << std::endl;
		
		return current->children[user_input];
	}
}

const ga::menu_item* ga::show_menu_main (const ga::menu_item* current) {
	std::cout << "Главное меню" << std::endl;
	return show_menu(current);
}

const ga::menu_item* ga::show_menu_travel (const ga::menu_item* current) {
	std::cout << "Второй уровень меню" << std::endl;
	return show_menu(current);
}

const ga::menu_item* ga::show_menu_far_east (const ga::menu_item* current) {
	std::cout << "Третий уровень Дальний восток" << std::endl;
	return show_menu(current);
}

const ga::menu_item* ga::exit (const ga::menu_item* current) {
	std::exit(0);
}

const ga::menu_item* ga::altai (const ga::menu_item* current) {
	std::cout << current->title << std::endl;
	return current->parent;
}

const ga::menu_item* ga::gold_ring (const ga::menu_item* current) {
	std::cout << current->title << std::endl;
	return current->parent;
}

const ga::menu_item* ga::vladivostok (const ga::menu_item* current) {
	std::cout << current->title << std::endl;
	return current->parent;
}

const ga::menu_item* ga::sakhalin (const ga::menu_item* current) {
	std::cout << current->title << std::endl;
	return current->parent;
}

const ga::menu_item* ga::khabarovsk (const ga::menu_item* current) {
	std::cout << current->title << std::endl;
	return current->parent;
}

const ga::menu_item* ga::go_back (const ga::menu_item* current) {
	return current->parent->parent;
}
		