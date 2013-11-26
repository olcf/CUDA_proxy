#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <omp.h>
 
extern "C" int64_t get_cycles(int seconds);
extern "C" void sleep_kernel(int64_t num_cycles);
extern "C" void wait_for_gpu();
 
int main(int argc, char *argv[])
{
    // Get number of cycles to sleep for 1 second
    uint64_t cycles;
    cycles = get_cycles(1);
 
    // Number of kernels to launch
    int num_kernels = 14;
 
    // Launch kernel
    omp_set_num_threads(num_kernels);
 
    #pragma omp parallel for shared(cycles) num_threads(num_kernels)
    for(int i=0; i<num_kernels; i++){
        sleep_kernel(cycles);
    }
 
    // Wait for the kernel to complete
    wait_for_gpu();
}
