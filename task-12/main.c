#include <stdio.h>
#include <stdlib.h>

int main()
{
    char text[100];
    int count[26] = {0};

    printf("Enter text: ");
    scanf("%[^\n]", text);

    char check = 'a';

    for (int i = 0; i < 26; i++)
    {
        char *ptr = text;

        while (*ptr != '\0')
        {
            if (*ptr == check)
            {
                count[i]++;
            }

            ptr++;
        }

        check++;
    }

    int max = count[0];

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
        }
    }

    check = 'a';

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            printf("%c = %d\n", check, count[i]);
        }

        check++;
    }

    printf("Max is %d\n", max);

    printf("Most popular: ");

    check = 'a';

    for (int i = 0; i < 26; i++)
    {
        if (count[i] == max)
        {
            printf("%c ", check);
        }

        check++;
    }

    printf("\n");

    return 0;
}
