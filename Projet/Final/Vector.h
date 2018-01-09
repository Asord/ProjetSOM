#pragma once
#include "Utility.h"

namespace SOM
{
	struct Vector
	{
		uint* pos;
		uint dim;
		
		// Constructeur par défaut
		Vector()
		{
			pos = new uint[2];
			dim = 2;
		}

		// Constructeur
		Vector(uint dim)
		{
			pos = new uint[dim];
			this->dim = dim;
		}

		~Vector() { delete[] pos; }

		uint& operator[](uint dim) { return pos[dim]; }
		const uint& operator[](uint dim) const { return pos[dim]; }
		uint& operator()(uint dim) { return pos[dim]; }
		const uint& operator()(uint dim) const { return pos[dim]; }
	};
}

