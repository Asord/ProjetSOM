#include <stdio.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <conio.h>
#include <math.h>

#define ARRAYSIZE 10

__global__ void vectDist(float * d_out, float * d_in, float * d_in2) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	float _res = 0;
	float f = d_in[idx];
	float f2 = d_in2[idx];
	if (idx < ARRAYSIZE) {
		_res += sqrt(pow(f - f2, 2));
		d_out[idx] = _res;
	}
}

int main(int argc, char ** argv) {
	const int ARRAY_BYTES = ARRAYSIZE * sizeof(float);

	// generate the input array on the host
	float h_in[ARRAYSIZE], h_weights[ARRAYSIZE], h_distOUT[ARRAYSIZE];

	for (int i = 0; i < ARRAYSIZE; i++) {
		h_in[i] = float(i+1);
		h_weights[i] = float(i);		
	}
	//sqrt(pow(x-x, 2)+pow(y-y,2)   distance formula

	/*for (int i = 0; i < ARRAYSIZE; ++i) {
		h_distOUT[i] = sqrt(pow(h_in[i] - h_weights[i], 2));
	}*/


	// declare GPU memory pointers
	float * d_in;
	float * d_in2;
	float * d_out;

	// allocate GPU memory
	cudaMalloc((void**)&d_in, ARRAY_BYTES);
	cudaMalloc((void**)&d_in2, ARRAY_BYTES);  
	cudaMalloc((void**)&d_out, ARRAY_BYTES);

	// transfer the array to the GPU
	cudaMemcpy(d_in, h_in, ARRAY_BYTES, cudaMemcpyHostToDevice);
	cudaMemcpy(d_in2, h_weights, ARRAY_BYTES, cudaMemcpyHostToDevice);

	// launch the kernel
	vectDist <<<ARRAYSIZE, 3>> >(d_out, d_in, d_in2);

	// copy back the result array to the CPU
	cudaMemcpy(h_distOUT, d_out, ARRAY_BYTES, cudaMemcpyDeviceToHost);

	// print out the resulting array
	for (int i = 0; i < ARRAYSIZE; i++) {
		printf("weight:%f", h_distOUT[i]);
		printf(((i % 4) != 3) ? "\t" : "\n");
	}

	cudaFree(d_in);
	cudaFree(d_in2);
	cudaFree(d_out);
	_getch();
	return 0;
}