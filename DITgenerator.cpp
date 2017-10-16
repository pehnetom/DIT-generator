//#include "PracticalSocket.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

using namespace std;

string fillInZeros(string a,int numVar){
    if((a.length() == 4 && numVar==5) || (a.length() == 3 && numVar==4) || (a.length() == 2 && numVar==3)){
        stream << "0" << a;
        a = stream.str();
    }else if((a.length() == 3 && numVar==5) || (a.length() == 2 && numVar==4) || (a.length() == 1 && numVar==3)){
        stream << "00" << a;
        a = stream.str();
    }else if((a.length() == 2 && numVar==5) || (a.length() == 1 && numVar==4)){
        stream << "000" << a;
        a = stream.str();
    }else if((a.length() == 1 && numVar==5)){
        stream << "0000" << a;
        a = stream.str();
    }

    return a;
}

string oneImplicant(int a,int numVar){
    stringstream stream;
    string numericImplicant = fillInZeros(convert(a,2),numVar);
    string temp;
    for(int i = 0;i<numericImplicant.length();i++){
        temp = numericImplicant.substr(i,1);
        
    }

}

string createImplicants(int mapa[],int numVar){




}

int highLimit(int a){
    int b = 500;

    if (a == 3 ) b = 20;
    if (a == 8) b = 1000;
    if (a == 9) b = 200;
    if (a == 16) b = 2000;
    if (a == 17) b= 200;

    return b;
}

int lowLimit(int a){
    int b = 1;

    if (a == 3 ) b = 20;
    if (a == 8) b = 1000;
    if (a == 9) b = 200;
    if (a == 16) b = 2000;
    if (a == 17) b= 200;

    return b;
}

string returnBase(int a){
    string b = "dvojkove";
    if (a == 8) b = "osmickove";
    if (a == 16) b = "sestnackove";
    return b;
}

string reverse(string a){
    string b;
    stringstream outStream;
    for(int i = 0; i < a.length();i++){
        outStream << a[a.length()-i-1];
    }
    b = outStream.str();
    return b;
}

char digit(int a){
    switch(a){
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
    }
}

string convertNum(int a,int b){
    string outputS = "";
    stringstream outStream;
    int rest,result=a;
    while(result!=0){
        rest = result % b;
        result = result / b;
        outStream << digit(rest);
    }
    outputS = outStream.str();
    return reverse(outputS);
}

void decToBase(int number,int base){
    cout << "## Prevedte z desítkové soustavy do " <<returnBase(base) << " soustavy." << endl;
    cout << endl;
    srand (time(NULL));
    int randNum;
    for(int i = 0;i < number;i++){
        randNum = rand() % highLimit(base) + 30;
        cout << "* "<< randNum << " (10) = " << convertNum(randNum,base) << " ("<< base <<")" << endl;

    }
}

void baseToDec(int number,int base){
    cout << "## Prevedte z " << returnBase(base) << " soustavy do desitkove soustavy." << endl;
    cout << endl;
    srand (time(NULL));
    int randNum;
    for(int i = 0;i < number;i++){
        randNum = rand() % highLimit(base) + 30;
        cout << "* " << convertNum(randNum,base) << " (" << base << ") = " << randNum << " (10)" << endl;

    }
}

void addition(int number,int base){
    cout << "## Sectete dve cisla z " << returnBase(base) <<" soustavy." << endl;
    cout << endl;
    srand (time(NULL));
    int randNum_1;
    int randNum_2;
    for(int i = 0; i < number ;i++){
        randNum_1 = rand() % highLimit(base) + 30;
        randNum_2 = rand() % highLimit(base) + 30;
        cout << "* " << convertNum(randNum_1,base) << "(" << base << ") + " << convertNum(randNum_2,base) << "(" << base << ") = " << convertNum(randNum_1+randNum_2,base) << " -> [ " << randNum_1 << " + " << randNum_2 <<  " = " << (randNum_1+randNum_2) <<" ]" << endl;

    }
}

void subtraction(int number,int base){
    cout << "## Odectete dvojici čisel z " << base <<" soustavy." << endl;
    cout << endl;
    srand (time(NULL));
    int randNum_1;
    int randNum_2;
    for(int i = 0; i < number ;i++){
        randNum_1 = rand() % highLimit(base) + 30;
        randNum_2 = rand() % highLimit(base) + 30;
        cout << "* " << convertNum(max(randNum_1,randNum_2),base) << "(" << base << ") - " << convertNum(min(randNum_1,randNum_2),base) << "(" << base << ") = " << convertNum(abs(randNum_1-randNum_2),base) << " -> [ " << max(randNum_1,randNum_2) << " - " << min(randNum_1,randNum_2) <<  " = " << abs(randNum_1-randNum_2) <<" ]" << endl;

    }
}

void multiplication(int number,int base){
    cout << "## Vynasobte dvojici cisel z " << base <<" soustavy." << endl;
    srand (time(NULL));
    int randNum_1;
    int randNum_2;
    for(int i = 0; i < number ;i++){
        randNum_1 = rand() % highLimit(base) + 30;
        randNum_2 = rand() % highLimit(base+1) + 1;
        while(randNum_2<3) randNum_2 = rand() % highLimit(base+1) + 1;
        cout << "* " << convertNum(randNum_1,base) << "(" << base << ") x " << convertNum(randNum_2,base) << "(" << base << ") = " << convertNum(randNum_1*randNum_2,base) << " -> [ " << randNum_1 << " x " << randNum_2 <<  " = " << (randNum_1*randNum_2) <<" ]" << endl;

    }
}

string disp(int a,int form){
    string temp;

    if(form == 1){
        if(a == 1) return "1";
        else return " ";
    }else{
        if(a==1) return " ";
        else return "0";
    }
}


void printKMap(int numVar,int map[],int formDisp){
    int m = 1,n = 1;
    switch(numVar){
        case 3:
        cout <<"          ----b----" << endl;
        cout <<"      ----a----    " << endl;
        cout <<"  +---+---+---+---+" << "\r\n";
        cout <<"  | "<< disp(map[0],formDisp) << " | "<< disp(map[1],formDisp) << " | "<< disp(map[3],formDisp) << " | "<< disp(map[2],formDisp) << " |" << "\r\n";
        cout <<"| +---+---+---+---+" << "\r\n";
        cout <<"c | "<< disp(map[4],formDisp) << " | "<< disp(map[5],formDisp) << " | "<< disp(map[7],formDisp) << " | "<< disp(map[6],formDisp) << " |" << "\r\n";
        cout <<"| +---+---+---+---+" << "\r\n" << endl;
        break;
        case 4:
        cout <<"            ----b---" << endl;
        cout <<"       ----a----    " << endl;
        cout <<"   +---+---+---+---+" << "\r\n";
        cout <<"   | "<< disp(map[0],formDisp) << " | "<< disp(map[1],formDisp) << " | "<< disp(map[3],formDisp) << " | "<< disp(map[2],formDisp) << " |" << "\r\n";
        cout <<" | +---+---+---+---+" << "\r\n";
        cout <<" | | "<< disp(map[4],formDisp) << " | "<< disp(map[5],formDisp) << " | "<< disp(map[7],formDisp) << " | "<< disp(map[6],formDisp) << " |" << "\r\n";
        cout <<"|c +---+---+---+---+" << "\r\n";
        cout <<"|| | "<< disp(map[12],formDisp) << " | "<< disp(map[13],formDisp) << " | "<< disp(map[15],formDisp) << " | "<< disp(map[14],formDisp) << " |" << "\r\n";
        cout <<"d| +---+---+---+---+" << "\r\n";
        cout <<"|  | "<< disp(map[8],formDisp) << " | "<< disp(map[9],formDisp) << " | "<< disp(map[11],formDisp) << " | "<< disp(map[10],formDisp) << " |" << "\r\n";
        cout <<"|  +---+---+---+---+" << "\r\n" << endl;
        break;
        case 5:
        cout <<"                   ---------c-------" <<endl;
        cout <<"           ----------b------        " << endl;
        cout <<"       ----a----       ----a----    " << endl;
        cout <<"   +---+---+---+---+---+---+---+---+" << "\r\n";
        cout <<"   | "<< disp(map[0],formDisp) << " | "<< disp(map[1],formDisp) << " | "<< disp(map[3],formDisp) << " | "<< disp(map[2],formDisp);
        cout <<" | "<< disp(map[6],formDisp) << " | "<< disp(map[7],formDisp) << " | "<< disp(map[5],formDisp) << " | "<< disp(map[4],formDisp) << " |" << "\r\n";
        cout <<" | +---+---+---+---+---+---+---+---+" << "\r\n";
        cout <<" | | "<< disp(map[8],formDisp) << " | "<< disp(map[9],formDisp) << " | "<< disp(map[11],formDisp) << " | "<< disp(map[10],formDisp);
        cout <<" | "<< disp(map[14],formDisp) << " | "<< disp(map[15],formDisp) << " | "<< disp(map[13],formDisp) << " | "<< disp(map[12],formDisp) << " |" << "\r\n";
        cout <<"|d +---+---+---+---+---+---+---+---+" << "\r\n";
        cout <<"|| | "<< disp(map[24],formDisp) << " | "<< disp(map[25],formDisp) << " | "<< disp(map[27],formDisp) << " | "<< disp(map[26],formDisp)
        ;cout <<" | "<< disp(map[30],formDisp) << " | "<< disp(map[31],formDisp) << " | "<< disp(map[29],formDisp) << " | "<< disp(map[28],formDisp) << " |" << "\r\n";
        cout <<"e| +---+---+---+---+---+---+---+---+" << "\r\n";
        cout <<"|  | "<< disp(map[16],formDisp) << " | "<< disp(map[17],formDisp) << " | "<< disp(map[19],formDisp) << " | "<< disp(map[18],formDisp);
        cout <<" | "<< disp(map[22],formDisp) << " | "<< disp(map[23],formDisp) << " | "<< disp(map[21],formDisp) << " | "<< disp(map[20],formDisp) << " |" << "\r\n";
        cout <<"|  +---+---+---+---+---+---+---+---+" << "\r\n";
        break;
        default:break;
    }


}

void printOnlyDef(string file){
    ifstream fileStr(file);
    string line;
    int a;
    if(fileStr.is_open()){
        while(getline(fileStr,line)){
            a = line.find("=");
            if (a > 0){
                cout << line.substr(0,a+1) << endl;
            }else{
                cout << line << endl;
            }
        }
    }
}

string funcToString(int numVar,int mapa[]){
    stringstream mapaStream;
    int mapLength;
    if(numVar==5){
        mapLength = 32;
    }else if(numVar==4){
        mapLength = 16;
    }else{
        mapLength = 8;
    }

    mapaStream << "f=";
    for(int i = 0;i<mapLength;i++){
        mapaStream << "(" << mapa[i] <<")";
        if(i<(mapLength-1)){
            mapaStream <<",";
        }
    }
    return mapaStream.str();
}

int* generateMap(int numVar,int mapa[]){
  int maxNumOfImp = 0,numOfImp,maxVar,k=0,imp;
  if (numVar == 5){
    maxNumOfImp = 20;
    maxVar = 32;
  }else if(numVar == 4){
    maxNumOfImp = 10;
    maxVar = 16;
  }else{
    numVar = 3;
    maxNumOfImp = 5;
    maxVar = 8;
  }

  srand (time(NULL));
  numOfImp = rand() % (maxNumOfImp-3) + 3;
  while(k<numOfImp){
    imp = rand() % maxVar + 0;
    if(mapa[imp]==0){
      mapa[imp] = 1;
      k++;
    }
  }

  return mapa;
}

void solverKMap(int numVar){
    int * mapa;
    mapa = new int [8];
    if (numVar == 5){
      mapa = new int [32];
    }else if(numVar == 4){
      mapa = new int [16];
    }
    mapa = generateMap(numVar,mapa);
    cout << funcToString(numVar,mapa) << endl;
    printKMap(numVar,mapa,1);
}


int main(int argc, char* argv[]) {
    int prikaz = 0;
    int number = 1;
    string file;

    if (argc > 1){
        prikaz = atol(argv[1]);
    }
    if(argc > 2){
        if( prikaz == 16){
            file = argv[2];
        }else{
            number = atol(argv[2]);
        }
    }

    switch(prikaz){
        case  1: decToBase(number,2);break;
        case  2: decToBase(number,8);break;
        case  3: decToBase(number,16);break;
        case  4: baseToDec(number,2);break;
        case  5: baseToDec(number,8);break;
        case  6: baseToDec(number,16);break;
        case  7: addition(number,2);break;
        case  8: addition(number,8);break;
        case  9: addition(number,16);break;
        case 10: subtraction(number,2);break;
        case 11: subtraction(number,8);break;
        case 12: subtraction(number,16);break;
        case 13: multiplication(number,2);break;
        case 14: multiplication(number,8);break;
        case 15: multiplication(number,16);break;
        case 16: printOnlyDef(file);break;
        case 17: solverKMap(number);break;
        default: break;
    }

    cout << endl;
    return 0;
}
