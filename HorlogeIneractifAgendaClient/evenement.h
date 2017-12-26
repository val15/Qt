/*
 Auteur : val15
 Date De Creation : 02/09/14

Role :
represente une evenement

 */


#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QtWidgets>
#include <QtSql>
#include "clienttcpsocket.h"

class Evenement: public QWidget
{
    Q_OBJECT
public :
    Evenement(QString date,QString evenement,int id,ClientTcpSocket *clientTcp,QWidget *parent);

protected:


private:
    QWidget *m_parent;
    ClientTcpSocket *m_clientTcp;
    QString m_evenement;
    QString m_sDate;
    int m_id;

    QGridLayout *m_layoutGenerale;
   QGridLayout *m_layoutHaut;
   QGridLayout *m_layoutBas;
   QDateEdit *m_deDate;
   QLineEdit *m_leDate;
   QLineEdit *m_leEvenement;
   QPushButton *m_btModifier;
   QPushButton *m_btSupprimer;


    QGroupBox *m_GRPBox;

private slots:
    void envoyerRequeteSupprimerEtRelecture();//il faut ce subilitE affint d'actualiser l'affichage apre la suppression
    void envoyerRequeteEnregisterEtRelecture();
signals:
    void emmetreModif();



};

#endif //EVENEMENT_H
