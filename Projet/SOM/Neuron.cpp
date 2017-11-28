#include "Neuron.h"
#include "Network.h"

namespace SOM
{
	Neuron::Neuron(uint weightDim): m_pCoordinate(2)
	{
		m_nWeightDim = weightDim;
		m_fWeight = new double[m_nWeightDim];
	}

	Neuron::~Neuron()
	{
		delete[] m_fWeight;
	}

	double Neuron::GetWeight(uint idWeight)
	{
		return m_fWeight[idWeight];
	}

	void Neuron::SetWeight(uint idWeight, float alpha, float phi, double* input)
	{
		m_fWeight[idWeight] += alpha*phi*(input[idWeight]-m_fWeight[idWeight]);
	}
}