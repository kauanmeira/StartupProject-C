#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct data DATA;
struct data
{
    int dia;
    int mes;
    int ano;
};
typedef struct chamado Chamado;
struct chamado
{
    char tipo[30];
    char cliente[30];
    char descricao[30];
    char criado_por[30];
    char finalizado_por[30];
    float valor;
    DATA data_abertura;
    DATA data_concluido;
};

void abrirChamado(char nomeusuarioOnline[30]);

void listarChamado();
void chamadosFinalizadosPorAnoEValor();

    void
    listarFinalizarChamadoPorCliente(char nomeusuarioOnline[30]);

void abrirChamado(char nomeusuarioOnline[30])
{  setlocale(LC_ALL, "Portuguese");
    FILE *arquivo;
    Chamado chamado;
    arquivo = fopen("chamados.txt", "ab");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    else
    {

            fclose(arquivo);
        do
        {
            system("cls");
            char dados[80] = "";
            char loginSenha[80] = "";
            int tipoUsuario;
            fflush(stdin);
            printf("******CADASTRO DE CHAMADO******\n");
            printf("Digite o CHAMADO: ");
            gets(chamado.tipo);

            fflush(stdin);
            printf("Digite o CLIENTE: ");
            gets(chamado.cliente);

            fflush(stdin);



            printf("Descrição:  ");
            gets(chamado.descricao);
            fflush(stdin);
            strcpy(chamado.criado_por, nomeusuarioOnline);
            // fflush(stdin);
            // printf("Digite a senha: ");
            // gets(chamado.criado_por);
            fflush(stdin);
            chamado.data_concluido.dia = 0;
            chamado.data_concluido.mes = 0;
            chamado.data_concluido.ano = 0;
            fflush(stdin);
            printf("Valor($): ");
            scanf(" %f", &chamado.valor);

            fflush(stdin);
            printf("Data abertura(DD/MM/AAAA): ");
            scanf("%d/%d/%d", &chamado.data_abertura.dia, &chamado.data_abertura.mes, &chamado.data_abertura.ano);
            int salvar;
            system("cls");
            printf("******CADASTRO DE CHAMADO******\n");
            printf("Chamado: %s\n", chamado.tipo);
            printf("Cliente: %s\n", chamado.cliente);
            printf("Descrição: %s\n ", setlocale(LC_ALL,NULL), chamado.descricao);
            printf("Valor($): %.2f\n", chamado.valor);
            printf("Data abertura: %d/%d/%d\n", chamado.data_abertura.dia, chamado.data_abertura.mes, chamado.data_abertura.ano);
            printf("\nSalvar? 1-SIM / 0-NÂO\n ", setlocale(LC_ALL,NULL));
            fflush(stdin);
            scanf(" %d", &salvar);
            if (salvar == 1)
            {
                arquivo = fopen("chamados.txt", "ab");
                fwrite(&chamado, sizeof(Chamado), 1, arquivo);
                fclose(arquivo);
            }
            fflush(stdin);
            system("cls");
            printf("ABRIR NOVO CHAMADO? 1-SIM / 0-NÂO\n");
        } while (getche() == '1');
        fclose(arquivo);
    }
}
void listarChamado()
{
    FILE *arquivo;
    Chamado chamado;
    arquivo = fopen("chamados.txt", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    else
    {
        while (fread(&chamado, sizeof(Chamado), 1, arquivo) == 1)
        {
            printf("Chamado: %s\n", chamado.tipo);
            printf("Cliente: %s\n", chamado.cliente);
            printf("Descrição: %s\n", chamado.descricao);
            printf("Valor($): %.2f\n", chamado.valor);
            printf("Data abertura: %d/%d/%d\n", chamado.data_abertura.dia, chamado.data_abertura.mes, chamado.data_abertura.ano);
            printf("Data fechamento: %d/%d/%d\n", chamado.data_concluido.dia, chamado.data_concluido.mes, chamado.data_concluido.ano);
            printf("------------------\n\n");
        }
        fclose(arquivo);
        fflush(stdin);
        printf("Precione Enter para voltar!");
        getch();
    }
}

void listarFinalizarChamadoPorCliente(char nomeusuarioOnline[30])
{
    FILE *arquivo;
    Chamado chamado;
    Chamado alterarChamado;
    char cliente[30];
    int id, i = 1;
    arquivo = fopen("chamados.txt", "rb+");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    else
    {
        fflush(stdin);
        printf("Digite o nome do cliente: ");
        gets(cliente);
        int count = 1, count2 = 1;
        while (fread(&chamado, sizeof(Chamado), 1, arquivo) == 1)
        {
            if (strcmp(cliente, chamado.cliente) == 0)
            {
                printf("ID: %d\n", i);
                printf("Chamado: %s\n", chamado.tipo);
                printf("Cliente: %s\n", chamado.cliente);
                printf("Descrição: %s\n", chamado.descricao);
                printf("Data abertura: %d/%d/%d\n", chamado.data_abertura.dia, chamado.data_abertura.mes, chamado.data_abertura.ano);
                printf("Data fechamento: %d/%d/%d\n", chamado.data_concluido.dia, chamado.data_concluido.mes, chamado.data_concluido.ano);
                printf("------------------\n\n");
                count++;
            }
            i++;
        }
        if(count > 1){
            fflush(stdin);
            printf("Digite o ID do chamado que deseja finalizar: \n");
            scanf("%d", &id);
            id--;
            if (id >= 0 && id < i - 1)
            {
                fclose(arquivo);
                arquivo = fopen("chamados.txt", "rb+");
                while (fread(&alterarChamado, sizeof(Chamado), 1, arquivo) == 1)
                {
                        if(count2 == id + 1){

                        printf("Chamado: %s\n", alterarChamado.tipo);
                        printf("Cliente: %s\n", alterarChamado.cliente);
                        printf("Descrição: %s\n", alterarChamado.descricao);
                        printf("Data abertura: %d/%d/%d\n", alterarChamado.data_abertura.dia, alterarChamado.data_abertura.mes, alterarChamado.data_abertura.ano);
                        printf("Data fechamento: %d/%d/%d\n", alterarChamado.data_concluido.dia, alterarChamado.data_concluido.mes, alterarChamado.data_concluido.ano);
                        printf("------------------\n\n");
                        }
                        count2++;
                }
                printf("Digite a data de finalização(DD/MM/AAAA):\n");
                strcpy(alterarChamado.finalizado_por, nomeusuarioOnline);
                scanf("%d/%d/%d", &alterarChamado.data_concluido.dia, &alterarChamado.data_concluido.mes, &alterarChamado.data_concluido.ano);
                fseek(arquivo, id * sizeof(Chamado), SEEK_SET);
                fwrite(&alterarChamado, sizeof(Chamado), 1, arquivo);
            }
            fclose(arquivo);
        }
        else {
            printf("Cliente não encontrado!!");
        }
    }
}

void chamadosFinalizadosPorAnoEValor(){
    FILE *arquivo;
    FILE *relatorio;
    Chamado chamado;
    arquivo = fopen("chamados.txt", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    else
    {
        int ano, mes, quantidadeChamadosFinalizados = 0;
        float valorTotalChamados = 0.0, descAvista = 0.0;
        char nomeCliente[30];
        relatorio = fopen("relatorio.txt", "w");
        fflush(stdin);
        printf("Cliente: ");
        gets(nomeCliente);
        printf("Mês e ano para gerar relatorio");
        scanf("%d/%d", &mes,&ano);

        while (fread(&chamado, sizeof(Chamado), 1, arquivo) == 1)
        {
            if (strcmp(nomeCliente, chamado.cliente) == 0)
            {
                if (ano == chamado.data_concluido.ano && mes == chamado.data_concluido.mes)
                {
                    printf("Chamado: %s\n", chamado.tipo, setlocale(LC_ALL,""));
                    printf("Cliente: %s\n", chamado.cliente);
                    printf("Descrição: %s\n", chamado.descricao);
                    printf("Valor($): %.2f\n", chamado.valor);
                    printf("Data abertura: %d/%d/%d\n", chamado.data_abertura.dia, chamado.data_abertura.mes, chamado.data_abertura.ano);
                    printf("Data fechamento: %d/%d/%d\n", chamado.data_concluido.dia, chamado.data_concluido.mes, chamado.data_concluido.ano);
                    printf("------------------\n\n");
                    quantidadeChamadosFinalizados = quantidadeChamadosFinalizados + 1;
                    valorTotalChamados = valorTotalChamados + chamado.valor;

                    fprintf(relatorio,"Chamado: %s\n", chamado.tipo);
                    fprintf(relatorio,"Cliente: %s\n", chamado.cliente);
                    fprintf(relatorio, "Descrição: %s\n", chamado.descricao);
                    fprintf(relatorio, "Valor($): %.2f\n", chamado.valor);
                    fprintf(relatorio, "Data abertura: %d/%d/%d\n", chamado.data_abertura.dia, chamado.data_abertura.mes, chamado.data_abertura.ano);
                    fprintf(relatorio, "Data fechamento: %d/%d/%d\n", chamado.data_concluido.dia, chamado.data_concluido.mes, chamado.data_concluido.ano);
                    fprintf(relatorio, "------------------\n\n");
                }
            }
        }
        printf("Total de chamados finalizados: %d\n", quantidadeChamadosFinalizados);
        printf("Valor total:R$ %.2f\n", valorTotalChamados);
        printf("Valor avista:R$ %.2f\n", valorTotalChamados * 0.9);
        fprintf(relatorio, "Total de chamados finalizados: %d\n", quantidadeChamadosFinalizados);
        fprintf(relatorio, "Valor total:R$ %.2f\n", valorTotalChamados);
        fprintf(relatorio, "Valor avista:R$ %.2f\n", valorTotalChamados * 0.9);
        fclose(arquivo);
        fclose(relatorio);
        fflush(stdin);
        printf("Precione Enter para voltar!\n");
        getch();
    }
}
