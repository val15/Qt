#include "evenement.h"

Evenement::Evenement(QString date,QString evenement,int id,ClientTcpSocket *clientTcp,QWidget *parent)
{
    m_parent=parent;
    m_sDate=date;
    m_evenement=evenement;
    m_id=id;
    m_clientTcp=clientTcp;
    int annee=m_sDate.split("-").at(0).toInt();
    int mois=m_sDate.split("-").at(1).toInt();
    int jour=m_sDate.split("-").at(2).toInt();
    QDate dateD;
    dateD.setDate(annee,mois,jour);
    m_GRPBox=new QGroupBox(this);
    setFixedWidth(500);
    m_GRPBox->setFixedWidth(500);
    m_layoutGenerale=new QGridLayout;
    setLayout(m_layoutGenerale);
   m_layoutHaut=new QGridLayout;
   m_layoutBas=new QGridLayout;
    m_deDate=new QDateEdit;
    m_deDate->setDate(dateD);
    //m_le_date=new QLineEdit(m_sDate);
    m_leEvenement=new QLineEdit(m_evenement);
    m_btModifier=new QPushButton("enregister");
    m_btSupprimer=new QPushButton("supprimer");
   // m_layoutHaut->addWidget(m_le_date,0,0);
    m_layoutHaut->addWidget(m_deDate,0,0);
    m_layoutHaut->addWidget(m_leEvenement,0,1);
    m_layoutBas->addWidget(m_btModifier,0,0);
    m_layoutBas->addWidget(m_btSupprimer,0,1);
    m_layoutGenerale->addLayout(m_layoutHaut,0,0);
    m_layoutGenerale->addLayout(m_layoutBas,1,0);

    connect(m_btSupprimer, SIGNAL(clicked()), this,SLOT(envoyerRequeteSupprimerEtRelecture()));
    connect(m_btModifier, SIGNAL(clicked()), this,SLOT(envoyerRequeteEnregisterEtRelecture()));
}

void Evenement::envoyerRequeteSupprimerEtRelecture()
{
    QStringList rqt;
    rqt.append("supprimerEvenementEtRelecture");
    rqt.append(QString::number(m_id));
   m_clientTcp->envoyerMessage(rqt.join("#"));
   emmetreModif();
   m_parent->close();


}

void Evenement::envoyerRequeteEnregisterEtRelecture()
{
    QStringList rqt;
    rqt.append("modifierEvenementEtRelecture");
    rqt.append(QString::number(m_id));
    rqt.append(m_deDate->date().toString("yyyy-MM-dd"));
    rqt.append("evenement a un jour");
    rqt.append("00:00:00");
    rqt.append(m_leEvenement->text());
   m_clientTcp->envoyerMessage(rqt.join("#"));
   emmetreModif();
   m_parent->close();
}
