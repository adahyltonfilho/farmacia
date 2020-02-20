#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//------globbal------
typedef struct {
      int codigo;
      char nome[200];
      float Preco;
      char TipoRemedio;
      char CRM[200];
}EstruturaRemedio;

EstruturaRemedio Cadastrar;
EstruturaRemedio Ler;
//------globbal------



int main()
{
	setlocale(LC_ALL, "Portuguese");
    FILE *Pont_Arq;

    Pont_Arq = fopen("arquivo", "ab+");
    if (Pont_Arq == NULL){
    //printf("ERRO! O arquivo não foi aberto!\n");
    }
    else
    {
    //printf("O arquivo foi aberto com sucesso!");
    }

    //Menu
    int Selecao;
    do{
        Selecao = 0;
        //Exibindo o menu
        printf("Sistema de Gerenciamento de Fármacias:\n");
        printf("Digite o código referente a operação que deseja executar:\n");
        printf("1 - Cadastrar Novo Medicamento\n");
        printf("2 - Excluir um Medicamento\n");
        printf("3 - Editar um Medicamento\n");
        printf("4 - Consultar um Medicamento\n");
        printf("5 - Imprimir as Informações de um Medicamento\n");
        printf("0 - Sair do Sistema\n");

        //Lendo a operação
        scanf("%d",&Selecao);

        //Executando a operação
        switch(Selecao){
            case 1 :
                printf("Digite o Código do Novo Medicamento\n");
                scanf("%d", &Cadastrar.codigo);

                printf("Digite o Nome do Novo Medicamento\n");
                scanf("%s", Cadastrar.nome);

                printf("Digite o Preço do Novo Medicamento\n");
                scanf("%f", &Cadastrar.Preco);

                printf("Necessita a Retenção da Receita?\nS - Sim \nN - Não\n");
                scanf("%s", &Cadastrar.TipoRemedio);

                if(Cadastrar.TipoRemedio == 'S'){
                    printf("Digite o CRM do Médico que receitou:\n");
                    scanf("%s",Cadastrar.CRM);
                }
                fwrite(&Cadastrar, sizeof(EstruturaRemedio), 1, Pont_Arq);
                
                fclose(Pont_Arq);
                Pont_Arq = fopen("arquivo", "ab+");
                fread(&Ler, sizeof(EstruturaRemedio), 1, Pont_Arq);
                fseek(Pont_Arq,sizeof(EstruturaRemedio), 0);
                
                printf("Comeca Aqui\n");
                printf("%d\n",Ler.codigo);
                printf("%s\n",Ler.nome);
                printf("%f\n",Ler.Preco);
                printf("%c\n",Ler.TipoRemedio);
                printf("%s\n",Ler.CRM);
                fclose(Pont_Arq);
                break;

            case 2:
                printf("%d\n",Selecao);
                break;
            case 3:
                printf("%d\n",Selecao);
                break;
            case 4:
                printf("%d\n",Selecao);
                break;
            case 5:
                printf("%d\n",Selecao);
                //ImprimeTodos(Pont_Arq);
                break;
        }

    }while(Selecao!=0);
    system("pause");
    return 0;
}
