#include <stdio.h>
#include <stdlib.h>
int brancas = 1;
int pretas  = 0;
int contX =0;
int contX1 =0;
int cont = 0;
int cont1 = -1;
  int mover1 =0;
char xadrez[9][9] = { {' ','1','2','3','4','5','6','7','8'}
                     ,{'1','T','C','B','Q','K','B','C','T'}
                     ,{'2','P','P','P','P','P','P','P','P'}
                     ,{'3',' ',' ',' ',' ',' ',' ',' ',' '}
                     ,{'4',' ',' ',' ',' ',' ',' ',' ',' '}
                     ,{'5',' ',' ',' ',' ',' ',' ',' ',' '}
                     ,{'6',' ',' ',' ',' ',' ',' ',' ',' '}
                     ,{'7','p','p','p','p','p','p','p','p'}
                     ,{'8','t','c','b','q','k','b','c','t'}};

int mostrarMatriz(){
  system("CLS"); 
  int linha;
  int coluna;
  int x;
  printf("============================================= GAECO ==========================================================\n");
  for(linha = 0; linha<9;linha++){ // 0 1 2 3 4 5 6 7
        for(x=0;x<3;x++){ // 0 1 2 para cada loop o  mais interno executa 8 vezes

            for(coluna = 0; coluna<9;coluna++){
                char peca = xadrez[linha][coluna]; // pe�a recebe o que est� dentro das respectivas posi�oes da matrix xadrex
             char letra1 = ((linha+coluna)%2 ==0 && linha>0 && coluna>0)?'\xB2':' ';
             char letra = (x == 1 && peca != ' ')? peca: letra1;
        if((linha+coluna)%2==0 && linha>0 && coluna>0){ // atrav�s da soma das posi��es da linha  e da coluna e com o resto da divis�o da saber se
                                 // a soma  dos indices o resto e par ou impar. as que forem par seram pintadas e as que n�o s�o ficaram em branco
           printf("\xB2\xB2%c\xB2\xB2", letra); // sequencia de escape \xB2 para pintar !!
        }else{
            printf("  %c  ", letra);//DO MESMO MODO QUE TEMOS  4 \xB2 ENVOLTA DA MASCARA %c TEMOS 4 ESPA�OS VAZIOS ENTORNO  DESTA  MASCARA TAMBEM
        }
    }
     printf("\n");
        }
  }
}
//METODO MOVER PECA ==============================================================================================================================================================================================================
//O MAIOR DE TODOS OS M�TODOS RESPONS�VEL POR SOBRE ESCREVER OS VALORES DA MATRIZ SO DETERMINADAS CONDI��ES
//================================================================================================================================================================================================================================
int moverpeca(int LO ,int CO, int lD,int cD,int valor){ // A CADA CHAMADA AS VARI�VEIS S�O REINICIADAS!
    // EST�O SENDO RECEBIDOS OS VALORES  DOS ARGUMENTOS "{ linhaOrigem colunaOrigem linhaDestino colunaDestino } PARA OS PAR�MENTROS { LO , CO , lD ,cD}
    int mover;
     char peca;
    int i = 0;

    //O DESLOCAMNETO VERTICAL SER� A SUBTRA��O DA LINHA DE DESTINO MENOS A LINHA DE ORIGEM. EXEMPLO{ LINHA 1 PARA LINHA 3} OPERA��O SER� (3 - 1 QUE E == 2 CASAS) DESTINO MENOS ORIGEM.
    int deslocamentoVertical = abs(lD - LO); //ABS VALOR ABSOLUTO
      //printf("\n\n%d\n\n",deslocamentoVertical);
      //O DESLOCAMENTO HORIZONTAL SER�  A SUBTR��O DA COLUNA DE DESTINO MENOS A COLUNA DE ORIGEM EXEMPLO (4 - 2 == 2 CASAS)
    int deslocamentoHorizontal = abs(cD - CO);

      if( ((LO >=1 && LO <=8) && (CO >=1 && CO <=8)) && (lD >=1 && lD <=8) && (cD >=1 && cD <=8)){// S� SER�O ACEITOS OS VALORES ENTRE 1 E 8 TANTO PARA O DESTINO QUANTO PARA A ORIGEM
          // J� QUE O TABULEIRO ONDE AS PE�AS IR�O SE MOVER E UMA MATRIZ QUE VARIA  ENTRE 1 E 8  SENDO [8]POR [8]
             peca = xadrez[LO][CO];
             if(( valor == 1 )&& (xadrez[LO][CO] == 'T' || xadrez[LO][CO] == 'C' || xadrez[LO][CO] == 'B' || xadrez[LO][CO] == 'Q' || xadrez[LO][CO] == 'P' || xadrez[LO][CO] == 'K')){

                     if(xadrez[LO][CO] == 'T' || xadrez[LO][CO] == 'C' || xadrez[LO][CO] == 'B' || xadrez[LO][CO] == 'Q' || xadrez[LO][CO] == 'P' || xadrez[LO][CO] == 'K') { // se a origem  for mai�scula Branca  entra aque
                 // SE xadrez[LO][CO] na linha de origem e coluna de origem for igual a T maiusculo E xadrez[lD][cD] na linha Destino coluna Destino for igual a vaziu ou
// xadrez[LO][CO] for igual a T mauisculo E   xadrez[lD][cD] na linha Destino coluna Destino for igual a p minusculo ENT�O ELE PODE MOVER

                      if(( xadrez[LO][CO] == 'T' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 'p') || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 't')
                  || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 'b') || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 'c')
                  || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 'q') || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 'k')
                 && (deslocamentoVertical == 0 || deslocamentoHorizontal == 0)){ // SE  O DESTINO FOR  VAZIO OU ENT�O UM CARACTER MIN�SCULO ENT�O PODE SOBRE ESCREVER !!
                     // NESTE CASO  A ORIGEM VAI PARA O LOCAL DE DESTINO E O DESTINO RECEBE == ' '  VAZIO
                     /*
                      1 SE O DESCOLACAMENTOVERTICAL FOR == 0 SIGNIFICA QUE A TORRE  SE MOVEU TODO NA HORIZONTAL E  N�O SE DESLOCOU  NA VERTICAL ! 
                      2 quando o deslocamentoHorizontal == 8 foi oito,
                      3 O MESMO VALE PARA O deslocamentoHorizontal SE ELE FOR == 0 ENT�O O MOVIMENTO SERA  NA VERTICAL.
                      4 OU UM OU OUTRO  NUNCA OS DOIS
                     */
                    int cont = 0;
                     int cont1 = 0;


//=============================================================================================================================================================================
                           if(deslocamentoVertical >0){




                            if(CO == 1){ 
                                    int f = LO; 
                                if(LO - lD == 1 || lD - LO  == 1){ //  A solu��o para andar um casa, se alinha de origem menos a linha destino for == 1 ou  linha destino menos origem for == 1 ENT�O entra na cond��o
// obs LINHA ORGEM == ONDE EST�
// LINHA DESTINO PARA ONDE  VAI

                                 for(f;f<=lD;f++){// PARA F QUE COME�A NO VALOR DE LINHA ORIGEM ENQUANTO FOR MENOR OU IGUAL A LINHA DESTINO  SEJA INCREMENTADO EM UMA UNIDADE

                              if(xadrez[f][1] == ' '){// NESTE CASO A COLUNA  EST� FIXA EM 1 ,  E QUEM VARIA � A LINHA f
                                    cont++;        // se xadrez[f][1] na linha f coluna 1 �  == a vazio  ent�o a torre pode se mover  por essa casa  at� porque a torre n�o pode saltar  por cima das pe�as
                                                   // O cont VAI CONTAR QUANTAS CASAS VAZIAS A ENTRE A TORRE E SEU DESTINO

                             }else if(xadrez[f+1][1] != ' ' ){ // f+1 PORQUE NA POSI��O F J� TEM A PR�PRIA TORRE E ELA � UMA PE�A POR TANTO N�O E VAZIO
                                  cont1++; // cont1 CONTA AS POSI��ES QUE TEM PE�AS, SE HOUVER  PE�AS ENTRE A TORRE E SEU DESTINO ELE VAI CONTAR.
                             }

                         }
                           f = LO; // NOVAMENTE f RECEBE O VALOR DO PAR�METRO linhaOrigem
                  /* printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -f));
                   printf("====ttuu%d===\n\n",(f - lD));*/

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){ //ESSA CONDI��O SERVE PARA SABER SE A QUANTIDADE DE CASAS VAZIAS ENTRE A TORRE EO DESTINO � IGUAL A SUBTR��O
                        // DA LINHA DE DESTINO MENOS A LINHA DE ORIGEM  EXEMPLO { cont == 6 foi contada sei casas e a lD == 8 e f == 2 o resultado de casas �  8 - 2 == 6
                        // comparando as  6 casas vazias  com o resultado  podemos ter certeza que h� 6 casas entre destino e origem e que est�o vazias pois cont1 e == 0
                        //POR�M SE cont1 TIVESSE CONTADO UMA CASA ENT�O ENTRE A TORRE E SEU DESTINO HAVIA UMA PE�A
                        // A OPERA��O N�O SERIA ACEITA POIS A TORRE N�O PODE SALTAR SOBRE AS PE�AS

                            for( i = 0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1 );
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO]; //SOB ESCREVE A FOR�A E RETORNA 1
                               xadrez[LO][CO] = ' ';
                              return 1; // movimento realizado;

                           }

                   }

//================================================================================================================================================================================================================================

                                     int   i = LO+1; // I RECEBE LINHA DE ORIGEM MAIS 1
                                    if(i < lD){ // SE A LINHA DE ORIGEM FOR MENOR QUE A LINHA DESTINO EXEMPLO{ linha 1 para linha 8}


                                 for(i;i<lD;i++){

                        if(xadrez[i][1] == ' '){// o que vai variar � a linha ( DESLOCAMENTO VERTICAL) e a coluna permanece FIXA COLUNA 1
                                cont++;// cont  vaizio

                        }else if(xadrez[i][1] != ' ' ){
                        cont1++; //cont1 conta as pe�as
                        }

                    }
                      i = LO+1; // I RECEBE LINHA DE ORIGEM MAIS 1 NOVAMENTE

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){ // SE N�O HOUVER PE�AS ENTRE A TORRE � O DESTINO PODE MOVER

                         for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Nao eh possivel saltar sobre as pecas"); // NESTE CASO cont1 CONTOU UMA PE�A ENTRE A TORRE E SEU DESTINO
                                                                                // N�O PODE MOVER  POIS A TORRE N�O SALTA SOBRE PE�AS
                           }

                   }
//===============================================================================================================================================================================================
                   if(i > lD){ // neste caso origem �  maior que o destino ORIGEM == 8 DESTINO == 1
                           int x = LO - 1;

                     for(x;x>lD;x--){// ENT�O PARA SE MOVER PARA TRAZ E S� DECREMENTAR

                        if(xadrez[x][1] == ' '){
                                cont++;

                        }else if(xadrez[x][1] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1; // SERIA A LINHA 8 MENOS 1 POIS A LINHA 8 J� E A PR�PRIA PE�A

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                         for(i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }


                  }else if(CO == 2){//================

                                int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solu��o para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][2] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][2] != ' ' ){
                                  cont1++;
                             }

                         }
                        f = LO;
                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{


                         for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

 //============================================================================================================
                         int   i = LO + 1;
                        if(i < lD){ // ESSA CONDI��O SERVE PARA SABER SE A LINHA DE ORIGEM i � MENOR QUE A LINHA DE DESTINO lD, SE FOR TEREMOS QUE FAZER UM LOOP INCREMENTADO AS CASAS

                        for(i;i<lD;i++){

                        if(xadrez[i][2] == ' '){//  NESTE CASO QUEM VARIA � A LINHA (deslocamento  vertical) A COLUNA EST� FIXA
                                cont++; // CONTA OS VAIOS

                        }else if(xadrez[i][2] != ' ' ){
                        cont1++; // CONTA  AS PE�AS
                        }

                    }
                      i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){         //ESSA CONDI��O SERVE PARA SABER SE A QUANTIDADE DE CASAS VAZIAS ENTRE A TORRE EO DESTINO � IGUAL A SUBTR��O
                        // DA LINHA DE DESTINO MENOS A LINHA DE ORIGEM  EXEMPLO { cont == 6 foi contada sei casas e a lD == 8 e i == 2 o resultado de casas �  8 - 2 == 6
                        // comparando as  6 casas vazias  com o resultado  podemos ter certeza que h� 6 casas entre destino e origem e que est�o vazias pois cont1 e == 0
                        //POR�M SE cont1 TIVESSE CONTADO UMA CASA ENT�O ENTRE A TORRE E SEU DESTINO HAVIA UMA PE�A
                        // A OPERA��O N�O SERIA ACEITA POIS A TORRE N�O PODE SALTAR SOBRE AS PE�AS
                            for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }


                   if(i > lD){ // SE A ORIGEM FOR MAIOR QUE O DESTINO, SER� FEITO UM LOOP  DECREMENTANDO AS CASAS.
                    int x = LO - 1; // O MENOS UM E PARA QUE A PROPRIA PE�A N�O SEJA  CONTADA J� QUE QUEREMOS CHECAR SO O INTERVALO ASSIM SUPONDO QUE VAMOS DE 8 PARA 1 O INTERVALO E 7 2

                    for(x;x>lD;x--){

                    if(xadrez[x][2] == ' '){
                                cont++; // CONTA  VAZIO

                    }else if(xadrez[x][2] != ' ' ){
                        cont1++; // CONTA PE�A
                        }

                   }
                     x = LO - 1;
                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }

                 }else if(CO == 3){ // SE A COLUNA FOR == 3  ENT�O SERA EXECUTADO ESSA CONDI��O

                                int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solu��o para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][3] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][3] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;


                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){ // NESTE CASO A TORRE SO SE MOVER��A UMA CASA


                            for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                }else{

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                    }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                 xadrez[lD][cD] = xadrez[LO][CO];
                 xadrez[LO][CO] = ' ';
                    return 1; // movimento realizado;
                           }

                   }


// A LOGICA �  A MESMA AO LONGO DE TODA A CONDI��O DA TORRE
//===============================================================================================================================================================
                        int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][3] == ' '){
                                cont++;

                           }else if(xadrez[i][3] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                           for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Nao eh possivel saltar sobre as pecas");
                           }

                   }

//==============================================================================================================================================================================
                   if(i > lD){

                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][3] == ' '){
                                cont++;

                        }else if(xadrez[x][3] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                        for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Nao eh possivel saltar sobre as pecas\n");
                           }

                   }
//===================================================================================================================================================================================================
                    }else if(CO == 4){

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solu��o para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][4] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][4] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;
                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                              for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                          for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                                xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;
                           }

                   }

//====================================================================================================================================================================
                    int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][4] == ' '){
                                cont++;

                           }else if(xadrez[i][4] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                                for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                        }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//========================================================================================================================================================
                   if(i > lD){
                    int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][4] == ' '){
                                cont++;

                        }else if(xadrez[x][4] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;
                  /* printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -x));
                   printf("====ttuu%d===\n\n",(x - lD));*/

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                              for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }

//===============================================================================================================================================================================
                    }else if(CO == 5){

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solu��o para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][5] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][5] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;


                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                     }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                   for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                            xadrez[lD][cD] = xadrez[LO][CO];
                            xadrez[LO][CO] = ' ';
                             return 1; // movimento realizado;;

                           }

                   }


//===================================================================================================================================================================
                        int   i = LO + 1;

                       if(i < lD){

                          for(i;i<lD;i++){

                        if(xadrez[i][5] == ' '){
                                cont++;

                        }else if(xadrez[i][5] != ' ' ){
                        cont1++;
                        }

                    }
                      i = LO +1;
                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                              for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                       }

//=========================================================================================================================================================================================
                   if(i > lD){
                      int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][5] == ' '){
                                cont++;

                        }else if(xadrez[x][5] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }
//=�============================================================================================================================================================================
                }else if(CO == 6){

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solu��o para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][6] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][6] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;


                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                              for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                              xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;
                           }

                   }

//=============================================================================================================
                    int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][6] == ' '){
                                cont++;

                           }else if(xadrez[i][6] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//=========================================================================================================================================================================================
                   if(i > lD){

                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][6] == ' '){
                                cont++;

                        }else if(xadrez[x][6] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;


                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                         }
                     }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }



//=========================================================================================================================================================================
               }else if(CO == 7){

                        int f = LO;
                    if(LO - lD == 1 || lD - LO  == 1){ // solu��o para andar um casa

                                 for(f;f<=lD;f++){

                              if(xadrez[f][7] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][7] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                              for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                        xadrez[lD][cD] = xadrez[LO][CO];
                        xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }

//=================================================================================================================
                      int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][7] == ' '){
                                cont++;

                           }else if(xadrez[i][7] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;


                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                                for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//====================================================================================================================================================================================

                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][7] == ' '){
                                cont++;

                        }else if(xadrez[x][7] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;


                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){
                            mover = 1;


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }

//============================================================================================================================================================================================

               }else if(CO == 8 ){

                            int f = LO;
                            if(LO - lD == 1 || lD - LO  == 1){ // solu��o para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][8] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][8] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;
                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                           }else{

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

//============================================================================================================
                      int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][8] == ' '){
                                cont++;

                           }else if(xadrez[i][8] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;


                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                                for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }


                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][8] == ' '){
                                cont++;

                        }else if(xadrez[x][8] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }


                            }
//=======================================================================================================================================================================================================================
//=======================================================================================================================================================================================================================
               }else if(deslocamentoHorizontal >0){ // ESSA CONDI��O SERVE PARA O DESLOCAMENTO HORIZONTAL SE ELE FOR MAIOR QUE ZERO � PORQUE O DESLOCAMENTO HORIZONTAL E 1 2 3 ETC E O VERTICAL � ZERO

                   if(LO == 1){  // VERIFICANDO A LINHA 1

                          int z = CO; // z RECEBE O VALOR DO PAR�METRO COLUNAoRIGEM

                    if(CO - cD == 1 || cD - CO  == 1){ // solu��o para andar um casa  COLUNA DE ORIGEM  MENOS COLUNA DE DESTINO  == 1 OU SEJA ANDA S� UMA CASA


                        for(z;z<=cD;z++){ // z INICIA COM O VALOR DA COLUNA ORIGEM E VAI SENDO INCREMENTADO AT� QUE SEJA DADA A CONDI��O

                        if(xadrez[1][z] == ' '){ //linha um fixa !!! quem vai variar e a coluna linha  1 coluna z que varia de 1 a 8
                                cont++;

                             }else if(xadrez[1][z+1] != ' ' ){ // esse mais um � para ele n�o contar a pr�ria pe�a que esta na posi��o inicial  lembrando que cont1 significa que tem pe�a ou seja n�o � vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;


                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;
                           }

                   }


//===================================================================================================================================================================================
                     int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[1][j] == ' '){
                                cont++;

                           }else if(xadrez[1][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1; // j recebe a colunaOrigem mais 1 para n�o contar a propria pe�a  que ser� movimnetada
                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){ // SE A CONTIDADE DE CASAS VAZIAS FOR == A O INTERVALO DA ORIGEM MENOS O DESTINO ENT�O  PODE MOVER
                                                                        // POR�M SE CONT1 TIVESSE CONTADO AO MENOS UMA CASA, N�O PODERIAMOS MOVER POIS A TORRE N�O SALTA CASAS
                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                       }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//=======================================================================================================================================================================================================================
//=======================================================================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){ //LOOP FEITO PARA  VARIA DE UM COLUNA 8 PARA UMA MENOR POR ISSO O DECREMNETO

                           if(xadrez[1][y] == ' '){ // AGORA E A LINHA QUE EST� FIXA E QUEM VARIA � A COLUNA
                                cont++; // CONT VAZIO

                           }else if(xadrez[1][y] != ' ' ){
                               cont1++; // CONT1 PE�A
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                             printf(" A TORRE NAO PODE SALTAR SOBRE AS PECAS \n");

                           }

                   }




//==============================================================================================================================================================================================

             }else if(LO == 2){ // LINHA 2

                    int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[2][z] == ' '){
                                cont++;

                             }else if(xadrez[2][z+1] != ' ' ){ // esse mais um � para ele n�o contar a pr�ria pe�a que esta na posi��o inicial  lembrando que cont1 significa que tem pe�a ou seja n�o � vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                              for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                 for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; 
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                                return 1; // movimento realizado;
                           }

                   }

//====================================================================================================================
// A L�GICA � A MESMA AO LONGO DA CONDI��O TORRE
                    int j = CO + 1;
                      if(j < cD){ // SE A ORIGEM E MENOR  ENT�O  LOOP
                             for(j;j<cD;j++){

                           if(xadrez[2][j] == ' '){ // LINHA FIXA  EM 2 j COLUNA VARIANDO ENTRE ORIGEM E DESTINO
                                cont++;

                           }else if(xadrez[2][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//========================================================================================================================
                      if(j > cD){ // ORIGEM MAIOR QUE DESTINO ENT�O LOOP DE DECREMENTO
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[2][y] == ' '){ // LINHA FIXA EM 2
                                cont++;

                           }else if(xadrez[2][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){ // SE A QUANTIDADE DE VAZIOS FOR == A COLUNA DESTINO MENOS A ORIGEM E CONT1 FOR == 0 ENT�O MOVER

                              for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//========================================================================================================================================================================================
             }else if(LO == 3){ // LINHA 3

                    int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){

                        for(z;z<=cD;z++){

                        if(xadrez[3][z] == ' '){
                                cont++;

                             }else if(xadrez[3][z+1] != ' ' ){ // Z + 1 PARA N�O CONTAR A PR�PRIA PE�A SE  ISSO ACONTECESSE  cont 1 SERIA  CONTADO
                                  cont1++;
                             }

                         }
                           z = CO; // Z RECEBE A COLUNA DE ORIGEM

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                          for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;
                           }

                   }

//====================================================================================================================================================================
                   int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[3][j] == ' '){
                                cont++;

                           }else if(xadrez[3][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;
                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//=====================================================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[3][y] == ' '){
                                cont++;

                           }else if(xadrez[3][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;
                       /* printf("====ttuu%d==\n\n",cont);
                        printf("====ttuu%d==\n\n",(cD - y));
                        printf("====ttuu%d===\n\n",(y - cD));*/

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){


                            for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//===================================================================================================================================================================================================
            }else if(LO == 4){

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[4][z] == ' '){
                                cont++;

                             }else if(xadrez[4][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                               for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                    return 1; // movimento realizado;

                           }

                   }

//===============================================================================================================================================================================================

                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[4][j] == ' '){
                                cont++;

                           }else if(xadrez[4][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//======================================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[4][y] == ' '){
                                cont++;

                           }else if(xadrez[4][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;
                    if(((cont == (lD - y)) || (cont == ( y - lD) )) && (cont1 == 0)){

                              for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX = contX + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                         mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//================================================================================================================================================================================================
            }else if(LO == 5){ // LINHA 5

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){ // SE ESSA CONDI��O FOR VERDADEIRA ENT�O O MOVIMENTO DA PE�A SER� 1


                        for(z;z<=cD;z++){ // VAI CONTAR DA ORIGEM AT� O DESTINO XEMPLO  CASA 1 ATA� A CASA 2

                        if(xadrez[5][z] == ' '){
                                cont++;

                             }else if(xadrez[5][z+1] != ' ' ){ // esse mais um � para ele n�o contar a pr�ria pe�a que esta na posi��o inicial  lembrando que cont1 significa que tem pe�a ou seja n�o � vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;
                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                        for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                         xadrez[lD][cD] = xadrez[LO][CO];
                         xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }

//============================================================================================================================================================================================

                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[5][j] == ' '){
                                cont++;

                           }else if(xadrez[5][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                    }else{
                        printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//==================================================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[5][y] == ' '){
                                cont++;

                           }else if(xadrez[5][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;
                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                        for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//===========================================================================================================================================================================================================
            }else if(LO == 6){

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){

                        for(z;z<=cD;z++){

                        if(xadrez[6][z] == ' '){
                                cont++;

                             }else if(xadrez[6][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;
                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                          //     printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                              return 1; // movimento realizado;

                           }

                   }
//======================================================================================================================================
                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[6][j] == ' '){
                                cont++;

                           }else if(xadrez[6][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                         }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//============================================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[6][y] == ' '){
                                cont++;

                           }else if(xadrez[6][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//==============================================================================================================================================================================================
            }else if(LO == 7){

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){ // solu��o para andar um casa


                        for(z;z<=cD;z++){

                        if(xadrez[7][z] == ' '){
                                cont++;

                             }else if(xadrez[7][z+1] != ' ' ){ // esse mais um � para ele n�o contar a pr�ria pe�a que esta na posi��o inicial  lembrando que cont1 significa que tem pe�a ou seja n�o � vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                  for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

//===================================================================================================================================
//===================================================================================================================================
                 int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[7][j] == ' '){
                                cont++;

                           }else if(xadrez[7][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                              for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//=======================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[7][y] == ' '){
                                cont++;

                           }else if(xadrez[7][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                                   for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }


//======================================================================================================================================================================================
            }else if(LO == 8){ // LINHA 8

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[8][z] == ' '){
                                cont++;

                             }else if(xadrez[8][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                        for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                       }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                         for( i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

//===================================================================================================================================================
                 int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[8][j] == ' '){
                                cont++;

                           }else if(xadrez[8][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;


                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//=======================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[8][y] == ' '){
                                cont++;

                           }else if(xadrez[8][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                                  for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }


            }

              }
        }

//===================================================================================================================================================
//==========================================================BISPO====================================================================================
//===================================================================================================================================================
// A LOGICA DO BISPO � FAZER COM QUE O DESLOCAMENTO HORIZONTAL SEJA IGUAL AO VERTICALL
// SE xadrez[LO][CO] NA LINHA  DE ORIGEM  COLUNA DE ORIGEM  FOR IGUAL == B E  xadrez[lD][cD]  NA LINHA DE DESTINO E COLUNA DE DESTINO  FOR  IGUAL == A VAZIO OU  || IGUAL A QUALQUER PE�A  MINUSCULA QUE S�O AS PRETAS
// ENT�O ELE PODE COMER  E MOVER


          if(( xadrez[LO][CO] == 'B' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 'p')
             || (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 't') || (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 'b') ||
             (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 'c') || (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 'q') ||
             (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 'k')&& (deslocamentoVertical == deslocamentoHorizontal)) { //SE ELE SE MOVER UM NAVERTICAL SERA  UM  NA HORIZONTAL TAMB�M

                    for( i =0; i < 1;i++){ // LA�O CRIADO PARA  CONTAR QUANTAS VEZES  B MIROU O REI
                     if(xadrez[LO][CO] == 'B' && xadrez [lD][cD] == 'k'){
                         contX1 = contX1 + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX1);
                      if(xadrez[LO][CO] == 'B' && xadrez [lD][cD] == 'k' && contX1 == 1){ // XEQUE

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'B' && xadrez [lD][cD] == 'k' && contX1 == 2 ){ // SE A PESSOA  N�O DESVIAR O REI E A PE�A ATACAR  O REI E XEQUE MATE
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }


    }

    //====================================================CAVALO==================================================================================
// A L�GICA DO CAVALO  �  O DESLOCAMENTO EM L PODENDO SALTAR  SOBRE AS PE�AS
// SE O DESLOCAMENTO EM VERTICAL linhaOrigem - linha Destino for igual a 1 E O DESLOCAMENTO  horizontal for igual  dois  ent�o temos  UM MOVIMENTO EM L
// o mesmo pode ser feito ao contr�rio  H� TAMB�M  O JOGO DOS OPERADORES L�GICOS  && ||   SENDO QUE CAVALO  que � c mai�sculo s� pode mover para o vazio ou   atacar as pe�as  MIN�SCULAS
          if(((xadrez[LO][CO] == 'C') && (xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'C') && ( xadrez[lD][cD] == 'p') ||
             (xadrez[LO][CO] == 'C') && (xadrez[lD][cD] == 't') || (xadrez[LO][CO] == 'C') && ( xadrez[lD][cD] == 'c') ||
             (xadrez[LO][CO] == 'C') && (xadrez[lD][cD] == 'b') || (xadrez[LO][CO] == 'C') && (xadrez[lD][cD] == 'q') ||
             (xadrez[LO][CO] == 'C' && xadrez[lD][cD] == 'k'))
              && (deslocamentoVertical == 1) && (deslocamentoHorizontal == 2) ||(deslocamentoHorizontal == 1) &&(deslocamentoVertical == 2)){
                 if(xadrez[LO][CO]!='P'){

                                     for( i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'C' && xadrez [lD][cD] == 'k'){
                         contX1 = contX1 + 1 ; // contado global
                   //   printf("=========yyyyy%d========",contX1);
                      if(xadrez[LO][CO] == 'C' && xadrez [lD][cD] == 'k' && contX1 == 1){

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'C' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }






                 }


          }

//===========================================RAINHA=================================================================================================
//==================================================================================================================================================
//O MOVIMENTO DA RAINMHA �  A UNI�O  DO MOVEIMENTO DA TORRE COM O BISPO OU SEJA, SE O DESLOCAMENTO  VERTICAL FOR IGUAL AO  HORIZONTAL OU SE
// O DESLOCAMENTO VERTICAL  FOR == A ZERO OU SE O DESLOCAMENTO HORIZAONTAL FOR IGUAL A ZERO

          if((xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 'p') ||
              (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 't') || (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 'c') ||
             (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 'b') || (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 'q') ||
             (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 'k') && ((deslocamentoVertical == deslocamentoHorizontal) || (deslocamentoVertical == 0) || (deslocamentoHorizontal == 0))){

                  for( i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'Q' && xadrez [lD][cD] == 'k'){
                         contX1 = contX1 + 1 ; // contado global
                    //  printf("=========yyyyy%d========",contX1);
                      if(xadrez[LO][CO] == 'Q' && xadrez [lD][cD] == 'k' && contX1 == 1){

                            return 4; // XEQUE

// fun��o dom contX1 e ver quantas  vezes  a pe�a mira o rei K se ele for contado 1 vez xeque 2

                  }else if(xadrez[LO][CO] == 'Q' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }

          }

//========================================REI===============================================================================================================
//==========================================================================================================================================================
// A PE�A REI K S� PODE SE DESLOCAR  OU 1 NA HORIZONTAL OU 1 NA VERTICAL  EPRA TAL
          if ((((xadrez[LO][CO] == 'K') &&(xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'K') && (xadrez[lD][cD] == 'p') ||
              (xadrez[LO][CO] == 'K') && (xadrez[lD][cD] == 't') || (xadrez[LO][CO] == 'K') && xadrez[lD][cD] == 'c') ||
             (xadrez[LO][CO] == 'K') && (xadrez[lD][cD] == 'b') || (xadrez[LO][CO] == 'K') && xadrez[lD][cD] == 'q') ||
             (xadrez[LO][CO] == 'K') && (xadrez[lD][cD] == 'k')){

                if(((deslocamentoVertical >=0) && (deslocamentoVertical <=1) && deslocamentoHorizontal >=0 )&& (deslocamentoHorizontal <=1 )){ // O MOVIMENTO  SO E UMA CASA POR VEZ


                  for( i =0; i < 1;i++){ // LOOP  QUE VAI DE 0 A 1
                     if(xadrez[LO][CO] == 'K' && xadrez [lD][cD] == 'k'){ // O LOOP E FEITO PARA VER  QUANTAS  VEZES O K REI FOI MIRADO  EE FAZEMOS ISSO ATRAVEZ DO CONTADOR
                         contX1 = contX1 + 1 ; // contado global
                    //  printf("=========yyyyy%d========",contX1);
                      if(xadrez[LO][CO] == 'K' && xadrez [lD][cD] == 'k' && contX1 == 1){

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'K' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{
              mover = 1; // MOVIMENTO NORMAL
                }
        }


              }else{
                  printf("MOVIMENTO INVALIDO ! \n");
                printf("REFACA A JOGADA ! \n");
                jogadaBancada();
                inversao();
              }


          }


//======================MOVIMENTO DOS PE�ES======================================================================================================================
//===============================================================================================================================================================
// OS PE�ES S� PODEM SE MOVER NA  VERTICAL  SENDO O PRIMEIRO MOVIMENTO DE DUAS CASAS OU DE UMA CASA
// E O SEGUNDO APENAS DE UMA EM UMA CASA
          if((peca == 'P') && ((lD - LO) == 1) && (deslocamentoHorizontal == 0)){// SE A linhaDestino menos A linhaOrigem  for igual A  1 ENT�O DESLOCAMENTO � DE UMA CASA NA VERTICAL CRESCETE TIPO 1 2 3 4  ETC

              if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;   // O MOVIMENTO DAS PE�AS BRANCAS  E CRESCETE DE CIMA PARA BAIXO 1 2 3 4 5 6 7 8  ETC
              }

          }else if((xadrez[2][1] == 'P' && LO == 2 && CO == 1 && lD == 4 && cD == 1)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){ // SE A linhaDestino menos A linhaOrigem  for igual A  2  ENT�O ELE PODERAR SALTAR DUAS CASAS
                          // VEJA QUE O PE�O SO PODE ANDAR DUAS CASAS UMA �NICA VEZ J� QUE AS POSI��ES DA MATRIZ EST�O TRAVADAS  TANTO NA ORIGEM QUANTO DUAS CASAS A FRENTE  E A LOGICA � AMESMA  PARA TODOS  OS PE�ES  S� � ALTENADO AS LETRAS
                         // ENTRE P branca ma�uscula e PRETA p min�scula
                if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                       mover = 1;   // O MOVIMENTO DAS PE�AS BRANCAS  E CRESCETE DE CIMA PARA BAIXO 1 2 3 4 5 6 7 8  ETC
              }

          }else if(( xadrez[2][2] == 'P' && LO == 2 && CO == 2 && lD == 4 && cD == 2 )&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){ // linha 2 coluna 2 para linha 4 coluna 2

              if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;   // O MOVIMENTO DAS PE�AS BRANCAS  E CRESCETE DE CIMA PARA BAIXO 1 2 3 4 5 6 7 8  ETC
              }


          }else if((xadrez[2][3] == 'P' && LO == 2 && CO == 3 && lD == 4 && cD == 3)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

              if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;   // O MOVIMENTO DAS PE�AS BRANCAS  E CRESCETE DE CIMA PARA BAIXO 1 2 3 4 5 6 7 8  ETC
              }

          }else if(( xadrez[2][4] == 'P' && LO == 2 && CO == 4 && lD == 4 && cD == 4)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

                if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

          }else if(( xadrez[2][5] == 'P'  && LO == 2 && CO == 5 && lD == 4 && cD == 5)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

                 if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

          }else if((xadrez[2][6] == 'P'  && LO == 2 && CO == 6 && lD == 4 && cD == 6)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

                  if((xadrez[LO][CO] == 'P') &&( xadrez[lD][cD] == ' ')){
                  mover = 1;
              }


          }else if((xadrez[2][7] == 'P' && LO == 2 && CO == 7 && lD == 4 && cD == 7)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

                  if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }


          }else if((xadrez[2][8] == 'P'  && LO == 2 && CO == 8 && lD == 4 && cD == 8)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

                   if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

          }
              if(((xadrez[LO][CO] == 'P' && xadrez[lD][cD] == 'p' || xadrez[lD][cD] == 't' || xadrez[lD][cD] == 'b' || xadrez[lD][cD] == 'c' || xadrez[lD][cD] == 'q' || xadrez[lD][cD] == 'k')
               && (lD - LO) == 1) && (deslocamentoVertical == deslocamentoHorizontal)){
 // SE USARMOS A CONDI��O DO BISPO LIMITADA POR UM TIPO deslocamentoVertical == deslocamentoHorizontal E LINHA DESTINO MENOS A LINHA ORIGEM == 1 ENT�O TEMOS  O MOVIMENTO DE ATAQUE DO PEAO  PARA O LADO  EM 1
 // ATENTE PARA O JOGO COM OS OPERADORES L�GICOS && ||

                     for( i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'P' && xadrez [lD][cD] == 'k'){
                         contX1 = contX1 + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX1);
                      if(xadrez[LO][CO] == 'P' && xadrez [lD][cD] == 'k' && contX1 == 1){

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'P' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{
               mover = 1; // MOVIMENTO NORMAL
                }
        }

               }



//==================================================================MINUSCULAS PRETAS=============================================================================================================================================
    }else {
        printf("ERRO ! VOCE ESTA TENTANDO MOVER UMA PECA QUE NAO E BRANCA \n");
         getch();// a instru��o getch() vai travar a tela para que a menssagem n�o pesse r�pido sem que o jogador note
                 printf("POR FAVOR FACA UMA JOGADA VALIDA \n");
                   mostrarMatriz(); // SER� ATUALIZADA  A MATRIZ AP�S A JOGADA !!!
                   jogadaBancada();
                     inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!
    }


        }else if(valor ==1){
            printf("ERRO ! O JOGADOR DAS PECAS BRANCAS NAO PODE  MOVER AS PECAS PRETAS \n");
            printf("faca uma jogada valida !\n");
             getch();
              mostrarMatriz(); // SER� ATUALIZADA  A MATRIZ AP�S A JOGADA !!! ATUALIZA O JOGO
              jogadaBancada(); // TODA AS VEZES QUE HOUVER UMA  JOGADA,  LOGO APOS A EXECU��O  DO METODO DEVE SER EVOCADO O M�TODO INVERS�O  PARA QUE POSSA TROCAR OS VALORES SE ISSO N�O FOR FEITO  AVER� JOGADAS REPETIDAS
            inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETA



        }

// ===============CODI��O MOVER ============================================================================================================================================================
               if(mover == 1){
        xadrez[lD][cD] = xadrez[LO][CO];
        xadrez[LO][CO] = ' ';
               return 1; // movimento realizado;
          } else{
              return 9; // pe�a n�o ode ser mechida
          }



      }else {
          return 0;
      }
}

//========PRETAS=================================================================================================================================================================================================================
int moverpecaPreta(int LO ,int CO, int lD,int cD,int valor){
    // A CADA CHAMADA AS VARI�VEIS S�O REINICIADAS!
    // EST�O SENDO RECEBIDOS OS VALORES  DOS ARGUMENTOS "{ linhaOrigem colunaOrigem linhaDestino colunaDestino } PARA OS PAR�MENTROS { LO , CO , lD ,cD}
    int mover;
    char peca;
    int i = 0;

    //O DESLOCAMNETO VERTICAL SER� A SUBTRA��O DA LINHA DE DESTINO MENOS A LINHA DE ORIGEM. EXEMPLO{ LINHA 1 PARA LINHA 3} OPERA��O SER� (3 - 1 QUE E == 2 CASAS) DESTINO MENOS ORIGEM.
    int deslocamentoVertical = abs(lD - LO); //ABS VALOR ABSOLUTO
      //printf("\n\n%d\n\n",deslocamentoVertical);
      //O DESLOCAMENTO HORIZONTAL SER�  A SUBTR��O DA COLUNA DE DESTINO MENOS A COLUNA DE ORIGEM EXEMPLO (4 - 2 == 2 CASAS)
    int deslocamentoHorizontal = abs(cD - CO);
      //printf("%d %d %d %d ",LO,CO,lD,cD);
//printf("====TTTTTT%dTTTTTT=====",valor);
      if( ((LO >=1 && LO <=8) && (CO >=1 && CO <=8)) && (lD >=1 && lD <=8) && (cD >=1 && cD <=8)){// S� SER�O ACEITOS OS VALORES ENTRE 1 E 8 TANTO PARA O DESTINO QUANTO PARA A ORIGEM
          // J� QUE O TABULEIRO ONDE AS PE�AS IR�O SE MOVER E UMA MATRIZ QUE VARIA  ENTRE 1 E 8  SENDO [8]POR [8]
             peca = xadrez[LO][CO];

                      if((valor == 0) && (xadrez[LO][CO] == 't' || xadrez[LO][CO] == 'c' || xadrez[LO][CO] == 'b' || xadrez[LO][CO] == 'q' || xadrez[LO][CO] == 'p' || xadrez[LO][CO] == 'k')){


            if((valor == 0) && (xadrez[LO][CO] == 't' || xadrez[LO][CO] == 'c' || xadrez[LO][CO] == 'b' || xadrez[LO][CO] == 'q' || xadrez[LO][CO] == 'p' || xadrez[LO][CO] == 'k')){ //se for preta entre minuscula entrad nessa condi��o

//=======================================torre preta minuscula=====================================================================================================================================================================
//================================================================================================================================================================================================================================
              if(( xadrez[LO][CO] == 't' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'P') ||
                 (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'T') || (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'B') || (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'C')
                  || (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'Q') || (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'K')
                && (deslocamentoVertical == 0 || deslocamentoHorizontal == 0)){

                 int cont = 0;
                     int cont1 = 0;

// AS MESMAS  CONDI��O LOOP E ITERA��ES VALIDAS PARA T  mai�sculas  QUE � A TORRE  CABRANCA  VALE PARA AS PRETAS  torre minuscula t

                           if(deslocamentoVertical >0){

                            if(CO == 1){ // QUEM VAI VARIAR  � ALINHA  A COLUNA EST� FIXA
                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solu��o para andar um casa  // NESTA CONDI��O  LIMITA A TORRE  ANDAR UMA CASA E �SO UMA CASA


                                 for(f;f<=lD;f++){

                              if(xadrez[f][1] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][1] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;


                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                             for(i = 0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                            }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                }else{
                   xadrez[lD][cD] = xadrez[LO][CO];
                   xadrez[LO][CO] = ' ';
                   return 1; // movimento realizado;
                    }

                   }

//==============================================================================================================================

                                     int   i = LO+1;
                                    if(i < lD){


                                 for(i;i<lD;i++){

                        if(xadrez[i][1] == ' '){
                                cont++;

                        }else if(xadrez[i][1] != ' ' ){
                        cont1++;
                        }

                    }
                      i = LO+1;


                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                            for( i =0; i < 1;i++){

                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][1] == ' '){
                                cont++;

                        }else if(xadrez[x][1] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;
                 /*  printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -x));
                   printf("====ttuu%d===\n\n",(x - lD));*/

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                            for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }

//===========================================================================================================================
                  }else if(CO == 2){// COLUNA 2

                                int f = LO;
                    if(LO - lD == 1 || lD - LO  == 1){


                                 for(f;f<=lD;f++){

                              if(xadrez[f][2] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][2] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO; // f RECEBE A LINHA  DE ORIGEM

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){


                        for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){ // SE ESSA CONDI��O FOR VERDADEIRA ENT�O ELE ENCHERGA  O CONTx, CASO ELE  SEJA CONTADO 1 VEZ E PORQUE  ESTA EM XEQUE  SE FOR DUAS VEZES E XEQUE-MATE
                              contX = contX + 1 ; // contado global                // O CONTADOR  contX SO EXISTE DENTRO DA CONDI��O  XEQUE E XEQUE-MATE
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                            }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                    }else{
                       mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

 //============================================================================================================
 //=============================================================================================================
                         int   i = LO + 1; // linhaOrigem + 1 PARA N�O CONTAR A PR�PRIA PE�A J� QUE QUEREMOS S� O INTERVAMO ENTRE A ORIGEM E DESTINO
                        if(i < lD){

                        for(i;i<lD;i++){ // COMO i ORIGEM E MENOR QUE O DESTINO ENT�O O LOOP ser�  UM INCREMENTO

                        if(xadrez[i][2] == ' '){
                                cont++; //CONT VAIZO

                        }else if(xadrez[i][2] != ' ' ){
                        cont1++; // contador para pe�as
                        }

                    }
                      i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                         for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//==========================================================================================================================================================================
                   if(i > lD){ // ORIGEM MAIOR QUER O DESTINO NESSE CASO SER� FEITO UM LOOP DE DECREMENTO !
                    int x = LO - 1; // SE A PE�AS EST� NA CASA 8 E QUEREMOS O INTERVALO ENTRE 8 E 1  ENT�O A POSI��O 8 N�O CONTA  POR ISSO O - 1

                    for(x;x>lD;x--){

                    if(xadrez[x][2] == ' '){
                                cont++;

                    }else if(xadrez[x][2] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                }else{
                    printf("N�o � possivel saltar sobre as pe�as\n");
                     }

                   }
//===========================================================================================================================================================================
                 }else if(CO == 3){ // COLUNA 3
// ESSE PRIMEIRA PARTE PERMITE A TORRE ANDAR UMA CASA
                                int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){


                                 for(f;f<=lD;f++){ // DE 1 PARA 2

                              if(xadrez[f][3] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][3] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                              for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                          mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                                xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }


//===========================================================================================================================================================================================================
//============================================================================================================================================================================================================
                        int   i = LO + 1;
                    if(i < lD){
// NESTA PARTE DA COLUNA 3  PERMITIR� A TORRE ANDAR VARIAS CASAS DESDE QUE ELA SE VERTICAL E POSITIVA SENDO ORIGEM < QUE DESTINO
                        for(i;i<lD;i++){

                           if(xadrez[i][3] == ' '){
                                cont++;

                           }else if(xadrez[i][3] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

// NESTA PARTE DA COLUNA 3  PERMITIR� A TORRE ANDAR VARIAS CASAS DESDE QUE ELA SE VERTICAL E  NEGATIVA SENDO A ORIGEM > QUE O DESTINO
                   if(i > lD){

                           int x = LO - 1; //  N�O CONTAMOS  A CASA DA PE�A  SE A PE�A EST�  NA CASA 7 E VAI PARA CASA 2 ENT�O SEU INTERVALO E 7 - 2 == 5

                     for(x;x>lD;x--){ // DECREMENTO

                        if(xadrez[x][3] == ' '){ // COLUNA 3 FIXA  X LINHA VARIANDO ENTRE 1 E 8  LO - lD == deslocamento vertical
                                cont++; // conta as casas vazias

                        }else if(xadrez[x][3] != ' ' ){
                        cont1++; // conta as pe�as
                        }

                   }
                     x = LO - 1; // x RECEBE A POSI��O DE ORIGEM

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){ // SE QUANTIDADE DE VAZIOS FOR IGUAL A LINHA-ORIGEM MENOS  A LINHA-DESTINO  E A QUANTIDADE DE PE�AS ENTRE A TORRE E DETINO FOR 0 ENT�O PODE MOVER

                             for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n"); // TEM PE�A ENTRE A TORRE E SEU ALVO,  N�O PODE MOVER POIS A TORRE  N�O SALTA PE�AS
                           }

                   }

                    }else if(CO == 4){ // COLUNA 4

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){


                                 for(f;f<=lD;f++){

                              if(xadrez[f][4] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][4] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;
                /*   printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -f));
                   printf("====ttuu%d===\n\n",(f - lD));*/

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                               for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                                xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;
                           }

                   }

//====================================================================================================================================================================
                    int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][4] == ' '){
                                cont++;

                           }else if(xadrez[i][4] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1; //ORIGEM + 1

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                       }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//=========================================================================================================================================================================
                   if(i > lD){
                    int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][4] == ' '){
                                cont++;

                        }else if(xadrez[x][4] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;


                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }

//=======================================================================================================================================================================================
                    }else if(CO == 5){ // COLUNA 5

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){

                                 for(f;f<=lD;f++){

                              if(xadrez[f][5] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][5] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO]; //ATRIBUI��O DE UMA CASA FOR�ADA  ARA TORRE ANDAR SO UMA CASA
                               xadrez[LO][CO] = ' ';
                          return 1; // MOVIMENTO FEITO
                           }

                   }


//===================================================================================================================================================================
                           int   i = LO + 1;

                       if(i < lD){

                          for(i;i<lD;i++){

                        if(xadrez[i][5] == ' '){
                                cont++;

                        }else if(xadrez[i][5] != ' ' ){
                        cont1++;
                        }

                    }
                      i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                              for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                       }

//==============================================================================================================================================================================
                   if(i > lD){
                      int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][5] == ' '){
                                cont++;

                        }else if(xadrez[x][5] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;
                  /* printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -x));
                   printf("====ttuu%d===\n\n",(x - lD));*/

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                       }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }


//======================================================================================================================================================

                }else if(CO == 6){// COLUNA 6

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // ESSA CONDI��O S� ACEITA MOVIMNETO  DE 1  CASA


                                 for(f;f<=lD;f++){

                              if(xadrez[f][6] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][6] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                              xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1;
                           }

                   }
//=============================================================================================================
//=============================================================================================================
                    int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][6] == ' '){
                                cont++;

                           }else if(xadrez[i][6] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;


                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                         for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }


                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][6] == ' '){
                                cont++;

                        }else if(xadrez[x][6] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }
//=============================================================================================================
               }else if(CO == 7){ // COLUNA 7

                        int f = LO;
                    if(LO - lD == 1 || lD - LO  == 1){ // solu��o para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][7] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][7] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }

//=================================================================================================================
                      int   i = LO + 1; // ORIGEM +1
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][7] == ' '){ // i LINHA VARIANDO COLUNA FIXA EM 5
                                cont++; // esse contador  IRA CONTAR OS INTERVALOS ENTRE A PE�A E O DESTINO QUE EST�O VAZIOS

                           }else if(xadrez[i][7] != ' ' ){
                               cont1++; // conta pe�a
                           }

                        }
                             i = LO +1;
                        /*printf("====ttuu%d==\n\n",cont);
                        printf("====ttuu%d==\n\n",(lD -i));
                        printf("====ttuu%d===\n\n",(i - lD));*/

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//=========================================================================================================================================================================================
                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][7] == ' '){
                                cont++;

                        }else if(xadrez[x][7] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;


                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                         for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }

//=============================================================================================================================

               }else if(CO == 8 ){ // COLUNA 8

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solu��o para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][8] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][8] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                         for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                                contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                                 xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

//============================================================================================================
                      int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][8] == ' '){
                                cont++;

                           }else if(xadrez[i][8] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;


                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }


                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][8] == ' '){
                                cont++;

                        }else if(xadrez[x][8] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;
                  /* printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -x));
                   printf("====ttuu%d===\n\n",(x - lD));*/

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                         for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as\n");
                           }

                   }


                            }
//===============================================================================================================================================================================================================================
//========================== DESLOCAMENTO HORIZONTAL=============================================================================================================================================================================
               }else if(deslocamentoHorizontal >0){




                   if(LO == 1){// LINHA 1

                          int z = CO; //  A VARIAVEL z RECEBE O PAR�MTRO  coluna de origem

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){ // LOOP CRESCEETE ++

                        if(xadrez[1][z] == ' '){ // linha travada  coluna z varinado
                                cont++; // CONTADOR DE VAIZO

                             }else if(xadrez[1][z+1] != ' ' ){
                                  cont1++; // CONTA PE�A
                             }

                         }
                           z = CO; // z RECEBE O VALOR  DA COLUNA DE ORIGEM

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                           for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                                xadrez[lD][cD] = xadrez[LO][CO]; // SOBRE ESCRITA FOR�ADA !!
                               xadrez[LO][CO] = ' ';
                               return 1;
                           }

                   }


//===================================================================================================================================================================================
                     int j = CO + 1; // COLUNA DE ORIGEM MAIS 1 PARA N�O CONTAR A PE�A J� QUE QUEREMOS O INTERVALO
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[1][j] == ' '){ // LINHA UM TRAVADA  EM 1 COLUNA j VARIANDO ENTRE J E cD ORIGEME DESTINO
                                cont++; //CONTA VAZIO

                           }else if(xadrez[1][j] != ' ' ){
                               cont1++; // CONTA PE�A
                           }

                        }
                            j = CO + 1; // j volta  SEU VALOR DE ORIGEM  PARA QUE POSSAMOS COMPARA  ORIGEM MENOS DESTINO == QUANTIDADE DE VAZIO

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as"); // cont1 FOI CONTADO ENT�O A UMA PE�A ENTRE  A TORRE E SEU DESTINO  E A TORRE N�O PODE SALTAR PE�A
                           }

                   }

//========================================================================================================================================================================================
                      if(j > cD){ // ORIGEM  AMIOR QUE O DESTINO
                          int y = CO - 1;
                           for(y;y>cD;y--){ // LOOP DE DECREMENTO ! NECESSARIO PARA IR DE UMA CASA 5 PARA CASA 3

                           if(xadrez[1][y] == ' '){
                                cont++; // CONTA VAZIO

                           }else if(xadrez[1][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1; //  y VOLTA A RECEBER O VALOR  DA COLUNA ORIGEM - 1   J� QUE QUEREMOS O INTERVALO ENTRE POR XEMPLO 8 E 1 ENT�O SER� 7  CASAS N�O PODEMOS CONTAR A CASA DA PE�A

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                               for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                              printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }





//==================================================================================================================================================================================================
             }else if(LO == 2){ // LINHA 2

                    int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){ // solu��o para andar um casa


                        for(z;z<=cD;z++){

                        if(xadrez[2][z] == ' '){
                                cont++;

                             }else if(xadrez[2][z+1] != ' ' ){ // esse mais um � para ele n�o contar a pr�ria pe�a que esta na posi��o inicial  lembrando que cont1 significa que tem pe�a ou seja n�o � vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;
                      /* printf("====ttuu%d==\n\n",cont);
                       printf("====ttuu%d==\n\n",(cD -z));
                       printf("====ttuu%d===\n\n",(z - cD));*/

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                                return 1; // movimento realizado;
                           }

                   }

//======================================================================================================================================================================================================
                    int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[2][j] == ' '){
                                cont++;

                           }else if(xadrez[2][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }


                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[2][y] == ' '){
                                cont++;

                           }else if(xadrez[2][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                            for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//=====================================================================================================================================================================
             }else if(LO == 3){ // LINHA 3

                    int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){

                        for(z;z<=cD;z++){

                        if(xadrez[3][z] == ' '){
                                cont++;

                             }else if(xadrez[3][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;


                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                     for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                           //    printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1;
                           }

                   }

//====================================================================================================================================================================
                   int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[3][j] == ' '){
                                cont++;

                           }else if(xadrez[3][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                  for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//=========================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[3][y] == ' '){
                                cont++;

                           }else if(xadrez[3][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                                    for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//=================================================================================================================================================================================================
            }else if(LO == 4){ // LINHA 4

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){ // solu��o para andar um casa


                        for(z;z<=cD;z++){

                        if(xadrez[4][z] == ' '){
                                cont++;

                             }else if(xadrez[4][z+1] != ' ' ){ // esse mais um � para ele n�o contar a pr�ria pe�a que esta na posi��o inicial  lembrando que cont1 significa que tem pe�a ou seja n�o � vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;
                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                   for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                                xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }

//===============================================================================================================================================================================================

                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[4][j] == ' '){
                                cont++;

                           }else if(xadrez[4][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                  for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//==================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[4][y] == ' '){
                                cont++;

                           }else if(xadrez[4][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (lD - y)) || (cont == ( y - lD) )) && (cont1 == 0)){

                               for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }






//===========================================================================================================================================================================================
            }else if(LO == 5){ // LINHA 5

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){

                        for(z;z<=cD;z++){

                        if(xadrez[5][z] == ' '){
                                cont++;

                             }else if(xadrez[5][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;
                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }

//============================================================================================================================================================================================

                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[5][j] == ' '){
                                cont++;

                           }else if(xadrez[5][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                  for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//=====================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[5][y] == ' '){
                                cont++;

                           }else if(xadrez[5][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                               for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//=============================================================================================================================================================================================
            }else if(LO == 6){// LINHA 6

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[6][z] == ' '){
                                cont++;

                             }else if(xadrez[6][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;
                     /*  printf("====ttuu%d==\n\n",cont);
                       printf("====ttuu%d==\n\n",(cD -z));
                       printf("====ttuu%d===\n\n",(z - cD));*/

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                     for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                              return 1; // movimento realizado;

                           }

                   }
//======================================================================================================================================
                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[6][j] == ' '){
                                cont++;

                           }else if(xadrez[6][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;
                        /*printf("====ttuu%d==\n\n",cont);
                        printf("====ttuu%d==\n\n",(cD - j));
                        printf("====ttuu%d===\n\n",(j - cD));*/

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                    for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//=========================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[6][y] == ' '){
                                cont++;

                           }else if(xadrez[6][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                                for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//===========================================================================================================================================================================================
            }else if(LO == 7){ // LINHA 7

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[7][z] == ' '){
                                cont++;

                             }else if(xadrez[7][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                     for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1;

                           }

                   }

//===================================================================================================================================
                 int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[7][j] == ' '){ // LINHA 7 TRAVADA  COLUNA j  VARIANDO ENTRE A COLUNA DE ORIGEM E A COLUNA DE DESTINO
                                cont++; // CONT VAIZO

                           }else if(xadrez[7][j] != ' ' ){
                               cont1++; // CONT PE�A
                           }

                        }
                            j = CO + 1; // j RECEBE NOVAMENTO O VALOR DE ORIGEM

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                  for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

//==============================================================================================================================================
                      if(j > cD){ // ORIGEM MAIOR QUE O DESTINO  NESTE CASO SER� FEITO UM LOOP DE DECREMENTO
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[7][y] == ' '){ // LINHA 7 TRAVADA
                                cont++; // CONT vaizo

                           }else if(xadrez[7][y] != ' ' ){
                               cont1++; // conta pe�a
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                             for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

            }else if(LO == 8){

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[8][z] == ' '){
                                cont++;

                             }else if(xadrez[8][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                 for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                            for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1;

                           }

                   }

//===================================================================================================================================================
                 int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[8][j] == ' '){
                                cont++;

                           }else if(xadrez[8][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                          for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }
//=====================================================================================================================================================

                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[8][y] == ' '){
                                cont++;

                           }else if(xadrez[8][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                            for( i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                }



                           }else{
                               printf("N�o � possivel saltar sobre as pe�as");
                           }

                   }

            }

              }

//===================================================================================================================================================

 //====================================================bispo=================================================================================
 // A MESMA L�GICA  VALE  PARA O BISPO b  MIN�SCULO PROR�M  INVERTENDO AS LETRA  QUE ELA VAI ATACAR SENDO AS MESMAS AS LETRAS MA�SCULAS
          if(( xadrez[LO][CO] == 'b' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'P')
             || (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'T') || (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'B') ||
             (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'C') || (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'Q') ||
             (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'K')&& (deslocamentoVertical == deslocamentoHorizontal)){

                for( i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'b' && xadrez [lD][cD] == 'K'){
                         contX = contX + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX);
                      if(xadrez[LO][CO] == 'b' && xadrez [lD][cD] == 'K' && contX == 1){

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'b' && xadrez [lD][cD] == 'K' && contX == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }

             }

//==================================================cavalo======================================================================================
// A L�GICA � MESMA  TROCANDO S� AS LETRAS mai�sculas e min�sculas
          if(((xadrez[LO][CO] == 'c' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'P') ||
             (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'T') || (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'C') ||
             (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'B') || (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'Q') ||
             (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'K'))
              && (deslocamentoVertical == 1 && deslocamentoHorizontal == 2) ||(deslocamentoHorizontal == 1 && deslocamentoVertical == 2)){
                        if(xadrez[LO][CO]!='p'){
                                   for( i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'c' && xadrez [lD][cD] == 'K'){
                         contX = contX + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX);
                      if(xadrez[LO][CO] == 'c' && xadrez [lD][cD] == 'K' && contX == 1){

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'c' && xadrez [lD][cD] == 'K' && contX == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }

                        }

              }


//=============================================rainha=====================================================================================================
//=========================================================================================================================================================
          if((xadrez[LO][CO] == 'q' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'P') ||
              (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'T') || (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'C') ||
             (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'B') || (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'Q') ||
             (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'K') && ((deslocamentoVertical == deslocamentoHorizontal) || (deslocamentoVertical == 0) || (deslocamentoHorizontal == 0))){

                  for( i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'q' && xadrez [lD][cD] == 'K'){
                         contX = contX + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX);
                      if(xadrez[LO][CO] == 'q' && xadrez [lD][cD] == 'K' && contX == 1){

                            return 4; // XEQUE

                  }else if(xadrez[LO][CO] == 'q' && xadrez [lD][cD] == 'K' && contX == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{
              mover = 1; // MOVIMENTO NORMAL
                }
        }

    }


//====================================rei===================================================================================================================
//==========================================================================================================================================================
          if((xadrez[LO][CO] == 'k' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'P') ||
              (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'T') || (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'C') ||
             (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'B') || (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'Q') ||
             (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'K')){


                    if( (deslocamentoVertical >=0 && deslocamentoVertical <=1) && (deslocamentoHorizontal >=0 && deslocamentoHorizontal <=1 ) ){

               for( i =0; i < 1;i++){

                     if(xadrez[LO][CO] == 'k' && xadrez [lD][cD] == 'K'){
                         contX = contX + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX);
                      if(xadrez[LO][CO] == 'k' && xadrez [lD][cD] == 'K' && contX == 1){

                            return 4; // XEQUE

                  }else if(xadrez[LO][CO] == 'k' && xadrez [lD][cD] == 'K' && contX == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{
               mover = 1; // MOVIMENTO NORMAL
                }



        }
            }else{
                printf("MOVIMENTO INVALIDO ! \n");
                printf("REFACA A JOGADA ! \n");
                jogadaPreta();
                inversao();
            }
             }

               if((peca == 'p' ) && ((LO - lD) == 1 ) && (deslocamentoHorizontal == 0)){

                    if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

          }else if((peca == 'p' && xadrez[7][1] == 'p' && LO == 7 && CO == 1 && lD == 5 && cD == 1)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){
                 if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              } // O MOVIMENTO DAS PRETAS E DECRESCENTE 8 7 6 5 4 3 2 1  ETC

          }else if((peca == 'p' && xadrez[7][2] == 'p' && LO == 7 && CO == 2 && lD == 5 && cD == 2)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){
                   if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              } // O MOVIMENTO DAS PRETAS E DECRESCENTE 8 7 6 5 4 3 2 1  ETC


          }else if((peca == 'p' && xadrez[7][3] == 'p' && LO == 7 && CO == 3 && lD == 5 && cD == 3)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){

                        if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                            mover = 1;
              } // O MOVIMENTO DAS PRETAS E DECRESCENTE 8 7 6 5 4 3 2 1  ETC

          }else if((peca == 'p' && xadrez[7][4] == 'p' && LO == 7 && CO == 4 && lD == 5 && cD == 4)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){

                     if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }


          }else if((peca == 'p' && xadrez[7][5] == 'p' && LO == 7 && CO == 5 && lD == 5 && cD == 5)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){

                     if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                        mover = 1;
              }

          }else if((peca == 'p' && xadrez[7][6] == 'p' && LO == 7 && CO == 6 && lD == 5 && cD == 6)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){


                     if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                       mover = 1;
              }

          }else if((peca == 'p' && xadrez[7][7] == 'p' && LO == 7 && CO == 7 && lD == 5 && cD == 7)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){

                     if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

          }else if((peca == 'p' && xadrez[7][8] == 'p' && LO == 7 && CO == 8 && lD == 5 && cD == 8)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){

                     if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

  //=======================================================================================================================================================================================================================
  // MESMA L�GICA S� TROCA AS LETRAS
               }else if(((xadrez[LO][CO] == 'p' && xadrez[lD][cD] == 'P' || xadrez[lD][cD] == 'T' || xadrez[lD][cD] == 'B' || xadrez[lD][cD] == 'C' || xadrez[lD][cD] == 'Q' || xadrez[lD][cD] == 'K')
               && (LO - lD) == 1) && (deslocamentoVertical == deslocamentoHorizontal)){

                      for( i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'p' && xadrez [lD][cD] == 'K'){
                         contX = contX + 1 ; // contado global
                      //printf("=========yyyyy%d========",contX);
                      if(xadrez[LO][CO] == 'p' && xadrez [lD][cD] == 'K' && contX == 1){

                            return 4; // XEQUE
 // o CONTx S� PODE SER VISUALIZADO DUAS VEZES POR ISSO ELE ESTA DENTRO DA ESTRUTURA CONDICIONAL ORIGEM DESTINO SENDO K O DESTINO O REI  SENDO O REI VISUALIZADO PELO ATACANTE A PRIMEIRA VE E XEQUE
 // SE O CONTx FOR == 2 ENT�O p VISUALIZOU E ATACOU K POIS O MESMO N�O FOI MUDADO OU PROTEGIDO

                  }else if(xadrez[LO][CO] == 'p' && xadrez [lD][cD] == 'K' && contX == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }

               }


//=========================CONDI��O MOVER========================================================================================================================================================================================
// CASO N�O HAJA UM RETORNO  ESPECIFICO MAIS A CIMA OU UM XEQUE-MATE  HAVER� UM REETORNO  SER� UTILIZADA ESTA CONDI��O CASO MOVER SEJA == A 1
               if(mover == 1){
                 xadrez[lD][cD] = xadrez[LO][CO];
                 xadrez[LO][CO] = ' ';
               return 1; // movimento realizado;
              }else{
              return 9; // pe�a n�o ode ser mechida
             }



    }else{
       printf("ERRO! VOCE ESTA  TADO MOVER UMA PE�A QUE NAO E PRETA !\n ");
        getch();
       printf("POR FAVOR FACA UMA JOGADA VALIDA \n");
        jogadaPreta();
         mostrarMatriz(); // SER� ATUALIZADA  A MATRIZ AP�S A JOGADA !!!
        inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!
        }



            }else if(valor == 0){
                   printf("POR FAVOR FACA UMA JOGADA VALIDA \n");
                    getch();
                    mostrarMatriz(); // SER� ATUALIZADA  A MATRIZ AP�S A JOGADA !!!
                      jogadaPreta();



                 int  mover1 = 1;
                 //printf("===============ttttttt%d",mover1);
                   //printf("===============ttttttt%d",valor);
                     //printf("===============ttttttt%c",xadrez[LO][CO]);
                      inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS

                   getch();
                      if((mover1 == 1 )&&(valor == 0) && (xadrez[LO][CO] == 't') || (xadrez[LO][CO] == 'c') || (xadrez[LO][CO] == 'b') || (xadrez[LO][CO] == 'q') || (xadrez[LO][CO] == 'p') || (xadrez[LO][CO] == 'k') ){
                         if(mover == 1){
                         xadrez[lD][cD] = xadrez[LO][CO];
                         xadrez[LO][CO] = ' ';
                         return 1; // movimento realizado;
                        }else{
                          return 9; // pe�a n�o ode ser mechida
                        }

              }


            }




//=========================CONDI��O MOVER========================================================================================================================================================================================
// CASO N�O HAJA UM RETORNO  ESPECIFICO MAIS A CIMA OU UM XEQUE-MATE  HAVER� UM REETORNO  SER� UTILIZADA ESTA CONDI��O CASO MOVER SEJA == A 1
        if(mover == 1){
         xadrez[lD][cD] = xadrez[LO][CO];
         xadrez[LO][CO] = ' ';
         return 1; // movimento realizado;
           }else{
              return 9; // pe�a n�o ode ser mechida
             }





    }else {
          return 0;
      }
}
//METODO DE INVERSAO============================================================================================================
// NESTE M�TODO � FEITO A TROCA DOS VALORES  DAS  VARI�VEIS  BRANCAS E PRETAS, SE BRANCAS � 1 OU SEJA � VERDADEIRA,  ENT�O  BRANCAS
// PASSARAM A SER FALSA E PRETAS VERDADEIRAS SE N�O SE BRANCAS J�  FOR FALSA, FOR 0!!! ENT�O ELA PASSA A SER 1 VERDADEIRA, E PRETAS  FALSAS  QUE E == 0
int inversao(){
  if(brancas == 1){ //TRUE
    brancas =0; // FALSE
    pretas = 1; //TRUE
  }else if(brancas == 0){
     brancas = 1;//TRUE
     pretas = 0;//FALSE
 }
}
//========= METODO JOGADA PE�A BRANCA============================================================================================================
int jogadaBancada(){
    int resultado;
    char simbolo;
    int brancas1 = 1;
    int linhaOrigem =0;
    int  colunaOrigem =0;
    int linhaDestino =0;
    int  colunaDestino =0;

printf("============== Caso o Jogador seja Leo, sua derrota iniciara uma investigacao do GAECO =================================\n");

    if( brancas == 1 && pretas == 0 ){ // BRANCAS � VERDADEIRA OU SEJA � 1???? SE SIM, PODE JOGAR ! E S�O, ELA E FAL�A E PRETA PODE JOGAR , OU SEJA OU UMA OU A OUTRA
    printf("POR FAVOR PECA BRANCA FACA A SUA JOGADA !\n");
    printf("Digite o simbolo da peca que sera movida\n");
    printf("Sendo as MAIUSCULAS AS PECAS BRANCAS !");
    scanf(" %c",&simbolo);
    if(simbolo == 'T' || simbolo == 'C' || simbolo == 'B' || simbolo == 'Q' || simbolo == 'K' || simbolo == 'P'){ // VERIFICANDO SE DE FATO  ESTOMAS MECHENDO COM AS PE�AS BRANCAS. SE SIM PODE JOGAR SE N�O  MENSSAGEM JOAGADA INV�LIDA.
    printf("\nInforme a linha de origem !");
    scanf("%d",&linhaOrigem);               //ORIGEM !
      setbuf(stdin,NULL);
    printf("\nInforme a coluna de origem !");
    scanf("%d",&colunaOrigem);
      setbuf(stdin,NULL);
   printf("\n Informe a linha  de Destino !");
    scanf("%d",&linhaDestino);                // DESTINO !
      setbuf(stdin,NULL);
     printf("\nInforme a coluna de Destino !");
    scanf(" %d",&colunaDestino);
      setbuf(stdin,NULL);

        // printf("\n\n %d %d %d %d ",linhaOrigem,colunaOrigem,linhaDestino,colunaDestino);
      resultado = moverpeca(linhaOrigem, colunaOrigem, linhaDestino,colunaDestino, brancas1); // M�TODO COM PASSAGEM DE PAR�METROS OU ARGUMENTOS E COM RETORNO. ESSE VALOR DE RETORNO SER� JOGADO EM RESULTADO
      mostrarMatriz(); // SER� ATUALIZADA  A MATRIZ AP�S A JOGADA !!!
       inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!
      if(resultado != 1){ // SE RESULTADO FOR DIFERENTE DE 1, SER� MOSTRADA UMA MENSAGEM DE ERRO! E SER� PEDIDO PARA FAZER UMA JOGADA V�LIDA . CASO CONTRARIO, ELE N�O ENTRARA NESTA CONDI��O
            switch( resultado){
             case 9 : printf("\nERRO : peca nao pode ser mechida\n"); getch();
             jogadaBancada();// COMO FOI MOSTRADO QUE A JOGADA ERA  INV�LIDA,  ENT�O E CHAMADO O M�TODO PARA QUE ELE POSSA FAZER UMA JOAGADA V�LIDA !
             inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!
              inversao();

             break;
             case 0 : printf("\nERRO : Coordenadas Invalidas\n"); getch();
             jogadaBancada();// COMO FOI MOSTRADO QUE A JOGADA ERA  INV�LIDA,  ENT�O E CHAMADO O M�TODO PARA QUE ELE POSSA FAZER UMA JOAGADA V�LIDA !
             inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!

             break;
             case 3:
                printf("XEQUE-MATE AS BRANCAS GANHARAM O JOGO \n");
                  getch();// N�O PEGA NADA � SO PARA TRAVAR O CURSO E N�O PASSAR DIRETO
                // system("CLS"); // FUN��O LIMAP TELA
                printf("FIM DO JOGO !");
                exit(0); // FIM DO JOGO
                break;
            case 4:
                 printf("\n ATENCAO PECA PRETA VOCE ESTA EM  XEQUE, FACA A SUA JOGADA RAPIDO !!\n");
                 getch();// N�O PEGA NADA � SO PARA TRAVAR O CURSO E N�O PASSAR DIRETO
                jogadaPreta();
                //inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!

                break;



            }
    }
        mostrarMatriz(); // SER� ATUALIZADA  A MATRIZ AP�S A JOGADA !!!


    }else{

        printf("JOGADA INVALIDA!\n");
  }

    }
}

//===========================================================================================================================================

//========JOGADA PE�A PRETA !================================================================================================================
int jogadaPreta(){
    int resultado;
    char simbolo;
    int brancas1 = 0; // ESTOU PASSANDO A VARI�VEL BRANCAS COMO ARGUMENTO PARA  FAZER COM QUE AS PRETAS  S� POSSAM MOVER  AS MINUCULAS
    int linhaOrigem =0;
    int  colunaOrigem =0;
    int linhaDestino =0;
    int  colunaDestino = 0;
    if( brancas == 0 && pretas == 1){ // ESTOU VERIFICANDO OS VALORES DAS VARI�VEIS GLOBAIS brancas E prentas,  SENDO ZERO PARA FALSO E 1 PARA VERDADEIRO
                                        // SE A VARI�VEL preta FOR 1 ENT�O ELA PODE JOGAR!!! SE N�O ,  BRANCA � VERDADEIRA 1 E PRETA E ZERO  NESTE CASO A BRANCA JOGA E A PRETA N�O.
    printf("POR FAVOR PECA PRETA FACA A SUA JOGADA !\n");
    printf("Por favo digite o simbolo da peca que sera mechida\n");
    printf("sendo as pretas as (minusculas)!\n");
    scanf(" %c",&simbolo);
    if(simbolo == 't' || simbolo == 'c' || simbolo == 'b' || simbolo == 'q' || simbolo == 'k' || simbolo == 'p'){ // NESTA ETAPA � VERIFICADO  SE O JOGADOR EST� MOVIMENTADO AS PE�AS PRETAS
        printf("Informe a linha de origem !\n");                                                                  // SENDO ELAS AS PE�AS MINUSCULAS ( t de torre, c de cavalo,  b de bispo, q para rainha, e k para rei.
    scanf("%d",&linhaOrigem);
    setbuf(stdin,NULL);                 // ORIGEM !
    printf("Informe a coluna de origem !\n");
    scanf("%d",&colunaOrigem);
    setbuf(stdin,NULL);
   printf("\n Informe a linha  de Destino !");
    scanf("%d",&linhaDestino);                 // DESTINO !
    setbuf(stdin,NULL);
     printf("\nInforme a coluna de Destino !");
    scanf(" %d",&colunaDestino);
    setbuf(stdin,NULL); // ESSA FUN��O EST� LIMPADO O BUFF DE MEM�RIA

        // printf("\n\n %d %d %d %d ",linhaOrigem,colunaOrigem,linhaDestino,colunaDestino);
      resultado = moverpecaPreta(linhaOrigem, colunaOrigem, linhaDestino,colunaDestino ,brancas1); // CHAMADA COM RETONO A FUN��O  " movepeca(); " PARA A VARI�VEL  " resultado ", ATE��O!!  EST�O SENDO PASSADOS ARGUMENTOS PARA O M�TODO !!
       inversao(); // E PRO FIM, SER� CHAMADO O M�TODO DE INVERS�O DE INVERS�O  QUE INVERTER� OS VALORES  PARA QUE AS BRANCAS POSSAM JOGAR !!
      if(resultado != 1){// SE RESULTADO FOR DIFERENTE DE 1, SER� MOSTRADA UMA MENSAGEM DE ERRO! E SER� PEDIDO PARA FAZER UMA JOGADA V�LIDA . CASO CONTRARIO, ELE N�O ENTRAR� NETA  CONDI��O
            switch( resultado){//
            case 9 : printf("\nERRO : peca nao pode ser mechida"); getch();
             jogadaPreta();// COMO FOI MOSTRADO QUE A JOGADA ERA  INV�LIDA,  ENT�O E CHAMADO O M�TODO PARA QUE ELE POSSA FAZER UMA JOAGADA V�LIDA !
              inversao(); // E PRO FIM, SER� CHAMADO O M�TODO DE INVERS�O DE INVERS�O  QUE INVERTER� OS VALORES  PARA QUE AS BRANCAS POSSAM JOGAR !!
              inversao(); // E PRO FIM, SER� CHAMADO O M�TODO DE INVERS�O DE INVERS�O  QUE INVERTER� OS VALORES  PARA QUE AS BRANCAS POSSAM JOGAR !!
             break;
             case 0 : printf("\nERRO : Coordenadas Invalidas"); getch();
                if(resultado < 9){
                     jogadaPreta();// COMO FOI MOSTRADO QUE A JOGADA ERA  INV�LIDA,  ENT�O E CHAMADO O M�TODO PARA QUE ELE POSSA FAZER UMA JOAGADA V�LIDA !
                inversao(); // E PRO FIM, SER� CHAMADO O M�TODO DE INVERS�O DE INVERS�O  QUE INVERTER� OS VALORES  PARA QUE AS BRANCAS POSSAM JOGAR !!
                   inversao();// COMO ESTAVA DANDO ERRO SENDO O VALOR DE INVER��O  ERRADO COLOQUEI MAIS UM PARA JOGAR PARA O CORRETO
                }
             break;// SAI�DA !
             case 3:
                printf("XEQUE-MATE AS PRETAS GANHARAM O JOGO \n");
                  getch(); // N�O PEGA NADA � SO PARA TRAVAR O CURSO E N�O PASSAR DIRETO
                //system("CLS"); // FUN��O LIMPA TELA
                printf("FIM DO JOGO !");
                exit(0); // SA�DA DO PROGRAMA
                break;
             case 4:
                  printf("\n ATENCAO PECA BRANCA VOCE ESTA EM  XEQUE, FACA A SUA JOGADA RAPIDO !!\n");
                  getch();// N�O PEGA NADA � SO PARA TRAVAR O CURSO E N�O PASSAR DIRETO
                   jogadaBancada();
                    //inversao(); // E PRO FIM, SER� CHAMADO O M�TODO DE INVERS�O DE INVERS�O  QUE INVERTER� OS VALORES  PARA QUE AS BRANCAS POSSAM JOGAR !!
                break;

            }
    }

    mostrarMatriz(); // SER� ATUALIZADA  A MATRIZ AP�S A JOGADA !!!


    }else{

        printf("JOGADA INVALIDA!");
  }

    }
}


//=========== METODO PRINCIPAL===========================================================================================================================//
// NESTA PARTE DO C�DIGO SER�O REALIZADAS AS MACHADAS  AOS PRINCIPAIS M�TODOS !!
int main(){

    int num1 =0;
     while(num1 <1){
   	 	mostrarMatriz();// CHAMADA AO M�TODO mostrazMatriz(); !! NESTE CASO O CURSO SAI DESSA LINHA E VAI PARA O M�TODO mostrarMatriz();
  	 	jogadaBancada();// CHAMADA AO M�TODO jogadaBranca(); !! NESTE CASO O CURSO SAI DESSA LINHA E VAI PARA O M�TODO jogadaBranca();
   		jogadaPreta();// CHAMADA AO M�TODO jogadaPreta(); !! NESTE CASO O CURSO SAI DESSA LINHA E VAI PARA O M�TODO jogadaPreta();
   /*
    * QUANDO � REALIZADA UMA CHAMADA A UMA FUN��O OU M�TODO, O CURSOS SAI DA LINHA DA CHAMADA  E  ENTRA  NA DETERMINADA FUN��O  E EXECUTA TUDO QUE TEM DETRO DA FU��O
    * PODENDO RETORNAR VALOR OU N�O.
    * E LOGO SA� DA MESMA  RETORNANDO AO MAIN(); EXECUTANDO O QUE ESTIVER  ABAIXO  DA CHAMADA DA FUN��O!!
   */

    getch();// o getch � essencial para que o loop n�o seja cont�uno !!!! AT� PORQUE NUM1 � IGUAL A ZERO !
   }
   getch();
      return 0;
 }









