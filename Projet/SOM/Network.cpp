#include "Network.h"

namespace SOM
{
	Network::Network(int nbLine, int nbCol, size_t weightVect) : m_pCoordinate(2)
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

	float Network::getActivity(const double * entryTable, DistanceMetric distanceType) const
	{
		return 0.0f;
	}

	void Network::getNeighbour(std::vector<Neuron>& neighbour, Neuron & winner)
	{
	}
	
	void Network::getWinner()
	{
		for (int row = 0; row < m_nNbRow; ++row)
			for (int col = 0; col < m_nNbCol; ++col)
			{
				switch(distanceMetric)
				{
					case EUCL:
					for(int poids = 0; poids < m_nSizeInputVector; ++poids)
						act += (v(poids)-vneuron(poids))²;
					act = sqrt(act);
				}
			}
	}
	
	void Network::getDistance()
	{
		
	}
}