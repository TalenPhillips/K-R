/*
╔═══════════════╤══════════════════════════════════════════════════════════════╗
║     Title     │ "Word Length Histogram" (Exercise 1-13b)                     ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Author     │ Talen Phillips                                               ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║     Date      │ 30NOV2018                                                    ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║    Program    │ Print a histogram of the length of the words in its input.   ║
║  Description  │ Draw the histogram bars vertically.                          ║
╟───────────────┼──────────────────────────────────────────────────────────────╢
║ Exercise text │ Write a program to print a histogram of the lengths of words ║
║               │ in its input. It is easy to draw the histogram with the bars ║
║               │ horizontal; a vertical orientation is more challenging.      ║
╚═══════════════╧══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>

#define MAX_LEN 50

int main(void)
{
    char c, arr[MAX_LEN] = {0};
    int minLength = MAX_LEN, maxLength = 0, wordLen = 0, maxCount = 0;

    while ((c = getchar()) != '\n')
    {
        if ( !( (c >= 'a' && c <= 'z') || // if c is not a letter or number
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9') ||
                (c == '\'') ) )
        {
            if (wordLen > MAX_LEN)
            {
                wordLen = MAX_LEN;
            }

            if (minLength > wordLen && wordLen > 0)
            {
                minLength = wordLen;
            }

            if (maxLength < wordLen)
            {
                maxLength = wordLen;
            }

            ++arr[wordLen];
            wordLen = 0;
        }
        else // c is a letter or number
        {
            ++wordLen;
        }
    }

    if (wordLen > MAX_LEN)
    {
        wordLen = MAX_LEN;
    }

    if (minLength > wordLen && wordLen > 0)
    {
        minLength = wordLen;
    }

    if (maxLength < wordLen)
    {
        maxLength = wordLen;
    }
    ++arr[wordLen]; // count the last word

    for (int i = 0; i <= maxLength; ++i)
    {
        if (arr[i] > maxCount)
        {
            maxCount = arr[i];
        }
    }

    for (; maxCount > 0; --maxCount)
    {
        printf("%4d |", maxCount);

        for (int i = minLength; i <= maxLength; ++i)
        {
            if (arr[i] >= maxCount)
            {
                printf("  *");
            }
            else
            {
                printf("   ");
            }
        }

        putchar('\n');
    }

    printf("-----|");

    for (int i = minLength; i <= maxLength; ++i)
    {
        printf("---");
    }

    printf("\n     |");

    for (int i = minLength; i <= maxLength; ++i)
    {
        printf("%3d",i);
    }

    putchar('\n');

    return 0;
}