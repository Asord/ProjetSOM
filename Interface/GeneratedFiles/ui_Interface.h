/********************************************************************************
** Form generated from reading UI file 'Interfacev0.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEV0_H
#define UI_INTERFACEV0_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QGroupBox *Interface;
    QPushButton *NouveauRes;
    QGroupBox *ExecutionGrp;
    QProgressBar *ProgressBar;
    QPushButton *StartBtn;
    QPushButton *PauseBtn;
    QLabel *NbrIterations;
    QLabel *Titre1;
    QLabel *Lignes;
    QLabel *Colonnes;
    QFrame *Line1;
    QSpinBox *ColValue;
    QLabel *ErreurLignes;
    QSpinBox *LigneValue;
    QLabel *ErreurColonnes;
    QLabel *ErreurBeta;
    QGroupBox *Parametres;
    QLabel *Titre2;
    QSlider *AlphaSlider;
    QRadioButton *Distance1;
    QSpinBox *BetaValue;
    QFrame *Line2;
    QLabel *AlphaValue;
    QLabel *Alpha;
    QLabel *Beta;
    QLabel *TauxAlpha;
    QLabel *PeriodeAlpha;
    QDoubleSpinBox *TauxAlphaValue;
    QSpinBox *PeriodeAlphaValue;
    QLabel *TauxBeta;
    QDoubleSpinBox *TauxBetaValue;
    QSpinBox *PeriodeBetaValue;
    QLabel *PeriodeBeta;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(802, 591);
        Interface = new QGroupBox(Window);
        Interface->setObjectName(QStringLiteral("Interface"));
        Interface->setGeometry(QRect(-10, -20, 300, 620));
        NouveauRes = new QPushButton(Interface);
        NouveauRes->setObjectName(QStringLiteral("NouveauRes"));
        NouveauRes->setGeometry(QRect(85, 50, 130, 37));
        NouveauRes->setStyleSheet(QStringLiteral(""));
        ExecutionGrp = new QGroupBox(Interface);
        ExecutionGrp->setObjectName(QStringLiteral("ExecutionGrp"));
        ExecutionGrp->setGeometry(QRect(10, 490, 291, 131));
        ProgressBar = new QProgressBar(ExecutionGrp);
        ProgressBar->setObjectName(QStringLiteral("ProgressBar"));
        ProgressBar->setEnabled(false);
        ProgressBar->setGeometry(QRect(10, 50, 285, 23));
        ProgressBar->setValue(0);
        ProgressBar->setTextVisible(true);
        StartBtn = new QPushButton(ExecutionGrp);
        StartBtn->setObjectName(QStringLiteral("StartBtn"));
        StartBtn->setEnabled(false);
        StartBtn->setGeometry(QRect(10, 10, 121, 31));
        PauseBtn = new QPushButton(ExecutionGrp);
        PauseBtn->setObjectName(QStringLiteral("PauseBtn"));
        PauseBtn->setEnabled(false);
        PauseBtn->setGeometry(QRect(140, 10, 121, 31));
        NbrIterations = new QLabel(ExecutionGrp);
        NbrIterations->setObjectName(QStringLiteral("NbrIterations"));
        NbrIterations->setEnabled(false);
        NbrIterations->setGeometry(QRect(20, 90, 171, 21));
        Titre1 = new QLabel(Interface);
        Titre1->setObjectName(QStringLiteral("Titre1"));
        Titre1->setEnabled(false);
        Titre1->setGeometry(QRect(100, 120, 91, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Titre1->setFont(font);
        Titre1->setTextFormat(Qt::AutoText);
        Titre1->setWordWrap(false);
        Lignes = new QLabel(Interface);
        Lignes->setObjectName(QStringLiteral("Lignes"));
        Lignes->setEnabled(false);
        Lignes->setGeometry(QRect(20, 150, 51, 21));
        Colonnes = new QLabel(Interface);
        Colonnes->setObjectName(QStringLiteral("Colonnes"));
        Colonnes->setEnabled(false);
        Colonnes->setGeometry(QRect(20, 180, 51, 21));
        Line1 = new QFrame(Interface);
        Line1->setObjectName(QStringLiteral("Line1"));
        Line1->setEnabled(false);
        Line1->setGeometry(QRect(20, 130, 271, 16));
        Line1->setFrameShape(QFrame::HLine);
        Line1->setFrameShadow(QFrame::Sunken);
        ColValue = new QSpinBox(Interface);
        ColValue->setObjectName(QStringLiteral("ColValue"));
        ColValue->setEnabled(false);
        ColValue->setGeometry(QRect(80, 180, 42, 22));
        ErreurLignes = new QLabel(Interface);
        ErreurLignes->setObjectName(QStringLiteral("ErreurLignes"));
        ErreurLignes->setEnabled(true);
        ErreurLignes->setGeometry(QRect(140, 150, 151, 21));
        ErreurLignes->setStyleSheet(QStringLiteral(""));
        LigneValue = new QSpinBox(Interface);
        LigneValue->setObjectName(QStringLiteral("LigneValue"));
        LigneValue->setEnabled(false);
        LigneValue->setGeometry(QRect(80, 150, 42, 22));
        LigneValue->setValue(0);
        ErreurColonnes = new QLabel(Interface);
        ErreurColonnes->setObjectName(QStringLiteral("ErreurColonnes"));
        ErreurColonnes->setEnabled(true);
        ErreurColonnes->setGeometry(QRect(140, 180, 151, 21));
        ErreurColonnes->setStyleSheet(QStringLiteral(""));
        ErreurBeta = new QLabel(Interface);
        ErreurBeta->setObjectName(QStringLiteral("ErreurBeta"));
        ErreurBeta->setEnabled(true);
        ErreurBeta->setGeometry(QRect(130, 300, 151, 21));
        ErreurBeta->setStyleSheet(QStringLiteral(""));
        Parametres = new QGroupBox(Interface);
        Parametres->setObjectName(QStringLiteral("Parametres"));
        Parametres->setGeometry(QRect(10, 210, 291, 281));
        Titre2 = new QLabel(Parametres);
        Titre2->setObjectName(QStringLiteral("Titre2"));
        Titre2->setEnabled(false);
        Titre2->setGeometry(QRect(80, 10, 131, 16));
        Titre2->setFont(font);
        AlphaSlider = new QSlider(Parametres);
        AlphaSlider->setObjectName(QStringLiteral("AlphaSlider"));
        AlphaSlider->setEnabled(false);
        AlphaSlider->setGeometry(QRect(60, 50, 181, 22));
        AlphaSlider->setMaximum(1000);
        AlphaSlider->setSliderPosition(0);
        AlphaSlider->setOrientation(Qt::Horizontal);
        Distance1 = new QRadioButton(Parametres);
        Distance1->setObjectName(QStringLiteral("Distance1"));
        Distance1->setEnabled(false);
        Distance1->setGeometry(QRect(10, 247, 121, 17));
        Distance1->setTabletTracking(false);
        Distance1->setCheckable(true);
        Distance1->setChecked(true);
        BetaValue = new QSpinBox(Parametres);
        BetaValue->setObjectName(QStringLiteral("BetaValue"));
        BetaValue->setEnabled(false);
        BetaValue->setGeometry(QRect(60, 120, 51, 22));
        BetaValue->setMaximum(0);
        Line2 = new QFrame(Parametres);
        Line2->setObjectName(QStringLiteral("Line2"));
        Line2->setEnabled(false);
        Line2->setGeometry(QRect(10, 20, 271, 16));
        Line2->setFrameShape(QFrame::HLine);
        Line2->setFrameShadow(QFrame::Sunken);
        AlphaValue = new QLabel(Parametres);
        AlphaValue->setObjectName(QStringLiteral("AlphaValue"));
        AlphaValue->setEnabled(false);
        AlphaValue->setGeometry(QRect(230, 50, 61, 16));
        AlphaValue->setAlignment(Qt::AlignCenter);
        Alpha = new QLabel(Parametres);
        Alpha->setObjectName(QStringLiteral("Alpha"));
        Alpha->setEnabled(false);
        Alpha->setGeometry(QRect(10, 50, 47, 21));
        Beta = new QLabel(Parametres);
        Beta->setObjectName(QStringLiteral("Beta"));
        Beta->setEnabled(false);
        Beta->setGeometry(QRect(10, 120, 47, 21));
        TauxAlpha = new QLabel(Parametres);
        TauxAlpha->setObjectName(QStringLiteral("TauxAlpha"));
        TauxAlpha->setEnabled(false);
        TauxAlpha->setGeometry(QRect(10, 81, 71, 21));
        PeriodeAlpha = new QLabel(Parametres);
        PeriodeAlpha->setObjectName(QStringLiteral("PeriodeAlpha"));
        PeriodeAlpha->setEnabled(false);
        PeriodeAlpha->setGeometry(QRect(160, 80, 81, 21));
        TauxAlphaValue = new QDoubleSpinBox(Parametres);
        TauxAlphaValue->setObjectName(QStringLiteral("TauxAlphaValue"));
        TauxAlphaValue->setEnabled(false);
        TauxAlphaValue->setGeometry(QRect(80, 81, 62, 22));
        TauxAlphaValue->setMaximum(1);
        TauxAlphaValue->setSingleStep(0.01);
        PeriodeAlphaValue = new QSpinBox(Parametres);
        PeriodeAlphaValue->setObjectName(QStringLiteral("PeriodeAlphaValue"));
        PeriodeAlphaValue->setEnabled(false);
        PeriodeAlphaValue->setGeometry(QRect(240, 80, 42, 22));
        PeriodeAlphaValue->setMinimum(1);
        PeriodeAlphaValue->setMaximum(5);
        TauxBeta = new QLabel(Parametres);
        TauxBeta->setObjectName(QStringLiteral("TauxBeta"));
        TauxBeta->setEnabled(false);
        TauxBeta->setGeometry(QRect(10, 150, 71, 21));
        TauxBetaValue = new QDoubleSpinBox(Parametres);
        TauxBetaValue->setObjectName(QStringLiteral("TauxBetaValue"));
        TauxBetaValue->setEnabled(false);
        TauxBetaValue->setGeometry(QRect(80, 150, 62, 22));
        TauxBetaValue->setMaximum(1);
        TauxBetaValue->setSingleStep(0.01);
        PeriodeBetaValue = new QSpinBox(Parametres);
        PeriodeBetaValue->setObjectName(QStringLiteral("PeriodeBetaValue"));
        PeriodeBetaValue->setEnabled(false);
        PeriodeBetaValue->setGeometry(QRect(240, 150, 42, 22));
        PeriodeBetaValue->setMinimum(1);
        PeriodeBetaValue->setMaximum(5);
        PeriodeBeta = new QLabel(Parametres);
        PeriodeBeta->setObjectName(QStringLiteral("PeriodeBeta"));
        PeriodeBeta->setEnabled(false);
        PeriodeBeta->setGeometry(QRect(160, 150, 81, 21));

        retranslateUi(Window);
        QObject::connect(LigneValue, SIGNAL(valueChanged(int)), Window, SLOT(setRows()));
        QObject::connect(ColValue, SIGNAL(valueChanged(int)), Window, SLOT(setColumns()));
        QObject::connect(BetaValue, SIGNAL(valueChanged(int)), Window, SLOT(setBeta()));
        QObject::connect(Distance1, SIGNAL(clicked(bool)), Window, SLOT(setEuclidian()));
        QObject::connect(StartBtn, SIGNAL(clicked()), Window, SLOT(start()));
        QObject::connect(PauseBtn, SIGNAL(clicked()), Window, SLOT(pause()));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), Titre1, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), Line1, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), Lignes, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), LigneValue, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), Colonnes, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), ColValue, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), Titre2, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), Alpha, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), Beta, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), BetaValue, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), Distance1, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), StartBtn, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), AlphaValue, SLOT(setDisabled(bool)));
        QObject::connect(AlphaSlider, SIGNAL(sliderMoved(int)), Window, SLOT(setAlphaValueText()));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), TauxAlpha, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), TauxAlphaValue, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), PeriodeAlpha, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), PeriodeAlphaValue, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), TauxBeta, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), TauxBetaValue, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), PeriodeBeta, SLOT(setDisabled(bool)));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), PeriodeBetaValue, SLOT(setDisabled(bool)));
        QObject::connect(TauxAlphaValue, SIGNAL(valueChanged(double)), Window, SLOT(alphaRateConstraint()));
        QObject::connect(TauxBetaValue, SIGNAL(valueChanged(double)), Window, SLOT(betaRateConstraint()));
        QObject::connect(NouveauRes, SIGNAL(clicked(bool)), AlphaSlider, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Algorithme de SOM", Q_NULLPTR));
        Interface->setTitle(QApplication::translate("Window", "GroupBox", Q_NULLPTR));
        NouveauRes->setText(QApplication::translate("Window", "Nouveau r\303\251seau", Q_NULLPTR));
        ExecutionGrp->setTitle(QString());
        StartBtn->setText(QApplication::translate("Window", "Lancer apprentissage", Q_NULLPTR));
        PauseBtn->setText(QApplication::translate("Window", "Pause apprentissage", Q_NULLPTR));
        NbrIterations->setText(QApplication::translate("Window", "It\303\251rations : ", Q_NULLPTR));
        Titre1->setText(QApplication::translate("Window", "Taille du r\303\251seau", Q_NULLPTR));
        Lignes->setText(QApplication::translate("Window", "Lignes :", Q_NULLPTR));
        Colonnes->setText(QApplication::translate("Window", "Colonnes :", Q_NULLPTR));
        ErreurLignes->setText(QString());
        ErreurColonnes->setText(QString());
        ErreurBeta->setText(QString());
        Parametres->setTitle(QString());
        Titre2->setText(QApplication::translate("Window", "Param\303\250tres du r\303\251seau", Q_NULLPTR));
        Distance1->setText(QApplication::translate("Window", "Distance Euclidienne", Q_NULLPTR));
        AlphaValue->setText(QApplication::translate("Window", "0", Q_NULLPTR));
        Alpha->setText(QApplication::translate("Window", "Alpha :", Q_NULLPTR));
        Beta->setText(QApplication::translate("Window", "Beta :", Q_NULLPTR));
        TauxAlpha->setText(QApplication::translate("Window", "Taux alpha :", Q_NULLPTR));
        PeriodeAlpha->setText(QApplication::translate("Window", "Periode alpha :", Q_NULLPTR));
        TauxBeta->setText(QApplication::translate("Window", "Taux beta :", Q_NULLPTR));
        PeriodeBeta->setText(QApplication::translate("Window", "Periode beta :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEV0_H
