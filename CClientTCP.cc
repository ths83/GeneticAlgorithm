#include <iostream>
#include <iomanip>
#include <sstream>

#include "CClientTCP.h"

using namespace std;

CClientTCP::CClientTCP( std::string pIp, unsigned short pPort )
{
    #if defined (WIN32)
        WSADATA WSAData;
        mError = WSAStartup (MAKEWORD (2, 0), &WSAData);
    #else
        mError = 0;

    #endif

    mSock    =   socket( AF_INET, SOCK_STREAM, 0 );

    // connecte la socket
    connectClient( pIp, pPort );

}

CClientTCP::~CClientTCP( )
{
    #if defined (WIN32)
        WSACleanup ();
    #endif

}

void CClientTCP::connectClient()
{
    if(( mError = connect( mSock, (SOCKADDR *) &mSin, sizeof( mSin ))) < 0 )
    {
        cout << "Erreur lors de la connection au serveur : \n";
        cout << "Verifier l'adresse ip et le port, sinon verifier que le serveur est correctement lancé\n";
    }
}

void CClientTCP::connectClient( std::string pIp, unsigned short pPort )
{
    mSin.sin_addr.s_addr =   inet_addr( pIp.c_str() );
    mSin.sin_family      =   AF_INET;
    mSin.sin_port        =   htons( pPort );

    connectClient();
}

void CClientTCP::disconnect()
{
    closesocket( mSock );
}

void CClientTCP::sendQuery( string pQuery )
{
    if( mError = send( mSock, pQuery.c_str(), pQuery.size(), 0 ) < 0 )
    {
        cout << "Erreur lors de l'envoie de la socket au serveur\n";
    }
}

int CClientTCP::getLastError()
{
    return mError;
}

void CClientTCP::clear()
{
    ostringstream lStream;
    lStream << "10;";

    string lQuery = lStream.str();

    sendQuery( lQuery );
}

void CClientTCP::drawPoint( int pX, int pY, CColor pColor )
{
    ostringstream lStream;
    lStream << "20;" << pColor.getRed() << ";" << pColor.getGreen() << ";" <<  pColor.getBlue() << ";" << pX << ";" << pY << "\n";

    string lQuery = lStream.str();

    sendQuery( lQuery );
}

void CClientTCP::drawSegment( int pX1, int pY1, int pX2, int pY2, CColor pColor )
{
    ostringstream lStream;
    lStream << "30;" << pColor.getRed() << ";" << pColor.getGreen() << ";" <<  pColor.getBlue() << ";" << pX1 << ";" << pY1 << ";" << pX2 << ";" << pY2 << "\n";

    string lQuery = lStream.str();

    sendQuery( lQuery );
}

void CClientTCP::drawCircle( int pX, int pY, int pRadius, CColor pColor, bool pFull )
{
    ostringstream lStream;

    if( !pFull )
    {
        lStream << "40;";
    }
    else
    {
        lStream << "50;";
    }

    lStream << pColor.getRed() << ";" << pColor.getGreen() << ";" <<  pColor.getBlue() << ";" << pX << ";" << pY << ";" << pRadius << "\n";

    string lQuery = lStream.str();

    sendQuery( lQuery );
}

void CClientTCP::drawRectangle( int pX1, int pY1, int pX2, int pY2, CColor pColor, bool pFull )
{
    ostringstream lStream;

    if( !pFull )
    {
        lStream << "60;";
    }
    else
    {
        lStream << "70;";
    }

    lStream << pColor.getRed() << ";" << pColor.getGreen() << ";" <<  pColor.getBlue() << ";" << pX1 << ";" << pY1 << ";" << pX2 << ";" << pY2 << "\n";

    string lQuery = lStream.str();

    sendQuery( lQuery );
}

