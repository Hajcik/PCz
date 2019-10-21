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
