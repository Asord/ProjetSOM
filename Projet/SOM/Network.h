#pragma once

#include "Neuron.h"
#include "Point.h"
#include <vector>
#include "Utility.h"

namespace SOM
{
	class Network
	{
	public:

		// Types de calcules de distance
		enum DistanceMetric { EUCL };

	private:
		// Point coordonnée d'un neurone
		// Point m_pCoordinate;

		// Dimention du tableau de neurones
		int m_nNbCol;
		int m_nNbRow;

		// Données utiles au traitement du réseau de neurone lors de l'apprentissage
		const float m_fInitialAlpha;
		const float m_fInitialBeta;

		float m_fAlpha;
		float m_fBeta;

		float m_fAlphaRate;
		float m_fBetaRate;

		int m_nAlphaPeriod;
		int m_nBetaPeriod;
		
		//ajouter membres
		int m_nIteration;

		uint m_nSizeInputVector;

		// Tableau dynamique de réseau de neurones
		std::vector<std::vector<Neuron>> m_vvNetwork; // revoir dim

	public:
		// Constructeurs et destructeurs
		Network(int nbLine, int nbCol, uint weightVect, int alpha, int beta);

		void UpdateAlpha();
		void UpdateBeta();
		float getActivity(const double * entryTable, Network::DistanceMetric distanceType) const;
		//ajouter param
		void getNeighbour(std::vector<Neuron>& neighbour, Neuron& winner);

		void getWinner();
		void getDistance();
	};
}
