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

string fillInZeros(string a,int numVar){
    stringstream streamS;
    if((a.length() == 4 && numVar==5) || (a.length() == 3 && numVar==4) || (a.length() == 2 && numVar==3)){
        streamS << "0" << a;
    }else if((a.length() == 3 && numVar==5) || (a.length() == 2 && numVar==4) || (a.length() == 1 && numVar==3)){
        streamS << "00" << a;
    }else if((a.length() == 2 && numVar==5) || (a.length() == 1 && numVar==4)){
        streamS << "000" << a;
    }else if((a.length() == 1 && numVar==5)){
        streamS << "0000" << a;
        
    }else{
        streamS << a;
    }
    a = streamS.str();
    return a;
}

string oneImplicant(int a,int numVar){
    stringstream stream;
    string k = "0";
    if(a>0){
        k = convertNum(a,2);
    }
    string numericImplicant = fillInZeros(k,numVar);
    return numericImplicant;
}

string createImplicants(int mapa[],int numVar,int form){
    int k = pow (2, numVar);
    int l = 0,m = 0;
    stringstream stream;
    for(int i = 0;i < k;i++){
        l = mapa[i];
        if (l == form){
            if(m == 1){
                stream << "+";
            }
            stream << oneImplicant(i,numVar);
            m = 1;
        }
    }

    return stream.str();
}

string implicantIndex(int mapa[],int numVar,int form){
    int k = pow (2, numVar);
    int l = 0,m = 0;
    stringstream stream;
    for(int i = 0;i < k;i++){
        l = mapa[i];
        if (l == form){
            if(m == 1){
                stream << "+";
            }

            stream << i;
            m = 1;
        }
    }

    return stream.str();
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

string funcToString(int numVar,int mapa[],int form){
    stringstream mapaStream;
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

int countImplicants(string implicants){
    int a = 0;
    int k = 1;
    string temp = implicants;
    while( temp.find("+")!=-1){
        a = temp.find("+");
        temp = temp.substr(a+1,temp.length()-a+1);
        k++;
    }   
    return k;
}

int compareImplicants(string a,string b){
    int countOfConform = 0;
    int answer = 0;
    int limitOfComformity = a.length()-1;
    for (int i=0; i < a.length();i++){
        if(( a.substr(i,1).compare(b.substr(i,1)) == 0)){
            countOfConform ++;
        }
    }
    if(countOfConform==(limitOfComformity)){
        answer = 1;
    }
    return answer;
}

string combineImplicants(string a,string b){
    stringstream streamS;
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

string eradicateDuplicates(string index,string implicants,int numOfImplicants,int numVar){
    string result_index,remains_index,result_index_i,remains_index_i;
    string result_impl,remains_impl,result_impl_i,remains_impl_i;;

    int * unique = new int[numOfImplicants];
    int * implicantsInt = new int[numOfImplicants];
    
    int c,d,e;
    stringstream output_impl,output_index;
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
            result_impl = implicants.substr(0,d);
            remains_impl = implicants.substr(d+1,implicants.length()-1);
            e = index.find("+");
            result_index = index.substr(0,e);
            remains_index = index.substr(e+1,index.length()-1);
            //cout << remains_index <<endl;
            
        }else if( j == numOfImplicants-1){
            result_impl=remains_impl;
            result_index = remains_index;
            //cout << remains_index << endl;
        }else{
            d = remains_impl.find("+");
            result_impl = remains_impl.substr(0,d);
            remains_impl = remains_impl.substr(d+1,implicants.length()-1);
            e = remains_index.find("+");
            result_index = remains_index.substr(0,e);
            remains_index = remains_index.substr(e+1,index.length()-1);
            //cout << remains_index <<endl;
        }
        c = stoi(result_impl);
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


string combineIndexes(string a, string b, string implicants, string index,int numOfImplicants,int numVar){
    
    string result,temp,remains;
    int c,d;
    stringstream output;
    int first = implicants.find(a)/(numVar+1);
    int second = 0,found=0;
    if(b.compare("none")!=0){
        second=implicants.find(b)/(numVar+1);
    }
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
        if(i == first || (i == second && b.compare("none")!=0)){
            if(found>0){
                output << ",";
            }
            output << result;
            found++;
        }
        
    }


    return output.str();
}

int * findPoints(int numOfImplicants,int table[],string index){
    string result,remains;
    int c,d;
    stringstream output;
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
        table[i] = stoi(result);
    }

    return table;
}

int findCoverage(int a,int b,string index,int table[],int numOfImplicants){
    string result,remains,temp;
    int count = 0;
     int c,d,e;
     stringstream output;
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

string parseVarString(string a){
    stringstream output;
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
            output << symbol;
        }else if(value == 0){
            output<< "non(" << symbol << ")";
        }
    }
    return output.str();
}

string parseOutput(string func,int numVar,int form){
    int lengthOfFunc = func.length()/(numVar+1);
    string temp = func.substr(0,func.length()-1);
    stringstream output;
    
    for(int i = 0;i<lengthOfFunc;i++){
        output << parseVarString(temp.substr(i*(numVar+1),numVar));
        if(i<lengthOfFunc-1){
            output << "+";
        }
    }

    return output.str();
}

string QuineMcCluskey(string implicants,string index,int numVar,int form){
    
    int k=0,l=0,m=0,n=0,lastCountOfImplicants=0;
    int comparation=0;
    int found = 0;
    stringstream newImplicants;
    stringstream newIndexes;
    string eredication;
    string a,b;
    int basicNumberOfImplicants = countImplicants(implicants);
    int * implicantTable = new int [basicNumberOfImplicants];
    implicantTable = findPoints(basicNumberOfImplicants,implicantTable,index);
    while(k<100){
        newImplicants.str("");
        newIndexes.str("");
        k++;
        // cout << "Round: " << k << endl;
        // cout << "Implikanty: " << implicants << endl;
        // cout << "Indexy: " << index << endl;
        l = countImplicants(implicants);
        m = 0;

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
        }
        //cout << newImplicants.str() << endl;
        //cout << newIndexes.str() << endl;
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

    stringstream minimizedFunc;

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
        minimum = 0;
        for(int i = 0; i < columns;i++){
             if( minimum == 0 && sumOfCoverage[i] > 0){
                minimum = sumOfCoverage[i]; 
             }
             if(sumOfCoverage[i]<minimum && sumOfCoverage[i] > 0){
                 minimum = sumOfCoverage[i];
             } 
        }

        for ( int i = 0; i <columns; i++){
            if(sumOfCoverage[i]==minimum){
                for(int j = 0; j <rows ; j++){
                    if(tableOfCoverage[j][i] == 1) {
                        delColumn = i;
                        delRow = j;
                    }
                }
                break;
            }
        }

        //cout << "Deleting on row:" << delRow << ", Implicant on the column:" << delColumn <<endl;
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
    //cout << minimizedFunc.str() << endl;
    string solvedFunc;
    if(form==1){
        solvedFunc = parseOutput(minimizedFunc.str(),numVar,1);  
    }else{
        solvedFunc = parseOutput(minimizedFunc.str(),numVar,0);  
    }

    return solvedFunc;
}

void solverKMap(int numVar,int form){
    int * mapa;
    string implicants;
    string index;
    mapa = new int [8];
    if (numVar == 5){
      mapa = new int [32];
    }else if(numVar == 4){
      mapa = new int [16];
    }
    mapa = generateMap(numVar,mapa);
    cout << funcToString(numVar,mapa,form) << endl;  
    printKMap(numVar,mapa,form);

    implicants = createImplicants(mapa,numVar,form);
    index = implicantIndex(mapa,numVar,form);
    //cout << "Implikanty: " << implicants << endl;
    //cout << "Indexy: " << index << endl;
    string outputFunc = QuineMcCluskey(implicants,index,numVar,form);
    cout << "Function is: " << outputFunc << endl;
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
        case 17: solverKMap(number,1);break;
        case 18: solverKMap(3,1);break;
        case 19: solverKMap(4,1);break;
        case 20: solverKMap(5,1);break;
        default: break;
    }

    cout << endl;
    return 0;
}
