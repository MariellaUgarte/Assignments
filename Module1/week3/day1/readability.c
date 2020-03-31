#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
/* Crear la funcion count_letters, count_words y count_senteces*/


int count_letters(string input)
{
    int letters = 0;
    long int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            letters++;
        }
    }
    return letters;
}
int count_words(string input)
{
    int words = 1;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ' && input[i + 1] != ' ')
        {
            words++;
        }
    }
    return words;
}
int count_sentences(string input)
{
    int sentences = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!' || input[i] == '\n')
        {
            sentences++;
        }
    }
    return sentences;
}

int main()
{
    /* Input string*/

    string input = get_string("Text: ");

    float l, s;
    int letters = count_letters(input);
    int words = count_words(input);
    int sentences = count_sentences(input);
    /*printf ("Letters: %d \n", letters);*/

    /*printf ("Words: %d \n",   words);*/

    /*printf ("Sentences: %d \n", sentences);*/

    l = (letters * 1.0 / words) * 100;
    s = (sentences * 1.0 / words) * 100;
    float index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index >= 1 && index <= 16)
    {

        printf("Grade %d\n", (int)index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}
