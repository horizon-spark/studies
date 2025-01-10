/* in_out.c
----------------------
(�)�����: ���������� �.�.
������  : ����-��-23
���� 25.03.2024
----------------------------------------------------
1) ���� ������� � ��� ����� � ���������� ���� � � ���� ����.
2) ���� ������ ��������, ����������� � ����� � ����� ������ �������� � ��������� � �����.
3) ���� ���� ����� ���������� ����� � �� ����� � ���������� � ����������������� ���� � �������������� ������������ ������������ ����� ���������� ����� � ��� ������������.
4) ���� ���� ����� � ��������� ������ � �� ����� � ���������� � ���������������� ������ � �������� ���������. 
5) ���� ������ ������������ ����� � ��� ����� � ���� ����������� ������ ��� �����, ������������� ������ ��� �����, ������������������ ������ ��� �����.*/

#include <stdio.h>	
#include <string.h>

int main()
{ 
    char symbol;
    char string_1[15],string_2[15],string_3[15],string_4[15],string_5[15];
    int number_1,number_2;
    float float_number_1,float_number_2;
    unsigned int unsigned_number;
    printf("Input data: ");
    scanf("%c",&symbol);
    scanf("%s %s %s %s %s",string_1,string_2,string_3,string_4,string_5);
    size_t str_len = strlen(string_1)+strlen(string_2)+strlen(string_3)+strlen(string_4)+strlen(string_5);
    scanf("%i %i",&number_1,&number_2);
    scanf("%f %f",&float_number_1,&float_number_2);
    printf("Output data: \n");
    printf("1) Given symbol is '%c' (ASCII code is '%i')\n2) Given string is '%s %s %s %s %s' (Length %zu symbols)\n3) %-10i %-10i %-10x %-10x \n%3i %3i %3x %8x \n \
    %10i %10i %10x %10x \n4) %7.3f %7.3f %6.3e %6.3e \n5) %u %o %x \n",symbol,symbol,string_1,string_2,string_3,string_4,string_5,str_len,number_1,number_2,number_1,\
    number_2,number_1,number_2,number_1,number_2,number_1,number_2,number_1,number_2,float_number_1,float_number_2,float_number_1,float_number_2,unsigned_number,\
    unsigned_number,unsigned_number);
    return 0;
}