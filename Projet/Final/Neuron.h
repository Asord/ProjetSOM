#pragma once

#include "Utility.h"
#include "Vector.h"
#include "Utility.h"
#include <stdlib.h>
#include "../Final/Resources.h"
#include <qcolor.h>

namespace SOM
{
	class Neuron
	{
	private:

		Vector m_pCoordinate;

		// Tableau de poids (double)
		uchar* m_fWeight;

		//Dimension du vecteur de poids
		uint m_nWeightDim;
		
	public:
		// Constructeur par défaut
		Neuron() { m_fWeight = nullptr; m_nWeightDim = 0; }
		// Constructeur
		Neuron(uint dimWeight);
		// Destructeur
		~Neuron();

		// getActivity
		//float getActivity(const double* entryTable, Network::DistanceMetric distanceType = Network::DistanceMetric::EUCL) const;
		
		// Met à jour un poids du vecteur de poids
		void SetWeight(uint idWeight, double alpha, double phi, const uchar* input);
		
		// GETTER //

		// Récupère un poids du vecteur de poids
		uchar& GetWeight(uint idWeight);
	};
}