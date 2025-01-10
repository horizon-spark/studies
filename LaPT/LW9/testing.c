#include <stdio.h>
#include <string.h>

int main()
{
    char text[20];
    printf("Input text: ");
    scanf("%s",text);
    printf("Number of elements in array: %d",strlen(text));
}