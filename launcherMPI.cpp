#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <mpi.h>
 
extern "C" int64_t get_cycles(int seconds);
extern "C" void sleep_kernel(int64_t num_cycles);
extern "C" void wait_for_gpu();
 
int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 
    // Get number of cycles to sleep for 1 second
    uint64_t cycles;
    cycles = get_cycles(1);
 
    // Sleep kernel for 1 second
    sleep_kernel(cycles);
 
    // Wait for the kernel to complete
    wait_for_gpu();
 
    MPI_Finalize();
    return 0;
}
