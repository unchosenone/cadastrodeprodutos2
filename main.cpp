#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAX_REGISTROS 10


int comando=0,i=0, posicao=0,escolha=1;
struct RegProdutos{  //O registro dos produtos é inicializado neste conjunto de linhas.
 char cod_produto[30];
 char nome_produto[30];
 float valor_custo;
 float valor_venda;
 int quant_estoque;
};


RegProdutos produtos[MAX_REGISTROS];
int flag_registro[MAX_REGISTROS]; //Utilizado para identificar se há um produto ou não, na posição de memória correspondente do registro. 




//funçoes

//inicio do programa
void inicializacao(){
 
 for(i=0;i<MAX_REGISTROS;i++) strcpy(produtos[i].nome_produto,"<vazio>"); 
 //Inicializa os nomes do registro como vazio cada um, para representar um espaço disponivel para cadastro de prduto.
 for(i=0;i<MAX_REGISTROS;i++) flag_registro[i]=0; 
 //Inicializa o vetor de flags de registro como 0. Admite-se neste caso que 0 representa sem registro, e 1 representa produto registrado.
 
}










//imprime o menu principal do programa
void tela_principal(){
 printf("---------Programa registro----------\n\n");
 printf("---------REGISTRO DE PRODUTOS --- BEM VINDO -----------------------\n\n");
 printf("-------------------------------------------------------------------\n\n");
 
 printf("PODEM SER ARMAZENADOS  %d.\n\n",MAX_REGISTROS);
 printf("-----------------MENU----------------\n");
 printf("-------------------------------------\n");
 printf("-------------------------------------\n");

 
 printf("1---Incluir Um Novo Produto\n2---Alterar um Produto \n3---Excluir um Produto\n4---Imprimir Os Produtoss\n5---Sair do Programa- TCHAU!\n\n");
 printf("Bem Vindo! Para comecar escolha uma das opcoes acima:");
}













//Procedimento para imprimir lista de registros. Esta que mostra as posições que possuem produtos já registrados e tambem os espaços vazios.
void mostra_produtos(){
 for(i=0;i<MAX_REGISTROS;i++) printf("%d- %s\n",i,produtos[i].nome_produto);
}











//Função que verifica se a posição de memória de produtos informada é válida.
//OBS: Aqui está sendo considerado o valor de resultado como 1=POSIÇÃO VÁLIDA e 0=POSIÇÃO INVÁLIDA.
int verificacao_posicao(int posicao){
 int resultado;
 if(posicao<0 || posicao>MAX_REGISTROS-1){
  resultado=0;  
  return resultado;
 }
 else{
  resultado=1;
  return resultado;
 }          
}








//incluir um produto
int incluir_produto(int comando){
 printf("A OPCAO SELECIONADA FOI: INCLUIR\n");
   mostra_produtos();
   printf("Em qual posicao voce deseja inserir o novo produto?( as posicoes disponiveis sao: 0 - %d)",MAX_REGISTROS-1);
   scanf("%d",&posicao);
   if(verificacao_posicao(posicao)==0){
    printf("A Posicao e invalida. Pressione qualquer tecla para voltar ao menu.");
    getch();
   }
   else{
    fflush(stdin);
    printf("DIGITE OS DADOS DO NOVO PRODUTO.\nCodigo do produto = ");
    gets(produtos[posicao].cod_produto);
    printf("Nome do produto = ");
    gets(produtos[posicao].nome_produto);
    printf("Valor de custo(em reais) = ");
    scanf("%f",&produtos[posicao].valor_custo);
    printf("Valor de venda(em reais) = ");
    scanf("%f",&produtos[posicao].valor_venda);
    printf("Quantidade em estoque = ");
    scanf("%d",&produtos[posicao].quant_estoque);
    flag_registro[posicao]=1;
    printf("\n PARABENS SEU REGISTRO FOI FEITO COM SUCESSO!!!\nAperte qualquer tecla para voltar ao menu.");
    getch();
   }
}









//Função para alterar um produto
int alterar_produto(int comando){
 printf("A OPCAO SELECIONADA FOI: ALTERAR UM PRODUTO\n");
  mostra_produtos();
  printf("Qual dos produtos sera alterado?");
  scanf("%d",&posicao);
  fflush(stdin);
  if(verificacao_posicao(posicao)==0){
    printf("A Posicao e invalida. Pressione qualquer tecla para voltar ao menu.");
    getch();
  }
  else if(flag_registro[posicao]==0){
    printf("OPS! OCORREU UM ERRO. Posicao esta vazia. Aperte qualquer tecla para voltar ao menu.");
    getch();
   }
   else{
    printf("1.Codigo do  produto = %s\n",produtos[posicao].cod_produto);
    printf("2.Nome do produto = %s\n",produtos[posicao].nome_produto);
    printf("3.Valor de custo = %.2f\n",produtos[posicao].valor_custo);
    printf("4.Valor de venda = %.2f\n",produtos[posicao].valor_venda);
    printf("5.Quantidade em estoque = %d\n",produtos[posicao].quant_estoque);
    printf("ESCOLHA A OPCAO DO QUE SERA ALTERADO:");
    scanf("%d",&escolha);
    if(escolha<1 || escolha>5){
     printf("OPS! OCORREU UM ERRO. Aperte qualquer tecla para voltar ao menu.");
     getch();
    }
    else{
     fflush(stdin);
     switch(escolha){
      case 1: printf("NOVO CODIGO DO PRODUTO = ");
        gets(produtos[posicao].cod_produto);
        fflush(stdin);
        printf("\nA ALTERACAO FOI FEITA COM SUCESSO!!! .Pressione qualquer tecla para voltar ao menu.");
        getch();
        break;
      case 2: printf("NOVO NOME DO PRODUTO = ");
        gets(produtos[posicao].nome_produto);
        fflush(stdin);
        printf("\nA ALTERACAO FOI FEITA COM SUCESSO!!! .Pressione qualquer tecla para voltar ao menu.");
        getch();
        break;
      case 3: printf("NOVO VALOR DE CUSTO = ");
        scanf("%f",&produtos[posicao].valor_custo);
        printf("\nA ALTERACAO FOI FEITA COM SUCESSO!!! .Pressione qualquer tecla para voltar ao menu.");
        getch();
        break;
      case 4: printf("NOVO VALOR DE VENDA = ");
        scanf("%f",&produtos[posicao].valor_venda);
        printf("\nA ALTERACAO FOI FEITA COM SUCESSO!!! .Pressione qualquer tecla para voltar ao menu.");
        getch();
        break;
      case 5: printf("NOVA QUANTIDADE DE ESTOQUE = ");
        scanf("%d",&produtos[posicao].quant_estoque);
        printf("\nA ALTERACAO FOI FEITA COM SUCESSO!!! .Pressione qualquer tecla para voltar ao menu.");
        getch();
        break;
      default: break;
     }
    }
   }
}













//excluir um produto
int excluir_produto(int comando){
 printf("A OPCAO SELECIONADA FOI: EXCLUIR UM REGISTRO\n");
  mostra_produtos();
  printf("Qual registro sera excluido?");
  scanf("%d",&posicao);
  if(posicao<0 || posicao>MAX_REGISTROS-1){
   printf("A Posicao e invalida. Pressione qualquer tecla para voltar ao menu.");
   getch();
  }
  else if(flag_registro[posicao]==0){
   printf("A Posicao esta vazia. Pressione qualquer tecla para voltar ao menu.");
   getch();
  }
  else{
   printf("VOCE TEM CERTEZA DISSO?(1==SIM 2==NAO)");
   scanf("%d",&escolha);
   if(escolha<1 || escolha>2){
    printf("OPS! Ocorreu um Erro. Pressione qualquer tecla para voltar ao menu.");
    getch();
   }
   else if(escolha==2){
    printf("A Operacao foi cancelada. Pressione qualquer tecla para voltar ao menu.");
    getch();
    }
    else {
     strcpy(produtos[posicao].cod_produto,"0");
     strcpy(produtos[posicao].nome_produto,"<campo vazio>");
     produtos[posicao].valor_custo=0;
     produtos[posicao].valor_venda=0;
     produtos[posicao].quant_estoque=0;
     flag_registro[posicao]=0;
     printf("A EXCLUSAO FOI FEITA COM SUCESSO!!! .Pressione qualquer tecla para voltar ao menu.");
     getch();
    }
  }
}









//Função para mostrat na tela os dados do produto
int imprimir_produto(int comando){
  printf("A OPCAO SELECIONADA FOI: IMPRIMIR OS REGISTROS\n");
  mostra_produtos();
  printf("Qual registro voce deseja imprimir?");
  scanf("%d",&posicao);
  if(posicao<0 || posicao>MAX_REGISTROS-1){
   printf("A Posicao e invalida. Pressione qualquer tecla para voltar ao menu.");
   getch();
  }
  else if(flag_registro[posicao]==0){
   printf("A Posicao esta vazia. Pressione qualquer tecla para voltar ao menu.");
   getch();
  }
   else{
    printf("-------DADOS DO PRODUTO-------");
    printf("\n\n1.Codigo do produto = %s\n",produtos[posicao].cod_produto);
    printf("2.Nome do produto = %s\n",produtos[posicao].nome_produto);
    printf("3.Valor de custo = %.2f\n",produtos[posicao].valor_custo);
    printf("4.Valor de venda = %.2f\n",produtos[posicao].valor_venda);
    printf("5.Quantidade em estoque = %d\n\n\n",produtos[posicao].quant_estoque);
    printf("A OPERACAO FOI FEITA COM SUCESSO!!!. Pressione qualquer tecla para voltar ao menu.");
    getch();
   }
}








//MAIN ROUTINE:
int main(){
 inicializacao();
 while(1){
  tela_principal();
  scanf("%d",&comando); //Lê a opção selecionada pelo usúario.
  if(comando==1){
   incluir_produto(comando);
  }
  if(comando==2){
   alterar_produto(comando);
  }
  if(comando==3){
   excluir_produto(comando);
  }
  if(comando==4){
   imprimir_produto(comando);
  }
  if(comando==5) break;
  system("cls");
  fflush(stdin);
 }
 printf("\n\n  ADEUS ---------- VOLTE SEMPRE --------- O PROGRAMA FOI TERMINADO -------");
 printf("\n\n  ------------------------- UNISOFTWARE-----------------------------------");
 

}
