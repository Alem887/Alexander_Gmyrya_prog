#include "menu_items.hpp"
#include "menu_functions.hpp"
#include "menu.hpp"

const ga::menu_item ga::VLADIVOSTOK = {"1 - Владивосток", ga::vladivostok, &ga::FAR_EAST};
const ga::menu_item ga::SAKHALIN = {"2 - Сахалин", ga::sakhalin, &ga::FAR_EAST};
const ga::menu_item ga::KHABAROVSK = {"3 - Хабаровск", ga::khabarovsk, &ga::FAR_EAST};
const ga::menu_item ga::FAR_EAST_GO_BACK = {"0 - Выйти в предыдущее меню", ga::go_back, &ga::FAR_EAST};

namespace {
	const ga::menu_item* const far_east_children[] = {&ga::FAR_EAST_GO_BACK, &ga::VLADIVOSTOK, &ga::SAKHALIN, &ga::KHABAROVSK};
	int far_east_children_count = sizeof(far_east_children)/sizeof(far_east_children[0]);
}

const ga::menu_item ga::FAR_EAST = {"1 - Дальний Восток", ga::show_menu_far_east, &ga::TRAVEL, far_east_children, far_east_children_count};
const ga::menu_item ga::ALTAI = {"2 - Алтай", ga::altai, &ga::TRAVEL};
const ga::menu_item ga::GOLD_RING = {"3 - Золотое кольцо России", ga::gold_ring, &ga::TRAVEL};
const ga::menu_item ga::TRAVEL_GO_BACK = {"0 - Выйти в главное меню", ga::go_back, &ga::TRAVEL};

namespace {
	const ga::menu_item* const travel_children[] = {&ga::TRAVEL_GO_BACK, &ga::FAR_EAST, &ga::ALTAI, &ga::GOLD_RING};
	int travel_children_count = sizeof(travel_children)/sizeof(travel_children[0]);
}

const ga::menu_item ga::TRAVEL = {"1 - Путешествовать по Росии", ga::show_menu_travel, &ga::MAIN, travel_children, travel_children_count};
const ga::menu_item ga::EXIT = {"0 - Закончить путешествие", ga::exit, &ga::MAIN};

namespace {
	const ga::menu_item* const main_children[] = {&ga::EXIT, &ga::TRAVEL};
	int main_children_count = sizeof(main_children)/sizeof(main_children[0]);
}

const ga::menu_item ga::MAIN = {"Главное меню", ga::show_menu_main, nullptr, main_children, main_children_count};