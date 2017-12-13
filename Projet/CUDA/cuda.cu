#include "cuda.cuh"

namespace SOM {
	__global__
	void activiteNeurone(double * d_out, double * d_in, double * d_w, const int ARRAYSIZE)
	{
		int idx = threadIdx.x + blockIdx.x * blockDim.x;
		float _act = 0;
		float f = d_in[idx];
		float f2 = d_w[idx];

		if (idx < ARRAYSIZE) {
			_act += pow(f - f2, 2);
			d_out[idx] = sqrt(_act);
		}
	}
	
	double launchActiviteNeurone(double* h_actIn)
	{
		const int ARRAYSIZE = 10; //grid dimension
		const int ARRAY_BYTES = ARRAYSIZE * sizeof(double); //memoire à allouer par element

		// tableaux sur le host pour le calcul d'activité
		double h_weights[ARRAYSIZE], h_actOUT[ARRAYSIZE];

		// déclaration des pointers mémoire sur GPU
		double * d_actIn;
		double * d_weights;
		double * d_actOut;

		// alloue la memoire sur GPU pour les pointers
		cudaMalloc((void**)&d_actIn, ARRAY_BYTES);
		cudaMalloc((void**)&d_weights, ARRAY_BYTES);
		cudaMalloc((void**)&d_actOut, ARRAY_BYTES);

		// transfert les tableaux sur le GPU
		cudaMemcpy(d_actIn, h_actIn, ARRAY_BYTES, cudaMemcpyHostToDevice);
		cudaMemcpy(d_weights, h_weights, ARRAY_BYTES, cudaMemcpyHostToDevice);

		// lance le kernel activiteNeurone
		activiteNeurone <<<ARRAYSIZE, 3 >>> (d_actOut, d_actIn, d_weights, ARRAYSIZE);

		// copie le résultat final sur le CPU
		cudaMemcpy(h_actOUT, d_actOut, ARRAY_BYTES, cudaMemcpyDeviceToHost);

		/*
		// affiche le tableau de poids final
		for (int i = 0; i < ARRAYSIZE; i++) {
			printf("weight:%f", h_actOUT[i]);
			printf(((i % 4) != 3) ? "\t" : "\n");
		}*/

		cudaFree(d_actIn);
		cudaFree(d_weights);
		cudaFree(d_actOut);
		_getch();

		return *h_actOUT;
	}

}