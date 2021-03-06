/*Bibliotecas Importadas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

/*Definindo os Tipos de Registros*/
typedef struct {
	int Indice;
    char codigo[4];
    char nome[100];
    float Preco;
    char TipoRemedio;
    char CRM[25];
}EstruturaRemedio;

/*Declarando os Registros Globais*/
//EstruturaRemedio Cadastrar;
EstruturaRemedio Ler;
EstruturaRemedio Excluir;
	
//--Regi�o dos Met�dos Auxiliares--//
/*M�todo que imprime Todos os Registros*/
void ImprimeTodosRegistros(){
    FILE *Arquivo = fopen("arquivo", "ab+");
    int cont = 1;
    while(!(feof(Arquivo)))
    {   	
    	fread(&Ler, sizeof(EstruturaRemedio), 1, Arquivo);
    	if (!(feof(Arquivo))){
    		printf("Indice %d: \n", Ler.Indice);
        	printf("ITEM N� %d: \n", cont);
        	printf("C�DIGO: %s\n",Ler.codigo);
        	printf("NOME: %s\n",Ler.nome);
        	printf("PRE�O: R$ %.2f\n",Ler.Preco);
        	Ler.TipoRemedio=='S'?printf("Obrigat�rio Reter a Receita: Sim\nCRM do M�dico: %s\n\n",Ler.CRM):printf("Obrigat�rio Reter a Receita: N�o\n\n");
			//printf("\n\n",Ler.CRM);
			cont++;
		}
		else if (cont == 1){
			printf("Arquivo sem nenhum registro de medicamento!\n\n");
		}
    }
    fclose(Arquivo);
}

/*M�todo que Exclui Todos*/
ExcluirTodos(){
	FILE *Pont_Arq;
	Pont_Arq = fopen("arquivo", "wb+");
	printf("Registros Excluidos com Sucesso!\n\n");
	fclose(Pont_Arq);
}

/*M�todo que Exclui um registro*/
void ExcluiRegistro(int Tipo, char Pesquisa[]){
	FILE *Arquivo = fopen("arquivo", "ab+");
	int QTD = ftell (Arquivo);
	QTD = QTD / 140;
	EstruturaRemedio NovoArquivo[QTD];
	
	int cont = 0;
	
    while(!(feof(Arquivo)))
    {   	
    	fread(&Ler, sizeof(EstruturaRemedio), 1, Arquivo);
    	if (!(feof(Arquivo))){
    		printf("Indice %d: \n", Ler.Indice);
        	printf("ITEM N� %d: \n", cont);
        	printf("C�DIGO: %s\n",Ler.codigo);
        	printf("NOME: %s\n",Ler.nome);
        	printf("PRE�O: R$ %.2f\n",Ler.Preco);
        	Ler.TipoRemedio=='S'?printf("Obrigat�rio Reter a Receita: Sim\nCRM do M�dico: %s\n\n",Ler.CRM):printf("Obrigat�rio Reter a Receita: N�o\n\n");
			//printf("\n\n",Ler.CRM);
			cont++;
		}
		else if (cont == 1){
			printf("Arquivo sem nenhum registro de medicamento!\n\n");
		}
    }
    fclose(Arquivo);
	*/
	switch(Tipo){
		case 1:
			Ler.codigo !=  Pesquisa ? NovoArquivo[cont] = Ler : printf("");
			break;
		case 2:
			Ler.nome !=  Pesquisa ? NovoArquivo[cont] = Ler : printf("");
			break;
	}
}

/*M�todo Principal*/
int main()
{
	system("chcp 1252 > nul");
    FILE *Pont_Arq;

    Pont_Arq = fopen("arquivo", "ab+");
    if (Pont_Arq == NULL){
		//printf("ERRO! O arquivo n�o foi aberto!\n");
    }
    else {
		//printf("O arquivo foi aberto com sucesso!");
    }
	fclose(Pont_Arq);
	
    //Menu
	int Selecao;
    do{
        Selecao = 0;
        //Exibindo o menu
        printf("Sistema de Gerenciamento de F�rmacias:\n");
        printf("Digite o cdigo referente a opera��o que deseja executar:\n");
        printf("1 - Cadastrar Novo Medicamento\n");
        printf("2 - Excluir um Medicamento\n");
        printf("3 - Editar um Medicamento\n");
        printf("4 - Consultar um Medicamento\n");
        printf("5 - Imprimir as Informa��es de um Medicamento\n");
        printf("0 - Sair do Sistema\n");

        //Lendo a opera��o
        scanf("%d",&Selecao);

        //Executando a opera��o
        switch(Selecao){
            case 1 :
    			//Abre o Arquivo
            	Pont_Arq = fopen("arquivo", "ab+");
            	
            	system ("cls");
            	EstruturaRemedio Cadastrar;
				fread(&Ler, sizeof(EstruturaRemedio), 2, Pont_Arq);
				
				if(Ler.Indice == 0){
					Cadastrar.Indice = 1;
					
				}
				else{
					Cadastrar.Indice = Ler.Indice+1;
				}
		       	printf("Cadastrar Registros de Medicamentos\n");
            	
            	//Solicita as Informa��es para Cadastrar
                printf("Digite o C�digo do Novo Medicamento:\n");
                scanf("%s", Cadastrar.codigo);
				//Cadastrar.codigo = toupper(Cadastrar.codigo); 
				
                printf("Digite o Nome do Novo Medicamento:\n");
                scanf("%s", Cadastrar.nome);
				//Cadastrar.nome = toupper(Cadastrar.nome); 
				
                printf("Digite o Pre�o do Novo Medicamento:\n");
                scanf("%f", &Cadastrar.Preco);

                printf("Necessita a Reten��o da Receita?\nS - Sim \nN - N�o\n");
                scanf("%s", &Cadastrar.TipoRemedio);
                Cadastrar.TipoRemedio = toupper(Cadastrar.TipoRemedio); 

                if(Cadastrar.TipoRemedio == 'S'){
                    printf("Digite o CRM do M�dico que receitou:\n");
                    scanf("%s",Cadastrar.CRM);
                    //Cadastrar.CRM = toupper(Cadastrar.CRM); 
                }
                
                if(Cadastrar.TipoRemedio != 0){
                	fwrite(&Cadastrar, sizeof(EstruturaRemedio), 1, Pont_Arq);
				}

                fclose(Pont_Arq);

                break;

            case 2:
            	system ("cls");
				int Op=0;
				char confirma ='N';
				printf("Excluir Registros de Medicamentos\n");
				printf("1 - Excluir todos os Registros.\n");
				printf("2 - Excluir Registros por C�digo.\n");
				printf("3 - Excluir Registros por Nome.\n");
				scanf("%d",&Op);
				switch(Op){
					case 1 :
						printf("Aten��o, tal opera��o excluira os seguintes registros:\n");
						ImprimeTodosRegistros();
						printf("Confirma excluir todos?\n");
						printf("S - Sim\n");
						printf("N - N�o\n");
						scanf("%s",&confirma);
						confirma=='S'?ExcluirTodos():printf("Opera��o Cancelada!\n\n");				
						break;
					case 2 :			
						break;			
					case 3:
						break;
					default:
						printf("C�digo digitado � invalido, favor refazer a opera��o!\n\n");
	}
                break;
            case 3:
                printf("%d\n",Selecao);

                
                break;
            case 4:
                printf("%d\n",Selecao);
                break;
            case 5:
            	system ("cls");
                ImprimeTodosRegistros();
                break;
}

}
while(Selecao!=0);
    system("pause");
    return 0;
}
