#pragma once

namespace SOM
{
	class Point
	{
	private:
		double* p;
		size_t d;

	public:
		Point(size_t dim)
		{
			p = new double[dim];
			d = dim;
		}

		~Point() { delete[] p; }

		double& operator[](size_t dim) { return p[dim]; }
		const double& operator[](size_t dim) const { return p[dim]; }
		double& operator()(size_t dim) { return p[dim]; }
		const double& operator()(size_t dim) const { return p[dim]; }
	};
}