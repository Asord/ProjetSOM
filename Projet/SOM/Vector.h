#pragma once
#include "Utility.h"

namespace SOM
{
	struct Vector
	{
		uint* pos;
		uint dim;
		
		// Constructeur par d�faut
		Vector()
		{
			pos = new uint[2];
			dim = 2;
		}

		// Constructeur
		Vector(uint d)
		{
			pos = new uint[d];
			dim = d;
		}

		~Vector() { delete[] pos; }

		uint& operator[](uint dim) { return pos[dim]; }
		const uint& operator[](uint dim) const { return pos[dim]; }
		uint& operator()(uint dim) { return pos[dim]; }
		const uint& operator()(uint dim) const { return pos[dim]; }
	};
}

