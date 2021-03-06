/* "Text Analyser" by Talen Phillips
 * written 23MAY2013 - 08DEC2018
 * This program analyses a file of ASCII text, and prints out stats and graphs.
 * It was originally written as an exercise (K&R2: 1-13 and 1-14), but became an
 * exploratory project. */

#include <stdio.h>
#define MAX_LENGTH 20
#define MAX_HEIGHT 20
#define MAXLINE 10000
#define IN 1
#define OUT 0
#define CPY(to, from) for (int cpycntr = 0; (to[cpycntr] = from[cpycntr]) != '\0'; ++cpycntr);



typedef struct sstrct
{
    FILE *file_ptr;
    int chars;
    int letters;
    int words;
    int sentences;
    char long_word[46];
    char long_sen[MAXLINE];
    int word_lengths[MAX_LENGTH];
    int letter_frequency[26];
} stat_struct;



/* Function:    Open File
 *
 * Description: Opens a file to be read. Displays a message if an error occurs.
 *
 * Arguments:   none
 *
 * Returns:     a pointer to the file
 */
FILE *open_file()
{
    char c, filename[200]= {0};
    int i;
    FILE *file_ptr = NULL;

    printf("Enter a file name: ");
    for (i = 0; (c = getchar()) != '\n' && i < 200; ++i)
    {
        filename[i] = c;
    }
    putchar('\n');

    file_ptr = fopen(filename,"r");

    return file_ptr;
}



/* Function:    Initialize structure
 *
 * Description: Initializes the stat_struct pointed to by the argument.
 *
 * Arguments:   statistics: pointer to a stat_struct
 *
 * Returns:     nothing
 */
void init_struct(stat_struct * statistics)
{
    statistics->file_ptr = open_file();
    statistics->chars = 0;
    statistics->letters = 0;
    statistics->words = 0;
    statistics->sentences = 0;

    for(int i = 0; i < 46; i++)
    {
        statistics->long_word[i] = 0;
    }

    for(int i = 0; i < MAXLINE; i++)
    {
        statistics->long_sen[i] = 0;
    }

    for(int i = 0; i < MAX_LENGTH; i++)
    {
        statistics->word_lengths[i] = 0;
    }

    for(int i = 0; i < 26; i++)
    {
        statistics->letter_frequency[i] = 0;
    }

    return;
}



/* Function:    Print table
 *
 * Description: Prints a scaled histogram using unicode block and line
 *              characters. Does not include title or horizontal axis labels.
 *
 * Arguments:   arr[]: An array of values to be represented.
 *              arr_len: the length of arr[]
 *
 * Returns:     Nothing.
 */
void print_table(int arr[], int arr_len)
{
    int big = 0, division = 1, rounded = 1;

    /* find the largest element. */
    for (int i = 0; i < arr_len; ++i)
    {
        if (arr[i] > big)
        {
            big = arr[i];
        }
    }

    /* Find a divisor */
    if (big > MAX_HEIGHT)
    {
        division = big/MAX_HEIGHT;
    }
    /* round the divisor */
    for (int i = 1; rounded < division; rounded += i)
    {
        if (!(rounded % (i * 10)))
        {
            i *= 10;
        }
    }
    division = rounded;

    /* scale the maximum value according to the rounded division */
    while (rounded <= big)
    {
        rounded += division;
    }
    big = rounded / division;

    /* Print the vertical axis and the bars */
    for (; big > 0; --big)
    {
        printf("%6d │", big * division);

        for (int i = 0; i < arr_len; ++i)
        {
            rounded = ((arr[i] - ((big - 1) * division)) * 1000) / division;

            if (rounded < 63)
            {
                printf("  ");
            }
            else if (rounded < 125)
            {
                printf(" _");
            }
            else if (rounded < 250)
            {
                printf(" ▁");
            }
            else if (rounded < 375)
            {
                printf(" ▂");
            }
            else if (rounded < 500)
            {
                printf(" ▃");
            }
            else if (rounded < 625)
            {
                printf(" ▄");
            }
            else if (rounded < 750)
            {
                printf(" ▅");
            }
            else if (rounded < 875)
            {
                printf(" ▆");
            }
            else if (rounded < 1000)
            {
                printf(" ▇");
            }
            else
            {
                printf(" █");
            }
        }

        putchar('\n');
    }

    /* Print horizontal axis (line only) */
    printf("───────┼");

    for (int i = 0; i < arr_len; ++i)
    {
        printf("──");
    }

    return;
}



/* Function:    Analyze Function
 *
 * Description: Fills the arrays declared in stats() and prints out general
 *              statistics.
 *
 * Arguments:   temp_ptr: the file pointer
 *              word_lengths[]: An array representing the total number of
 *               appearances of words with lengths equal to each array index.
 *              letter_frequency[]: an array of elements representing each
 *               letter of the alphabet, to be filled with the total number of
 *               appearances of those letters.
 *
 * Returns:     nothing
 */
void analyze(stat_struct * statistics)
{
    char c, state = OUT;
    char currentWord[46] = { 0 }, currentSentence[MAXLINE] = { 0 };
    int word_len = 0, sen_len = 0, max_word = 0, max_sen = 0;

    /* Count each word and increment the corresponding array element.
     * This loop also contains char, letter, word, and sentence counters.*/
    while ((c = fgetc(statistics->file_ptr)))
    {
        if (c == '_' || c == '.' || c == EOF)
        {
            if (sen_len >= 10)
            {
                ++statistics->sentences; /* need better definition of sentence */
                if (sen_len > max_sen)
                {
                    max_sen = sen_len;
                    sen_len = 0;
                    CPY(statistics->long_sen, currentSentence);
                    statistics->long_sen[max_sen] = c;
                }
            }

            for (int i = 0; i <= sen_len; i++)
            {
                currentSentence[i] = '\0';
            }
            sen_len = 0;

            if (c == EOF)
            {
                break;
            }
        }
        else if (sen_len < MAXLINE-1 && ((c >= ' ' && c <= '~') || c == '\n'))
        {
            currentSentence[sen_len++] = c;
        }

        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;

            if (word_len >= MAX_LENGTH)
            {
                ++statistics->word_lengths[MAX_LENGTH-1];
            }
            else
            {
                ++statistics->word_lengths[word_len];
            }

            if (word_len > max_word)
            {
                max_word = word_len;
                CPY(statistics->long_word, currentWord);
            }

            for (int i = 0; i < 46; i++)
            {
                currentWord[i] = 0;
            }

            word_len = 0;
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (c >= 'a' && c <= 'z')
            {
                ++statistics->letter_frequency[c-97];
            }
            else
            {
                ++statistics->letter_frequency[c-65];
            }

            if (state == OUT)
            {
                state = IN;
                ++statistics->words;
            }

            ++statistics->letters;
            currentWord[word_len++] = c;
        }
        else if (c == '\'' || (c >= '0' && c <= '9'))
        {
            ++statistics->letters;
            currentWord[word_len++] = c;
        }

        ++statistics->chars;
    }

    return;
}



/* Function:    Display Function
 *
 * Description: This function displays the data gathered in the statistics func
 *
 * Arguments:   pointer to the statistics structure
 *
 * Returns:     nothing
 */
void display(stat_struct * statistics)
{
    /***** Table 1: Word Length Histogram *****/
    printf(" Table:     Word Lengths\n───────┬────────────────\n");
    print_table(statistics->word_lengths+1, MAX_LENGTH-1);

    /* Print horizontal axis legend: */
    printf("\n       │");
    for (int i = 1; i < (MAX_LENGTH-1); ++i)
    {
        if (!(i % 5))
        {
            printf("%2d", i);
        }
        else
        {
            printf("  ");
        }
    }
    printf(" +\n\n");


    /***** Table 2: Letter Frequency Histogram *****/
    printf(" Table:   Letter Frequency\n───────┬──────────────────\n");
    print_table(statistics->letter_frequency, 26);

    /* Print horizontal axis legend: */
    printf("\n       │");
    for (int i = 0; i < 26; ++i)
    {
        printf(" %c", i + 65);
    }
    printf("\n\n");


    int max_word = 0;
    while (statistics->long_word[max_word++] != '\0');

    int max_sen = 0;
    while (statistics->long_sen[max_sen++] != '\0');

    /****************** Print totals and averages ******************/
    printf("Number of characters: %d\n", statistics->chars);
    printf("Number of letters:    %d\n", statistics->letters);
    printf("Number of words:      %d\n", statistics->words);
    printf("Number of sentences:  %d\n", statistics->sentences);
    printf("Mean word length:     %.2f letters\n",
           1.0*statistics->letters/statistics->words);
    printf("Mean sentence length: %.2f words\n",
           1.0*statistics->words/statistics->sentences);

    printf("Longest word (%i characters): %s\n",
           max_word, statistics->long_word);

    if (max_sen > 0)
    {
        printf("Longest sentence (%d characters): ", max_sen);
        for (int i = 0; i < max_sen && i <= 100; i++)
        {
            if (statistics->long_sen[i] != '\n')
            {
                putchar(statistics->long_sen[i]);
            }
            else
            {
                putchar(' ');
            }
        }
	    puts(max_sen > 100 ? "..." : ".");
    }
    else
    {
        printf("The longest sentence is: 0 \n\n");
    }


    return;
}



/* * * * * * * * * * * * * * * * * * * MAIN * * * * * * * * * * * * * * * * * */
int main(void)
{
    char cont = 'N', c;
    stat_struct statistics;

    do {
        init_struct(&statistics);

        if (statistics.file_ptr != NULL)
        {
            analyze(&statistics);
            display(&statistics);
            fclose(statistics.file_ptr);
        }
        else
        {
            puts("Error opening file");
        }

        printf("\nContinue? Y/N : ");

        while ((c = getchar()) != '\n' && c != EOF)
        {
            cont = c;
        }
    } while (cont == 'Y' || cont == 'y');

    return 0;
}
