#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int LETTER_VALUE[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int N = 2;

void make_upper(string s);
int get_points(string s);
void winner(int points[]);

int main(void)
{
    string users_ans[N];
    int answers_points[N];

    for (int i = 0; i < N; i++)
    {
        // get user input
        users_ans[i] = get_string("Player %i: ", i + 1);
        // normalize the string to uppercase
        make_upper(users_ans[i]);
        // get the points the string
        answers_points[i] = get_points(users_ans[i]);
    }
    // get winner
    winner(answers_points);
}

void make_upper(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        s[i] = toupper(s[i]);
    }
}

int get_points(string s)
{
    int total = 0;
    int length = strlen(s);
    int char_val;

    for (int i = 0; i < length; i++)
    {
        char_val = LETTER_VALUE[(int) s[i] - 65];
        total += char_val;
    }

    return total;
}

void winner(int points[])
{
    if (points[0] > points[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (points[1] > points[0])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
