#include <stdio.h>
#include <stdlib.h>

struct linie
{
    char chars[100];
};

struct perechi
{
    int nr = 0;
    int zero = 0;
};

int contains(perechi per[100], int numar)
{

    for (int i = 0; i < 100; i++)
    {

        if (per[i].nr == numar) return 1;

    }

    return 0;

}


int countZero(char a[100], int start)
{
    int zeros = 0;

    for (int i = start; i < 100; i++)
    {

        if (a[i] == ',') continue;

        if (a[i] == 48) zeros++;
        else break;

    }

    return zeros;
}

int getNumber(char c)
{
    int i = c - '0';
    return i;

}



perechi* findPairs(char a[100]) //perechile pt fiecare linie
{

    perechi* per = (perechi*) malloc(100 * sizeof(perechi));

    for (int i = 0; i < 100; i++)
    {
        per[i].nr = 0;
        per[i].zero = 0;
    }

    int z = 0;
    int NUMAR = 0;
    int l = 0;



    for (int i = 0; i < 100; i++)
    {

        if (a[i] == 0) break;
        if (a[i] == ',' || a[i] == '0') continue;

        //Daca urm. char nu e 0 sau , 
        if (a[i + 1] != '0' && a[i + 1] != ',' && a[i + 1] != 0)
        {
            
            //Inseamna ca mai are o cifra si tre sa il construim
            NUMAR = 10 * getNumber(a[i]) + getNumber(a[i + 1]);
            printf("Numar de 2 cifre: %d\n", NUMAR);
            l = 3;
        }      
        else
        {
            if (a[i] != '0')
            {
                
                //E doar o cifra
                NUMAR = getNumber(a[i]);
                printf("Numar de o cifra: %d\n", NUMAR);
                l = 2;
            }

        }
        
        //Sigur nu e virgula
        z = countZero(a, i + l);
        printf("Sir detectat ce incepe la %d si are %d zerouri\n", NUMAR, z);

        per[i].nr = NUMAR;
        per[i].zero = z;

        if (l == 3) i++;
   
    }

    return per;

}

int hasZeroInPair(perechi per)
{

    return per.zero != 0;

}

int isValid(perechi per)
{

    if (per.nr > 100 || per.nr < 0) return 0;

    return per.nr != 0;
}

void printLines(linie lin)
{

    perechi* per = findPairs(lin.chars);

    for (int i = 0; i < 100; i++)
    {

        if (!isValid(per[i]))
        {
            //printf("\nPair %d not valid (%d,%d)\n", i, per[i].nr, per[i].zero);
            continue;
        }
        if (isValid(per[i + 1]) && i != 0) printf(",");

        if (!hasZeroInPair(per[i]))
        {
            printf("%d, ", per[i].nr);
        }
        else
        {
            printf("(%d,%d), ", per[i].nr, per[i].zero);
        }

    }

    printf("\n");

}

int main()
{

    int n = 0;
    scanf("%d", &n);

    linie* sir = (linie*) malloc(n * sizeof(linie));

    for (int i = 0; i < n; i++)
    {
        scanf("%s", sir[i].chars);
    }

    for (int i = 0; i < n; i++)
    {
        printLines(sir[i]);
    }

    return 0;

}
