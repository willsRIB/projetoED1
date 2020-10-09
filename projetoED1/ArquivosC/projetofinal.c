#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projetofinal.h"

//dados para contagem
struct elemento{
    FUNCIONARIO dados;
    struct elemento *prox;
};

Lista *cria_lista();
Lista *lista_s();

typedef struct elemento ELEM;

//Comando para criar funcionario
Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    };
    return li;
};

//comando para o usuário inserir os dados do funcionario
FUNCIONARIO ler_funcionario(){
    Lista *li_s;
    FUNCIONARIO func;
    int op,cod,x;
    char cargo;
    int menu_princ = 1;
    int menu_secun;

    printf("Digite o ID do Funcionario: ");
        scanf("%d",&func.ID);

            getchar();

    printf("Digite o nome do Funcionario: ");
            gets(func.NOME);

    printf("Digite o endereco do Funcionario: ");
            gets(func.ENDERECO);
    printf("Digite o idade do funcionario: ");
        scanf("%d",&func.IDADE);

    printf("Digite o salario do funcionario: ");
        scanf("%f",&func.SALARIO);

    func.CARGO = menu_cargo();

    return func;

};

//comando para reconhecer se há dados na lista
int listaVazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
};

//comando para inserir os funcionarios na lista criada
int insere_inicio_ordenada(Lista *li, FUNCIONARIO func){
    if(li == NULL){
        return 0;
    }

    ELEM *no = (ELEM*) malloc(sizeof(ELEM));

    if(no == NULL){
        return 0;
    }

    no->dados = func;

    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.ID < func.ID){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox =  ant->prox;
            ant->prox = no;
        }
        return 1;
    }
};

//comando para buscar o funcionario pelo ID
int consulta_lista_mat(Lista *li, int id){
    char cargo;
    if(li == NULL){
        printf("\nLista Vazia!");
        return 0;
        }
    ELEM *no = *li;
    while(no != NULL && no->dados.ID != id){
        no = no->prox;
    }
    if(no == NULL){
        printf("\Funcionario nao encontrada\n");
        return 0;
    }else{
        printf(" ID: %d\n",no->dados.ID);
        printf(" NOME: %s\n",no->dados.NOME);
        printf(" ENDERECO: %s\n",no->dados.ENDERECO);
        printf(" IDADE: %d\n",no->dados.IDADE);
        printf(" SALARIO: %.2f\n",no->dados.SALARIO);
        printf(" CARGO: %ld",no->dados.CARGO);
        printf("\n\n");
        return 1;
    }
};

//função para pesquisa de funcionário por faixa salárial
void consulta_lista_salario(Lista *li, float salariomin, float salariomax){
    if(li == NULL){
        printf("\nLista Vazia!");
                  }
    ELEM *no = *li;
    while(no != NULL){
        if(no->dados.SALARIO >= salariomin && no->dados.SALARIO <= salariomax){
            printf("\n ID: %d\n",no->dados.ID);
            printf(" NOME: %s\n",no->dados.NOME);
            printf(" ENDERECO: %s\n",no->dados.ENDERECO);
            printf(" IDADE: %d\n",no->dados.IDADE);
            printf(" SALARIO: %.2f\n",no->dados.SALARIO);
            printf(" CARGO: %ld",no->dados.CARGO);
            printf("\n\n");
        }
        no = no->prox;
                    }
};

//comando para exclusão de funcionario
int remove_lista(Lista *li, int id){
    if(li == NULL){
        printf("Funcionario nao encontrado\n");
        return 0;
    }

    ELEM *ant, *no = *li;

    while(no != NULL && no->dados.ID != id){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        printf("Funcionario nao encontrado\n");
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
};


//comando para exibir todos os funcionarios
void consulta_lista(Lista *li){
    if(li == NULL){
        printf("\nLista Vazia!");
    }
    ELEM *no = *li;
    while(no != NULL){
        printf(" ID: %d\n",no->dados.ID);
        printf(" NOME: %s\n",no->dados.NOME);
        printf(" ENDERECO: %s\n",no->dados.ENDERECO);
        printf(" IDADE: %d\n",no->dados.IDADE);
        printf(" SALARIO: %.2f\n",no->dados.SALARIO);
        printf(" CARGO: %ld",no->dados.CARGO);
        printf("\n\n");
        no = no->prox;
    }
};

//menu principal da aplicacao
void menu(){
    Lista *li;
    int x, op, posicao, id,salario,no;
    float salariomin,salariomax;
    int menu_princ = 1;
    int menu_secun;

    li = criaLista();
    printf("| Guilherme Estevam de Lima (GU3007863)     |     William Ribeiro da Silva (GU3008568) |\n\n");
    while(menu_princ = 1){

        printf("*********************************************\n\n");
        printf("|        *Digite de 1 a 6 para opcoes*      |");
        printf("\n| 1 - Adicionar Funcionarios                |");
        printf("\n| 2 - Buscar funcionarios por ID            |");
        printf("\n| 3 - Excluir Funcionarios por ID           |");
        printf("\n| 4 - Exibir Funcionarios                   |");
        printf("\n| 5 - Editar Funcionarios                   |");
        printf("\n| 6 - Exibicao Funcionarios por salario     |");
        printf("\n| 0 - Sair                                  |\n");
        printf("\n\n*********************************************\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d",&menu_secun);
        printf("\n*****************************\n\n");

        switch(menu_secun){

            case 0:
                printf("\nPrograma encerrado\n\n");
                exit(0);

            case 1:
                x = insere_inicio_ordenada(li, ler_funcionario(li)); //chamada da funcao para inserção
                if(x){ //teste da funcao
                    printf("\nFuncionario inserido com sucesso!\n\n");
                }else{
                    printf("\nFuncionario nao inserido\n\n!");
                };
                break;

            case 2:
                printf("Buscar funcionario por ID: \n");
                printf("ID:");
                scanf("%d", &id);
                printf("*****************************\n\n");
                x = consulta_lista_mat(li, id); //chamada da funcao para consulta de funcionarios cadastrados por ID
                break;

            case 3:
                printf("Remover funcionario por ID: \n");
                printf("ID: ");
                scanf("%d", &id);
                printf("*****************************\n");
                x = consulta_lista_mat(li, id); // chamada da funcao para consulta ao funcionario que será excluido
                printf("Deseja realmente excluir o funcionario? \n 1 - Sim\n 0 - Nao\n");
                printf("\nDigite opcao desejada:");
                scanf("%d", &x);
                if(x==1){
                    x = remove_lista(li, id); //chamada da funcao que exclui o funcionario
                }else{
                    printf("\nOperacao cancelada!\n");
                    break;
                };

                if(x){ //teste da funcao chamada anteriormente
                    printf("\nFuncionario removido com sucesso!\n");
                }else{
                    printf("\nNao foi possivel remover o funcionario!\n");
                }
                break;
            case 4:
                printf("\nExibir funcionarios\n");
                printf("\n");
                consulta_lista(li); //chamada da funcao que exibe todos os funcionarios
                printf("\n\n");
                break;
            case 5:
                printf("\nEditar funcionario por ID\n");
                printf("ID: ");
                scanf("%d", &id);
                printf("*****************************\n");
                x = consulta_lista_mat(li, id); //chamada da funcao para selecionar o funcionario que sera editado
                if(x==0){
                    printf("\nUsuario nao encontrado!");
                    break;
                }else{
                    printf("Deseja realmente editar o funcionario? \n 1 - Sim\n 0 - Nao\n");
                    printf("\nDigite opcao desejada:");
                    scanf("%d", &x);
                    if(x==1){
                        x = remove_lista(li, id); //chamada da funcao que exclui o funcionario para inserir os novos dados
                        x = insere_inicio_ordenada(li, ler_funcionario(li)); //chamada da funcao para insercao de novos dados
                        if(x){//teste da funcao chamada anteriormente
                            printf("\nEditado com sucesso!\n\n");
                        }else{
                            printf("\nNao foi possivel editar!\n\n");
                        }
                        break;
                    }else{
                        printf("\nEdicao cancelada!\n\n");
                        break;
                    }
                };
                break;
            case 6:
                printf("\nExibicao Funcionarios por salario\n");
                printf("Digite o salario minimo: ");
                    scanf("%f",&salariomin);
                printf("Digite o salario maximo: ");
                    scanf("%f",&salariomax);
                consulta_lista_salario(li, salariomin,salariomax);//chamada da funcao que faz a consulta por faixa salarial
                break;

            }
        }
    };

/////////////////////////////////////////////////////////////////////////////////
///////////////////////////metodos lista estatica////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

//estrutura de listagem
struct lista_s{
    int qtd;
    struct cargo dados[MAX];
};

//funcao para criacao da lista de cargos
Lista *cria_lista_s(){
    Lista_s *li_s;
    li_s = (Lista_s*) malloc(sizeof(struct lista_s));
    if(li_s != NULL){
        li_s->qtd = 0;
    };
    return li_s;
};

//funcao para finalizar a lista quando alcancar o maximo estipulado
int lista_cheia_s(Lista_s *li_s){
    if(li_s == NULL){
        return -1;
    }else{
        return(li_s->qtd == MAX);
    }
};

//funcao para inserir no final cada valor apresentado
int insere_lista_final_s(Lista_s *li_s, struct cargo al){
    if(li_s == NULL){
        return 0;
    }
    if(lista_cheia_s(li_s)){
        return 0;
    }
    li_s->dados[li_s->qtd] = al;
    li_s->qtd++;
    return 1;
};

//funcao que printa a lista de cargos
void consulta_lista_s(Lista_s *li_s){
    int i = 0;
    printf("*****************************\n");
    while(i < li_s->qtd){
        printf("%d - %s\n",li_s->dados[i].id,li_s->dados[i].cargo);
        i++;

    };
    printf("*****************************\n");
};

//funcao que recebe o codigo desejado da lista para retornar o codigo CBO para a lista cargo
long int consulta_codigo_cargo_s(Lista_s *li_s, int cod){
    int i = 0;
    while(i < li_s->qtd && li_s->dados[i].id != cod){
        i++;
    }
    if(li_s->dados[i].id == cod){
        return li_s->dados[i].codigo;
    }else{
        printf("\n Codigo nao encontrado! \n");
        return NULL;
        };

};

//funcao para liberar a lista gerada, evitando acumulo na memória
void libera_lista(Lista *li_s){
    free(li_s);
};

//funcao para elaboracao da lista de cargos
long int menu_cargo(){
    struct cargo cg1, cg2, cg3, cg4, cg5, cg6, cg7, cg8, cg9, cg10, cg11, cg12, cg13, cg14, cg15, dados_cargo;
    Lista *li_s;
    int x;

    cg1.id = 1;
    cg1.codigo = 862110;
    strcpy(cg1.cargo,"Maquinista de embarcacoes");

    cg2.id = 2;
    cg2.codigo = 862115;
    strcpy(cg2.cargo,"Operador de bateria de gas de hulha");

    cg3.id = 3;
    cg3.codigo = 862120;
    strcpy(cg3.cargo,"Operador de caldeira");

    cg4.id = 4;
    cg4.codigo = 862130;
    strcpy(cg4.cargo,"Operador de compressor de ar");

    cg5.id = 5;
    cg5.codigo = 862140;
    strcpy(cg5.cargo,"Operador de estação de bombeamento");

    cg6.id = 6;
    cg6.codigo = 862150;
    strcpy(cg6.cargo,"Operador de maquinas fixas, em geral");

    cg7.id = 7;
    cg7.codigo = 862155;
    strcpy(cg7.cargo,"Operador de utilidade (producao e distribuicao de vapor, gas, oleo, combustivel, energia, oxigenio)");

    cg8.id = 8;
    cg8.codigo = 862160;
    strcpy(cg8.cargo,"Operador de abastecimento de combustivel de aeronave");

    cg9.id = 9;
    cg9.codigo = 862205;
    strcpy(cg9.cargo,"Operador de estacao de captacao, tratamento e distribuicao de agua");

    cg10.id = 10;
    cg10.codigo = 862305;
    strcpy(cg10.cargo,"Operador de estacao de tratamento de agua e efluentes");

    cg11.id = 11;
    cg11.codigo = 862310;
    strcpy(cg11.cargo,"Operador de forno de incineracao no tratamento de agua, efluentes e residuos industriais");

    cg12.id = 12;
    cg12.codigo = 862405;
    strcpy(cg12.cargo,"Operador de instalacao de extracao, processamento, envasamento e distribuicao de gases");

    cg13.id = 13;
    cg13.codigo = 862505;
    strcpy(cg13.cargo,"Operador de instalacao de refrigeracao");

    cg14.id = 14;
    cg14.codigo = 862510;
    strcpy(cg14.cargo,"Operador de refrigeracao com amonia");

    cg15.id = 15;
    cg15.codigo = 862515;
    strcpy(cg15.cargo,"Operador de instalacao de ar-condicionado");

    li_s = cria_lista_s();

    insere_lista_final_s(li_s,cg1);
    insere_lista_final_s(li_s,cg2);
    insere_lista_final_s(li_s,cg3);
    insere_lista_final_s(li_s,cg4);
    insere_lista_final_s(li_s,cg5);
    insere_lista_final_s(li_s,cg6);
    insere_lista_final_s(li_s,cg7);
    insere_lista_final_s(li_s,cg8);
    insere_lista_final_s(li_s,cg9);
    insere_lista_final_s(li_s,cg10);
    insere_lista_final_s(li_s,cg11);
    insere_lista_final_s(li_s,cg12);
    insere_lista_final_s(li_s,cg13);
    insere_lista_final_s(li_s,cg14);
    insere_lista_final_s(li_s,cg15);

    consulta_lista_s(li_s);

    long int cod;

    printf("\nDigite o ID do cargo: ");
    scanf("%d",&cod);

    cod = consulta_codigo_cargo_s(li_s, cod);

    libera_lista(li_s);

    return cod;

};
