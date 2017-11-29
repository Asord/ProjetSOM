#include "cuda.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <conio.h>
#include <math.h>
#include <stdio.h>


namespace SOM {
	
		__global__ 
		void activiteNeurone(double * d_out, double * d_in, double * d_w, const int ARRAYSIZE);
		double launchActiviteNeurone(double*);



	
}