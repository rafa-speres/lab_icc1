//[6 - Struct] Pokedex
//Rafael Scalon Peres Conti

#include <stdio.h>
#include <stdlib.h>
//quantdade de pokemons da primeira geracao
#define tam_MAX 151 

struct Ataque{
  char nome[20];
  int poder_base;
  float acuracia;
  char classe;
};

struct Atributos{
  int hp;
  int ataque;
  int defesa;
  int atq_especial;
  int def_especial;
  int velocidade;
};

struct Pokemon{
  char nome[50];
  char tipo_primario[20];
  char tipo_secundario[20];
  struct Atributos atributos_pokemon;
  struct Ataque ataque_pokemon[4];
};
typedef struct Pokemon Pokemon;

void cadastroPokemon(Pokemon pokemon[tam_MAX], int index_pokemon){
  scanf("%s", pokemon[index_pokemon].nome);
  scanf("%s", pokemon[index_pokemon].tipo_primario);
  scanf("%s", pokemon[index_pokemon].tipo_secundario);
  scanf("%d", &pokemon[index_pokemon].atributos_pokemon.hp);
  scanf("%d", &pokemon[index_pokemon].atributos_pokemon.ataque);
  scanf("%d", &pokemon[index_pokemon].atributos_pokemon.defesa);
  scanf("%d", &pokemon[index_pokemon].atributos_pokemon.atq_especial);
  scanf("%d", &pokemon[index_pokemon].atributos_pokemon.def_especial);
  scanf("%d", &pokemon[index_pokemon].atributos_pokemon.velocidade);
}

void adicionarAtaque(Pokemon pokemon[tam_MAX], int index_pokemon, int index_ataque){
  scanf("%s", pokemon[index_pokemon].ataque_pokemon[index_ataque].nome);
  scanf("%d", &pokemon[index_pokemon].ataque_pokemon[index_ataque].poder_base);
  scanf("%f", &pokemon[index_pokemon].ataque_pokemon[index_ataque].acuracia);
  scanf(" %c", &pokemon[index_pokemon].ataque_pokemon[index_ataque].classe);
}

void imprimirDadosPokemon(Pokemon pokemon[tam_MAX], int index_pokemon){
  printf("Nome do Pokemon: %s\n", pokemon[index_pokemon].nome);
  printf("Tipo primario: %s\n", pokemon[index_pokemon].tipo_primario);
  printf("Tipo secundario: %s\n", pokemon[index_pokemon].tipo_secundario);
  printf("Status:\n");
  printf("\tHP: %d\n", pokemon[index_pokemon].atributos_pokemon.hp);
  printf("\tAtaque: %d\n", pokemon[index_pokemon].atributos_pokemon.ataque);
  printf("\tDefesa: %d\n", pokemon[index_pokemon].atributos_pokemon.defesa);
  printf("\tAtaque Especial: %d\n", pokemon[index_pokemon].atributos_pokemon.atq_especial);
  printf("\tDefesa Especial: %d\n", pokemon[index_pokemon].atributos_pokemon.def_especial);
  printf("\tVelocidade: %d\n\n", pokemon[index_pokemon].atributos_pokemon.velocidade);
}

void imprimirAtaque(Pokemon pokemon[tam_MAX], int index_pokemon, int index_ataque){
  printf("Nome do Ataque: %s\n", pokemon[index_pokemon].ataque_pokemon[index_ataque].nome);
  printf("Poder base: %d\n", pokemon[index_pokemon].ataque_pokemon[index_ataque].poder_base);
  printf("Acuracia: %f\n", pokemon[index_pokemon].ataque_pokemon[index_ataque].acuracia);
  printf("Classe: %c\n\n", pokemon[index_pokemon].ataque_pokemon[index_ataque].classe);
}

int main(void) {
  Pokemon lista_pokemon[tam_MAX];
  int index_pokemon = 0;
  int index_pok_atual, index_ataque, comando;

  do{
   scanf("%d", &comando);

    switch(comando){
      case 1:
        cadastroPokemon(lista_pokemon, index_pokemon);
        index_pokemon++;
        break;

      case 2:
        scanf("%d", &index_pok_atual);
        scanf("%d", &index_ataque);
        adicionarAtaque(lista_pokemon, index_pok_atual, index_ataque);
        break;

      case 3:
        scanf("%d", &index_pok_atual);
        imprimirDadosPokemon(lista_pokemon, index_pok_atual);
        break;

      case 4:
        scanf("%d", &index_pok_atual);
        scanf("%d", &index_ataque);
        imprimirAtaque(lista_pokemon, index_pok_atual, index_ataque);
        break;
    }
  }while(comando != 0);

  return 0;
}
