/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "Word Length Histogram" (Exercise 1-13a)                     ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 30NOV2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ Print a histogram of the length of the words in its input.   ║
║  Description  │ Draw the histogram bars horizontally.                        ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║ Exercise text │ Write a program to print a histogram of the lengths of words ║
║               │ in its input. It is easy to draw the histogram with the bars ║
║               │ horizontal; a vertical orientation is more challenging.      ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

#define MAX_LEN 20

int main(void)
{
    char c, arr[20] = { 0 };
    int min = MAX_LEN, max = 0, wordLen = 0;

    while ((c = getchar()) != '\n')
    {
        if ( !( (c >= 'a' && c <= 'z') || // if c is not a letter or number
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9') ) )
        {
            if (wordLen > MAX_LEN)
            {
                wordLen = MAX_LEN;
            }

            if (min > wordLen && wordLen > 0)
            {
                min = wordLen;
            }

            if (max < wordLen)
            {
                max = wordLen;
            }

            ++arr[wordLen];
            wordLen = 0;
        }
        else // c is a letter or number
        {
            ++wordLen;
        }
    }
    ++arr[wordLen];
    
    for (int i = min; i <= max; ++i)
    {
        printf("%3i: ", i);

        for (int j = 0; j < arr[i]; ++j)
        {
            putchar('*');
        }

        putchar('\n');
    }

    return 0;
}
