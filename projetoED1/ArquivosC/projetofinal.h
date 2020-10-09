#define MAX 15
typedef struct funcionario{ //criacao da estrutura de funcionarios que será preenchida pelo usuario
    int ID;
    char NOME[50];
    char ENDERECO[50];
    int IDADE;
    float SALARIO;
    long int CARGO;
}FUNCIONARIO;

typedef struct elemento* Lista;

Lista *criaLista();

int insere_inicio_ordenada(Lista *li,FUNCIONARIO func);

int listaVazia(Lista *li);

FUNCIONARIO ler_funcionario();

int consulta_lista_pos(Lista *li, int posicao);

int consulta_lista_mat(Lista *li, int id);

int remove_lista(Lista *li, int id);

void consulta_lista(Lista *li);

void consulta_lista_salario(Lista *li, float min, float max);

void apagaLista(Lista *li);

void menu();

/* metodos lista estatica*/

struct cargo{//criacao da estrutura de funcionarios que será preenchida pelo programa
    int id;
    long int codigo;
    char cargo[100];
};

typedef struct lista_s Lista_s;

Lista *cria_lista_s();

int insere_lista_final_s(Lista_s *li_s, struct cargo al);

int lista_cheia_s(Lista_s *li_s);

void consulta_lista_s(Lista_s *li_s);

long int menu_cargo();

long int consulta_codigo_cargo_s(Lista_s *li, int mat);

void libera_lista(Lista *li_s);
