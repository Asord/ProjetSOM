#include "PTUT.h"
#include <QWaitCondition>
#include <QMutex>
#include <QFileDialog>

namespace SOM {

	PTUT::PTUT(QWidget *parent)
		: QWidget(parent)
	{
		ui.setupUi(this);
	}

	void PTUT::setRows()
	{
		//met la valeur du compteur dans la variable m_nNbRows
		settings.m_nNbRows = (uint)ui.LigneValue->value();
		if (settings.m_nNbRows > ui.BetaValue->maximum())
			ui.BetaValue->setMaximum(settings.m_nNbRows);
	}

	void PTUT::setColumns()
	{
		//met la valeur du compteur dans la variable m_nNbCols
		settings.m_nNbCols = (uint)ui.ColValue->value();
		if (settings.m_nNbCols > ui.BetaValue->maximum())
			ui.BetaValue->setMaximum(settings.m_nNbCols);
	}

	void PTUT::updateValuesUI(int currentIteration)
	{
		//alpha
		ui.AlphaSlider->setSliderPosition((int)network->getAlpha() * 1000);
		ui.AlphaValue->setText(QString::number(network->getBeta() + 0.006));

		//beta
		ui.BetaValue->setValue((int)network->getBeta());

		ui.ProgressBar->setValue(currentIteration);

		//calcul nombre d'itérations a faire
		ui.NbrIterations->setText("Iterations : " + QString::number(currentIteration) + "/" + QString::number(network->getMaxIteration()));
	}

	void PTUT::updateGraphic()
	{

		m_pScene = new QGraphicsScene(this);
		ui.graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		ui.graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

		QPen outlinePen(Qt::black);
		outlinePen.setWidth(0);

		//dessine chaque neurone du reseau
		uint red, green, blue, id;
		//Neuron neuron(3);
		for (uint row = 0; row < settings.m_nNbRows; row++)
		{
			for (uint col = 0; col < settings.m_nNbCols; col++) {
				
				red = network->getNeuron(row, col).GetWeight(0);
				green = network->getNeuron(row, col).GetWeight(1);
				blue = network->getNeuron(row, col).GetWeight(2);
				id = network->getNeuron(row, col).getID();

				QBrush brush(QColor(red, green, blue));
				m_pScene->addRect((ui.graphicsView->width() - 5) / settings.m_nNbCols*col, (ui.graphicsView->height() - 5) / settings.m_nNbRows*row, ui.graphicsView->width() / settings.m_nNbCols, ui.graphicsView->height() / settings.m_nNbRows, outlinePen, brush);
				printf("");
			}
		}
		ui.graphicsView->setScene(m_pScene);
		ui.graphicsView->update();

		printf("");
	}

	void PTUT::setAlphaValueText()
	{
		//met la valeur du slider dans la variable m_dAlpha
		ui.AlphaValue->setText(QString::number(ui.AlphaSlider->value() / 1000.0 + 0.006));
	}

	void PTUT::setEuclidian()
	{
		//initialisation de m_bEuclidian fonction de si la case est cochée ou non
		m_bEuclidian = ui.Distance1->isChecked();
	}

	void PTUT::alphaRateConstraint()
	{
		//empeche le taux de alpha d'etre supérieur au taux de beta
		if (ui.TauxAlphaValue->value() >= ui.TauxBetaValue->value())
			ui.TauxAlphaValue->setValue(ui.TauxBetaValue->value() - 0.01);
	}

	void PTUT::betaRateConstraint()
	{
		//empeche le taux de beta d'etre inferieur au taux de alpha
		if (ui.TauxBetaValue->value() <= ui.TauxAlphaValue->value())
			ui.TauxBetaValue->setValue(ui.TauxAlphaValue->value() + 0.01);
	}

	void PTUT::setBeta()
	{
		ui.BetaValue->setMaximum(std::max(ui.LigneValue->value(), ui.ColValue->value()));
	}

	void PTUT::restart()
	{
		ui.AlphaSlider->setValue(0);
		ui.AlphaValue->setText("0");
		ui.TauxAlphaValue->setValue(0);
		ui.PeriodeAlphaValue->setValue(0);
		ui.TauxBetaValue->setValue(1);
		ui.PeriodeBetaValue->setValue(0);
		m_pScene->clear();
		ui.graphicsView->setScene(m_pScene);
		//TODO: réinitialiser le reseau (MaxIterations)
	}

	void PTUT::openFile()
	{
		//choix du fichier
		QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),"C://", tr("Image Files (*.png *.jpg *.bmp)"));

		//récupération du chemin du fichier
		QFileInfo fileInfo(filename);
		QString dirPath = fileInfo.filePath();

		//stoquage des couleur dans un tableau
		Resources(dirPath.toStdString);
	}

	void PTUT::initValues() {

		//initialisation des parametres
		settings.m_dInitialAlpha = ui.AlphaSlider->value() / 1000.0;
		settings.m_dAlphaRate = ui.TauxAlphaValue->value();
		settings.m_nAlphaPeriod = (uint)ui.PeriodeAlphaValue->value();
		settings.m_nInitialBeta = ui.BetaValue->value();
		settings.m_dBetaRate = ui.TauxBetaValue->value();
		settings.m_nBetaPeriod = (uint)ui.PeriodeBetaValue->value();


		//initialisation des messages d'erreur
		ui.ErreurLignes->setText("");
		ui.ErreurColonnes->setText("");
	}

	void PTUT::checkIfReady()
	{
		//verifie que le taux alpha n'est pas egal au taux beta
		if (settings.m_dAlphaRate == settings.m_dBetaRate)
			m_bReady = false;

		//verifie que le nombre de ligne est correct
		if (settings.m_nNbRows == 0)
		{
			ui.ErreurLignes->setText("Veuillez saisir une valeur valide.");
			m_bReady = false;
		}
		//verifie que le nombre de colonnes est correct
		if (settings.m_nNbCols == 0)
		{
			ui.ErreurColonnes->setText("Veuillez saisir une valeur valide.");
			m_bReady = false;
		}
	}

	void PTUT::disabledEverything()
	{
		//desactive les elements de l'interface
		ui.NouveauRes->setEnabled(false);
		ui.StartBtn->setEnabled(false);
		ui.PauseBtn->setEnabled(true);
		ui.ProgressBar->setEnabled(true);
		ui.NbrIterations->setEnabled(true);
		ui.Restart->setEnabled(false);
	}

	void PTUT::activateEverything()
	{
		ui.NouveauRes->setEnabled(true);
		ui.StartBtn->setEnabled(true);
		ui.PauseBtn->setEnabled(false);
		ui.ProgressBar->setEnabled(false);
		ui.NbrIterations->setEnabled(false);
		ui.Restart->setEnabled(true);
		ui.ProgressBar->setValue(0);
		ui.NbrIterations->setText("Iterations :");
	}

	void PTUT::start()
	{
		initValues();//initialisation des parametres
		checkIfReady();//verification des parametres

		
		if (m_bReady)
		{
			disabledEverything();//desactive l'interface inutile
		
			// Creation du réseau
			SOM::Vector vDimNetwork(2);
			vDimNetwork[0] = settings.m_nNbRows;
			vDimNetwork[1] = settings.m_nNbCols;
			network = SOM::Network::GetInstance(settings);

			//calcul du nombre maximum d'iterations
			network->calcNbMaxIterations();

			uint maxIteration = network->getMaxIteration();

			//initialisation de la progressBar
			ui.ProgressBar->setMaximum(maxIteration);

			//debut de l'algorithme
			//updateGraphic();//initialisation de la visualisation

			//boucle a déplacer pour optimiser
			for (uint it = 1; it <= maxIteration; ++it) {
				updateGraphic();
				//network->AlgoSOM(i);
				for (uint i = 0; i < sizeof(network->GetResources().m_fColor) / sizeof(Color); ++i)
				{
					network->AlgoSOM(it, i);
					updateValuesUI(it);
				}
				printf("");
			}
		}

		//réactivation de l'interface
		activateEverything();
	}

	void PTUT::pause()
	{
		//TODO: Implémenter handler de pause dans l'algorithme SOM depuis l'interface
		//changement du texte en fonction de m_bIsPaused
		m_bIsPaused = ! m_bIsPaused;
		if (m_bIsPaused)
		{
			ui.PauseBtn->setText("Reprendre");
			//QWaitCondition w;
			//w.wait(new QMutex(), 5);
		}
		else
			ui.PauseBtn->setText("Pause");
	}
}