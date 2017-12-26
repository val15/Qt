#include "clienttcpsocket.h"
ClientTcpSocket::ClientTcpSocket(QString adresseIpServeur,QString port)
{
    m_adresseIpServeur=adresseIpServeur;
    m_port=port;
    m_socket=new QTcpSocket();
    m_tailleMessage = 0;
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(clientDonneesRecues()));
    connect(m_socket, SIGNAL(connected()), this, SLOT(connectE()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(deconnectE()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));

}


void ClientTcpSocket::connexionAuServeur()
{


        qDebug() << "Tentative de connexion en cours..." << endl;
        m_socket->abort(); // On desactive les connections precedente
        m_socket->connectToHost(m_adresseIpServeur, m_port.toInt()); // On se connecte au serveur

}

void ClientTcpSocket::connectE()//est appeller si la connexion a reussit
{
    qDebug() << ("Connexion reussie") << endl;
   // boutonConnexion->setEnabled(true);
     m_estConnecT=true;
    emit emmetreConnecE();
}

void ClientTcpSocket::deconnectE()//quand on se deconnecte
{
    qDebug() <<"Deconnection du serveur" << endl;
    m_estConnecT=false;
   // desactiverToutLesAutresWidgets();
    emit emmetreDeconnection();

}



void ClientTcpSocket::erreurSocket(QAbstractSocket::SocketError erreur)//en cas d'érreur
{
    switch(erreur)
    {
        case QAbstractSocket::HostNotFoundError:
            qDebug() << "ERREUR : le serveur n'a pas pu etre trouve. Verifiez l'IP et le port." << endl;
            break;
        case QAbstractSocket::ConnectionRefusedError:
            qDebug() << "ERREUR : le serveur a refuse la connexion. Verifiez si le programme \"serveur\" a bien ete lancer" << endl;
            break;
        case QAbstractSocket::RemoteHostClosedError:
            qDebug() << "ERREUR : le serveur a coupe la connexion." << endl;
            break;
        default:
            qDebug() << "ERREUR : " + m_socket->errorString() << endl;
    }

    m_estConnecT=false;
    emit emmetreDeconnection();
}

void ClientTcpSocket::clientDonneesRecues()
{
    // 1 : on reçoit un paquet (ou un sous-paquet) d'un des clients

    // On détermine quel client envoie le message (recherche du QTcpSocket du client)
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    // Si tout va bien, on continue : on récupère le message
    QDataStream in(socket);

    if (m_tailleMessage == 0) // Si on ne connaît pas encore la taille du message, on essaie de la récupérer
    {
        if (socket->bytesAvailable() < (int)sizeof(quint32)) // On n'a pas reçu la taille du message en entier
             return;

        in >> m_tailleMessage; // Si on a reçu la taille du message en entier, on la récupère
    }

    // Si on connaît la taille du message, on vérifie si on a reçu le message en entier
    if (socket->bytesAvailable() < m_tailleMessage) // Si on n'a pas encore tout reçu, on arrête la méthode
        return;


    // Si ces lignes s'exécutent, c'est qu'on a reçu tout le message : on peut le récupérer !
    QString message;
    in >> message;


    // 2 : on renvoie le message à tous les clients


    // 3 : remise de la taille du message à 0 pour permettre la réception des futurs messages
    m_tailleMessage = 0;

 //  qDebug() << "message recu :" +message << endl;
   emmetreMessageRecu(message);

}

void ClientTcpSocket::envoyerMessage(QString message)
{

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    // On prépare le paquet à envoyer
    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));
    m_socket->write(paquet); // On envoie le paquet
}

