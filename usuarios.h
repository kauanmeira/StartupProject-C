#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
typedef struct usuario User;
struct usuario
{
    char nome[30];
    char login[30];
    char senha[30];
    char nivelUsuario[10];
};
void inserirUsuario();
void listarusuarios();

void inserirUsuario()
{
    FILE *arquivo;
    User usuario;
    arquivo = fopen("usuarios.txt", "ab");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    else
    {
        fclose(arquivo);
        char dados[80] = "";
        char loginSenha[80] = "";
        int tipoUsuario;
        printf("========================================================================================================\n");
        printf("====================================== STARTUP SOFTWARES DIGITAIS ======================================\n");
        printf("=========================================  CADASTRO DE USUARIO  ========================================\n");
        printf("========================================================================================================\n");
        fflush(stdin);
        printf("Digite o nome: ");
        gets(usuario.nome);

        fflush(stdin);
        printf("Digite o login: ");
        gets(usuario.login);

        fflush(stdin);
        printf("Digite a senha: ");
        gets(usuario.senha);

        printf("Nivel: 1-ADMIN / 0-USER\n");
        scanf("%d", &tipoUsuario);
        if (tipoUsuario == 1)
        {
            strcpy(usuario.nivelUsuario, "ADMIN");
            }
            else
            {
                strcpy(usuario.nivelUsuario, "USER");
            }
            system("cls");
            printf("\nNome: %s", usuario.nome);
            printf("\nLogin: %s", usuario.login);
            printf("\nNivel: %s", usuario.nivelUsuario);
            int salvar;
            printf("\nSalvar? 1-SIM / 0-NÂO\n");
            scanf(" %d", &salvar);
            if (salvar == 1){
                arquivo = fopen("usuarios.txt", "ab");
                fwrite(&usuario, sizeof(User), 1, arquivo);
                fclose(arquivo);
            }
    }
}
void listarusuarios()
{
    FILE *arquivo;
    User usuario;
    arquivo = fopen("usuarios.txt", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    else
    {
        printf("========================================================================================================\n");
        printf("====================================== STARTUP SOFTWARES DIGITAIS ======================================\n");
        printf("=========================================  LISTA DE USUARIO  ===========================================\n");
        printf("========================================================================================================\n");
        while (fread(&usuario, sizeof(User), 1, arquivo) == 1)
        {
            printf("-------------------------\n");
            printf("Nome: %s\n", usuario.nome);
            printf("login: %s\n", usuario.login);
            printf("senha: %s\n", usuario.senha);
            printf("tipo de usuario: %s\n", usuario.nivelUsuario);
            printf("-------------------------\n");
        }
        fclose(arquivo);
        printf("Precione ENTER para voltar ao menu");
        getchar();
    }
}