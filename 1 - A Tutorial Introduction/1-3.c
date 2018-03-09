/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "Temperature Conversion" (Exercise 1-3)                      ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 08MAR2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ Print farenheit-celcius table                                ║
║  Description  │ for fahr = 0, 20, ..., 150; floating-point version           ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║ Exercise text │ Modify the temperature conversion program to print a heading ║
║               │ above the table.                                             ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int lower = 0;      // lower limit of temperature table
    int upper = 150;    // upper limit
    int step  = 10;     // step size

    float fahr = lower, celsius = 0.0;

    puts(" ºF\tºC");

    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }

    return 0;
}