#include <stdio.h> //biblioteca de Comunica��o de usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings


int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");// coleta informa��o do usu�rio
	scanf("%s", cpf);//salva as informa��o do usuario/ %s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo,"w");//abre o arquiso e "W" escreve informa��es nele
	fprintf(file, "CPF: ");//pede infoma��o do usu�rio a ser registrada
	fprintf(file,cpf);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",\nNOME: ");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");//pede a informa��o ao usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");//atualiza a informa��o dada pelo usu�rio
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");//abre o arquivo e "a" atualiza com novas informa��es
	fprintf(file,",\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");//pede a informa��o ao usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");//atualiza a inform��o dada pelo usuario
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",\nCARGO: ");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");//Pede a informa��o ao usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//atualiza a informa��o dada pelo usu�rio
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",\n\n");
	fclose(file);
	
	system("pause");//Pausa o sitema 
	 
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");//Define a Linguagem
	
    char cpf[40];//cria uam variavel, char exemplo.
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");//Pede a infoma��o ao usu�rio
    scanf("%s", cpf);//scaneia o arquivo j� cadastrado
    
    FILE *file;
    file = fopen(cpf, "r");//abre o arquivo e l� o que ta escrito nele
    
    if(file == NULL)//variavel caso n�o haja o arquivo no sistema
    {
    	printf("Arquivo n�o localizado!.\n ");
    	
	}
	
	printf("\nEssas s�o as informa��es do usu�rio:\n\n ");//informa os dados do usu�rio no sistema
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	
		printf("%s", conteudo);// mostra o resultado da busca ao usu�rio
		
	}
	fclose(file);//fecha o arquivo
	system("pause");//pausa o sistema


}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");//define o idioma para portugues
	
	char cpf[40];//cria uma vari�vel
	
	printf("Digite o usu�rio a ser deletado: \n");//Solicita o CPF a ser digitado
	scanf("%s",cpf);
	
	FILE *file;//cria o arquivo
	file =fopen(cpf,"r");//abre o aquivo e l� as informa��es
	fclose(file);
	
	if(file == NULL)//variavel caso o arquivo n�o exista
	{
		printf("O CPF do usu�rio n�o se encontra no sistema: \n");//Informa o usu�rio caso n�o exista o mesmo
		system("pause");
	}
	
	else
	{
		if(remove(cpf)== 0)//Remove o CPF do usu�rio
		{
			printf("\n\nCPF de usu�rio deletado com �xito!\n\n");//Informa que o CPF foi deletado com �xito
			system("pause");
		}
	}
	
	
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;//definindo vari�veis
	char senhadigitada[]= "a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador !\n\nDigite a senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");

	if (comparacao == 0)
	{
		
	    system("cls");
	
           for(laco=1;laco=1;)//cria a repeti��o do menu pro usu�rio
	       {
	
	            system("cls");
	
	            setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	            printf("### Cart�rio da EBAC ###\n\n"); //�nicio do Menu
	            printf("Escolha a op��o desejada do menu:\n\n");
                printf("\t1 - Registrar nomes\n");
                printf("\t2 - Consultar nomes\n");
	            printf("\t3 - Deletar nomes\n\n");
	            printf("\t4 - Sair do sistema\n\n");
	            printf("Op��o:");//Fim do menu
	
	            scanf("%d", &opcao);//Armazenando a escolha do usu�rio
	
	            system("cls");//resposanvel por limpar a tela
	  
	             switch(opcao)//inicio da sele��o do menu
	             {
	  	        case 1:
	  	        registro();//chamada de fun��es
		        break;
		
		        case 2:	
	        	consulta();//chamada de fun��es
		        break;
		
		        case 3: 
	  	        deletar();//chamada de fun��es
		        break;
		
		        case 4:
		        printf("Obrigado por usar nosso sistema!");
		        return 0;
		        break;
		
		        default: 
		        printf("Essa op��o n�o est� dispon�vel!\n");//mostra ao usu�rio as informa��es
		        system("pause");
		        break;
		    }//fim da sele��o  
	    }
    } 
    
     else
         system("cls");
         printf("Senha Incorreta!\n\n");
     	    
}
