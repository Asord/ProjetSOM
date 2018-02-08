#include "PTUT.h"

#ifdef _SOM_DEBUG
namespace SOM
{
    void PTUT::drawInput()
    {
        m_pEntryScene = new QGraphicsScene(this);
        ui.graphicsPreview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui.graphicsPreview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        QPen outlinePen(Qt::black);
        outlinePen.setWidth(0);

        for (uint i = 0;  i < m_pResources->m_nNbPix; ++i)
        {
            uint col = i % m_pResources->m_nWidth;
            uint row = i / m_pResources->m_nWidth;

            Color color = m_pResources->vector[i];
            uchar red = color[0];
            uchar gre = color[1];
            uchar blu = color[2];

            QBrush brush(QColor(red, gre, blu));
            m_pEntryScene->addRect(
            (ui.graphicsPreview->width() - 5)  / m_pResources->m_nWidth*col,
            (ui.graphicsPreview->height() - 5) / m_pResources->m_nHeight*row,
            ui.graphicsPreview->width()        / m_pResources->m_nWidth,
            ui.graphicsPreview->height()       / m_pResources->m_nHeight,
            outlinePen,
            brush
            );
        }
        ui.graphicsPreview->setScene(m_pEntryScene);
        ui.graphicsPreview->update();

    }

    void PTUT::start()
	{
		initValues();//initialisation des parametres
		checkIfReady();//verification des parametres


		if (m_bReady)
		{
			begin = std::chrono::system_clock::now();//TODO:remove apres debug

			disabledEverything();//desactive l'interface inutile

			// Creation du réseau
			SOM::Vector vDimNetwork(2);
			vDimNetwork[0] = m_settings.m_nNbRows;
			vDimNetwork[1] = m_settings.m_nNbCols;

			if (m_bDefaultResource)
			{
				DYN_FREE(m_pResources);
				m_pResources = new Resources<Color>(m_settings.m_nNbCols / 5, m_settings.m_nNbRows / 5);
			}


			m_pNetwork = new SOM::Network(&m_settings, m_pResources);

			drawInput();

			//calcul du nombre maximum d'iterations
			m_pNetwork->calcNbMaxIterations();

			uint maxIteration = m_pNetwork->getMaxIteration();

			//initialisation de la progressBar
			ui.ProgressBar->setMaximum(maxIteration);


			//boucle a déplacer pour optimiser
			for (uint it = 1; it <= maxIteration; ++it) {
				for (uint i = 0; i < m_pResources->m_nHeight * m_pResources->m_nWidth; ++i)
                {
					updateGraphic();
                    m_pNetwork->AlgoSOM(it, i);
                    updateValuesUI(it);
                }

				m_pNetwork->UpdateAlpha();
				m_pNetwork->UpdateBeta();
			}

			end = std::chrono::system_clock::now();//TODO:remove apres debug
			std::chrono::duration<double> time = end - begin;
			ui.Time->setText("Temps: " + QString::number(time.count()));

			ui.NbrIterations->setText("Apprentissage fini.");
		}
	}

	void PTUT::restart()
	{
		ui.AlphaSlider->setValue(0);
		ui.AlphaValue->setText("0");
		ui.TauxAlphaValue->setValue(0);
		ui.PeriodeAlphaValue->setValue(0);
		ui.BetaSlider->setValue(0);
		ui.BetaValue->setText("0");
		ui.TauxBetaValue->setValue(1);
		ui.PeriodeBetaValue->setValue(0);
		m_pScene->clear();
		m_pEntryScene->clear();
		ui.graphicsView->setScene(m_pScene);
		ui.graphicsPreview->setScene(m_pScene);
		ui.ProgressBar->setValue(0);
		ui.StartBtn->setEnabled(true);
		ui.NbrIterations->setText("");

		m_bDefaultResource = true;

		delete m_pNetwork;
	}

}
#endif

