CUDA_Proxy
==========

The default GPU compute mode for Titan is Exclusive Process. In this mode many threads within a process may access the GPU context. To allow multiple processes access to the GPU context, such as multiple MPI tasks on a single node accessing the GPU, the CUDA proxy server was developed. Once enabled the proxy server transparently manages work issued to the GPU context from multiple processes. 
