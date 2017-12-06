#pragma once

#include "Utility.h"
#include "Neuron.h"
#include "Vector.h"
#include <vector>


namespace SOM
{
	class Network
	{
	public:

		// Types de calcules de distance
		enum DistanceMetric { EUCL };

	private:
		// Vecteur d'entr�e : Tableau de uint de taille m_nSizeInputVector
		double* m_fInput;
		uint m_nDimInputVector;

		// Stockage activit� minimum
		double m_fMinAct;

		// Id du winner dans m_vvNetwork
		Vector m_vWinner;
		// Point coordonn�e d'un neurone
		// Point m_pCoordinate;

		// Dimention du tableau de neurones
		uint m_nNbCol;
		uint m_nNbRow;

		// Donn�es utiles au traitement du r�seau de neurone lors de l'apprentissage (alpha et beta)
		double m_fInitialAlpha;
		double m_fInitialBeta;

		double m_fAlpha;
		double m_fBeta;

		double m_fAlphaRate;
		double m_fBetaRate;

		uint m_nAlphaPeriod;
		uint m_nBetaPeriod;
		//

		// Variable phi qui permet de modifier les neurones proportionnellement
		double m_fPhi;

		// Iteration actuelle
		uint m_nCurrentIteration;

		// Nombre d'it�ration de l'apprentissage //Utile pour l'interface d'Arthur
		uint m_nNbIteration; //TODO: Calculer � partir de alpha

		// Tableau dynamique de r�seau de neurones
		std::vector<std::vector<Neuron>> m_vvNetwork;

		// Singleton instance pointer
		static Network* instance;

		// Constructeurs priv� pour singleton
		Network(int row, int col, uint dimInputVector, float initialAlpha, float initialBeta, double alphaRate, double betaRate, uint alphaEpoch, uint betaEpoch, uint size);
		
	public:
		static Network* GetInstance(int row, int col, uint dimInputVector, float initialAlpha, float initialBeta, double alphaRate, double betaRate, uint alphaEpoch, uint betaEpoch, uint size);

		//Mise � jour de Alpha
		void UpdateAlpha();
		//Mise � jour de Beta
		void UpdateBeta();

		//TODO: Faire cette fonction
		void UpdateNeighbour();

		//Retourne le neurone avec l'activit� la plus minime
		void SetWinner();

		//Calcul l'activit� d'un neurone
		double GetActivity(Vector coordinate);

		// Retourne la dimension du tableau de poids
		uint GetInputDim() { return m_nDimInputVector; } // TODO: pas s�re que �a soit utile
	
		// Modification du tableau de poids
		void UpdateWeight(double*);

		// Retourne la distance entre un neurone et le neurone vainqueur
		double GetDistance(Vector coordinate);


		std::vector<std::vector<Neuron>> GetvvNetwork() { return m_vvNetwork; }
	};
}
