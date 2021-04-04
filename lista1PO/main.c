/*
Lista 3

Com base no exercício da "Lista 1" e os códigos disponibilizados no Moodle,
você deve construir um programa que faça a mensuração do tempo para a ordenação de
500.000, 750.000 e 1.000.000 registros, utilizando os 7 algoritmos vistos,
Bubblesort, Insertsort, Selectionsort, Shellsort, Quicksort (Lomuto), Mergesort e Radixsort

Na planilha, verifique ainda, o número de operações de trocas que são feitas em cada um dos algoritmos.
*/

/*
Obs: Todos os comentários em torno do código são originados sem a intenção de ser
usado para fins de avaliações, são somente simples observações para compreendimento do código
por terceiros e aquele que o desenvolveu.
Esse código não pode ser comercializado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

char arquivoOrdNome[20] = "dados_ordenados.txt";
char arquivoInvNome[25] = "dados_invertidos.txt";
char arquivoRanNome[25] = "dados_randomicos.txt";

int main()
{
    int tamanhoVet = 0;
    //printf("\a");

    tamanhoVet = criar_arquivos();
    if(tamanhoVet != 1){
        if(menu_operacional(tamanhoVet) == 0){
            printf("Processo funcionando!\n");
        }
    }

}

int menu_operacional(int tamanhoVet){

    int i=0;
    long int trocasContador = 0;
    long int *trocas = &trocasContador;

    // ------------------- MENU -------------------------------------
    do{
        printf("\n---------------------------------------------------------\n");
        printf("---------------- Escolha uma das opcoes -------------------\n");
        printf("-----------------------------------------------------------\n");
        printf("1 - executar a ordenacao do arquivo usando Bubble Sort-----\n");
        printf("2 - executar a ordenacao do arquivo usando Insertion Sort--\n");
        printf("3 - executar a ordenacao do arquivo usando Selection Sort--\n");
        printf("4 - executar a ordenacao do arquivo usando Shell Sort------\n");
        printf("5 - executar a ordenacao do arquivo usando Quicksort(Lomuto)\n");
        printf("6 - executar a ordenacao do arquivo usando Mergesort-------\n");
        printf("7 - executar a ordenacao do arquivo usando Radixsort-------\n");
        printf("8 - executar a ordena��o do arquivo usando QuickSort(Hoare)\n");
        printf("-----------------------------------------------------------\n");
        i=0;
        scanf("%i",&i);
        printf("Opcao de metodo de ordenacao escolhido : %d", i);
        switch(i){
            case 1:{
                printf("\n1 - Arquivo Ordenado \n2 - Arquivo Invertido\n3 - Arquivo Randômico\n");
                scanf("%i",&i);
                printf("Opcao de arquivo escolhida : %d\n", i);
                switch(i){
                    case 1:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);
                        *vet = ordenar_bubble(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoOrdNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 2:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoInvNome);
                        *vet = ordenar_bubble(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoInvNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 3:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoRanNome);
                        *vet = ordenar_bubble(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoRanNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                }
                printf("Ordenacao em bubblesort realizada!");
            break;
            }
            case 2:{
                printf("\n1 - Arquivo Ordenado \n2 - Arquivo Invertido\n3 - Arquivo Randômico\n");
                scanf("%i",&i);
                printf("Opcao de arquivo escolhida : %d\n", i);
                switch(i){
                    case 1:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);
                        *vet = ordenar_insertion(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoOrdNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 2:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoInvNome);
                        *vet = ordenar_insertion(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoInvNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 3:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoRanNome);
                        *vet = ordenar_insertion(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoRanNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                }
                printf("Ordenacao em insertionsort realizada!");
            break;
            }
            case 3:{
                printf("\n1 - Arquivo Ordenado \n2 - Arquivo Invertido\n3 - Arquivo Randômico\n");
                scanf("%i",&i);
                printf("Opcao de arquivo escolhida : %d\n", i);
                switch(i){
                    case 1:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);
                        *vet = ordenar_selection(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoOrdNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 2:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoInvNome);
                        *vet = ordenar_selection(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoInvNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 3:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoRanNome);
                        *vet = ordenar_selection(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoRanNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                }
                printf("Ordenacao em selectionsort realizada!");
            break;
            }
            case 4:{
                printf("\n1 - Arquivo Ordenado \n2 - Arquivo Invertido\n3 - Arquivo Randômico\n");
                scanf("%i",&i);
                printf("Opcao de arquivo escolhida : %d\n", i);
                switch(i){
                    case 1:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);
                        *vet = ordenar_shell(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoOrdNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 2:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoInvNome);
                        *vet = ordenar_shell(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoInvNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 3:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoRanNome);
                        *vet = ordenar_shell(tamanhoVet, vet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoRanNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                }
                printf("Ordenacao em shellsort realizada!");
            break;
            }
            case 5:{
                printf("\n1 - Arquivo Ordenado \n2 - Arquivo Invertido\n3 - Arquivo Randômico\n");
                scanf("%i",&i);
                printf("Opcao de arquivo escolhida : %d\n", i);
                switch(i){
                    case 1:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);


                        //------------------ Marcação de tempo ---------
                        clock_t Ticks[2];
                        Ticks[0] = clock();
                        //---------------------------

                        ordenar_quick(vet, 0, tamanhoVet-1, trocas);

                        //---------------------------------------------
                        Ticks[1] = clock();
                        double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
                        printf("Tempo: %.2f \n", Tempo);
                        //-------------------------------------------------

                        escrever_arquivo(vet, tamanhoVet, arquivoOrdNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 2:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoInvNome);

                        //------------------ Marcação de tempo ---------
                        clock_t Ticks[2];
                        Ticks[0] = clock();
                        //---------------------------

                        //ordenar_quick(vet, 0, tamanhoVet-1, trocas);
                        ordenar_quick(vet, 0, tamanhoVet-1);

                        //---------------------------------------------
                        Ticks[1] = clock();
                        double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
                        printf("Tempo: %.2f \n", Tempo);
                        //-------------------------------------------------

                        escrever_arquivo(vet, tamanhoVet, arquivoInvNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 3:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoRanNome);

                        //------------------ Marcação de tempo ---------
                        clock_t Ticks[2];
                        Ticks[0] = clock();
                        //---------------------------

                        ordenar_quick(vet, 0, tamanhoVet-1, trocas);

                        //---------------------------------------------
                        Ticks[1] = clock();
                        double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
                        printf("Tempo: %.2f \n", Tempo);
                        //-------------------------------------------------

                        escrever_arquivo(vet, tamanhoVet, arquivoRanNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                }
                printf("Ordenacao em quicksort realizada!");
            break;
            }
            case 6:{
                printf("\n1 - Arquivo Ordenado \n2 - Arquivo Invertido\n3 - Arquivo Randômico\n");
                scanf("%i",&i);
                printf("Opcao de arquivo escolhida : %d\n", i);
                switch(i){
                    case 1:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);

                        //------------------ Marcação de tempo ---------
                        clock_t Ticks[2];
                        Ticks[0] = clock();
                        //---------------------------

                        ordenar_merge(vet, 0, tamanhoVet-1, trocas, tamanhoVet);

                        //---------------------------------------------
                        Ticks[1] = clock();
                        double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
                        printf("Tempo: %.2f \n", Tempo);
                        //-------------------------------------------------

                        escrever_arquivo(vet, tamanhoVet, arquivoOrdNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 2:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoInvNome);

                        //------------------ Marcação de tempo ---------
                        clock_t Ticks[2];
                        Ticks[0] = clock();
                        //---------------------------

                        ordenar_merge(vet, 0, tamanhoVet-1, trocas, tamanhoVet);

                        //---------------------------------------------
                        Ticks[1] = clock();
                        double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
                        printf("Tempo: %.2f \n", Tempo);
                        //-------------------------------------------------

                        escrever_arquivo(vet, tamanhoVet, arquivoInvNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 3:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoRanNome);

                        //------------------ Marcação de tempo ---------
                        clock_t Ticks[2];
                        Ticks[0] = clock();
                        //---------------------------

                        ordenar_merge(vet, 0, tamanhoVet-1, trocas, tamanhoVet);

                        //---------------------------------------------
                        Ticks[1] = clock();
                        double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
                        printf("Tempo: %.2f \n", Tempo);
                        //-------------------------------------------------

                        escrever_arquivo(vet, tamanhoVet, arquivoRanNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                }
                printf("Ordenacao em mergesort realizada!");
            break;
            }
            case 7:{
                printf("\n1 - Arquivo Ordenado \n2 - Arquivo Invertido\n3 - Arquivo Randômico\n");
                scanf("%i",&i);
                printf("Opcao de arquivo escolhida : %d\n", i);
                switch(i){
                    case 1:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);
                        ordenar_radix(vet, tamanhoVet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoOrdNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 2:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoInvNome);
                        ordenar_radix(vet, tamanhoVet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoInvNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 3:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoRanNome);
                        ordenar_radix(vet, tamanhoVet, trocas);
                        escrever_arquivo(vet, tamanhoVet, arquivoRanNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                }
                printf("Ordenacao em radixsort realizada!");
            break;
            }
            case 8:{
                printf("\n1 - Arquivo Ordenado \n2 - Arquivo Invertido\n3 - Arquivo Randômico\n");
                scanf("%i",&i);
                printf("Opcao de arquivo escolhida : %d\n", i);
                switch(i){
                    case 1:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);

                        //------------------ Marcacao de tempo ---------
                        clock_t Ticks[2];
                        Ticks[0] = clock();
                        //---------------------------

                        ordenar_quick_hoare(vet, 0, tamanhoVet-1, trocas);

                        //---------------------------------------------
                        Ticks[1] = clock();
                        double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
                        printf("Tempo: %.2f \n", Tempo);
                        //-------------------------------------------------

                        escrever_arquivo(vet, tamanhoVet, arquivoOrdNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 2:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);

                        //------------------ Marcacao de tempo ---------
                        clock_t Ticks[2];
                        Ticks[0] = clock();
                        //---------------------------

                        ordenar_quick_hoare(vet, 0, tamanhoVet-1, trocas);

                        //---------------------------------------------
                        Ticks[1] = clock();
                        double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
                        printf("Tempo: %.2f \n", Tempo);
                        //-------------------------------------------------

                        escrever_arquivo(vet, tamanhoVet, arquivoInvNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                    case 3:{
                        int *vet = ler_arquivo(tamanhoVet, arquivoOrdNome);

                        //------------------ Marcacao de tempo ---------
                        clock_t Ticks[2];
                        Ticks[0] = clock();
                        //---------------------------

                        ordenar_quick_hoare(vet, 0, tamanhoVet-1, trocas);

                        //---------------------------------------------
                        Ticks[1] = clock();
                        double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
                        printf("Tempo: %.2f \n", Tempo);
                        //-------------------------------------------------

                        escrever_arquivo(vet, tamanhoVet, arquivoRanNome);
                        printf("Trocas realizadas %d\n", trocasContador);
                    break;
                    }
                }
            }
        }

        trocasContador = 0;
    }while(!(i>8 || i<1));

    return 0;

}

int criar_arquivos(){
//------------- Criação de arquivos --------------------------
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
    printf("Qual sera o tamanho dos arquivos ?\n");
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

int ordenar_bubble(int tamanhoVet, int *vet, int *trocas){

    int j, aux = 0, i = 0;

    //------------------ Marcação de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------

    //----------------- Bubble sort ----------------

    for(i = tamanhoVet-1 ; i >= 1 ; i--){ //percorre pelo tamanho do vetor (ele limita até quantas execuções de ordenação irão acontecer)

        for(j = 0; j < i; j++){ //inicia percorrendo o vetor e vai ordenando de acordo com os valores (seu limite é até o ponto que foi ordenado)

            if(vet[j] > vet[j+1]){ //se a posição atual do vetor for maior que a da frente
                aux = vet[j];       //irá pegar esse valor e por na variavel auxiliar
                vet[j] = vet[j+1];  //substituir o valor de onde foi pego a "cópia" para o valor do vetor a frente
                vet[j+1] = aux;     //E será recolocado o valor nesse da frente, por ele ser maior
                *trocas = *trocas + 1;
            }
        }
    }

    //---------------------------------------------
    Ticks[1] = clock();
    double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    printf("Tempo: %.2f  \n", Tempo);

    return *vet;
}

int ordenar_insertion(int tamanhoVet, int *vet, int *trocas){

    int i = 0, j = 1, aux=0;

    //------------------ Marcação de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------

    //----------------- Insertion Sort ----------------

    for(j = 1; j<= tamanhoVet-1; j++){ //começa já na posição 1 pq o primeiro meio que já é ordenado
        aux = vet[j]; //pega esse numero a frente do ordenado e coloca no auxiliar
        i = j - 1; //i pega a posicao atrás, o cara que tá ordenado
        while(i >= 0 && aux < vet[i]){ //enquanto i for maior ou igual a x (pra limitar o verificador de ir pro lado esquerdo) e o auxiliar for menor que o valor ordenado
            vet[i + 1] = vet[i]; //o valor passa pra frente
            i = i - 1; //o ponteiro que tá com o valor a ser comparado com o auxiliar vai pra trás
        }
        vet[i + 1] = aux; //troca
        *trocas = *trocas + 1;
    }
    //---------------------------------------------
    Ticks[1] = clock();
    double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    printf("Tempo: %.2f \n", Tempo);

    return *vet;
}

int ordenar_selection(int tamanhoVet, int *vet, int *trocas){

    int i, j, min, aux;

    //------------------ Marcação de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------


    //------------------ Selection Sort -----------
    for (i = 0; i < (tamanhoVet-1); i++){ //vai do inicio ao final do vetor

     min = i;//começa com o primeiro como o menor

        for (j = (i+1); j <= tamanhoVet-1; j++) { //vai da segunda posicao até o final do vetor
            if(vet[j] < vet[min]) //verifica pra ver se tem alguém menor
            min = j;//se tiver coloca lá
        }

        if (i != min) { //se for diferente, no caso ele percorreu e o min se tornou outro valor, o I que é o primeiro da lista, é trocado com esse menor
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
            *trocas = *trocas + 1;
        }
    }

    //---------------------------------------------
    Ticks[1] = clock();
    double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    printf("Tempo: %.2f \n", Tempo);

    return *vet;
}

int ordenar_shell(int tamanhoVet, int *vet, int *trocas){

    int i, j, value;

    //------------------ Marcação de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------

    int h = 1;
    while(h < tamanhoVet) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < tamanhoVet; i++) {
            value = vet[i];
            j = i;
            while (j > h-1 && value <= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;
                *trocas = *trocas + 1;
            }
            vet[j] = value;
        }
        h = h/3;
    }


    //---------------------------------------------
    Ticks[1] = clock();
    double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    printf("Tempo: %.2f \n", Tempo);

    return *vet;

}
/*
void ordenar_quick(int *vet, int esquerda, int direita, int *trocas){

    int i;
    if(direita > esquerda){
        i = particionar(vet, esquerda, direita, trocas);
        ordenar_quick(vet, esquerda, i-1, trocas);
        ordenar_quick(vet, i+1, direita, trocas);
    }

}
*/

int ordenar_quick(int *vet, int esquerda, int direita){


    if(esquerda < direita){
        int p = particioner(vet, esquerda, direita);
        ordenar_quick(vet, esquerda, p - 1);
        ordenar_quick(vet, p + 1, direita);
    } else {
        return 0;
    }
    return 0;

}

int particioner(int *arr, int low, int high){
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;

    return (i + 1);
}

int particionar(int *vet, int esquerda, int direita,int *trocas){
    int pivo = vet[esquerda];
    int i = esquerda;
    int aux = 0;

    for(int j = esquerda + 1; j <= direita; j++){
        if(vet[j] <= pivo){
            i+=1;

            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            //*trocas = *trocas + 1;
        }
    }

    aux = vet[i];
    vet[i] = vet[esquerda];
    vet[esquerda] = aux;
    //*trocas = *trocas + 1;

    return i;
}

void ordenar_merge(int *vet, int esquerda, int direita, int *trocas,  int tamanhoVet){

    if(esquerda < direita){
        int meio = (esquerda + direita)/2;
        ordenar_merge(vet, esquerda, meio, trocas, tamanhoVet);
        ordenar_merge(vet, meio+1, direita, trocas, tamanhoVet);
        merge(vet, esquerda, meio, direita, trocas, tamanhoVet);
    }

}

void merge(int *vet, int esquerda, int meio, int direita, int *trocas, int tamanhoVet){
    int i,j,k;
    //int aux[tamanhoVet];//isso faz funcionar com 500 mil
    int *aux = (int *) malloc (tamanhoVet * sizeof(int));//não funciona com 500 min nem mais tmb kk

    for(i = meio + 1; i > esquerda; i--){
        aux[i-1] = vet[i-1];
    }
    for(j = meio; j < direita; j++){
        aux[direita + meio - j] = vet[j + 1];
    }
    for(k = esquerda; k <= direita; k++){
        if(aux[j] < aux[i]){
            vet[k] = aux[j--];
            *trocas = *trocas + 1;
        } else {
            vet[k] = aux[i++];
            *trocas = *trocas + 1;
        }
    }
}

void ordenar_radix(int *vet, int tamanhoVet, int *trocas){
    int i, exp = 1, m = 0;

    int *bucket = (int *) malloc (tamanhoVet * sizeof(int));
    int *temp = (int *) malloc (tamanhoVet * sizeof(int));

    //------------------ Marcação de tempo ---------
    clock_t Ticks[2];
    Ticks[0] = clock();
    //---------------------------

    for(i = 0; i < tamanhoVet; i++){ //percorre e acha o maior?
        if(vet[i] > m){
            m = vet[i];
        }
    }

    while((m/exp) > 0){
        for( i = 0; i < tamanhoVet; i++){
            bucket[i] = 0;
        }
        for(i = 0; i < tamanhoVet; i++){
            bucket[(vet[i]/exp) % 10]++;
        }
        for(i = 1; i < tamanhoVet; i++) {
            bucket[i] += bucket[i-1];
        }
        for(i = (tamanhoVet - 1); i >= 0; i--) {
            temp[--bucket[(vet[i] / exp) % 10]] = vet[i];
            *trocas = *trocas + 1;
        }
        for(i = 0; i < tamanhoVet; i++) {
            vet[i] = temp[i];

        }

        exp *= 10;
    }

    //---------------------------------------------
    Ticks[1] = clock();
    double Tempo = (double)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    printf("Tempo: %.2f \n", Tempo);
}

void ordenar_quick_hoare(int *vet, int esquerda, int direita, int *trocas){

    int i;
    if(direita > esquerda){
        i = particionar_hoare(vet, esquerda, direita, trocas);
        ordenar_quick_hoare(vet, esquerda, i-1, trocas);
        ordenar_quick_hoare(vet, i+1, direita, trocas);
    }
}

int particionar_hoare(int *vet, int esquerda, int direita,int *trocas){
    int x = vet[esquerda];
    int up = direita;
    int down = esquerda;
    int aux = 0;
    while(down < up){
        while(vet[down] <= x && down < direita){
            down = down+1;
        }
        while(vet[up] > x){ //vem percorrendo da direita at� se encontrar com o "ponteiro" da esquerda fazendo a varredura
            up = up-1;
        }
        if(down < up){
            aux = vet[down];
            vet[down] = vet[up];
            vet[up] = aux;
            //*trocas = *trocas + 1;
        }
    }
    vet[esquerda] = vet[up];
    vet[up] = x;
    //*trocas = *trocas + 1;
    return(up);
}

