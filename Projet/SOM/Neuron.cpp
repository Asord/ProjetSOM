#include "Neuron.h"
namespace SOM
{
	Neuron::Neuron(uint weightVect): m_pCoordinate(2)
	{
		m_nWeight = new uint[weightVect];
	}

	Neuron::~Neuron()
	{
		delete[] m_nWeight;
	}

	double * Neuron::getWeight()
	{
		return nullptr;
	}

	void Neuron::updateWeight(double* weight)
	{
		/* TODO: Code */
	}
}