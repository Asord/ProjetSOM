#pragma once

#include "Utility.h"
#include "Neuron.h"
#include "Vector.h"
#include "Settings.h"
#include <vector>


namespace SOM
{
	class Network
	{
	public:

		// Types de calcules de distance
		enum DistanceMetric { EUCL };

	private:
		// Vecteur d'entrée : Tableau de uint de taille m_nSizeInputVector
		double* m_fInput;
		uint m_nDimInputVector;

		// Stockage activité minimum
		double m_fMinAct;

		// Id du winner dans m_vvNetwork
		Vector m_vWinner;
		// Point coordonnée d'un neurone
		// Point m_pCoordinate;

		// Dimention du tableau de neurones

		// Données utiles au traitement du réseau de neurone lors de l'apprentissage (alpha et beta)

		double m_fAlpha;
		double m_fBeta;

		// Variable phi qui permet de modifier les neurones proportionnellement
		double m_fPhi;

		// Iteration actuelle
		//uint m_nCurrentIteration;

		// Nombre d'itération de l'apprentissage //Utile pour l'interface d'Arthur
		uint m_nNbIterationMax;

		// Tableau dynamique de réseau de neurones
		std::vector<std::vector<Neuron>> m_vvNetwork;

		// Singleton instance pointer
		static Network* instance;

		Settings m_settings;
		int m_nCurrentIteration;

		// Constructeurs privé pour singleton
		Network(Settings &settings);
		
	public:
		static Network* GetInstance(Settings &settings);

		double getAlpha() { return m_fAlpha; }
		int getBeta() { return m_fBeta; }
		//int getCurrentIteration() { return m_nCurrentIteration; }
		uint getMaxIteration() { return m_nNbIterationMax; }

		//calcul le nombre maximum d'iterations
		void calcNbMaxIterations();

		//Mise à jour de Alpha
		void UpdateAlpha();
		//Mise à jour de Beta
		void UpdateBeta();

		void UpdatePhi(Vector vNeuron); //TODO: Modifier dans l'UML

		//Retourne le neurone avec l'activité la plus minime
		void SetWinner();

		//Calcul l'activité d'un neurone
		double GetActivity(Vector coordinate);
	
		// Modification du tableau de poids
		void UpdateWeight();

		// Retourne la distance entre un neurone et le neurone vainqueur
		double GetDistance(Vector coordinate);

		// Met à jour l'itération courante //TODO: Modifier dans l'UML
		void UpdateCurrentIteration(uint currentIteration) { m_nCurrentIteration = currentIteration; }

		//std::vector<std::vector<Neuron>>& GetvvNetwork() { return m_vvNetwork; }

		void AlgoSOM(int currentIteration);

		Neuron& getNeuron(int row, int col);
	};
}
