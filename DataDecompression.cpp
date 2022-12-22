#include <iostream>

struct line
{
    char text[100];
};

void spitZero(int nr)
{

    for (int i = 0; i < nr; i++)
    {
        printf("%d,", 0);
    }

}

int getNumber(char c)
{
    int i = c - '0';
    return i;
}

int bigNumber(char* nr)
{

    if (nr[1] != ',' && nr[1] != ')') return 1;
    return 0;

}

//The parameter is when the pointer to the first (
char* decompress(char* text)
{

    int offset = 0;

    //text[0] paranteza text[1/2] nr text[2/3] virgula text[3/4] nr2


        //Daca primu nr e de 2 cifre
        if (bigNumber(text + 1))
        {

            printf("%c", text[1]);
            printf("%c,", text[2]);

            offset = 4;

        }
        else
        {

            printf("%c,", text[1]);
            offset = 3;

        }

        if (bigNumber(text + offset))
        {

            int nr = 10 * getNumber(text[offset]) + getNumber(text[offset + 1]);
            spitZero(nr);
            offset += 3;
            //printf("Last big: %d", nr);
        }
        else
        {

            //printf("Last small: %d, %d, %c", getNumber(text[offset]), offset, text[offset]);

            spitZero(getNumber(text[offset]));
            offset += 2;
        }

        //Daca al doilea nr e de 2 cifre
        //printf("\n|%s|\n", text + offset);
        return text + offset;

}

void printLine(line l)
{

    char* text = l.text;

    for (int i = 0; i < 100; i++)
    {

        if(text[i] == 0) break;

        if (text[i] != '(') printf("%c", text[i]);
        else
        {

            text = decompress(text + i);
            i = 0;

            if (*text == 0) break;

        }

    }

}

int main()
{
   
    int n = 0;
    scanf("%d", &n);

    line* lines = (line*)malloc(n * sizeof(line));

    for (int i = 0; i < n; i++)
    {
        scanf("%s", lines[i].text);
    }

    for (int i = 0; i < n; i++)
    {

        printLine(lines[i]);
        printf("\n");

    }


}

