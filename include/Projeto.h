/**
 *  \file Projeto.h
 *  \brief Arquivo com struct e variaveis globais
 *   Arquivo com variaveis globais usadas no programa
 */

#ifndef Projeto_h
#define Projeto_h

#include <stdio.h>/**Biblioteca de funções padrão da linguagem C*/
#include <stdlib.h>/**Biblioteca para uso específico de algumas funções*/
#include <string.h>/**Biblioteca para uso de strings*/
#include <ctype.h>/**Biblioteca usada para tratamento de algumas especificidades do programa*/
#include <math.h>/**Biblioteca para uso de funções matemáticas*/



#define Max_nome 256 /**Tamanho do Nome do arquivo*/



/**Variáveis usadas para alocar largura e altura da matriz*/
int altura, largura;

/**Variáveis usadas para contadores*/
int g,h,i,j;

/**Variável para alocar o nome do arquivo*/
char Nome_arquivo[100];

/**Variável para alocar o nome do arquivo 2*/
char arq[100];

/**Variável para alocar o comando desejado*/
char comando[256];

/**Variável para determinar o angulo de rotação*/
int angulo;

/**Variável para determinar a quantidade de vezes que a imagem é ampliada*/
int zoom;

/**Variável para alocar um valor máximo da matriz*/
int max;

/**Variável para valor de thresholding*/
int thr;


/**Struct com as cores do RGB*/
 typedef struct {
    int r;/**<  Quantidade de Vermelho (r). */
    int g;/**<  Quantidade de Verde (r). */
    int b;/**<  Quantidade de Azul (r). */
} color;
typedef color Pixel;


/**Função limpa tela*/

void reset() {

    
#if defined WIN32
    system("cls");/**No Windows*/
#else
    system("clear");/**No Linux*/
#endif
}

/**Limpa o buffer do teclado retirada do site 
 *http://pt.stackoverflow.com/questions/9427/limpeza-do-buffer-do-teclado-após-scanf
 */
void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}


#endif /* Projeto_h */
