
/**
 *  \file menu.h
 *  \brief Arquivo com a função Menu
 *
 *  Arquivo com a função menu
 *
 */
#ifndef menu_h
#define menu_h


void menu() {
    /**
     * \brief Função com menu do programa
     * \return Nada
     */
    printf("****************** OPERAÇÕES DISPONÍVEIS ******************\n");
    printf("*'thr'      Binarização da imagem usando thresholding     *\n");/*Ok*/
    printf("*'gra'      Filtro grayscale(Tons de cinza)               *\n");/*Ok*/
    printf("*'inv'      Filtro que inverte as cores da imagem         *\n");/*Ok*/
    printf("*'esp'      Faz um espelhamento da imagem                 *\n");/*Ok*/
    printf("*'rot'      Rotaciona a imagem                            *\n");/*Ok*/
    printf("*'rel'      Deixar a imagem em alto relevo                *\n");/*Ok*/
    printf("*'amp'      Ampliar imagem                                *\n");/*Ok*/
    printf("*'red'      Reduzir imagem                                *\n");/*Ok*/
    printf("*'sha'      Sharpering 'Passa-Alta'                       *\n");/*Ok*/
    printf("*'blu'      Blurring 'Passa-Baixa'                        *\n");/*Ok*/
    printf("*'gau'      Filtro Gaussiano                              *\n");/*Ok*/
    printf("*'lap'      Filtro laplace                                *\n");/*Ok*/
    printf("*'exit'     Finalizar o programa.                         *\n");/*Ok*/
    printf("***********************************************************\n\n");
}
#endif /* menu_h */
