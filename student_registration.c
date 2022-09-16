//[6 - Struct] Gerenciamento de estudantes
//Rafael Scalon Peres Conti

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudante{
  int id;
  char* nome;
  char* curso;
  int idade;
}; typedef struct Estudante Estudante;

//E necessario passar o ponteiro de ponteiro, pois passando somente * os reallocs podem (e muitvas vezes acabam) em segfault
void leituraEAlocacaoLinha(char** linha){ //para leitura dos nomes de aluno e de curso (alocacao dinamica da linha lida, por nao ter tamanho determinado)
  (*linha) = (char*)malloc(sizeof(char));
  int index = 0;
  char parcial;
  do{
    scanf("%c", &parcial);
    (*linha)[index] = parcial;
    index++;
    //realloc para receber mais um caracter
    (*linha) = (char*)realloc(*linha, (index+1)*sizeof(char));
  }while (parcial != 10); //parcial != \n
  //trocando o \n por um \0 (finaliza a linha)
  (*linha)[index-1] = '\0';
}

void consultaID(Estudante* estudante, int num_id, int quant_est){
  int bool_est = 0;
  for(int i = 0; i < quant_est; i++){
    if(estudante[i].id == num_id){
      bool_est = 1;
      printf("Nome: %s\n", estudante[i].nome);
      printf("Curso: %s\n", estudante[i].curso);
      printf("N USP: %d\n", estudante[i].id);
      printf("IDADE: %d\n\n", estudante[i].idade);
    }
  }
  if(bool_est == 0){
    printf("Aluno nao cadastrado\n");
  }
}

void consultaCurso(Estudante* estudante, char* nome_curso, int quant_est){
  //int bool_est = 0;
  for(int i = 0; i < quant_est; i++){
    if(strcmp(estudante[i].curso, nome_curso) == 0){
      //bool_est = 1;
      printf("Nome: %s\n", estudante[i].nome);
      printf("Curso: %s\n", estudante[i].curso);
      printf("N USP: %d\n", estudante[i].id);
      printf("IDADE: %d\n\n", estudante[i].idade);
    }
  }
  /*if(bool_est ==0){
    printf("Aluno nao cadastrado\n");
  }*/
}

void consultaTodos(Estudante* estudante, int quant_est){
  for(int i = 0; i < quant_est; i++){
    printf("Nome: %s\n", estudante[i].nome);
    printf("Curso: %s\n", estudante[i].curso);
    printf("N USP: %d\n", estudante[i].id);
    printf("IDADE: %d\n\n", estudante[i].idade);
  }
}

int main(void) {
  Estudante* estudante;
  estudante = malloc(sizeof(Estudante));
  int index_est = 0;
  scanf(" %d\n", &estudante[index_est].id);
  while(estudante[index_est].id != -1){
    leituraEAlocacaoLinha(&estudante[index_est].nome);
    leituraEAlocacaoLinha(&estudante[index_est].curso);
    scanf("%d", &estudante[index_est].idade);
    index_est++;
    estudante = realloc(estudante, (index_est+1)*sizeof(Estudante));
    scanf(" %d\n", &estudante[index_est].id);
  }

  int operacao;
  int id_aluno;
  char* nome_curso;

  do{
    scanf("%d", &operacao);
    switch(operacao){
      case 1:
        scanf("%d", &id_aluno);
        consultaID(estudante, id_aluno, index_est);
        break;

      case 2:
        leituraEAlocacaoLinha(&nome_curso);
        consultaCurso(estudante, nome_curso, index_est);
        break;

      case 3:
        consultaTodos(estudante, index_est);
        break;
    }
  }while(operacao != -1);

  for(int i = 0; i < index_est; i++){
    free(estudante[i].curso);
    free(estudante[i].nome);
  }
  free(nome_curso);
  free(estudante);
  return 0;
}
