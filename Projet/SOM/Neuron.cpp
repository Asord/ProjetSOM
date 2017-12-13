#include "Neuron.h"

namespace SOM
{
	Neuron::Neuron(uint weightDim): m_pCoordinate(2)
	{
		m_nWeightDim = weightDim;
		m_fWeight = new uchar[m_nWeightDim];
		for (uint i=0; i<m_nWeightDim;++i)
			m_fWeight[i] = rand() % 255;
	}

	Neuron::~Neuron()
	{
		delete[] m_fWeight;
	}

	uchar& Neuron::GetWeight(uint idWeight)
	{
		return m_fWeight[idWeight];
	}

	void Neuron::SetWeight(uint idWeight, double alpha, double phi, uchar* input)
	{
		m_fWeight[idWeight] += alpha*phi*(input[idWeight]-m_fWeight[idWeight]);
	}
}