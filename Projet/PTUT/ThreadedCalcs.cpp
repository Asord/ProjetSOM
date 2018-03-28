#include "ThreadedCalcs.h"

namespace SOM
{
	ThreadedCalcs::ThreadedCalcs(ThreadedCalcsParam param, QObject *parent)
		: QObject(parent)
	{
		m_pNetwork = param.nwk_ptr;
		m_pResources = param.rsc_ptr;
		m_pSettings = param.stg_ptr;

		m_nMaxIteration = param.max_it_int;

		m_fAlpha = m_pNetwork->getAlpha();
		m_fBeta = m_pNetwork->getBeta();
	}

	void ThreadedCalcs::process()
	{
		//boucle a déplacer pour optimiser
		for (m_nCurrentIteration = 1; m_nCurrentIteration <= m_nMaxIteration; ++m_nCurrentIteration)
		{
			for (int iteration = 0; iteration < m_pResources->images.size(); ++iteration)
			{
				SetWinner(m_pResources->images[iteration]);
				UpdateWeight(m_pResources->images[iteration]);
			}

			m_pNetwork->UpdateAlpha();
			m_pNetwork->UpdateBeta();
		}

		emit finished();
	}

	void ThreadedCalcs::SetWinner(QImage & image)
	{
		double alphaTest = m_fAlpha;
		double m_fMinAct = fColorMinAct;
		double activity;

		for (uint row = 0; row < m_pSettings->m_nNbRows; ++row)
			for (uint col = 0; col < m_pSettings->m_nNbCols; ++col)
			{
				//Calcul de l'activité
				activity = GetActivity(row, col, image);

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

	double ThreadedCalcs::GetActivity(uint row, uint col, QImage & image)
	{
		auto distanceType = DistanceMetric::EUCL; //TODO: ajouter d'autres methodes de calcules de distances
		double activity = 0;
		uchar neuronWeight;
		uchar colorWeight;
		switch (distanceType)
		{
		case EUCL:
			for (uint x = 0; x < m_pResources->imageWidth; ++x)
				for (uint y = 0; y < m_pResources->imageHeight; ++y)
				{
					neuronWeight = m_pNetwork->getNeuron(row, col).GetWeight(y*m_pResources->imageWidth + x);
					colorWeight = qGray(image.pixel(x, y));
					activity += pow((colorWeight - neuronWeight), 2);
				}

			activity = sqrt(activity);
		}
		return activity;
	}

	void ThreadedCalcs::UpdateWeight(QImage & image)
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
						m_pNetwork->getNeuron(row, col).SetWeight(
							y * m_pResources->imageWidth + x,
							m_fAlpha,
							qGray(image.pixel(x, y))
						);
					}
			}
	}

	void ThreadedCalcs::UpdatePhi(Vector & vNeuron)
	{
		double phi = exp(-GetDistance(vNeuron) / 2 * m_fBeta);
		m_pNetwork->getNeuron(vNeuron[0], vNeuron[1]).setPhi(phi);
	}

	double ThreadedCalcs::GetDistance(Vector& vNeuron)
	{
		auto distanceType = DistanceMetric::EUCL;  //TODO: ajouter d'autres methodes de calcules de distances
		double distance = 0;
		int diff;
		switch (distanceType)
		{
		case EUCL:
			for (uint coord = 0; coord < 2; ++coord)
			{
				diff = (int)(m_vWinner[coord] - vNeuron[coord]);
				distance += (uint)pow(diff, 2);
			}
			distance = sqrt(distance);
		}
		return distance;
	}

	int ThreadedCalcs::GetCurrentIteration()
	{
		return m_nCurrentIteration;
	}

}