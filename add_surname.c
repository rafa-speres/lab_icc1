//[5 - AlocaÃ§Ã£o Dinamica] Adicionando Sobrenomes
//Rafael Scalon Peres Conti

#include<stdio.h>
#include<stdlib.h>

int main(void){
    char** lista;
    lista = (char**)malloc(sizeof(char*));
    int contador = 0;
    lista[contador] = malloc(sizeof(char));

    int* index_nomes = (int*)malloc(sizeof(int));
    int* index_espaco = (int*)malloc(sizeof(int));
    int conta_index_nomes = 0;

    scanf("%c", &lista[conta_index_nomes][contador]);
    while(lista[conta_index_nomes][contador] != '$'){

        if(lista[conta_index_nomes][contador] == ' '){
            index_espaco[conta_index_nomes] = contador;
        }
        if(lista[conta_index_nomes][contador] == '\n'){
            lista[conta_index_nomes][contador] = '\0';
            index_nomes[conta_index_nomes] = contador;
            conta_index_nomes++;
            index_espaco = (int*)realloc(index_espaco, (conta_index_nomes+1)*sizeof(int));
            index_nomes = (int*)realloc(index_nomes, (conta_index_nomes+1)*sizeof(int));
            lista = (char**)realloc(lista, (conta_index_nomes+1)*sizeof(char*));
            lista[conta_index_nomes] = malloc(sizeof(char));
            contador = -1;
        }
        contador++;
        lista[conta_index_nomes] = (char*)realloc(lista[conta_index_nomes], (contador+1)*sizeof(char));
        scanf("%c", &lista[conta_index_nomes][contador]);
    }
    index_nomes[conta_index_nomes] = contador; 
    lista[conta_index_nomes][contador] = '\0';
    conta_index_nomes++;

    char* ult_sobrenome;
    ult_sobrenome = (char*)malloc(sizeof(char));
    for(int i = 0; i < conta_index_nomes; i++){
      if(i % 2 == 0){
        ult_sobrenome = (char*)realloc(ult_sobrenome,(index_nomes[i]-index_espaco[i]+2)*sizeof(char));
        for(int j = index_espaco[i]; j < index_nomes[i]; j++){
          ult_sobrenome[j-index_espaco[i]] = lista[i][j];
          ult_sobrenome[j-index_espaco[i]+1] = '\0';
        }
        printf("%s\n", lista[i]);
      } else{
        printf("%s%s\n", lista[i], ult_sobrenome);
      }
    }

    free(index_espaco);
    free(index_nomes);
    free(ult_sobrenome);
    for(int i = 0; i < conta_index_nomes; i++){
      free(lista[i]);
    }
    free(lista);

    return 0;
}
