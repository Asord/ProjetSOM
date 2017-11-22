#include "Network.h"

namespace SOM
{
	Network* Network::instance = nullptr;

	Network* Network::getInstance(Vector dim, float initialAlpha, float initialBeta, uint size)
	{
		if (instance == nullptr)
			instance = new Network(dim, initialAlpha, initialBeta, size);
		
		return instance;
	}



	Network::Network(Vector dim, float initialAlpha, float initialBeta, uint size): m_vWinner(size)
	{
		m_fInitialAlpha = initialAlpha;
		m_fInitialBeta = initialBeta;
		m_vvNetwork.resize(dim[0]);
		for (auto v : m_vvNetwork)
			v.resize(dim[1]);
	}

	void Network::UpdateAlpha()
	{
		if (m_nIteration % m_nAlphaPeriod == 0)
			m_fAlpha = m_fInitialAlpha * exp(-m_nIteration / m_fAlphaRate);
	}

	void Network::UpdateBeta()
	{
		if (m_nIteration % m_nBetaPeriod == 0)
			m_fBeta = m_fInitialBeta * exp(-m_nIteration / m_fBetaRate);
	}

	float Network::GetActivity(Vector coordinate)
	{
		//TODO: corriger pour les Points
		auto distanceType = DistanceMetric::EUCL;
		float activity = 0;
		switch(distanceType)
				{
					case EUCL:
						for (uint idWeight = 0; idWeight < m_nDimInputVector; ++idWeight)
							activity += pow((m_fInput[idWeight]- m_vvNetwork[row][col].getDimWeight()), 2);
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
		//TODO: corriger pour les Point
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