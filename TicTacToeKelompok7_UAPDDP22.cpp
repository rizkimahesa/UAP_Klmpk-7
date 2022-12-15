#include <ncurses/ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

char board [3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
					 
int player, row, column, input, win = 0;
char reply = '1';

void header () {
	printf ("\n\t\t\t    __ __ __      __    _   __       __ __  ___ \n");
	printf ("\t\t\t   |_   | /  _\\    |_   |  / \\ /   _\\     |_   / _ \\| ___|\n");
	printf ("\t\t\t     | |  | |  /         | |   / _ \\   /          | || | | |  _|  \n");
	printf ("\t\t\t     | |  | |  \\__      | |  / __ \\  \\__       | || || | |_ \n");
	printf ("\t\t\t     || |_\\_/      || //   \\_\\__/       || \\_/|__|\n");
}

void start_screen () {
	initscr ();
	curs_set (0);
	mvprintw (11, 29, " __ __ __      __    _   __       __ __  ___ ");
	mvprintw (12, 29, "|_   | /  _\\    |_   |  / \\ /   _\\     |_   / _ \\| ___|");
	mvprintw (13, 29, "  | |  | |  /         | |   / _ \\   /          | || | | |  _|  ");
	mvprintw (14, 29, "  | |  | |  \\__      | |  / __ \\  \\__       | || || | |_ ");
	mvprintw (15, 29, "  || |_\\_/      || //   \\_\\__/       || \\_/|__|");
	mvprintw (17, 48, "By : Devina Citra Felisha");
	mvprintw (18, 53, "Farhan Dzaky Aldias");
	mvprintw (19, 53, "Rizki Mahesa");
	mvprintw (21, 47, "PRESS ANY KEY TO CONTINUE...");
	getch ();
	clear ();
	endwin ();
}

void loading () {
	initscr ();
	curs_set (0);
	mvprintw (25, 2, "Loading...");
	mvprintw (26, 2,"====================================================================================================================");
	for (int i = 1; i < 117; i++) {
		mvprintw (27, i + 1, "|");
		refresh ();
		Sleep (20);
	}
	clear ();
	endwin ();
}

void closing () {
	initscr ();
	clear ();
	mvprintw (13,37, "THANK'S FOR TAKING YOUR TIME TO PLAY THIS GAME");
	mvprintw (14,56, " /\\_/\\");
	mvprintw (15,56, "(  >.<)");
	mvprintw (16,55, "/ )[bye!]");
	curs_set (0);
	getch ();
	endwin ();
}

int main () {
	
	start :
		start_screen ();
	
	loading :
		loading ();
	
	close :
		closing ();
	hi
	return 0;
}
