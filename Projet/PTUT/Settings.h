#pragma once

#include "Utility.h"

namespace SOM
{

	struct  Settings{

		uint m_nNbRows;//nombre de lignes du réseau
		uint m_nNbCols;//nombre de colonnes du réseau
		uint m_nDimInputVector;//Dimension = 3
		double m_dInitialAlpha;//valeur initial de alpha
		double m_dAlphaRate;//taux de diminution de alpha
		uint m_nAlphaPeriod;//periode de alpha
		int m_nInitialBeta;//Valeur initial de beta
		double m_dBetaRate;//taux de diminution de beta
		uint m_nBetaPeriod;//periode de beta
		uint m_nNetworkDim; // dimension du vecteur de poids (commun aux vecteur d'entrée et aux neurones)



	private:

		Settings()
		{
			m_nNbRows = 0;
			m_nNbCols = 0;
			m_nDimInputVector = 3;
			m_dInitialAlpha = 0;
			m_dAlphaRate = 0;
			m_nAlphaPeriod = 1;
			m_nInitialBeta = 0;
			m_dBetaRate = 1;
			m_nBetaPeriod = 1;
			m_nNetworkDim = 2;
		}
	};
}
