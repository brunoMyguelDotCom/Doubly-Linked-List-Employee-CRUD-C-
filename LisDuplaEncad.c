/*
Autor: Bruno Myguel
Data: 23/09/25

Objetivo: CRUD cadastro funcionarios com lista duplamente encadeada.

OBSERVACAO: Esse codigo foi feito em Macos, porem, com funcoes e verificacoes de sistema operacional para rodar em sistemas distintos.
usando #ifdef para verificar o sistema operacional onde esta sendo compilado
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * funcoes multiplataforma para linux, macOs e windows:
 * cor terminal
 * gotoxy
 */
#ifdef _WIN32
#include <windows.h>

void corTerminal(void)
{
	system("color 02"); // cor do terminal (VERDE)
}

void gotoxy(int x, int y)
{
	COORD pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#else
#include <unistd.h>

void corTerminal(void)
{
	printf("\033[40;32m");
}

void gotoxy(int x, int y)
{
	printf("\033[%d;%dH", y, x);
}
#endif

// funcao que substitui o sys(cls), verificando o sistema operacional antes de executar
void limpaTela()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

// sleep
void espera(int ms)
{
#ifdef _WIN32
	Sleep(ms);
#else
	usleep(ms * 1000); // mac e em microsegundo, por isso multiplicado por 1000
#endif
}

// funcao de pausa
void pausa()
{
	gotoxy(62, 22);
	printf("+");

	gotoxy(62, 24);
	printf("+");

	gotoxy(62, 23);
	printf("| Pressione ENTER");

	gotoxy(0, 0);

	getchar();
	getchar();
}

// TELAS E MENUS:
// tela padrao
void moldura()
{
	limpaTela();
	int i;

	for (i = 1; i < 25; i++)
	{
		gotoxy(1, i);
		printf("|");
		gotoxy(80, i);
		printf("|");
	}
	gotoxy(1, 1);
	printf("+------------------------------------------------------------------------------+");
	gotoxy(1, 4);
	printf("+------------------------------------------------------------------------------+");
	gotoxy(1, 22);
	printf("+------------------------------------------------------------------------------+");
	gotoxy(1, 24);
	printf("+------------------------------------------------------------------------------+");
	gotoxy(3, 2);
	printf("UNICV");
	gotoxy(3, 3);
	printf("Nome: Bruno Myguel Marcal");
	gotoxy(60, 2);
	printf("Estrutura de Dados");
	gotoxy(66, 3);
	printf("Prof. Rodney");
	gotoxy(2, 23);
	printf("MSG.:");
}

// Funcao da Tela dados funcionario
void telaCadastro()
{
	moldura();

	gotoxy(10, 8);
	printf("1 - Codigo.........: ");
	gotoxy(10, 10);
	printf("2 - Nome...........: ");
	gotoxy(10, 12);
	printf("3 - Endereco.......: ");
	gotoxy(10, 14);
	printf("4 - Cargo..........: ");
	gotoxy(10, 16);
	printf("5 - Data Admissao..: ");
	gotoxy(10, 18);
	printf("6 - Telefone.......: ");
	gotoxy(10, 20);
	printf("7 - Salario........: ");
}

// tela inicial
void telaMenu()
{
	moldura();

	gotoxy(27, 5);
	printf("GERENCIAMENTO FUNCIONARIOS");

	gotoxy(15, 9);
	printf("1 - Cadastrar Funcionario");
	gotoxy(15, 11);
	printf("2 - Remover Funcionario");
	gotoxy(15, 13);
	printf("3 - Alteracao do Cadastro de Funcionario");
	gotoxy(15, 15);
	printf("4 - Consultar Funcionarios");
	gotoxy(15, 17);
	printf("0 - Sair do Programa");
}

int subMenu(int possibilidadeDeTela) // passando possibilidade de tela ele muda o que o usuario ve na execucao
{

	int resp = -1;
	moldura();
	do
	{
		if (possibilidadeDeTela == 1)
		{
			gotoxy(15, 7);
			printf("*CADASTAR* FUNCIONARIO");

			gotoxy(15, 9);
			printf("1 - Cadastrar Funcionario no Inicio da Lista");
			gotoxy(15, 11);
			printf("2 - Cadastrar Funcionario no Final da Lista");
			gotoxy(15, 13);
			printf("3 - Cadastrar Funcionario em uma Posicao da Lista");
			gotoxy(15, 15);
			printf("4 - VOLTAR AO INICIO");

			gotoxy(7, 23);
			printf("Digite uma opcao: ");
			scanf("%d", &resp);

			return resp;
		}

		if (possibilidadeDeTela == 2)
		{
			gotoxy(15, 7);
			printf("*REMOVER* FUNCIONARIO");

			gotoxy(15, 9);
			printf("1 - Remover Funcionario no Inicio da Lista");
			gotoxy(15, 11);
			printf("2 - Remover Funcionario no Final da Lista");
			gotoxy(15, 13);
			printf("3 - Remover Funcionario em uma Posicao da Lista");
			gotoxy(15, 15);
			printf("4 - VOLTAR AO INICIO");

			gotoxy(7, 23);
			printf("Digite uma opcao: ");
			scanf("%d", &resp);

			return resp;
		}

		if (possibilidadeDeTela == 3)
		{
			gotoxy(15, 7);
			printf("*CONSULTAR* FUNCIONARIO");

			gotoxy(15, 9);
			printf("1 - Consultar Funcionario pelo Codigo");
			gotoxy(15, 11);
			printf("2 - Consultar Lista Completa");
			gotoxy(15, 13);
			printf("3 - Consultar Lista Completa - ORDENADA POR CODIGO");
			gotoxy(15, 15);
			printf("4 - Consultar Lista Completa - ORDENADA POR NOME");
			gotoxy(15, 17);
			printf("5 - VOLTAR AO INICIO");

			gotoxy(7, 23);
			printf("Digite uma opcao: ");
			scanf("%d", &resp);

			return resp;
		}

		if (resp != 1 && resp != 2 && resp != 3 && resp != 4)
		{
			gotoxy(24, 21);
			printf("Valor invalido, digite novamente!\n\n");
			pausa();
		}
	} while (resp != 1 && resp != 2 && resp != 3 && resp != 4);
}

// Funcao que limpa a Linha de Mensagem
void limpaMsg()
{
	gotoxy(7, 23);
	printf("                                                                 ");
}

void barraCarregamento()
{
	gotoxy(26, 13);
	printf("[");

	for (int i = 0; i < 25; i++)
	{
		printf("=");
		fflush(stdout);
		espera(40);
	}

	printf("]");
	espera(60);
}

void animacaoInicioFim(int possibilidade)
{

	if (possibilidade == 1)
	{

		int inicioMsg = 30;
		char msgSalvando[20] = "Abrindo o Arquivo...";

		gotoxy(inicioMsg, 12);

		moldura();

		for (size_t i = 0; i < 20; i++)
		{
			gotoxy(inicioMsg++, 12);
			espera(45);
			printf("%c", msgSalvando[i]);
		}
	}
	else if (possibilidade == 2)
	{

		int inicioMsg = 29;
		char msgSalvando[21] = "Salvando o Arquivo...";

		gotoxy(inicioMsg, 12);

		moldura();

		for (size_t i = 0; i < 21; i++)
		{
			gotoxy(inicioMsg++, 12);
			espera(45);
			printf("%c", msgSalvando[i]);
		}
	}
}

// ESTRUTURAS DE DADOS:
// Atributos do funcionario
typedef struct
{

	int codigo;
	char nome[50];
	char endereco[50];
	char cargo[50];
	char dt_admissao[11];
	char telefone[15];
	float salario;
} reg_funcionarios;

typedef struct Item *Apontador;

typedef struct Item
{

	Apontador anterior;
	reg_funcionarios conteudo;
	Apontador proximo;
} Item;

typedef struct
{

	Apontador primeiro;
	Apontador ultimo;
} Lista;

// REQUISITOS NAO FUNCIONAIS:
// conta lista
int contaLista(Lista *L)
{
	int cont = 0;
	Apontador PAux = L->primeiro;

	while (PAux != NULL)
	{
		cont++;
		PAux = PAux->proximo;
	}

	return cont;
}

// remove \n de string
void removeNovaLinhaString(char *string)
{
	size_t tam = strlen(string); // pega o tamanho da string

	if (tam > 0 && string[tam - 1] == '\n') // verifica se o ultimo caractere e \n
	{
		string[tam - 1] = '\0'; // se for, troca por \0 que finaliza a string
	}
}

void inicializaLista(Lista *L)
{

	L->primeiro = NULL;
	L->ultimo = NULL;
}

// verifica se so tem um item e ja o remove e iniicaliza a lista
int removeUnicoItem(Lista *L)
{
	if (L->primeiro == L->ultimo)
	{
		Apontador unico = L->primeiro;
		inicializaLista(L);
		free(unico);
		moldura();
		gotoxy(30, 5);
		printf("UNICO ITEM REMOVIDO!");
		espera(2000);
		return 1;
	}
	return 0;
}

// verifica se lista esta vazia
// usado somente em remocoes
int listaVazia(Lista *L)
{

	if (L->primeiro == NULL) // lista vazia
	{
		moldura();

		gotoxy(34, 5);
		printf("Lista vazia!");
		gotoxy(31, 6);
		printf("Impossivel remover!");

		espera(2000);

		return 1;
	}
	return 0;
}

// Verifica se codigo ja existe na lista
int verificaCodigo(Lista *L, int codConferido)
{
	Apontador PAux = L->primeiro;

	while (PAux != NULL)
	{
		if (PAux->conteudo.codigo == codConferido)
		{
			return 1; // codigo existe
		}
		PAux = PAux->proximo;
	}

	return 0; // permitido criar
}

// solicita os inputs ao usuario
Item *inputCadastro(Lista *L)
{
	Item *itemAtual = malloc(sizeof(Item));

	int confirmacao = -1;
	int codDuplicado;

	// chama tela para pedir input
	telaCadastro();
	do
	{
		gotoxy(31, 8);
		scanf("%d", &itemAtual->conteudo.codigo);
		getchar();

		codDuplicado = verificaCodigo(L, itemAtual->conteudo.codigo);

		if (codDuplicado)
		{
			gotoxy(8, 23);
			printf("CODIGO JA PERTENCE A OUTRO FUNCIONARIO!\n\n");
		}

	} while (codDuplicado);

	gotoxy(31, 10);
	fgets(itemAtual->conteudo.nome, sizeof(itemAtual->conteudo.nome), stdin);
	removeNovaLinhaString(itemAtual->conteudo.nome); // remove linha chamado so em string

	gotoxy(31, 12);
	fgets(itemAtual->conteudo.endereco, sizeof(itemAtual->conteudo.endereco), stdin);
	removeNovaLinhaString(itemAtual->conteudo.endereco);

	gotoxy(31, 14);
	fgets(itemAtual->conteudo.cargo, sizeof(itemAtual->conteudo.cargo), stdin);
	removeNovaLinhaString(itemAtual->conteudo.cargo);

	gotoxy(31, 16);
	fgets(itemAtual->conteudo.dt_admissao, sizeof(itemAtual->conteudo.dt_admissao), stdin);
	removeNovaLinhaString(itemAtual->conteudo.dt_admissao);

	getchar();

	gotoxy(31, 18);
	fgets(itemAtual->conteudo.telefone, sizeof(itemAtual->conteudo.telefone), stdin);
	removeNovaLinhaString(itemAtual->conteudo.telefone);

	gotoxy(31, 20);
	scanf("%f", &itemAtual->conteudo.salario);

	do // loop para confirmacao
	{
		gotoxy(8, 23);
		printf("Cadastrar funcionario? (1 - SIM, 0 - NAO):");
		gotoxy(8, 33);
		scanf("%d", &confirmacao);

		limpaMsg();

		// mostra confimacao
		if (confirmacao == 1)
		{

			gotoxy(8, 23);
			printf("OPERACAO CONCLUIDA!");

			espera(2000);
		}

		// cancela
		if (confirmacao == 0)
		{

			gotoxy(8, 23);
			printf("CADASTRO CANCELADO!\n\n");

			free(itemAtual);

			espera(2000);

			return NULL;
		}

		if (confirmacao != 1 && confirmacao != 0)
		{
			gotoxy(8, 23);
			printf("Valor invalido, digite novamente!\n\n");
			pausa();
		}

	} while (confirmacao != 1 && confirmacao != 0);

	return itemAtual;
}

// exibe de forma detalhada cada funcionario
void exibirDados(Item *itemE)
{
	telaCadastro();

	gotoxy(31, 8);
	printf("%d", itemE->conteudo.codigo);

	gotoxy(31, 10);
	printf("%s", itemE->conteudo.nome);

	gotoxy(31, 12);
	printf("%s", itemE->conteudo.endereco);

	gotoxy(31, 14);
	printf("%s", itemE->conteudo.cargo);

	gotoxy(31, 16);
	printf("%s", itemE->conteudo.dt_admissao);

	gotoxy(31, 18);
	printf("%s", itemE->conteudo.telefone);

	gotoxy(31, 20);
	printf("%.2f", itemE->conteudo.salario);

	gotoxy(8, 23);
	printf(" ");
	pausa();
}

// REQUISITOS FUNCIONAIS:
// cadastrar no final da lista
void CadFuncFinList(Lista *L)
{
	gotoxy(24, 6);
	printf("Colocando no FINAL da lista!");

	espera(2000);

	Apontador apontadorNovoItem = inputCadastro(L);

	if (apontadorNovoItem != NULL)
	{

		// verifica se a lista esta vazia
		if (L->primeiro == NULL)
		{
			L->primeiro = apontadorNovoItem;
			L->ultimo = L->primeiro;

			apontadorNovoItem->anterior = NULL;
			apontadorNovoItem->proximo = NULL;
		}
		else
		{
			// aterra o proximo
			apontadorNovoItem->proximo = NULL;

			// liga o penultimo no ultimo e vice versa
			L->ultimo->proximo = apontadorNovoItem;
			apontadorNovoItem->anterior = L->ultimo;

			// aponta pro "novo ultimo"
			L->ultimo = apontadorNovoItem;
		}
	}
}

void CadFuncIniList(Lista *L)
{
	gotoxy(23, 6);
	printf("Colocando no INICIO da lista!");

	espera(2000);

	Apontador apontadorNovoItem = inputCadastro(L);

	if (apontadorNovoItem != NULL)
	{
		// verifica se a lista esta vazia
		if (L->primeiro == NULL)
		{
			L->primeiro = apontadorNovoItem;
			L->ultimo = L->primeiro;

			apontadorNovoItem->anterior = NULL;
			apontadorNovoItem->proximo = NULL;
		}
		else
		{
			// aterra o anterior
			apontadorNovoItem->anterior = NULL;

			// liga o segundo no primeiro e vice versa
			apontadorNovoItem->proximo = L->primeiro;
			L->primeiro->anterior = apontadorNovoItem;

			// aponta para "novo primeiro"
			L->primeiro = apontadorNovoItem;
		}
	}
}

void CadFuncMidList(Lista *L, int posicao)
{

	// verifica se a lista esta vazia
	if (L->primeiro == NULL && posicao != 0)
	{
		gotoxy(34, 5);
		printf("Lista vazia!");
		gotoxy(23, 6);
		printf("Colocando no INICIO da lista!");

		espera(2000);
		Apontador apontadorNovoItem = inputCadastro(L);

		if (apontadorNovoItem != NULL)
		{

			// operacao para cadastrar no inicio
			apontadorNovoItem->anterior = NULL;
			apontadorNovoItem->proximo = NULL;
			L->primeiro = apontadorNovoItem;
			L->ultimo = apontadorNovoItem;
			return;
		}

		return;
	}

	// posicao 0
	if (posicao == 0)
	{
		gotoxy(28, 5);
		printf("Primeira posicao escolhida!");
		gotoxy(27, 6);
		printf("Colocando no INICIO da lista!");

		espera(2000);
		Apontador apontadorNovoItem = inputCadastro(L);

		if (apontadorNovoItem != NULL)
		{
			apontadorNovoItem->anterior = NULL;
			apontadorNovoItem->proximo = L->primeiro;
			L->primeiro->anterior = apontadorNovoItem;
			L->primeiro = apontadorNovoItem;
			return;
		}

		return;
	}

	// posicao no meio ou final
	Item *PAux = L->primeiro;
	int i = 0;
	while (PAux->proximo != NULL && i < posicao)
	{
		PAux = PAux->proximo;
		i++;
	}

	if (i < posicao) // cadastra no final
	{
		gotoxy(22, 5);
		printf("Lista menor que posicao solicitada!");
		gotoxy(24, 6);
		printf("Colocando no FINAL da lista!");

		espera(2000);
		Apontador apontadorNovoItem = inputCadastro(L);

		if (apontadorNovoItem != NULL)
		{
			apontadorNovoItem->proximo = NULL;
			apontadorNovoItem->anterior = L->ultimo;
			L->ultimo->proximo = apontadorNovoItem;
			L->ultimo = apontadorNovoItem;
		}
	}
	else
	{ // cadastra no meio

		gotoxy(27, 6);
		printf("Colocando na posicao %d!", posicao);

		espera(2000);
		Apontador apontadorNovoItem = inputCadastro(L);

		if (apontadorNovoItem != NULL)
		{
			apontadorNovoItem->anterior = PAux->anterior;
			apontadorNovoItem->proximo = PAux;
			PAux->anterior->proximo = apontadorNovoItem;
			PAux->anterior = apontadorNovoItem;
		}
	}
}

void RemFuncFinList(Lista *L)
{

	if (listaVazia(L))
	{
		return;
	} // lista vazia

	if (removeUnicoItem(L))
	{
		return;
	} // um item na lista
	else // remove o ultimo
	{
		Apontador PAux = L->ultimo;
		L->ultimo = PAux->anterior;
		L->ultimo->proximo = NULL;
		free(PAux);

		moldura();
		gotoxy(30, 5);
		printf("Ultima posicao removida!");

		espera(2000);
	}
}

void RemFuncIniList(Lista *L)
{

	if (listaVazia(L))
	{
		return;
	} // lista vazia

	// um item na lista
	if (removeUnicoItem(L))
	{
		return;
	}

	else // remove o primeiro
	{
		Apontador PAux = L->primeiro;
		L->primeiro = PAux->proximo;
		L->primeiro->anterior = NULL;
		free(PAux);

		moldura();
		gotoxy(34, 5);
		printf("Primeira posicao removida!");

		espera(2000);
	}
}

void RemFuncMidList(Lista *L, int posicao)
{

	if (listaVazia(L))
	{
		return;
	} // lista vazia

	if (removeUnicoItem(L))
	{
		return;
	} // um item na lista

	if (posicao == 0) // primeira opcao escolhida
	{
		RemFuncIniList(L);

		return;
	}

	// variaveis auxiliares
	Apontador PAux = L->primeiro;
	Apontador PAux2 = PAux->proximo;

	int i = 0;
	while (i < posicao) // percorre a lista
	{
		if (PAux2 == NULL && i < posicao) // lista menor que a posicao solicitada
		{
			gotoxy(22, 5);
			printf("Lista menor que posicao solicitada!");
			espera(2000);
			return;
		}

		PAux = PAux2;
		PAux2 = PAux2->proximo;
		i++;
	}

	if (PAux2 == NULL && i == posicao) // ultima posicao escolhida
	{
		RemFuncFinList(L);

		return;
	}
	else if (PAux != NULL && i == posicao) // qualquer posicao do meio
	{
		PAux->anterior->proximo = PAux2;
		PAux2->anterior = PAux->anterior;
		free(PAux);

		moldura();
		gotoxy(34, 5);
		printf("Posicao %d removida!", posicao);

		espera(2000);
	}
}

void AltFunc(Lista *L, int codAlt)
{
    Apontador PAux = L->primeiro;

    // procura pelo código
    while (PAux != NULL && PAux->conteudo.codigo != codAlt)
    {
        PAux = PAux->proximo;
    }

    if (PAux == NULL)
    {
        moldura();
        gotoxy(34, 5);
        printf("Codigo: %d inexistente!", codAlt);
        espera(2000);
        return;
    }

    // chama inputCadastro
    Item *reg = inputCadastro(L);

    if (reg != NULL)
    {
        // mantém o código original
        reg->conteudo.codigo = codAlt;

        // atualiza os outros campos
        PAux->conteudo = reg->conteudo;

        free(reg);

        gotoxy(34, 5);
        printf("Funcionario Cod: %d Alterado!", codAlt);
        espera(2000);
    }
    else
    {
        gotoxy(34, 5);
        printf("Alteracao cancelada!");
        espera(2000);
    }
}
void Consulta(Lista *L, int codAlt)
{

	Apontador PAux = L->primeiro;

	while (PAux != NULL && PAux->conteudo.codigo != codAlt)
	{
		PAux = PAux->proximo;
	}

	if (PAux == NULL)
	{
		gotoxy(34, 5);
		printf("Codigo: %d inexistente!", codAlt);

		espera(2000);

		return;
	}

	exibirDados(PAux);
}

void ConsultaListaCompleta(Lista *L)
{
	Apontador PAux = L->primeiro;

	// verifica lista vazia
	if (PAux == NULL)
	{
		moldura();
		gotoxy(34, 5);
		printf("Lista vazia!");
		espera(2000);
		return;
	}

	int linha = 8; // primeira linha para imprimir
	int qtdImpresso = 0;

	moldura();
	gotoxy(30, 5);
	printf("LISTA DE FUNCIONARIOS");

	gotoxy(4, 6);
	printf("Cod. | Nome                   | Cargo          | Data       | Salario");
	gotoxy(4, 7);
	printf("-----+------------------------+----------------+------------+------------");

	while (PAux != NULL)
	{
		gotoxy(4, linha);

		printf("%-4d | %-22.22s | %-14.14s | %-10s | %10.2f",
			   PAux->conteudo.codigo,
			   PAux->conteudo.nome,
			   PAux->conteudo.cargo,
			   PAux->conteudo.dt_admissao,
			   PAux->conteudo.salario); // print com tamanho predifinido

		PAux = PAux->proximo;
		linha += 1;
		qtdImpresso++;

		if (qtdImpresso == 14)
		{
			pausa();
			moldura();

			gotoxy(30, 5);
			printf("LISTA DE FUNCIONARIOS");

			// reseta o cabecalho
			gotoxy(4, 6);
			printf("Cod. | Nome                   | Cargo          | Data       | Salario");

			gotoxy(4, 7);
			printf("-----+------------------------+----------------+------------+------------");

			// reseta as duas variaveis
			linha = 8;
			qtdImpresso = 0;
		}
	}

	gotoxy(8, 23);
	printf("Fim da lista");
	pausa();
}

// PERSISTENCIA
// ler arquivo
void leArquivo(Lista *L)
{
	FILE *file;
	reg_funcionarios func;
	Apontador lido;

	// abre arquivo / modo leitura
	file = fopen("funcionarios.dat", "rb");

	if (file == NULL) // nao consegue abrir ou criar o arquivo
	{
		gotoxy(10, 23);
		printf("Erro ao abrir o arquivo!");
		return;
	}
	else
	{
		// enquanto conseguir ler registros
		while (fread(&func, sizeof(reg_funcionarios), 1, file))
		{
			// cria item
			lido = (Apontador)malloc(sizeof(Item));

			if (lido == NULL) // nao conseguiu criar
			{
				gotoxy(10, 23);
				printf("Erro: memoria insuficiente!");
				fclose(file);
				return;
			}

			// copia o conteudo e aterra o proximo
			lido->conteudo = func;
			lido->proximo = NULL;

			if (L->primeiro == NULL)
			{ // lista vazia, coloca registro do arquivo na primeira posicao
				L->primeiro = lido;
				L->ultimo = lido;

				// aterra ultimo
				lido->anterior = NULL;
			}
			else
			{ // coloca no final
				lido->anterior = L->ultimo;
				L->ultimo->proximo = lido;
				L->ultimo = lido;
			}
		}
	}

	// fecha arquivo
	fclose(file);
}

// salvar arquivo
void salvaArquivo(Lista *L)
{
	FILE *file;
	Apontador PAux = L->primeiro;

	// abre arquivo / modo escrita
	file = fopen("funcionarios.dat", "wb");

	if (file == NULL) // nao consegue abrir ou criar o arquivo
	{
		gotoxy(10, 23);
		printf("Erro ao abrir o arquivo!");
		return;
	}

	while (PAux != NULL)
	{
		// escreve conteudo no item atual
		fwrite(&PAux->conteudo, sizeof(reg_funcionarios), 1, file);
		PAux = PAux->proximo;
	}

	fclose(file);
}

// bubble sort
// ordena reg por codigo
void ordenaCodigo(Lista *L)
{
	// variaiveis
	Apontador P, R;
	int i, j, tam;
	reg_funcionarios PAux;

	// tamanho da lista
	tam = contaLista(L);

	P = L->primeiro;
	for (i = 0; i < tam - 1; i++) // vai ate o penultimo da lista
	{
		R = P->proximo;
		for (j = i + 1; j < tam; j++) // vai sempre ate o final da lista
		{
			if (R != NULL && P->conteudo.codigo > R->conteudo.codigo) // compara qual numero e maior
			{
				// faz um rodizio para troca sem perder o ponteiro
				PAux = P->conteudo;
				P->conteudo = R->conteudo;
				R->conteudo = PAux;
			}
			R = R->proximo; // R vai para o proximo
		}
		P = P->proximo; // P vai para o proximo
	}
}

// ordena reg por codigo
void ordenaNome(Lista *L)
{
	// variaiveis
	Apontador P, R;
	int i, j, tam;
	reg_funcionarios PAux;

	tam = contaLista(L); // tamanho da lista

	P = L->primeiro;

	for (i = 0; i < tam - 1; i++) // vai ate o penultimo da lista
	{
		R = P->proximo;
		for (j = i + 1; j < tam; j++) // vai sempre ate o final da lista
		{
			if (R != NULL && strcmp(P->conteudo.nome, R->conteudo.nome) > 0) // compara qual string vem antes
			{

				// faz um rodizio para troca sem perder o ponteiro
				PAux = P->conteudo;
				P->conteudo = R->conteudo;
				R->conteudo = PAux;
			}

			R = R->proximo; // R vai para o proximo
		}
		P = P->proximo; // P vai para o proximo
	}
}

int main()
{

	corTerminal();

	// variaveis
	int resp = -1;
	Lista L;

	inicializaLista(&L);

	leArquivo(&L);

	animacaoInicioFim(1);
	barraCarregamento();

	// loop do software
	do
	{

		// chamadas iniciais de telas
		telaMenu();

		gotoxy(7, 23);
		printf("Digite uma opcao: ");
		scanf("%d", &resp);

		limpaMsg();
		switch (resp)
		{

		case 1:
			resp = subMenu(1);
			limpaMsg();

			switch (resp)
			{
			case 1:
				moldura();

				CadFuncIniList(&L);
				break;

			case 2:
				moldura();

				CadFuncFinList(&L);
				break;

			case 3:

				moldura();

				gotoxy(23, 5);
				printf("Digite a posicao a ser colocado!\n");

				gotoxy(7, 6);
				printf("(Caso lista esteja vazia sera automaticamente a primeira posicao!)");

				// input posicao
				gotoxy(2, 23);
				printf("Digite a posicao: ");

				gotoxy(20, 23);
				scanf("%d", &resp);

				moldura();

				CadFuncMidList(&L, resp);
				break;

			case 4: // volta ao inicio
				break;

			default:
				gotoxy(24, 21);
				printf("Valor invalido, digite novamente!\n\n");
				pausa();
			}
			break;

		case 2:
			resp = subMenu(2);
			limpaMsg();

			switch (resp)
			{
			case 1:

				moldura();

				RemFuncIniList(&L);
				break;

			case 2:

				moldura();

				RemFuncFinList(&L);
				break;

			case 3:

				moldura();

				gotoxy(23, 5);
				printf("Digite a posicao a ser removido!\n");

				// input posicao
				gotoxy(2, 23);
				printf("Digite a posicao: ");

				gotoxy(20, 23);
				scanf("%d", &resp);

				RemFuncMidList(&L, resp);
				break;

			case 4: // volta ao inicio
				break;

			default:
				gotoxy(24, 21);
				printf("Valor invalido, digite novamente!\n\n");
				pausa();
			}

			break;

		case 3:

			moldura();

			gotoxy(23, 5);
			printf("Digite o CODIGO para alterar!\n");

			// input posicao
			gotoxy(2, 23);
			printf("Digite o CODIGO: ");

			gotoxy(20, 23);
			scanf("%d", &resp);

			AltFunc(&L, resp);
			break;

		case 4:

			resp = subMenu(3);
			limpaMsg();

			moldura();

			switch (resp)
			{
			case 1:

				gotoxy(23, 5);
				printf("Digite o CODIGO para consultar!\n");

				// input posicao
				gotoxy(2, 23);
				printf("Digite o CODIGO: ");

				gotoxy(20, 23);
				scanf("%d", &resp);

				Consulta(&L, resp);
				break;

			case 2:
				ConsultaListaCompleta(&L);
				break;

			case 3:
				ordenaCodigo(&L);
				ConsultaListaCompleta(&L);
				break;

			case 4:
				ordenaNome(&L);
				ConsultaListaCompleta(&L);
				break;

			case 5:
				break;

			default:
				gotoxy(24, 21);
				printf("Valor invalido, digite novamente!\n\n");
				pausa();
			}
			break;

		case 0:

			salvaArquivo(&L);

			animacaoInicioFim(2);
			barraCarregamento();
			return 0;

		default:
			gotoxy(24, 21);
			printf("Valor invalido, digite novamente!\n\n");
			pausa();
		}

	} while (resp != -1);

	return 0;
}
