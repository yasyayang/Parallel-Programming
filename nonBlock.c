#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
  // Inisiasi Environment Awal
  MPI_Init(NULL, NULL);
  
  //Mencari Rank dan Size 
  int global_seq;
  MPI_Comm_rank(MPI_COMM_WORLD,&global_seq);
  int global_size;
  MPI_Comm_size(MPI_COMM_WORLD,&global_size);
  MPI_Request req;
  // Menggunakan 2 Processor
  if (global_size < 2) {
    fprintf(stderr, "Ukuran Global harus lebih besar dari 1 untuk  %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int numb;
  
  if (global_seq == 0) {
    numb= -1;
    MPI_Isend(&numb, 1, MPI_INT, 1,0,MPI_COMM_WORLD,&req);
  } else if (world_rank == 1) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n", number);
  }
  
  MPI_Finalize();	
}
