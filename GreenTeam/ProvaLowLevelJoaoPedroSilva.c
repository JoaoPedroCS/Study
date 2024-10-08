//João Pedro Corrêa Silva
//Eu fiz incluindo as funcionalidades extras, nao consegui fazer receber inputs todos na mesma linha infelizmente, mas acho que ficou bem legal
//eu nao fui cuidadoso com a memória, mas acho que nao tem problema, pois o programa é pequeno e nao vai ser usado por muito tempo.




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Coloquei aqui pra nao encher a visão :)
char* options = "0.Como usar\n1.Somar Matrizes\n2.Subtrair Matrizes\n3.Multiplicação de Matrizes\n4.Multiplição Escalar\n5.Calcular Transposta\n6.Verificar Simetria\n7.Verificar se a matriz é quadrada\n8.Sair\n";
    
//protótipos
int get_int(char* msg);
void menu(void);
void help(void);
void end(void);
int* rowsxcolumns(void);
int** matriz(int rows, int columns);
void print_matrix(int** matrix, int rows, int columns);
int** matrix_sum(int** matrixA, int** matrixB, int rows, int columns);
int** matrix_notsum(int** matrixA, int** matrixB, int rows, int columns);
int** matrix_mult(int** matrixA, int** matrixB, int rowsA, int columnsA, int rowsB, int columnsB);
int** escalar(int** matrix, int rows, int columns, int escalar);
int** transposta(int** matrix, int rows, int columns);

int main(void) 
{
    menu();//minimalistico
}

//funções
void menu(void) //menu principal com opções de operações
{
    printf("\n-----Calculadora de Matrizes-----\n%s", options);
    int operation = get_int("Escolha uma opção:\n");
    if (operation == 0)
    {
        help();
    }
    else if (operation == 1)
    {
        int nofmatrixes = get_int("Digite o número de matrizes que deseja somar:\n"); //pega esse numero
        if (nofmatrixes < 2) //se for menor que 2, não é possivel somar ou subtrair
        {
            printf("Número de matrizes inválido\n");
            return;
        }
        int* size = rowsxcolumns(); //pega o tamanho da matriz, em soma e subtração, todas as matrizes tem que ter o mesmo tamanho
        int** matrixA = matriz(size[0], size[1]); 
        int** matrixB = matriz(size[0], size[1]);
        matrixA = matrix_sum(matrixA, matrixB, size[0], size[1]); //peguei as duas primeiras, e somei, e guardei na matrizA, assim nao preciso criar varias outras arrays
        for (int i = 0; i < nofmatrixes-2; i++)
        {
            matrixB = matriz(size[0], size[1]);
            matrixA = matrix_sum(matrixA, matrixB, size[0], size[1]);
        }
        printf("------Resultado:------\n");
        print_matrix(matrixA, size[0], size[1]);
        end();
    }
    else if (operation == 2)
    {   // aqui mesma coisa da de cima, mas subtração
        int nofmatrixes = get_int("Digite o número de matrizes que deseja subtrair:\n");
        if (nofmatrixes < 2)
        {
            printf("Número de matrizes inválido\n");
            return;
        }
        int* size = rowsxcolumns();
        
        int** matrixA = matriz(size[0], size[1]); 
        int** matrixB = matriz(size[0], size[1]);
        matrixA = matrix_notsum(matrixA, matrixB, size[0], size[1]);
        for (int i = 0; i < nofmatrixes-2; i++)
        {
            matrixB = matriz(size[0], size[1]);
            matrixA = matrix_notsum(matrixA, matrixB, size[0], size[1]);
        }
        printf("------Resultado:------\n");
        print_matrix(matrixA, size[0], size[1]);
        end();
    }
    else if (operation == 3)
    {//o mais complicado de todos, multiplicação de matrizes, explico mais na função
        printf("Para multiplicação de matrizes, o número de colunas de A é o numero de linhas de B\n");
        int* sizeA = rowsxcolumns();
        int* sizeB = malloc(2 * sizeof(int));
        sizeB[0] = sizeA[1];
        sizeB[1] = get_int("Digite o número de colunas da matriz B:\n");
        int** matrixA = matriz(sizeA[0], sizeA[1]);
        int** matrixB = matriz(sizeB[0], sizeB[1]);
        int** result = matrix_mult(matrixA, matrixB, sizeA[0], sizeA[1], sizeB[0], sizeB[1]);
        printf("------Resultado:------\n");
        print_matrix(result, sizeA[0], sizeB[1]);
        end();
    }
    else if (operation == 4)
    {//simples pega uma array de arrays e multiplica todos os elementos por um escalar
        int n = get_int("Digite o valor do escalar:\n");
        int* size = rowsxcolumns();
        int** matrix = matriz(size[0], size[1]);
        int** result = escalar(matrix, size[0], size[1], n);
        printf("------Resultado:------\n");
        print_matrix(result, size[0], size[1]);
        end();

    }
    else if (operation == 5)
    {//aqui eu crio uma transposta
        int* size = rowsxcolumns();
        int** matrix = matriz(size[0], size[1]);
        int** result = transposta(matrix, size[0], size[1]);
        printf("------Resultado:------\n");
        print_matrix(result, size[1], size[0]);
        end();
    }
    else if (operation == 6)
    {//aqui eu crio uma transposta e comparo com a original, se forem iguais, é simetrica
        int* size = rowsxcolumns();
        int** matrix = matriz(size[0], size[1]);
        int** matrixt = transposta(matrix, size[0], size[1]);
        if (size[0] == size[1])
        {
            int flag = 0;
            for (int i = 0; i < size[0]; i++)
            {
                for (int j = 0; j < size[1]; j++)
                {
                    if (matrix[i][j] != matrixt[i][j])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0)
            {
                printf("-----A matriz é simétrica-----\n");
            }
            else
            {
                printf("-----A matriz não é simétrica-----\n");
            }
        }
        else
        {
            printf("-----A matriz não é simétrica-----\n");
        }
        printf("\n");
        end();
    }
    else if (operation == 7)
    {//aqui eu vejo se o numero de linhas é igual ao de colunas
        int* size = rowsxcolumns();
        int** matrix = matriz(size[0], size[1]);
        if (size[0] == size[1])
        {
            printf("-----A matriz é quadrada-----\n");
        }
        else
        {
            printf("-----A matriz não é quadrada-----\n");
        }
        printf("\n");
        end();
    }
    else if (operation == 8)
    {
        printf("Saindo...\n");
        exit(0);
    }
}

void help(void) //aqui só o textinho de ajuda mesmo
{
    printf("\n\nPara usar bastar escolher a operação desejada:\nSe selecionar de 1-2, escolha quantas matrizes serão calculadas, tem que ser no minimo 2, depois digite o número de linhas e colunas\n4 será 2 matrizes, e 5-8, será apenas uma matriz. Ao digitar sua matriz, deve ser digitada linha por linha, e separando os itens por enter\nDepois de digitar toda a matriz, o resultado será mostrado\n");
    end();
}

void end(void) // aqui ve se a pessoa quer voltar pro menu ou sair
{
    int n = get_int("1.Para voltar ao menu inicial\n2.Para sair\n");
    if (n == 1) {menu();}
    else if (n == 2)
    {
        printf("Saindo...\n");
        exit(0);
    }
    else
    {
        printf("Opção inválida\n");
        help();
    }
}

int get_int(char* msg) //pega o inteiro e verifica se é inteiro mesmo
{
    int n;
    int result;
    char c;
    do {
        printf("%s", msg);
        result = scanf("%d", &n);
        while ((c = getchar()) != '\n' && c != EOF);
        if (result != 1) {
            printf("Entrada inválida. Apenas números.\n");
        }
    } while (result != 1);
    return n;
}

int* rowsxcolumns(void) //cria uma array com o numero de linhas e colunas
{
    int* size = (int*)malloc(2 * sizeof(int));
    size[0] = get_int("Digite o número de linhas da matriz:\n");
    size[1] = get_int("Digite o número de colunas da matriz:\n");
    return size;
}

int** matriz(int rows, int columns) //cria a matriz
{
    int** arr = (int**)malloc(rows * sizeof(int*));
    
    if (arr == NULL) {
        printf("Erro na memória\n");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(columns * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation for row %d failed!\n", i);

            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return NULL;
        }
    }
    for (int i = 0; i < rows; i++) {
        printf("Digite os valor da linha %d, pressione enter a cada número:\n", i+1);
        for (int j = 0; j < columns; j++) {
            arr[i][j] = get_int(" ");
        }
    }
    printf("------A Matriz:------\n");
    print_matrix(arr, rows, columns);
    return arr;
}

void print_matrix(int** matrix, int rows, int columns) //printa a matriz
{
    for (int i = 0; i < rows; i++) {
        printf("| ");
        for (int j = 0; j < columns; j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

int** matrix_sum(int** matrixA, int** matrixB, int rows, int columns) //soma as matrizes
{
    int** result = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(columns * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

int** matrix_notsum(int** matrixA, int** matrixB, int rows, int columns) //subtração
{
    int** result = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(columns * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return result;
}

int** matrix_mult(int** matrixA, int** matrixB, int rowsA, int columnsA, int rowsB, int columnsB) //multiplicação, crio a array de arrays, com linhas de A e colunas de B, e multiplico de acordo com a regra
{
    int** result = (int**)malloc(rowsA * sizeof(int*));
    for (int i = 0; i < rowsA; i++) {
        result[i] = (int*)malloc(columnsB * sizeof(int));
    }
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columnsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

int** escalar(int** matrix, int rows, int columns, int escalar) //multiplica todos os elementos por um escalar, nada demais
{
    int** result = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(columns * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix[i][j] * escalar;
        }
    }
    return result;
}

int** transposta(int** matrix, int rows, int columns) //inverto o tamanho invertendo as linhas e colunas da original, e calculo fazendo o mesmo
{
    int** result = (int**)malloc(columns * sizeof(int*));
    for (int i = 0; i < columns; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
    }
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}
