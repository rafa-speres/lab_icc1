//[3 - Matriz] A Esteira de Plinio
//Rafael Scalon Peres Conti
#include <stdio.h>

int main(void){
    char caminho[32][32];
    char lixo;
    int atualI = 0;
    int atualJ = 0;
    char instAnterior;
    int checkFim = 0;
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 65; j++){
            if(j % 2 == 0){
                scanf("%c", &caminho[i][j/2]);
            } else{
            scanf("%c", &lixo);
            }
        }
    }
    //determinando a posicao de inicio (a direita da marcacao de inicio da esteira)
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            if(caminho[i][j]=='['){
                atualI = i;
                atualJ = j+1;
            }
        }
    }
    
    while(caminho[atualI][atualJ] != '.' && caminho[atualI][atualJ] != ']' && caminho[atualI][atualJ] != ' '){
        if(caminho[atualI][atualJ] == '>'){
            instAnterior = caminho[atualI][atualJ];
            caminho[atualI][atualJ] = '.';
            atualJ++;
        } else if(caminho[atualI][atualJ] == '<'){
            instAnterior = caminho[atualI][atualJ];
            caminho[atualI][atualJ] = '.';
            atualJ--;
        } else if(caminho[atualI][atualJ] == '^'){
            instAnterior = caminho[atualI][atualJ];
            caminho[atualI][atualJ] = '.';
            atualI--;
        } else if(caminho[atualI][atualJ] == 'v'){
            instAnterior = caminho[atualI][atualJ];
            caminho[atualI][atualJ] = '.';
            atualI++;
        } else if(caminho[atualI][atualJ] == '#'){
            //nao altera a instrucao anterior
            if(instAnterior == '>'){
                atualJ++;
            } else if(instAnterior == '<'){
                atualJ--;
            } else if(instAnterior == '^'){
                atualI--;
            } else if(instAnterior == 'v'){
                atualI++;
            }
        } if(caminho[atualI][atualJ] == ']'){
            checkFim = 1;
            printf("Ok.\n");
        }
    }

    //caso a esteira nao esteja ok.
    if(caminho[atualI][atualJ] == '.'){
        printf("Loop infinito.\n");
    } else if(checkFim == 0){
        printf("Falha na esteira.\n");
    }

    //esteira apos a passagem do robo
    for (int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            printf("%c ", caminho[i][j]);
        }
        printf("\n");
    }
    return 0;
}
