#pragma once

#include "menu.hpp"

namespace ga {
	const menu_item* show_menu_main (const menu_item* current); 
	const menu_item* exit (const menu_item* current); 
	
	const menu_item* show_menu_travel (const menu_item* current);
	const menu_item* altai (const menu_item* current);
	const menu_item* gold_ring (const menu_item* current);
	const menu_item* go_back (const menu_item* current);
	
	const menu_item* show_menu_far_east (const menu_item* current);
	const menu_item* vladivostok (const menu_item* current);
	const menu_item* sakhalin (const menu_item* current);
	const menu_item* khabarovsk (const menu_item* current);
}
	