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

		// Variable phi qui permet de modifier les neurones proportionnellement à leur distance au neurone vainqueur
		double m_fPhi;

	public:
		//Neuron() { m_fWeight = nullptr; m_nWeightDim = 0; }
		// Constructeur
		Neuron(uint dimWeight = 3);
		// Destructeur
		~Neuron();

		// getActivity
		//float getActivity(const double* entryTable, Network::DistanceMetric distanceType = Network::DistanceMetric::EUCL) const;
		
		// SETTER //

		// Met à jour un poids du vecteur de poids
		void SetWeight(uint idWeight, double alpha, const uchar* input);

		//Met à jour phi
		void setPhi(double phi);

		// GETTER //

		// Récupère un poids du vecteur de poids
		uchar& GetWeight(uint idWeight);
		uint getID() { return m_nID; }
		//double getPhi() { return m_fPhi; }
	};
}