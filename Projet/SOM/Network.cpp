#include "Network.h"

namespace SOM
{
	Network* Network::instance = nullptr;

	Network* Network::GetInstance(int row, int col, uint dimInputVector, float initialAlpha, float initialBeta, double alphaRate, double betaRate, uint alphaEpoch, uint betaEpoch, uint size)
	{
		if (instance == nullptr)
			instance = new Network(row, col, dimInputVector, initialAlpha, initialBeta, alphaRate, betaRate, alphaEpoch, betaEpoch, size);
		
		return instance;
	}

	//Constructeur
	Network::Network(int row, int col, uint dimInputVector, float initialAlpha, float initialBeta, double alphaRate, double betaRate, uint alphaPeriod, uint betaPeriod, uint size): m_vWinner(size)
	{
		//Initialisation des valeurs liées à Alpha et Beta
		m_fInitialAlpha = initialAlpha;
		m_fInitialBeta = initialBeta;

		m_fAlphaRate = alphaRate;
		m_fBetaRate = betaRate;

		m_nAlphaPeriod = alphaPeriod;
		m_nBetaPeriod = betaPeriod;

		uint m_nCurrentIteration=0;
		
		m_nDimInputVector = dimInputVector;
		m_nNbCol = col;
		m_nNbRow = row;

		//Création du vecteur de neurones
		m_vvNetwork.resize(m_nNbCol);
		for (int i = 0; i < m_nNbCol; ++i)
			m_vvNetwork[i].resize(m_nNbRow);

		//Initialisation du vecteur de neurones
		for(uint rows=0;rows<m_nNbRow;++rows)
			for (uint cols = 0; cols < m_nNbCol; ++cols)
			{
				Neuron m_NNeuron(dimInputVector);
				m_vvNetwork[rows][cols] = m_NNeuron;
			}
	}

	void Network::UpdateAlpha()
	{
		if (m_nCurrentIteration % m_nAlphaPeriod == 0)
			m_fAlpha = m_fInitialAlpha * exp(m_nCurrentIteration / -m_fAlphaRate);
	}

	void Network::UpdateBeta()
	{
		if (m_nCurrentIteration % m_nBetaPeriod == 0)
			m_fBeta = m_fInitialBeta * exp(m_nCurrentIteration / -m_fBetaRate);
	}

	double Network::GetActivity(Vector coordinate)
	{
		auto distanceType = DistanceMetric::EUCL;
		double activity = 0;
		switch(distanceType)
				{
					case EUCL:
						for (uint idWeight = 0; idWeight < m_nDimInputVector; ++idWeight) 
							activity += pow((m_fInput[idWeight] - m_vvNetwork[coordinate[0]][coordinate[1]].GetWeight(idWeight)), 2);
						activity = sqrt(activity);
				}
		return activity;
	}
	double Network::GetDistance(Vector coordinate)
	{
		auto distanceType = DistanceMetric::EUCL;
		double distance = 0;
		switch (distanceType)
		{
		case EUCL:
			for (uint idWeight = 0; idWeight < m_nDimInputVector; ++idWeight)
				distance += pow((m_vvNetwork[m_vWinner[0]][m_vWinner[1]].GetWeight(idWeight) - m_vvNetwork[coordinate[0]][coordinate[1]].GetWeight(idWeight)), 2);
			distance = sqrt(distance);
		}
		return distance;
	}

	// TODO: Jamais appelé
	void Network::UpdateNeighbour()
	{
		Vector vNeuron(2);
		for (uint row = 0; row < m_nNbRow; ++row)
			for (uint col = 0; col < m_nNbCol; ++col)
			{
				vNeuron[0] = row;
				vNeuron[1] = col;
				m_fPhi = exp(-GetDistance(vNeuron) / 2 * m_fBeta);
			}
	}
	
	void Network::SetWinner()
	{
		m_fMinAct = 66000;
		double activity;
		Vector vNeuron(2);
		for (uint row = 0; row < m_nNbRow; ++row)
			for (uint col = 0; col < m_nNbCol; ++col)
			{
				// Neurone pour lequel on calcule l'activité
				vNeuron[0] = row;
				vNeuron[1] = col;

				//Calcul de l'activité
				activity = GetActivity(vNeuron); 

				// Verification si vNeuron est le neurone vainqueur
				if (activity < m_fMinAct)
				{
					m_fMinAct = activity;
					//Modification du neurone vainqueur
					m_vWinner = vNeuron;
				}
			}
	}

	//TODO:Jamais appelée
	void Network::UpdateWeight(double* weight)
	{
		for (uint row = 0; row < m_nNbRow; ++row)
			for (uint col = 0; col < m_nNbCol; ++col)
				for (uint idWeight = 0; idWeight < m_nDimInputVector; ++idWeight)
					m_vvNetwork[row][col].SetWeight(idWeight, m_fAlpha, m_fPhi, m_fInput);
	}
}