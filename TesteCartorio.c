#include <stdio.h> //bliblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuarios no sistema
{
		//inicio criação de variaveis/string
		char arquivo[40];
		char cpf[40];
		char nome [40];
		char sobrenome[40];
		char cargo[40];
		//final criação de variaveis/string
		
		printf("Digite o CPF a ser cadastrado:"); //coletando informações do usuario 
		scanf("%s", cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //responsável por copiar os valores das string
		
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

int consulta() //Função responsavel por consultar no sistema
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
			printf("Não foi possivel abrir o arquivo, não localizado!\n");
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

int deletar() //Função responsavel por deletar do sistema
{
		char cpf[40];
		
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usuário foi deletado no sistema!. \n");
			system("pause");
		}
		
		if(file != NULL)
		{
			printf("Usuário nao se encontra no sistema!");
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
	
		printf("     Cartório da EBAC    \n\n"); // inicio do menu
		printf("Escolha a opção desejada do menu:\n\n"); 
		printf("\t1 - Resgistrar nomes\n"); 
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf(" Opção:");// final do menu
	
		scanf("%d", &opcao);// armazenando as informações 
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao)// inicio da seleção
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
			printf("Essa opção não esta disponivel!\n");
			system("pause");
			break;
				
		}// fim da seleção 
	
    
    	}
}
