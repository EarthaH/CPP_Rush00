#include <iostream>
#include <curses.h>

void    erase (int y, int x)
{
    mvaddch(y, x, '#');
}

void    game_loop(char main_char, int row, int col, int ch)
{
    if (ch == 'q' || ch == 'Q') return;

    mvaddch(row, col, main_char);
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
    }
}

void    printMenu(void)
{
    int     maxRow, maxCol, i;
    char    startMsg[] = "Welcome to your day of doom!";
    char    instruct[] = "Press 'S' to start and 'Q' to quit.";

    getmaxyx(stdscr, maxRow, maxCol);
    for (i = 0; i < maxCol; i++) {
        mvaddch(0, i, '|');
        mvaddch(maxRow - 1, i, '|');
    }
    for (i = 0; i < maxRow; i++) {
        mvaddch(i, 0, '-');
        mvaddch(i, maxCol - 1, '-');
    }
    mvprintw(maxRow / 2, (maxCol - strlen(startMsg)) / 2, "%s", startMsg);
    mvprintw((maxRow / 2) + 1, (maxCol - strlen(instruct)) / 2, "%s", instruct);
}

int     main()
{
    int     row = 10, col = 10;
    char    main_char = '@';

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    printMenu();
    refresh();
    int     ch = getch();
    clear();
    game_loop(main_char, row, col, ch);
    endwin();

    return (0);
}