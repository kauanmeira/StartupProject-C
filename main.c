#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "main.h"


char sessao[30];
char nomeusuarioOnline[30];
void migration();
void listar();
int login();
void menuAdmin();
void menuUser();

int main()
{
    setlocale(LC_ALL, "Portuguese-brazilian");
    FILE *arquivo;
    arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL)
    {
        migration();
    }
    int validaDado = login();
    // printf("Tipo de usuario: %s\n", sessao);
    if (validaDado == 1)
    {
        if (strcmp(sessao, "ADMIN") == 0){
            menuAdmin();
        } else {
            menuUser();
        }
        printf("Tipo de usuario: %s\n", sessao);
    }
    else
    {
        printf("Erro");
    }
    getchar();
    return 0;
}

int login()
{
    FILE *arquivo;
    User usuario;
    printf("%s \n", sessao);
    strcpy(sessao, " ");
    printf("%s \n", sessao);
    char login[30];
    char senha[30];
    arquivo = fopen("usuarios.txt", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    else
    {
        int a = 0, b = 1, d = 3, c = 0;
        char login[30];
        char senha[30];
        int validaLongin = 0;
        do
        {
            fclose(arquivo);
            arquivo = fopen("usuarios.txt", "rb");
            a = 0;
            system("cls");
            printf("========================================================================================================\n");
            printf("====================================== STARTUP SOFTWARES DIGITAIS ======================================\n");
            printf("========================================================================================================\n\n\n");
            printf("Digite o Login: ");
            scanf("%s", login);
            printf("Digite a Senha: ");
            do
            {
                c = getch();
                if (isprint(c))
                {
                    senha[a] = c;
                    a++;
                    printf("*");
                }
                else if (c == 8 && a)
                {
                    senha[a] = '\0';
                    a--;
                    printf("\b \b");
                }
            } while (c != 13);
            senha[a] = '\0';
            while (fread(&usuario, sizeof(User), 1, arquivo) == 1)
            {


                if (strcmp(usuario.login, login) == 0)
                {
                    if (strcmp(usuario.senha, senha) == 0)
                    {
                        strcpy(nomeusuarioOnline, usuario.nome);
                        if (strcmp(usuario.nivelUsuario, "ADMIN") == 0)
                        {
                            strcpy(sessao, "ADMIN");
                        }
                        else
                        {
                            strcpy(sessao, "USER");
                        }
                        validaLongin = 1;
                        fclose(arquivo);
                        return 1;
                    }
                    else
                    {
                        printf("Senha invalida\n");
                        fclose(arquivo);
                    }
                }
                else
                {

                }
                validaLongin = 2;
            }
            printf("usuario não encontrado\n");
            fclose(arquivo);
        } while (validaLongin == 2);
        return 0;
    }
}

void migration()
{
    User admin;
    FILE *arquivo;
    arquivo = fopen("usuarios.txt", "ab");
    strcpy(admin.nome, "ADMIN");
    strcpy(admin.login, "ADMIN");
    strcpy(admin.senha, "ADMIN");
    strcpy(admin.nivelUsuario, "ADMIN");
    fwrite(&admin, sizeof(User), 1, arquivo);
    fclose(arquivo);
}

void menuAdmin()
{
    int opcao;
    do
    {
        // system("cls");
        setlocale(LC_ALL, "");
        system("cls");
        printf("==========================================================================================\n");
        printf("====================================== MENU ADMINISTRADOR ================================\n");
        printf("==========================================================================================\n\n\n");
        printf("1 - Cadastrar Usuario\n");
        printf("2 - Listar usuarios\n");
        printf("3 - Cadastrar Cliente\n");
        printf("4 - Listar Clientes\n");
        printf("5 - Abrir chamado\n");
        printf("6 - Listar chamados\n");
        printf("7 - Finalizar chamado\n");
        printf("8 - Relatorio dos chamados por cliente\n");
        printf("0 - Sair\n");
        printf("\n\nEscolha uma opção: \n", setlocale(LC_ALL,""));
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            inserirUsuario();
            getchar();
            break;
        case 2:
            system("cls");
            listarusuarios();
            getchar();
            break;
        case 3:
            system("cls");
            inserircliente();
            getchar();
            break;
        case 4:
            system("cls");
            listarclientes();
            getchar();
            break;
        case 5:
            system("cls");
            abrirChamado(nomeusuarioOnline);
            getchar();
            break;
        case 6:
            system("cls");
            listarChamado();
            getchar();
            break;
        case 7:
            system("cls");
            listarFinalizarChamadoPorCliente(nomeusuarioOnline);
            getchar();
            break;
        case 8:
            system("cls");
            chamadosFinalizadosPorAnoEValor();
            getchar();
            break;
        case 0:
            system ("cls");
            printf("Bye!!\n");
            return 0;
            break;

        default:

           printf("Opção inválida\n");
           system ("pause");
getchar();
            {
                menuAdmin();
            }
            break;
        }

    } while (opcao != 0);
}

void menuUser(){

    int opcao;
    do
    {
        system("cls");
        printf("==========================================================================================\n");
        printf("====================================== MENU USUARIO ======================================\n");
        printf("==========================================================================================\n\n\n");
        printf("1 - Listar Clientes\n");
        printf("2 - Abrir chamado\n");
        printf("3 - Listar chamados\n");
        printf("4 - Finalizar chamado\n");
        printf("0 - Sair\n");
        printf("\n\nEscolha uma opção: \n", setlocale(LC_ALL,""));
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            listarclientes();
            getchar();
            break;
        case 2:
            abrirChamado(nomeusuarioOnline);
            getchar();
            break;
        case 3:
            listarChamado();
            getchar();
            break;
        case 4:
            listarFinalizarChamadoPorCliente(nomeusuarioOnline);
            getchar();
            break;
        case 0:
            system ("cls");
            printf("Bye!!!\n");
            return 0;
            break;

        default:
            system ("cls");
            printf("Opção inválida\n");
            getch();
            break;
        }
    } while (opcao != 0);
}
