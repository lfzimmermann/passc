#include <locale.h>
#include <stdlib.h>
#include <threads.h>


#include <ncursesw/curses.h>
#include <ncursesw/menu.h>

#include "main.h"

const char* choices[] = {
		"Choice 1",
		"Choice 2",
		"Choice 3",
		"Choice 4",
		"Exit",
		(char*)NULL,
};
const size_t n_menu_choices = ARRAY_SIZE(choices);

void 
quit(){
		endwin();	
}

void 
setup(){
		setlocale(LC_ALL, "");
		cbreak();
		noecho();
		keypad(stdscr, TRUE);
}

void
free_items(ITEM** items, const size_t size){
		for (int i = 0; i < size; i++){
				free_item(items[i]);
		}
		free(items);
}

int main(){
		MENU *menu;
		WINDOW *win;
		ITEM** items;
		int x, y, c;

		win = initscr();
		atexit(quit);
		setup();

		curs_set(0);

		items = (ITEM**)calloc(n_menu_choices, sizeof(ITEM*));

		for (int i = 0; i < n_menu_choices; i++){
				items[i] = new_item(choices[i], "");
		}

		start_color();

		menu = new_menu((ITEM**)items);
		mvprintw(10, 0, "WHYHWYHWYHWY");
		// DO STUFF

		post_menu(menu);
		refresh();

		while ((c = getch()) != KEY_RIGHT)
		{
				switch(c) {
						case KEY_DOWN:
								menu_driver(menu, REQ_DOWN_ITEM);
								refresh();
								break;
						case KEY_UP:
								menu_driver(menu, REQ_UP_ITEM);
								mvprintw(LINES - 2, 0, "UP  ");
								break;
				}
		}


		// END STUFF
		unpost_menu(menu);
		free_menu(menu);
		free_items(items, n_menu_choices);	
		return 0;
}
