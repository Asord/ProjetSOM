#pragma once

// Défini l'instance débug
#define _SOM_DEBUG

// Include spécifique par IDE (VS17 | CLion2017)
#if defined (_MSC_VER)
#include "ui_PTUT.h"
#elif defined (__MINGW32__)or(__MINGW64__)
#include "cmake-build-debug/PTUT_autogen/include/ui_PTUT.h"
#endif


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

	private:
		Ui::Window ui;

		bool m_bIsPaused = false; // programme en pause ?
		bool m_bReady = true; // tous les parametres sont correcte?
		bool m_bDefaultResource = true;

		Network* m_pNetwork = nullptr;
		Resources<Color>* m_pResources = nullptr;

		Settings m_settings;

		//visualisation
		QGraphicsScene *m_pScene = Q_NULLPTR;//Scene du QGraphicView

	public:
		//initialise les variables avec les valeurs des parametres
		void initValues();
		//verifie que toutes les parametres sont correctes
		void checkIfReady();
		//actualise la valeur de alpha et beta au cours de l'algo
		void updateValuesUI(int currentIteration);
		//desactive tout l'interface inutile lorsque l'apprentissageest lancé
		void disabledEverything();
		//initialisation de la visualisation
		void updateGraphic();

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

		#ifdef _SOM_DEBUG  // TODO: Mettre les methodes debug ici et définir dans PTUT_DBG.cpp

	private:
		std::chrono::time_point < std::chrono::system_clock > begin, end;
		QGraphicsScene *m_pEntryScene; // Scene d'entrée
	public:
		void drawInput();

		#endif
	};
}