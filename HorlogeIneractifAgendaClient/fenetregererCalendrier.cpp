#include "fenetregererCalendrier.h"


fenetregererCalendrier::fenetregererCalendrier(QStringList lstEvt,ClientTcpSocket *clientTcp)
{
   //setFixedSize(800,8000);
    //setFixedWidth(500);
    m_lstEvt=lstEvt;
    m_clientTcp=clientTcp;



    m_layoutGenerale=new QGridLayout;
    setLayout(m_layoutGenerale);
    m_layoutEvenement=new QGridLayout;
    m_btAjouter=new QPushButton("ajouter");
    m_layoutGenerale->addWidget(m_btAjouter,0,0);
    //m_layoutEvenement->


    m_areaEnevement=new QScrollArea(this);
    m_areaEnevement->setWidgetResizable(true);
    m_conteneurEnevement=new QWidget;
   // m_conteneurEnevement->setFixedSize(500,8000);
    m_conteneurEnevement->adjustSize();
    m_areaEnevement->setWidget(m_conteneurEnevement);
    m_conteneurEnevement->setLayout(m_layoutEvenement);
    m_layoutGenerale->addWidget(m_areaEnevement,1,0);
    m_btMajAnnee=new QPushButton("mise a jour annee");
    m_layoutGenerale->addWidget(m_btMajAnnee,2,0);
    m_espaceMessageVartical=new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);;
    m_espaceMessageHorizontal = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  //  mieAJourAnnE();
    lireListeEvenement();

   // connect(this, SIGNAL(close()), this,SLOT(slotFermer()));
    connect(m_btAjouter, SIGNAL(clicked()), this,SLOT(ajouter()));
    connect(m_btMajAnnee, SIGNAL(clicked()), this,SLOT(miseAJourAnnE()));
    fenetregererCalendrier::setWindowTitle("géstion des événements et rdv");


}

void fenetregererCalendrier::miseAJourAnnE()
{
    /*QStringList lstId;
    QStringList lstDate;
    QStringList lstEevenement;


   // query.exec("create table evenement (id int primary key ,dateEvenement DATE,evenement varchar(255))");
    //remplissage
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(m_cheminEtNomDb);
       if(!db.open())
       {
           QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
       }
    QSqlQuery query;//SELECT pseudo, message, DATE_FORMAT(date, '%d/%m/%Y %Hh%imin%ss') AS date FROM minichat
    if(query.exec("SELECT * FROM evenement ORDER BY evenement.id"))
    {
        while(query.next())
        {//m_listWidgetPhoto.append(new miniWidgetPhoto(query.value(0).toInt(),m_cheminMediaPhoto+ query.value(1).toString(),m_cheminMediaPhoto+query.value(2).toString(),m_le_psedo->text(),m_socketMessage,m_socketFichier,m_sID,query.value(3).toString(),m_socketInfo,m_socketListe,query.value(7).toString(),this));
           // m_listWidgetEvenement.append(new evenement(query.value(1).toString(),query.value(2).toString(),query.value(0).toInt(),m_cheminEtNomDb));
            lstId.append(query.value(0).toString());
            lstDate.append(query.value(1).toString());
            lstEevenement.append(query.value(2).toString());
        }
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("erreur lors lecture de la base"),query.lastError().text());
    }
    query.clear();
    db.close();
   // m_listWidgetEvenement.append(new evenement(query.value(1).toString(),query.value(2).toString(),query.value(0).toInt(),m_cheminEtNomDb));


    //modification
    QStringList lstDateDef;
    for(int c=0;c<lstDate.count();c++)
    {
        if(lstEevenement.at(c).split(" ").at(0)=="anniv")
        {
            if(lstDate.at(c).split("-").at(0)!=QDate::currentDate().toString("yyyy"))
           {
              //  QMessageBox::critical(0, QObject::tr("query Error"),lstDate.at(c).split("-").at(0));

                lstDateDef.append(QDate::currentDate().toString("yyyy")+"-"+lstDate.at(c).split("-").at(1)+"-"+lstDate.at(c).split("-").at(2));

            }
            else
                lstDateDef.append(lstDate.at(c));
        }

    }
 if(query.exec("DELETE FROM evenement"))
    {

    }
    else
        QMessageBox::critical(0, QObject::tr("query Error supppretion non faite"),query.lastError().text());
    //28-01-15
    for(int c=0;c<lstId.count();c++)
    {
        query.prepare("insert into evenement values(:id,:dateEvenement,:evenement)");
        query.bindValue(":id", lstId.at(c).toInt());
        query.bindValue(":dateEvenement",lstDateDef.at(c));
        query.bindValue(":evenement",lstEevenement.at(c));
        query.exec();
    }
    query.clear();
    db.close();

*/
}

void fenetregererCalendrier::lireListeEvenement()
{

    if(m_lstEvt.at(1)!="")
    {
        int c;
        for(c=0;c<m_listWidgetEvenementEtRdv.count();c++)
        {
            m_listWidgetEvenementEtRdv.at(c)->close();
        }
        m_listWidgetEvenementEtRdv.clear();
        // qDebug() << query.value(0).toString()<< query.value(1).toString() << query.value(2).toString()<< query.value(3).toString() << query.value(4).toString()<< endl;
        for(int c=1;c<m_lstEvt.count();c++)//1 car 0 est le type
        {
            QString parametres=m_lstEvt.at(c);
            qDebug() << parametres << endl;
            if(parametres.split(";").at(1)=="evenement a un jour")
            {
                Evenement *ev=new Evenement(parametres.split(";").at(0),parametres.split(";").at(3),parametres.split(";").at(4).toInt(),m_clientTcp,this);
                connect(ev,SIGNAL(emmetreModif()),this,SLOT(slotEmmetreModitDUnEvenement()));
                m_listWidgetEvenementEtRdv.append(ev);


            }
            if(parametres.split(";").at(1)=="rendez-vous")
            {
                Rdv *rdv=new Rdv(parametres.split(";").at(0),parametres.split(";").at(2),parametres.split(";").at(3),parametres.split(";").at(4).toInt(),m_clientTcp,this,"");
                connect(rdv,SIGNAL(emmetreModif()),this,SLOT(slotEmmetreModitDUnEvenement()));
               m_listWidgetEvenementEtRdv.append(rdv);
            }

        }




        for(c=0;c<m_listWidgetEvenementEtRdv.count();c++)
        {
            m_layoutEvenement->addWidget(m_listWidgetEvenementEtRdv.at(c),c,0);
            m_layoutEvenement->addItem(m_espaceMessageHorizontal,c,1);
            connect(m_listWidgetEvenementEtRdv.at(c),SIGNAL(emmetreFermeture()),this,SLOT(slotEmmetreModitDUnEvenement()));

        }
        m_layoutEvenement->addItem(m_espaceMessageVartical,c+1,0);


        //emit lireListe();
        m_conteneurEnevement->adjustSize();
        m_conteneurEnevement->adjustSize();

    }

}
void fenetregererCalendrier::slotEmmetreModitDUnEvenement()
{
    emmetreModitDUnEvenement();//ce signale vien du client
}


void fenetregererCalendrier::ajouter()
{
    m_fenetreAjouter=new QDialog();
    m_fenetreAjouter->setModal(true);
    m_fenetreAjouter->setWindowTitle("ajout événement ou rdv");
    m_fenetreAjouter->show();
    m_layoutAjout=new QGridLayout;
   // m_lb_ajoutDate=new QLabel *;
    m_deAjoutDate=new QDateEdit(QDate::currentDate());
 //   QLabel *m_lb_ajoutEvenement;
    m_leAjoutEvenement=new QLineEdit;
    m_btAjoutEnregister=new QPushButton("enregister");
    m_cbTypeAjoutEvennemt=new QComboBox();
    m_tieHeurAjoutEvennemt=new QTimeEdit();
    m_tieHeurAjoutEvennemt->setEnabled(false);
    m_cbTypeAjoutEvennemt->addItem("evenement a un jour");
    m_cbTypeAjoutEvennemt->addItem("rendez-vous");
    m_layoutAjout->addWidget(m_deAjoutDate,0,0);
    m_layoutAjout->addWidget(m_cbTypeAjoutEvennemt,0,1);
    m_layoutAjout->addWidget(m_tieHeurAjoutEvennemt,0,2);
    m_layoutAjout->addWidget(m_leAjoutEvenement,0,3);
    m_layoutAjout->addWidget(m_btAjoutEnregister,0,4);
    m_fenetreAjouter->setLayout(m_layoutAjout);
    connect(m_cbTypeAjoutEvennemt , SIGNAL(currentIndexChanged(QString)), this,SLOT(selectionTypeEvenement(QString)));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(envoyerRequeteAjouterEnregisterEtRelecture()));

    connect(m_btAjoutEnregister , SIGNAL(clicked()), m_fenetreAjouter,SLOT(accept()));

}

void fenetregererCalendrier::selectionTypeEvenement(QString texte)
{
   // QMessageBox::critical(0, QObject::tr("query Error"),"jjrj");
    if(texte=="evemenet a un jour")
        m_tieHeurAjoutEvennemt->setEnabled(false);
    if(texte=="rendez-vous")
        m_tieHeurAjoutEvennemt->setEnabled(true);
}

void fenetregererCalendrier::envoyerRequeteAjouterEnregisterEtRelecture()
{

    QStringList rqt;
    rqt.append("ajouterEvenementEtRelecture");
    rqt.append(m_deAjoutDate->date().toString("yyyy-MM-dd"));
    rqt.append(m_cbTypeAjoutEvennemt->currentText());
    rqt.append(m_tieHeurAjoutEvennemt->time().toString("hh:mm:ss"));
    rqt.append(m_leAjoutEvenement->text());

   m_clientTcp->envoyerMessage(rqt.join("#"));
   emit emmetreFermeture();
   this->close();
}

void fenetregererCalendrier::slotFermer()
{
    emit emmetreFermeture();
}

