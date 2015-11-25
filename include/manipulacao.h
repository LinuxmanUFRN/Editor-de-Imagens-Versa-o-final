/**
 *  \file manipulacao.h
 *  \brief Arquivo com a função para manipulação da imagem
 *  Arquivo com a função de manipulação da imagem
 */
 
#include "Projeto.h"

#ifndef manipulacao_h
#define manipulacao_h


/**
 *Gera um novo aquivo .ppm com as devidas alocações de dados.
 */

void gerar_img (Pixel imagem[max][max], char saida[]){
    strcat(saida, "_manip.ppm");
    FILE * arq_imagem;
    
    arq_imagem = fopen(saida, "w");
    
    
    fprintf(arq_imagem, "P3\n");
    fprintf(arq_imagem, "%i %i\n%i\n",largura, altura, 255);




    for(i = 0; i < altura; i++){
        for(j = 0; j < largura; j++){
            fprintf(arq_imagem, "%i %i %i\n", imagem[i][j].r, imagem[i][j].g, imagem[i][j].b);
        }
    }
    
    fclose(arq_imagem);
}


#endif /* manipulacao_h */