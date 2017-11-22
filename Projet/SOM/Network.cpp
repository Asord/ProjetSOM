#include "Network.h"

namespace SOM
{
	Network::Network(int nbLine, int nbCol, uint weightVect, int alpha, int beta): m_fInitialAlpha(alpha), m_fInitialBeta(beta)
	{
		m_vvNetwork.resize(nbLine);
		for (auto v : m_vvNetwork)
			v.resize(nbCol);
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

	float Network::getActivity(uint row, uint col)
	{
		auto distanceType = DistanceMetric::EUCL;
		float activity = 0;
		switch(distanceType)
				{
					case EUCL:
						for (uint idWeight = 0; idWeight < m_nSizeInputVector; ++idWeight)
							activity += pow((m_nInput[idWeight]- m_vvNetwork[row][col].getWeightTab(idWeight)), 2);
							activity = sqrt(activity);
				}
		return activity;
	}

	void Network::getNeighbour(std::vector<Neuron>& neighbour, Neuron & winner)
	{
	}
	
	void Network::getWinner()
	{
		m_fMinAct = 66000;
		float activity;
		for (uint row = 0; row < m_nNbRow; ++row)
			for (uint col = 0; col < m_nNbCol; ++col)
			{
				//Calcul de l'activité
				activity = getActivity(row, col); 
				//Recherche du winner
				if (activity < m_fMinAct)
				{
					//pas propre je sais je vais modif ça
					m_fMinAct = activity;
					m_nIdWinner[0] = row;
					m_nIdWinner[1] = col;
				}
			}
	}
	
	void Network::getDistance()
	{
		
	}
}