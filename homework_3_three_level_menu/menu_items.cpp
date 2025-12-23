#include "menu_items.hpp"
#include "menu_functions.hpp"

#include <cstddef>

const ga::menu_item ga::INTEGRAL = {"2.Хочу учиться интегральному исчислению", ga::integral, &ga::CALCULUS};
const ga::menu_item ga::DIFFERENTIAL = {"1.Хочу учиться дифференциальному исчислению", ga::differential, &ga::CALCULUS};
const ga::menu_item ga::CALCULUS_GO_BACK = {"0.Вернуться к выбору предметов", ga::go_back, &ga::CALCULUS};

const ga::menu_item ga::DIVIDE = {"4.Хочу учиться делению", ga::divide, &ga::ALGEBRA};
const ga::menu_item ga::MULTIPLY = {"3.Хочу учиться умножению", ga::multiply, &ga::ALGEBRA};
const ga::menu_item ga::SUBSTRACT = {"2.Хочу учиться вычитанию", ga::substract, &ga::ALGEBRA};
const ga::menu_item ga::ADD = {"1.Хочу учиться сложению", ga::add, &ga::ALGEBRA};
const ga::menu_item ga::ALGEBRA_GO_BACK = {"0.Вернуться к выбору предметов", ga::go_back, &ga::ALGEBRA};

namespace {
   const ga::menu_item* const calculus_children[] = {&ga::CALCULUS_GO_BACK, &ga::DIFFERENTIAL, &ga::INTEGRAL}; 
   const int calculus_size = sizeof(calculus_children)/sizeof(calculus_children[0]);
}

namespace {
   const ga::menu_item* const algebra_children[] = {&ga::ALGEBRA_GO_BACK, &ga::ADD, &ga::SUBSTRACT, &ga::MULTIPLY, &ga::DIVIDE}; 
   const int algebra_size = sizeof(algebra_children)/sizeof(algebra_children[0]);
}

const ga::menu_item ga::CALCULUS = {"2.Хочу учиться математическому анализу", ga::show_menu, &ga::STUDY, calculus_children, calculus_size};
const ga::menu_item ga::ALGEBRA = {"1.Хочу учиться алгебре", ga::show_menu, &ga::STUDY, algebra_children, algebra_size};
const ga::menu_item ga::STUDY_GO_BACK = {"0.Выйти в главное меню", ga::go_back, &ga::STUDY};

namespace {
   const ga::menu_item* const study_children[] = {&ga::STUDY_GO_BACK, &ga::ALGEBRA, &ga::CALCULUS}; 
   const int study_size = sizeof(study_children)/sizeof(study_children[0]);
}

const ga::menu_item ga::STUDY = { "1. Хочу учиться математике", ga::show_menu, &ga::MAIN, study_children, study_size};
const ga::menu_item ga::EXIT = { "0. Я лучше пойду полежу", ga::exit, &ga::MAIN};

namespace {
    const ga::menu_item* const main_children[] = {&ga::EXIT, &ga::STUDY};
    const int main_size = sizeof(main_children)/sizeof(main_children[0]);
}

const ga::menu_item ga::MAIN = {nullptr, ga::show_menu, nullptr, main_children, main_size};


