#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

main ()
{
  setlocale(LC_ALL, "Portuguese");
  int x, numero, esc, op, soma = 0, cont=0;
  int *vet;
  FILE *ponteiro_de_arquivo;
  do{
    printf("\nDigite 1 para criar, 2 para listar, 3 para apendar, 4 para somar, 5 para contar, 6 para excluir e 0 para sair \n");
    scanf("%i",&op);
    getchar();
    switch (op){
      case 1:{
        ponteiro_de_arquivo = fopen("teste.txt","w");
        printf("Entre com os numeros para gravar e 0 para sair: ");
        scanf("%d",&numero);
        while(numero){
          fprintf(ponteiro_de_arquivo,"%d ",numero);
          scanf("%d",&numero);
        }
        fclose(ponteiro_de_arquivo);
      }
      break;
      case 2:{
        ponteiro_de_arquivo = fopen("teste.txt","r");
        printf("\nNumeros gravados: ");
        while(!feof(ponteiro_de_arquivo)){
          fscanf(ponteiro_de_arquivo,"%d ",&numero);
          printf("%d ",numero);
        }
        fclose(ponteiro_de_arquivo);
        printf("\n");
      }
      break;
      case 3:{
        ponteiro_de_arquivo = fopen("teste.txt","a");
        printf("\nEntre com os numeros para gravar e 0 para sair: ");
        scanf("%i",&numero);
        while(numero){
          fprintf(ponteiro_de_arquivo,"%i",numero);
          scanf("%i",&numero);
        }
        fclose(ponteiro_de_arquivo);
        printf("\n");
      }
      break;
      case 4:{
        soma = 0;
        printf("\nImplementar a soma dos números contidos no arquivo. \n");
        ponteiro_de_arquivo = fopen("teste.txt","r");
        while(!feof(ponteiro_de_arquivo)){
          fscanf(ponteiro_de_arquivo,"%d ",&numero);
          soma = numero + soma;
        }
        fclose(ponteiro_de_arquivo);
        printf("Soma: %i", soma);
        printf("\n");
      }
      break;
      case 5:{
        cont=0;
        printf("\nImplementar a contagem dos números contidos no arquivo. \n");
        ponteiro_de_arquivo = fopen("teste.txt","r");
        while(!feof(ponteiro_de_arquivo)){
          fscanf(ponteiro_de_arquivo,"%d ",&numero);
          cont++;
        }
        printf("Número de números: %i", cont);
        fclose(ponteiro_de_arquivo);
        printf("\n");
      }
      break;
      case 6:{
        ponteiro_de_arquivo = fopen("teste.txt","r");
        cont=0;
        while(!feof(ponteiro_de_arquivo)){
          fscanf(ponteiro_de_arquivo,"%d ",&numero);
          cont++;
        }
        if(cont > 0){
          fclose(ponteiro_de_arquivo);
          vet = malloc(cont*sizeof(int));
          ponteiro_de_arquivo = fopen("teste.txt","r");
          x=0;
          while(!feof(ponteiro_de_arquivo)){
            fscanf(ponteiro_de_arquivo,"%d ",&numero);
            vet[x] = numero;
            x++;
          }
          fclose(ponteiro_de_arquivo);
          printf("Números anteriores: ");
          for(x = 0; x < cont; x++){
            printf("%i - ", vet[x]);
          }
          printf("\nSelecione a posição que deseja excluir: ");
          scanf("%i", &esc);
          ponteiro_de_arquivo = fopen("teste.txt","w");
          x=0;
          while(x < cont){
            if(x != (esc - 1)){
              fprintf(ponteiro_de_arquivo, "%i ", vet[x]);
            }
            x++;
          }
          fclose(ponteiro_de_arquivo);
        } else{
          printf("Arquivo vazio\n");
        }
      }
      break;
      case 0:{
        printf("fim");
      }
    }
  }
  while (op != 0);
}