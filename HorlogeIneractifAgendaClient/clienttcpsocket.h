/*
 Auteur : val15
 Date De Creation : 06/01/17

Role :
client tcp

 */


#ifndef CLIENTTCPSOCKET_H
#define CLIENTTCPSOCKET_H
#include <QtWidgets>
#include <QTcpSocket>

class ClientTcpSocket : public QWidget
{
    Q_OBJECT
public :
    ClientTcpSocket(QString adresseIpServeur,QString port);
    void envoyerMessage(QString message);
    void connexionAuServeur();

protected:


private:
    QTcpSocket *m_socket; // pour communiquer avec le serveur

    bool m_estConnecT;
    int m_tailleMessage;
    QString m_adresseIpServeur;
    QString m_port;

private slots:
    //pour le connexion avec le serveur
    void clientDonneesRecues();
    void connectE();//slot appeller lors de la connection
    void deconnectE();//slot appeller lors de la deconnection
    void erreurSocket(QAbstractSocket::SocketError erreur);
signals:
    void emmetreMessageRecu(QString message);
    void emmetreConnecE();
    void emmetreDeconnection();



};

#endif //CLIENTTCPSOCKET_H
