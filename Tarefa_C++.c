/*NOME: LUCAS LENZ
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>

//ESTRUTURA
struct cliente
{
	char nome[81];
	float altura;
	float peso;

};
typedef struct cliente Cliente;

//FUNÇÕES
int countLines(char* fName);
Cliente** lerMontarVetor(char* fName, int numLinhas);
void imprimeVetor(Cliente** vpClientes, int n);
float mean(Cliente** vpClientes, int n);
float standardDeviation(Cliente** vpClientes, int n);
int comparaAltura(Cliente* b, float altura);
int buscaBin(int n, Cliente** vpClientes, float altura);
void freeMem(Cliente** vpCliente, int numLinhas);

/*************** PARTE 1 ***********************/

int countLines(char* fName) {    
	FILE* arq = fopen(fName, "r");
	int contador = 0;
	char c;
	int ehVazio = 1; // verificar se eh vazio

	if (arq == NULL) { //caso o arquivo não exista ou esteja vazio

		return 0;
	}

	
	while ((c = fgetc(arq)) != EOF) {
		
		if (c == '\n') {
			contador++;
			ehVazio = 0;
		}
	}
	
	fclose(arq);
	
	if (ehVazio) {
		return NULL; //se for vazio, retorna NULL
	}

	return contador + 1; //icluir a ultima linha
}


Cliente** lerMontarVetor(char* fName, int numLinhas) {
	if (numLinhas == NULL) {
		return NULL;
	}

	Cliente** vpClientes = (Cliente**)malloc(numLinhas * sizeof(Cliente*));
	if (vpClientes == NULL) {
		return NULL;
	}

	FILE* arq = fopen(fName, "r");
	if (arq == NULL) {
		return NULL;
	}

	int i = 0;
	while (!feof(arq) && i < numLinhas) {
		
		vpClientes[i] = (Cliente*)malloc(sizeof(Cliente));
		if (vpClientes[i] == NULL) {
			return NULL;
		}

		fscanf(arq, "%[^:]: ", &(vpClientes[i]->nome));
		
		fscanf(arq, "%f %f", &(vpClientes[i]->altura), &(vpClientes[i]->peso));
		
		i++;
	}
	fclose(arq);
	return vpClientes;
}


void imprimeVetor(Cliente** vpClientes, int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%-60s %.2f %.1f", vpClientes[i]->nome, vpClientes[i]->altura, vpClientes[i]->peso);
		}
	
}

//FUNÇÕES DE MÉDIA E DESVIO-PADRÃO DOS PESOS
float mean(Cliente** vpClientes, int n) {
	float soma = 0.0;
	int i;
	for (i = 0; i < n; i++) {
		soma += vpClientes[i]->peso;
	}

	return soma / n;
}

float standardDeviation(Cliente** vpClientes, int n) {
	float media = mean(vpClientes, n);
	float soma = 0.0;
	int i;

	for (i = 0; i < n; i++) {
		float diferenca = vpClientes[i]->peso - media;
		soma += diferenca * diferenca;
	}

	float variancia = soma / n;
	return sqrt(variancia);
}

/*************** PARTE 2 ***********************/

int comparaAltura(Cliente* b, float altura) {
	if (altura < b->altura) {
		return -1;
	}
	else if (altura > b->altura) {
		return 1;
	}
	else {
		return 0;
	}
}


int buscaBin(int n,Cliente** vpClientes, float altura) {

	int ini,meio, fim, r;
	ini = 0;
	fim = n - 1;


	while (ini <= fim) {
		
		meio = (ini + fim) / 2;
		
		r = comparaAltura(vpClientes[meio], altura);

		if (r < 0) {
			fim = meio - 1;
		}
		else if (r > 0) {
			ini = meio + 1;
		}
		else {
			while (meio < n && comparaAltura(vpClientes[meio], altura) == 0) {
				meio++;
			}
			return meio - 1;
		}
	}
	return -1; //altura nao encontrada
}

void freeMem(Cliente** vpCliente, int numLinhas) {

	int i;
	for (i = 0; i < numLinhas; i++) {
		free(vpCliente[i]);
	}

}


int main(void) {
	
	Cliente** vp;// vetor de ponteiros para clientes
	
	char* fileName = "Texto.txt";
	int numLinhas = countLines(fileName);

	vp = lerMontarVetor(fileName, numLinhas); //criando o vetor
	
	float media = mean(vp, numLinhas);
	float desvioPadrao = standardDeviation(vp, numLinhas);
	
	printf("Numero de linhas do arquivo: %d\n", numLinhas); //Achei melhor exibir para me ajudar na construção dos codigos
	printf("Clientes: \n");
	
	if (vp == NULL) {
		printf("Arquivo %s vazio!\n", fileName);
	}
	else {
		imprimeVetor(vp, numLinhas);
		printf("\nMedia do Peso: %.2f         Desvio Padrao do Peso: %.2f\n", media, desvioPadrao);
	}



	// TESTE PESSOA 01
	float alturaDesejada01 = 1.82;
	int indice01 = buscaBin(numLinhas, vp, alturaDesejada01);
	if (indice01 == -1) {
		printf("Nao ha pacientes com altura %.2f\n", alturaDesejada01);
	}
	else {
		printf("Registro de maior peso com altura %.2f: ", alturaDesejada01);
		printf("%s %.2f %.1f\n", vp[indice01]->nome, alturaDesejada01, vp[indice01]->peso);
	}

	//TESTE PESSOA 02
	float alturaDesejada02 = 2.10;
	int indice02 = buscaBin(numLinhas, vp, alturaDesejada02);
	if (indice02 == -1) {
		printf("Nao ha pacientes com altura %.2f\n", alturaDesejada02);
	}
	else {
		printf("Registro de maior peso com altura %.2f: ", alturaDesejada02);
		printf("%s %.2f %.1f\n", vp[indice02]->nome, alturaDesejada02, vp[indice02]->peso);
	}

	//TESTE PESSOA 03
	float alturaDesejada03 = 1.67;
	int indice03 = buscaBin(numLinhas, vp, alturaDesejada03);
	if (indice03 == -1) {
		printf("Nao ha pacientes com altura %.2f\n", alturaDesejada03);
	}
	else {
		printf("Registro de maior peso com altura %.2f: ", alturaDesejada03);
		printf("%s %.2f %.1f\n", vp[indice03]->nome, alturaDesejada03, vp[indice03]->peso);
	}
	freeMem(vp, numLinhas);
	return;
}

