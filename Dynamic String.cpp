#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * Dynamic allocation for a string 
 * and concatenation
 * By Nanescu Eduard
 * 
 */

char* readString(int &x)
{

    
    char *s1 = (char*) malloc(1 * sizeof(char));
    
    char c;
    int i = 1;
    
    while((c=getc(stdin)) != '\n')
    {
        *(s1 + i) = c;
        s1 = (char*) realloc(s1, sizeof(char) * i);
        i++;
    }
    
    *(s1 + i) = '\0';
    x = i;
    return s1;
    
}

char* concat(char* s, char* s2, int size1, int size2)
{
    
    char *fin = (char*) malloc((size1 + size2) * sizeof(char));
    
    for(int i = 0; i < size1; i++)
    {
        *(fin + i) = *(s + i);
    }
    
    for(int i = 0; i < size2; i++)
    {
        *(fin + size1 + i) = *(s2 + i);
    }
    
    return fin;
}

void printString(char* s, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%c", *(s + i));
    }
}

int main()
{
    
    int size1, size2 = 0;
    
    char* s = readString(size1);
    char* s2 = readString(size2);
    
    char* fin = concat(s, s2, size1, size2);
    printString(fin, size1 + size2);
    
    return 0;
}
