#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 3500

void count_words_maxlen(char text[],unsigned *spaces, unsigned *max, unsigned len);
void get_word_from_text(char text[], char *buff, unsigned *pos, unsigned max);
void get_word_from_string(char str[], char *buff, unsigned word, unsigned max);
int compare(char *str1, char *str2, unsigned max);
void print(char *arr, unsigned max, unsigned len);
void write_word_to_string(char *str, char *buff, unsigned word, unsigned max);
char* get_unique(char text[], unsigned spaces, unsigned max);
unsigned count_word_in_text(char text[], char *word, unsigned spaces, unsigned max);
char* top_three(char text[], char *unique, unsigned spaces, unsigned max);
unsigned* count_top_words(char str[], unsigned len, char *top, unsigned max);
void program(char *filename);

int main()
{
    program("Input.txt");
    program("test1.txt");
    return 0; 
}

void count_words_maxlen(char text[],unsigned *spaces, unsigned *max, unsigned len)
{
    unsigned count = 0; 
    for (int i=0;i<len;i++) // Ищем количество пробелов между словами и максимальную длину слова
    {
        count++;
        if ((text[i]=='\40')) // || ((int)(text[i])==0) || ((int)(text[i])==10))     // ???????              
        {
            (*spaces)++;
            if (count>(*max))
                *(max) = count;
            count = 0;
        }
    }
    (*spaces)++;
}

void get_word_from_text(char text[], char *buff, unsigned *pos, unsigned max)
{
    unsigned i=0;
    while (text[(*pos)]!='\40') {  //|| ((int)(text[i])!=0) || ((int)(text[i])!=10)) { // ???????
        buff[i] = text[(*pos)];
        (*pos)++;
        i++;
    }
    while (i<max) {
        buff[i] = '*';
        i++;
    }
    while (text[(*pos)]=='\40'||text[(*pos)]=='.'||text[(*pos)]==',') {
        (*pos)++;
    }
}

void get_word_from_string(char str[], char *buff, unsigned word, unsigned max) 
{
    for (int i=0;i<max;i++) {
        buff[i] = str[word*max+i];
    }
}

int compare(char *str1, char *str2, unsigned max)
{   
    for (int i=0;i<max;i++) {
        if (str1[i]!=str2[i] && (str1[i]!=',' && str2[i]!=',') && (str1[i]!='.' && str2[i]!='.')
        && (str1[i]!='?' && str2[i]!='?') && (str1[i]!='(' && str2[i]!='(') && (str1[i]!=')' && str2[i]!=')')
        && (((int)(str1[i]) + 32) != (int)(str2[i])) && (((int)(str1[i]) - 32) != (int)(str2[i])))
            return 0;
    }
    return 1;
}

void print(char *arr, unsigned max, unsigned len)
{
    for (int i=0,j=1;i<len;i++,j++) {
        printf("%c\t",arr[i]);
        if (j%max==0) {
            printf("\n");
            j=0;
        }
    }
}

void write_word_to_string(char *str, char *buff, unsigned word, unsigned max)
{
    for (int i=0;i<max;i++) {
        str[word*max+i] = buff[i];
    }
}

char* get_unique(char text[], unsigned spaces, unsigned max)
{
    unsigned pos = 0;
    unsigned words = 0;
    char *unique = (char*)malloc(spaces*max*sizeof(char));
    char *buff1 = (char*)malloc(max*sizeof(char));
    char *buff2 = (char*)malloc(max*sizeof(char)); 
    for (int i=0;i<spaces*max*sizeof(char);i++) {
        unique[i] = '*';
    }
    for (int i=0;i<max*sizeof(char);i++) {
        buff1[i] = '*';
        buff2[i] = '*';
    }
    for (int i=0;i<spaces;i++) {
        get_word_from_text(text,buff1,&pos,max);
        for (int j=0;j<words;j++) {
            get_word_from_string(unique,buff2,j,max);
            if (compare(buff1,buff2,max)==1)
                break;
        }
        if (compare(buff1,buff2,max)==0) {
            write_word_to_string(unique,buff1,words,max);
            words++;
        }
    }
    return unique;
}

unsigned count_word_in_text(char text[], char *word, unsigned spaces, unsigned max)
{
    unsigned pos = 0, result = 0;
    char *buff = (char*)malloc(max*sizeof(char));

    for (int i=0;i<spaces;i++) {
        get_word_from_text(text,buff,&pos,max);
        if (compare(word,buff,max)==1)
            result++;
    }
    return result;
}

char* top_three(char text[], char *unique, unsigned spaces, unsigned max)
{
    unsigned *quantities = (unsigned*)malloc(3*sizeof(unsigned));
    char *result = (char*)malloc(3 * max * sizeof(char));
    char *buff = (char*)malloc(max*sizeof(char));
    char *buff1 = (char*)malloc(max*sizeof(char));
    char *buff2 = (char*)malloc(max*sizeof(char));
    unsigned count = 0;
    for (int i=0;i<3;i++) {
        quantities[i] = 0;
    }
    for (int i=0;i<3*max*sizeof(char);i++) {
        result[i] = '*';
    }
    for (int i=0;i<max*sizeof(char);i++) {
        buff[i] = '*';
        buff1[i] = '*';
        buff2[i] = '*';
    }
    for (int i=0;i<spaces;i++) {
        get_word_from_string(unique,buff,i,max);
        count = count_word_in_text(text,buff,spaces,max);
        if (count > quantities[0]) {
            get_word_from_string(result,buff1,0,max);
            get_word_from_string(result,buff2,1,max);
            write_word_to_string(result,buff,0,max);
            write_word_to_string(result,buff1,1,max);
            write_word_to_string(result,buff2,2,max);
            quantities[0] = count;
        } else if(count > quantities[1]) {
            get_word_from_string(result,buff1,1,max);
            write_word_to_string(result,buff,1,max);
            write_word_to_string(result,buff1,2,max);
            quantities[1] = count;
        } else if (count > quantities[2]) {
            write_word_to_string(result,buff,2,max);
            quantities[2] = count;
        }  
    }
    return result;
}

unsigned* count_top_words(char str[], unsigned len, char *top, unsigned max)
{
    unsigned spaces = 0, useless = 0,pos = 0;
    count_words_maxlen(str,&spaces,&useless,len);
    // printf("%u\n",spaces);
    char *buff1 = (char*)malloc(max*sizeof(char));
    char *buff2 = (char*)malloc(max*sizeof(char));
    unsigned *result = (unsigned*)malloc(3*sizeof(unsigned));
    result[0] = 0;
    result[1] = 0;
    result[2] = 0;
    for (int i=0;i<max*sizeof(char);i++) {
        buff1[i] = '*';
        buff2[i] = '*';
    }
    for (int i=0;i<3;i++) {
        get_word_from_string(top,buff1,i,max);
        for (int j=0;j<spaces;j++) {
            get_word_from_text(str,buff2,&pos,max);
            if (compare(buff1,buff2,max)==1) {
                (result[i])++;
            }
        }
        pos = 0;
    }
    return result;
}

void program(char *filename)
{
    char text[N];
    FILE *ft = fopen(filename,"r");
    size_t written = fread(text,sizeof(text[0]),N,ft);
    printf("File: %s, written %u symbols \n",filename,written);
    unsigned max = 0, spaces = 0, len = sizeof(text)/sizeof(text[0]);
    count_words_maxlen(text,&spaces,&max,len);
    char *unique = get_unique(text,spaces,max);
    char *top = top_three(text,unique,spaces,max);
    fclose(ft);

    FILE *fw = fopen(filename,"a");
    fprintf(fw,"\n#\n");
    fprintf(fw,"Most frequent words: ");
    for (int i=0;i<3;i++) {
        for (int j=0;j<max;j++) {
            if (top[max*i+j]!='*') {
                fprintf(fw,"%c",top[max*i+j]);
            } else if (i!=2) {
                fprintf(fw,",");
                break;
            } 
        }
    }
    fprintf(fw,"\n");
    fprintf(fw, "+------------------------------------------+\n");
    fprintf(fw,"| String number | Word 1 | Word 2 | Word 3 | \n");

    FILE *fs = fopen(filename,"r");
    char str[256];
    int c = 1;
    while ((fgets(str,256,fs))!=NULL) {
        if (str[0]=='#')
            break;
        // if (text[strlen(text)-2]!=' ') {
        // text[strlen(text)-1] = ' ';
        // }
        // printf(str);
        len = 0;
        for (int i=0;(int)(str[i])!=0;i++)
            len++;
        // printf("%d\n",len);
        unsigned *result = count_top_words(str,len,top,max);
        fprintf(fw,"|\t\t%d\t\t|\t%d\t |\t  %d\t  |\t  %d    |\n",c,result[0],result[1],result[2]);
        c++;
    }
    fprintf(fw, "+------------------------------------------+\n");
    fclose(fs);
    fclose(fw);
}
