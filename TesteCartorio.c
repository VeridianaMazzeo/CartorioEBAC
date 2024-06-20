#include <stdio.h> //bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{
		//inicio cria��o de variaveis/string
		char arquivo[40];
		char cpf[40];
		char nome [40];
		char sobrenome[40];
		char cargo[40];
		//final cria��o de variaveis/string
		
		printf("Digite o CPF a ser cadastrado:"); //coletando informa��es do usuario 
		scanf("%s", cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
		
		FILE *file; //cria o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,"\n CPF:");
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, cpf); //salvo o valor da variavel
		fclose(file); //fecha o arquivo
			
		printf("Digite o nome a ser cadastrado:");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\n Nome:");
		fclose(file); 
		
		file = fopen (arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
		printf ("Digite o sobrenome a ser  cadastrado:");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\n Sobrenome:");
		fclose(file); 
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
			
		printf("Digite o cargo a ser cadastrado:");
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\n Cargo:");
		fclose(file); 
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
			
		system("pause");
}

int consulta() //Fun��o responsavel por consultar no sistema
{
		setlocale(LC_ALL, "Portuguese"); //selecionar a linguaguem
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado:");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\n");
			printf("%s", conteudo);
			
			
		}
		
		printf("\n");
		printf("\n");
		system("pause");
		fclose(file);
}

int deletar() //Fun��o responsavel por deletar do sistema
{
		char cpf[40];
		
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usu�rio foi deletado no sistema!. \n");
			system("pause");
		}
		
		if(file != NULL)
		{
			printf("Usu�rio nao se encontra no sistema!");
			system("pause");
		}
}


int main ()
{
	int opcao=0; //variavel inicial 
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //selecionar a linguaguem
	
		printf("     Cart�rio da EBAC    \n\n"); // inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n"); 
		printf("\t1 - Resgistrar nomes\n"); 
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf(" Op��o:");// final do menu
	
		scanf("%d", &opcao);// armazenando as informa��es 
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao)// inicio da sele��o
		{
			case 1: 
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o esta disponivel!\n");
			system("pause");
			break;
				
		}// fim da sele��o 
	
    
    	}
}
