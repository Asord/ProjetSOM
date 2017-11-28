#include "Network.h"

namespace SOM
{
	Network* Network::instance = nullptr;

	Network* Network::getInstance(Vector dim, uint dimInputVector, float initialAlpha, float initialBeta, uint size)
	{
		if (instance == nullptr)
			instance = new Network(dim, dimInputVector, initialAlpha, initialBeta, size);
		
		return instance;
	}

	//Constructeur
	Network::Network(Vector dimNetwork, uint dimInputVector, float initialAlpha, float initialBeta, uint size): m_vWinner(size)
	{
		//Initialisation des valeurs liées à Alpha et Beta
		m_fInitialAlpha = initialAlpha;
		m_fInitialBeta = initialBeta;
		//TODO:compléter les initialisations
		uint m_nCurrentIteration=0;
		
		m_nDimInputVector = dimInputVector;
		m_nNbCol = dimNetwork[0];
		m_nNbRow = dimNetwork[1];

		//Création du vecteur de neurones
		m_vvNetwork.resize(m_nNbCol);
		for (auto v : m_vvNetwork)
			v.resize(m_nNbRow);

		//Initialisation du vecteur de neurones
		for(uint row=0;row<m_nNbRow;++row)
			for (uint col = 0; col < m_nNbCol; ++col)
			{
				Neuron m_NNeuron(dimInputVector);
				m_vvNetwork[row][col] = m_NNeuron;
			}
	}

	void Network::UpdateAlpha()
	{
		if (m_nCurrentIteration % m_nAlphaPeriod == 0)
			m_fAlpha = m_fInitialAlpha * exp(-m_nCurrentIteration / m_fAlphaRate);
	}

	void Network::UpdateBeta()
	{
		if (m_nCurrentIteration % m_nBetaPeriod == 0)
			m_fBeta = m_fInitialBeta * exp(-m_nCurrentIteration / m_fBetaRate);
	}

	float Network::GetActivity(Vector coordinate)
	{
		auto distanceType = DistanceMetric::EUCL;
		float activity = 0;
		switch(distanceType)
				{
					case EUCL:
						for (uint idWeight = 0; idWeight < m_nDimInputVector; ++idWeight) 
							activity += pow((m_fInput[idWeight] - m_vvNetwork[coordinate[0]][coordinate[1]].GetWeight(idWeight)), 2);
						activity = sqrt(activity);
				}
		return activity;
	}

	void Network::UpdateNeighbour()
	{
		//TODO: completer (utilisation de la variable m_fPhi)
	}
	
	void Network::SetWinner()
	{
		m_fMinAct = 66000;
		float activity;
		Vector vNeuron(2);
		for (uint row = 0; row < m_nNbRow; ++row)
			for (uint col = 0; col < m_nNbCol; ++col)
			{
				// Neurone pour lequel on calcule l'activité
				vNeuron[0] = row;
				vNeuron[1] = col;

				//Calcul de l'activité
				activity = GetActivity(vNeuron); 

				// Verification si vNeuron est le neurone vainqueur
				if (activity < m_fMinAct)
				{
					m_fMinAct = activity;
					//Modification du neurone vainqueur
					m_vWinner = vNeuron;
				}
			}
	}

	//TODO:Jamais appelée
	void Network::updateWeight(double* weight, Vector coordinate)
	{
		for (uint idWeight = 0; idWeight < m_nDimInputVector; ++idWeight)
			m_vvNetwork[coordinate[0]][coordinate[1]].SetWeight(idWeight, m_fAlpha, m_fPhi, m_fInput);
	}
}