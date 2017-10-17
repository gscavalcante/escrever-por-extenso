#include <iostream.h>
using namespace std;

void excecao(int NUM){
     string EXCECAO[10];
     
     EXCECAO[1]="ONZE";
     EXCECAO[2]="DOZE";
     EXCECAO[3]="TREZE";
     EXCECAO[4]="QUATORZE";
     EXCECAO[5]="QUINZA";
     EXCECAO[6]="DEZESSEIS";
     EXCECAO[7]="DEZESSETE";
     EXCECAO[8]="DEZOITO";
     EXCECAO[9]="DEZENOVE";
          
     cout<<EXCECAO[NUM%10];          
};

void unidade(int NUM){
     string UNIDADE[10];
     /*O número zero é desnecessário, e pulei o VETOR[0] para ficar mais fácil*/
     UNIDADE[1]="UM";
     UNIDADE[2]="DOIS";
     UNIDADE[3]="TRES";
     UNIDADE[4]="QUATRO";
     UNIDADE[5]="CINCO";
     UNIDADE[6]="SEIS";
     UNIDADE[7]="SETE";
     UNIDADE[8]="OITO";
     UNIDADE[9]="NOVE";
     
     cout<<UNIDADE[NUM];
};
void dezena(int NUM){
     string DEZENA[10];
     int UNI=NUM%10;
     
     DEZENA[1]="DEZ";
     DEZENA[2]="VINTE";
     DEZENA[3]="TRINTA";
     DEZENA[4]="QUARENTA";
     DEZENA[5]="CINQUENTA";
     DEZENA[6]="SESSENTA";
     DEZENA[7]="SETENTA";
     DEZENA[8]="OITENTA";
     DEZENA[9]="NOVENTA";

     if((NUM>10) && (NUM<20)){
         excecao(NUM);
     }
     else {
         cout<<DEZENA[NUM/10];
         if((NUM%10>0) && (NUM/10>0)) cout<<" E ";
         unidade(UNI);
     }
};

void centena(int NUM){
     string CENTENA[10];
     int DEZ=NUM%100;
     CENTENA[0]="";
     CENTENA[1]="CENTO";
     CENTENA[2]="DUZENTOS";
     CENTENA[3]="TREZENTOS";
     CENTENA[4]="QUATROCENTOS";
     CENTENA[5]="QUINHENTOS";
     CENTENA[6]="SEISCENTOS";
     CENTENA[7]="SETECENTOS";
     CENTENA[8]="OITOCENTOS";
     CENTENA[9]="NOVECENTOS";
     
     if((DEZ/10==0) && (DEZ%10==0)){
         cout<<"CEM";               
     }
     else{ 
         cout<<CENTENA[NUM/100];
         if((DEZ/10>0) && (NUM/100>0)) cout<<" E ";       
             dezena(DEZ);
     }
};

void NUMERO(int NUM){
     int X, Y, Z;
     if((NUM>999999) && (NUM<1000000000)){
         X=NUM/1000000;
         Y=NUM%1000000;
         Y=Y/1000;
         Z=NUM%1000;
         centena(X);
         if(NUM/1000000==1){
             cout<<" MILHAO ";
         }
         else{
             cout<<" MILHOES ";
         }
         if(Y>0){
             cout<<"E ";
             centena(Y);
             cout<<" MIL";
             if(Z>0){
                 cout<<" E ";
                 centena(Z);
             }
         }
     }
    else if((NUM>999) && (NUM<1000000)){
        X=NUM/1000;
        Y=NUM%1000;
        centena(X);
        cout<<" MIL";
        if(X>0){
            cout<<" E ";
            centena(Y);
        }
     }
     else{
          centena(NUM);
     }
     cout<<"\n";   
};

int main(){
    int NUM;
    string EX;
    char OPC;
    bool EXIT;
    do{
    system("cls");
    cout<<"\t\t\t* Gabriel Cavalcante - Senai EL *\n\n";
    cout<<"Digite um numero: ";
    cin>>NUM;
    if((NUM>0) && (NUM<=999999999)){
        NUMERO(NUM);
    }
    else{
        cout<<"Numero invalido.\n\n";
    }
    cout<<"Deseja digitar outro? ";
    cin>>OPC;
    }while(OPC=='s' or OPC=='S');
} 
