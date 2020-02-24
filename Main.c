#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Tipos de Registros*/
typedef struct {
      int codigo;
      char nome[200];
      float Preco;
      char TipoRemedio;
      char CRM[200];
}EstruturaRemedio;

/*Vari�veis Globais*/
EstruturaRemedio Cadastrar;
EstruturaRemedio Ler;
EstruturaRemedio Excluir;


/*M�todo que imprime Todos os Registros*/
void ImprimeTodosRegistros(){
    FILE *Arquivo = fopen("arquivo", "ab+");
    int cont = 0;
    system ("cls");
    while(!(feof(Arquivo)))
    {
        fread(&Ler, sizeof(EstruturaRemedio), 1, Arquivo);
        if (!(feof(Arquivo))){
        printf("ITEM N� %d: \n", cont);
        printf("CODIGO: %d\n",Ler.codigo);
        printf("NOME: %s\n",Ler.nome);
        printf("PRECO: R$ %.2f\n",Ler.Preco);
        printf("TRIBUTADO: %c\n",Ler.TipoRemedio);
        if(Ler.TipoRemedio == 'S'){
        	printf("%s\n",Ler.CRM);
		}
        cont++;
        }
    }
    fclose(Arquivo);
}

/*M�todo que Exclui Todos*/
void Mod_Exclusao()
{
	int codigo_local = 0;
	FILE *arq_local;
	FILE *arq_local_aux;
	arq_local = fopen("arquivo", "ab+");
	arq_local_aux = fopen("arquivo_aux", "ab+");
	int cont = 1;

	printf("Digite o Código do Medicamento Para Exclusão\n");
    scanf("%d", &codigo_local);

	while(!(feof(arq_local)))
	{
		fread(&Excluir, sizeof(EstruturaRemedio), 1, arq_local);
		if (!(feof(arq_local)) && Excluir.codigo != codigo_local)
		{
			fwrite(&Excluir, sizeof(EstruturaRemedio), 1, arq_local_aux);
		}
	}
	fclose(arq_local);
	fclose(arq_local_aux);


	arq_local_aux = fopen("arquivo_aux", "ab+");
	while(!(feof(arq_local_aux)))
	{
		fread(&Excluir, sizeof(EstruturaRemedio), 1, arq_local_aux);
		//fseek(Pont_Arq,cont, SEEK_CUR);
		if (!(feof(arq_local_aux))){
		printf("ITEM N %d: \n", cont);
		printf("CODIGO: %d\n",Excluir.codigo);
		printf("NOME: %s\n",Excluir.nome);
		printf("PRECO: R$ %.2f\n",Excluir.Preco);
		printf("TRIBUTADO: %c\n",Excluir.TipoRemedio);
		printf("%s\n",Excluir.CRM);
		cont++;
		}
	}
	fclose(arq_local_aux);

}


/*M�todo Principal*/
int main()
{
	setlocale(LC_ALL, "Portuguese");
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
            	
            	//Solicita as Informa��es para Cadastrar
                printf("Digite o C�digo do Novo Medicamento\n");
                scanf("%d", &Cadastrar.codigo);

                printf("Digite o Nome do Novo Medicamento\n");
                scanf("%s", Cadastrar.nome);

                printf("Digite o Preço do Novo Medicamento\n");
                scanf("%f", &Cadastrar.Preco);

                printf("Necessita a Retenção da Receita?\nS - Sim \nN - Não\n");
                scanf("%s", &Cadastrar.TipoRemedio);

                if(Cadastrar.TipoRemedio == 'S'){
                    printf("Digite o CRM do M�dico que receitou:\n");
                    scanf("%s",Cadastrar.CRM);
                }
                fwrite(&Cadastrar, sizeof(EstruturaRemedio), 2, Pont_Arq);
                fclose(Pont_Arq);

                break;

            case 2:
				Mod_Exclusao();
                printf("-------------\\-------------\\-------------\n\n");
                break;
            case 3:
                printf("%d\n",Selecao);
                break;
            case 4:
                printf("%d\n",Selecao);
                break;
            case 5:
                ImprimeTodosRegistros();
                break;
        }

    }while(Selecao!=0);
    system("pause");
    return 0;
}
