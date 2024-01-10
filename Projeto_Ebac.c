#include <stdio.h>//bliioteca comunica��o com usu�rio
#include <stdlib.h>// aloca��o de espa�o em mem�ria
#include <locale.h>//aloca��o de texto por regi�o
#include <string.h>//respons�vel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//Respons�vel por copiar valores das strings
	
	FILE * file;// cria o aqruivo
	file = fopen(arquivo, "w");
	fprintf(file,cpf);// salva valor da vari�vel
	fclose(file);// fecha arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE * file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("Arquivo n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");	

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o cadastrado! \n");
		system("pause");
	}
		
}

int main()
{
	int opcao=0;//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
			setlocale(LC_ALL,"Portuguese");//Definindo idioma
			
				printf("###Cart�rio da EBAC###\n\n");
				printf("Escolha a op��o desejada do menu:\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n\n");
				printf("Op��o:");//fim do menu
	
	scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
		registro();
		system("pause");
		break;
		
		case 2:
		consulta();
		system("pause");
		break;
		
		case 3:
		deletar();
		system("pause");
		break;
				
		default:
		printf("Op��o n�o dispon�vel\n");
		system("pause");
		break;
		
	}
	
	
	
	
}
}
