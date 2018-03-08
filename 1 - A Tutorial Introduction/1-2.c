/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "Hello World" (Exercise 1-2)                                 ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 07MAR2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ This program simply prints the text "Hello World" to the     ║
║  Description  │ command line.                                                ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║               │ Experiment to find out what happens when printf's argument   ║
║ Exercise text │ string contains \c where c is some character not listed      ║
║               │ above.                                                       ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Notes     │ Type definition and arguments of main intentionally omitted. ║
║               │ Undefined escape sequence on line 25 is intentional.         ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

main()
{
    printf("Hello, world!\^\n");
}