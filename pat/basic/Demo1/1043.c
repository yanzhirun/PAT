#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main()
{
    int i, j, length_arr, max = 0;
    char arr_char_input[10001];
    int arr_six[6] = {0};
    char PATest[6] = {'P', 'A', 'T', 'e', 's', 't'};

    scanf ("%s", arr_char_input);
    length_arr = strlen(arr_char_input);
    for (i = 0; i < length_arr; i++)
    {
        if (arr_char_input[i] == 'P')
            arr_six[0]++;
        else if (arr_char_input[i] == 'A')
            arr_six[1]++;
        else if (arr_char_input[i] == 'T')
            arr_six[2]++;
        else if (arr_char_input[i] == 'e')
            arr_six[3]++;
        else if (arr_char_input[i] == 's')
            arr_six[4]++;
        else if (arr_char_input[i] == 't')
            arr_six[5]++;
        else
            continue;
    }

    for (i = 0; i < 6; i++)
    {
         if (arr_six[i] > max)
             max = arr_six[i];
    }
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < 6; j++)
            if (arr_six[j]-- > 0)
                printf ("%c", PATest[j]);
    }

    return 0;
}
