#define CURRENT_VER_TITLE "Algorithme de SOM | Beta 1.1"

#include "PTUT.h"
#include <QtAlgorithms>
#include <qtextcodec.h>
#include <QFileDialog>

namespace SOM {

	PTUT::PTUT(QWidget *parent)
		: QWidget(parent)
	{
		ui.setupUi(this);
		setWindowTitle(QString(CURRENT_VER_TITLE));
	}

	void PTUT::setRows()
	{
		//met la valeur du compteur dans la variable m_nNbRows
		m_settings.m_nNbRows = (uint)ui.LigneValue->value();
		if (m_settings.m_nNbRows > ui.BetaSlider->maximum())
			ui.BetaSlider->setMaximum(m_settings.m_nNbRows);

		if (ui.BetaSlider->value() > std::max(m_settings.m_nNbRows, m_settings.m_nNbCols))
		{
			ui.BetaSlider->setValue(std::max(m_settings.m_nNbRows, m_settings.m_nNbCols));
			ui.BetaValue->setText(QString::number(std::max(m_settings.m_nNbRows, m_settings.m_nNbCols)));
		}
	}

	void PTUT::setColumns()
	{
		//met la valeur du compteur dans la variable m_nNbCols
		m_settings.m_nNbCols = (uint)ui.ColValue->value();
		if (m_settings.m_nNbCols > ui.BetaSlider->maximum())
			ui.BetaSlider->setMaximum(m_settings.m_nNbCols);

		if (ui.BetaSlider->value() > std::max(m_settings.m_nNbRows, m_settings.m_nNbCols))
		{
			ui.BetaSlider->setValue(std::max(m_settings.m_nNbRows, m_settings.m_nNbCols));
			ui.BetaValue->setText(QString::number(std::max(m_settings.m_nNbRows, m_settings.m_nNbCols)));
		}
	}

	void PTUT::updateValuesUI(int currentIteration)
	{
		//alpha
		ui.AlphaSlider->setSliderPosition((int)(m_pNetwork->getAlpha() * 1000.0)); //TODO: Corriger problème interface du slider
		ui.AlphaValue->setText(QString::number(m_pNetwork->getAlpha() + 0.006)); // TODO: slider pour BETA

		//beta
		ui.BetaSlider->setSliderPosition((int)(m_pNetwork->getBeta()));
		ui.BetaValue->setText(QString::number(m_pNetwork->getBeta()));

		ui.ProgressBar->setValue(currentIteration);

		//calcul nombre d'itérations a faire
		ui.NbrIterations->setText("Iterations : " + QString::number(currentIteration) + "/" + QString::number(m_pNetwork->getMaxIteration()));
	}

	void PTUT::updateGraphic()
	{	
		DYN_FREE(m_pScene)
		
		m_pScene = new QGraphicsScene(this);
		
		ui.graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		ui.graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

		QPen outlinePen(Qt::black);
		outlinePen.setWidth(0);

		//dessine chaque neurone du reseau
		uint red, green, blue;
		//Neuron neuron(3);
		for (uint row = 0; row < m_settings.m_nNbRows; row++)
		{
			for (uint col = 0; col < m_settings.m_nNbCols; col++) {
				
				red = m_pNetwork->getNeuron(row, col).GetWeight(0);
				green = m_pNetwork->getNeuron(row, col).GetWeight(1);
				blue = m_pNetwork->getNeuron(row, col).GetWeight(2);

				QBrush brush(QColor(red, green, blue));
				m_pScene->addRect(
						(ui.graphicsView->width() - 5) / m_settings.m_nNbCols*col,
						(ui.graphicsView->height() - 5) / m_settings.m_nNbRows*row,
						ui.graphicsView->width() / m_settings.m_nNbCols,
						ui.graphicsView->height() / m_settings.m_nNbRows,
						outlinePen,
						brush
				);

			}
		}
		ui.graphicsView->setScene(m_pScene);
		ui.ProgressBar->setValue(1);

	}

	void PTUT::drawCurves()
	{
		//Courbe Alpha
		QGraphicsScene* m_pAlphaCurveScene = new QGraphicsScene(this);
		int size = m_pNetwork->getAlphaValues().size();

		QPen outlinePen(Qt::red);
		outlinePen.setWidth(2);
		
		for (int i = 0; i < size-1; i++) {
			m_pAlphaCurveScene->addLine(i * ui.AlphaCurve->width() / size,
										ui.AlphaCurve->height() - (m_pNetwork->getAlphaValues()[i] * ui.AlphaCurve->height() / m_settings.m_dInitialAlpha),
										(i + 1) * ui.AlphaCurve->width() / size,
										ui.AlphaCurve->height() - (m_pNetwork->getAlphaValues()[i + 1] * ui.AlphaCurve->height() / m_settings.m_dInitialAlpha),
										outlinePen);
		}
		
		ui.AlphaCurve->setScene(m_pAlphaCurveScene);

		//Courbe Beta
		QGraphicsScene* m_pBetaCurveScene = new QGraphicsScene(this);

		double beta = m_settings.m_nInitialBeta;
		double beta2 = beta - beta * m_settings.m_dBetaRate;
		for (int i = 0; i < size - 1; i++) {
			
			m_pBetaCurveScene->addLine(i * ui.BetaCurve->width() / size,
				ui.BetaCurve->height() - (beta * (ui.BetaCurve->height()-30) / m_settings.m_nInitialBeta),
				(i + 1) * ui.BetaCurve->width() / size,
				ui.BetaCurve->height() - (beta2 * (ui.BetaCurve->height()-30) / m_settings.m_nInitialBeta),
				outlinePen);

			beta -= beta * m_settings.m_dBetaRate;
			beta2 -= beta2 * m_settings.m_dBetaRate;
		}

		ui.BetaCurve->setScene(m_pBetaCurveScene);
	}

	void PTUT::setAlphaValueText()
	{
		//met la valeur du slider dans la variable m_dAlpha
		ui.AlphaValue->setText(QString::number(ui.AlphaSlider->value() / 1000.0 + 0.006));
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

	void PTUT::setBetaValueText()
	{
		ui.BetaSlider->setMaximum(std::max(ui.LigneValue->value(), ui.ColValue->value()));
		ui.BetaValue->setText(QString::number(ui.BetaSlider->value()));
	}

	void PTUT::initValues() {

		//initialisation des parametres
		m_settings.m_dInitialAlpha = ui.AlphaSlider->value() / 1000.0;
		m_settings.m_dEndAlpha = ui.AlphaEndValue->value();
		m_settings.m_dAlphaRate = ui.TauxAlphaValue->value();
		m_settings.m_nAlphaPeriod = (uint)ui.PeriodeAlphaValue->value();
		m_settings.m_nInitialBeta = ui.BetaSlider->value();
		m_settings.m_dBetaRate = ui.TauxBetaValue->value();
		m_settings.m_nBetaPeriod = (uint)ui.PeriodeBetaValue->value();


		//initialisation des messages d'erreur
		ui.ErreurLignes->setText("");
		ui.ErreurColonnes->setText("");
		ui.NbrIterations->setText("Calculs preparatoires en cours.");
	}

	void PTUT::checkIfReady()
	{
		//verifie que le taux alpha n'est pas egal au taux beta
		if (m_settings.m_dAlphaRate == m_settings.m_dBetaRate)
			m_bReady = false;

		//verifie que le nombre de ligne est correct
		if (m_settings.m_nNbRows == 0)
		{
			ui.ErreurLignes->setText("Veuillez saisir une valeur valide.");
			m_bReady = false;
		}
		//verifie que le nombre de colonnes est correct
		if (m_settings.m_nNbCols == 0)
		{
			ui.ErreurColonnes->setText("Veuillez saisir une valeur valide.");
			m_bReady = false;
		}

		if (m_settings.m_nInitialBeta == 0)
			m_bReady = false;
	}

	void PTUT::disabledEverything()
	{
		//desactive les elements de l'interface
		ui.NouveauRes->setEnabled(false);
		ui.StartBtn->setEnabled(false);
		//ui.PauseBtn->setEnabled(true); //TODO Enable btn when pause handle works
		ui.ProgressBar->setEnabled(true);
		ui.NbrIterations->setEnabled(true);
	}

	void PTUT::openFile()
	{
		//choix du fichier
		QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "%userdata%", tr("SOM Data Files (*.sdt)"));

		//récupération du chemin du fichier
		QFileInfo fileInfo(filename);
		QString dirPath(fileInfo.filePath());

		//stoquage des couleur dans un tableau
		DYN_FREE(m_pResources);
		m_pResources = new Resources(dirPath.toStdString());

		m_bDefaultResource = false;
	}

	#ifndef _SOM_DEBUG

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
		ui.ProgressBar->setValue(0);
		ui.StartBtn->setEnabled(true);
		ui.NbrIterations->setText("");

		delete network;

		//TODO: réinitialiser le reseau (MaxIterations)
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
		}
	}
	#endif

	void PTUT::pause()
	{
		//TODO: Implémenter handler de pause dans l'algorithme SOM depuis l'interface
		//changement du texte en fonction de m_bIsPaused
		m_bIsPaused = ! m_bIsPaused;
		if (m_bIsPaused)
			ui.PauseBtn->setText("Reprendre");
		else
			ui.PauseBtn->setText("Pause apprentissage");
	}
}