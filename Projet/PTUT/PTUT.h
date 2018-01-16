#pragma once

#include <QtWidgets/QWidget>
#include "ui_PTUT.h"
#include "Network.h"
#include "Vector.h"
#include "Settings.h"
#include "Resources.h"

namespace SOM {
	class PTUT : public QWidget
	{
		Q_OBJECT

	public:
		PTUT(QWidget *parent = Q_NULLPTR);

	private:
		Ui::Window ui;

        bool m_bEuclidian; //TODO: bool Euclidian a modifier quand avancement calcule distance
		//TODO: remove
		bool m_bIsPaused;//programme en pause ?
		bool m_bReady;//tous les parametre sont correcte?
		Network* network;
		Settings settings;
		Resources resource;

		//visualisation
		QGraphicsScene *m_pScene;//Scene du QGraphicView

	public:
		//initialise les variables avec les valeurs des parametres
		void initValues();
		//verifie que toutes les parametres sont correctes
		void checkIfReady();
		//actualise la valeur de alpha et beta au cours de l'algo
		void updateValuesUI(int currentIteration);
		//desactive tout l'interface inutile lorsque l'apprentissageest lancé
		void disabledEverything();
		//réactive tout l'interface à la fin de l'aprentissage
		void activateEverything();
		//initialisation de la visualisation
		void updateGraphic();

	public slots:
		void setRows();//Actualise le nombre de lignes
		void setColumns();//Actualise le nombre de colonnes
		void setAlphaValueText();//Actualise l'affichage de la valeur de alpha
		void setEuclidian();//Actualise Euclidian
		void start();//Lance l'algorythme de SOM
		void pause();//met le programme en pause
		void alphaRateConstraint();//contraint la modification du taux de alpha
		void betaRateConstraint();//contraint la modification du taux de beta
		void setBeta();
		void restart();//réinitialise tout
		void openFile();//selection de fichier
	};
}