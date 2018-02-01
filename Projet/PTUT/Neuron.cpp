#include "Neuron.h"

namespace SOM
{
	uint Neuron::m_nCounter = 0;

	Neuron::Neuron(uint weightDim): m_pCoordinate(2)
	{
		//TODO : Supprimer weightDim des param�tres et l'ajouter � Settings.
		//TODO: V�rifier quel type d'entree on utilise
		// TODO : Si type 1
		m_nID = Neuron::m_nCounter;
		Neuron::m_nCounter++;
		m_nWeightDim = weightDim;
		m_fWeight = new uchar[m_nWeightDim];
		for (uint i = 0; i < m_nWeightDim; ++i) {
			m_fWeight[i] = (uchar)(rand() % 255);
		}
		// TODO : Si type 2 (nuance de gris) � �crire
		// TODO : Si type 3 (lettre) � �crire
		// TODO : 
		/*
		Resources res;
		res.m_pData[i].m_pData // Poids de l'image index i
		*/
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