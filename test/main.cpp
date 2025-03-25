#include <ncurses.h>

int main()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);

    bool level1 = false;
    bool level2 = false;

    MEVENT event;
    while (true) {
        if (!level1 && !level2) {
            mvprintw(5, 1, "level1\n\nlevelcaca");
            mvprintw(6, 1, "level2");
        } else if (level1) {
            mvprintw(5, 1, "Bienvenu dans level1");
        } else if (level2) {
            mvprintw(5, 1, "Bienvenu dans level2");
        }

        int ch = getch();
        if (ch == KEY_MOUSE) {
            if (getmouse(&event) == OK) {
                if (event.y == 5 && event.x < 8)
                    level1 = true;
                if (event.y == 6 && event.x < 8)
                    level2 = true;
            }
        } else if (ch == 'q') {
            break;
        } else if (ch == ' ') {
            level1 = false;
            level2 = false;
        }
        clear();
        refresh();
    }
    endwin();
    return 0;
}
