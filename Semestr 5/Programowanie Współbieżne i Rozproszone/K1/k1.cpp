// Lab 1
/*
Kompilacja: mpic++ -o lab1 lab1.cpp
Uruchomienie: mpirun -np 4 ./lab1
Napisać program z wykorzystaniem biblioteki MPI, który pozwoli na uruchomienie równolegle np
procesów. Każdy proces powinien wyświetli bieżący numer procesu, liczbę wszystkich procesów
oraz podstawowe informacje o komputerze.
*/

#include<mpi.h>
#include<iostream>
using namespace std;

int main()
{
	int rank; // ID procesu
	int size; // Liczba uruchomionych procesow
	int len;
	char name[MPI_MAX_PROCESSOR_NAME];	
		
	MPI_Init(NULL, NULL);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Get_processor_name(name, &len);
//	cout<<"HELLO WORLD, RANK: "<<rank<<" SIZE: "<<size<<endl;
	cout<<"HELLO WORLD, RANK: "<<rank<<" SIZE: "<<size
		<<" PROCESSOR NAME: "<<name<<endl;
	
	int temp = 0;
	
	
	//Funkcja cin jest dostepna tylko dla ranku o id=0
	if(rank == 0)
	{
		// cin >> temp
		temp = 10;
	}
	else
	{
		temp=11;
	}
	cout<<"Rank: "<< rank <<"Temp: "<<temp<<endl;
	
	int MPI_Finalize();
	
	
	return 0;
}

// Lab2

/*
Kompilacja: mpic++ -o lab0 lab0.cpp
Uruchomienie: mpirun -np 4 ./lab1
Napisać program z wykorzystaniem biblioteki MPI, który będzie realizował komunikację między
4 procesami z wykorzystaniem funkcji MPI_Send i funkcji MPI_Recv.
Procesy, w kolejności od procesu 0 do procesu 3, mają przekazywać wiadomość msg zwiększając
jej wartość o swój rank:
proces 0: wysyła msg=0 do procesu 1;
proces 1: odbiera msg;
 zwiększa wartość: msg = msg + rank;
 wysyła msg do procesu 2;
proces 2: odbiera msg;
 zwiększa wartość msg = msg + rank;
 wysyła msg do procesu 3;
proces 3: odbiera msg;
 zwiększa wartość msg = msg + rank;
 wyświetla rank i wartość msg;
Po uruchomieniu (mpirun -np 4 ./lab1) , program powinien wypisać na ekranie:
rank:3 msg:6
*/

#include<iostream>
#include<mpi.h>

using namespace std;

int main()
{
	MPI_Init(NULL, NULL);
	
	
	int rank, size;
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int msg;
	
/*	if(rank == 0)
	{
		msg = 10;
		MPI_Send(&msg, 1, MPI_INT, size-1, 88, MPI_COMM_WORLD);
	}
	
	if(rank == size-1)
	{
		MPI_Recv(&msg, 1, MPI_INT, 0, 88, MPI_COMM_WORLD, nullptr); //albo null, bez znaczenia
	}
	
	cout << rank << " " << msg << endl;
*/
	////// 
	
	if(rank == 0)
	{
		msg = 0;	
		MPI_Send(&msg, 1, MPI_INT, rank+1, 88, MPI_COMM_WORLD);
		
		MPI_Recv(&msg, 1, MPI_INT, size-1, 88, MPI_COMM_WORLD, nullptr);
		
		cout << "rank: " << rank << " msg: " << msg << endl;
	}
	else if(rank == size-1) 
	{								
		MPI_Recv(&msg, 1, MPI_INT, rank-1, 88, MPI_COMM_WORLD, nullptr);
		msg += rank;
		MPI_Send(&msg, 1, MPI_INT, 0, 88, MPI_COMM_WORLD);
		
	}
	else
	{
		MPI_Recv(&msg, 1, MPI_INT, rank-1, 88, MPI_COMM_WORLD, nullptr);
		msg += rank;
		MPI_Send(&msg, 1, MPI_INT, (rank+1 > size-1? 0 : rank+1), 88, MPI_COMM_WORLD);
		
	}
	 
	MPI_Finalize();
	
/*	
	MPI_Send(void *msg, int count, MPI_Datatype datatype, 
		     int dest, int tag, MPI_Comm comm);
		     
	MPI_Recv(void *msg, int count, MPI_Datatype datatype, 
			 int source, int tag, MPI_Comm comm, MPI_Status *status);
*/
	
	
	
	return 0;
}

// Lab3

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

// Lab 4

/*
Wykorzystując bibliotekę MPI napisać równoległą wersję poniższego kodu:
float max(const float &a, const float &b)
{
	return (a>b)?a:b;
}
int main(int argv, char **argc)
{
int n;
std::cout<<"Wprowadz rozmiar tablicy: ";
std::cin>>n;
int *tab = new int[n];
for(int i = 0; i<n; ++i)
	tab[i] = i;
int mx = tab[0];
for(int i=1; i<n; ++i)
	mx = max(mx, tab[i]);
std::cout<<"max: "<<mx<<std::endl;
delete [] tab;
}
Zakładamy, że liczba elementów wektora jest n razy większa od liczby procesów size. Główna tablica
tworzona jest w obrębie 0 procesu. Rozmiar nRank odpowiednich fragmentów tablicy należy rozesłać do
pozostałych procesów przy pomocy funkcji MPI_Bcast. Odpowiednie fragmenty tablicy rozsyłane są do
pozostałych procesów przy pomocy funkcji MPI_Scatter. Każdy proces poszukuje największego elementu
w swojej części tablicy. Przy pomocy funkcji MPI_Reduce należy znaleźć największy element spośród
największych elementów znalezionych w poszczególnych procesach.
MPI_Bcast (*buffer,count,datatype,root,comm)
MPI_Scatter (*sendbuf,sendcnt,sendtype,*recvbuf, recvcnt,recvtype,root,comm)
MPI_Reduce (*sendbuf,*recvbuf,count,datatype,op,root,comm) 
*/

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

// Lab 5

/*
Napisać program z wykorzystaniem biblioteki MPI, którego zadaniem jest podzielenie size
procesów na dwie grupy. Pierwsza grupa powinna się składać z procesów parzystych a druga z
nieparzystych. Przy pomocy funkcji MPI_Reduce zsumować numery globalnych procesów w
obrębie każdej grupy. Ostatni proces z każdej nowej grupy powinien wyświetlić wynik obliczeń.
MPI_Reduce (*sendbuf,*recvbuf,count,datatype,op,root,comm)
MPI_Group_incl (group,n,*ranks,*newgroup)
MPI_Group_difference (group1,group2,*newgroup
MPI_Comm_create (comm,group,*newcomm)
*/

#include<iostream>
 #include<cstdlib>
 #include "mpi.h"

 using namespace std;

 int main(int argc, char** argv)
 {
   MPI_Init(&argc, &argv);

   int rank(0);
   int size(0);
   int lRank(0);
   int lSize(0);

   int n(0);
   int *tab;
   int suma(0);

   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Comm_size(MPI_COMM_WORLD, &size);

   if(size < 2)
   {
     cout <<"Zbyt mala liczba procesow"<<endl;
     cout << size << endl;
     MPI_Finalize();
     return 0;
   }

   n = size / 2;
   tab = new int[n];

   for(int i = 0; i<n; i++)
      tab[i] = i*2 + 1;

    MPI_Group allGroup, evenGroup, oddGroup;
    MPI_Comm evenComm, oddComm;

    MPI_Comm_group(MPI_COMM_WORLD, &allGroup);
    MPI_Group_incl(allGroup, n, tab, &oddGroup);
    MPI_Group_difference(allGroup, oddGroup, &evenGroup);
    MPI_Comm_create(MPI_COMM_WORLD, oddGroup, &oddComm);
    MPI_Comm_create(MPI_COMM_WORLD, evenGroup, &evenComm);

    if(rank % 2 == 0)
    {
      MPI_Comm_rank(evenComm, &lRank);
      MPI_Comm_size(evenComm, &lSize);
      MPI_Reduce(&rank, &suma, 1, MPI_INT, MPI_SUM, lSize-1, evenComm);
      if(lRank == lSize - 1)
          cout<<"evenGroup - suma: "<<suma<<endl;
    }
    else if(rank % 2 == 1)
    {
      MPI_Comm_rank(oddComm, &lRank);
      MPI_Comm_size(oddComm, &lSize);
      MPI_Reduce(&rank, &suma, 1, MPI_INT, MPI_SUM, lSize-1, oddComm);
      if(lRank == lSize - 1)
          cout<<"oddGroup - suma: "<<suma<<endl;
    }

    delete[] tab;
    MPI_Finalize();
    return 0;
 }
