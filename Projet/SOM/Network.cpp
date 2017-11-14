#include "Network.h"

namespace SOM
{
	Network::Network(int nbLine, int nbCol, size_t weightVect) : m_pCoordinate(2)
	{
		m_vvNetwork.resize(nbLine);
		for (auto v : m_vvNetwork)
			v.resize(nbCol);
	}

	void Network::getNeighbour(std::vector<Neuron>& neighbour, Neuron & winner)
	{
	}
}