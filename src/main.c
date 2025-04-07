#include <locale.h>
#include <stdlib.h>
#include <ncursesw/curses.h>
#include <threads.h>

void 
quit(){
		endwin();	
}

void 
setup(){
		setlocale(LC_ALL, "");
}

int main(){
		setup();


		int x, y;
		WINDOW* win;
		win = initscr();
		atexit(quit);

		curs_set(0);
		move(5, 5);

		mvprintw(3, 5, "LINES: %d", LINES);
		mvprintw(4, 5, "COLS: %d", COLS);

		getyx(win, y, x);
		mvprintw(5, 5, "Momentane Cursorposition: [%d, %d]", y, x);
		mvaddstr(11, 2, "Drücke [↑]");
		refresh();

		getch();
		sleep(2);
		return 0;
}
