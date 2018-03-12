/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "Getchar and whitespaces" (Exercise 1-9)                     ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 11MAR2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ Repeats the input, but replaces each set of space with a     ║
║  Description  │ single space. Terminates with an EOF character.              ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║ Exercise text │ Write a program to copy its input to its output, replacing   ║
║               │ each string of one or more blanks by a single blank.         ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Note      │ To input an EOF character Press ctrl-D.                      ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int character = 0, previous = 0;
         (character = getchar()) != EOF;
         previous = character)
    {
        if (character != ' ' || previous != ' ')
        {
            putchar(character);
        }
    }

    return 0;
}