#include "Neuron.h"
#include <QDebug>

namespace SOM
{
	uint Neuron::m_nCounter = 0;

	Neuron::Neuron()
	{
		m_nID = Neuron::m_nCounter;
		Neuron::m_nCounter++;
		m_nWeightDim = 0;
		//m_fWeight = nullptr;
		m_fWeight = new uchar[m_nWeightDim];
		for (uint i = 0; i < m_nWeightDim; ++i) {
			m_fWeight[i] = (uchar)(rand() % 255);
			qDebug() << m_fWeight[i];
		}
	}

	Neuron::~Neuron()
	{
		delete[] m_fWeight;
	}

	uchar& Neuron::GetWeight(uint idWeight)
	{
		//TODO : Verifier si m_fweight = nullptr
		if (m_fWeight == nullptr)
		{
			uchar& weight = m_fWeight[idWeight];
			return weight;
		}
		else
		{
			std::cerr << "Vecteur de poids null";
			exit(EXIT_FAILURE);
		}
	}

	void Neuron::SetWeight(uint idWeight, double alpha, const uchar input)
	{
		//TODO : Verifier si m_fweight = nullptr
		if (m_fWeight == nullptr)
		{
			uint old_weight = m_fWeight[idWeight];
			uint input_weight = input;
			int diff = input_weight - old_weight;
			int weightToAdd = (int)(alpha*m_fPhi*diff);
			m_fWeight[idWeight] += weightToAdd;
		}
		else
		{
			std::cerr << "Vecteur de poids null";
			exit(EXIT_FAILURE);
		}
	}
	
	void Neuron::setPhi(const double phi)
	{
		m_fPhi = phi;
	}

	void Neuron::InitiateWeight(uint WeightDim, uint resourceType)
	{

	}
}