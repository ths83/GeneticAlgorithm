#ifndef ____COLOR_H____
#define ____COLOR_H____


class CColor{
    
    private:
        unsigned char mRed;
        unsigned char mGreen;
        unsigned char mBlue;

    public:
        CColor();
        CColor( unsigned char pRed, unsigned char pGreen, unsigned char pBlue);
        void setColor( unsigned char pRed, unsigned char pGreen, unsigned char pBlue);

        // assesseur
        int getRed();
        int getGreen();
        int getBlue();

        // variable static par defaut
        static const CColor sRed;
        static const CColor sGreen;
        static const CColor sBlue;
        static const CColor sBlack;
        static const CColor sWhite;
        static const CColor sYellow;
        static const CColor sMagenta;
        static const CColor sCyan;
        
};


#endif
