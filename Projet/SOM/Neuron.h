#pragma once

#include "Utility.h"
#include "Point.h"

namespace SOM
{
	class Neuron
	{
	private:
		int m_nId;
		Point m_pCoordinate;

		// Tableau de floats de dimention weightDim
		uint* m_nWeight;
		size_t m_dDimWeight;

	public:
		Neuron(size_t weightVect);
		~Neuron();

		void updateWeight(double*);


		// getActivity
		//float getActivity(const double* entryTable, Network::DistanceMetric distanceType = Network::DistanceMetric::EUCL) const;
		
		double* getWeight();
		
		uint& getWeightTab(uint idWeight) { return m_nWeight[idWeight]; }
	};
}