#include "Fenetre0.h"
MaFenetre::MaFenetre() : QWidget()
{

    prm=true;
    //il faut installer bwm-ng
    //il faut que la base de donne contienne des donnes
    //il faut que les fichiers "heurReveille" et "etatReveille" existent et ne sont pas vide





    m_nomFichierDeConfig="horlogeAgendaClient.conf";//ce ficher contioen tout les config comme l'heur du reveil....
    m_debit="0K";
    m_debitPrecedent=m_debit;

    m=0;
    pas=40;
    m_etindreAlrme="d";//d activer l'etinte
    m_etatClignotement="a";//a ou d
    m_etatVitesse="d";
    m_etatEspace="a";
    m_allumAuto=false;
    m_estConnecter=false;
    m_clignotementEstActivE=true;
    m_ledVitesseEstActivE=false;
    m_ledEspaceEstActivE=true;
    m_lumiereActvE=false;
    m_priseActivE=false;
    m_peutDEspace="f";


    //pour la connexion au serveur
    m_layoutConnexion=new QGridLayout;
    m_leAdressIpServeur=new QLineEdit;
    m_lbIp=new QLabel("ip : ");
    m_lbPort=new QLabel("port : ");
    m_lePort=new QLineEdit;
    m_btConnexion=new QPushButton("connexion");
    m_layoutConnexion->addWidget(m_lbIp,0,0);
    m_layoutConnexion->addWidget(m_leAdressIpServeur,0,1);
    m_layoutConnexion->addWidget(m_lbPort,0,2);
    m_layoutConnexion->addWidget(m_lePort,0,3);
    m_layoutConnexion->addWidget(m_btConnexion,0,4);

    m_btChargerConfiguration=new QPushButton("charger configuration");
    m_configChargE=false;

    m_layoutGenerale=new QGridLayout;
    m_layoutDebit=new QGridLayout;
    m_lb_typeDebit=new QLabel("type debit :");
    m_cbTypeDebit=new QComboBox;
    m_cbTypeDebit->addItem("debit client");
    m_cbTypeDebit->addItem("debit interne");
    m_estDebitInterne=false;
    m_leDebitInterface=new QLineEdit();
    m_layoutDebit->addWidget(m_lb_typeDebit,0,0);
    m_layoutDebit->addWidget(m_cbTypeDebit,0,1);
    m_layoutDebit->addWidget(m_leDebitInterface,0,2);




    m_btGereCalentdier=new QPushButton("gerecalendrier");


    m_layoutAlarme=new QGridLayout;
    m_chbAlarme=new QCheckBox("activer réveil");
    m_lbReveil=new QLabel("réveil : ");
    m_btEteindreAlarme=new QPushButton("éteindre alarme");

    m_layoutCommande=new QGridLayout;
    m_btPrise=new QPushButton("activer prise");
    m_btLumiere=new QPushButton("allumer lumière");

    m_chbAllumAutomatque=new QCheckBox("allumage automatique à :");
    m_tieAllumAutomatque=new QTimeEdit;
    m_chbExtinctionAutomatque=new QCheckBox("éxtinction automatique à");
    m_tieExtinctionAutomatque=new QTimeEdit;
    m_btClignote=new QPushButton("désactiver clignotement");
    m_btVitesse=new  QPushButton("activer led vitesse");
    m_chbActiverAutoLedVitesse=new QCheckBox("automatique led vitesse");
    m_activerAutoLedVitesse=false;
    m_chbActiverAutoLedVitesse->setChecked(false);
    m_btEspace=new   QPushButton("désactiver led espace faible");
    m_layoutLed=new QGridLayout;
    m_layoutLed->addWidget(m_btClignote,0,0);
    m_layoutLed->addWidget(m_btEspace,0,1);
    m_layoutLed->addWidget(m_btVitesse,0,2);
    m_layoutLed->addWidget(m_chbActiverAutoLedVitesse,0,3);
    m_tieSelectionReveille=new QTimeEdit();

    m_btClignote->setEnabled(false);
    m_btVitesse->setEnabled(false);
    m_btEspace->setEnabled(false);
    m_chbAllumAutomatque->setEnabled(false);
    m_btPrise->setEnabled(false);
    m_btLumiere->setEnabled(false);
    m_btLumiere=new QPushButton("allumer lumiere");

    mLbDebitTitre=new QLabel("debit : ");
    mLbDebit=new QLabel("0k");
    mLayoutDebitAffiche=new QGridLayout();
    mLayoutDebitAffiche->addWidget(mLbDebitTitre,0,0);
     mLayoutDebitAffiche->addWidget(mLbDebit,0,1);


    m_layoutAlarme->addWidget(m_lbReveil,0,0);
    m_layoutAlarme->addWidget(m_tieSelectionReveille,0,1);
    m_layoutAlarme->addWidget(m_chbAlarme,0,2);
    m_layoutAlarme->addWidget(m_btEteindreAlarme,0,3);

     m_layoutCommande->addWidget(m_chbAllumAutomatque,0,0);
     m_layoutCommande->addWidget(m_tieAllumAutomatque,0,1);
     m_layoutCommande->addWidget(m_chbExtinctionAutomatque,1,0);
     m_layoutCommande->addWidget(m_tieExtinctionAutomatque,1,1);
     m_layoutCommande->addWidget(m_btLumiere,0,2);
     m_layoutCommande->addWidget(m_btPrise,1,2);



     //pour le calandrier
     m_layoutCalandrier=new QGridLayout();
     m_cldr=new MaClandrier();
     m_lbEvenementsDuJour=new QLabel();
     QLabel *lbRdvDuJour= new QLabel("les rendez-vous du jour");
     m_conteneurRvdDuJour=new QWidget;
     m_layoutRdvDuJour=new QGridLayout;
     m_areaConteneurRvdDuJour=new QScrollArea;
     m_areaConteneurRvdDuJour->setWidgetResizable(true);
     m_areaConteneurRvdDuJour->setWidget(m_conteneurRvdDuJour);
     m_conteneurRvdDuJour->setLayout(m_layoutRdvDuJour);
     m_btAjouterEvenement=new QPushButton("ajouter événement");
     m_layoutCalandrier->addWidget(m_cldr,0,0);
     m_layoutCalandrier->addWidget(m_lbEvenementsDuJour,1,0);
     m_layoutCalandrier->addWidget(lbRdvDuJour,2,0);
     m_layoutCalandrier->addWidget(m_areaConteneurRvdDuJour,3,0);
     m_layoutCalandrier->addWidget(m_btAjouterEvenement,4,0);



    m_layoutGenerale->addLayout(m_layoutConnexion,0,0);
    m_layoutGenerale->addLayout(m_layoutDebit,1,0);
    m_layoutGenerale->addWidget(m_btChargerConfiguration,2,0);
    m_layoutGenerale->addLayout(mLayoutDebitAffiche,3,0);
    m_layoutGenerale->addLayout(m_layoutAlarme,4,0);
    m_layoutGenerale->addLayout(m_layoutCommande,5,0);
    m_layoutGenerale->addLayout(m_layoutLed,6,0);
    m_layoutGenerale->addWidget(m_btGereCalentdier,7,0);
    m_layoutGenerale->addLayout(m_layoutCalandrier,8,0);


   // m_pb_allumerEtindreLed=new QPushButton("allumer led");
  //  m_pb_allumerEtindreLed->setEnabled(false);
   // m_layoutGenerale->addWidget(m_pb_allumerEtindreLed,6,0);

    setLayout(m_layoutGenerale);





    m_dateTempsActuel=new QDateTime;
    m_timerDebit=new QTimer;







    //pour le calandrier
    connect(m_cldr, SIGNAL(clicked(QDate)), this, SLOT(envoyerRequeteDemandeDesEvenementsDuJour(QDate)));//lis les dade important du mois courant pour les colorer;
    connect(m_cldr, SIGNAL(currentPageChanged(int,int)), this, SLOT(envoyerRequeteDemanderDateImportantesDuMois(int,int)));//lis les dade important du mois courant pour les colorer;
    connect(m_btAjouterEvenement, SIGNAL(clicked()), this, SLOT(ajouterEvenement()));//lis les dade important du mois courant pour les colorer;

    //pour la connexion
    connect(m_btConnexion , SIGNAL(clicked()), this,SLOT(connexion()));




    QObject::connect(m_btGereCalentdier  , SIGNAL(clicked()), this,SLOT(envoyerRequeteDemanderToutLesEvements()));

    QObject::connect(m_cbTypeDebit, SIGNAL(currentTextChanged(QString)), this,SLOT(typeDebitChange(QString)));
    //  QMessageBox::critical(0, QObject::tr("Database Error"),m_dateTempsActuel->currentDateTime().toString("mm:ss"));

  //  QObject::connect(m_pb_allumerEtindreLed , SIGNAL(clicked()), this,SLOT(allumerEtindreLed()));
     QObject::connect(m_btClignote, SIGNAL(clicked()), this,SLOT(envoyerRequeteActiVOuDesactiVClignotement()));
      QObject::connect(m_btVitesse, SIGNAL(clicked()), this,SLOT(envoyerRequeteActiVOuDesactiVVitesse()));
      QObject::connect(m_chbActiverAutoLedVitesse, SIGNAL(clicked()), this,SLOT(envoyerRequeteActiVOuDesactiVVitesseAuto()));
      QObject::connect(m_btEspace, SIGNAL(clicked()), this,SLOT(envoyerRequeteActiVOuDesactiVEspace()));
     QObject::connect(m_btLumiere , SIGNAL(clicked()), this,SLOT(envoyerRequeteAllumerOuEteindreLumiR()));
     QObject::connect(m_btPrise , SIGNAL(clicked()), this,SLOT(envoyerRequeteActiVOueteindrePrise()));
     QObject::connect(m_chbAllumAutomatque, SIGNAL(clicked()), this,SLOT(desativerActiverAllumeAuto()));
    QObject::connect(m_tieSelectionReveille , SIGNAL(editingFinished()), this,SLOT(envoyerEcrireConfig()));
    QObject::connect(m_btEteindreAlarme , SIGNAL(clicked()), this,SLOT(envoyerRequeteEteindreAlarme()));
    QObject::connect(m_chbAlarme , SIGNAL(clicked()), this,SLOT(envoyerEcrireConfig()));
    QObject::connect(m_tieAllumAutomatque , SIGNAL(editingFinished()), this,SLOT(envoyerEcrireConfig()));
    QObject::connect(m_chbExtinctionAutomatque , SIGNAL(clicked()), this,SLOT(envoyerEcrireConfig()));
    QObject::connect(m_tieExtinctionAutomatque , SIGNAL(editingFinished()), this,SLOT(envoyerEcrireConfig()));
    QObject::connect(m_chbAllumAutomatque , SIGNAL(clicked()), this,SLOT(envoyerEcrireConfig()));

    QObject::connect(m_btChargerConfiguration , SIGNAL(clicked()), this,SLOT(chargerConfiguration()));



    lireConfigLocal();

    //lecture des dates
 //   lectureDesDatesImportantsDuMois(QDate::currentDate().year(),QDate::currentDate().month());
 //   lectureDesEvenementsDuJour(QDate::currentDate());


    desactiverToutLesAutresWidgets();
    desactiverLesWidgetsConfig();



    //setFixedSize(600,680);
    setFixedHeight(695);
   // setMaximumSize(300,115);
   // resize(300,115);
   // setW
    MaFenetre::setWindowTitle("horloge interracif client");
}

void MaFenetre::desactiverToutLesAutresWidgets()
{

    //pour l'horloge
    //QPushButton *m_bt_apropo;//on ceer un atribu de type QPushButton s'est un pointeur

    m_btChargerConfiguration->setEnabled(false);
    m_btGereCalentdier->setEnabled(false);
    m_btAjouterEvenement->setEnabled(false);
    m_cldr->setEnabled(false);

}

void MaFenetre::activerToutLesAutresWidgets()
{
    m_btChargerConfiguration->setEnabled(true);
    m_btGereCalentdier->setEnabled(true);
    m_cldr->setEnabled(true);
    m_btAjouterEvenement->setEnabled(true);
}

void MaFenetre::desactiverLesWidgetsConfig()
{

    //pour l'horloge
    //QPushButton *m_bt_apropo;//on ceer un atribu de type QPushButton s'est un pointeur

    m_chbAllumAutomatque->setEnabled(false);
    m_tieAllumAutomatque->setEnabled(false);
    m_chbExtinctionAutomatque->setEnabled(false);
    m_tieExtinctionAutomatque->setEnabled(false);
    m_btPrise->setEnabled(false);
    m_btLumiere->setEnabled(false);
    m_btClignote->setEnabled(false);
     m_btVitesse->setEnabled(false);
     m_chbActiverAutoLedVitesse->setEnabled(false);
      m_btEspace->setEnabled(false);
    m_tieSelectionReveille->setEnabled(false);
    m_chbAlarme->setEnabled(false);
    m_btEteindreAlarme->setEnabled(false);

}

void MaFenetre::activerLesWidgetsConfig()
{
    m_chbAllumAutomatque->setEnabled(true);
    m_tieAllumAutomatque->setEnabled(true);
    m_chbExtinctionAutomatque->setEnabled(true);
    m_tieExtinctionAutomatque->setEnabled(true);
    m_btPrise->setEnabled(true);
    m_btLumiere->setEnabled(true);
    m_btClignote->setEnabled(true);
     m_btVitesse->setEnabled(true);
     m_chbActiverAutoLedVitesse->setEnabled(true);
      m_btEspace->setEnabled(true);
     m_btAjouterEvenement->setEnabled(true);
    m_tieSelectionReveille->setEnabled(true);
    m_chbAlarme->setEnabled(true);
    m_btEteindreAlarme->setEnabled(true);
}




void MaFenetre::traiterMessagServeur(QString msg)
{
    //qDebug() << m_debit << endl;
   //m_debit=msg;

}

void MaFenetre::deconnectionClient()
{
   // m_debit="0K";
    mLbDebit->setText("0K");
}


//arduino
void MaFenetre::readData()
{

   /* QByteArray array = m_port->readAll();
    m_teInfo->insertPlainText(array);*/
    //QString strRecu;
}


//slote qui appele les slotes des meme nom
void MaFenetre::lectureDesDatesImportantsDuMois(QStringList lstDate)
{
    if(lstDate.at(1)!="")//si il y a des dates
    {
        m_cldr->colorerNormalepourLesAutres(m_moisPageCourant);
        for(int c=1;c<lstDate.count();c++)
        {
            QStringList lst=lstDate.at(c).split("-");
            QString a=lst.at(0);
            QString m=lst.at(1);
            QString j=lst.at(2);
            QString type=lst.at(3);
            QDate d0(a.toInt(),m.toInt(),j.toInt());
            if(type=="evenement a un jour")
                m_cldr->colorerEnBleu(d0);
            if(type=="rendez")//parceque rendez-vous contie un -
                m_cldr->colorerEnJaune(d0);
        }
    }

}
void MaFenetre::lectureDesConfig(QStringList lstConfig)//11-01-21
{



    lstConfig.append("lstConfig");


    if(lstConfig.at(1)=="1")
    {
        m_etatReveil="1";
        m_chbAlarme->setChecked(true);
    }
    else
    {
        m_etatReveil="0";
        m_chbAlarme->setChecked(false);
    }
    m_heurReveil=lstConfig.at(2);
    QStringList lst=m_heurReveil.split(":");
    int h=lst.at(0).toInt();
    int m=lst.at(1).toInt();
    QTime timeAlarm(h,m);
    m_tieSelectionReveille->setTime(timeAlarm);

    if(lstConfig.at(3)=="1")
    {
        m_etatAllumAutomatque="1";
        m_chbAllumAutomatque->setChecked(true);
    }
    else
    {
        m_etatAllumAutomatque="0";
        m_chbAllumAutomatque->setChecked(false);
    }
    m_heurAllumAutomatque=lstConfig.at(4);
     lst=m_heurAllumAutomatque.split(":");
     h=lst.at(0).toInt();
     m=lst.at(1).toInt();
    QTime timeAllum(h,m);
    m_tieAllumAutomatque->setTime(timeAllum);

    if(lstConfig.at(5)=="1")
    {
        m_etatExtictionAutomatque="1";
        m_chbExtinctionAutomatque->setChecked(true);
    }
    else
    {
        m_etatExtictionAutomatque="0";
        m_chbExtinctionAutomatque->setChecked(false);
    }
    m_heurExtictionAutomatque=lstConfig.at(6);
     lst=m_heurExtictionAutomatque.split(":");
     h=lst.at(0).toInt();
     m=lst.at(1).toInt();
    QTime time(h,m);
    m_tieExtinctionAutomatque->setTime(time);


    if(lstConfig.at(7)=="1")
    {
        m_lumiereActvE=true;
        m_btLumiere->setText("éteindre lumière");

    }
    else
    {
        m_lumiereActvE=false;
        m_btLumiere->setText("allumer lumière");

    }
    if(lstConfig.at(8)=="1")
    {
        m_priseActivE=true;
        m_btPrise->setText("désactiver prise");
    }
    else
    {
        m_btPrise->setText("activer prise");
        m_priseActivE=false;
    }
    if(lstConfig.at(9)=="1")
    {
        m_clignotementEstActivE=true;
        m_btClignote->setText("désactiver clignotement");

    }
    else
    {
        m_clignotementEstActivE=false;
       m_btClignote->setText("activer clignotement");
    }

    if(lstConfig.at(10)=="1")
    {
        m_ledEspaceEstActivE=true;
        m_btEspace->setText("désactiver led éspace faible");
    }
    else
    {
         m_ledEspaceEstActivE=false;
        m_btEspace->setText("activer led espace faible");
    }

    if(lstConfig.at(11)=="1")
        m_chbActiverAutoLedVitesse->setChecked(true);
    else
        m_chbActiverAutoLedVitesse->setChecked(false);
    if(lstConfig.at(12)=="1")
    {
        m_ledVitesseEstActivE=true;
        m_btVitesse->setText("désactiver led vitesse");
    }
    else
    {
        m_ledVitesseEstActivE=false;
        m_btVitesse->setText("activer led vitesse");
    }

    activerLesWidgetsConfig();

}

void MaFenetre::traiterDebit(QStringList rep)
{
   // qDebug() << rep << endl;
    QString debit=rep.at(1);
    mLbDebit->setText(debit);
}


/*void MaFenetre::lectureDesEvenementsDuJour()
{
    lectureDesEvenementsDuJour(QDate::currentDate());
}
*/



//pour le calandrier

int MaFenetre::comparerDeuxDate(QString d0,QString d1)
{
    int m0=d0.split("-").at(0).toInt();
    int j0=d0.split("-").at(1).toInt();
    int m1=d1.split("-").at(0).toInt();
    int j1=d1.split("-").at(1).toInt();
    if(m0>m1)
        return 1;
    else if(m0<m1)
        return -1;
    else
    {
        if(d0>d1)
            return 1;
        else if(d0<d1)
            return -1;
        else
            return 0;
    }
}


void MaFenetre::lectureDesEvenementsDuJour(QStringList lstEvt)
{
    for(int c=0;c<m_listWidgetRdv.count();c++)
        m_listWidgetRdv.at(c)->close();
    m_lbEvenementsDuJour->clear();
    m_listWidgetRdv.clear();
    m_areaConteneurRvdDuJour->setVisible(false);
    //QMessageBox::critical(0, QObject::tr("query Error"),"query.lastError().text()");
    QStringList lstEvenementsDuJour;
    QStringList lstRdv;

    //23-7-1-17


    //determiner la pace du ceparateur
     int indiceCeparateur;
     for(int c=1;c<lstEvt.count();c++)//1 car 0 c'est le type
     {
         if(lstEvt.at(c)=="rdv")
             indiceCeparateur=c;
     }


     if(lstEvt.at(1)!="")//si il y a des evemements
     {
         for(int c=1;c<indiceCeparateur;c++)
             lstEvenementsDuJour.append(lstEvt.at(c));
     }
    qDebug() << "indiceCeparateur="<<indiceCeparateur<< endl;
    qDebug() << "taille du tableau="<<lstEvt.count()<< endl;
     if(indiceCeparateur!=lstEvt.count()-2)//si le separateur n'est pas le dérnier element
     {
         qDebug() << "indiceCeparateur="<<indiceCeparateur<< endl;
         for(int c=indiceCeparateur+1;c<lstEvt.count()-1 ;c++)
         {
             lstRdv.append(lstEvt.at(c));
             qDebug() << "rdv c = "<<c<< endl;
         }

     }


    if(!lstEvenementsDuJour.isEmpty())
    {
        QString contenu="<strong>";
        for(int c=0;c<lstEvenementsDuJour.count();c++)
            contenu+=lstEvenementsDuJour.at(c) +" ; ";
        contenu+="</strong>";
        m_lbEvenementsDuJour->setText(m_dateCourrante.toString("dd MMMM  :")+contenu);
    }

  //  QMessageBox::critical(0, QObject::tr("query Error"),QString::number(m_listWidgetRdv.count()));
    for(int c=0;c<lstRdv.count();c++)//il faut céer les objet à partir de la liste
    {

        QString parametres=lstRdv.at(c);
        m_listWidgetRdv.append(new Rdv(parametres.split(";").at(0),parametres.split(";").at(1),parametres.split(";").at(2),parametres.split(";").at(3).toInt(),m_clientTcp,this,m_dateCourrante.toString("yyyy-MM-dd")));

    }


    if(!m_listWidgetRdv.isEmpty())
    {
        m_areaConteneurRvdDuJour->setVisible(true);
        for(int c=0;c<m_listWidgetRdv.count();c++ )
        {
            m_layoutRdvDuJour->addWidget(m_listWidgetRdv.at(c),c,0);
            //13-01
            QObject::connect(m_listWidgetRdv.at(c), SIGNAL(), this,SLOT(envoyerRequeteDemanderToutLesEvements()));
        }
   }
}

void MaFenetre::lectureDeToutLesEvenement(QStringList lstEvt)
{
    m_fcl=new fenetregererCalendrier(lstEvt,m_clientTcp);
    QObject::connect(m_fcl, SIGNAL(emmetreFermeture()), this,SLOT(mettreEnRequeteEnRetartDemanderDateImportantesDuMois()));
    QObject::connect(m_fcl, SIGNAL(emmetreModitDUnEvenement()), this,SLOT(mettreEnRequeteEnRetartDemanderDateImportantesDuMois()));

       m_fcl->setModal(true);
       m_fcl->show();
}

void MaFenetre::ajouterEvenement()
{
    QDialog *fenetreAjouter=new QDialog();
    fenetreAjouter->setModal(true);
    fenetreAjouter->setWindowTitle("ajout événement ou rdv");
    fenetreAjouter->show();
    QGridLayout *layoutAjoutPrincipal=new QGridLayout;
    QGridLayout *layoutAjoutElement=new QGridLayout;
   // m_lb_ajoutDate=new QLabel *;
    m_deAjoutDate=new QDateEdit(m_cldr->selectedDate());
    QLabel *lbDate=new QLabel("date");
    QLabel *lbType=new QLabel("type");
    QLabel *lbHeure=new QLabel("heure");
    QLabel *lbEvenement=new QLabel("evenement");
    m_leAjoutEvenement=new QLineEdit;
    m_btAjoutEnregister=new QPushButton("enregister");
    m_cbTypeAjoutEvennemt=new QComboBox();
    m_tieHeurAjoutEvennemt=new QTimeEdit();
    m_tieHeurAjoutEvennemt->setEnabled(false);
    QSpacerItem *spiV=new QSpacerItem(200,400,QSizePolicy::Minimum,QSizePolicy::Expanding);

    m_cbTypeAjoutEvennemt->addItem("evenement a un jour");
    m_cbTypeAjoutEvennemt->addItem("rendez-vous");
    layoutAjoutElement->addWidget(lbDate,0,0);
    layoutAjoutElement->addWidget(lbType,0,1);
    layoutAjoutElement->addWidget(lbHeure,0,2);
    layoutAjoutElement->addWidget(lbEvenement,0,3);
    layoutAjoutElement->addWidget(m_deAjoutDate,1,0);
    layoutAjoutElement->addWidget(m_leAjoutEvenement,1,3);
    layoutAjoutElement->addWidget(m_cbTypeAjoutEvennemt,1,1);
    layoutAjoutElement->addWidget(m_tieHeurAjoutEvennemt,1,2);
    layoutAjoutPrincipal->addLayout(layoutAjoutElement,0,0);
    layoutAjoutPrincipal->addWidget(m_btAjoutEnregister,1,0);
    layoutAjoutPrincipal->addItem(spiV,2,0);


    fenetreAjouter->setLayout(layoutAjoutPrincipal);
  /*  connect(btAjoutEnregister , SIGNAL(clicked()), this,SLOT(enregister()));
*/   connect(m_cbTypeAjoutEvennemt , SIGNAL(currentIndexChanged(QString)), this,SLOT(selectionTypeEvenement(QString)));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(envoyerRequeteAjouterEnregister()));

   // connect(m_btAjoutEnregister , SIGNAL(clicked()), this,SLOT(lireEvenementDuJourEtProch1()));
    connect(m_btAjoutEnregister , SIGNAL(clicked()), fenetreAjouter,SLOT(accept()));
   // connect(fenetreAjouter , SIGNAL(rejected()), this,SLOT(envoyerRequeteDemanderDateImportantesDuMois()));

}

void MaFenetre::selectionTypeEvenement(QString texte)
{
   // QMessageBox::critical(0, QObject::tr("query Error"),"jjrj");
    if(texte=="evemenet a un jour")
        m_tieHeurAjoutEvennemt->setEnabled(false);
    if(texte=="rendez-vous")
        m_tieHeurAjoutEvennemt->setEnabled(true);
}

void MaFenetre::envoyerRequeteAjouterEnregister()
{

        QStringList rqt;
        rqt.append("ajouterEvenement");
        rqt.append(m_deAjoutDate->date().toString("yyyy-MM-dd"));
        rqt.append(m_cbTypeAjoutEvennemt->currentText());
        rqt.append(m_tieHeurAjoutEvennemt->time().toString("hh:mm:ss"));
        rqt.append(m_leAjoutEvenement->text());

       m_clientTcp->envoyerMessage(rqt.join("#"));
        /* lectureDesDatesImportantsDuMois();
       lectureDesEvenementsDuJour();
         lireEvenementDuJourEtProch1();*/

       mettreEnRequeteEnRetartDemanderDateImportantesDuMois();


}



//lecture et eccriture des configs locaux
void MaFenetre::lireConfigLocal()
{
    Fichier fConfig(m_nomFichierDeConfig);
    if(!fConfig.siExiste())
    {
        qDebug() << "le fichier de configuration n'existe pas"<< endl;
         return;
    }
    else
    {
        qDebug() << "lectre du fichier de config"<< endl;
        m_adresseIpServeur=fConfig.lireUneLigne(0);
        m_port=fConfig.lireUneLigne(1);
        m_interface=fConfig.lireUneLigne(2);
        m_leAdressIpServeur->setText(m_adresseIpServeur);
        m_lePort->setText(m_port);
       m_leDebitInterface->setText(m_interface);

    }
}
void MaFenetre::ecrirConfigLocal()
{

    QString strConfig;
    m_adresseIpServeur=m_leAdressIpServeur->text();
    strConfig+=m_adresseIpServeur;
    strConfig+="\r\n";
    m_port=m_lePort->text();
    strConfig+=m_port;
    strConfig+="\r\n";
    m_interface=m_leDebitInterface->text();
    strConfig+=m_interface;

    Fichier fConfig(m_nomFichierDeConfig);
    fConfig.ecrire(strConfig);


}

void MaFenetre::envoyerEcrireConfig()
{

    if(m_chbAlarme->isChecked())
              m_etatReveil = "1";
      else
             m_etatReveil = "0";
      m_heurReveil=m_tieSelectionReveille->text();
      if(m_chbAllumAutomatque->isChecked())
          m_etatAllumAutomatque = "1";
      else
          m_etatAllumAutomatque = "0";
      m_heurAllumAutomatque=m_tieAllumAutomatque->text();
      if(m_chbExtinctionAutomatque->isChecked())
          m_etatExtictionAutomatque = "1";
      else
          m_etatExtictionAutomatque = "0";
      m_heurExtictionAutomatque=m_tieExtinctionAutomatque->text();

       QString strConfig;//ce string contiedra les configuration
       strConfig+=m_heurReveil;
       strConfig+="\r\n";
       strConfig+=m_etatReveil;
       strConfig+="\r\n";
       strConfig+=m_heurAllumAutomatque;
       strConfig+="\r\n";
       strConfig+=m_etatAllumAutomatque;
       strConfig+="\r\n";
       strConfig+=m_heurExtictionAutomatque;
       strConfig+="\r\n";
       strConfig+=m_etatExtictionAutomatque;



    QStringList rqt;
    rqt.append("ecrireConfig");
    rqt.append(strConfig);
    qDebug() << rqt<< endl;
    m_clientTcp->envoyerMessage(rqt.join("#"));
}

void MaFenetre::envoyerRequeteEteindreAlarme()
{
    QStringList rqt;
    rqt.append("demandeEteindreAlarme");
    rqt.append("#");
    m_clientTcp->envoyerMessage(rqt.join("#"));
}






//Slot pour le click sur le bouton de connexion
void MaFenetre::connexion()
{
    ecrirConfigLocal();
    //on coche > connexion
    if(!m_estConnecter)
    {
        //ecrirConfig();
        m_adresseIpServeur=m_leAdressIpServeur->text();
        m_port=m_lePort->text();
        //pour la conexion avec le server
        m_clientTcp=new ClientTcpSocket(m_adresseIpServeur,m_port);
       // m_clientTcpDebit=new ClientTcpSocket(m_adresseIpServeur,"7115");
        connect(m_clientTcp, SIGNAL(emmetreMessageRecu(QString)), this, SLOT(clientDonneesRecues(QString)));
        connect(m_clientTcp, SIGNAL(emmetreConnecE()), this, SLOT(connectionAuServeurReussit()));
        connect(m_clientTcp, SIGNAL(emmetreDeconnection()), this, SLOT(deconnectionDuServeur()));
      /*  connect(m_clientTcpDebit, SIGNAL(emmetreMessageRecu(QString)), this, SLOT(clientDonneesRecues(QString)));
        connect(m_clientTcpDebit, SIGNAL(emmetreConnecE()), this, SLOT(connectionAuServeurReussit()));
        connect(m_clientTcpDebit, SIGNAL(emmetreDeconnection()), this, SLOT(deconnectionDuServeur()));*/
       // connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));



        if(m_adresseIpServeur.isEmpty() || m_port.isEmpty())
        {
            QMessageBox::critical(this,"erreur","vous devez entre un adresse et le numero de port");
        }
        else
        {
            m_clientTcp->connexionAuServeur();
         //   m_clientTcpDebit->connexionAuServeur();
            //on demande les evenement du mois en cour
            //les requettes entre le cient et le serveur seras tjrs sous forme de tableau avec l'indice 0 le type
            envoyerRequeteDemanderDateImportantesDuMois(QDate::currentDate().toString("yyyy").toInt(),QDate::currentDate().toString("MM").toInt());
           // envoyerRequeteDemandeDesEvenementsDuJour(QDate::currentDate());//il faut eviter les requettes succesives
            m_timerDebit->start(1000);
            connect(m_timerDebit,SIGNAL(timeout()),this,SLOT(tempLireEtEnvoieDebit()));
        }



    }
    else
    {


    }


}

void MaFenetre::envoyerRequeteActiVOuDesactiVClignotement()
{
    QStringList rqt;
    rqt.append("demandeActiVOuDesactiVClignotement");
    rqt.append("#");
   m_clientTcp->envoyerMessage(rqt.join("#"));
}

void MaFenetre::envoyerRequeteActiVOuDesactiVVitesse()
{
    QStringList rqt;
    rqt.append("demandeActiVOuDesactiVVitesse");
    rqt.append("#");
   m_clientTcp->envoyerMessage(rqt.join("#"));
}

void MaFenetre::actiVOuDesactiVVitesseFnc()
{
    if(m_ledVitesseEstActivE)
    {
        m_etatVitesse="d";
        m_btVitesse->setText("activer led vitesse");

    }
    else
    {
        m_etatVitesse="a";
       m_btVitesse->setText("désactiver led vitesse");
    }
    m_ledVitesseEstActivE=!m_ledVitesseEstActivE;
}

void MaFenetre::envoyerRequeteActiVOuDesactiVVitesseAuto()
{
    QStringList rqt;
    rqt.append("demandeActiVOuDesactiVVitesseAuto");
    rqt.append("#");
    m_clientTcp->envoyerMessage(rqt.join("#"));
}

void MaFenetre::envoyerRequeteActiVOuDesactiVEspace()
{
    QStringList rqt;
    rqt.append("demandeActiVOuDesactiVEspace");
    rqt.append("#");
    m_clientTcp->envoyerMessage(rqt.join("#"));
}

void MaFenetre::temp()
{


}


void MaFenetre::desactiverAllumAuto()
{


}

void MaFenetre::activerAllumAuto()
{

}
void MaFenetre::envoyerRequeteAllumerOuEteindreLumiR()//12-01
{
    QStringList rqt;
    rqt.append("demandeAllumerOuEteindreLumiR");
    rqt.append("#");
   m_clientTcp->envoyerMessage(rqt.join("#"));
}

void MaFenetre::envoyerRequeteActiVOueteindrePrise()
{
    QStringList rqt;
    rqt.append("demandeActiVOueteindrePrise");
    rqt.append("#");

   m_clientTcp->envoyerMessage(rqt.join("#"));
}

void MaFenetre::envoyerText(QString text)
{
    //m_ard0->envoyerText(text);
}

void MaFenetre::setRecepton(QString txtRecu)
{


    if(txtRecu=="/dev/ttyACM1:b")
        m_etindreAlrme="d";
    if(txtRecu=="/dev/ttyACM1:a")
    {
       //m_btActiverAllumAutomatque->setText("activer allumage automatisue");
        m_etatClignotement="d";
    }


    m_lumiereActvE=!m_lumiereActvE;
}


void MaFenetre::lireEspceLibre()
{
        QString commandLine ("df -h");
       QProcess process;
       process.start (commandLine);
       process.waitForFinished ();
       QString result;
       if (process.exitCode () == 0)
           result = process.readAllStandardOutput();
        result=result.split("\n").at(1);
        if(result.indexOf("M")==-1)
            m_peutDEspace="f";
        else
            m_peutDEspace="v";
}



//interaciviter avec le serveur
void MaFenetre::clientDonneesRecues(QString msg)
{
   // qDebug() << "DONNÉES DU SERVEUR " << msg << endl;
    QStringList rep=msg.split("#");
    QString type=rep.at(0);
    if(type=="lstDatesImportantesDuMois")//7-1-17
        lectureDesDatesImportantsDuMois(rep);
    if(type=="lstEvemenetDuJour")
        lectureDesEvenementsDuJour(rep);
    if(type=="lstEvenement")
        lectureDeToutLesEvenement(rep);
    if(type=="lstConfig")//11-01
        lectureDesConfig(rep);
    if(type=="debit")//11-01
        traiterDebit(rep);

}

void MaFenetre::connectionAuServeurReussit()
{
    activerToutLesAutresWidgets();
}

void MaFenetre::deconnectionDuServeur()
{
    desactiverToutLesAutresWidgets();
    desactiverLesWidgetsConfig();
}

void MaFenetre::chargerConfiguration()
{
    //envoyer requette au serveur qui demande tout les configuration
    QStringList rqt;
    rqt.append("demandeConfig");
    rqt.append("#");
    m_clientTcp->envoyerMessage(rqt.join("#"));
  // activerLesWidgetsConfig();//ne se pace pas ici, mais juste pour le teste
}

void  MaFenetre::envoyerRequeteDemanderDateImportantesDuMois(int anneE,int mois)
{
    QStringList rqt;
    m_moisPageCourant=mois;
    rqt.append("demandeDatesImportantesDuMois");
    rqt.append(QString::number(anneE));
    rqt.append(QString::number(mois));
    m_clientTcp->envoyerMessage(rqt.join("#"));
}
void  MaFenetre::mettreEnRequeteEnRetartDemanderDateImportantesDuMois()
{
    m_rqtEnRetard.append("demandeDatesImportantesDuMois");
    m_rqtEnRetard.append("17");
    m_rqtEnRetard.append("01");
    qDebug() << "rqt en retard"<< m_rqtEnRetard << endl;

}

void  MaFenetre::envoyerRequeteDemanderDateImportantesDuMois()
{
    envoyerRequeteDemanderDateImportantesDuMois(QDate::currentDate().toString("yyyy").toInt(),QDate::currentDate().toString("MM").toInt());
}

void MaFenetre::envoyerRequeteDemandeDesEvenementsDuJour(QDate date)
{
    m_dateCourrante=date;
    QStringList rqt;
    rqt.append("demandeEvenementsDuJour");
    rqt.append(m_dateCourrante.toString("yyyy-MM-dd"));
    m_clientTcp->envoyerMessage(rqt.join("#"));
}
void MaFenetre::envoyerRequeteDemanderToutLesEvements()//pour apres afficher la fenetre de gestion des évemenents
{
    QStringList rqt;
    rqt.append("demandeToutLesEvenements#");
    m_clientTcp->envoyerMessage(rqt.join("#"));
}

void MaFenetre::typeDebitChange(QString typeDebit)
{
    if(typeDebit=="debit client")
    {
        m_leDebitInterface->setEnabled(true);
    }
    else
    {
        m_leDebitInterface->setEnabled(false);
    }
    envoyerRequeteTypeDebit();
}
void MaFenetre::envoyerRequeteTypeDebit()
{
    QStringList rqt;
    rqt.append("typeDebit");
    rqt.append(m_cbTypeDebit->currentText());
    m_clientTcp->envoyerMessage(rqt.join("#"));
}
void MaFenetre::envoyerRequeteDebitEtRequeteEnRetard(QString debit)
{
    QStringList rqt;

    if(!m_rqtEnRetard.isEmpty())
    {
        rqt.append(m_rqtEnRetard);
        m_rqtEnRetard.clear();

    }
    else
    {
        rqt.append("debit");
        rqt.append(debit);
    }
    m_clientTcp->envoyerMessage(rqt.join("#"));

}



void MaFenetre::tempLireEtEnvoieDebit()
{
    /*if(prm)
    {*/
        if(m_cbTypeDebit->currentText()=="debit client")
        {

            //lecture du debit
            try
            {

                    //QString commandLine ("bwm-ng -I wlp0s29u1u3u3 -o html");
                  QString commandLine ("bwm-ng -I "+m_interface+" -o html");
                  QProcess process;
                  process.start (commandLine);
                  process.waitForFinished ();
                  QString result;
                  if (process.exitCode () == 0)
                      result = process.readAllStandardOutput();



                  QStringList lst(result.split("span"));
                     QString partieVitesse(lst.at(1));
                      partieVitesse=partieVitesse.split(" KB").at(0);
                      partieVitesse=partieVitesse.mid(22);
                      partieVitesse=partieVitesse.split(".").at(0);


                      int pui=1;
                      int vitesse=0;
                      vitesse =partieVitesse.at(partieVitesse.length()-1).digitValue();

                      for(int c=partieVitesse.length()-2;c!=0;c--)
                      {
                          if(partieVitesse.at(c).isNumber())
                          {
                              vitesse=vitesse + (partieVitesse.at(c).digitValue()* pow(10,pui));
                              pui++;
                          }
                      }



                          if(vitesse<1024)
                              m_debit= QString::number(vitesse)+"K";
                          else if(vitesse>=1024)
                          {
                              m_debit=QString::number(vitesse/1024.0);
                              m_debit=m_debit.split(".").at(0)+"."+m_debit.split(".").at(1).mid(0,2);//pour eviter d'afficher trop de chiffre, on ne prend que 2 chiffre apre la ","
                              m_debit+="M";
                          }
                        }
            catch( std::exception e)
            {
                //qDebug() << e << endl;
                m_debit="0K";
            }




                   // qDebug() << m_debit << endl;
            envoyerRequeteDebitEtRequeteEnRetard(m_debit);
            m_debitPrecedent=m_debit;

        }

}



