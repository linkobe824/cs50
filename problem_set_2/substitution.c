#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char cipher_lower(char letter, string key);
char cipher_upper(char letter, string key);

int main(int argc, string argv[])
{
    // array for the key set to null
    char input_key[26];
    memset(input_key, '\0', 26);

    // check for only 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int size = strlen(argv[1]);

    // check the size of the key
    if (size != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // check if key is valid.
    char key_char;
    for (int i = 0; i < size; i++)
    {
        key_char = argv[1][i];
        if (!isalpha(key_char))
        {
            printf("Key must contain only alphabetic characters\n");
            return 1;
        }

        if (islower(key_char))
        {
            if (input_key[((int) key_char) - 97] == '\0')
                input_key[((int) key_char) - 97] = key_char;
            else
            {
                printf("Key must contain not repeated characters -> %c\n", key_char);
                return 1;
            }
        }
        else
        {
            if (input_key[((int) key_char) - 65] == '\0')
                input_key[((int) key_char) - 65] = key_char;
            else
            {
                printf("Key must contain not repeated characters -> %c\n", key_char);
                return 1;
            }
        }
    }

    string key = argv[1];

    string plaintext = get_string("plaintext: ");
    int text_size = strlen(plaintext);
    char ciphertext[text_size + 1];

    // ciphering
    for (int i = 0; i < text_size; i++)
    {
        // if character is not a letter, continue to next character
        if (!isalpha(plaintext[i]))
            ciphertext[i] = plaintext[i];
        else if (islower(plaintext[i]))
            // change to lower
            ciphertext[i] = cipher_lower(plaintext[i], key);
        else
            // change to upper
            ciphertext[i] = cipher_upper(plaintext[i], key);
    }
    ciphertext[text_size] = '\0';
    printf("ciphertext: %s", ciphertext);
    printf("\n");

    return 0;
}

char cipher_lower(char letter, string key)
{
    int letter_index = ((int) letter) - 97;
    char ciphered_char = key[letter_index];
    if (islower(key[letter_index]))
        return key[letter_index];
    else
        return tolower((char) key[letter_index]);
}

char cipher_upper(char letter, string key)
{
    int letter_index = ((int) letter) - 65;
    char ciphered_char = key[letter_index];
    if (isupper(key[letter_index]))
        return key[letter_index];
    else
        return toupper((char) key[letter_index]);
}
