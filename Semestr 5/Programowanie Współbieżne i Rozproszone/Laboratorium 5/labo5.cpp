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
