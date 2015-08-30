#include "CColor.h"


const CColor CColor::sRed          =   CColor( 255, 0, 0 );
const CColor CColor::sGreen        =   CColor( 0, 255, 0 );
const CColor CColor::sBlue         =   CColor( 0, 0, 255 );
const CColor CColor::sBlack        =   CColor( 0, 0, 0 );
const CColor CColor::sWhite        =   CColor( 255, 255, 255 );
const CColor CColor::sYellow       =   CColor( 255, 255, 0 );
const CColor CColor::sMagenta      =   CColor( 255, 0, 255 );
const CColor CColor::sCyan         =   CColor( 0, 255, 255 );


CColor::CColor()
{
    mRed     =   0;
    mGreen   =   0;
    mBlue    =   0;
}

CColor::CColor( unsigned char pRed, unsigned char pGreen, unsigned char pBlue )
{
    mRed     =  pRed;
    mGreen   =     pGreen;
    mBlue    =     pBlue;
}

void CColor::setColor( unsigned char pRed, unsigned char pGreen, unsigned char pBlue )
{
    mRed     =  pRed;
    mGreen   =     pGreen;
    mBlue    =     pBlue;
}

int CColor::getRed()
{
    return mRed;
}

int CColor::getGreen()
{
    return mGreen;
}

int CColor::getBlue()
{
    return mBlue;
}
