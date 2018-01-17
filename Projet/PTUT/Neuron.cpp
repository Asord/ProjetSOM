#include "Neuron.h"

namespace SOM
{
	uint Neuron::m_nCounter = 0;

	Neuron::Neuron(uint weightDim): m_pCoordinate(2)
	{
		m_nID = Neuron::m_nCounter;
		Neuron::m_nCounter++;
		m_nWeightDim = weightDim;
		m_fWeight = new uchar[m_nWeightDim];
		for (uint i = 0; i < m_nWeightDim; ++i) {
			m_fWeight[i] = (uchar)(rand() % 255);
		}
	}

	Neuron::~Neuron()
	{
		delete[] m_fWeight;
	}

	uchar& Neuron::GetWeight(uint idWeight)
	{
		return m_fWeight[idWeight];
	}

	void Neuron::SetWeight(uint idWeight, double alpha, const uchar input)
	{
		uint old_weight = m_fWeight[idWeight];
		uint input_weight = input;
		int diff = input_weight - old_weight;
		int weightToAdd = (int)(alpha*m_fPhi*diff);
		m_fWeight[idWeight] += weightToAdd;
	}
	
	void Neuron::setPhi(const double phi)
	{
		m_fPhi = phi;
	}
}