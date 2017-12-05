#include "Final.h"
#include <iostream>



Final::Final(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void Final::setRows()
{
	//met la valeur du compteur dans la variable m_nNbRows
	m_nNbRows = ui.LigneValue->value();
	if (m_nNbRows > ui.BetaValue->maximum())
		ui.BetaValue->setMaximum(m_nNbRows);
}

void Final::setColumns()
{
	//met la valeur du compteur dans la variable m_nNbCols
	m_nNbCols = ui.ColValue->value();
	if (m_nNbCols > ui.BetaValue->maximum())
		ui.BetaValue->setMaximum(m_nNbCols);
}

void Final::updateValues()
{
	//alpha
	ui.AlphaSlider->setSliderPosition(m_dAlpha * 1000);
	ui.AlphaValue->setText(QString::number(m_dAlpha + 0.006));

	//beta
	ui.BetaValue->setValue(m_nBeta);
}

void Final::updateGraphic()
{
	m_pScene = new QGraphicsScene(this);
	ui.graphicsView->setScene(m_pScene);
	ui.graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	QPen outlinePen(Qt::black);
	outlinePen.setWidth(0);

	//desinne chaque neurone du reseau
	for (int i = 0; i < m_nNbRows; i++)
		for (int j = 0; j < m_nNbCols; j++) {
			QBrush brush(QColor(rand() % 255, rand() % 255, rand() % 255, 255));//TODO:mettre poids a la place de rand
			m_pRect = m_pScene->addRect((ui.graphicsView->width() - 5) / m_nNbCols*j, (ui.graphicsView->height() - 5) / m_nNbRows*i, ui.graphicsView->width() / m_nNbCols, ui.graphicsView->height() / m_nNbRows, outlinePen, brush);
		}
}

void Final::setAlphaValueText()
{
	//met la valeur du slider dans la variable m_dAlpha
	ui.AlphaValue->setText(QString::number(ui.AlphaSlider->value() / 1000.0 + 0.006));
}

void Final::setEuclidian()
{
	//initialisation de m_bEuclidianen fonction de si la case est cochée ou non
	m_bEuclidian = ui.Distance1->isChecked();
}

void Final::alphaRateConstraint()
{
	//empeche le taux de alpha d'etre supérieur au taux de beta
	if (ui.TauxAlphaValue->value() >= ui.TauxBetaValue->value())
		ui.TauxAlphaValue->setValue(ui.TauxBetaValue->value() - 0.01);
}

void Final::betaRateConstraint()
{
	//empeche le taux de beta d'etre inferieur au taux de alpha
	if (ui.TauxBetaValue->value() <= ui.TauxAlphaValue->value())
		ui.TauxBetaValue->setValue(ui.TauxAlphaValue->value() + 0.01);
}

void Final::initValues() {
	//initialisation des parametres
	m_dAlpha = ui.AlphaSlider->value() / 1000.0;
	m_dAlphaRate = ui.TauxAlphaValue->value();
	m_nAlphaEpoch = ui.PeriodeAlphaValue->value();
	m_nBeta = ui.BetaValue->value();
	m_dBetaRate = ui.TauxBetaValue->value();
	m_nBetaEpoch = ui.PeriodeBetaValue->value();
	m_dInitialAlpha = m_dAlpha;

	//initialisation des messages d'erreur
	ui.ErreurLignes->setText("");
	ui.ErreurColonnes->setText("");
}

void Final::checkIfReady()
{
	//verifie que le taux alpha n'est pas egal au taux beta
	if (m_dAlphaRate == m_dBetaRate)
		m_bReady = false;

	//verifie que le nombre de ligne est correct
	if (m_nNbRows == 0)
	{
		ui.ErreurLignes->setText("Veuillez saisir une valeur valide.");
		m_bReady = false;
	}
	//verifie que le nombre de colonnes est correct
	if (m_nNbCols == 0)
	{
		ui.ErreurColonnes->setText("Veuillez saisir une valeur valide.");
		m_bReady = false;
	}
}

void Final::disabledEverything()
{
	//desactive les elements de l'Final
	ui.NouveauRes->setEnabled(false);
	ui.StartBtn->setEnabled(false);
	ui.PauseBtn->setEnabled(true);
	ui.ProgressBar->setEnabled(true);
	ui.NbrIterations->setEnabled(true);
}

void Final::calcNbMaxIterations()
{
	//calcul nombre d'itérations a faire
	while (m_dAlpha > 0.000000001)
	{
		m_dAlpha = m_dInitialAlpha * exp(-m_nCurrentIteration / m_dAlphaRate);
		m_nNbIterationsMax++;
		m_nCurrentIteration++;
	}
	m_nCurrentIteration = 1;
	m_nNbIterationsMax *= m_nAlphaEpoch;
	ui.NbrIterations->setText("Iterations : " + QString::number(m_nCurrentIteration) + "/" + QString::number(m_nNbIterationsMax));

	//initialisation de la progressBar
	ui.ProgressBar->setMaximum(m_nNbIterationsMax);
}

void Final::start()
{
	initValues();//initialisation des parametres
	updateGraphic();//initialisation de la visualisation
	checkIfReady();//verification des parametres

	if (m_bReady)
	{
		disabledEverything();//desactive l'Final inutile
		calcNbMaxIterations();//calcul du nombre maximum d'iterations

							  //TODO: algo SOM
							  //debut de l'algorithme
		for (m_nCurrentIteration; m_nCurrentIteration <= m_nNbIterationsMax; m_nCurrentIteration++) {

			ui.ProgressBar->setValue(m_nCurrentIteration);
			ui.NbrIterations->setText("Iterations : " + QString::number(m_nCurrentIteration) + "/" + QString::number(m_nNbIterationsMax));

			m_dAlpha = m_dInitialAlpha * exp(-m_nCurrentIteration / m_dAlphaRate);;
			m_nBeta--;
			updateValues();
			_sleep(50);
		}
	}
}

void Final::pause()
{
	//changement du texte en fonction de m_bIsPaused
	m_bIsPaused = m_bIsPaused ? false : true;
	if (m_bIsPaused)
		ui.PauseBtn->setText("Reprendre");
	else
		ui.PauseBtn->setText("Pause apprentissage");
}
