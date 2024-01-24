// index = 0.0588 * L - 0.296 * S - 15.8
// L = average number of letters per 100 words
// S = average number of sentences per 100 words

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text, int size);
int count_words(string text, int size);
int count_sentences(string text, int size);
int coleman_liau_index(int letters, int words, int sentences);
void print_grade(int index);

int main(void)
{
    string text = get_string("Text: ");

    int size = strlen(text);

    int letters = count_letters(text, size);
    int words = count_words(text, size);
    int sentences = count_sentences(text, size);

    int index = coleman_liau_index(letters, words, sentences);

    print_grade(index);
}

int count_letters(string text, int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        if (isalpha(text[i]))
            total++;
    }
    return total;
}

int count_words(string text, int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        if (text[i] == ' ')
            total++;
    }
    return total + 1;
}

int count_sentences(string text, int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            total++;
    }
    return total;
}

int coleman_liau_index(int letters, int words, int sentences)
{
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    return round(0.0588 * L - 0.296 * S - 15.8);
}

void print_grade(int index)
{
    if (index >= 16)
        printf("Grade 16+\n");
    else if (index < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %i\n", index);
}
