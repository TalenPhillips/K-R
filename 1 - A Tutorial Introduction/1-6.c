/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "Getchar and EOF" (Exercise 1-6)                             ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 11MAR2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ Outputs the value of the expression: getchar() != EOF        ║
║  Description  │ until an EOF character is encountered.                       ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║ Exercise text │ Verify that the expression getchar() != EOF is 0 or 1.       ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Note      │ To input an EOF character Press ctrl-D.                      ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c = 1;

    while (c)
    {
        c = getchar() != EOF;
        printf("%i\n", c);
    }

    return 0;
}