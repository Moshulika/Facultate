// Procesor RISC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <math.h>

struct registry
{

    int value;

};

int strlen(char a[])
{

    int i = 0;

    while (a[i] != 0)
    {

        i++;

    }

    return i;

}

char* split(char a[], char c)
{

    static char* input = NULL;

    if (a != NULL) input = a; //Daca stringu initial nu e null
    if (input == NULL) return NULL;

    char* result = new char[strlen(input) + 1]; //Aici vom stoca caracterele pana la caracterul dorit
     
    int i = 0;

    for (i; input[i] != 0; i++)
    {
        //Daca caracteru nu e ala pe care il cautam il bagam in rezultate
        if (input[i] != c) result[i] = input[i];
        else
        {
            result[i] = '\0'; //Daca este, oprim stringu
            input = input + i + 1; //Si pentru o apelare ulterioara salvam pointeru unde am ramas
            return result;
        }

    }

    result[i] = '\0';
    input = NULL;


    return result;
}

int equalsIgnoreCase(char a[], char b[])
{


    for (int i = 0; i < strlen(a); i++)
    {

        //Daca nu e egal
        if (a[i] != b[i])
        {

            //Daca e litera
            if (a[i] >= 65 && a[i] <= 122 && b[i] >= 65 && b[i] <= 122)
            {

                if (a[i] >= 97)
                {
                    if (a[i] - 32 != b[i]) return 0;
                }

                if (a[i] + 32 != b[i]) return 0;

            }
            else
            {
                return 0;
            }

        }

    }

    return 1;

}

int equals(char a[], char b[])
{


    for (int i = 0; i < strlen(a); i++)
    {

        if (a[i] != b[i]) return 0;

    }

    return 1;

}

int equals(char a[], const char b[])
{


    for (int i = 0; i < strlen(a); i++)
    {

        if (a[i] != b[i]) return 0;

    }

    return 1;

}

int getFromChar(char c)
{
    return c - '0';
}

int countDigits(char* p)
{

    int i = 0;

    while (p[i] != 0)
    {
        i++;
    }

    return i;

}

int getNumberFromString(char* p)
{

    int i = 0;
    int nr = 0;

    int digits = countDigits(p);
    int pwr = 0;

    if (digits == 1)
    {
        return getFromChar(p[i]);
    }

    //10, //2
    while (p[i+1] != 0)
    {

        pwr = digits - 2 - i;
        nr += getFromChar(p[i]) * pow(10, pwr);
        i++;

    }

    return nr;

}

int dispatchCommand(char a[], registry *heap)
{
  
    char* p = split(a, ' ');

    int dst = 0;
    int x = 0;
    int y = 0;

    if (equals(p, "lconst"))
    {
        p = split(NULL, ' ');

        dst = getNumberFromString(p);
        
        p = split(NULL, ' ');

        x = getNumberFromString(p);

        registry* dest = heap + dst;

        dest->value = x;

    }
    else if (equals(p, "add"))
    {

        p = split(0, ' ');
        dst = getNumberFromString(p);

        p = split(0, ' ');
        x = getNumberFromString(p);

        p = split(0, ' ');
        y = getNumberFromString(p);

        registry* dest = heap + dst;

        dest->value = heap[x].value + heap[y].value;

    }
    else if (equals(p, "mul"))
    {

        p = split(0, ' ');
        dst = getNumberFromString(p);

        p = split(0, ' ');
        x = getNumberFromString(p);

        p = split(0, ' ');
        y = getNumberFromString(p);

        registry* dest = heap + dst;

        dest->value = heap[x].value * heap[y].value;

    }
    else if (equals(p, "div"))
    {

        p = split(0, ' ');
        dst = getNumberFromString(p);

        p = split(0, ' ');
        x = getNumberFromString(p);

        p = split(0, ' ');
        y = getNumberFromString(p);

        if (heap[y].value == 0) return -1;

        registry* dest = heap + dst;

        dest->value = heap[x].value / heap[y].value;

    }
    else if (equals(p, "print"))
    {

        p = split(0, ' ');
        dst = getNumberFromString(p);

        printf("%d\n", heap[dst].value);
    }

    return 0;
}


int main()
{

    int n = 0;

    scanf_s("%d *[^\n]", &n);
    fflush(stdin);

    registry heap[16];

    for (int i = 0; i < 16; i++)
    {
        heap[i].value = 0;
    }

    char line[50];

    int e = 0;

    for(int i = 0; i < n ; i++)
    {

        fgets(line, sizeof(line), stdin);
        
        e = dispatchCommand(line, heap);

        if (e == -1)
        {
            printf("Exception: line " + (i + 1));
            break;
        }


    }
   

    return 0;

}
