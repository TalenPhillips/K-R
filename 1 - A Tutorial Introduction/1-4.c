/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "Temperature Conversion Revised" (Exercise 1-4)              ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 08MAR2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ Print celcius-farenheit table                                ║
║  Description  │ for celsius = 0, 20, ..., 150; floating-point version        ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║ Exercise text │ Write a program to print the corresponding Celsius to        ║
║               │ Fahrenheit table.                                            ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int lower = 0;      // lower limit of temperature table
    int upper = 150;    // upper limit
    int step  = 10;     // step size

    float fahr = 0.0, celsius = lower;

    puts(" ºC\tºF");

    while (celsius <= upper)
    {
        fahr = celsius * (9.0/5.0) + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}