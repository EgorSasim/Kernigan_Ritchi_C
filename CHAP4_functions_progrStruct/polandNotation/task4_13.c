#include <stdio.h>
#include <string.h>

// Function to swap two given characters
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}


// Recursive function to reverse a given string
void reverse(char str[], int l, int h)
{
    if (l < h)
    {
        swap(&str[l], &str[h]);
        reverse(str, l + 1, h - 1);
    }
}


int main(void)
{
    char str[] = "hello world!!!";
    reverse(str, 0, strlen(str) - 1); 
    printf("%s\n", str);

    return 0;
}
