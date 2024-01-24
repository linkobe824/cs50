#include <cs50.h>
#include <math.h>
#include <stdio.h>

string company(long card);
bool luhn(long card);
int sum_card_numbers(long card);

int main(void)
{
    long card_number = get_long("Number: ");
    string company_card = company(card_number);

    if (company_card)
    {
        if (luhn(card_number))
            printf("%s\n", company_card);
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}

bool luhn(long card)
{
    if (sum_card_numbers(card) % 10 == 0)
        return true;
    return false;
}

int sum_card_numbers(long card)
{
    long num = card;
    int count = 1;
    int digit;
    int doubled_digit;
    int every_other_sum = 0;
    int not_every_other_sum = 0;

    while (num)
    {
        digit = num % 10;
        // every other from second digit
        if (count % 2 == 0)
        {
            doubled_digit = digit * 2;
            if (doubled_digit > 9)
                every_other_sum += 1 + (doubled_digit % 10);
            else
                every_other_sum += doubled_digit;
        }
        // digits not doubled
        else
            not_every_other_sum += digit;

        num = num / 10;
        count++;
    }
    return every_other_sum + not_every_other_sum;
}

string company(long card)
{
    int count = 0;
    long num = card;

    while (num)
    {
        num = num / 10;
        count++;
    }

    double divisor = pow(10, count - 1);
    int first_digits;
    int visa_digit;
    // amex
    if (count == 15)
    {
        first_digits = card / divisor * 10;
        if (first_digits == 34 || first_digits == 37)
            return "AMEX";
    }
    // mastercard or visa
    else if (count == 16)
    {
        first_digits = card / divisor * 10;
        visa_digit = card / divisor;
        if (first_digits == 51 || first_digits == 52 || first_digits == 53 || first_digits == 54 || first_digits == 55)
            return "MASTERCARD";
        else if (visa_digit == 4)
            return "VISA";
    }
    // visa
    else if (count == 13)
    {
        visa_digit = card / divisor;
        if (visa_digit == 4)
            return "VISA";
    }

    return NULL;
}
