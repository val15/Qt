#ifndef FENETRE0_H
#define FENETRE0_H

#include <QtWidgets>
#include <QTcpSocket>
#include "fenetregererCalendrier.h"
#include "fichier.h"
#include "maclandrier.h"
#include "rdv.h"
#include "clienttcpsocket.h"

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
Q_OBJECT
    public:
    MaFenetre();//constructeur par defaut
    void envoyerText(QString text);
    void lireConfigLocal();//config local
    void ecrirConfigLocal();




    void envoyerEtatAlrme();
    void desactiverAllumAuto();
    void activerAllumAuto();

    void envoyerMessageAuServeur(QString message);


    void envoyerRequeteDemandeDesEvenementsDuJour();//apeller apres l'ajout d'un evement

    void envoyerRequeteTypeDebit();
    void envoyerRequeteDebitEtRequeteEnRetard(QString debit);
    bool prm;






    private:

    void desactiverToutLesAutresWidgets();
    void activerToutLesAutresWidgets();
    void desactiverLesWidgetsConfig();
    void activerLesWidgetsConfig();

    void traiterDebit(QStringList rep);




    void actiVOuDesactiVVitesseFnc();

    //pour e wifi
    bool m_premierDemarage;//pour l'envoi ducoordonn�e par d�faut
    int m_C;


    //pour la connexion au serveur
    QGridLayout *m_layoutConnexion;
    QLabel *m_lbIp;
    QLabel *m_lbPort;
    QLineEdit *m_leAdressIpServeur;
    QLineEdit *m_lePort;
    QPushButton *m_btConnexion;
    QString m_adresseIpServeur;
    QString m_port;
    ClientTcpSocket *m_clientTcp;
    ClientTcpSocket *m_clientTcpDebit;




    QPushButton *m_btChargerConfiguration;
    bool m_configChargE;

    //pour l'horloge
    //QPushButton *m_bt_apropo;//on ceer un atribu de type QPushButton s'est un pointeur
    QLabel *m_lb_typeDebit;
    QComboBox *m_cbTypeDebit;
    QGridLayout *m_layoutDebit;
    QLineEdit *m_leDebitInterface;
    bool m_estDebitInterne;
    QTimer *m_timerDebit;
    QString m_interface;
    QString m_debitPrecedent;
    QString m_debit;
    QLabel *mLbDebitTitre;
    QLabel *mLbDebit;
    QGridLayout *mLayoutDebitAffiche;



    //pour les commades des �lement de la maison
    QGridLayout *m_layoutCommande;
    QCheckBox *m_chbAllumAutomatque;
    QTimeEdit *m_tieAllumAutomatque;
    QCheckBox *m_chbExtinctionAutomatque;
    QTimeEdit *m_tieExtinctionAutomatque;
    QPushButton *m_btPrise;

    //pour les leds
    QGridLayout *m_layoutLed;
    QPushButton *m_btLumiere;
    QPushButton *m_btClignote;
     QPushButton *m_btVitesse;
     QCheckBox *m_chbActiverAutoLedVitesse;
     bool m_activerAutoLedVitesse;
      QPushButton *m_btEspace;

      //pour le calandrier
     QGridLayout *m_layoutCalandrier;
     MaClandrier *m_cldr;
     QLabel *m_lbEvenementsDuJour;
     QList<Rdv *> m_listWidgetRdv;
     QPushButton *m_btAjouterEvenement;
     QDateEdit *m_deAjoutDate;
     QPushButton *m_btAjoutEnregister;
     QComboBox *m_cbTypeAjoutEvennemt;
     QTimeEdit *m_tieHeurAjoutEvennemt;
     QLineEdit *m_leAjoutEvenement;
     //pour afficher les rvd du jour
     QScrollArea *m_areaConteneurRvdDuJour;//pour avoir les crollbares
     QWidget *m_conteneurRvdDuJour;
     QGridLayout *m_layoutRdvDuJour;
     int comparerDeuxDate(QString d0,QString d1); //re�on en paramatre "MM-dd" return 1 si d0 est plus grand;-1 si d1 est plus grand et 0 si egale


     QGridLayout *m_layoutGenerale;











    bool m_estConnecter;
    bool m_clignotementEstActivE;
    bool m_ledVitesseEstActivE;
     bool m_ledEspaceEstActivE;
    bool m_allumAuto;

    bool m_lumiereActvE;
    bool m_priseActivE;



  //  QPushButton *m_pb_allumerEtindreLed;

    QDateTime *m_dateTempsActuel;


    //pour le reveil
    QGridLayout *m_layoutAlarme;
    QTimeEdit *m_tieSelectionReveille;
    QCheckBox *m_chbAlarme;
    QLabel *m_lbReveil;
    QPushButton *m_btEteindreAlarme;

   // QTimer *m_timerConnectionAutomatique;

    //element pour le fenetre calendrier
    QPushButton *m_btGereCalentdier;
    fenetregererCalendrier *m_fcl;
    QString m_evenementDuJour;
    QString m_evenementReste;
   /* QString m_evenement1;
    QString m_evenement2;
    QString m_evenement3;*/
    QStringList m_lstEvenementAEnvoyer;
    QString m_messageAEnvoyer;
    QString m_textAEnvoyer;
    int m_moisPageCourant;//ce variable est utile pour le lecture des dates important du mois
    QDate m_dateCourrante;//utilile pour la lecture des evenement de la date


    int m;
    int pas;
    QString m_chemin;
    QString m_modeDAffichage;
    QString m_etindreAlrme;
    QString m_etatClignotement;//a ou d
    QString m_etatVitesse;
    QString m_etatEspace;
    QString m_peutDEspace;



    //pour la config
    QString m_nomFichierDeConfig;
   // QString m_strConfig;//ce string contiedra les configuration
    QString m_heurReveil;
    QString m_etatReveil;
    QString m_heurAllumAutomatque;
    QString m_etatAllumAutomatque;
    QString m_heurExtictionAutomatque;
    QString m_etatExtictionAutomatque;

    //
    QStringList m_rqtEnRetard;//pour eviter le probleme de "premise et plus rien"








private slots:

    //pour le calandrier
     void lectureDesDatesImportantsDuMois(QStringList lstDate);
     void mettreEnRequeteEnRetartDemanderDateImportantesDuMois();//en envoi le requette apres avec le debit
     void envoyerRequeteDemanderDateImportantesDuMois(int anneE,int mois);
     void envoyerRequeteDemanderDateImportantesDuMois();//apeller apres l'ajout d'un evement
   // void lectureDesEvenementsDuJour(QDate date);
    void lectureDesEvenementsDuJour(QStringList lstEvt);
    void lectureDeToutLesEvenement(QStringList lstEvt);
     void envoyerRequeteDemandeDesEvenementsDuJour(QDate date);
    void ajouterEvenement();
    void selectionTypeEvenement(QString texte);
    void envoyerRequeteAjouterEnregister();

    void lectureDesConfig(QStringList lstConfig);//lecture des configes depuis le serveur

    //le slot automatique du bouton de connexion
    void connexion();


    void temp();



    //pour arduinoSerieHorlogeIneractif
    void envoyerRequeteDemanderToutLesEvements();//pour pouvoir gere le calandrier
   // void gererCalendrier(QStringList rep);
    void envoyerRequeteActiVOuDesactiVClignotement();
    void envoyerRequeteActiVOuDesactiVEspace();
    void setRecepton(QString txtRecu);
    void lireEspceLibre();
    void envoyerRequeteActiVOuDesactiVVitesse();
    void envoyerRequeteActiVOuDesactiVVitesseAuto();
    void  envoyerRequeteActiVOueteindrePrise();
     void envoyerRequeteAllumerOuEteindreLumiR();//ON ENVOI LA REQUETTE AU SERVEUR ET PUIS LE SERVEUR RÉENVOIS LES CONFIGURATIONS
    void envoyerRequeteEteindreAlarme();




    //
     void readData();

     //pour le serveur
    // void lancerServeur();
     void traiterMessagServeur(QString msg);
     void deconnectionClient();


     //pour le connexion avec le serveur
     void clientDonneesRecues(QString msg);
     void connectionAuServeurReussit();
     void deconnectionDuServeur();

     //pour la communication des configurations avec le serveur
     void envoyerEcrireConfig();
     void chargerConfiguration();


    void tempLireEtEnvoieDebit();//pour l'envoi du debit chaque seconde
    void typeDebitChange(QString typeDebit);




};



#endif // FENETRE0_H
