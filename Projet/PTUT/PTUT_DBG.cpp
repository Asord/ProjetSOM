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

        for (uint i = 0;  i < m_resources_ptr->m_nNbPix; ++i)
        {
            uint col = i % m_resources_ptr->m_nWidth;
            uint row = i / m_resources_ptr->m_nWidth;

            Color color = m_resources_ptr->m_fColor[i];
            uchar red = color[0];
            uchar gre = color[1];
            uchar blu = color[2];

            QBrush brush(QColor(red, gre, blu));
            m_pEntryScene->addRect(
            (ui.graphicsPreview->width() - 5)  / m_resources_ptr->m_nWidth*col,
            (ui.graphicsPreview->height() - 5) / m_resources_ptr->m_nHeight*row,
            ui.graphicsPreview->width()        / m_resources_ptr->m_nWidth,
            ui.graphicsPreview->height()       / m_resources_ptr->m_nHeight,
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
			vDimNetwork[0] = settings.m_nNbRows;
			vDimNetwork[1] = settings.m_nNbCols;

			if (m_bDefaultResource)
			{
				DYN_FREE(m_resources_ptr);
				m_resources_ptr = new Resources(settings.m_nNbCols / 5, settings.m_nNbRows / 5);
			}


			network = new SOM::Network(settings, m_resources_ptr);

			drawInput();

			//calcul du nombre maximum d'iterations
			network->calcNbMaxIterations();

			uint maxIteration = network->getMaxIteration();

			//initialisation de la progressBar
			ui.ProgressBar->setMaximum(maxIteration);


			//boucle a déplacer pour optimiser
			for (uint it = 1; it <= maxIteration; ++it) {
				for (uint i = 0; i < m_resources_ptr->m_nHeight * m_resources_ptr->m_nWidth; ++i)
                {
					updateGraphic();
                    network->AlgoSOM(it, i);
                    updateValuesUI(it);
                }

				network->UpdateAlpha();
				network->UpdateBeta();
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

		delete network;
	}

}
#endif

