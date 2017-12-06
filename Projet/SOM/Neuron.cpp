#include "Neuron.h"

namespace SOM
{
	Neuron::Neuron(uint weightDim): m_pCoordinate(2)
	{
		m_nWeightDim = weightDim;
		m_fWeight = new double[m_nWeightDim];
		for (uint i=0; i<m_nWeightDim;++i)
			m_fWeight[i] = rand() % 255;
	}

	Neuron::~Neuron()
	{
		delete[] m_fWeight;
	}

	double Neuron::GetWeight(uint idWeight)
	{
		return m_fWeight[idWeight];
	}

	void Neuron::SetWeight(uint idWeight, double alpha, double phi, double* input)
	{
		m_fWeight[idWeight] += alpha*phi*(input[idWeight]-m_fWeight[idWeight]);
	}
}