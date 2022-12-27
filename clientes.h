#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct cadastroclientes
{
    char nome[20][20];
    char cpfcnpj[30][20];
    char num[30][20];
    char endereco[50][20];
    char numcasa[20][20];
    char complemento[50][20];
    char bairro[50][20];
} cadastroclientes;

void listarclientes();

void inserircliente();

void listarclientes()
{setlocale(LC_ALL, "Portuguese-brazilian");
    FILE *bdcliente;
    char leitor[100];
    getchar();
    bdcliente = fopen("bdclientes.txt", "r");
    if (bdcliente == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    else
    {
        printf("========================================================================================================\n");
        printf("====================================== STARTUP SOFTWARES DIGITAIS ======================================\n");
        printf("=========================================  LISTA DE CLIENTES  ==========================================\n");
        printf("========================================================================================================\n");
        while (fgets(leitor, 100, bdcliente) != NULL)
        {
            printf("-------------------------\n");
            printf("NOME: %s\n", strtok(leitor, ","));
            printf("TELEFONE/CELULAR: %s\n", strtok(NULL, ","));
            printf("CPF/CNPJ: %s\n", strtok(NULL, ","));
            printf("ENDEREÇO: %s\n", strtok(NULL, ","));
            printf("BAIRRO: %s\n", strtok(NULL, ","));
            printf("NÚMERO: %s\n", strtok(NULL, ","));
            printf("COMPLEMENTO: %s\n", strtok(NULL, "\n"));
            printf("-------------------------\n");
        }
        fclose(bdcliente);
        printf("Precione ENTER para voltar ao menu");
        getchar();
    }
}

void inserircliente()
{setlocale(LC_ALL, "Portuguese-brazilian");
    getchar();
    char linha[100];

    cadastroclientes cadastro;

    FILE *bdclientes;

    int resp;
    int i = 0;
    int contador = 2;

    do
    {
        fflush(stdin);
        strcpy(linha, "");
        printf("========================================================================================================\n");
        printf("====================================== STARTUP SOFTWARES DIGITAIS ======================================\n");
        printf("========================================   CADASTRO DE CLIENTES   ======================================\n");
        printf("========================================================================================================\n");
        printf("NOME:");
        gets(cadastro.nome[i]);
        strcat(linha, cadastro.nome[i]);
        strcat(linha, ",");
        printf("CPF/CNPJ:");
        gets(cadastro.cpfcnpj[i]);
        strcat(linha, cadastro.cpfcnpj[i]);
        strcat(linha, ",");
        printf("TELEFONE/CELULAR:");
        gets(cadastro.num[i]);
        strcat(linha, cadastro.num[i]);
        strcat(linha, ",");
        printf("ENDEREÇO:");
        gets(cadastro.endereco[i]);
        strcat(linha, cadastro.endereco[i]);
        strcat(linha, ",");
        printf("BAIRRO:");
        gets(cadastro.bairro[i]);
        strcat(linha, cadastro.bairro[i]);
        strcat(linha, ",");
        printf("N?MERO:");
        gets(cadastro.numcasa[i]);
        strcat(linha, cadastro.numcasa[i]);
        strcat(linha, ",");
        printf("COMPLEMENTO:");
        gets(cadastro.complemento[i]);
        strcat(linha, cadastro.complemento[i]);
        strcat(linha, ",");
        strcat(linha, "\n");
        system("cls");
        printf("\nNome: %s", cadastro.nome[i]);
        printf("\nCPF/CNPJ: %s", cadastro.cpfcnpj[i]);
        printf("\nTELEFONE/CELULAR: %s", cadastro.num[i]);
        printf("\nENDEREÇO: %s", cadastro.endereco[i]);
        printf("\nBAIRRO: %s", cadastro.bairro[i]);
        printf("\nNÚMERO: %s", cadastro.numcasa[i]);
        printf("\nCOMPLEMENTO: %s", cadastro.complemento[i]);
        int salvar;
        printf("\nSalvar? 1-SIM / 0-NÃO\n");
        scanf(" %d", &salvar);
        if (salvar == 1){
            bdclientes = fopen("bdclientes.txt", "a");
            fprintf(bdclientes, linha, "%s");
            fclose(bdclientes);
        }
        // system("cls");
        // printf("1-Novo cliente / 0 - Voltar");
        // scanf(" %d", &resp);
        system("cls");
    } while (resp == 1);
}