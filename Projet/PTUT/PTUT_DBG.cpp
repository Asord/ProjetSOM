#include "PTUT.h"

#ifdef _SOM_DEBUG
namespace SOM
{
   // void PTUT::drawInput()
   // {
   //     m_pEntryScene = new QGraphicsScene(this);
   //     ui.graphicsPreview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   //     ui.graphicsPreview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   //     QPen outlinePen(Qt::black);
   //     outlinePen.setWidth(0);

   //     for (uint i = 0;  i < m_pResources->byteSize; ++i)
   //     {
   //         uint col = i % m_pResources->imageWidth;
   //         uint row = i / m_pResources->imageWidth;

			//QImage& image = m_pResources->images[i];

   //         /*uchar red = m_pResources->images[i][0];
   //         uchar gre = m_pResources->images[i][1];
   //         uchar blu = m_pResources->images[i][2];*/

   //         QBrush brush(QColor(red, gre, blu));
   //         m_pEntryScene->addRect(
   //         (ui.graphicsPreview->width() - 5)  / m_pResources->imageWidth*col,
   //         (ui.graphicsPreview->height() - 5) / m_pResources->imageHeight*row,
   //         ui.graphicsPreview->width()        / m_pResources->imageWidth,
   //         ui.graphicsPreview->height()       / m_pResources->imageHeight,
   //         outlinePen,
   //         brush
   //         );
   //     }
   //     ui.graphicsPreview->setScene(m_pEntryScene);
   //     ui.graphicsPreview->update();

   // }

    void PTUT::start()
	{
		initValues();//initialisation des parametres
		checkIfReady();//verification des parametres

		srand(time(NULL));

		if (m_bReady)
		{
			begin = std::chrono::system_clock::now();//TODO:remove apres debug

			disabledEverything();//desactive l'interface inutile

			// Creation du réseau
			SOM::Vector vDimNetwork(2);
			vDimNetwork[0] = m_settings.m_nNbRows;
			vDimNetwork[1] = m_settings.m_nNbCols;

			m_pNetwork = new SOM::Network(&m_settings, m_pResources);

			m_settings.m_nDimInputVector = m_pResources->imageHeight*m_pResources->imageWidth;

			//drawInput();

			//calcul du nombre maximum d'iterations
			//m_pNetwork->calcNbMaxIterations();

			uint maxIteration = m_pNetwork->getMaxIteration();

			//initialisation de la progressBar
			ui.ProgressBar->setMaximum(maxIteration);

			//affichage des courbes de alpha et beta
			drawCurves();

			//boucle a déplacer pour optimiser
			for (uint it = 1; it <= maxIteration; ++it) {
				for (uint i = 0; i < m_pResources->byteSize; ++i)
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

		delete m_pNetwork;
	}

}
#endif

