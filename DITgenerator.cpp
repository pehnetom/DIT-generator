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
#include <math.h>

using namespace std;

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

stringstream reverseOutStream("");

string reverse(string a){
    string b = "";
    // stringstream outStream = reverseOutStream;
    reverseOutStream.str("");
    for(int i = 0; i < a.length();i++){
        reverseOutStream << a.substr(a.length()-i-1,1);
        // outStream << a[a.length()-i-1];
    }
    try{
        b = reverseOutStream.str();
    }catch(...){
        cout << "Exception!!! : Error in function reverse, when trying to convert stringstream to string...." << endl;
    }
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


stringstream convOutStream;

string convertNum(int a,int b){
    string outputS = "";
    string retVal = ""; 
    convOutStream.str("");
    int rest,result=a;
    while(result!=0){
        rest = result % b;
        result = result / b;
        convOutStream << digit(rest);
    }
    outputS = convOutStream.str();
    retVal = reverse(outputS); 
    return retVal;
}

void decToBase(int number,int base){
    cout << "## Prevedte z desítkové soustavy do " <<returnBase(base) << " soustavy." << endl;
    cout << endl;
    int randNum;
    for(int i = 0;i < number;i++){
        randNum = rand() % highLimit(base) + 30;
        cout << "* "<< randNum << " (10) = " << convertNum(randNum,base) << " ("<< base <<")" << endl;

    }
}

void baseToDec(int number,int base){
    cout << "## Prevedte z " << returnBase(base) << " soustavy do desitkove soustavy." << endl;
    cout << endl;
    int randNum;
    for(int i = 0;i < number;i++){
        randNum = rand() % highLimit(base) + 30;
        cout << "* " << convertNum(randNum,base) << " (" << base << ") = " << randNum << " (10)" << endl;

    }
}

void addition(int number,int base){
    cout << "## Sectete dve cisla z " << returnBase(base) <<" soustavy." << endl;
    cout << endl;
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
    int randNum_1;
    int randNum_2;
    for(int i = 0; i < number ;i++){
        randNum_1 = rand() % highLimit(base) + 30;
        randNum_2 = rand() % highLimit(base) + 30;
        cout << "* " << convertNum(fmax(randNum_1,randNum_2),base) << "(" << base << ") - " << convertNum(fmin(randNum_1,randNum_2),base) << "(" << base << ") = " << convertNum(abs(randNum_1-randNum_2),base) << " -> [ " << max(randNum_1,randNum_2) << " - " << min(randNum_1,randNum_2) <<  " = " << abs(randNum_1-randNum_2) <<" ]" << endl;

    }
}

void multiplication(int number,int base){
    cout << "## Vynasobte dvojici cisel z " << base <<" soustavy." << endl;
    int randNum_1;
    int randNum_2;
    for(int i = 0; i < number ;i++){
        randNum_1 = rand() % highLimit(base) + 30;
        randNum_2 = rand() % highLimit(base+1) + 1;
        while(randNum_2<3) randNum_2 = rand() % highLimit(base+1) + 1;
        cout << "* " << convertNum(randNum_1,base) << "(" << base << ") x " << convertNum(randNum_2,base) << "(" << base << ") = " << convertNum(randNum_1*randNum_2,base) << " -> [ " << randNum_1 << " x " << randNum_2 <<  " = " << (randNum_1*randNum_2) <<" ]" << endl;

    }
}

stringstream streamFillZeros;

string fillInZeros(string a,int numVar){
    streamFillZeros.str("");
    if((a.length() == 4 && numVar==5) || (a.length() == 3 && numVar==4) || (a.length() == 2 && numVar==3)){
        streamFillZeros << "0" << a;
    }else if((a.length() == 3 && numVar==5) || (a.length() == 2 && numVar==4) || (a.length() == 1 && numVar==3)){
        streamFillZeros << "00" << a;
    }else if((a.length() == 2 && numVar==5) || (a.length() == 1 && numVar==4)){
        streamFillZeros << "000" << a;
    }else if((a.length() == 1 && numVar==5)){
        streamFillZeros << "0000" << a;
        
    }else{
        streamFillZeros << a;
    }
    a = streamFillZeros.str();
    return a;
}

string oneImplicant(int a,int numVar){
    string k = "0";
    if(a>0){
        k = convertNum(a,2);
    }
    string numericImplicant = fillInZeros(k,numVar);
    return numericImplicant;
}


stringstream streamCrImpl;

string createImplicants(int mapa[],int numVar,int form){
    int k = pow (2, numVar);
    int l = 0,m = 0;
    streamCrImpl.str("");
    for(int i = 0;i < k;i++){
        try{
            l = mapa[i];
        }catch(...){
            cout << "Error reading from memory in createImplicants " << endl;
        }
        if (l == form){
            if(m == 1){
                streamCrImpl << "+";
            }
            streamCrImpl << oneImplicant(i,numVar);
            m = 1;
        }
    }

    return streamCrImpl.str();
}


stringstream streamImpInde;

string implicantIndex(int mapa[],int numVar,int form){
    int k = pow (2, numVar);
    int l = 0,m = 0;
    streamImpInde.str("");
    for(int i = 0;i < k;i++){
        try{
            l = mapa[i];
        }catch(...){
            cout << "Error reading from memory in createImplicants " << endl;
        }
        if (l == form){
            if(m == 1){
                streamImpInde << "+";
            }

            streamImpInde << i;
            m = 1;
        }
    }

    return streamImpInde.str();
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

stringstream mapaStream("");

string funcToString(int numVar,int mapa[],int form){
    mapaStream.str("");
    string temp;
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
        if(mapa[i]==form){   
            mapaStream <<  i << ",";
        }
    }
    temp = mapaStream.str();
    return temp.substr(0,temp.length()-1);
}

string generateImplicants(int numVar){
    int maxRand = 0;
    if (numVar == 5) {
        maxRand = 39;
    }else if(numVar == 4){
        maxRand = 17;
    }else{
        maxRand = 6;
    }
    int randNum = rand() % maxRand + 0;
    // cout << randNum << endl;
    // cout << maxRand << endl;
    // cout << numVar << endl;
    string retVal="xxxxxxxx";
    switch(randNum){
        case  0: retVal = "00010504";break;
        case  1: retVal = "03020607";break;
        case  2: retVal = "01030507";break;
        case  3: retVal = "00020406";break;
        case  4: retVal = "00010302";break;
        case  5: retVal = "04050706";break;// 8
        case  6: retVal = "00010809";break;
        case  7: retVal = "05071315";break;
        case  8: retVal = "03021110";break;
        case  9: retVal = "06071415";break;
        case 10: retVal = "04051312";break;
        case 11: retVal = "13150911";break;
        case 12: retVal = "04061214";break;
        case 13: retVal = "00010504";break;
        case 14: retVal = "12081410";break;
        case 15: retVal = "11101415";break;
        case 16: retVal = "08091312";break;//16
        case 17: retVal = "12132829";break;
        case 18: retVal = "20212829";break;
        case 19: retVal = "14153031";break;
        case 20: retVal = "11102726";break;
        case 21: retVal = "08092425";break;
        case 22: retVal = "19182223";break;
        case 23: retVal = "27264041";break;
        case 24: retVal = "16172021";break;
        case 25: retVal = "24252928";break;
        case 26: retVal = "31302223";break;
        case 27: retVal = "27261918";break;
        case 29: retVal = "00082416";break;
        case 30: retVal = "11271531";break;
        case 31: retVal = "00010504";break;
        case 32: retVal = "09251329";break;
        case 33: retVal = "08241228";break;
        case 34: retVal = "02061822";break;
        case 35: retVal = "03071923";break;
        case 36: retVal = "01051721";break;
        case 37: retVal = "00041620";break;
        case 38: retVal = "16172425";break;//32
        default: retVal = "00010504";break;
    }

    return retVal;
}

const int numOfDigits = 2;
const int testMapa1[]={1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0};

int* generateMap(int numVar,int mapa[], int method){
  int maxNumOfImp = 0,numOfImp,maxVar,k=0,imp;
  string implicants;
  if (numVar == 5){
    maxNumOfImp = 20;
    maxVar = 32;
  }else if(numVar == 4){
    maxNumOfImp = 8;
    maxVar = 16;
  }else{
    numVar = 3;
    maxNumOfImp = 5;
    maxVar = 8;
  }
  numOfImp = rand() % (maxNumOfImp-3) + 3;
  
    if( method == 2 ){
        for (int i = 0; i < maxVar;i++){
            mapa[i] = testMapa1[i];
        }
    }else  if( method == 1){
        if (numVar == 5){
            maxNumOfImp = 10;
        }else if(numVar == 4){
            maxNumOfImp = 5;
        }else{
            maxNumOfImp = 2; 
        }
        while(k<numOfImp){
            implicants = generateImplicants(numVar);
            // cout << implicants << endl;
            for(int i=0;i < (implicants.length()/2);i++){
                // cout << i << " " << i*(numOfDigits) << " " << implicants.length() << " " << implicants.substr(i*(numOfDigits),numOfDigits) << endl;
                try{
                    imp = stoi(implicants.substr(i*(numOfDigits),numOfDigits));
                    // cout << imp <<endl;;
                    // imp = 1;
                }
                catch(...){
                    cout << "Error in function generateMap, Method 1, conversion from string to int..." << endl;
                    return mapa;
                }
                // cout << imp <<  " " << implicants.substr(i*(numOfDigits),numOfDigits) << endl;
                if(mapa[imp]==0){
                    mapa[imp] = 1;
                    
                }
            }
            k++;
        }
  }
  else  {
    while(k<numOfImp){
        imp = rand() % maxVar + 0;
        if(mapa[imp]==0){
            mapa[imp] = 1;
            k++;
        }
    }
  }
  return mapa;
}

int countImplicants(string implicants){
    int a = 0;
    int k = 1;
    string temp = implicants;
    // cout << temp << endl;
    // cout << "Found +: " << temp.find("+") << endl; 
    while( temp.find("+")!=-1){
        // cout << k <<endl;
        a = temp.find("+");
        if(a==-1){
            break;
        }else{
            // cout << temp << "----->";
            temp = temp.substr(a+1,temp.length()-a+1);
            k++;
        }
    }   
    return k;
}

int compareImplicants(string a,string b){
    int countOfConform = 0;
    int answer = 0;
    int limitOfComformity = a.length()-1;
    char c,d;
    for (int i=0; i < a.length();i++){
        c = a[i];
        d = b[i];
        if(( c== d)){
            countOfConform ++;
        }
    }
    if(countOfConform==(limitOfComformity)){
        answer = 1;
    }
    return answer;
}

stringstream streamS;
string combineImplicants(string a,string b){
    streamS.str("");
    for (int i=0; i < a.length();i++){
        //cout << a.substr(i,1) <<  " + " << b.substr(i,1) << (a.substr(i,1).compare(b.substr(i,1))) << endl;
        if(( a.substr(i,1).compare(b.substr(i,1)) == 0) && (a.substr(i,1).compare("2") != 0)){
            streamS << a[i];
        }else{
            streamS << 2;
        }
    }
    return streamS.str();
}

stringstream output_impl,output_index;

string eradicateDuplicates(string index,string implicants,int numOfImplicants,int numVar){
    string result_index,remains_index,result_index_i,remains_index_i;
    string result_impl,remains_impl,result_impl_i,remains_impl_i;;

    int * unique = new int[numOfImplicants];
    int * implicantsInt = new int[numOfImplicants];
    
    int c,d,e;
    output_impl.str("");
    output_index.str("");
    int found=0,conformity;
    for(int i = 0;i < numOfImplicants;i++){
        implicantsInt[i] = 333;
        unique[i] = 0;
    }
    //cout<< "nulovani" <<endl;
    //cout <<index << "   " << implicants <<endl;
    for(int j = 0; j < numOfImplicants;j++){
        if(j==0){
            d = implicants.find("+");
            e = index.find("+");
            result_index = index.substr(0,e);
            remains_index = index.substr(e+1,index.length()-1);
            result_impl = implicants.substr(0,d);
            remains_impl = implicants.substr(d+1,implicants.length()-1);
            //cout << remains_index <<endl;
        }else if( j == numOfImplicants-1){
            result_impl=remains_impl;
            result_index = remains_index;
            //cout << remains_index << endl;
        }else{
            d = remains_impl.find("+");
            e = remains_index.find("+");
            result_index = remains_index.substr(0,e);
            remains_index = remains_index.substr(e+1,index.length()-1);
            result_impl = remains_impl.substr(0,d);
            remains_impl = remains_impl.substr(d+1,implicants.length()-1);
            //cout << remains_index <<endl;
        }
        try{
        c = stoi(result_impl);
        }catch(...){
            cout << "Erorr on line 515 function eradicateDuplicates. string: " << result_impl << implicants << index << endl;
        }
        //cout << c << "->" << result_impl << endl;
        for(int i=0;i<numOfImplicants;i++){
            //cout << c << "==" << implicantsInt[i] << "?  ";
            if(c==implicantsInt[i] && i!=j ){
                //cout << unique[j] << "  " << result_impl << endl; 
                unique[j] = unique[j] + 1;
            }
        }
        //cout << unique[j] << endl;
        if(unique[j] == 0){
            implicantsInt[j] = c;
            output_impl << result_impl << "+";
            output_index << result_index << "+";
            //cout << result_index << endl;
        }
    }
    
    //cout << output_impl.str() << endl;
    //cout << output_index.str() << endl;

    output_impl << ";" << output_index.str();
    return output_impl.str();
}


stringstream outputIndexes;
string combineIndexes(string a, string b, string implicants, string index,int numOfImplicants,int numVar){
    outputIndexes.str("");
    string result,temp,remains;
    int c,d;
    int first = implicants.find(a)/(numVar+1);
    int second = 0,found=0;
    if(b.compare("none")!=0){
        second=implicants.find(b)/(numVar+1);
    }
    for(int i = 0; i < numOfImplicants;i++){
        if(i==0){
            c = index.find("+");
            // if(c!=-1){
            result = index.substr(0,c);
            remains = index.substr(c+1,index.length()-1);
            // }else{
            //result = remains;
            // }
        }else if( i == numOfImplicants-1){
            result=remains;
        }else{
            c = remains.find("+");
            // if(c!=-1){
            result = remains.substr(0,c);
            remains =remains.substr(c+1,index.length()-1);
            // }else{
            //result = remains;
            // }
        }
        if(i == first || (i == second && b.compare("none")!=0)){
            if(found>0){
                outputIndexes << ",";
            }
            outputIndexes << result;
            found++;
        }
        
    }


    return outputIndexes.str();
}

int * findPoints(int numOfImplicants,int table[],string index){
    string result,remains;
    int c,d;
    for(int i = 0; i < numOfImplicants;i++){
        if(i==0){
            c = index.find("+");
            result = index.substr(0,c);
            remains = index.substr(c+1,index.length()-1);

        }else if( i == numOfImplicants-1){
            result=remains;
        }else{
            c = remains.find("+");
            result = remains.substr(0,c);
            remains =remains.substr(c+1,index.length()-1);
        }
        try{
            table[i] = stoi(result);
        } catch(...){
            cout << "Error on line 598, in function findPoints. String:" << result << " " << remains << endl;
        }
    }

    return table;
}

int findCoverage(int a,int b,string index,int table[],int numOfImplicants){
    string result,remains,temp;
    int count = 0;
     int c,d,e;
     for(int i = 0; i < numOfImplicants;i++){
         if(i==0){
             c = index.find("+");
             result = index.substr(0,c);
             remains = index.substr(c+1,index.length()-1);
         }else if( i == numOfImplicants-1){
             result=remains;
         }else{
             c = remains.find("+");
             result = remains.substr(0,c);
             remains =remains.substr(c+1,index.length()-1);
         }
         if(i==b){
             temp = result;
             break;
         }
    }
    do{
        d = temp.find(",");
        if(d==-1){
            try{
                if(temp.length()==0) break;
                e = stoi(temp);
            }catch(...){
                cout << "Exception! on 546 with string: " << temp.substr(0,d)<< endl;
            }
        }else{
            try{
                e = stoi(temp.substr(0,d));
            }catch(...){
                cout << "Exception! on 551 with string: " << temp.substr(0,d)<< endl;
            }
            temp = temp.substr(d+1,temp.length()-d-1);
        }
        if(e==table[a]){
            count ++;
        }
    }while( d!=-1);

     
     return count;
}

int sumOfSums(int table[],int length){
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum = sum + table[i];
    }
    return sum;
}

stringstream outputPaVaCon;
string parseVarStringCon(string a){
    outputPaVaCon.str("");
    int value;
    string temp,symbol,retVal;
    temp = reverse(a);
    for(int i = 0; i < temp.length();i++){
        value = temp[i] - '0';
        switch(i){
            case 0: symbol = "a";break;
            case 1: symbol = "b";break;
            case 2: symbol = "c";break;
            case 3: symbol = "d";break;
            case 4: symbol = "e";break;
            default: symbol = "x";break;
        }
        if(value == 0){
            outputPaVaCon << symbol << "+";
        }else if(value == 1){
            outputPaVaCon<< "non(" << symbol << ")"<< "+";
        }
    }
    retVal = outputPaVaCon.str();
    return retVal.substr(0,retVal.length()-1);
}

stringstream outputPaVaDis;
string parseVarStringDis(string a){
    outputPaVaDis.str("");
    int value;
    string temp,symbol;
    temp = reverse(a);
    for(int i = 0; i < temp.length();i++){
        value = temp[i] - '0';
        switch(i){
            case 0: symbol = "a";break;
            case 1: symbol = "b";break;
            case 2: symbol = "c";break;
            case 3: symbol = "d";break;
            case 4: symbol = "e";break;
            default: symbol = "x";break;
        }
        if(value == 1){
            outputPaVaDis << symbol;
        }else if(value == 0){
            outputPaVaDis<< "non(" << symbol << ")";
        }
    }
    return outputPaVaDis.str();
}

stringstream outputP;
string parseOutput(string func,int numVar,int form){
    int lengthOfFunc = func.length()/(numVar+1);
    string temp = func.substr(0,func.length()-1);
    outputP.str("");
    
    if(form == 1){
        for(int i = 0;i<lengthOfFunc;i++){
            outputP << "(";
            outputP << parseVarStringDis(temp.substr(i*(numVar+1),numVar));
            outputP << ")";
            if(i<lengthOfFunc-1){
                outputP << " + ";
            }
        }   
    }else{
        for(int i = 0;i<lengthOfFunc;i++){
            outputP << "(";
            outputP << parseVarStringCon(temp.substr(i*(numVar+1),numVar));
            outputP << ")";
            if(i<lengthOfFunc-1){
                outputP << " * ";
            }
        }   
    } 
    return outputP.str();
}
stringstream newImplicants,newIndexes;
stringstream minimizedFunc;

string QuineMcCluskey(string implicants,string index,int numVar,int form){
    
    int k=0,l=0,m=0,n=0,lastCountOfImplicants=0;
    int comparation=0;
    int found = 0;
    newImplicants.str("");
    minimizedFunc.str("");
    newIndexes.str("");
    string eredication;
    string a,b;
    int basicNumberOfImplicants = countImplicants(implicants);
    int * implicantTable = new int [basicNumberOfImplicants];
    // cout << index << " "  << implicants << endl;
    implicantTable = findPoints(basicNumberOfImplicants,implicantTable,index);
    while(1){
        newImplicants.str("");
        newIndexes.str("");
        k++;
        // cout << "Round: " << k << endl;
        // cout << "Implikanty: " << implicants << endl;
        // cout << "Indexy: " << index << endl;
        l = countImplicants(implicants);
        m = 0;
        // cout << "Number of Implicants: " << l << endl;
        for(int i = 0; i < l;i++){
            found = 0;
            a = implicants.substr(i*(numVar+1),numVar);
            for(int j = 0; j< l;j++){
                b = implicants.substr(j*(numVar+1),numVar);
                if(i!=j){
                    comparation = compareImplicants(a,b);
                    if(comparation == 1){
                        if(m==1){
                            newImplicants << "+";
                            newIndexes << "+";
                        }
                        newImplicants << combineImplicants(a,b);
                        m=1;
                        found = 1;
                        newIndexes << combineIndexes(a,b,implicants,index,l,numVar);
                    }
                }
            }
            
            if(found==0){
                if(m==1){
                    newImplicants << "+";
                    newIndexes << "+";
                }
                m=1;
                newImplicants << a;
                newIndexes << combineIndexes(a,"none",implicants,index,l,numVar);
            }
            // cout << newImplicants.str() << endl;
            // cout << newIndexes.str() << endl;
        }
        // cout << newImplicants.str() << endl;
        // cout << newIndexes.str() << endl;
        eredication = eradicateDuplicates(newIndexes.str(),newImplicants.str(),countImplicants(newImplicants.str()),numVar);
        n=eredication.find(";");
        // cout << "END Implicants: " << eredication.substr(0,n-1) << "\r\nEND Indexes: "<< eredication.substr(n+1,eredication.length()-n-2) << endl;
        
        implicants = eredication.substr(0,n-1);
        index = eredication.substr(n+1,eredication.length()-n-2);
        // cout << implicants << endl;
        // cout << index << endl;
        l = countImplicants(implicants);
        
        if(lastCountOfImplicants == l){
            break;
        }else{
            lastCountOfImplicants = l;
        }
    }


    int rows = lastCountOfImplicants;
    int columns = basicNumberOfImplicants;

    int * sumOfCoverage = new int[columns];
    for(int i = 0; i < columns;i++){
        sumOfCoverage[i] =0; 
    }
    int** tableOfCoverage = new int*[rows];
    for(int i = 0; i < rows; ++i){
        tableOfCoverage[i] = new int[columns];
    }
    k=0;
    int delColumn=0,delRow=0,minimum=0,sums = 1;
    minimum = 1;
    // cout << "\r\n\r\n\r\n\r\n\r\n\r\n\r\n" << endl;
    // cout << rows << " "  << columns << endl;

    for( int i = 0;i < rows;i++){
        for (int j = 0 ; j < columns;j++){
            tableOfCoverage[i][j] = findCoverage(j,i,index,implicantTable,columns);
        }
    }
    for( int i = 0;i < rows;i++){
        for (int j = 0 ; j < columns;j++){
            if(tableOfCoverage[i][j]==1){
                sumOfCoverage[j]=sumOfCoverage[j]+1;
            }
        }
    }

    do{
        k++;
        // cout <<"ROUND: " << k  <<endl;
        // cout << endl;

        // for( int i = 0;i < rows;i++){
        //     cout << implicants.substr(i*(numVar+1),numVar);
        //     for (int j = 0 ; j < columns;j++){
        //         cout << "| " << tableOfCoverage[i][j] << " | ";
        //     }
        //     cout << endl;
        // }

        // cout << endl;
        // cout << "SUM";
        // for (int j = 0 ; j < columns;j++){
        //     cout << "| " << sumOfCoverage[j] << " | ";
        // }
        // cout << endl;cout <<endl;

        minimum = 0;
        for(int i = 0; i < columns;i++){
             if( minimum == 0 && sumOfCoverage[i] > 0){
                minimum = sumOfCoverage[i]; 
             }else if(sumOfCoverage[i]<minimum && sumOfCoverage[i] > 0){
                 minimum = sumOfCoverage[i];
             } 
        }

        // cout << minimum << endl;
        int maxCoverage = 0, curCoverage=0;
        for ( int i = 0; i <columns; i++){
            if(sumOfCoverage[i]==minimum && minimum == 1){
                for(int j = 0; j <rows ; j++){
                    if(tableOfCoverage[j][i] == 1) {
                        delColumn = i;
                        delRow = j;
                        break;
                    }
                }
                break;
            }else if(sumOfCoverage[i]==minimum && minimum != 1){
                for(int j = 0; j < rows; j++){
                    curCoverage=0;
                    for(int h = 0; h <columns; h++){
                        if(tableOfCoverage[j][h] == 1){
                            curCoverage++;
                        }
                    }
                    // cout << "Pokryti pro: " << j << " se stupnem: " << curCoverage << endl;
                    if(maxCoverage < curCoverage){
                        maxCoverage = curCoverage;
                        delColumn = i;
                        delRow = j;
                    }
                }
            }
        }

        // cout << "Deleting on row:" << delRow << ", Implicant on the column:" << delColumn <<endl;
        minimizedFunc << implicants.substr(delRow*(numVar+1),numVar) << "+";

        for( int i = 0; i <columns; i++){
            if(tableOfCoverage[delRow][i]==1){
                for(int j = 0; j < rows ; j++){
                    tableOfCoverage[j][i] = 0;
                }
                tableOfCoverage[delRow][i] = 0;
            }
        }

        // cout << " Current fc: " << minimizedFunc.str() << endl;
        for(int i = 0; i < columns;i++){
            sumOfCoverage[i] =0; 
        }
        for( int i = 0;i < rows;i++){
            for (int j = 0 ; j < columns;j++){
                if(tableOfCoverage[i][j]==1){
                    sumOfCoverage[j]=sumOfCoverage[j]+1;
                }
            }
        }
        sums= sumOfSums(sumOfCoverage,columns);
        // cout << sums <<endl;
        // cout <<endl;
    }while(sums != 0);
    // cout << minimizedFunc.str() << endl;
    string solvedFunc;
    if(form==1){
        solvedFunc = parseOutput(minimizedFunc.str(),numVar,1);  
    }else{
        solvedFunc = parseOutput(minimizedFunc.str(),numVar,0);  
    }


    
    delete[] implicantTable;
    
    delete[] sumOfCoverage;
    
    for(int i = 0; i < rows; ++i){
        delete[] tableOfCoverage[i];
    }
    delete[] tableOfCoverage;
    
    return solvedFunc;
}

void solverKMap(int numVar,int form,int scenario,int repetition){
        //f=0,1,4,5,6,7,10,11,14,15,16,17,18,19,22,23,24,25,26,27
        int * mapa;
        // mapa = new int [32];
        // numVar = 5;
        // const int mapa_test[] = {1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0};
        // for ( int i = 0; i < 32; i++){
        //     mapa[i] = mapa_test[i];
        // }
        int mapType;
        string implicants;
        string index;
        if (numVar == 5){
            try{
                mapa = new int [32];
            }catch(...){
                cout << "Error allocating memory. Length of map is 32. " << endl;
                return;
            }
        }else if(numVar == 4){
            try{
                mapa = new int [16];
            }catch(...){
                cout << "Error allocating memory. Length of map is 16. " << endl;
                return;
            }
        }else{
            try{
                mapa = new int [8];
            }catch(...){
                cout << "Error allocating memory. Length of map is 8." << endl;
                return;
            }
        }

        if( scenario == 7){
            scenario = 1;
            mapType = 2;
        }else if( scenario == 5){
            scenario = 1;
            mapType = 1;
        }else{
            mapType = 0;
        }

        for(int i = 0; i < pow (2, numVar); i++){
            try{
                mapa[i] = 0;
            }catch(...){
                cout << "Error writing zeros to map in the memory..." << endl;
            }
        }
        // cout << "GENMAP0" << endl;
        mapa = generateMap(numVar,mapa,mapType);        
        // cout << "GENMAP1" << endl;
        // for(int i = 0; i < pow (2, numVar); i++){
        //     cout << mapa[i];
        // }
        int countOfOnes = 0,notMinimizing = 0;
        // cout << "Countin0";
        for(int i = 0; i < pow (2, numVar); i++){
            if(mapa[i]==1){
                countOfOnes = countOfOnes + 1;
            }
        }
        // cout << "Countin1" <<endl;
        
        // cout << countOfOnes << " from " << pow(2,numVar) << endl;
        if(countOfOnes == pow(2,numVar)){
            notMinimizing = 1;
        }
        // cout << notMinimizing << endl;
        implicants = createImplicants(mapa,numVar,1);
        string impFunc = implicants;
        impFunc.append("+");
        string inputFunction = parseOutput(impFunc,numVar,1);
        index = implicantIndex(mapa,numVar,1);
        string outputFuncDis;
        if(notMinimizing == 0){
            // cout << "quine0";
            outputFuncDis = QuineMcCluskey(implicants,index,numVar,1);
            // cout << "quine1" << endl;
        }else{
            outputFuncDis = "1";
        }
        implicants = createImplicants(mapa,numVar,0);
        index = implicantIndex(mapa,numVar,0);
        // string outputFuncConj = QuineMcCluskey(implicants,index,numVar,1); 
        string outputFuncCon;
        if(notMinimizing == 0){
            // cout << "quine0";
            outputFuncCon = QuineMcCluskey(implicants,index,numVar,0);
            // cout << "quine1" << endl;
        }else{
            outputFuncCon = "1";
        }
        switch(scenario){
            case 2: 
                cout << "\r\n" << "```" << endl;
                cout << "Disjunction form of function is: f = " << outputFuncDis << "\r\n\r\n" << endl;
                cout << funcToString(numVar,mapa,form) << endl;
                cout << "\r\n" << "```" << "\r\n" << endl;
                cout << "Conjunction form of function is: f = " << outputFuncCon << "\r\n\r\n" << endl; 
                break;
            case 3:
                cout << "\r\n" << "```" << endl;
                // cout << funcToString(numVar,mapa,form) << endl;
                cout << "Disjunction form of function is: f = " << outputFuncDis << "\r\n\r\n" << endl;
                cout << "\r\n" << "```" << "\r\n" << endl;
                cout << "Conjunction form of function is: f = " << outputFuncCon << "\r\n\r\n" << endl;
                break;
            case 4:
                cout << "\r\n" << "```" << endl;
                // cout << funcToString(numVar,mapa,form) << endl;
                cout << "Conjunction form of function is: f = " << outputFuncCon << "\r\n\r\n" << endl; 
                cout << "\r\n" << "```" << "\r\n" << endl;
                cout << "Disjunction form of function is: f = " << outputFuncDis << "\r\n\r\n" << endl;
                break;
            case 6:
                cout << "\r\n" << "```" << endl;
                // cout << "Function is: " << funcToString(numVar,mapa,form) << "\r\n" << endl;
                // cout << "Function is: " <<  impFunc << "\r\n" << endl;
                cout << "Function is: " <<  inputFunction << "\r\n" << endl;
                printKMap(numVar,mapa,form);
                cout << "\r\n" << "```" << "\r\n" << endl;
                cout << "Conjunction form of function is: f = " << outputFuncCon << "\r\n\r\n" << endl; 
                cout << "Disjunction form of function is: f = " << outputFuncDis << "\r\n\r\n" << endl;
                break;
            default:
                cout << "\r\n" << "```" << endl;
                cout << funcToString(numVar,mapa,form) << endl;
                printKMap(numVar,mapa,form);
                cout << "\r\n" << "```" << "\r\n" << endl;
                cout << "Disjunction form of function is: f = " << outputFuncDis << "\r\n\r\n" << endl;
                cout << "Conjunction form of function is: f = " << outputFuncCon << "\r\n\r\n" << endl;   
                break;
        }
    delete[] mapa;

}

void solverOfMaps(int numVar,int form,int scenario,int repetition){
    for(int i = 0;i<repetition;i++){
        solverKMap(numVar,form,scenario,repetition);
    }
}

int main(int argc, char* argv[]) {
    int prikaz = 0;
    int number = 1;
    string file;
    srand (time(NULL));

    if (argc > 1){
        prikaz = atol(argv[1]);
    }
    if(argc > 2){
        if( prikaz == 16){
            file = argv[2];
        }else{
            number = atol(argv[2]);
            if( prikaz == 17 && (number != 3 && number != 4 && number != 5)){
                number = 3;
                cout << "Not implemented number of variables, switching to:" << number << endl;
            }
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
        case 17: solverOfMaps(number,1,1,1);break;
        case 18: solverOfMaps(3,1,1,number);break;
        case 19: solverOfMaps(4,1,1,number);break;
        case 20: solverOfMaps(5,1,1,number);break;
        case 21: solverOfMaps(3,1,2,number);break;
        case 22: solverOfMaps(4,1,2,number);break;
        case 23: solverOfMaps(5,1,2,number);break;
        case 24: solverOfMaps(3,1,3,number);break;
        case 25: solverOfMaps(4,1,3,number);break;
        case 26: solverOfMaps(5,1,3,number);break;
        case 27: solverOfMaps(3,1,4,number);break;
        case 28: solverOfMaps(4,1,4,number);break;
        case 29: solverOfMaps(5,1,4,number);break;
        case 31: solverOfMaps(3,1,5,number);break;
        case 32: solverOfMaps(4,1,5,number);break;
        case 33: solverOfMaps(5,1,5,number);break;
        case 34: solverOfMaps(3,1,6,number);break;
        case 35: solverOfMaps(4,1,6,number);break;
        case 36: solverOfMaps(5,1,6,number);break;
        case 37: solverOfMaps(5,1,7,number);break;
        default: break;
    }

    cout << endl;
    return 0;
}
