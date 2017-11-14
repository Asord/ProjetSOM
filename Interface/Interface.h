#pragma once


#include <QtWidgets/QWidget>
#include "ui_Interface.h"
class Interface : public QWidget
{
	Q_OBJECT

public:
	Interface(QWidget *parent = Q_NULLPTR);

private:
	Ui::Window ui;
	int nbrRows = 0;
	int nbrCols = 0;
	double alpha = 0;
	double alphaRate = 0;
	int alphaEpoch = 0;
	int beta = 0;
	double betaRate = 0;
	int betaEpoch = 0;
	bool Euclidian;
	bool isPaused = false;
	int nbrIterationsMax = 0;
	int currentIteration = 1;


public:
	void updateValues();//actualise la valeur de alpha et beta au cours de l'algo

public slots:
	void setRows();//Actualise le nombre de lignes
	void setColumns();//Actualise le nombre de colonnes
	void setAlphaValueText();//Actualise l'affichage de la valeur de alpha
	void setBeta();//Actualise la valeur de beta
	void setEuclidian();//Actualise Euclidian
	void start();//Lance l'algorythme de SOM
	void pause();//met le programme en pause
	void alphaRateConstraint();//contraint la modification du taux de alpha
	void betaRateConstraint();//contraint la modification du taux de beta
};