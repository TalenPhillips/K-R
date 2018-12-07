/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "One Word Per Line" (Exercise 1-12)                          ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 11MAR2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ Takes a newline-terminated input from the command line and   ║
║  Description  │ prints it out one word per line.                             ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║ Exercise text │ Write a program that prints its input one word per line.     ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Note      │ To input an EOF character Press ctrl-D.                      ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    for (char c = 0; (c = getchar()) != '\n'; putchar(c))
    {
        if (c == ' ' || c == '\t')
        {
            c = '\n';
        }
    }
    putchar('\n');
    return 0;
}