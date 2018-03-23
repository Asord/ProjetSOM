#pragma once

// Défini l'instance débug
#define _SOM_DEBUG

#include "ui_PTUT.h"

#include <QtWidgets/QWidget>
#include "Network.h"
#include "Vector.h"
#include "Settings.h"
#include <iostream>

#include <chrono>

namespace SOM {
	class PTUT : public QWidget
	{
		Q_OBJECT

	public:
		PTUT(QWidget *parent = Q_NULLPTR);
		PTUT(QApplication* master);

	private:
		Ui::Window ui;

		QApplication* masterPtr;

		bool m_bIsPaused = false; // programme en pause ?

		Network* m_pNetwork = nullptr;
		Resources* m_pResources = nullptr;

		Settings m_settings;

		//visualisation
		QGraphicsScene *m_pScene = Q_NULLPTR;//Scene du QGraphicView

	public:
		//initialise les variables avec les valeurs des parametres
		void initValues();
		//verifie que toutes les parametres sont correctes
		bool checkIfReady();
		//actualise la valeur de alpha et beta au cours de l'algo
		void updateValuesUI(const int& currentIteration);
		//desactive tout l'interface inutile lorsque l'apprentissageest lancé
		void disabledEverything();
		//initialisation de la visualisation
		void updateGraphic();
		//Dessin des courbes de alpha
		void drawCurves();

	public slots:
		void setRows();//Actualise le nombre de lignes
		void setColumns();//Actualise le nombre de colonnes
		void setAlphaValueText();//Actualise l'affichage de la valeur de alpha
		void start();//Lance l'algorythme de SOM
		void pause();//met le programme en pause
		void alphaRateConstraint();//contraint la modification du taux de alpha
		void betaRateConstraint();//contraint la modification du taux de beta
		void setBetaValueText();
		void restart();
		void openFile();
	};
}