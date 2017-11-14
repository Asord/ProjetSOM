#pragma once

#include "Neuron.h"
#include "Point.h"
#include <vector>

namespace SOM
{
	class Network
	{
	public:

		// Types de calcules de distance
		enum DistanceMetric { EUCL };

	private:
		// Point coordonn�e d'un neurone
		// Point m_pCoordinate;

		// Dimention du tableau de neurones
		int m_nNbCol;
		int m_nNbRow;

		// Donn�es utiles au traitement du r�seau de neurone lors de l'apprentissage
		float m_fAlpha;
		float m_fBeta;
		//ajouter membres
		//int m_nIteration;

		// Tableau dynamique de r�seau de neurones
		std::vector<std::vector<Neuron>> m_vvNetwork; // revoir dim

	public:
		// Constructeurs et destructeurs
		Network(int nbLine, int nbCol, size_t weightVect);

		//ajouter param
		void getNeighbour(std::vector<Neuron>& neighbour, Neuron& winner);
	};
}
