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

	float Network::getActivity(const double * entryTable, Network::DistanceMetric distanceType) const
	{
		return 0.0f;
	}

	void Network::getNeighbour(std::vector<Neuron>& neighbour, Neuron & winner)
	{
	}
	
	void Network::getWinner()
	{
		/*TODO Define a*/
		auto a = DistanceMetric::EUCL;

		for (int row = 0; row < m_nNbRow; ++row)
			for (int col = 0; col < m_nNbCol; ++col)
			{
				switch(a)
				{
					case EUCL:
						for (int poids = 0; poids < m_nSizeInputVector; ++poids)
							/*act += (v(poids)-vneuron(poids))²;
							act = sqrt(act);*/
							printf("");

				}
			}
	}
	
	void Network::getDistance()
	{
		
	}
}