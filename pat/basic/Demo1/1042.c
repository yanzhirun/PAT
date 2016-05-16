#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main ()
{
    char input_string[1001];
    int length_input, i, num_char, tmp = 0, output = 0;
    int character[26] = {0};
    scanf ("%[^\n]", input_string);
    length_input = strlen (input_string);
    for (i = 0; i < length_input; i++)
    {
        if (input_string[i] >= 'a' && input_string[i] <= 'z')
        {
            num_char = (int)input_string[i] - 'a';
        }
        else if (input_string[i] >= 'A' && input_string[i] <= 'Z')
        {
            num_char = (int)input_string[i] - 'A';
        }
        else
            continue;
        character[num_char]++;
    }
    for (i = 0; i <26; i++)
    {
        if (tmp < character[i])
        {
            tmp = character[i];
            output = i;
        }
    }
    printf("%c %d", (output + 'a'), tmp);

    return 0;
}
