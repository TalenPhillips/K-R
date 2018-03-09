/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "Temperature Conversion Revised" (Exercise 1-5)              ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 08MAR2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ Print celcius-farenheit table                                ║
║  Description  │ for celsius = 150, 140, ..., 0; floating-point version       ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║ Exercise text │ Modify the temperature conversion program to print the table ║
║               │ in reverse order, that is, from 300 degrees to 0.            ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int lower = 0;      // lower limit of temperature table
    int upper = 150;    // upper limit
    int step  = 10;     // step size

    float fahr = 0.0, celsius = upper;

    puts(" ºC\tºF");

    while (celsius >= lower)
    {
        fahr = celsius * (9.0/5.0) + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius -= step;
    }

    return 0;
}