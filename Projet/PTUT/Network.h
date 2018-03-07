#pragma once

#include "Utility.h"
#include "Neuron.h"
#include "Vector.h"
#include "Settings.h"
#include "Resources.h"
#include <vector>


namespace SOM
{
	class Network
	{
	public:

		// Types de calcules de distance
		enum DistanceMetric { EUCL };

	private:
		// Stockage activit� minimum
		double m_fMinAct;

		// Id du winner dans m_vvNetwork
		Vector m_vWinner;

		// Donn�es utiles au traitement du r�seau de neurone lors de l'apprentissage (alpha et beta)
		double m_fAlpha, m_fBeta;

		// Nombre d'it�ration de l'apprentissage //Utile pour l'interface d'Arthur
		uint m_nNbIterationMax;

		// Tableau dynamique de reseau de neurones
		std::vector<std::vector<Neuron>> m_vvNetwork;

		//Tableau dynamique des valeurs de alpha
		std::vector<double> m_vAlphaValues;

		Settings* m_pSettings;
		Resources* m_pResources;

		uint m_nCurrentIteration;

	public:
		// Constructeurs priv� pour singleton
		Network(Settings* settings, Resources* resources_ptr);

		/* GETTER */

		double getAlpha() { return m_fAlpha; }
		double getBeta() { return m_fBeta; }
		uint getMaxIteration() { return m_nNbIterationMax; }
		std::vector<double> getAlphaValues() { return m_vAlphaValues; }

		//Calcul l'activit� d'un neurone
		double GetActivity(uint row, uint col, SomElement &color);

		// Retourne la distance entre un neurone et le neurone vainqueur
		double GetDistance(Vector& coordinate);

		// Retourne le neurone à la position row col
		Neuron& getNeuron(int row, int col);

		//calcul le nombre maximum d'iterations
		void calcNbMaxIterations();

		//Mise � jour de Alpha
		void UpdateAlpha();
		//Mise � jour de Beta
		void UpdateBeta();

		void UpdatePhi(Vector& vNeuron);

		//Retourne le neurone avec l'activit� la plus minime
		void SetWinner(SomElement& color);

		// Modification du tableau de poids
		void UpdateWeight(SomElement& color);

		void UpdateCurrentIteration(uint currentIteration) { m_nCurrentIteration = currentIteration; }

		void AlgoSOM(uint currentIteration, uint i);

	};
}
