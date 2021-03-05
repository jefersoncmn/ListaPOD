/*
Lista 1
Instru��es:
a. Atividade individual
b. Enviar 1 �nico arquivo (arquivo-fonte em C)

Implemente um programa em C que contenha menu principal e fun��es para:

a) Solicite um vetor qualquer para o usu�rio e execute a ordena��o usando o Bubble Sort
b) Solicite um vetor qualquer para o usu�rio e execute a ordena��o usando o Insertion Sort
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

int main()
{
    int tam = 0, i=0;
    printf("Qual ser� o tamanho do seu vetor?\n");
    scanf("%i", &tam);

    int *vet;
    vet = (int *) malloc (tam * sizeof(int));

    printf("Preencha o vetor em sequ�ncia: \n");
    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }

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
                ordenar_bubble(tam, vet);
            break;
            }
            case 2:{
                ordenar_insertion(tam, vet);
            break;
            }
        }
    }while(!(i>2 || i<1));
    return 0;

}

void ordenar_bubble(int tam, int *vet){

    int j, aux = 0, i = 0;

    //------------------ Marca��o de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------

    //----------------- Bubble sort ----------------

    for(i = 1; i < tam ; i++){ //percorre pelo tamanho do vetor (ele limita at� quantas execu��es de ordena��o ir�o acontecer)

        for(j = 0; j < tam - 1 ; j++){ //inicia percorrendo o vetor e vai ordenando de acordo com os valores

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

    //---------------------------------------------
    printf("O vetor ordenado do metodo Bubble e: \n");
    for(i = 0; i < tam; i ++){
        printf("[%d] ", vet[i]);
    }
    //---------------------------------------------

}

void ordenar_insertion(int tam, int *vet){

    int i = 0, j = 1, aux=0;

    //------------------ Marca��o de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------

    //----------------- Insertion Sort ----------------
    while(j < tam){ //enquanto j � menor que o tamanho do vetor
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
    //---------------------------------------------
    printf("O vetor ordenado do metodo Insertion e: \n");
    for(i = 0; i < tam; i ++){
        printf("[%d] ", vet[i]);
    }


}

