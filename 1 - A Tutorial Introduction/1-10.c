/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "Un-Escape" (Exercise 1-10)                                  ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 11MAR2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ Replaces each tab with "\t", each backspace with "\b", and   ║
║  Description  │ each backslash with "\\".                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║               │ Write a program to copy its input to its output, replacing   ║
║ Exercise text │ each tab by \t, each backspace by \b, and each backslash by  ║
║               │ \\. This makes tabs and backspaces visible in an unambiguous ║
║               │ way.                                                         ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Note      │ To input an EOF character Press ctrl-D.                      ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c = 0;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
            case '\t': printf("\\t");  break;
            case '\b': printf("\\b");  break;
            case '\\': printf("\\\\"); break;
            default:   putchar(c);     break;
        }
    }

    return 0;
}