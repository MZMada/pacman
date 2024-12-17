#include <iostream>
#include <iomanip>
#include "gridmanagement.h"

#include "type.h" //nos types


using namespace std;



void ClearScreen()
{
    cout << "\033[H\033[2J";
}// ClearScreen ()

void Color (const string & Col)
{
    cout << "\033[" << Col.c_str () <<"m";
} // Color ()


void DisplayGrid (const CMat & Mat, const CMyParam & Param){
    const unsigned KNbLine = Mat.size ();
    const unsigned KNbCol  = Mat[0].size ();
    cout << string (KNbCol + 2 , '-') << endl;
    for (unsigned i (0); i < KNbLine; ++i)
    {
        cout << '|';
        for (char c : Mat[i])
        {

            if(KEmpty == c){
                Color (KColor.find("KReset")->second);
                cout << c;
                Color (KColor.find("KReset")->second);
            }
            else if (Param.MapParamChar.find("TokenP1")->second == c){
                Color (Param.MapParamString.find("ColorP1")->second);
                cout << c;
                Color (KColor.find("KReset")->second);
            }
            else if (Param.MapParamChar.find("TokenP2")->second == c){
                Color (Param.MapParamString.find("ColorP2")->second);
                cout << c;
                Color (KColor.find("KReset")->second);
        }
        cout << '|' << endl;
    }
    cout << string (KNbCol + 2 , '-') << endl;
}// ShowMatrix ()


void InitGrid (CMat & Mat, const CMyParam & Param, CPosition & PosPlayer1, CPosition & PosPlayer2){
    unsigned Nbline (Param.MapParamUnsigned.find("NbLine")->second),
    NbColumn(Param.MapParamUnsigned.find("NbColumn")->second);
    Mat.resize (NbLine);
    const CVLine KLine (NbColumn, KEmpty);
    for (CVLine &ALine : Mat)
        ALine = KLine;

    PosPlayer1.first = 0;
    PosPlayer1.second = NbColumn - 1;
    Mat [PosPlayer1.first][PosPlayer1.second] = Param.MapParamChar.find("TokenP1")->second;
    PosPlayer2.first = NbLine - 1;
    PosPlayer2.second =0;
    Mat [PosPlayer2.first][PosPlayer2.second]   = Param.MapParamChar.find("TokenP2")->second;
}//InitMat ()
