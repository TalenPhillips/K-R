/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "Whitespace counter" (Exercise 1-8)                          ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 11MAR2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ Counts the number of whitespace characters individually      ║
║  Description  │ until an EOF character is encountered, and prints the sums.  ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║ Exercise text │ Write a program to count blanks, tabs, and newlines.         ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Note      │ To input an EOF character Press ctrl-D.                      ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c = 0, NewLines = 0, Spaces = 0, Tabs = 0;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
            case '\n':  ++NewLines; break;
            case ' ':   ++Spaces;   break;
            case '\t':  ++Tabs;     break;
            default:                break;
        }
    }

    printf("%d\tNewLines\n%d\tSpaces\n%d\tTabs\n", NewLines, Spaces, Tabs);

    return 0;
}