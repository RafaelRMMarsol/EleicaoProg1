#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_STRING 50
#define TAM_CANDIDATOS 10

FILE * arquivo;
FILE* arquivoGrava;
typedef struct candidato{
    int numero;
    char nome[TAM_STRING];
    char partido[TAM_STRING];
    int codigo_cargo;
    char cargo[TAM_STRING];
    int total_votos;
    char cidade[TAM_STRING];
} Candidato;

void imprimir_candidato(Candidato c){
    printf("---------------------------------------\n");
    printf("Candidato(a): %d - %s\nPartido: %s\nCargo: %s\nVotos: %d\nCidade: %s\n",
            c.numero, c.nome, c.partido, c.cargo, c.total_votos, c.cidade);
}

void adicionar_Arquivo(Candidato c){
    if(arquivoGrava = fopen("banco.txt", "w") == NULL){
        printf("\nErro ao abrir, banco");
        exit(1);
    }
    fputs(c.cargo, arquivoGrava);

    fclose(arquivoGrava);
}

int main() {
    Candidato temp;
    int total_lido = 0;
    int pos_linha = 1;
    char linha[300];
    char * token;
    int ola;
    char teste[100];

    arquivo = fopen("urna.txt", "r");
    if(arquivo == NULL){
        printf("Falha ao ler arquivo!");
        exit(1);
    }

    while(fgets(linha, 300, arquivo) != NULL){
        token = strtok (linha, "\";");
        while(token != NULL){
            switch(pos_linha){
                case 6:
                    //codigo cargo
                    temp.codigo_cargo = atoi(token);
                    break;
                case 7:
                    //cargo
                    strcpy(temp.cargo, token);
                    break;
                case 11:
                    //numero do partido
                    temp.numero = atoi(token);
                    break;
                case 12:
                    //nome do partido
                    strcpy(temp.partido, token);
                    break;
                case 14:
                    strcpy(temp.cidade, token);
                    break;
                case 23:
                    //nome do votavel
                    strcpy(temp.nome, token);
                    break;
                case 24:
                    //qtde votos
                    //temp.total_votos = atoi(token);
                    printf("Digite os votos");
                    scanf("%d", &temp.total_votos);
                    break;

            }
            pos_linha++;
            token = strtok(NULL, "\";");
        }
        adicionar_Arquivo(temp);
        imprimir_candidato(temp);

        //inicializa a posicao da linha para o switch
        pos_linha=1;
    }
    return 0;
}
