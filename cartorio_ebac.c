#include <stdio.h> //biblioteca de Comunicação de usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das strings


int registro()//Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");// coleta informação do usuário
	scanf("%s", cpf);//salva as informação do usuario/ %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo,"w");//abre o arquiso e "W" escreve informações nele
	fprintf(file, "CPF: ");//pede infomação do usuário a ser registrada
	fprintf(file,cpf);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",\nNOME: ");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");//pede a informação ao usuário
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");//atualiza a informação dada pelo usuário
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");//abre o arquivo e "a" atualiza com novas informações
	fprintf(file,",\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");//pede a informação ao usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");//atualiza a informção dada pelo usuario
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",\nCARGO: ");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");//Pede a informação ao usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//atualiza a informação dada pelo usuário
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
    
    printf("Digite o CPF a ser consultado: ");//Pede a infomação ao usuário
    scanf("%s", cpf);//scaneia o arquivo já cadastrado
    
    FILE *file;
    file = fopen(cpf, "r");//abre o arquivo e lê o que ta escrito nele
    
    if(file == NULL)//variavel caso não haja o arquivo no sistema
    {
    	printf("Arquivo não localizado!.\n ");
    	
	}
	
	printf("\nEssas são as informações do usuário:\n\n ");//informa os dados do usuário no sistema
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	
		printf("%s", conteudo);// mostra o resultado da busca ao usuário
		
	}
	fclose(file);//fecha o arquivo
	system("pause");//pausa o sistema


}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");//define o idioma para portugues
	
	char cpf[40];//cria uma variável
	
	printf("Digite o usuário a ser deletado: \n");//Solicita o CPF a ser digitado
	scanf("%s",cpf);
	
	FILE *file;//cria o arquivo
	file =fopen(cpf,"r");//abre o aquivo e lê as informações
	fclose(file);
	
	if(file == NULL)//variavel caso o arquivo não exista
	{
		printf("O CPF do usuário não se encontra no sistema: \n");//Informa o usuário caso não exista o mesmo
		system("pause");
	}
	
	else
	{
		if(remove(cpf)== 0)//Remove o CPF do usuário
		{
			printf("\n\nCPF de usuário deletado com éxito!\n\n");//Informa que o CPF foi deletado com Éxito
			system("pause");
		}
	}
	
	
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;//definindo variáveis
	char senhadigitada[]= "a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador !\n\nDigite a senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");

	if (comparacao == 0)
	{
		
	    system("cls");
	
           for(laco=1;laco=1;)//cria a repetição do menu pro usuário
	       {
	
	            system("cls");
	
	            setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	            printf("### Cartório da EBAC ###\n\n"); //Ínicio do Menu
	            printf("Escolha a opção desejada do menu:\n\n");
                printf("\t1 - Registrar nomes\n");
                printf("\t2 - Consultar nomes\n");
	            printf("\t3 - Deletar nomes\n\n");
	            printf("\t4 - Sair do sistema\n\n");
	            printf("Opção:");//Fim do menu
	
	            scanf("%d", &opcao);//Armazenando a escolha do usuário
	
	            system("cls");//resposanvel por limpar a tela
	  
	             switch(opcao)//inicio da seleção do menu
	             {
	  	        case 1:
	  	        registro();//chamada de funções
		        break;
		
		        case 2:	
	        	consulta();//chamada de funções
		        break;
		
		        case 3: 
	  	        deletar();//chamada de funções
		        break;
		
		        case 4:
		        printf("Obrigado por usar nosso sistema!");
		        return 0;
		        break;
		
		        default: 
		        printf("Essa opção não está disponível!\n");//mostra ao usuário as informações
		        system("pause");
		        break;
		    }//fim da seleção  
	    }
    } 
    
     else
         system("cls");
         printf("Senha Incorreta!\n\n");
     	    
}
