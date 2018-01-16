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
		//if (m_nID == 0)
		//{
		//	m_fWeight[0] = 255;
		//	m_fWeight[1] = 0;
		//	m_fWeight[2] = 0;
		//}
		//if (m_nID == 1)
		//{
		//	m_fWeight[0] = 190;
		//	m_fWeight[1] = 100;
		//	m_fWeight[2] = 255;
		//}
		//if (m_nID == 2)
		//{
		//	m_fWeight[0] = 0;
		//	m_fWeight[1] = 255;
		//	m_fWeight[2] = 0;
		//}
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
		/*int new_weight;
		int diff = input_weight - old_weight;
		if (diff < 0)
		{
			new_weight = (int)(alpha*m_fPhi*diff);
			printf("");
		}
		else
			new_weight = (uint)(alpha*m_fPhi*diff);
		m_fWeight[idWeight] += new_weight;*/
		int weightToAdd = (int)(alpha*m_fPhi*diff);
		m_fWeight[idWeight] += weightToAdd;
	}
	
	void Neuron::setPhi(const double phi)
	{
		m_fPhi = phi;
	}
}