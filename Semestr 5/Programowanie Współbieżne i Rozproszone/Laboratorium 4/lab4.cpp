#include<iostream>
#include<mpi.h>
#include<ctime>

using namespace std;
// MPI_Bcast (Broadcast)

float max(const float &a, const float &b)
{ return (a>b)?a:b; }

int main()
{

MPI_Init(NULL, NULL);

int rank, size;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

int n, nRank;
int *tab, *rankTab;

if( rank == 0 )
{
  cout<<"Podaj wartosc N: ";
  cin>>n;

  srand(time(NULL));

  tab = new int[n];
  for(int i=0; i<n; ++i)
      tab[i] = rand() % 100;

  nRank = n / size;

  for(int i=0; i<n; ++i)
    cout<<tab[i]<<" ";
  cout<<endl;
}
// to 0 nie bierze sie znikad!
MPI_Bcast(&nRank, 1, MPI_INT, 0, MPI_COMM_WORLD);

rankTab = new int[nRank];

MPI_Scatter(tab, nRank, MPI_INT, rankTab, nRank, MPI_INT, 0, MPI_COMM_WORLD);

// Test funkcji MPI_Scatter
/*if( rank ==  0) // testuj 0 / 1 / 2 / 3
{
  for(int i=0; i<nRank; ++i)
    cout<<rankTab[i]<< " ";
  cout<<endl;
}*/


int maxL, maxG; //maxLocal maxGlobal
maxL = rankTab[0];
for(int i=1; i<nRank; ++i)
  maxL = max(maxL, rankTab[i]);

cout<<"maxL: "<<maxL;

MPI_Reduce(&maxL, &maxG, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

if( rank == 0 )
{
  cout<< "maxG: "<< maxG<<endl;
  delete[] tab;
}


MPI_Finalize();

  return 0;
}


/*
int n;
cout<<"Wprowadz rozmiar tablicy:\n";
cin>>n;

int *tab = new int[n];

for(int i=0; i<n; ++i)
{
  tab[i] = i;
}

int mx = tab[0];
for(int i=1; i<n; ++i)
{
  mx = max(mx, tab[i]);
}

std::cout<<"max: "<<mx<<endl;
delete [] tab;

*/
