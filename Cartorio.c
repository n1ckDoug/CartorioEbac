#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

// Começo outras funções
int registro() // Função responsável por cadastrar os usuários no sistema
{
	// Variável para receber textos
	// cpf[40] -> é uma string com 40 caracters
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    // Começo CPF
    printf("Digite o CPF a ser cadastrado: "); // Coleta informação do usuário
    scanf("%s", cpf); // Vai salvar o valor enviado dentro de uma string
    
    // Copiando valor da variável cpf e colocando na variável arquivo
    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
    
    // Criando o arquivo
    FILE *file; // Acessa o FILE e cria o file
    file = fopen(arquivo, "w"); // Abre o arquivo(nomeDoArquivo, "arquivo novo")
    
    // Armazenar dentro do arquivo
    fprintf (file,cpf); // Salva o valor da variável
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Abre o arquivo(nomeDoArquivo, "atualizar arquivo")
    fprintf(file," - "); // Separando
    fclose(file);
    // Fim CPF
    
    // Começo NOME
    printf("Digite o NOME a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file," - ");
    fclose(file);
    // Fim NOME
    
    // Começo SOBRENOME
    printf("Digite o SOBRENOME a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file," - ");
    fclose(file);
    // Fim SOBRENOME
    
    // Começo CARGO
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
	setlocale(LC_ALL, "Portuguese"); // Falando para o computador que estamos falando em português ( vai colocar os acentos e o Ç ).
	
    char cpf[40];
    char conteudo[200]; // Onde vai armazenar o conteúdo
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); // abra o arquivo(nome do arquivo, "leia o arquivo")
    
    if(file == NULL)
    {
    	printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	// Enquanto tiver conteúdo dentro desse arquivo, vai armazenando dentro de conteudo
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	// Fim
	
    
}

int deletar()
{
    char cpf[40]; // Variável/string CPF
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // Função para deletar
	
	FILE *file;
	file = fopen(cpf,"r"); // abra o arquivo(nome do arquivo, "leia o arquivo")
	
	// Começo da validação se não econtrar o arquivo
	if(file == NULL)
	{
		printf("O usuário não se enconta no sistema!\n");
		system("pause");
	}
	// Fim da validação se não econtrar o arquivo
	   
}
// Fim outras funções


// Começo função principal
int main()
{
	int opcao = 0; // Criou a variável opcao.
	int laco = 1; // Criou a variável laco.
	
	// Começo laço de repetição
	for(laco = 1; laco = 1;) // Nesse caso sempre volta para o começo, pois o laco e a saída são iguais à 1.
	{	
	
		system("cls"); // Comando para limpar a tela.
	
		setlocale(LC_ALL, "Portuguese"); // Falando para o computador que estamos falando em português ( vai colocar os acentos e o Ç ).
		
		// Começo do menu
		printf("========================\n"); // \n Pula a linha.
		printf("### Cartório da EBAC ###\n");
		printf("========================\n");
		
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n"); // \t Da um espaço.
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
		// Fim do menu
		
		scanf("%d", &opcao); // O que o usuário digitar, vai armazenar na variável opcao.
		
		system("cls"); // (Limpa a tela)
		
		// Começo seleção
		switch(opcao)
		{
			case 1:
				registro(); // Chamando a função
			break;
			
			case 2:
				consulta(); // Chamando a função
			break;
			
			case 3:
				deletar(); // Chamando a função
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
			return 0; // Para sair do sistema
			break;
			
			default:
				printf("Essa opção não está disponível!\n");
				system("pause"); // Mostra a mensagem até o usuário não querer mais
			break;
				
		}
		// Fim seleção
	
	}
	// Fim do laço de repetição
}
// Fim da função principal
