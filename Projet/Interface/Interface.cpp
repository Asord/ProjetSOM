#include "Interface.h"
#include <iostream>



Interface::Interface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void Interface::setRows()
{
	//mettre le valeur du compteur dans la variable
	nbrRows = ui.LigneValue->value();
	if (nbrRows > ui.BetaValue->maximum())
		ui.BetaValue->setMaximum(nbrRows);
}

void Interface::updateValues()
{
	//alpha
	ui.AlphaSlider->setSliderPosition(alpha*1000);
	ui.AlphaValue->setText(QString::number(alpha + 0.006));

	//beta
	ui.BetaValue->setValue(beta);
}

void Interface::setColumns()
{
	//mettre le valeur du compteur dans la variable
	nbrCols = ui.ColValue->value();
	if (nbrCols > ui.BetaValue->maximum())
		ui.BetaValue->setMaximum(nbrCols);
}

void Interface::setAlphaValueText()
{
	//mettre le valeur du compteur dans la variable
	ui.AlphaValue->setText(QString::number(ui.AlphaSlider->value()/1000.0 + 0.006));
}

void Interface::setBeta()
{
	//mettre le valeur du compteur dans la variable
	
}

void Interface::setEuclidian()
{
	Euclidian = ui.Distance1->isChecked();
}

void Interface::alphaRateConstraint()
{
	if (ui.TauxAlphaValue->value() >= ui.TauxBetaValue->value())
		ui.TauxAlphaValue->setValue(ui.TauxBetaValue->value() - 0.01);
}

void Interface::betaRateConstraint()
{
	if (ui.TauxBetaValue->value() <= ui.TauxAlphaValue->value())
		ui.TauxBetaValue->setValue(ui.TauxAlphaValue->value() + 0.01);
}

void Interface::start()
{

	bool ready = true;//check si tout les parametres sont corrects

	//initialisation des parametres
	alpha = ui.AlphaSlider->value() / 1000.0;
	alphaRate = ui.TauxAlphaValue->value();
	alphaEpoch = ui.PeriodeAlphaValue->value();
	beta = ui.BetaValue->value();
	betaRate = ui.TauxBetaValue->value();
	betaEpoch = ui.PeriodeBetaValue->value();

	if (alphaRate == betaRate)
		ready = false;

	//initialisation des messages d'erreur
	ui.ErreurLignes->setText("");
	ui.ErreurColonnes->setText("");

	//check si le nombre de ligne est correct
	if (nbrRows == 0)
	{
		ui.ErreurLignes->setText("Veuillez saisir une valeur valide.");
		ready = false;
	}
	//check si le nombre de colonnes est correct
	if (nbrCols == 0)
	{
		ui.ErreurColonnes->setText("Veuillez saisir une valeur valide.");
		ready = false;
	}

	//debut de l'algorithme
	if (ready)
	{
		ui.NouveauRes->setEnabled(false);
		ui.StartBtn->setEnabled(false);
		ui.PauseBtn->setEnabled(true);
		ui.ProgressBar->setEnabled(true);
		ui.NbrIterations->setEnabled(true);
		
		//calcul nombre d'itérations
		double alphaStart = alpha;
		while (alpha > 0.000000001)
		{
			alpha = alphaStart * exp(-currentIteration/alphaRate);
			nbrIterationsMax++;
			currentIteration++;
		}
		currentIteration = 1;
		nbrIterationsMax *= alphaEpoch;
		ui.NbrIterations->setText("Iterations : " + QString::number(currentIteration) + "/" + QString::number(nbrIterationsMax));
		
		//initialisation progressBar
		ui.ProgressBar->setMaximum(nbrIterationsMax);

		//TODO: algo SOM
		for (currentIteration; currentIteration <= nbrIterationsMax; currentIteration++) {
			
			ui.ProgressBar->setValue(currentIteration);
			ui.NbrIterations->setText("Iterations : " + QString::number(currentIteration) + "/" + QString::number(nbrIterationsMax));

			alpha = alphaStart * exp(-currentIteration / alphaRate);;
			beta--;
			updateValues();
			//_sleep(50);
		}
	}
}

void Interface::pause()
{
	isPaused = isPaused ? false : true;
	if (isPaused)
		ui.PauseBtn->setText("Reprendre");
	else
		ui.PauseBtn->setText("Pause apprentissage");
}
