#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct EstruturaRemedio{
      int codigo;
      char nome[200];
      float Preco;
      char TipoRemedio;
      char CRM[200];
};
struct EstruturaRemedio Cadastrar;
//------------------------global----------------------------------------

int main()
{
	setlocale(LC_ALL, "Portuguese");
    FILE *Pont_Arq;

    Pont_Arq = fopen("arquivo", "wb");
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
                
                printf("Necessita a Retenção da Receita?\n S - Sim \n N - Não\n");
                scanf("%c", &Cadastrar.TipoRemedio);
                
                if(Cadastrar.TipoRemedio == 'S'){
                    printf("Digite o Código do Novo Medicamento\n");
                    scanf("%s",Cadastrar.CRM);
                }
                
                printf("%d\n",Cadastrar.codigo);
                printf("%s\n",Cadastrar.nome);
                printf("%f\n",Cadastrar.Preco);
                printf("%c\n",Cadastrar.TipoRemedio);
                printf("%s\n",Cadastrar.CRM);
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
