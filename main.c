/**
 *  \mainpage Projeto do Processador de Imagens
 *  \author Adelino Fernandes e Ermeson Davi
 *  \date 26/11/2015
 *  \version Beta 
 *
 *  \file main.c
 *  \brief Arquivo principal
 */



#include "include/Projeto.h"/**Biblioteca para uso de struct e variáveis usadas no programa*/
#include "include/filtros.h"/**Biblioteca com os cabeçalho das funções*/
#include "include/menu.h"/**Biblioteca com menu do programa*/
#include "include/manipulacao.h"/**Biblioteca para gerar um novo arquivo de imagem*/
#include "include/funcoes.h"/**Biblioteca das funções de manipuladoras de imagens*/


/**
 *  \brief Metodo main onde é carregado o arquivo de imagem
 *  \param Nenhum
 *  \return EXIT_SUCCESS
 */


int main(int argc, char** argv) {
   
    
    /**Abertura do arquivo da imagem*/
    printf("%s\n","Informe o nome do arquivo de imagem a ser aberto:");
    scanf("%s",Nome_arquivo);
    
    /**Função limpa tela*/
    reset();
    
    FILE *arquivo;
    
    /**Ler o arquivo*/
    arquivo = fopen(Nome_arquivo, "r");
    
    /**Faz o teste de erro na abertura do arquivo*/
    if(arquivo == NULL){
        printf("%s\n","Erro ao abrir o arquivo de imagem.");
    }else{
        printf("%s\n","Arquivo de imagem aberto com sucesso."); 
    }
    
        /**Ler os dados do cabeçalho*/
        fscanf(arquivo, "P3 %i %i 255",&largura, &altura);
    
    /**Comparação para ver o maior valor da matriz*/
    if (largura > altura) {
        
        max = largura;
    }else{
        max = altura;
    }
    
    /**Cria uma variável do tipo struct*/
    Pixel imagem[max][max];
    

    /**Ler cada Pixel alocando na variável referente ao struct*/
    for (i = 0; i < altura; i++){
        for(j = 0; j < largura; j++){
            fscanf(arquivo, "%i %i %i", &imagem[i][j].r, &imagem[i][j].g, &imagem[i][j].b);
        }
    }
    /**fecha o arquivo*/
    fclose(arquivo);
    




    do{
        
        /**Menu do programa sendo chamado*/
        menu();

        printf("\nDigite o comando:>");
        /**Comando para leitura do menu*/
        scanf("%s",comando);
        reset();
   
        /**converte as letras para minusculo afim de facilitar a comparação*/
        for(i=0;comando[i];i++)
            comando[i]=tolower(comando[i]);
   
        
       
        if(strcmp(comando,"lap")==0){
            printf("\nExecutando o comando: %s\n", comando);
            /**Chama o Filtro de laplace*/
            laplace(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"gau")==0){
            printf("\nExecutando o comando: %s\n", comando);
            /**Chama o filtro de gaus*/
            gaussiano(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"blu")==0){
            printf("\nExecutando o comando: %s\n", comando);
            /**Chama o filtro Blurring*/
            passa_baixa(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"sha")==0){
            printf("\nExecutando o comando: %s\n", comando);
            /**Chama o filtro sharpening*/
            passa_alta(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"amp")==0){
            printf("\nExecutando o comando: %s\n", comando);
           
            printf("\nInforme o zoom desejado:\n");
            /**Ler o zoom para ampliar a imagem*/
            scanf("%i",&zoom);
           
           
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            /**Chama a função para ampliar da imagem*/
            ampliar_img(strcat(arq,".ppm"),zoom,imagem);
            
            printf("%s\n", "Imagem ampliada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"red")==0){
            printf("\nExecutando o comando: %s\n", comando);
           
            printf("\nInforme o zoom desejado:\n");
            /**Ler o zoom para reduzir a imagem*/
            scanf("%i",&zoom);
           
           
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            /**Chama a função para redução da imagem*/
            reduzir_img(strcat(arq,".ppm"),zoom,imagem);
            
            printf("%s\n", "Imagem reduzida com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"rel")==0){
            printf("\nExecutando o comando: %s\n", comando);
            /**Chama o filtro para aplicar o relevo na imagem*/
            relevo(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"thr")==0){
            printf("\nExecutando o comando: %s\n", comando);
            printf("\nInforme o valor do thresholding:\n");
            scanf("%i",&thr);
            /**Chama o filtro da binarização*/
            binarization(imagem, thr);
            printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem binarizada com sucesso.");
            return (EXIT_SUCCESS);

        }else if(strcmp(comando,"gra")==0){
            printf("\nExecutando o comando: %s\n", comando);
            /**Chama o filtro para grayscale*/
            grayscale(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"inv")==0){
            printf("\nExecutando o comando: %s\n", comando);
            /**Chama o filtro para inverter as cores*/
            inverter(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);

        }else if(strcmp(comando,"esp")==0){
            printf("\nExecutando o comando: %s\n", comando);
            /**Chama a função para espelhar a imagem*/
            espelhar(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem espelhada com sucesso.");
            return (EXIT_SUCCESS);

        }else if(strcmp(comando,"rot")==0){
            printf("%s\n", "Informe o ângulo desejado desejado (90, 180, 270):");
            /**Detalha o ângulo de rotação*/
            scanf("%i",&angulo);
			
		if(angulo == 90){
			printf("\nExecutando o comando: %s\n", comando);
            /**Chama a função para rotacionar a imagem*/
            rotacionar_esq(imagem);
			printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
			gerar_img(imagem, arq);
            printf("%s\n", "Imagem rotacionada com sucesso.");
           	return (EXIT_SUCCESS);
            
		}else if(angulo == 180){
			printf("\nExecutando o comando: %s\n", comando);
            rotacionar_180(imagem);
			printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
			gerar_img(imagem, arq);
            printf("%s\n", "Imagem rotacionada com sucesso.");
           	return (EXIT_SUCCESS);
		
		}else if(angulo == 270){
			printf("\nExecutando o comando: %s\n", comando);
            rotacionar_270(imagem);
			printf("%s\n", "Informe o nome desejado para saída:");
            /**Ler o novo nome para a imagem*/
            scanf("%s",arq);
			gerar_img(imagem, arq);
            printf("%s\n", "Imagem rotacionada com sucesso.");
           	return (EXIT_SUCCESS);
		}
        }else{
            /** chama a funcao limpa tela*/
            reset();
            printf("\nComando desconhecido: %s\n",comando);
            
        }    

    }while(strcmp(comando,"exit")!=0);



        printf("%s\n", "Programa finalizado");
    
    /**Finaliza o programa*/
    return (EXIT_SUCCESS);
}
