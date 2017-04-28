void ReplaceBlank(char string[], int length)
{
    if(string == NULL && length<=0)
        return;

    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;

    while(string[i] != '\0')
    {
        ++originalLength;
        if(string[i] == ' ')
            ++numberOfBlank;
        ++i;
    }

    int newLength = originalLength + numberOfBlank*2;

    if(newLength <= length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfNew >= indexOfOriginal && indexOfOriginal >= 0)
    {
        if (string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
            --indexOfOriginal;
        }
        else
        {
            string[indexOfNew--] = string[indexOfOriginal--];
        }
    }

}
