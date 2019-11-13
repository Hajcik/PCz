#include <iostream>
#include <mpi.h>
#include <ctime>
 
using namespace std;
 
int main()
{
  MPI_Init(NULL, NULL);
 
  int * tab;
 
  int maxLocal(0), maxGlobal(0);
 
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
 
  if ( rank == 0 )
  {
    int n;
    srand(time(NULL));
    cout << "Podaj wartosc N: " << endl;
    cin >> n;
 
    tab = new int[n];
    for (size_t i = 0; i < n; i++)
    {
      tab[i] = rand() % 100;
    }
    int nRank = n / size;
    int offset = nRank;
 
    for (size_t i = 1; i < size; i++)
    {
      MPI_Send(&nRank, 1, MPI_INT, i, 88, MPI_COMM_WORLD);
      MPI_Send(&tab[offset], nRank, MPI_INT, i, 88, MPI_COMM_WORLD);
      offset += nRank;
    }
    maxLocal = tab[0];
    for (size_t i = 1; i < nRank; i++) {
      maxLocal = max(maxLocal, tab[i]);
    }
  }
  else
  {
    int nRank = 0;
 
    MPI_Recv(&nRank, 1, MPI_INT, 0, 88, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
 
    //cout << rank << " " << nRank << "\n";
 
    int *rankTab = new int[nRank];
    MPI_Recv(rankTab, nRank, MPI_INT, 0, 88, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
 
    maxLocal = rankTab[0];
    for (size_t i = 1; i < nRank; i++) {
      maxLocal = max(maxLocal, rankTab[i]);
    }
 
    delete[] rankTab;
  }
 
  //cout << rank << " " << maxLocal << "\n";
 
  MPI_Reduce (&maxLocal, &maxGlobal, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
 
  if ( rank == 0 )
  {
    delete[] tab;
  }
 
  cout << rank << " maxGlobal= " << maxGlobal << endl;
 
  MPI_Finalize();
}
