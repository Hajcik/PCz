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
