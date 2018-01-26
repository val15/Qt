#include "rdv.h"

Rdv::Rdv(QString date,QString time,QString evenement,int id,QString cheminEtNomDb)
{
    m_sDate=date;
    m_sTime=time;
    m_evenement=evenement;
    m_id=id;
    m_cheminEtNomDb=cheminEtNomDb;
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

    connect(m_btSupprimer, SIGNAL(clicked()), this,SLOT(supprimer()));
    connect(m_btModifier, SIGNAL(clicked()), this,SLOT(enregister()));
}

void Rdv::supprimer()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    QSqlQuery query;
    query.prepare("delete from evenement where id=:id");
    query.bindValue(":id",m_id);
    query.exec();
    query.clear();
    db.close();


    emit lireListe();

}

void Rdv::enregister()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(m_cheminEtNomDb);
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }  
    QSqlQuery query;
    query.prepare("update evenement set dateEvenement=:dateEvenement,type=:type,heure=:heure, evenement=:evenement where id=:id");
    query.bindValue(":id",m_id);
    query.bindValue(":dateEvenement",m_deDate->date().toString("yyyy-MM-dd"));
    query.bindValue(":type","rendez-vous");
    query.bindValue(":heure",m_tieTime->time().toString("hh:mm:ss"));
    query.bindValue(":evenement",m_leEvenement->text());
    query.exec();
    query.clear();
    db.close();

    emit lireListe();
}
