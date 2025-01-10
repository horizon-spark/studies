/* structures.c
-------------------------
(с)оздал: Кадарметов Д.Н.
группа  : БИВТ-ВП-23
дата    : 02.06.2024
-----------------------------------------------------------------------------------------------------------------
1) Считывание с экрана элементов структуры "Покупатель" (фамилия, имя, отчество, домашний адрес, номер телефона, 
номер кредитной карточки) для массива структур и вывод его на экран.
2) Сортировка считанного массива структур по имени (в алфавитном порядке) и вывод полученного результата.
3) Поиск структуры в массиве по номеру телефона и вывод ее на экран.
4) Удаление структуры из массива по фамилии и вывод полученного массива на экран.
5) Вывод на экран результатов теста. */

#include <stdio.h>
#include <string.h>
#define N 5 // Количество элементов в массиве структур

struct client 
{
    char name[25];
    char surname[25];
    char patronymic [25];
    char adress[50];
    char phone_number[15];
    char card_number[20];
};

void input(struct client people[N])
{
    for (int i=0;i<N;i++) {
        printf("Input person's %d name: ",i+1);
        scanf("%s",people[i].name);
        printf("Input person's %d surname: ",i+1);
        scanf("%s",people[i].surname);
        printf("Input person's %d patronymic: ",i+1);
        scanf("%s",people[i].patronymic);
        printf("Input person's %d adress: ",i+1);
        scanf("%s",people[i].adress);
        printf("Input person's %d phone number: ",i+1);
        scanf("%s",people[i].phone_number);
        printf("Input person's %d card number: ",i+1);
        scanf("%s",people[i].card_number);
    }
}

void print_struct(struct client person)
{
    printf("Name: %s\nSurname: %s\nPatronymic: %s\nAdress: %s\nPhone number: %s\nCard Number: %s\n", 
    person.name,person.surname,person.patronymic,person.adress,person.phone_number,person.card_number);
    printf("\n");
}

void print_arr(struct client people[], unsigned n)
{
    for (int i=0;i<n;i++) {
        printf("Person %d\n",i+1);
        printf("Name: %s\nSurname: %s\nPatronymic: %s\nAdress: %s\nPhone number: %s\nCard Number: %s\n", 
        people[i].name,people[i].surname,people[i].patronymic,people[i].adress,people[i].phone_number,people[i].card_number);
        printf("\n");
    }
}

unsigned compare_names(char str1[], char str2[], unsigned max)
{
    for (int i=0;i<max;i++) {
        if (strcmp(str1,str2)<0)
            return 1;
        else if (strcmp(str1,str2)>0)
            return 2;
    }
}

void swap_people(struct client people[], unsigned i, unsigned j)
{
    struct client buff = people[i];
    people[i] = people[j];
    people[j] = buff;
}

struct client* sort_by_name(struct client people[])
{
    for (int i=0;i<N-1;i++) {
        for (int j=0;j<N-i-1;j++) {
            if (compare_names(people[j].name,people[j+1].name, 25)==2)
                swap_people(people,j,j+1);
        }
    }
    return people;
}

void find_by_phone_number(struct client people[], char number[15])
{
    printf("Attempt to find person with number '%s':",number);
    int i=0;
    while (i<N) {
        if (strcmp(people[i].phone_number, number)==0) {
            printf(" success\nFound person:\n");
            print_struct(people[i]);
            return;
        }
        i++;
    }
    printf(" failure\nNo person with number '%s' is found\n",number);
}

void delete_by_surname(struct client people[], char surname[25])
{
    printf("Attempt to delete person with surname '%s':",surname);
    for (int i=0;i<N;i++) {
        if (strcmp(people[i].surname,surname)==0) {
            for (int j=0;j<N-1;j++) {
                if (j<i)
                    people[j] = people[j];
                else if (j>i)
                    people[j] = people[j+1];
            }
            printf(" success\nArray after the deletion:\n");
            print_arr(people,N-1);
            return;
        }
    }
    printf(" failure\nNo person to delete is found by surname '%s'.\n",surname);
    printf("Array was not changed:\n");
}

int main()
{
    struct client people[N];
    input(people);
    printf("\nBefore sort:\n\n");
    print_arr(people,N);
    printf("After sort:\n\n");
    struct client *sorted = sort_by_name(people);
    print_arr(sorted,N);
    find_by_phone_number(people,"+79603925321");
    delete_by_surname(people,"Tolstoy");
    // Test 
    struct client test[] = 
    { {"Michail", "Lermontov", "Yurevitch", "Moscow,Kolonchevskaya_str.,23", "+78003810439", "1043920473829503"},
    {"Leo", "Tolstoy", "Nickolaevitch", "Moscow,Tverskaya_str.,12", "+79602142311", "6920385921053863"}, 
    {"Fyodor", "Dostoevskiy", "Michailovitch", "St.Petersburg,Ligovskiy_ave.,65", "+79343797840", "1305396503219224"},
    {"Anton", "Chechov", "Pavlovitch", "St.Petersburg,Nicolaevskaya_str.,61", "+78004326534", "4214965034829543"},
    {"Alexandr", "Pushkin", "Sergeevitch", "Moscow,Arbat_str.,53", "+79603925321", "4312345236756785"} };
    printf("1) Sorting test\n");
    printf("Members of the structure are in total disarray: \n");
    print_arr(test,N);
    printf("After sorting by name (expected: Alexandr,Anton,Fyodor,Leo,Michail): \n");
    struct client *sorted = sort_by_name(test);
    print_arr(sorted,N);
    printf("2) Search test\n");
    printf("a) existing number +79343797840 (expected to find Fyodor)\n");
    find_by_phone_number(test,"+79343797840");
    printf("b) non-existing number +78359396435 (expected not to find anyone)\n");
    find_by_phone_number(test,"+78359396435");
    printf("\n3) Delete test\n");
    printf("a) non-existing person (expected not to change the initial array)\n");
    delete_by_surname(test,"Shakespeare");
    printf("b) existing person (expected to return an array without one person)\n");
    delete_by_surname(test,"Lermontov");

    return 0;
}


