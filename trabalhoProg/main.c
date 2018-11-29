#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_STRING 50
#define TAM_CANDIDATOS 10
#include <locale.h>
#include <ctype.h>

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

void imprimir_candidato_Mais_votado(Candidato c){
    printf("---------------------------------------\n");
    printf("Nome: %s\nVotos: %d\nCidade: %s\n", c.nome, c.partido, c.total_votos, c.cidade);
}

void adicionar_Arquivo(Candidato c){
    int votos;
    int numero;
    arquivoGrava = fopen("banco.txt", "a");
    if(arquivoGrava == NULL){
        printf("\nErro ao abrir, banco");
        exit(1);
    }
    fputs(c.nome, arquivoGrava);
    fputs("\t", arquivoGrava);
    fputs(c.cargo, arquivoGrava);
    fputs("\t", arquivoGrava);
    fputs("BANDEIRANTES", arquivoGrava);
    fputs("\t", arquivoGrava);
    votos = c.total_votos;
    fputc(c.total_votos, arquivoGrava);
    fputs("\t", arquivoGrava);
    numero = c.numero;
    fputc(numero, arquivoGrava);
    fputs("\t", arquivoGrava);
    fputs("\n", arquivoGrava);
    fclose(arquivoGrava);

}

int main() {
    int menu;
    setlocale(LC_ALL, "portuguese");
    Candidato temp;
    int total_lido = 0;
    int pos_linha = 1;
    char linha[300];
    char * token;
    int votos = 0;
    int maior = 0;

    do{
     printf("\n#####################################################\tMENU\t#####################################################\n");
     printf("\n1 - Atribuir votos\n");
     printf("\n2 - Ver votos\n");
     printf("\n3 - Mais votado Bandeirantes\n");
     fflush(stdin);
     scanf("%d", &menu);

     switch(menu){
        case 1:
            arquivo = fopen("urna.txt", "r");
            if(arquivo == NULL){
                printf("Falha ao ler arquivo!");
                exit(1);
            }
            while(fgets(linha, 300, arquivo) != NULL){
                token = strtok (linha, "\";");
                while(token != NULL){
                    switch(pos_linha){
//                        case 6:
//                            //codigo cargo
//                            temp.codigo_cargo = atoi(token);
//                            break;
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
                            strcpy(temp.cidade, "BANDEIRANTES");

                        case 23:
                            //nome do votavel
//                            strcpy(temp.nome, token);
                               strcpy(temp.nome, token);
                            break;
                        case 24:
                            //qtde votos
                            printf("\nDigite o número de votos a serem inseridos\n%s: %s\t", temp.nome, temp.cargo);
                            scanf("%i", &votos);
                            temp.total_votos = votos;
                            break;
//                            temp.total_votos = atoi(token);



                    }

                    pos_linha++;
                    token = strtok(NULL, "\";");

                    }

                adicionar_Arquivo(temp);
                imprimir_candidato(temp);

                pos_linha=1;
                }

        case 2:
               arquivoGrava = fopen("banco.txt", "r");
            if(arquivoGrava == NULL){
                printf("Falha ao ler arquivo!");
                exit(1);
            }
            while(fgets(linha, 300, arquivoGrava) != NULL){
                token = strtok (linha, "\t""\n");
                while(token != NULL){
                    switch(pos_linha){
                        case 1:
                            //cargo
                            strcpy(temp.nome, token);
                            break;
                        case 2:
                            //numero do partido
                            strcpy(temp.cargo, token);
                            break;
                        case 3:
                            //nome do partido
                            strcpy(temp.cidade, token);
                            break;
                        case 4:
//                            strcpy(temp.cidade, token);
                            temp.total_votos = atoi(token);
                            break;




                    }

                    pos_linha++;
                    token = strtok(NULL, "\t""\n");

                    }
                imprimir_candidato(temp);

                pos_linha=1;
                }
        case 3:

            arquivoGrava = fopen("banco.txt", "r");
            if(arquivoGrava == NULL){
                printf("Falha ao ler arquivo!");
                exit(1);
            }
            while(fgets(linha, 300, arquivoGrava) != NULL){
                token = strtok (linha, "\t""\n");
                while(token != NULL){
                    switch(pos_linha){
                        case 1:
                            //cargo
                            strcpy(temp.nome, token);
                            break;
                        case 2:
                            //numero do partido
                            strcpy(temp.cargo, token);
                            break;
                        case 3:
                            //nome do partido
                            strcpy(temp.cidade, token);
                            break;
                        case 4:
//                            strcpy(temp.cidade, token);
                            temp.total_votos = atoi(token);
                            if(temp.total_votos > maior){
                                maior = temp.total_votos;
                            }
                            break;




                    }

                    pos_linha++;
                    token = strtok(NULL, "\t""\n");

                    }


                pos_linha=1;
                }
                imprimir_candidato_Mais_votado(temp);

                //inicializa a posicao da linha para o switch


        case 10:
            menu = 0;
            break;



    }



}while(menu != 0);

return 0;
    }





