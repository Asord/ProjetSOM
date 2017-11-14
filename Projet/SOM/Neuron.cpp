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

	float Neuron::getDistance(const double * entryTable, Network::DistanceMetric distanceType) const
	{
		return 0.0f;
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