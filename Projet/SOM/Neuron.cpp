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

	double * Neuron::GetWeight(uint idWeight)
	{
		return m_fWeight(idWeight); //TODO: corriger
	}

	void Neuron::updateWeight(double* weight)
	{
		for (uint i = 0; i < m_nWeightDim; ++i)
			m_fWeight[i] = weight[i];
		// TODO: vérifier si cette partie est juste (elle n'est pas bonne je la corrigerai)
	}
}