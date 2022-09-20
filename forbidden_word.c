//Retirar Palavra Tabu

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int tamPalavra(char* tabu){
    int tamanho = 0;
    while(tabu[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho;
}

int main(void){
    char tabu[21];
    scanf("%s\n", tabu);

    int tam_tabu = tamPalavra(tabu);
    int conta_tabu = 0;

    int contador = 0;
    char* frase = (char*)malloc(sizeof(char));
    scanf("%c", &frase[contador]);
    while(frase[contador] != '$'){
        contador++;
        if(contador >= tam_tabu && !(strncmp(&frase[contador-tam_tabu], tabu, tam_tabu))){
            conta_tabu++;
            contador -= tam_tabu;
        }
        frase = (char*)realloc(frase, (contador+1)*sizeof(char));
        scanf("%c", &frase[contador]);
    }
    frase[contador] = '\0';

    printf("A palavra tabu foi encontrada %d vezes\n", conta_tabu);
    printf("Frase: %s\n", frase);

    free(frase);
    return 0;
}
