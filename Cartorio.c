#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

// Come�o outras fun��es
int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// Vari�vel para receber textos
	// cpf[40] -> � uma string com 40 caracters
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    // Come�o CPF
    printf("Digite o CPF a ser cadastrado: "); // Coleta informa��o do usu�rio
    scanf("%s", cpf); // Vai salvar o valor enviado dentro de uma string
    
    // Copiando valor da vari�vel cpf e colocando na vari�vel arquivo
    strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
    
    // Criando o arquivo
    FILE *file; // Acessa o FILE e cria o file
    file = fopen(arquivo, "w"); // Abre o arquivo(nomeDoArquivo, "arquivo novo")
    
    // Armazenar dentro do arquivo
    fprintf (file,cpf); // Salva o valor da vari�vel
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Abre o arquivo(nomeDoArquivo, "atualizar arquivo")
    fprintf(file," - "); // Separando
    fclose(file);
    // Fim CPF
    
    // Come�o NOME
    printf("Digite o NOME a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file," - ");
    fclose(file);
    // Fim NOME
    
    // Come�o SOBRENOME
    printf("Digite o SOBRENOME a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file," - ");
    fclose(file);
    // Fim SOBRENOME
    
    // Come�o CARGO
    printf("Digite o CARGO a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    system("pause");
    // Fime CARGO
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Falando para o computador que estamos falando em portugu�s ( vai colocar os acentos e o � ).
	
    char cpf[40];
    char conteudo[200]; // Onde vai armazenar o conte�do
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); // abra o arquivo(nome do arquivo, "leia o arquivo")
    
    if(file == NULL)
    {
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	// Enquanto tiver conte�do dentro desse arquivo, vai armazenando dentro de conteudo
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	// Fim
	
    
}

int deletar()
{
    char cpf[40]; // Vari�vel/string CPF
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // Fun��o para deletar
	
	FILE *file;
	file = fopen(cpf,"r"); // abra o arquivo(nome do arquivo, "leia o arquivo")
	
	// Come�o da valida��o se n�o econtrar o arquivo
	if(file == NULL)
	{
		printf("O usu�rio n�o se enconta no sistema!\n");
		system("pause");
	}
	// Fim da valida��o se n�o econtrar o arquivo
	   
}
// Fim outras fun��es


// Come�o fun��o principal
int main()
{
	int opcao = 0; // Criou a vari�vel opcao.
	int laco = 1; // Criou a vari�vel laco.
	
	// Come�o la�o de repeti��o
	for(laco = 1; laco = 1;) // Nesse caso sempre volta para o come�o, pois o laco e a sa�da s�o iguais � 1.
	{	
	
		system("cls"); // Comando para limpar a tela.
	
		setlocale(LC_ALL, "Portuguese"); // Falando para o computador que estamos falando em portugu�s ( vai colocar os acentos e o � ).
		
		// Come�o do menu
		printf("========================\n"); // \n Pula a linha.
		printf("### Cart�rio da EBAC ###\n");
		printf("========================\n");
		
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n"); // \t Da um espa�o.
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
		// Fim do menu
		
		scanf("%d", &opcao); // O que o usu�rio digitar, vai armazenar na vari�vel opcao.
		
		system("cls"); // (Limpa a tela)
		
		// Come�o sele��o
		switch(opcao)
		{
			case 1:
				registro(); // Chamando a fun��o
			break;
			
			case 2:
				consulta(); // Chamando a fun��o
			break;
			
			case 3:
				deletar(); // Chamando a fun��o
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
			return 0; // Para sair do sistema
			break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause"); // Mostra a mensagem at� o usu�rio n�o querer mais
			break;
				
		}
		// Fim sele��o
	
	}
	// Fim do la�o de repeti��o
}
// Fim da fun��o principal
