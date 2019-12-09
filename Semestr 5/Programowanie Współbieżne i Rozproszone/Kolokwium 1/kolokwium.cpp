#include <iostream>
#include "mpi.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	MPI_Init(NULL, NULL);

	int rank;
	int size;
	int *tab;
	int n(0);
	int nG(0);
	int Gsum(0);
	int Lavg(0);
	int Gavg(0);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);


	if (rank == 0)
	{
		cout << "Podaj rozmiar tablicy: ";
		cin >> n;

		srand(time(NULL));

		nG = n;
		n *= size;

		tab = new int[n];

		for (int i = 0; i < n; i++)
		{
			tab[i] = rand() % 100;
		}
		cout << endl;

		for (int i = 1; i < size; i++)
		{
			MPI_Send(&nG, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
			MPI_Send(&tab[nG*i], nG, MPI_INT, i, 2, MPI_COMM_WORLD);
		}

		for (int i = 1; i < nG; i++)
		{
			Gsum += tab[i];
		}

		Lavg = Gsum / nG;

		delete[] tab;
	}
	else
	{
		MPI_Recv(&nG, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		int *rankTab = new int[nG];
		MPI_Recv(&rankTab[0], nG, MPI_INT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		for (int i = 1; i < nG; i++)
		{
			Gsum += rankTab[i];
		}

		Lavg = Gsum / nG;

		delete[] rankTab;
	}

	MPI_Reduce(&Lavg, &Gavg, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
	{
		Gavg = Gavg / size;
		cout << "Wartosc sredniej=" << Gavg << endl;
	}


	MPI_Finalize();

	return 0;
}
