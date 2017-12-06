#pragma once


#include <QtWidgets/QWidget>
#include "ui_Interface.h"
#include "Network.h"
#include "Vector.h"

class Interface : public QWidget
{
	Q_OBJECT

public:
	Interface(QWidget *parent = Q_NULLPTR);

private:
	Ui::Window ui;
	int m_nNbRows = 0;//nombre de lignes du réseau
	int m_nNbCols = 0;//nombre de colonnes du réseau
	double m_dAlpha = 0; //TODO: Recup via SOM
	double m_dInitialAlpha;//valeur initial de alpha
	double m_dAlphaRate = 0;//taux de diminution de alpha
	uint m_nAlphaPeriod = 0;//periode de alpha
	int m_nBeta = 0; //TODO: Recup via SOM
	int m_nInitialBeta;//Valeur initial de beta
	double m_dBetaRate = 0;//taux de diminution de beta
	uint m_nBetaPeriod = 0;//periode de beta
	bool m_bEuclidian; //TODO: Recup via SOM
	bool m_bIsPaused = false;//programme en pause ?
	int m_nNbIterationsMax = 0; //TODO: Recup via SOM (calculé par Arthur)
	int m_nCurrentIteration = 1;//TODO: Recup via SOM
	bool m_bReady = true;//tous les parametre sont correcte?
	uint m_nDimInputVector = 3;
	SOM::Network* network;

	//visualisation
	QGraphicsScene *m_pScene;//Scene du QGraphicView
	QGraphicsRectItem *m_pRect;//un rectangle du QGraphicView

public:
	//initialise les variables avec les valeurs des parametres
	void initValues();
	//verifie que toutes les parametres sont correctes
	void checkIfReady();
	//calcul le nombre maximum d'iterations
	void calcNbMaxIterations();
	//actualise la valeur de alpha et beta au cours de l'algo
	void updateValues();
	//desactive tout l'interface inutile lorsque l'apprentissageest lancé
	void disabledEverything();
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
};