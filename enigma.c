//The Enigma

#include <stdio.h>

int main(void) {
  int rotor1[26];
  int rotor2[26];
  int rotor3[26];
  int rot1 = 0;
  int rot2 = 0;

  //descarte da linha Rotores
  scanf("%*[^\r\n]s");
  scanf("%*[\r\n]s");

  for(int i = 0; i < 26; i++){
    scanf("%d", &rotor1[i]);
  }

  for(int i = 0; i < 26; i++){
    scanf("%d", &rotor2[i]);
  }

  for(int i = 0; i < 26; i++){
    scanf("%d", &rotor3[i]);
  }
  
  //descarte da linha vazia
  scanf("%*[^\r\n]s");
  scanf("%*[\r\n]s");

  //descarte da linha mensagem
  scanf("%*[^\r\n]s");
  scanf("%*[\r\n]s");
  
  char mensagem;
  char dcripto;
  
  while(scanf("%c", &mensagem) != EOF){
    if(mensagem >= 97 && mensagem <= 122){
      int mensagem_int = mensagem - 97;
      int dcripto_int = rotor3[rotor2[rotor1[mensagem_int]]];
      dcripto = dcripto_int + 97;

      //altera as posicoes do rotor 1
      int aux = rotor1[0];
      for(int j = 0; j < 25; j++){
        rotor1[j] = rotor1[j+1]; 
      }
      rotor1[25] = aux;
      rot1++;

      //altera as posicoes do rotor 2
      if(rot1 == 26){
        aux = rotor2[0];
        for(int j = 0; j < 25; j++){
          rotor2[j] = rotor2[j+1];
        }
        rotor2[25] = aux;
        rot1 = 0;
        rot2++;
      }

      //altera as posicoes do rotor 3
      if(rot2 == 26){
        aux = rotor3[0];
          for(int j = 0; j < 25; j++){
            rotor3[j] = rotor3[j+1];
          }
          rotor3[25] = aux;
        rot2 = 0;
      }
    } else if(mensagem >= 65 && mensagem <= 90){
      int mensagem_int = mensagem - 65;
      int dcripto_int = rotor3[rotor2[rotor1[mensagem_int]]];
      dcripto = dcripto_int + 65;

      //altera as posicoes do rotor 1
      int aux = rotor1[0];
      for(int j = 0; j < 25; j++){
        rotor1[j] = rotor1[j+1]; 
      }
      rotor1[25] = aux;
      rot1++;

      //altera as posicoes do rotor 2
      if(rot1 == 26){
        aux = rotor2[0];
        for(int j = 0; j < 25; j++){
          rotor2[j] = rotor2[j+1];
        }
        rotor2[25] = aux;
        rot1 = 0;
        rot2++;
      }

      //altera as posicoes do rotor 3
      if(rot2 == 26){
        aux = rotor3[0];
          for(int j = 0; j < 25; j++){
            rotor3[j] = rotor3[j+1];
          }
          rotor3[25] = aux;
        rot2 = 0;
      }
    }
    if((mensagem >= 97 && mensagem <= 122) || (mensagem >= 65 && mensagem <= 90)){
      printf("%c", dcripto);
    } else{
      printf("%c", mensagem);
    }
      
  }
  return 0;
}
