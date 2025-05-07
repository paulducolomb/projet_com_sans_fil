/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Connect;
    QPushButton *Quitter;
    QGroupBox *groupBox;
    QLineEdit *Nom;
    QLineEdit *Prenom;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Maj;
    QGroupBox *groupBox_2;
    QPushButton *Payer;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *nb_unite_spin_dec;
    QLineEdit *nb_unite;
    QGroupBox *groupBox_3;
    QPushButton *Charger;
    QSpinBox *nb_unite_spin_inc;
    QLabel *label_5;
    QPushButton *Disconnect;
    QPushButton *Select_carte;
    QGroupBox *groupBox_4;
    QTextEdit *Saisie_Affichage;
    QTextEdit *Affichage;
    QLabel *image_refus;
    QLabel *image_valide;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(824, 618);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Connect = new QPushButton(centralwidget);
        Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->setGeometry(QRect(30, 400, 91, 29));
        Quitter = new QPushButton(centralwidget);
        Quitter->setObjectName(QString::fromUtf8("Quitter"));
        Quitter->setGeometry(QRect(660, 490, 83, 29));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(320, 50, 421, 131));
        Nom = new QLineEdit(groupBox);
        Nom->setObjectName(QString::fromUtf8("Nom"));
        Nom->setGeometry(QRect(130, 40, 113, 28));
        Prenom = new QLineEdit(groupBox);
        Prenom->setObjectName(QString::fromUtf8("Prenom"));
        Prenom->setGeometry(QRect(130, 90, 113, 28));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 63, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 90, 63, 20));
        Maj = new QPushButton(groupBox);
        Maj->setObjectName(QString::fromUtf8("Maj"));
        Maj->setGeometry(QRect(290, 60, 91, 29));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(320, 200, 421, 121));
        Payer = new QPushButton(groupBox_2);
        Payer->setObjectName(QString::fromUtf8("Payer"));
        Payer->setGeometry(QRect(310, 60, 91, 29));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 40, 131, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 80, 221, 20));
        nb_unite_spin_dec = new QSpinBox(groupBox_2);
        nb_unite_spin_dec->setObjectName(QString::fromUtf8("nb_unite_spin_dec"));
        nb_unite_spin_dec->setGeometry(QRect(240, 80, 44, 29));
        nb_unite = new QLineEdit(groupBox_2);
        nb_unite->setObjectName(QString::fromUtf8("nb_unite"));
        nb_unite->setGeometry(QRect(220, 40, 61, 28));
        nb_unite->setReadOnly(true);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(320, 350, 421, 101));
        Charger = new QPushButton(groupBox_3);
        Charger->setObjectName(QString::fromUtf8("Charger"));
        Charger->setGeometry(QRect(310, 50, 91, 29));
        nb_unite_spin_inc = new QSpinBox(groupBox_3);
        nb_unite_spin_inc->setObjectName(QString::fromUtf8("nb_unite_spin_inc"));
        nb_unite_spin_inc->setGeometry(QRect(240, 50, 44, 29));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 50, 221, 20));
        Disconnect = new QPushButton(centralwidget);
        Disconnect->setObjectName(QString::fromUtf8("Disconnect"));
        Disconnect->setGeometry(QRect(142, 400, 91, 29));
        Select_carte = new QPushButton(centralwidget);
        Select_carte->setObjectName(QString::fromUtf8("Select_carte"));
        Select_carte->setGeometry(QRect(30, 440, 201, 29));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 50, 281, 131));
        Saisie_Affichage = new QTextEdit(groupBox_4);
        Saisie_Affichage->setObjectName(QString::fromUtf8("Saisie_Affichage"));
        Saisie_Affichage->setGeometry(QRect(10, 40, 241, 71));
        Affichage = new QTextEdit(centralwidget);
        Affichage->setObjectName(QString::fromUtf8("Affichage"));
        Affichage->setGeometry(QRect(30, 480, 201, 31));
        image_refus = new QLabel(centralwidget);
        image_refus->setObjectName(QString::fromUtf8("image_refus"));
        image_refus->setGeometry(QRect(90, 210, 121, 121));
        image_refus->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/false.png")));
        image_refus->setScaledContents(true);
        image_valide = new QLabel(centralwidget);
        image_valide->setObjectName(QString::fromUtf8("image_valide"));
        image_valide->setGeometry(QRect(60, 210, 161, 121));
        image_valide->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/valide.png")));
        image_valide->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        groupBox_3->raise();
        groupBox_2->raise();
        groupBox->raise();
        Connect->raise();
        Quitter->raise();
        Disconnect->raise();
        Select_carte->raise();
        groupBox_4->raise();
        Affichage->raise();
        image_refus->raise();
        image_valide->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 824, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        Quitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Identit\303\251", nullptr));
        Nom->setText(QString());
        Prenom->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        Maj->setText(QCoreApplication::translate("MainWindow", "Mise \303\240 jour", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "D\303\251cr\303\251menter le porte monnaie", nullptr));
        Payer->setText(QCoreApplication::translate("MainWindow", "Payer", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nombre d'unit\303\251s", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Nombre d'unit\303\251s \303\240 d\303\251cr\303\251menter", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Incr\303\251menter le porte monnaie", nullptr));
        Charger->setText(QCoreApplication::translate("MainWindow", "Charger", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nombre d'unit\303\251s \303\240 incr\303\251menter", nullptr));
        Disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        Select_carte->setText(QCoreApplication::translate("MainWindow", "S\303\251lectionner la carte ", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Debug", nullptr));
        image_refus->setText(QString());
        image_valide->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
