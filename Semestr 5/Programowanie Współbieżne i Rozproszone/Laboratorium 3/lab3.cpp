/*
Wykorzystując bibliotekę MPI napisać równoległą wersję poniższego kodu:

#include <iostream>
#include <stdlib.h>
int max(const int& a, const int& b) {
return (a>b)?a:b;
}
int main(int argv, char**argc) {
int n;
std::cout<<"podaj wartosc n: "<<std::endl;
std::cin>>n;
int * tab = new int[n];
srand (time(NULL));
for(int i = 0; i<n; ++i) {
//tab[i]=i;
tab[i]=rand() % 100;
}
int mx = tab[0];
for(int i = 1; i<n; ++i) {
mx = max(mx, tab[i]);
}
std::cout<<mx<<std::endl;
delete [] tab;
}

Założenia:
– dowolny rozmiar tablicy n;
– dowolna liczba procesów ( n>>size );
– podstawowe zadania dla procesu 0:
– dynamicznie przydzielić pamięć dla głównej tablicy tab o rozmiarze n,
– zapewnić równomierny podział obliczeń pomiędzy dostępne procesy (rys.): wyznaczyć rozmiar
zadania nRank dla każdego procesu,
– do każdego procesu wysłać rozmiar poszczególnych fragmentów głównej tablicy (nRank),
– przesłać odpowiednie fragmenty głównej tablicy do każdego procesu,
– podstawowe zadania dla pozostałych procesów:
– odebrać rozmiar nRank poszczególnych części tablicy,
– dynamicznie przydzielić pamięć dla tablicy o rozmiarze nRank,
– odebrać odpowiedni fragment tablicy,
– podstawowe zadania dla wszystkich procesów:
– znaleźć maksymalny element maxRank w obrębie każdego procesu,
– wykorzystać funkcję MPI_Reduce do znalezienia maksymalnego elementu maxAll spośród
znalezionych elementów w poszczególnych procesach
MPI_Reduce (*sendbuf, *recvbuf, count, datatype, op, root, comm)
MPI_Reduce(&maxRank, &maxAll, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD )
– zwolnić obszar pamięci dynamicznej;
Uwaga!
W celu uproszczenia można przyjąć: n=100 oraz -np 4

*/

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
