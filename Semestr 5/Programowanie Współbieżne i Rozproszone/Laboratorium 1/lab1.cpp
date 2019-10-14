#include<mpi.h>
#include<iostream>
using namespace std;

int main()
{
	int rank; // ID procesu
	int size; // Liczba uruchomionych procesow
		
	MPI_Init(NULL, NULL);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
//	cout<<"HELLO WORLD, RANK: "<<rank<<" SIZE: "<<size<<endl;

	int temp = 0;
	
	if(rank == 0)
	{
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
