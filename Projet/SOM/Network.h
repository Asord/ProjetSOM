#pragma once

#include "Utility.h"
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

		static Network& GetInstance(Vector dim, float initialAlpha, float initialBeta, uint size)
		{
			static Network instance(Vector dim, float initialAlpha, float initialBeta, uint size);
			return instance;
		}

	private:
		// Vecteur d'entrée : Tableau de uint de taille m_nSizeInputVector
		double* m_fInput;
		uint m_nDimInputVector;

		// Stockage activité minimum
		float m_fMinAct;

		// Id du winner dans m_vvNetwork
		Vector m_vWinner;
		// Point coordonnée d'un neurone
		// Point m_pCoordinate;

		// Dimention du tableau de neurones
		uint m_nNbCol;
		uint m_nNbRow;

		// Données utiles au traitement du réseau de neurone lors de l'apprentissage
		float m_fInitialAlpha;
		float m_fInitialBeta;

		float m_fAlpha;
		float m_fBeta;

		float m_fAlphaRate;
		float m_fBetaRate;

		uint m_nAlphaPeriod;
		uint m_nBetaPeriod;
		
		//ajouter membres
		uint m_nIteration;

		// Tableau dynamique de réseau de neurones
		std::vector<std::vector<Neuron>> m_vvNetwork;

		// Constructeurs et destructeurs
		Network(Vector dim, float initialAlpha, float initialBeta, uint size);

		Network& operator=(Network const& copy);
		Network(Network const& copy);
	public:

		void UpdateAlpha();
		void UpdateBeta();
		float GetActivity(Vector coordinate);
		//TODO: ajouter param
		void UpdateNeighbour();

		//Retourne
		void SetWinner();
		float GetActivity(Vector coordinate);

		// Retourne la dimension du tableau de poids
		uint getInputDim() { return m_nDimInputVector; }
	};
}
