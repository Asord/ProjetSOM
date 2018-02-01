#include "Neuron.h"

namespace SOM
{
	uint Neuron::m_nCounter = 0;

	Neuron::Neuron(): m_pCoordinate(2)
	{
		if (m_pRsc == nullptr)
		{
			std::cout << "Ressources non assignéeesesesses aux neurones!";
			exit(8);
		}

		m_nID = Neuron::m_nCounter;
		Neuron::m_nCounter++;

		m_nWeightDim = m_pRsc->m_nImageSize;
		m_fWeight = new uchar[m_nWeightDim];

		if (m_pRsc->m_cVersion == 1)
		{
			for (uint i = 0; i < m_nWeightDim; ++i) {
				m_fWeight[i] = (uchar)(rand() % 255);
			}
		}
		// TODO : Si type 2 (nuance de gris) à écrire
		else if (m_pRsc->m_cVersion == 3)
		{

			for (uint i = 0; i < m_nWeightDim; ++i) {
				m_fWeight[i] = (uchar)(rand() % 1) * 255;
				//*m_pRessource->m_pData[i].m_pData; // Poids de l'image à l'index i
			}
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