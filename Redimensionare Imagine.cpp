#include <iostream>

struct pixel
{
    int r, g, b;
};

pixel maxPixel(pixel* p, int size)
{

    int rMax = 0;
    int gMax = 0;
    int bMax = 0;

    for (int i = 0; i < size; i++)
    {

        if (p[i].r > rMax) rMax = p[i].r;
        if (p[i].g > gMax) gMax = p[i].g;
        if (p[i].b > bMax) bMax = p[i].b;

    }

    pixel max = { rMax, gMax, bMax };

    return max;

}

int main()
{
    
    int m, s = 0;

    scanf_s("%d", &m);
    scanf_s("%d", &s);

    pixel* image = (pixel*) malloc(m * m * sizeof(pixel));

    //Citim valorile
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < m; j++)
        {

            scanf_s("%d %d %d", &(image + i*m + j)->r, &(image + i * m + j)->g, &(image + i * m + j)->b);

        }

    }

    pixel max; //Pixelul cu valorile maxime rezultate din block
    pixel* block; //Array in care vom stoca blockurile de s x s
    pixel* resized = (pixel*) malloc(s * s * sizeof(pixel)); //Asta e matricea redimensionata

    int block_index = 0;

    //Pentru fiecare coloana, merge din s in s
    for (int i = 0; i < m; i = i+s)
    {

        //Pentru fiecare block
        for (int j = 0; j < m; j = j + s)
        {

            block_index = 0; //Indexul pixelului din interiorul blockului
            block = (pixel*) malloc(m * sizeof(pixel));

            //Block creation, merge de la i pana la i + s, 0 la 2, 2 la 4 etc
            for (int b1 = i; b1 < i+s; b1++)
            {

                //La fel merge pana la j + s si din 1 in 1
                for (int b2 = j; b2 < j+s; b2++)
                {

                    //Creeaza blockul de marime s x s si il pune liniar in matrice ce contine 
                    block[block_index] = *(image + b1 * m + b2);
                    block_index++;


                }


            }

            max = maxPixel(block, m);
            free(block);

            *(resized + (i / s) * s + (j / s)) = max;

        }

    }


    pixel temp;

    for (int i = 0; i < s; i++)
    {

        for (int j = 0; j < s; j++)
        {
            temp = *(resized + i * s + j);
            printf("%d %d %d\n", temp.r, temp.g, temp.b);

        }


    }

    return 0;


}

