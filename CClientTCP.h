#ifndef ____CLIENT_TCP____
#define ____CLIENT_TCP____


#if defined (WIN32)
    #include <winsock2.h>

#elif defined (linux)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>

    #define INVALID_SOCKET     ( -1 )
    #define SOCKET_ERROR     ( -1 )
    #define closesocket(s) close (s)

    typedef int                 SOCKET;
    typedef struct sockaddr_in  SOCKADDR_IN;
    typedef struct sockaddr     SOCKADDR;
#endif

#include <string>
#include "CColor.h"

class CClientTCP
{
    private :
        SOCKET          mSock;           // socket
        SOCKADDR_IN     mSin;            // structure d'information pour la socket
        int             mError;          // erreur de connection de la socket

        void connectClient();                                                                        // se connecte au serveur ( connect est pris )
        void sendQuery( std::string pQuery );                                                        // envoie le segment tcp contenant la chaine de caractere ( string ) (send est déjà pris)

    public :
        // CClientTCP();
        CClientTCP( std::string pIp, unsigned short pPort );

        ~CClientTCP();

        int getLastError();                                                                          // recupere l'erreur de connection

        void connectClient( std::string pIp, unsigned short pPort );                                 // se connecte au serveur
        void disconnect();                                                                           // se deconnecte du serveur

        void clear();                                                                                // efface l'ecran
        void drawPoint( int pX, int pY, CColor pColor  );                                            // affiche un point
        void drawSegment( int pX1, int pY1, int pX2, int pY2, CColor pColor );                       // affiche un segment
        void drawCircle( int pX, int pY, int pRadius, CColor pColor, bool pFull = false );           // affiche un cercle
        void drawRectangle( int pX1, int pY1, int pX2, int pY2, CColor pColor, bool pFull = false ); // affiche un rectangle
};


#endif
