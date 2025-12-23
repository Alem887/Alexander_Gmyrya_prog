#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const ga::menu_item* ga::exit(const menu_item* current) {
    std::exit(0);
}

const ga::menu_item* ga::show_menu(const menu_item* current) {
    std::cout << "Хотите учиться математике?" << std::endl;
        for (int i = 1; i < current->children_count; i++) {
            std::cout << current->children[i]->title << std::endl;
        }
        std::cout << current->children[0]->title << std::endl;

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const ga::menu_item* ga::go_back(const menu_item* current) {
    return current->parent->parent;
}

const ga::menu_item* ga::add(const menu_item* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const ga::menu_item* ga::substract(const menu_item* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const ga::menu_item* ga::multiply(const menu_item* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const ga::menu_item* ga::divide(const menu_item* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const ga::menu_item* ga::differential(const menu_item* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const ga::menu_item* ga::integral(const menu_item* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}