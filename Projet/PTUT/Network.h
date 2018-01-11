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
		Resources m_resources;
		// Stockage activit� minimum
		double m_fMinAct;

		// Id du winner dans m_vvNetwork
		Vector m_vWinner;
		// Point coordonn�e d'un neurone
		// Point m_pCoordinate;

		// Dimention du tableau de neurones

		// Donn�es utiles au traitement du r�seau de neurone lors de l'apprentissage (alpha et beta)

		double m_fAlpha;
		double m_fBeta;

		// Variable phi qui permet de modifier les neurones proportionnellement
		//double m_fPhi;

		// Iteration actuelle
		//uint m_nCurrentIteration;

		// Nombre d'it�ration de l'apprentissage //Utile pour l'interface d'Arthur
		uint m_nNbIterationMax;

		// Tableau dynamique de reseau de neurones
		std::vector<std::vector<Neuron>> m_vvNetwork;

		// Singleton instance pointer
		static Network* instance;

		Settings m_settings;
		uint m_nCurrentIteration;

		// Constructeurs priv� pour singleton
		explicit Network(Settings &settings);
		
	public:
		static Network* GetInstance(Settings &settings);

		/* GETTER */

		double getAlpha() { return m_fAlpha; }
		double getBeta() { return m_fBeta; }
		uint getMaxIteration() { return m_nNbIterationMax; }
		//Calcul l'activit� d'un neurone
		double GetActivity(/*Vector coordinate*/ uint row, uint col, Color &color);
		// Retourne la distance entre un neurone et le neurone vainqueur
		double GetDistance(Vector& coordinate);

		// Retourne le neurone à la position row col
		Neuron& getNeuron(int row, int col);

		Resources& GetResources() { return m_resources; }
		//int getCurrentIteration() { return m_nCurrentIteration; }
		//std::vector<std::vector<Neuron>>& GetvvNetwork() { return m_vvNetwork; }

		//calcul le nombre maximum d'iterations
		void calcNbMaxIterations();

		//Mise � jour de Alpha
		void UpdateAlpha();
		//Mise � jour de Beta
		void UpdateBeta();

		void UpdatePhi(Vector& vNeuron); //TODO: Modifier dans l'UML

		//Retourne le neurone avec l'activit� la plus minime
		void SetWinner(Color& color);

	
		// Modification du tableau de poids
		void UpdateWeight(Color& color);


		// Met � jour l'it�ration courante //TODO: Modifier dans l'UML
		void UpdateCurrentIteration(uint currentIteration) { m_nCurrentIteration = currentIteration; }


		void AlgoSOM(uint currentIteration, uint i);

	};
}
