//Ataques e Tipos


#include<stdio.h>
#include<stdlib.h>

float** alocaMatriz(int linha, int coluna){
    float** matriz;
    matriz = (float **)malloc(linha*sizeof(float *));
    for(int i = 0; i < linha; i++){
        matriz[i] = malloc(coluna*sizeof(float));
    }
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void desalocaMatriz(int linha, float** matriz){
    for(int i = 0; i < linha; i++){
        free(matriz[i]);
    }
    free(matriz);
}

float avaliaAtaque(float** matriz, int poder, int index, int oponente){
    float ataque;
    return ataque = poder*matriz[index][oponente];
}

int main(void){
    int m;
    scanf("%d", &m);
    float** matriz = alocaMatriz(m, m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            scanf("%f", &matriz[i][j]);
        }
    }

    int contador = 0;
    int* poder;
    poder = (int*)malloc(sizeof(int));
    int* index; 
    index = (int*)malloc(sizeof(int));
    scanf("%d", &poder[contador]);
    while(poder[contador] != -1){
        scanf("%d", &index[contador]);
        contador++;
        index = (int*)realloc(index, (contador+1)*sizeof(int));
        poder = (int*)realloc(poder, (contador+1)*sizeof(int));
        scanf("%d", &poder[contador]);
    }
    
    int tipo_oponente;
    scanf("%d", &tipo_oponente);

    float ataque;
    float maior = 0;
    int index_maior = 0;
    for(int i = 0; i < contador; i++){
        ataque = avaliaAtaque(matriz, poder[i], index[i], tipo_oponente);
        if(ataque > maior){
            maior = ataque;
            index_maior = i;
        }
    }

    printf("O melhor ataque possui indice %d e dano %.2f", index[index_maior], maior);
    
    free(poder);
    free(index);
    desalocaMatriz(m, matriz);
    return 0;
}
