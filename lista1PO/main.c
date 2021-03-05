/*
Lista 2
Instru��es:
a. Atividade individual
b. Enviar 2 arquivos (arquivo-fonte em C e uma planilha com a tabula��o do tempo x algoritmo)

Com base no exerc�cio da "Lista 1" e os c�digos disponibilizados no Moodle, voc� deve construir um programa que fa�a a mensura��o do tempo para a ordena��o de 500.000, 750.000 e 1.000.000 registros, utilizando os algoritmos Bubblesort e Insertsort
*/

/*
Obs: Todos os coment�rios em torno do c�digo s�o originados sem a inten��o de ser
usado para fins de avalia��es, s�o somente simples observa��es para compreendimento do c�digo
por terceiros e aquele que o desenvolveu.
Esse c�digo n�o pode ser comercializado.

- "Tudo em seu in�cio j� foi pequeno, o tempo o deu a liberdade de atingir a grandeza".
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char arquivoOrdNome[20] = "dados_ordenados.txt";
char arquivoInvNome[25] = "dados_invertidos.txt";
char arquivoRanNome[25] = "dados_randomicos.txt";

int main()
{
    int tamanhoVet = 0;
    tamanhoVet = criar_arquivos();
    if(tamanhoVet != 1){
        if(menu_operacional(tamanhoVet) == 0){
            printf("Processo funcionando!\n");
        }
    }

}

int menu_operacional(int tamanhoVet){

    int i=0;

    // ------------------- MENU -------------------------------------
    do{
        printf("\n----------------------------------------------------------\n");
        printf("---------------- Escolha uma das opcoes --------------------\n");
        printf("-----------------------------------------------------------\n");
        printf("1 - executar a ordena��o do arquivo usando Bubble Sort-----\n");
        printf("2 - executar a ordena��o do arquivo usando Insertion Sort--\n");
        printf("-----------------------------------------------------------\n");
        i=0;
        scanf("%i",&i);
        switch(i){
            case 1:{
                printf("\n1 - Arquivo Ordenado \n2 - Arquivo Invertido\n3 - Arquivo Rand�mico\n");
                scanf("%i",&i);
                switch(i){
                    case 1:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);
                        *vet = ordenar_bubble(tamanhoVet, vet);
                        escrever_arquivo(vet, tamanhoVet, arquivoOrdNome);
                    break;
                    }
                    case 2:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoInvNome);
                        *vet = ordenar_bubble(tamanhoVet, vet);
                        escrever_arquivo(vet, tamanhoVet, arquivoInvNome);
                    break;
                    }
                    case 3:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoRanNome);
                        *vet = ordenar_bubble(tamanhoVet, vet);
                        escrever_arquivo(vet, tamanhoVet, arquivoRanNome);
                    break;
                    }
                }
            break;
            }
            case 2:{
                printf("\n1 - Arquivo Ordenado \n2 - Arquivo Invertido\n3 - Arquivo Rand�mico\n");
                scanf("%i",&i);
                switch(i){
                    case 1:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);
                        *vet = ordenar_insertion(tamanhoVet, vet);
                        escrever_arquivo(vet, tamanhoVet, arquivoOrdNome);
                    break;
                    }
                    case 2:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoInvNome);
                        *vet = ordenar_insertion(tamanhoVet, vet);
                        escrever_arquivo(vet, tamanhoVet, arquivoInvNome);
                    break;
                    }
                    case 3:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoRanNome);
                        *vet = ordenar_insertion(tamanhoVet, vet);
                        escrever_arquivo(vet, tamanhoVet, arquivoRanNome);
                    break;
                    }
                }
            break;
            }
        }
    }while(!(i>3 || i<1));

    return 0;

}

int criar_arquivos(){
//------------- Cria��o de arquivos --------------------------
    FILE* arquivoOrdenado, *arquivoInverso, *arquivoRandomico;

    int tamanhoVet = 0, i=0;

    arquivoOrdenado = fopen(arquivoOrdNome,"w");
    arquivoInverso = fopen(arquivoInvNome,"w");
    arquivoRandomico = fopen(arquivoRanNome,"w");

    if(arquivoOrdenado == NULL || arquivoInverso == NULL || arquivoRandomico == NULL){
        printf("Erro ao operar os arquivos!\n");
        return 1;
    }

//------------- Preenchimento de arquivos -----------------------
    printf("--- Inicializacao dos arquivos --- \n");
    printf("Qual ser� o tamanho dos arquivos ?\n");
    scanf("%d",&tamanhoVet);

    while(i<tamanhoVet){
       fprintf(arquivoOrdenado, "%d ", i);
       i++;
    }
    i--;
    while(i>=0){
       fprintf(arquivoInverso, "%d ", i);
       i--;
    }
    i++;
    while(i<tamanhoVet){
       fprintf(arquivoRandomico, "%d ", rand() % tamanhoVet);
       i++;
    }

    fclose(arquivoOrdenado);
    fclose(arquivoInverso);
    fclose(arquivoRandomico);

    return tamanhoVet;
}

int ler_arquivo(int tamanhoVet, char arquivoNome[]){

    FILE* arquivo;
    arquivo = fopen(arquivoNome, "r");
    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }

    int *vet;
    vet = (int *) malloc (tamanhoVet * sizeof(int));
    int i =0;

    while((fscanf(arquivo,"%d ",&vet[i]))!= EOF){
        i++;
    }

    fclose(arquivo);

    return vet;
}

int escrever_arquivo(int *vet, int tamanhoVet ,char arquivoNome[]){

    int i;
    FILE* arquivo;
    arquivo = fopen(arquivoNome,"w");
    for(i = 0; i<tamanhoVet; i++ ){
        fprintf(arquivo, "%d ", vet[i]);
    }
    fclose(arquivo);

    return 0;
}

int ordenar_bubble(int tamanhoVet, int *vet){

    int j, aux = 0, i = 0;

    //------------------ Marca��o de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------

    //----------------- Bubble sort ----------------

    for(i = 1; i < tamanhoVet ; i++){ //percorre pelo tamanho do vetor (ele limita at� quantas execu��es de ordena��o ir�o acontecer)

        for(j = 0; j < tamanhoVet - 1 ; j++){ //inicia percorrendo o vetor e vai ordenando de acordo com os valores

            if(vet[j] > vet[j+1]){ //se a posi��o atual do vetor for maior que a da frente
                aux = vet[j];       //ir� pegar esse valor e por na variavel auxiliar
                vet[j] = vet[j+1];  //substituir o valor de onde foi pego a "c�pia" para o valor do vetor a frente
                vet[j+1] = aux;     //E ser� recolocado o valor nesse da frente, por ele ser maior
            }
        }
    }

    //---------------------------------------------
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo: %d ms \n", Tempo);

    return *vet;
}

int ordenar_insertion(int tamanhoVet, int *vet){

    int i = 0, j = 1, aux=0;

    //------------------ Marca��o de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------

    //----------------- Insertion Sort ----------------
    while(j < tamanhoVet){ //enquanto j � menor que o tamanho do vetor
        aux = vet[j]; //o auxiliar vai pegar a segunda posi��o do vetor
        i = j - 1; // esse ficar� atr�s do j no vetpr

        while((i >= 0) && (vet[i] > aux)){ //enquanto o i for maior ou igual a 0 e a posi��o do vetor for maior que o que t� o auxiliar
            vet[i + 1] = vet[i]; //ele vai substituir o valor do vetor da frente pelo de tr�s que � maior
            i = i - 1; //e o indice "i" que � respons�vel pelos vetores atras do "j" retrocede, se no caso o while continuar ele ir� fazer a troca novamente com a linha acima e ir retrocedendo no vetor at� seu inicio ou caso o valor n�o seja menor
        }
        vet[i + 1] = aux; //o vetor da frente � substitu�do pelo auxiliar
        j = j + 1; //e o indice "j" � incrementado para avan�ar no vetor, j� que tuda atr�s j� foi ordenado
    }

    //---------------------------------------------
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo: %d ms \n", Tempo);

    return *vet;
}

