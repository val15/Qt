/*
 Auteur : val15
 Date De Creation : 02/09/14

Role :
represente une evenement

 */


#ifndef RDV_H
#define RDV_H
#include <QtWidgets>
#include <QtGui>
#include <QtSql>
#include "clienttcpsocket.h"

class Rdv: public QWidget
{
    Q_OBJECT
public :
    Rdv(QString date,QString time,QString evenement,int id,ClientTcpSocket *clientTcp,QWidget *parent,QString dateDuJour);//si date est vide,alos le rdv est creer depuis la fenetre de gestion, si non elle est créer depuis lafenetre principal: dans ce cas, il faut reafficher les evement du jour

protected:


private:
    QWidget *m_parent;
    ClientTcpSocket *m_clientTcp;
    QString m_dateDuJour;
    QString m_evenement;
    QString m_sDate;
    QString m_sTime;
    int m_id;

    QGridLayout *m_layoutGenerale;
   QGridLayout *m_layoutHaut;
   QGridLayout *m_layoutBas;
   QDateEdit *m_deDate;
   QTimeEdit *m_tieTime;
   QLineEdit *m_leDate;
   QLineEdit *m_leEvenement;
   QPushButton *m_btModifier;
   QPushButton *m_btSupprimer;


    QGroupBox *m_GRPBox;

    void envoyerRequeteSupprimerEtRelecture();//il faut ce subilitE affint d'actualiser l'affichage apre la suppression
    void envoyerRequeteEnregisterEtRelecture();
    void envoyerRequeteSupprimerEtRelectureEvenementDuJour();//il faut ce subilitE affint d'actualiser l'affichage apre la suppression
    void envoyerRequeteEnregisterEtRelectureEvenementDuJour();

private slots:
    void envoyerRequeteSupprimer();
    void envoyerRequeteEnregister();
signals:
   // void emmetreLireDatesImportantsDuMois();
    void emmetreModif();



};

#endif //EVENEMENT_H
