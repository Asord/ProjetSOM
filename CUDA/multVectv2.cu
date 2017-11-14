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
//	if(idx <N)	result[idx] = a[idx] * b[idx];
//}
//
//
//int main() {
//	
//	int *d_vect1, *d_vect2, *d_vect3;
//
//	const int size = N * sizeof(int);
//
//	cudaMallocManaged(&d_vect1, size);
//	cudaMallocManaged(&d_vect2, size);
//	cudaMallocManaged(&d_vect3, size);
//
//	for (int i = 0; i < N; ++i)
//	{
//		d_vect1[i] = rand() % (int)floor(sqrt(INT_MAX));
//		d_vect2[i] = rand() % (int)floor(sqrt(INT_MAX));
//	}
//
//
//	multVect <<<N/ NB_THREADS, NB_THREADS >> >(d_vect3, d_vect1, d_vect2);
//
//	cudaDeviceSynchronize();
//
//	for (int i = 0; i < N; ++i)
//	{
//		printf("%d*%d=%d ", d_vect1[i], d_vect2[i], d_vect3[i]);
//	}
//
//	cudaFree(d_vect1);
//	cudaFree(d_vect2);
//	cudaFree(d_vect3);
//
//	_getch();
//	return 0;
//}