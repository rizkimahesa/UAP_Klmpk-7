#include <ncurses/ncurses.h>
#include <stdio.h>
#include <windows.h>

char board [3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
					 
int player, row, column, input, win = 0;
char reply = '1';

void header () {
	printf ("\n\t\t\t    _____ ___ ____      _____    _   _____       _____ ___  _____ \n");
	printf ("\t\t\t   |_   _|_ _/  __\\    |_   _|  / \\ /   __\\     |_   _/ _ \\| ____|\n");
	printf ("\t\t\t     | |  | |  /         | |   / _ \\   /          | || | | |  _|  \n");
	printf ("\t\t\t     | |  | |  \\___      | |  / ___ \\  \\___       | || |_| | |___ \n");
	printf ("\t\t\t     |_| |___\\____/      |_| /_/   \\_\\____/       |_| \\___/|_____|\n");
}

void start_screen () {
	initscr ();
	curs_set (0);
	mvprintw (11, 29, " _____ ___ ____      _____    _   _____       _____ ___  _____ ");
	mvprintw (12, 29, "|_   _|_ _/  __\\    |_   _|  / \\ /   __\\     |_   _/ _ \\| ____|");
	mvprintw (13, 29, "  | |  | |  /         | |   / _ \\   /          | || | | |  _|  ");
	mvprintw (14, 29, "  | |  | |  \\___      | |  / ___ \\  \\___       | || |_| | |___ ");
	mvprintw (15, 29, "  |_| |___\\____/      |_| /_/   \\_\\____/       |_| \\___/|_____|");
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
	
	gameplay :
		while (reply == '1') {
			win = 0;
			char board [3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
			for (int i = 0; i < 9 && win == 0; i++) {
			
				system ("cls");
				header ();
				printf ("\n\n\n");
				printf ("\t\t\t\t\t\t _________________ \n");
				printf ("\t\t\t\t\t\t|     |     |     |\n");
				printf ("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n", board [0][0], board [0][1], board [0][2]);
				printf ("\t\t\t\t\t\t|_____|_____|_____|\n");
				printf ("\t\t\t\t\t\t|     |     |     |\n");
				printf ("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n", board [1][0], board [1][1], board [1][2]);
				printf ("\t\t\t\t\t\t|_____|_____|_____|\n");
				printf ("\t\t\t\t\t\t|     |     |     |\n");
				printf ("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n", board [2][0], board [2][1], board [2][2]);
				printf ("\t\t\t\t\t\t|_____|_____|_____|\n");
			
				player = i%2 + 1;
				printf ("\n\t\t\t\t\t\t      Player %d ", player);
			
				do {
					
					printf ("\n\t\t\t\t\t\t  It's your turn : ");
					scanf ("%d", &input);
					
					if (input >= 1 && input <= 3) {
						row = 0;
						column = input - 1;
					} else if (input >= 4 && input <= 6) {
						row = 1;
						column = input - 4;
					} else {
						row = 2;
						column = input - 7;
					}
				} while (input < 1 || input > 9 || board [row][column] == 'X' || board [row][column] == 'O');
		}
			//player 1 dikategorikan dengan simbol "x"
				if (player == 1) {
					board [row][column] = 'X';
				//sedangkan jika bukan player 1 atau disini kami membuat player 2 maka simbol nya "o"
				} else {
					board [row][column] = 'O';
				}
				//jika terdapat 3 kolom yang sama maka player menang
				for (row = 0; row < 3; row++) {
					if (board [row][0] == board [row][1] && board [row][1] == board [row][2]){
						win = player;
					}
				}
				//jika terdapat 3 baris yang sama maka player menang
				for (column = 0; column < 3; column++){
					if (board [0][column] == board [1][column] && board [1][column] == board [2][column]) {
						win = player;
					}
				}
				//jika terdapat 3 simbol yang sama dalam diagonal maka player menang
				if (board [0][0] == board[1][1] && board [1][1] == board [2][2]) {
					win = player;
				} else if (board [0][2] == board [1][1] && board [1][1] == board [2][0]) {
					win = player;
				}
			}
			//menampilkan hasil tabel yang sudah dimainkan
			system ("cls");
			header ();
			printf ("\n\n\n");
			printf ("\t\t\t\t\t\t _________________ \n");
			printf ("\t\t\t\t\t\t|     |     |     |\n");
			printf ("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n", board [0][0], board [0][1], board [0][2]);
			printf ("\t\t\t\t\t\t|_____|_____|_____|\n");
			printf ("\t\t\t\t\t\t|     |     |     |\n");
			printf ("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n", board [1][0], board [1][1], board [1][2]);
			printf ("\t\t\t\t\t\t|_____|_____|_____|\n");
			printf ("\t\t\t\t\t\t|     |     |     |\n");
			printf ("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n", board [2][0], board [2][1], board [2][2]);
			printf ("\t\t\t\t\t\t|_____|_____|_____|\n");
			
			//program untuk menentukan player akan menang atau seri
			if (win != 0) {
				printf ("\n\t\t\t\t    Congratulations !!! Player %d Wins this game", win);
			} else {
				printf ("\n\t\t\t\t\t\tGame ends in a Draw");
			}
		
			//jika pemain ingin main lagi cukup menekan 1, maka akan kembali ke awal
			printf ("\n\n\t\t\t\t    Press 1 if you want to play this again : ");
			scanf (" %c", &reply);
		}
	//jika pemain menekan angka selain 1 maka permainan akan selesai dengan closing
	close :
		closing ();
	
	return 0;
	// game selesai Terima Kasih!!!
}
