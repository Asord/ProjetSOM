#pragma once

#include <QtWidgets/QWidget>
//#include "cmake-build-debug/PTUT_autogen/include/ui_PTUT.h"
#include "ui_PTUT.h"
#include "Network.h"
#include "Vector.h"
#include "Settings.h"

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
		bool m_bIsPaused = false;//programme en pause ?
		bool m_bReady = true;//tous les parametre sont correcte?
		Network* network;
		Settings settings;

		//visualisation
		QGraphicsScene *m_pScene = Q_NULLPTR;//Scene du QGraphicView
		QGraphicsScene *m_pEntryScene; // Scene d'entrée

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
		void setEuclidian();//Actualise Euclidian
		void start();//Lance l'algorythme de SOM
		void pause();//met le programme en pause
		void alphaRateConstraint();//contraint la modification du taux de alpha
		void betaRateConstraint();//contraint la modification du taux de beta
		void setBeta();

        // TODO: Remove after debug
		void drawInput()
		{
			m_pEntryScene = new QGraphicsScene(this);
			ui.graphicsPreview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
			ui.graphicsPreview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

			QPen outlinePen(Qt::black);
			outlinePen.setWidth(0);

			for (uint i = 0;  i < network->m_resources.m_nHeight * network->m_resources.m_nWidth; ++i)
			{
                uint col = i % network->m_resources.m_nWidth;
                uint row = i / network->m_resources.m_nWidth;

				Color color = network->m_resources.m_fColor[i];
				uchar red = color[0];
				uchar gre = color[1];
				uchar blu = color[2];

				QBrush brush(QColor(red, gre, blu));
				m_pEntryScene->addRect(
                        (ui.graphicsPreview->width() - 5) / network->m_resources.m_nWidth*col,
                        (ui.graphicsPreview->height() - 5) / network->m_resources.m_nHeight*row,
                        ui.graphicsPreview->width() / 10,
                        ui.graphicsPreview->height() / 10,
                        outlinePen,
                        brush
                );
			}
			ui.graphicsPreview->setScene(m_pEntryScene);
			ui.graphicsPreview->update();

		}
	};
}