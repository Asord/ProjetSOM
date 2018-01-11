#pragma once

#include "Utility.h"
#include "Vector.h"
#include "Utility.h"
#include <cstdlib>
#include "Resources.h"
#include <qcolor.h>

namespace SOM
{
	class Neuron
	{
	private:
		static uint m_nCounter;

		uint m_nID;
		Vector m_pCoordinate;

		// Tableau de poids (double)
		uchar* m_fWeight;

		//Dimension du vecteur de poids
		uint m_nWeightDim;
		
	public:
		//Neuron() { m_fWeight = nullptr; m_nWeightDim = 0; }
		// Constructeur
		Neuron(uint dimWeight = 3);
		// Destructeur
		~Neuron();

		// getActivity
		//float getActivity(const double* entryTable, Network::DistanceMetric distanceType = Network::DistanceMetric::EUCL) const;
		
		// Met � jour un poids du vecteur de poids
		void SetWeight(uint idWeight, double alpha, double phi, const uchar* input);
		
		// GETTER //

		// R�cup�re un poids du vecteur de poids
		uchar& GetWeight(uint idWeight);
		uint getID() { return m_nID; }
	};
}