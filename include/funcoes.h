/**
 *  \file funcoes.h
 *  \brief Arquivo com as funcoes do programa
 *  Arquivo com as funcoes de manipulacao de imagens do programa
 */



#ifndef funcoes_h
#define funcoes_h


    
void grayscale(Pixel imagem[altura][largura]){
    /**
     *  \brief Função de escala em cinza usando grayscale
     *
     *  Funcao para aplicacao da escala em cinza que consiste em aplicar valores afim de reduzir a quantidade de cores.
     *
     *  \param imamgem - Matriz da imagem original para ser alterada
     *  \return Nada
     */
    int valor;

    for(i=0; i<altura; i++)
        for(j=0;j<largura;j++){
            
            valor = 0.2989*imagem[i][j].r + 0.5870*imagem[i][j].g + 0.1140*imagem[i][j].b;
            
            imagem[i][j].r = valor;
            imagem[i][j].g = valor;
            imagem[i][j].b = valor;
    
        }
    
}

        

void binarization(Pixel imagem[altura][largura], int thr){
    /**
     *  \brief Função de Binarizacao usando thresholding
     *
     *  Binariza a imagem, com as cores preto e branco.
     *
     *
     *  \param imamgem - Matriz da imagem original para ser alterada
     *  \return Nada
     */
    
        int bin = 0;

    for(i=0; i < altura; i++){
        for(j=0;j < largura;j++){
            
            
            
            bin  = (imagem[i][j].r + imagem[i][j].g + imagem[i][j].b)/3;

            
            if (bin > thr){
                imagem[i][j].r = 255;
                imagem[i][j].g = 255;
                imagem[i][j].b = 255;
            }else{
                imagem[i][j].r = 0;
                imagem[i][j].g = 0;
                imagem[i][j].b = 0;
            }
        }
    }
}





void inverter(Pixel imagem[altura][largura]){
    /**
     *  \brief Função para inverter cores
     *
     *  Funcao para inverter cores da imagem apenas diminuindo do valor 255.
     *
     *
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */

    for(i=0; i<altura; i++){
        for(j=0;j<largura;j++){
            
      
            
            imagem[i][j].r = 255 - imagem[i][j].r;
            imagem[i][j].g = 255 - imagem[i][j].g;
            imagem[i][j].b = 255 - imagem[i][j].b;
    
        }
    }
}


void espelhar(Pixel imagem[altura][largura]){
    /**
     *  \brief Função espelhar imagem
     *
     *  Funcao para espelhar a imagem, que consiste em aplicar a matriz transposta afim de espelhar a mesma.
     *
     *
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */
    Pixel auxiliar[altura][largura];
    for(i=0; i<altura; i++){
        for(j=0;j<largura;j++){
            
      
            
            auxiliar[i][j].r =  imagem[i][largura - j].r;
            auxiliar[i][j].g =  imagem[i][largura - j].g;
            auxiliar[i][j].b =  imagem[i][largura - j].b;
    
        }
    }
    for(i=0; i<altura; i++){
        for(j=0;j<largura;j++){
            
      
            
            imagem[i][j].r =  auxiliar[i][j].r;
            imagem[i][j].g =  auxiliar[i][j].g;
            imagem[i][j].b =  auxiliar[i][j].b;
    
        }
    }

}



    /*​*
     *
     */

void rotacionar_esq(Pixel imagem[max][max]){
    /**
     *  \brief Função rotacionar imagem para esquerda
     *
     *
     *   Funcao para rotacionar a imagem para esquerda, basicamente apenas recebendo um valor, alocando o mesmo em uma matriz auxiliar e aplicando esta matriz auxilar dentro da original com o tratamento da mesma com valores de largura -j-1 e invertendo com o valor da altura.
     *
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */

    int i, j;
    int aux;
    Pixel auxiliar[max][max];
    
    for (i = 0; i < altura; i++){
      
        for (j = 0; j < largura; j++){
            auxiliar[i][j].r = imagem[i][j].r;
            auxiliar[i][j].g = imagem[i][j].g;
            auxiliar[i][j].b = imagem[i][j].b;
        }
    }

    for (i = 0; i < altura; i++){
        for (j = 0; j < largura; j++){
            imagem[largura-j-1][i].r = auxiliar[i][j].r;
            imagem[largura-j-1][i].g= auxiliar[i][j].g;
            imagem[largura-j-1][i].b= auxiliar[i][j].b;
        
        }
    }

    
    aux = altura;
    altura = largura;
    largura = aux;

}


void rotacionar_180(Pixel imagem[altura][largura]){
    /**
     *  \brief Função rotacionar 180
     *
     *  Funcao para rotacionar a imagem 180 graus, aplica a funcao para rotacionar a esquerda duas vezes.
     *
     *
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */
    
    for(i=0;i<2;i++)
    rotacionar_esq(imagem);
    
}

void rotacionar_270(Pixel imagem[altura][largura]){
    /**
     *  \brief Função rotacionar 270
     *
     *  Funcao para rotacionar a imagem 180 graus, aplica a funcao para rotacionar a esquerda tres vezes.
     *
     *
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */
   for(i=0;i<3;i++)
    rotacionar_esq(imagem);
}


    /**
     *
     */

void relevo(Pixel imagem[altura][largura]){
    /**
     *  \brief Função relevo
     *
     *  Funcao para aplicar alto relevo, que consiste em verificar os valores dos pixels já com bordas tratadas e acentua as cores dos mesmos para realcar as bordas onde ha diferencas de cores.
     *
     *
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */
    Pixel imagemaux[altura][largura];
    int i, j;
    for (i = 1; i < altura - 1; i++){
        for (j = 0; j < largura; j++){
            imagemaux[i][j].r = imagem[i + 1][j].r - imagem[i -1][j].r;
            imagemaux[i][j].g = imagem[i + 1][j].b - imagem[i -1][j].b;
            imagemaux[i][j].b = imagem[i + 1][j].b - imagem[i -1][j].b;
            
            if (imagemaux[i][j].r < 0 || imagemaux[i][j].g < 0 || imagemaux[i][j].b < 0){
                imagemaux[i][j].r = 0;
                imagemaux[i][j].g = 0;
                imagemaux[i][j].b = 0;
            }
        }

    }
    
    
    for (i = 1; i < altura - 1; i++){
        for(j = 0; j < largura; j++){
            
            imagem[i][j].r = imagemaux[i][j].r + 128;
            imagem[i][j].g = imagemaux[i][j].g + 128;
            imagem[i][j].b = imagemaux[i][j].b + 128;
            
            if (imagemaux[i][j].r > 255 || imagemaux[i][j].g > 255 || imagemaux[i][j].b > 255){
                imagemaux[i][j].r = 255;
                imagemaux[i][j].g = 255;
                imagemaux[i][j].b = 255;
            }

        }
    }
    
    
}



void ampliar_img(char arquivo[], int zoom,Pixel imagem[altura][largura]){
    /**
     *  \brief Função ampliar
     *
     *  Funcao para ampliar a imagem repetindo os pixels laterais, consiste apenas em repetir o mesmo valor nas laterais do pixel.
     *
     *  \param arquivo - Nome para salvar o novo arquivo
     *  \param zoom - Valor do zoom dado pelo usuário
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */
FILE *img;

img =  fopen(arquivo,"w");

	fprintf(img, "%s\n", "P3");
	fprintf(img, "%i %i\n", largura*zoom, altura*zoom);
	fprintf(img, "%s\n", "255");
	



	for (i = 0; i < altura; ++i){
		for (h = 0; h < zoom; ++h)
		{
			
		
		for (j = 0; j < largura; ++j){
			for (g = 0; g < zoom; ++g)
			{
			fprintf(img, "%i ",imagem[i][j].r);
			fprintf(img, "%i ",imagem[i][j].g);
			fprintf(img, "%i\n",imagem[i][j].b);
			}
		}

	}
}
fclose(img);

}


    /*​*
     *
     */
void reduzir_img(char arquivo[], int zoom,Pixel imagem[altura][largura]){
    /**
     *  \brief Função reduzir
     *
     *  Funcao para reduzir imagem, e o processo inverso da de ampliar imagem, no entando calculando uma area e aplicando novos valores baseados nesta area.
     *  \param arquivo - Nome para salvar o novo arquivo
     *  \param zoom - Valor do zoom dado pelo usuário
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */
    int area = zoom*zoom;
    Pixel soma = {0, 0, 0};
FILE *img;

img =  fopen(arquivo,"w");

    fprintf(img, "%s\n", "P3");
    fprintf(img, "%i %i\n", largura/zoom, altura/zoom);
    fprintf(img, "%s\n", "255");
    



    for (i = 0; i <= altura - zoom; i = i + zoom){
        for (h = 0; h <= largura - zoom; h = h + zoom, soma.r = 0, soma.g = 0, soma.b = 0){
             for (j = 0; j < zoom; j++){
                for (g = 0; g < zoom; g++){
                soma.r = soma.r + imagem[i+j][h+g].r;
                soma.g = soma.g + imagem[i+j][h+g].g;
                soma.b = soma.b + imagem[i+j][h+g].b;
                }
            }
        fprintf(img, "%i ", (soma.r/area > 255) ? 255 : soma.r/area);
        fprintf(img, "%i ", (soma.g/area > 255) ? 255 : soma.g/area );
        fprintf(img, "%i\n",(soma.b/area > 255) ? 255 : soma.b/area);                          
        }
    }
    fclose(img);
}


void passa_alta(Pixel imagem[altura][largura]) {
    /**
     *  \brief Função Passa Alta
     *
     *  Funcao para aplicar o sharpening, consiste em aplicar uma mascara no pixel afim de afiar a imagem.
     *
     *
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */

    Pixel auxiliar[altura][largura];

 

    for (i = 1; i < altura - 1; i++){
        for (j = 1; j < largura - 1; j++){

            auxiliar[i][j].r = 5*imagem[i][j].r - imagem[i-1][j].r - imagem[i][j-1].r - imagem[i][j+1].r - imagem[i+1][j].r;
            auxiliar[i][j].g = 5*imagem[i][j].g - imagem[i-1][j].g - imagem[i][j-1].g - imagem[i][j+1].g - imagem[i+1][j].g;
            auxiliar[i][j].b = 5*imagem[i][j].b - imagem[i-1][j].b - imagem[i][j-1].b - imagem[i][j+1].b - imagem[i+1][j].b;

        }
    }

    for (i = 1; i < altura - 1; i++){
        for (j = 1; j < largura - 1; j++){

            imagem[i][j].r = auxiliar[i][j].r;
            imagem[i][j].g =  auxiliar[i][j].g ;
            imagem[i][j].b = auxiliar[i][j].b ;

        }
    }


}


        
void passa_baixa(Pixel imagem[altura][largura]){
    /**
     *  \brief Função Passa Baixa
     *
     *  Funcao para aplicar o blurring, consiste em aplicar uma mascara 4x4 afim de tratar alguns erros na imagem, limpando a mesma.
     *
     *
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */
    Pixel auxiliar[altura][largura];

    for (i = 2; i < altura - 2 ; ++i){
        
        for (j = 2; j < largura - 2 ; ++j){
             

            auxiliar[i][j].r = (imagem[i-1][j-1].r + imagem[i-1][j].r   + imagem[i-1][j+1].r   + imagem[i-1][j+2].r +
                                imagem[i][j-1].r   + imagem[i][j+1].r + imagem[i][j+1].r +       imagem[i][j+2].r +
                                imagem[i+1][j-1].r   + imagem[i+1][j+1].r   + imagem[i+1][j+1].r + imagem[i+1][j+2].r +
                                imagem[i+2][j-1].r   + imagem[i+2][j+1].r   + imagem[i+2][j+1].r + imagem[i+2][j+2].r )/16;
        
            auxiliar[i][j].g =   (imagem[i-1][j-1].g + imagem[i-1][j].g   + imagem[i-1][j+1].g   + imagem[i-1][j+2].g +
                                imagem[i][j-1].g   + imagem[i][j+1].g + imagem[i][j+1].g +       imagem[i][j+2].g +
                                imagem[i+1][j-1].g   + imagem[i+1][j+1].g   + imagem[i+1][j+1].g + imagem[i+1][j+2].g +
                                imagem[i+2][j-1].g   + imagem[i+2][j+1].g   + imagem[i+2][j+1].g + imagem[i+2][j+2].g )/16;
            
            auxiliar[i][j].b =  (imagem[i-1][j-1].b + imagem[i-1][j].b   + imagem[i-1][j+1].b   + imagem[i-1][j+2].b +
                                imagem[i][j-1].b   + imagem[i][j+1].b + imagem[i][j+1].b +       imagem[i][j+2].b +
                                imagem[i+1][j-1].b   + imagem[i+1][j+1].b   + imagem[i+1][j+1].b + imagem[i+1][j+2].b +
                                imagem[i+2][j-1].b   + imagem[i+2][j+1].b   + imagem[i+2][j+1].b + imagem[i+2][j+2].b )/16;
        }

    }
    for (i = 2; i < altura - 2; i++){
        
        for (j = 2; j < largura - 2; j++){

            imagem[i][j].r = auxiliar[i][j].r;
            imagem[i][j].g =  auxiliar[i][j].g ;
            imagem[i][j].b = auxiliar[i][j].b ;

        }
    }


}



void gaussiano(Pixel imagem[altura][largura]){
    /**
     *  \brief Função de Gauss
     *
     *  Funcao para aplicar o filtro de Gauss. O filtro de gaus e um filtro de tratamento da imagem semelhante ao blurring, no entando e um filtro mais bem trabalhado e tem um poder de limpeza bem maior.
     *
     *
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */

    Pixel gauss[altura][largura];
    
    for (i = 1; i < altura - 1 ; ++i){
        
        for (j = 1; j < largura - 1 ; ++j){
            
            
            gauss[i][j].r =     4*(imagem[i][j].r)+
                                2*(imagem[i][j-1].r + imagem[i][j+1].r + imagem[i-1][j].r + imagem[i+1][j].r)+
                                1*(imagem[i-1][j+1].r + imagem[i+1][j+1].r + imagem[i+1][j-1].r + imagem[i-1][j-1].r);
            
                                gauss[i][j].r = (int) (gauss[i][j].r/16);
            
            gauss[i][j].g =     4*(imagem[i][j].g)+
                                2*(imagem[i][j-1].g + imagem[i][j+1].g + imagem[i-1][j].g + imagem[i+1][j].g)+
                                1*(imagem[i-1][j+1].g + imagem[i+1][j+1].g + imagem[i+1][j-1].g + imagem[i-1][j-1].g);
  
                                gauss[i][j].g = (int) (gauss[i][j].g/16);
            
            gauss[i][j].b =     4*(imagem[i][j].b)+
                                2*(imagem[i][j-1].b + imagem[i][j+1].b + imagem[i-1][j].b + imagem[i+1][j].b)+
                                1*(imagem[i-1][j+1].b + imagem[i+1][j+1].b + imagem[i+1][j-1].b + imagem[i-1][j-1].b);
            
                                gauss[i][j].b = (int) (gauss[i][j].b/16);
        }
        
    }
    for (i = 1; i < altura - 1 ; i++){
        
        for (j = 1; j < largura - 1  ; j++){
            
            imagem[i][j].r = gauss[i][j].r;
            imagem[i][j].g = gauss[i][j].g;
            imagem[i][j].b = gauss[i][j].b;
            
        }
    }
    
    
}



void laplace(Pixel imagem[altura][largura]){
    /**
     *  \brief Função de Laplace
     *
     * Funcao para aplicar o filtro de Laplace. O filtro de laplace e muito usado para se identificar detalhes na imagens, para isso e preciso aplicar a funcao de escala em cinza para ter uma maior nitidez.
     *
     *
     *  \param img -  Matriz da imagem original para ser alterada
     *  \return Nada
     */
    
     grayscale(imagem);
    
    
    Pixel gauss[altura][largura];
    
    for (i = 1; i < altura - 1 ; ++i){
        
        for (j = 1; j < largura - 1 ; ++j){
            
            
            gauss[i][j].r =     4*(imagem[i][j].r) - imagem[i][j-1].r - imagem[i][j+1].r - imagem[i-1][j].r + imagem[i+1][j].r;
            gauss[i][j].g =     4*(imagem[i][j].g) - imagem[i][j-1].g - imagem[i][j+1].g - imagem[i-1][j].g + imagem[i+1][j].g;
            gauss[i][j].b =     4*(imagem[i][j].b) - imagem[i][j-1].b - imagem[i][j+1].b - imagem[i-1][j].b + imagem[i+1][j].b;
            
            gauss[i][j].r /= 4;
            gauss[i][j].r = (gauss[i][j].r * gauss[i][j].r);
            
            gauss[i][j].g /= 4;
            gauss[i][j].g = (gauss[i][j].g * gauss[i][j].g);
            
            gauss[i][j].b /= 4;
            gauss[i][j].b = (gauss[i][j].b * gauss[i][j].b);
 
            
        }
        
    }
    for (i = 1; i < altura - 1 ; i++){
        
        for (j = 1; j < largura - 1  ; j++){
            
            imagem[i][j].r = gauss[i][j].r;
            imagem[i][j].g = gauss[i][j].g;
            imagem[i][j].b = gauss[i][j].b;

            
        }
    }
    
    
}
#endif /* funcoes_h */
