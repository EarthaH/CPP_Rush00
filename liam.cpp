#include <iostream>
#include <curses.h>

void    erase (int y, int x)
{
    mvaddch(y, x, '#');
}

void    printBorder(void)
{
    int     maxRow, maxCol, i;

    getmaxyx(stdscr, maxRow, maxCol);
    for (i = 0; i < maxCol; i++) {
        mvaddch(0, i, '|');
        mvaddch(maxRow - 1, i, '|');
    }
    for (i = 0; i < maxRow; i++) {
        mvaddch(i, 0, '-');
        mvaddch(i, maxCol - 1, '-');
    }
}

void    printMenu(void)
{
    int     maxRow, maxCol;
    char    startMsg[] = "Welcome to your day of doom!";
    char    instruct[] = "Press 'S' to start and 'Q' to quit.";

    getmaxyx(stdscr, maxRow, maxCol);
    printBorder();
    mvprintw(maxRow / 2, (maxCol - strlen(startMsg)) / 2, "%s", startMsg);
    mvprintw((maxRow / 2) + 1, (maxCol - strlen(instruct)) / 2, "%s", instruct);
}

void    game_loop(char main_char, int row, int col, int ch)
{
    int     maxRow, maxCol;
    if (ch == 'q' || ch == 'Q') return;

	clear();
    getmaxyx(stdscr, maxRow, maxCol);
    mvaddch(row, col, main_char);
    printBorder();
    refresh();

    for(;;)
    {
        ch = getch();

        if (ch == KEY_LEFT)
        {
            erase(row, col);
            col = col - 1;
            mvaddch(row, col, main_char);
            refresh();
        }
        else if (ch == KEY_RIGHT)
        {
            erase(row, col);
            col = col + 1;
            mvaddch(row, col, main_char);
            refresh();
        }
        else if (ch == KEY_UP)
        {
            erase(row, col);
            row = row - 1;
            mvaddch(row, col, main_char);
            refresh();
        }
        else if (ch == KEY_DOWN)
        {
            erase(row, col);
            row = row + 1;
            mvaddch(row, col, main_char);
            refresh();
        }
        else if (ch == 'q' || ch == 'Q' || ch == KEY_EXIT)
            return ;
        if (row >= maxRow - 1 || row <= 0 || col >= maxCol - 1 || col <= 0)
            return ;
    }
}

int    gameOver()
{
    int     maxRow, maxCol;
    char    lose[] = "YOU LOST!";
    char    startOrQuit[] = "Press 'S' to start and 'Q' to quit.";
    char    ch;

	clear();
    getmaxyx(stdscr, maxRow, maxCol);
    printBorder();
    mvprintw(maxRow / 2, (maxCol - strlen(lose)) / 2, "%s", lose);
    mvprintw((maxRow / 2) + 1, (maxCol - strlen(startOrQuit)) / 2, "%s", startOrQuit);
	for (;;){
		ch = getch();
		if (ch == 'q' || ch == 'Q')
			return 0;
		else if (ch == 'S' || ch == 's')
			return 1;
	}
}

int     main()
{
    int     row = 10, col = 10, stillPlaying;
    char    main_char = '@';

	stillPlaying = 1;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    printMenu();
    refresh();
    int     ch = getch();
    clear();
	while (stillPlaying == 1) {
		game_loop(main_char, row, col, ch);
		stillPlaying = gameOver();
	}
    endwin();

    return (0);
}