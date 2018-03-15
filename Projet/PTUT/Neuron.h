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

		// Variable phi qui permet de modifier les neurones proportionnellement � leur distance au neurone vainqueur
		double m_fPhi;

	public:
		// Constructeur
		Neuron();
		// Destructeur
		~Neuron();

		// SETTER //

		// Met � jour un poids du vecteur de poids
		void SetWeight(uint idWeight, double alpha, const uchar input);

		// Initialise le vecteur de poids
		void InitiateWeight(uint WeightDim, uint height, uint width);

		//Met � jour phi
		void setPhi(const double phi);

		// GETTER //

		// R�cup�re un poids du vecteur de poids
		uchar& GetWeight(uint idWeight);
		uint getID() { return m_nID; }
		//double getPhi() { return m_fPhi; }
	};
}