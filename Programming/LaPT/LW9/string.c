/* string.c
-------------------------
(с)оздал: Кадарметов Д.Н.
группа  : БИВТ-ВП-23
дата    : 04.05.2024
---------------------------------------------------------------------------------------------
1) Вывод на экран исходного слова.
2) Вычисление количества символов, которые заключены в круглые скобки, и вывод его на экран.
3) Вывод на экран результатов теста. */

#include <stdio.h>
#include <string.h>
#define max_len 20

void count_letters_in_brackets(char text[max_len]);

int main()
{
    char text[max_len] = "Hel(gfdgdg)ddf";
    printf("%s\n",text);
    count_letters_in_brackets(text);

    // тест 

    printf("\t Test\n");
    printf("1) 'Helloworld!' - No brackets (expected result: 0)\n");
    count_letters_in_brackets("Helloworld!");
    printf("2) 'H(elloworld!' - No closing bracket (expected result: 0)\n");
    count_letters_in_brackets("H(elloworld!");
    printf("3) 'Hellowo)rld!' - No opening bracket (expected result: 0)\n");
    count_letters_in_brackets("Hellowo)rld!");
    printf("4) 'Hellow()orld!' - Empty brackets (expected result: 0)\n");
    count_letters_in_brackets("Hellow()orld!");
    printf("5) 'He(lloworl)d!' - Middle part in brackets (expected result: 7)\n");
    count_letters_in_brackets("He(lloworl)d!");
    printf("6) '(Hello)world!' - Beginning in brackets (expected result: 5)\n");
    count_letters_in_brackets("(Hello)world!");
    printf("7) 'Hello(world!)' - End in brackets (expected result: 6)\n");
    count_letters_in_brackets("Hello(world!)");
    printf("8) '(Helloworld!)' - Whole word in brackets (expected result: 11)\n");
    count_letters_in_brackets("(Helloworld!)");
    return 0;
}

void count_letters_in_brackets(char text[max_len])
{
    char *ptr_text = text;
    unsigned int index_begin = 0, index_end = 0, count = 0, len = strlen(text);

    while (*ptr_text != '(' && index_begin < len) {
        ptr_text++;
        index_begin++;
    }

    if (index_begin == len) {
        printf("Total symbols in brackets: 0\n");
    } else {
        index_end = index_begin;
        while (*ptr_text != ')' && index_end < len) {
            ptr_text++;
            index_end++;
        }
        if (*ptr_text != ')' && index_end == len) {
            printf("Total symbols in brackets: 0\n");
        } else {
            count = index_end - index_begin - 1;
            printf("Total symbols in brackets: %u\n",count);
        }
    }
}