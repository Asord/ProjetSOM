#pragma once
#include "Utility.h"

namespace SOM
{
	class Point
	{
	private:
		double* p;
		uint d;

	public:
		Point(uint dim)
		{
			p = new double[dim];
			d = dim;
		}

		~Point() { delete[] p; }

		double& operator[](uint dim) { return p[dim]; }
		const double& operator[](uint dim) const { return p[dim]; }
		double& operator()(uint dim) { return p[dim]; }
		const double& operator()(uint dim) const { return p[dim]; }
	};
}