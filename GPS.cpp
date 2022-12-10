#include <iostream>

struct coordonate {

    double x;
    double y;
    double z;
    int visited = 0;

};

double distance(coordonate p, coordonate n)
{

    double x = (p.x - n.x) * (p.x - n.x);
    double y = (p.y - n.y) * (p.y - n.y);
    double z = (p.z - n.z) * (p.z - n.z);

    return sqrt(x + y + z);

}

void sort(coordonate planete[], coordonate nava, int n)
{

    coordonate aux;
    double daux;

    double* distante = (double*) malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
    {

        if (distance(planete[i], nava) == 0 || planete[i].visited)
        {
            distante[i] = 500;
        }
        else
        {
            distante[i] = distance(planete[i], nava);
        }

    }


    for (int i = 0; i < n; i++)
    {

        for (int x = i + 1; x < n; x++)
        {
            printf("\n%d-%d, X:%lf I:%lf\n", i, x, distante[x], distante[i]);
            if (distante[x] < distante[i])
            {
                aux = planete[x];
                planete[x] = planete[i];
                planete[i] = aux;

                daux = distante[x];
                distante[x] = distante[i];
                distante[i] = daux;
            }

        }

    }

}

int main()
{
    
    int n = 0;

    scanf("%d", &n);

    coordonate *planete = (coordonate*) malloc(n * sizeof(coordonate));

    for (int i = 0; i < n; i++)
    {

        scanf("%lf %lf %lf", &planete[i].x, &planete[i].y, &planete[i].z);
        planete[i].visited = 0;

    }

    coordonate nava;

    scanf("%lf %lf %lf", &nava.x, &nava.y, &nava.z);

    nava.visited = -1;

    double length = 0;

    for (int i = 0; i < n; i++)
    {

        sort(planete, nava, n);
        length += distance(planete[0], nava);

        printf("\n\nMiscarea %d: %lf %lf %lf, distanta: %lf, nava: %lf %lf %lf\n\n", i, planete[0].x, planete[0].y, planete[0].z, distance(planete[0], nava), nava.x, nava.y, nava.z);
        printf("Planete:\n");

        for (int a = 0; a < n; a++)
        {
            printf("Planeta %d: %lf %lf %lf - Distance to ship: %lf - Visited: %d\n",a, planete[a].x, planete[a].y, planete[a].z, distance(planete[a], nava), planete[a].visited);
        }

        nava.x = planete[0].x;
        nava.y = planete[0].y;
        nava.z = planete[0].z;

        planete[0].visited = 1;
    
    }

    printf("Distanta: %lf", length);


    return 0;
}
