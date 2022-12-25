#include <iostream>

double coef(int u, int n)
{

	if (u == 0)
	{
		return 1.0 / sqrt(n);
	}

	if (u > 0)
	{
		return sqrt(2.0 / n);
	}

	return -1;

}

double calcCos(int u, int m, int i)
{

	double pi = 3.14;

	return cos(((pi * u) / (2 * m)) * ((2 * i) + 1));
}

double sum(int u, int v, int linii, int coloane, int *imagine)
{


	double sumaJ, sumaI = 0;
	

	for (int i = 0; i < linii; i++)
	{

		sumaJ = 0;

		for (int j = 0; j < coloane; j++)
		{

			sumaJ += calcCos(u, linii, i) * calcCos(v, coloane, j) * *(imagine + i * coloane + j);
		
		}

		sumaI += sumaJ;

	}

	return sumaI;

}

double finalSum(int i, int j, int linii, int coloane, double* imagine_freq)
{


	double sumaJ, sumaI = 0;


	for (int u = 0; u < linii; u++)
	{

		sumaJ = 0;

		for (int v = 0; v < coloane; v++)
		{

			sumaJ += coef(u, linii) * coef(v, coloane) * calcCos(u, linii, i) * calcCos(v, coloane, j) * *(imagine_freq + u * coloane + v);

		}

		sumaI += sumaJ;

	}

	return sumaI;

}

void clean(double* imagine_freq, int linii, int coloane)
{


	for (int i = 0; i < linii; i++)
	{

		for (int j = 0; j < coloane; j++)
		{

			if (i == 0 && j == 0) continue;
	 
			*(imagine_freq + i * coloane + j) = 0;

		}

	}

}

int main()
{
   
	int linii, coloane = 0;

	scanf_s("%d", &linii);
	scanf_s("%d", &coloane);


	int* imagine = (int*) calloc (linii * coloane, sizeof(int));
	double* imagine_freq = (double*) calloc(linii * coloane, sizeof(double));
	double* imagine_rez = (double*) calloc(linii * coloane, sizeof(double));


	for (int i = 0; i < linii; i++)
	{

		for (int j = 0; j < coloane; j++)
		{

			scanf_s("%d", (imagine + i * coloane + j));

		}

	}

	//Constructia lui Af
	for (int u = 0; u < linii; u++)
	{

		for (int v = 0; v < coloane; v++)
		{

			*(imagine_freq + u * linii + v) = coef(u, linii) * coef(v, coloane) * sum(u, v, linii, coloane, imagine);

		}

	}

	//Inlocuim toate valorile cu 0 in afara de (0,0)
	clean(imagine_freq, linii, coloane);

	//Constructia lui Ar
	for (int i = 0; i < linii; i++)
	{

		for (int j = 0; j < coloane; j++)
		{

			*(imagine_rez + i * linii + j) = finalSum(i, j, linii, coloane, imagine_freq);

		}

	}

	//Afisare rezultat
	for (int i = 0; i < linii; i++)
	{

		for (int j = 0; j < coloane; j++)
		{

			printf("%d\n", (int) * (imagine_rez + i * linii + j));

		}

	}


}


