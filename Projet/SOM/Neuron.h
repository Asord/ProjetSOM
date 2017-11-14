#pragma once
#include "Point.h"
#include "Network.h"

namespace SOM
{
	class Neuron
	{
	private:
		int m_nId;
		Point m_pCoordinate;

		double* m_fWeight;
		size_t m_dDimWeight;

	public:
		Neuron(size_t weightVect);
		~Neuron();

		void updateWeight(double*);


		// getActivity
		float getDistance(const double* entryTable, Network::DistanceMetric distanceType = Network::DistanceMetric::EUCL) const;
		
		double* getWeight();
	};
}