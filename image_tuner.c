//[4 - Funcoes] Sintonizando Imagem
//Rafael Scalon Peres Conti
#include<stdlib.h>

char** deslocamento_horizontal(int quantidade, int linhas, int colunas, char **imagem){
    char aux;
    for(int i = 0; i < quantidade; i++){
        for(int j = 0; j < linhas; j++){
            aux = imagem[j][0];
            for(int k = 0; k < colunas-1; k++){
                imagem[j][k] = imagem[j][k+1];
            }
            imagem[j][colunas-1] = aux;
        }
    }
    return imagem;
}

char** deslocamento_vertical(int quantidade, int linhas, int colunas, char **imagem){
    char aux;
    for(int i = 0; i < quantidade; i++){
        for(int j = 0; j < colunas; j++){
            aux = imagem[0][j];
            for(int k = 0; k < linhas-1; k++){
                imagem[k][j] = imagem[k+1][j];
            }
            imagem[linhas-1][j] = aux;
        }
    }
    return imagem;
}

int main(void){
    int M, N, B, D;
    scanf("%d %d", &M, &N);
    scanf("%d %d", &B, &D);

    char aux;
    //alocando matriz dinamicamente.
    char **imagem;
    imagem = (char**)malloc(M * sizeof(char*));
    for(int i = 0; i < M; i++){
        imagem[i] = malloc(N * sizeof(char));
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%c", &aux);
          if(aux == '\n'){
            scanf("%c", &aux);
          }
          imagem[i][j] = aux;
        }
    }
    
    imagem = deslocamento_horizontal(D, M, N, imagem);
    imagem = deslocamento_vertical(B, M, N, imagem);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            printf("%c", imagem[i][j]);
        }
        printf("\n");
    }
    //desalocando a matriz
    for(int i = 0; i < M; i++){
        free(imagem[i]);
    }
    free(imagem);

    return 0;
}
