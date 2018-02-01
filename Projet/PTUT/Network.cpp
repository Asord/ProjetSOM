#include "Network.h"
#include <ctime>

namespace SOM
{
	//Constructeur
	Network::Network(Settings* settings_ptr, Resources* resources_ptr) : m_vWinner(settings_ptr->m_nNetworkDim)
	{
		m_pSettings = settings_ptr;

		m_pResources = resources_ptr;

		//initialisation alpha et beta
		m_fAlpha = m_pSettings->m_dInitialAlpha;
		m_fBeta = m_pSettings->m_nInitialBeta;

		m_nCurrentIteration = 1;
		m_nNbIterationMax = 0;

		// Aléatoire fait par rapport au temps
		srand((uint)time(NULL));

		m_pRessource = resources_ptr;

		//Création du vecteur de neurones
		m_vvNetwork.resize(m_pSettings->m_nNbCols);
		for (int i = 0; i < m_pSettings->m_nNbCols; ++i)
			m_vvNetwork[i].resize(m_pSettings->m_nNbRows);

		//Initialisation du vecteur de neurones
		uint valueWeight;
		uint id = 0;
	}

	void Network::calcNbMaxIterations()
	{
		uint iteration = 1;
		double alpha = m_fAlpha;
		while (alpha > 0.03)
		{
			alpha -= alpha * m_pSettings->m_dAlphaRate;
			m_nNbIterationMax++;
		}
		m_nNbIterationMax *= m_pSettings->m_nAlphaPeriod/2;
	}

	void Network::UpdateAlpha()
	{
		if (m_nCurrentIteration % m_pSettings->m_nAlphaPeriod == 0)
			m_fAlpha -= m_fAlpha * m_pSettings->m_dAlphaRate;
	}

	void Network::UpdateBeta()
	{
		if (m_nCurrentIteration % m_pSettings->m_nBetaPeriod == 0)

			m_fBeta -= m_fBeta * m_pSettings->m_dBetaRate;
	}

	double Network::GetActivity(uint row, uint col, SOMData& data)
	{
		auto distanceType = DistanceMetric::EUCL; //TODO: ajouter d'autres methodes de calcules de distances
		double activity = 0;
		uchar neuronWeight;
		uchar colorWeight;
		switch (distanceType)
		{
		case EUCL:
			for (uint idWeight = 0; idWeight < m_pSettings->m_nDimInputVector; ++idWeight)
			{
				neuronWeight = this->getNeuron(row, col).GetWeight(idWeight);
				colorWeight = data[idWeight];
				activity += pow((colorWeight - neuronWeight), 2);
			}
			activity = sqrt(activity);
		}
		return activity;
	}

	double Network::GetDistance(Vector& neuron)
	{
		auto distanceType = DistanceMetric::EUCL;  //TODO: ajouter d'autres methodes de calcules de distances
		double distance = 0;
		int diff;
		switch (distanceType)
		{
		case EUCL:
			for (uint coord = 0; coord < 2; ++coord)
			{
				diff = (int)(m_vWinner[coord] - neuron[coord]);
				distance += (uint)pow(diff, 2);
			}
			distance = sqrt(distance);
		}
		return distance;
	}

	void Network::AlgoSOM(uint currentIteration, uint i)
	{
		SetWinner(m_pResources->m_pData[i]);
		UpdateWeight(m_pResources->m_pData[i]);
		UpdateCurrentIteration(currentIteration);

	}

	void Network::UpdatePhi(Vector& vNeuron)
	{
		double phi = exp(-GetDistance(vNeuron) / 2 * m_fBeta);
		getNeuron(vNeuron[0], vNeuron[1]).setPhi(phi);

	}

	void Network::SetWinner(SOMData& data)
	{
		double alphaTest = m_fAlpha;
		m_fMinAct = fColorMinAct;
		double activity;
		for (uint row = 0; row < m_pSettings->m_nNbRows; ++row)
			for (uint col = 0; col < m_pSettings->m_nNbCols; ++col)
			{
				//Calcul de l'activité
				activity = GetActivity(row, col, data);

				// Verification si vNeuron est le neurone vainqueur
				if (activity < m_fMinAct)
				{
					m_fMinAct = activity;
					//Modification du neurone vainqueur
					m_vWinner[0] = row;
					m_vWinner[1] = col;
				}
			}
	}

	void Network::UpdateWeight(SOMData& data)
	{
		Vector vNeuron(2);
		for (uint row = 0; row < m_pSettings->m_nNbRows; ++row)
			for (uint col = 0; col < m_pSettings->m_nNbCols; ++col)
			{
				vNeuron[0] = row;
				vNeuron[1] = col;

				UpdatePhi(vNeuron);
				for (uint idWeight = 0; idWeight < m_pSettings->m_nDimInputVector; ++idWeight)
					this->getNeuron(row, col).SetWeight(idWeight, m_fAlpha, data[idWeight]);
			}
	}

	Neuron& Network::getNeuron(int row, int col)
	{
		return m_vvNetwork[col][row];
	}
}