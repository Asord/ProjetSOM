#include "Network.h"
#include <QDebug>
#include <ctime>

namespace SOM
{
	//Constructeur
	Network::Network(Settings* settings_ptr, Elements* resources_ptr) : m_vWinner(settings_ptr->m_nNetworkDim)
	{
		m_pSettings = settings_ptr;

		m_pResources = resources_ptr;

		if (m_pResources == nullptr)
			exit(0xa); 

		//initialisation alpha et beta
		m_fAlpha = m_pSettings->m_dInitialAlpha;
		m_fBeta = m_pSettings->m_nInitialBeta;

		m_nCurrentIteration = 1;
		calcNbMaxIterations();

		// Aléatoire fait par rapport au temps
		srand((uint)time(NULL));

		//Création du vecteur de neurones
		m_vvNetwork.resize(m_pSettings->m_nNbCols);
		for (int i = 0; i < m_pSettings->m_nNbCols; ++i)
			m_vvNetwork[i].resize(m_pSettings->m_nNbRows);


		for (int i = 0; i < m_pSettings->m_nNbCols; ++i)
			for (int j = 0; j < m_pSettings->m_nNbRows; ++j)
				m_vvNetwork[i][j].InitiateWeight(m_pSettings->m_nDimInputVector, m_pResources->imageHeight, m_pResources->imageWidth);
		//TODO : pb ici
		//m_vvNetwork.resize(m_pSettings->m_nNbCols);
		//for (int i = 0; i < m_pSettings->m_nNbCols; ++i)
		//{
		//	m_vvNetwork[i].reserve(m_pSettings->m_nNbRows);
		//	for (int j = 0; j < m_pSettings->m_nNbRows; ++j)
		//	{
		//		{
		//			Neuron n = Neuron();
		//			m_vvNetwork[i].push_back(n);
		//		}
		//		qDebug() << m_vvNetwork[i][j].GetWeight(0) << " " 
		//			<< m_vvNetwork[i][j].GetWeight(1) << " "
		//			<< m_vvNetwork[i][j].GetWeight(2) << " ";
		//	}
		//}

		//qDebug() << "Affichage du réseau";
		//
		//for (uint i = 0; i < m_pSettings->m_nNbCols; ++i)
		//	for (uint j = 0; j < m_pSettings->m_nNbRows; ++j)
		//		for (uint w = 0; w <3; ++w)
		//			qDebug() << m_vvNetwork[i][j].GetWeight(w);

		//Initialisation du vecteur de neurones
		uint valueWeight;
		uint id = 0;
	}

	void Network::calcNbMaxIterations()
	{
		double alpha = m_fAlpha;
		m_nNbIterationMax = 0;
		if (m_pSettings->m_dEndAlpha == 0)
			m_pSettings->m_dEndAlpha = 0.03;

		while (alpha > m_pSettings->m_dEndAlpha)
		{
			alpha -= alpha * m_pSettings->m_dAlphaRate;
			m_nNbIterationMax++;
			//ajout de toutes les valeurs de alpha dans un tableau pour les courbes
			m_vAlphaValues.push_back(alpha);
		}	
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

	double Network::GetActivity(uint row, uint col, QImage& image)
	{
		auto distanceType = DistanceMetric::EUCL; //TODO: ajouter d'autres methodes de calcules de distances
		double activity = 0;
		uchar neuronWeight;
		uchar colorWeight;
		switch (distanceType)
		{
		case EUCL:
			for(uint x = 0; x < m_pResources->imageWidth; ++x)
				for(uint y = 0; y < m_pResources->imageHeight; ++y)
				{
					neuronWeight = this->getNeuron(row, col).GetWeight(y*m_pResources->imageWidth+x);
					colorWeight = qGray(image.pixel(x, y));
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
		SetWinner(m_pResources->images[i]);
		UpdateWeight(m_pResources->images[i]);
		UpdateCurrentIteration(currentIteration);

	}

	void Network::UpdatePhi(Vector& vNeuron)
	{
		double phi = exp(-GetDistance(vNeuron) / 2 * m_fBeta);
		getNeuron(vNeuron[0], vNeuron[1]).setPhi(phi);

	}

	void Network::SetWinner(QImage& color)
	{
		double alphaTest = m_fAlpha;
		m_fMinAct = fColorMinAct;
		double activity;
		for (uint row = 0; row < m_pSettings->m_nNbRows; ++row)
			for (uint col = 0; col < m_pSettings->m_nNbCols; ++col)
			{
				//Calcul de l'activité
				activity = GetActivity(row, col, color);

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

	void Network::UpdateWeight(QImage &image)
	{
		Vector vNeuron(2);
		for (uint row = 0; row < m_pSettings->m_nNbRows; ++row)
			for (uint col = 0; col < m_pSettings->m_nNbCols; ++col)
			{
				vNeuron[0] = row;
				vNeuron[1] = col;

				UpdatePhi(vNeuron);
				for (uint x = 0; x < m_pResources->imageWidth; ++x)
					for (uint y = 0; y < m_pResources->imageHeight; ++y)
					{
						this->getNeuron(row, col).SetWeight(
							y * m_pResources->imageWidth + x,
							m_fAlpha,
							qGray(image.pixel(x, y))
						);
					}
			}
	}

	Neuron& Network::getNeuron(int row, int col)
	{
		Neuron& neuron = m_vvNetwork[col][row];
		return neuron;
	}
}