
#include <iostream>
using namespace std;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
int posicaoElemento(int valor);
//--------------------------


const int MAX = 10;
//tamanho max
int lista[MAX]{};
//posições 0,1,2,3,4,5,6,7,8,9
int nElementos = 0;
//contagem dos itens


int main()
{
	menu();
}

void menu()
//controle do sistema
{
	int op = 0;
	//variável de opção do user

	while (op != 7) //enquanto a op digitada ser diferente de 7, repita o cod abaixo
	
	{
		system("cls"); // somente no windows

		cout << "Menu Lista Linear";
		cout << endl << endl; //pular linha
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op; //o programa espera o user digitar um n e apertar enter, esse n vai para OP

		switch (op) //ele olha o número que está em op e pula direto para o case correspondente

		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7: // executa o return que encerra a função menu e fecha o programa

			return;
		default:
			break;
		}

		system("pause"); // somente no windows: congela a tela com a mensagem "Pressione qualquer tecla para continuar..."
	}
}

void inicializar() //redefine a contagem de itens para 0.
{
	nElementos = 0;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	cout << "Quantidade de elementos: " << nElementos << endl;
	//mostra a quantidade de elementos

}

void exibirElementos() //serve para imprimir na tela todos os números que foram guardados até o momento.

{
	if (nElementos == 0) //verifica se nEle. é = 0
	{
		cout << " A lista esta vazia \n";
	}
	else //se tem pelo menos 1 n guardado
	{
		cout << "Elementos: \n";

		for (int n = 0; //cmc a leitura na pos 0
			n < nElementos; n++) //lê e soma 1 até o MAX de pos
		
		{
			cout << lista[n] << endl; //Mostra na tela o valor do número armazenado na posição n da lista.
		}
	}
}

void inserirElemento()
{
	int pos; //guarda o resultado da busca
	int valor; //guarda o valor digitado

	if (nElementos < MAX) //se a lista n tiver cheia
	
	{
		cout << "Digite o elemento: ";

		cin >> valor;

		pos = posicaoElemento(valor); //chama a função posicaoElemento enviando o número digitado para conferir se ele já existe na lista.

		if (pos != -1) //se pos for diferente de -1, significa que o número já está salvo em algum índice

		{
			cout << "Elemento já esta na lista" << endl;
		}

		else //caso seja um novo valor na lista

		{
			lista[nElementos] = valor; //guarda o valor na primeira pos livre do array

			nElementos++; //indica que a lista tem +1
		}

	}
	else {
		cout << "Lista cheia";
	}

}

void excluirElemento() //excluirElemento() implementada conforme especificação.

{
	//verificação, se a lista está vazia:
	if (nElementos == 0) {
		cout << "A lista esta vazia \n";
		return; //para a função para o programa n tentar apagar nada se n tiver nada na lista
	}

	int valor; //guarda o número que o user quer apagar

	cout << "Digite o numero que deseja apagar: \n";
	cin >> valor; //user digita

	int pos = posicaoElemento(valor); //chama a função posicaoElemento e passa o valor que foi digitado, e ela verifica o vetor.

	if (pos == -1) {
		cout << "elemento nao encontrado \n";
	}

	else {
		for (int i = pos; i < nElementos - 1; i++) {
			lista[i] = lista[i + 1];
		}
		nElementos--;
		cout << "Elemento excluido com sucesso \n";
	}


}

void buscarElemento()
{
	int valor; //cria a variável para armazenar o número desejado

	cout << "Digite o elemento que queira buscar: ";

	cin >> valor;

	int pos = posicaoElemento(valor); //chama a função de busca e armazena o índice retornado dentro de pos

	if (pos != -1) //se n encontrar o elemento na lista
	
	{
		cout << "O elemento foi encontrado na posicao" << pos << endl;
	}

	else //caso esse retorno estiver na lista

	{
		cout << "O elemento digitado nao foi encontrado" << endl;
	}
}

int posicaoElemento(int busca) //recebe um número no parâmetro busca e promete retornar um número inteiro no final

{
	int posicao = -1; //inicia a variável posicao com o valor -1 (sinal padrão para "não encontrado"

	for (int i = 0; i < nElementos; i++) //verificação dos dados válidos
	
	{
		if (busca == lista[i]) //o valor buscado é igual ao valor guardado na posição i da lista? Se for igual, atualiza
		
		{
			posicao = i; //atualiza
			break; // quando encontra o valor, para a execução e devolve o primeiro
		}
	}
	return posicao;
}