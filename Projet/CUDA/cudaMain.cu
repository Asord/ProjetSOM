#include <iostream>

#include "cuda.cuh"

using std::cout;

//#define DIM 1000

namespace SOM {

	void main()
	{
		double h_weight[10];
		double eee[10];
		for (short i = 0; i < 11; ++i) {
			eee[i] = launchActiviteNeurone(h_weight);
			cout << *eee;
		}
		
		
	}
}

