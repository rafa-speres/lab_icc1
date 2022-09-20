//[Bonus] Compilador JIT de Brainf*ck


#include<stdio.h>
#include<stdlib.h>

void ajustaIdentacao(FILE* arquivo, int quant_tab){
    for(int i = 0; i < quant_tab; i++){
        fprintf(arquivo, "\t");
    }
}
void incrementaValor(FILE* arquivo, int identador){
    ajustaIdentacao(arquivo, identador);
    fprintf(arquivo, "\tmem[i]++;\n");
}

void decrementaValor(FILE* arquivo, int identador){
    ajustaIdentacao(arquivo, identador);
    fprintf(arquivo, "\tmem[i]--;\n");
}

void incrementaPosicao(FILE* arquivo, int identador){
    ajustaIdentacao(arquivo, identador);
    fprintf(arquivo, "\ti++;\n");
}

void decrementaPosicao(FILE* arquivo, int identador){
    ajustaIdentacao(arquivo, identador);
    fprintf(arquivo, "\ti--;\n");
}

void imprimeValorComoChar(FILE* arquivo, int identador){
    ajustaIdentacao(arquivo, identador);
    fprintf(arquivo, "\tputchar(mem[i]);\n");
}

void iniciaLoop(FILE* arquivo, int identador){
    ajustaIdentacao(arquivo, identador);
    fprintf(arquivo, "\twhile(mem[i]){\n");
}

void terminaLoop(FILE* arquivo, int identador){
    ajustaIdentacao(arquivo, identador);
    fprintf(arquivo, "\t}\n");
}

int main(void){
    FILE* arquivo_c = fopen("jit-gerado.c", "w");
    //texto de codigo padrao
    fprintf(arquivo_c, "#include <stdio.h>\n\n");
    fprintf(arquivo_c, "int main() {\n");
    fprintf(arquivo_c, "\tchar mem[30000];\n\tint i = 0;\n");
    fprintf(arquivo_c,"\tfor (int j = 0; j < 30000; j++) {\n\t\tmem[j] = 0;\n\t}\n");

    //inicio da traducao de BF
    char operacao;
    int identador = 0;
    while(scanf("%c", &operacao) != EOF){
        switch(operacao){
            case '+':
                incrementaValor(arquivo_c, identador);
                break;
            
            case '-':
                decrementaValor(arquivo_c, identador);
                break;
            
            case '>':
                incrementaPosicao(arquivo_c, identador);
                break;
            
            case '<':
                decrementaPosicao(arquivo_c, identador);
                break;

            case '.':
                imprimeValorComoChar(arquivo_c, identador);
                break;
            
            case '[':
                iniciaLoop(arquivo_c, identador);
                identador++;
                break;

            case ']':
                identador--;
                terminaLoop(arquivo_c, identador);
                break;
            
            default:
                break;
        }
    }
    //fim da traducao de BF

    fprintf(arquivo_c, "\tprintf(\"\\n\");\n");
    fprintf(arquivo_c, "\tfor (int j = 0; j < 30000; j++) {\n\t\tif (mem[j] != 0) {\n");
    fprintf(arquivo_c, "\t\t\tprintf(\"%%d \", mem[j]);\n");
    fprintf(arquivo_c, "\t\t}\n");
    fprintf(arquivo_c, "\t}");
      
    fprintf(arquivo_c, "\treturn 0;\n}");
    
    fclose(arquivo_c);

    system("gcc jit-gerado.c -o jit-exe");
    system("./jit-exe");

    return 0;
}
