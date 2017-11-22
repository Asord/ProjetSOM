#include "Neuron.h"
namespace SOM
{
	Neuron::Neuron(uint weightVect): m_pCoordinate(2)
	{
		m_fWeight = new double[weightVect];
		m_nDimWeight = weightVect;
	}

	Neuron::~Neuron()
	{
		delete[] m_fWeight;
	}

	double * Neuron::GetWeight()
	{
		return m_fWeight;
	}

	void Neuron::updateWeight(double* weight)
	{
		for (uint i = 0; i < m_nDimWeight; ++i)
			m_fWeight[i] = weight[i];
		// TODO: vérifier si cette partie est juste
	}
}