#include "rdv.h"

Rdv::Rdv(QString date,QString time,QString evenement,int id,ClientTcpSocket *clientTcp,QWidget *parent,QString dateDuJour)
{
    m_dateDuJour=dateDuJour;
    m_evenement=evenement;
    m_clientTcp=clientTcp;
    m_parent=parent;
    m_sDate=date;
    m_sTime=time;
    m_evenement=evenement;
    m_id=id;
    int annee=m_sDate.split("-").at(0).toInt();
    int mois=m_sDate.split("-").at(1).toInt();
    int jour=m_sDate.split("-").at(2).toInt();
    int h=m_sTime.split(":").at(0).toInt();
    int mn=m_sTime.split(":").at(1).toInt();
    int s=m_sTime.split(":").at(2).toInt();
    QDate dateD;
    dateD.setDate(annee,mois,jour);
    QTime timeD;
    timeD.setHMS(h,mn,s);
    m_GRPBox=new QGroupBox(this);
    setFixedWidth(500);
    m_GRPBox->setFixedWidth(500);
    m_layoutGenerale=new QGridLayout;
    setLayout(m_layoutGenerale);
   m_layoutHaut=new QGridLayout;
   m_layoutBas=new QGridLayout;
    m_deDate=new QDateEdit;
    m_deDate->setDate(dateD);
    m_tieTime=new QTimeEdit;
    m_tieTime->setTime(timeD);
    //m_le_date=new QLineEdit(m_sDate);
    m_leEvenement=new QLineEdit(m_evenement);
    m_btModifier=new QPushButton("enregister");
    m_btSupprimer=new QPushButton("supprimer");
   // m_layoutHaut->addWidget(m_le_date,0,0);
    m_layoutHaut->addWidget(m_deDate,0,0);
    m_layoutHaut->addWidget(m_tieTime,0,1);
    m_layoutHaut->addWidget(m_leEvenement,0,2);
    m_layoutBas->addWidget(m_btModifier,0,0);
    m_layoutBas->addWidget(m_btSupprimer,0,1);
    m_layoutGenerale->addLayout(m_layoutHaut,0,0);
    m_layoutGenerale->addLayout(m_layoutBas,1,0);

    connect(m_btSupprimer, SIGNAL(clicked()), this,SLOT(envoyerRequeteSupprimer()));
    connect(m_btModifier, SIGNAL(clicked()), this,SLOT(envoyerRequeteEnregister()));
}

void Rdv::envoyerRequeteSupprimer()
{
    if(m_dateDuJour!="")
       envoyerRequeteSupprimerEtRelectureEvenementDuJour();
    else
        envoyerRequeteSupprimerEtRelecture();
}

void Rdv::envoyerRequeteEnregister()
{
   if(m_dateDuJour!="")
       envoyerRequeteEnregisterEtRelectureEvenementDuJour();
    else
        envoyerRequeteEnregisterEtRelecture();
}

void Rdv::envoyerRequeteSupprimerEtRelecture()
{
    QStringList rqt;
    rqt.append("supprimerEvenementEtRelecture");
    rqt.append(QString::number(m_id));

   m_clientTcp->envoyerMessage(rqt.join("#"));
   emmetreModif();
   m_parent->close();


}

void Rdv::envoyerRequeteEnregisterEtRelecture()
{
    QStringList rqt;
    rqt.append("modifierEvenementEtRelecture");
    rqt.append(QString::number(m_id));
    rqt.append(m_deDate->date().toString("yyyy-MM-dd"));
    rqt.append("rendez-vous");
    rqt.append(m_tieTime->time().toString("hh:mm:ss"));
    rqt.append(m_leEvenement->text());

   m_clientTcp->envoyerMessage(rqt.join("#"));
   emmetreModif();
   m_parent->close();
}

void Rdv::envoyerRequeteSupprimerEtRelectureEvenementDuJour()
{
    QStringList rqt;
    rqt.append("supprimerEvenementEtRelectureEvenementDuJour");
    rqt.append(QString::number(m_id));
    rqt.append(m_dateDuJour);
   m_clientTcp->envoyerMessage(rqt.join("#"));
}

void Rdv::envoyerRequeteEnregisterEtRelectureEvenementDuJour()
{
    QStringList rqt;
    rqt.append("modifierEvenementEtRelectureEvenementDuJour");
    rqt.append(QString::number(m_id));
    rqt.append(m_deDate->date().toString("yyyy-MM-dd"));
    rqt.append("rendez-vous");
    rqt.append(m_tieTime->time().toString("hh:mm:ss"));
    rqt.append(m_leEvenement->text());
    rqt.append(m_dateDuJour);
   m_clientTcp->envoyerMessage(rqt.join("#"));
}
