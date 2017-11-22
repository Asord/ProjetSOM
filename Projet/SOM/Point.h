#pragma once
#include "Utility.h"

namespace SOM
{
	struct Vector
	{
		double* pos;
		uint dim;

		Vector(uint dim)
		{
			pos = new double[dim];
			dim = dim;
		}

		~Vector() { delete[] pos; }

		double& operator[](uint dim) { return pos[dim]; }
		const double& operator[](uint dim) const { return pos[dim]; }
		double& operator()(uint dim) { return pos[dim]; }
		const double& operator()(uint dim) const { return pos[dim]; }
	};
}

