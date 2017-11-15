#pragma once
#include "Point.h"
#include "Utility.h"
#include "Network.h"

namespace SOM
{
	class Neuron
	{
	private:
		int m_nId;
		Point m_pCoordinate;

		// Tableau de floats de dimention weightDim
		double* m_fWeight;
		uint m_dDimWeight;

	public:
		Neuron(uint weightVect);
		~Neuron();

		void updateWeight(double*);


		// getActivity
		float getActivity(const double* entryTable, Network::DistanceMetric distanceType = Network::DistanceMetric::EUCL) const;
		
		double* getWeight();
		
		uint getWeightTab() {return m_dDimWeight;}
	};
}