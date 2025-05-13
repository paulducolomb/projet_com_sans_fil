#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "MfErrNo.h"
#include "Sw_Device.h"
#include "Sw_ISO14443A-3.h"
#include "Sw_Mf_Classic.h"
#include "Tools.h"
#include "TypeDefs.h"
#include <QDebug>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->image_valide->setVisible(false);
    ui->image_refus->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
ReaderName MonLecteur;
//fonction petit buzzer pour valider à chaque fois
void MainWindow::activerLEDBuzzerValidation() {
    LEDBuzzer(&MonLecteur, BUZZER_ON | LED_RED_ON); //pb de couleur de led dans .h led red et green inversé mais je veux du vert
    usleep(400000);
    LEDBuzzer(&MonLecteur, 0x00);
    ui->image_valide->setVisible(true);
    ui->image_refus->setVisible(false);
    //attente de 3s avant de cacher l'image
    QTimer::singleShot(3000, this, [this]() {
        ui->image_valide->setVisible(false);

    });
}

//fonction de buzzer refus
void MainWindow::activerLEDBuzzerRefus() {
    LEDBuzzer(&MonLecteur, BUZZER_ON | LED_GREEN_ON);
    usleep(100000);
    LEDBuzzer(&MonLecteur, 0x00);

    LEDBuzzer(&MonLecteur, BUZZER_ON | LED_GREEN_ON);
    usleep(100000);
    LEDBuzzer(&MonLecteur, 0x00);
    ui->image_valide->setVisible(false);
    ui->image_refus->setVisible(true);

    //attente de 3s avant de cacher l'image
    QTimer::singleShot(3000, this, [this]() {
        ui->image_refus->setVisible(false);
    });

}


void MainWindow :: on_Connect_clicked()
{
    int16_t status = MI_OK;
    MonLecteur.Type = ReaderCDC;
    MonLecteur.device = 0;

    status = OpenCOM(&MonLecteur);
    qDebug() << "OpenCOM" << status;

    status = Version(&MonLecteur);
    ui->Affichage->setText(MonLecteur.version);
    ui->Affichage->update();

    QString Text = ui->Saisie_Affichage->toPlainText();
    qDebug() << "Text : " <<Text;


    //GetLibraryExtension();
    //OpenCOM();
    //Version();
    //RF_Power_Control();
}
void MainWindow::on_Quitter_clicked()
{
    int16_t status = MI_OK;
    RF_Power_Control(&MonLecteur, FALSE, 0);
    status = LEDBuzzer(&MonLecteur, LED_OFF);
    status = CloseCOM(&MonLecteur);
    qApp->quit();
}


void MainWindow::on_Select_carte_clicked()
{
    uint8_t atq = 0, sak = 0, uid[10] = {0};
    uint16_t uid_len = 0;
    uint8_t dataPrenom[16] = {0}, dataNom[16] = {0};
    uint32_t value13 = 0, value14 = 0;

    // Sélection de la carte
    if (ISO14443_3_A_PollCard(&MonLecteur, &atq, &sak, uid, &uid_len) != MI_OK)
        return;

    activerLEDBuzzerValidation();

    // Lecture prénom (bloc 9)
    if (Mf_Classic_Read_Block(&MonLecteur, TRUE, 9, dataPrenom, AuthKeyA, 2) == MI_OK) {
        QString prenom;
        for (int i = 0; i < 16 && QChar::isPrint(dataPrenom[i]); ++i)
            prenom += QChar(dataPrenom[i]);
        ui->Prenom->setText(prenom);
    }

    // Lecture nom (bloc 10)
    if (Mf_Classic_Read_Block(&MonLecteur, TRUE, 10, dataNom, AuthKeyA, 2) == MI_OK) {
        QString nom;
        for (int i = 0; i < 16 && QChar::isPrint(dataNom[i]); ++i)
            nom += QChar(dataNom[i]);
        ui->Nom->setText(nom);
    }

    // Lecture de la valeur dans le bloc 13
    if (Mf_Classic_Read_Value(&MonLecteur, TRUE, 13, &value13, AuthKeyA, 3) == MI_OK) {
        qDebug() << "Valeur bloc 13 :" << (int)value13;
    } else {
        qDebug() << "Erreur lecture bloc 13";
        activerLEDBuzzerRefus();

    }

    // Lecture de la valeur dans le bloc 14
    if (Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &value14, AuthKeyA, 3) == MI_OK) {
        qDebug() << "Valeur bloc 14 :" << (int)value14;
        //ui->nb_unite->setText(QString::number((int)value14));
    } else {
        qDebug() << "Erreur lecture bloc 14";
        activerLEDBuzzerRefus();
    }

    // Comparaison et affichage
    if (value13 == value14) {
        ui->nb_unite->setText(QString::number((int)value13));
    } else {
        ui->nb_unite->setText("Incohérence");
        activerLEDBuzzerRefus();
    }

}


void MainWindow::on_Maj_clicked()
{
    uint8_t atq = 0, sak = 0, uid[10] = {0};
    uint16_t uid_len = 0;

    // Vérifie que la carte est présente
    if (ISO14443_3_A_PollCard(&MonLecteur, &atq, &sak, uid, &uid_len) != MI_OK)
        return;

    // Récupération du prénom et du nom depuis l'interface
    QString prenomStr = ui->Prenom->text();
    QString nomStr = ui->Nom->text();

    // Conversion des QString en tableau de 16 octets (char array)
    uint8_t dataPrenom[16] = {0};
    uint8_t dataNom[16] = {0};
    QByteArray baPrenom = prenomStr.left(16).toUtf8();
    QByteArray baNom = nomStr.left(16).toUtf8();
    memcpy(dataPrenom, baPrenom.constData(), baPrenom.size());
    memcpy(dataNom, baNom.constData(), baNom.size());

    // Écriture dans le bloc 9 (Prénom)
    Mf_Classic_Write_Block(&MonLecteur, TRUE, 9, dataPrenom, AuthKeyB, 2);

    // Écriture dans le bloc 10 (Nom)
    Mf_Classic_Write_Block(&MonLecteur, TRUE, 10, dataNom, AuthKeyB, 2);


    ui->Saisie_Affichage->setPlainText("Identité mise à jour");
    activerLEDBuzzerValidation();
}



void MainWindow::on_Disconnect_clicked()
{
    activerLEDBuzzerValidation();
    CloseCOM(&MonLecteur);
    ui->Nom->clear();
    ui->Prenom->clear();
    ui->nb_unite->clear();
    ui->nb_unite_spin_dec->clear();
    ui->nb_unite_spin_inc->clear();


}


void MainWindow::on_Payer_clicked()
{
    uint32_t nb_u = 0;
    uint32_t nb_u_dec = ui->nb_unite_spin_dec->value();
    qDebug() << "Valeur demandée dans le QSpinBox :" << nb_u_dec;

    // Lire la valeur actuelle (bloc 14) avec clé A, index 3
    if (Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &nb_u, AuthKeyA, 3) == MI_OK) {
        qDebug() << "Valeur actuelle dans le bloc 14 :" << nb_u;

        if (nb_u >= nb_u_dec) {
            // Décrémenter bloc 14, stocker dans bloc 13 (tampon) avec clé A
            if (Mf_Classic_Decrement_Value(&MonLecteur, TRUE, 14, nb_u_dec, 13, AuthKeyA, 3) == MI_OK) {
                qDebug() << "Décrémentation réussie (bloc 14 -> tampon bloc 13)";

                // Restaurer valeur dans bloc 14 depuis bloc 13 avec clé A
                if (Mf_Classic_Restore_Value(&MonLecteur, TRUE, 13, 14, AuthKeyA, 3) == MI_OK) {
                    qDebug() << "Restauration réussie dans le bloc 14";

                    // Relire la valeur mise à jour
                    uint32_t new_nb = 0;
                    if (Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &new_nb, AuthKeyA, 3) == MI_OK) {
                        ui->nb_unite->setText(QString::number(new_nb));
                        activerLEDBuzzerValidation();
                        QString message = QString("Paiement effectué avec succès de %1 unités, Il vous reste %2 unités ! ").arg(nb_u_dec).arg(new_nb);
                        ui->Saisie_Affichage->setPlainText(message);

                        qDebug() << "Nouvelle valeur dans le bloc 14 :" << new_nb;
                    } else {
                        qDebug() << "Erreur de lecture après restauration.";
                        activerLEDBuzzerRefus();
                    }
                } else {
                    qDebug() << "Échec de la restauration dans le bloc 14.";
                    activerLEDBuzzerRefus();
                }
            } else {
                qDebug() << "Échec de la décrémentation (bloc 14).";
                activerLEDBuzzerRefus();
            }
        } else {
            QString message = QString("Pas assez d’unités (disponible : %1, demandé : %2)")
                                  .arg(nb_u)
                                  .arg(nb_u_dec);

            ui->Saisie_Affichage->setPlainText(message);  // Affiche le message dans le champ texte
            qDebug() << message;
            activerLEDBuzzerRefus();
        }
    } else {
        qDebug() << "Échec de lecture du bloc 14.";
        activerLEDBuzzerRefus();
    }
    ui->nb_unite_spin_dec->clear();
    //on_Select_carte_clicked();


}


void MainWindow::on_Charger_clicked()
{
    uint32_t nb_u_add = ui->nb_unite_spin_inc->value();
    qDebug() << "Nombre de crédit à ajouter :" << nb_u_add;

    uint32_t old_value = 0;
    if (Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &old_value, AuthKeyA, 3) == MI_OK) {
        qDebug() << "Valeur d'unité sur la carte :" << old_value;

        // Incrémenter -> stocker dans le bloc tampon
        if (Mf_Classic_Increment_Value(&MonLecteur, TRUE, 14, nb_u_add, 13, AuthKeyB, 3) == MI_OK) {
            qDebug() << "Incrémentation réussie (bloc 14 -> tampon bloc 13)";

            // Restaurer tampon vers bloc 14
            if (Mf_Classic_Restore_Value(&MonLecteur, TRUE, 13, 14, AuthKeyA, 3) == MI_OK) {
                qDebug() << "Restauration réussie dans le bloc 14";

                // Lire nouvelle valeur
                uint32_t new_value = 0;
                if (Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &new_value, AuthKeyA, 3) == MI_OK) {
                    qDebug() << "Nouvelle valeur dans le bloc 14 :" << new_value;
                    ui->nb_unite->setText(QString::number(new_value));
                    activerLEDBuzzerValidation();
                    QString message = QString("Chargement effectué avec succès de %1 unités. Vous avez désormais %2 unités ! ").arg(nb_u_add).arg(new_value);
                    ui->Saisie_Affichage->setPlainText(message);
                } else {
                    qDebug() << "Erreur de lecture après restauration.";
                    activerLEDBuzzerRefus();

                }
            } else {
                qDebug() << "Échec de la restauration dans le bloc 14.";
                activerLEDBuzzerRefus();
            }
        } else {
            qDebug() << "Échec de l’incrémentation (bloc 14).";
            activerLEDBuzzerRefus();
        }
    } else {
        qDebug() << "Échec de lecture du bloc 14.";
        activerLEDBuzzerRefus();
    }

    //on_Select_carte_clicked();
    ui->nb_unite_spin_inc->clear();

}






//Convertir un QString en Char
    //char DataIn[16];
    //strncpy(DataIn, ui->Affichage_Prenom->toPlainText().toUtf8().data(), 16);
//Convertir un entier en Qstring
    //uint32_t value = 32;
    //ui->Affichage_Nbre_unite->setText(QString::number(value));
