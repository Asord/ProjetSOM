#pragma once

#include "Utility.h"
#include "Vector.h"
#include "Utility.h"

namespace SOM
{
	class Neuron
	{
	private:
		//TODO: A quoi sert l'id ?
		uint m_nId;
		Vector m_pCoordinate;

		// Tableau de poids (double)
		double* m_fWeight;

		//Dimension du vecteur de poids
		uint m_nWeightDim;
		
	public:
		// Constructeur par défaut
		Neuron() { m_nWeightDim = 0; }
		// Constructeur
		Neuron(uint dimWeight);
		// Destructeur
		~Neuron();

		// getActivity
		//float getActivity(const double* entryTable, Network::DistanceMetric distanceType = Network::DistanceMetric::EUCL) const;
		
		// Met à jour un poids du vecteur de poids
		void SetWeight(uint idWeight, double alpha, double phi, double* input);
		
		// Récupère un poids du vecteur de poids
		double GetWeight(uint idWeight);
	};
}