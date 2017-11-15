#pragma once
#include "Point.h"

namespace SOM
{
	class Neuron
	{
	private:
		int m_nId;
		Point m_pCoordinate;

		// Tableau de floats de dimention weightDim
		double* m_fWeight;
		size_t m_dDimWeight;

	public:
		Neuron(size_t weightVect);
		~Neuron();

		void updateWeight(double*);


		// getActivity
		float getActivity(const double* entryTable, Network::DistanceMetric distanceType = Network::DistanceMetric::EUCL) const;
		
		double* getWeight();
		
		size_t getWeightTab() {return m_dDimWeight;}
	};
}