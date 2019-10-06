#include "menu.h"
#include <string>
#include <ncurses.h>
std::string choices[3] =
{
    "Play Two Player Game",
    "Play Against Computer",
    "Quit",
};

int numChoices = std::size(choices);
void printMenu(int highlight);

int startMenu()
{
    int highlight = 1;
    int choice = 0;
    int c;
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    mvprintw(0, 0, "Use arrow keys to go up and down, enter to select a choice.");
    printMenu (highlight);
    bool noChoice = true;
    while (noChoice)
    {
        c = getch();
        switch(c)
        {
            case KEY_UP:
                {
                    if(highlight == 1)
                        highlight = numChoices;
                    else
                        --highlight;
                    break;
                }
            case KEY_DOWN:
                {
                    if(highlight == numChoices)
                        highlight = 1;
                    else
                        ++highlight;
                    break;

                }
            case 10:
                {
                    choice = highlight;
                    break;
                }
            default:
                {
                    break;
                }
        }
        printMenu(highlight);
        if(choice)
            noChoice = false;
    }
    echo();
    return choice;
}
void printMenu(int highlight)
{
    int x{2};
    int y{2};
    box(stdscr, 0, 0);
    for(int i = 0; i < numChoices; i++)
    {
        const char* c_choice = choices[i].c_str();
        if(highlight == i + 1)
        {
            attron(A_REVERSE);
            mvprintw(y, x, "%s", c_choice);
            attroff(A_REVERSE);
        }
        else
            mvprintw(y, x, "%s", c_choice);
        ++y;
    }
    refresh();
}
