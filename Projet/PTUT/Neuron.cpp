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
<<<<<<< HEAD
			m_fWeight[i] = (uint(rand() % 255));
=======
			m_fWeight[i] = (uchar)(rand() % 255);
>>>>>>> 2a1021c8507ab7ca51ad5cdac59dd0b4a065ced3
			printf("%d", m_fWeight[i]);
		}
		/*uchar weight = this->GetWeight(0);
		uchar weight1 = this->GetWeight(1);
		uchar weight2 = this->GetWeight(2);*/
		/*uint red = m_fWeight[0] = (uchar)(rand() % 255);
		uint green = m_fWeight[1] = (uchar)(rand() % 255);
		uint blue = m_fWeight[2] = (uchar)(rand() % 255);*/
		printf("");
	}

	Neuron::~Neuron()
	{
		delete[] m_fWeight;
	}

	uchar& Neuron::GetWeight(uint idWeight)
	{
		return m_fWeight[idWeight];
	}

	void Neuron::SetWeight(uint idWeight, double alpha, double phi, const uchar* input)
	{
		double old_weight = m_fWeight[idWeight];
		m_fWeight[idWeight] += alpha*phi*(input[idWeight]-old_weight);
		printf("");
	}
}