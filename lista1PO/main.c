/*
Lista 1
Instruções:
a. Atividade individual
b. Enviar 1 único arquivo (arquivo-fonte em C)

Implemente um programa em C que contenha menu principal e funções para:

a) Solicite um vetor qualquer para o usuário e execute a ordenação usando o Bubble Sort
b) Solicite um vetor qualquer para o usuário e execute a ordenação usando o Insertion Sort
*/

/*
Obs: Todos os comentários em torno do código são originados sem a intenção de ser
usado para fins de avaliações, são somente simples observações para compreendimento do código
por terceiros e aquele que o desenvolveu.
Esse código não pode ser comercializado.

- "Tudo em seu início já foi pequeno, o tempo o deu a liberdade de atingir a grandeza".
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tam = 0, i=0;
    printf("Qual será o tamanho do seu vetor?\n");
    scanf("%i", &tam);

    int *vet;
    vet = (int *) malloc (tam * sizeof(int));

    printf("Preencha o vetor em sequência: \n");
    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }

    // ------------------- MENU -------------------------------------
    do{
        printf("\n----------------------------------------------------------\n");
        printf("---------------- Escolha uma das opcoes --------------------\n");
        printf("-----------------------------------------------------------\n");
        printf("1 - executar a ordenação do arquivo usando Bubble Sort-----\n");
        printf("2 - executar a ordenação do arquivo usando Insertion Sort--\n");
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

    //------------------ Marcação de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------

    //----------------- Bubble sort ----------------

    for(i = 1; i < tam ; i++){ //percorre pelo tamanho do vetor (ele limita até quantas execuções de ordenação irão acontecer)

        for(j = 0; j < tam - 1 ; j++){ //inicia percorrendo o vetor e vai ordenando de acordo com os valores

            if(vet[j] > vet[j+1]){ //se a posição atual do vetor for maior que a da frente
                aux = vet[j];       //irá pegar esse valor e por na variavel auxiliar
                vet[j] = vet[j+1];  //substituir o valor de onde foi pego a "cópia" para o valor do vetor a frente
                vet[j+1] = aux;     //E será recolocado o valor nesse da frente, por ele ser maior
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

    //------------------ Marcação de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------

    //----------------- Insertion Sort ----------------
    while(j < tam){ //enquanto j é menor que o tamanho do vetor
        aux = vet[j]; //o auxiliar vai pegar a segunda posição do vetor
        i = j - 1; // esse ficará atrás do j no vetpr

        while((i >= 0) && (vet[i] > aux)){ //enquanto o i for maior ou igual a 0 e a posição do vetor for maior que o que tá o auxiliar
            vet[i + 1] = vet[i]; //ele vai substituir o valor do vetor da frente pelo de trás que é maior
            i = i - 1; //e o indice "i" que é responsável pelos vetores atras do "j" retrocede, se no caso o while continuar ele irá fazer a troca novamente com a linha acima e ir retrocedendo no vetor até seu inicio ou caso o valor não seja menor
        }
        vet[i + 1] = aux; //o vetor da frente é substituído pelo auxiliar
        j = j + 1; //e o indice "j" é incrementado para avançar no vetor, já que tuda atrás já foi ordenado
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

