#include <stdio.h>

int vowel(char);
int main()
{
    char str[40];
    int i, p= 0, count = 0;

    printf("Enter a line of text: ");
    gets(str);

    printf("Vowels in successions are in a line :\n");

    for (i = 0; str[i] != '\0'; i++)
    {
        if (vowel(str[i]))
        {
            p++;
        }
        else
        {
            p = 0;
        }

        if (p== 2)
        {
            printf("%c%c\n", str[i - 1], str[i]);
            p= 1;
            count++;
        }
    }

    printf("\nTotal number of occurences vowel: %d", count++);

    return 0;
}

int vowel(char ch)
{
    switch (ch)
    {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return 1;
        default:
            return 0;
    }
}