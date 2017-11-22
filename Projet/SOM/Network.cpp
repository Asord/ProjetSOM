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
		//TODO:compléter
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
		//TODO: corriger en adaptant pour la structure Vector
		auto distanceType = DistanceMetric::EUCL;
		float activity = 0;
		switch(distanceType)
				{
					case EUCL:
						for (uint idWeight = 0; idWeight < m_nDimInputVector; ++idWeight)
							activity += pow((m_fInput[idWeight]- m_vvNetwork[coordinate[0]][coordinate[1]].GetWeight(idWeight)), 2);
						activity = sqrt(activity);
				}
		return activity;
	}

	void Network::UpdateNeighbour()
	{
		//TODO: completer
	}
	
	void Network::SetWinner()
	{
		//TODO: corriger en adaptant pour la structure Vector
		m_fMinAct = 66000;
		float activity;
		for (uint row = 0; row < m_nNbRow; ++row)
			for (uint col = 0; col < m_nNbCol; ++col)
			{
				//Calcul de l'activité
				activity = GetActivity(row, col); 
				//Recherche du winner
				if (activity < m_fMinAct)
				{
					m_fMinAct = activity;
					m_nIdWinner[0] = row;
					m_nIdWinner[1] = col;
				}
			}
	}
}