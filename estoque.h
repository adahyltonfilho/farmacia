#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>


//typedef struct {
//    char codigo[4];
//    char nome[100];
//    float Preco;
//    char TipoRemedio;
//    char CRM[25];
//    int Quantidade;
//}Controle_Estoque;
//
//int Comprar(){}
//int Vender(){}
//
//void Historico_compra(){}
//
//void Historico_venda(){}


int Estoque (void)
{
	printf("Bem vindo ao modulo de estoque!\n");
	system("pause");
	system ("cls");	
	
	
	int Selecao;
    do
    {
		system ("cls");	
        Selecao = 0;
        //Exibindo o menu
        printf("Sistema de Gerenciamento de Farmacias:\n");
        printf("Digite o codigo referente a operacao que deseja executar:\n");
        printf("1 - Verificar Estoque Atual\n");
        printf("2 - Adicionar / comprar medicamentos\n");
        printf("3 - Vender / remover medicamentos\n");
        printf("4 - historico de compras\n");
        printf("5 - historico de vendas\n");
        printf("0 - Voltar ao Menu Inicial\n");

        //Lendo a operação
        scanf("%d",&Selecao);

        //Executando a operação
        switch(Selecao)
        {
            case 1 :
                break;

            case 2:
            	
                break;
            case 3:
                               
                break;
            case 4:
            
                break;
            case 5:
            
                break;
                
		}
	}while(Selecao!=0);
	system ("cls");	
	return 0;
}


