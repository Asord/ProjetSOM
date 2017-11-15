#include "Neuron.h"
namespace SOM
{
	Neuron::Neuron(size_t weightVect): m_pCoordinate(2)
	{
		m_fWeight = new double[weightVect];
	}

	Neuron::~Neuron()
	{
		delete[] m_fWeight;
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