/* Memory.c
------------------------
(с)оздал: Кадарметов Д.Н.
группа  : БИВТ-ВП-23
дата    : 16.03.2024
---------------------------------
1) Вычисление размера памяти, отводимой компилятором под тип signed_char
2) Вычисление размера памяти, отводимой под символ "?" 
3) Вычисление предельных значений для типа unsighed_char "*/

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Memory used for type 'signed_char' is %d b.\n",sizeof(signed char));
    printf("Memory used for symbol '?' is %d b.\n",sizeof('?'));
    printf("Range of 'unsigned_char' data type is %d to %d",0, UCHAR_MAX);
    return 0;
}