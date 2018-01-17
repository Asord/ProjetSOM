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

        for (uint i = 0;  i < m_resources->m_nNbPix; ++i)
        {
            uint col = i % m_resources->m_nWidth;
            uint row = i / m_resources->m_nWidth;

            Color color = m_resources->m_fColor[i];
            uchar red = color[0];
            uchar gre = color[1];
            uchar blu = color[2];

            QBrush brush(QColor(red, gre, blu));
            m_pEntryScene->addRect(
            (ui.graphicsPreview->width() - 5) / m_resources->m_nWidth*col,
            (ui.graphicsPreview->height() - 5) / m_resources->m_nHeight*row,
            ui.graphicsPreview->width() / m_resources->m_nWidth,
            ui.graphicsPreview->height() / m_resources->m_nHeight,
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
			network = SOM::Network::GetInstance(settings);

			m_resources = network->GetResources();

			drawInput();

			//calcul du nombre maximum d'iterations
			network->calcNbMaxIterations();

			uint maxIteration = network->getMaxIteration();

			//initialisation de la progressBar
			ui.ProgressBar->setMaximum(maxIteration);


			//boucle a déplacer pour optimiser
			for (uint it = 1; it <= maxIteration; ++it) {
				for (uint i = 0; i < network->m_resources.m_nHeight * network->m_resources.m_nWidth; ++i)
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

}
#endif

