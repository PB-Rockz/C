#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    char text[1000];
    printf("Enter a line of text: ");
    fgets(text, sizeof(text), stdin);

    int count = 0;
    int length = strlen(text);

    for (int i = 0; i < length - 1; i++)
    {
        if (isVowel(text[i]) && isVowel(text[i + 1]))
        {
            printf("Found: %c%c\n", text[i], text[i + 1]);
            count++;
        }
    }

    printf("Number of occurrences of two successive vowels: %d\n", count);

    return 0;
}
