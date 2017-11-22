//#include "cuda_runtime.h"
//#include "device_launch_parameters.h"
//
//#include <stdio.h>
//#include <random>
//#include <conio.h>
//
//
//#define N 2048
//#define NB_THREADS 1024
//
//__global__ void multVect(int* result, int* a, int* b) {
//	int idx = threadIdx.x + blockIdx.x * blockDim.x;
//	if(idx < N)
//	result[idx] = a[idx] * b[idx];
//}
//
//
//int main() {
//	int *h_vect1, *h_vect2, *h_vect3;
//	int *d_vect1, *d_vect2, *d_vect3;
//
//	const int size = N * sizeof(int);
//
//	cudaMalloc(&d_vect1, size);
//	cudaMalloc(&d_vect2, size);
//	cudaMalloc(&d_vect3, size);
//
//	h_vect1 = (int *)malloc(size); 
//	h_vect2 = (int *)malloc(size); 
//	h_vect3 = (int *)malloc(size);
//
//	for(int i = 0; i < N; ++i)
//	{
//		h_vect1[i]= rand() % (int)floor(sqrt(INT_MAX));
//		h_vect2[i]= rand() % (int)floor(sqrt(INT_MAX));
//	}
//	
//	cudaMemcpy(d_vect1, h_vect1, size, cudaMemcpyHostToDevice);
//	cudaMemcpy(d_vect2, h_vect2, size, cudaMemcpyHostToDevice);
//
//	multVect <<<N / NB_THREADS, NB_THREADS >> >(d_vect3, d_vect1, d_vect2);
//
//	cudaMemcpy(h_vect3, d_vect3, size, cudaMemcpyDeviceToHost);
//
//	for (int i = 0; i < N; ++i) 
//	{
//		printf("%d*%d=%d", h_vect1[i], h_vect2[i], h_vect3[i]);
//	}
//
//	free(h_vect1);
//	free(h_vect2);
//	free(h_vect3);
//    cudaFree(d_vect1);
//    cudaFree(d_vect2);
//    cudaFree(d_vect3);
//	
//	_getch();
//	return 0;
//}