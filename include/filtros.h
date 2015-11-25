/**
 *  \file filtros.h
 *  \brief Arquivo com os cabecalhos funcoes
 *  Created on 30 de Outubro de 2015, 09:34
 *  Arquivo com as funcoes do programa
 */



#ifndef filtros_h
#define filtros_h
/**Cabecalhos das funcoes*/
void grayscale(Pixel imagem[altura][largura]);
void binarization(Pixel imagem[altura][largura], int thr);
void inverter(Pixel imagem[altura][largura]);
void espelhar(Pixel imagem[altura][largura]);
void rotacionar_esq(Pixel imagem[max][max]);
void rotacionar_180(Pixel imagem[altura][largura]);
void rotacionar_270(Pixel imagem[altura][largura]);
void relevo(Pixel imagem[altura][largura]);
void ampliar_img(char arquivo[], int zoom,Pixel imagem[altura][largura]);
void reduzir_img(char arquivo[], int zoom,Pixel imagem[altura][largura]);
void passa_alta(Pixel imagem[altura][largura]);
void passa_baixa(Pixel imagem[altura][largura]);
void gaussiano(Pixel imagem[altura][largura]);
void laplace(Pixel imagem[altura][largura]);

#endif /* filtros_h */
