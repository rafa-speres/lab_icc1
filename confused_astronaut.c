//Astronauta confuso

#include <stdio.h>

int main(void){
  int N;
  int P;
  scanf("%d ", &N);
  scanf("%d", &P);

  int L = N*N;
  //para descobrir a posicao
  int mapa[N][N];
  //inicializando todos os valores como 0 (e importante para saber se esse valor ja foi utilizado ou nao)
  for(int a = 0; a < N; a++){
    for(int b = 0; b < N; b++){
      mapa[a][b] = 0;
    }
  }
  int i = 0, j = 0; //coordenadas iniciais 
  int mudaI = 0, mudaJ = 1; //instrucoes iniciais para avanco no mapa
  int alvoI, alvoJ; //coordenadas da prox pos
  int aux;
  int iAstronauta, jAstronauta; //coordenadas que devem ser mostradas
  
  for(int k = 1; k <= N*N; k++){
    mapa[i][j] = k;
    if (k == P){
      //salva a posicao do astronauta
      iAstronauta = i;
      jAstronauta = j;
    }
    //procedimento para determinar a posicao alvo (prox pos)
    alvoI = i + mudaI;
    alvoJ = j + mudaJ;

    //determina se a posicao alvo e valida, se nao for, altera as instrucoes para avanco no mapa
    if(alvoI >= N || alvoJ >= N || alvoI < 0 || alvoJ < 0 || mapa[alvoI][alvoJ]!= 0){
      aux = mudaJ;
      mudaJ = -mudaI;
      mudaI = aux;
    }
    //altera as coordenadas a partir das regras de avanco, preparando para nova entrada no loop
    i = i + mudaI;
    j = j + mudaJ;

  }

  //define o output adequado e suas respectivas informacoes.
  if(P>L){
    printf("O astronauta ja saiu em missao ha %d chamadas.\n", P-L);
  } else if(P==L){
    printf("O astronauta esta na posicao: %d %d\nPreste atencao, astronauta, chegou a sua vez!\n", iAstronauta, jAstronauta);
  } else{
    printf("O astronauta esta na posicao: %d %d\nAinda faltam %d chamadas para a sua vez!\n", iAstronauta, jAstronauta, L-P);
  }
  return 0;
}
