/* Projeto realizado por Vasco Correia Rodrigues nº100493 
para a cadeira de IAED do Instituto Superior Tecnico*/

/*Este programa funciona como um sistema de gestao de carreiras
de transporte publico
Como tal este programa permite a criacao e listagem de carreiras,
criacao e listagem de paragens e respetivas ligacoes,
e tambem teria a capacidade de listar todas as paragens
onde passam mais de uma carreira e quantas/quais passam,
sendo que esta ultima funcao nao ficou bem implementada*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAXNOME 21 /*Nome maximo que uma carreira pode ter*/
#define MAXPARAG 51 /*Nome maximo que uma paragem pode ter*/
#define MAXCARR 200 /*Numero maximo de carreiras*/
#define MAXTOTALPARAG 10000 /*Numero maximo de paragens*/
/*#define MAXLIG 30000 Acabou por nao ser utilizado*/
#define INDEX 3 /*Numero de indices para a funcao getIndex*/

/*Estruturas*/

/*Estrutura que define uma paragem*/
typedef struct
{
    char nome[MAXPARAG];
    double latitude;
    double longitude;
    int carreiras[MAXCARR];
    int nCarreiras;
} Paragem;

/*Estrutura que define uma carreira*/
typedef struct
{
    char nome[MAXNOME];
    char origem[MAXPARAG];
    char destino[MAXPARAG];
    int nParagens;
    int paragens[MAXTOTALPARAG];
    double custo;
    double duracao;
} Carreira;

/*Variaveis Globais*/
Carreira carreiras[MAXCARR]; /*Todas as carreiras existentes*/
Paragem paragens[MAXTOTALPARAG]; /*Todas as paragens existentes*/

int numCarreiras = 0; /* Numero total de carreiras existentes*/
int numParagens = 0;  /* Numero total de paragens existentes*/

/*Funcoes auxiliares*/

/*Imprime o nome, origem e destino (apenas se estes estiverem estabelecidos),
 numero de paragens, custo total e duracao total de uma carreira*/
void imprimirCarreira(Carreira c)
{
    if (strcmp(c.origem, "") == 0)
    {
        printf("%s %d %.2f %.2f\n", c.nome, c.nParagens, c.custo, c.duracao);
        return;
    }
    printf("%s %s %s %d %.2f %.2f\n", c.nome, c.origem, c.destino,
           c.nParagens, c.custo, c.duracao);
}

/*Imprime as paragens de uma carreira, */
void imprimirCarreiraParagens(Carreira c, int inverso)
{
    int i;
    if (inverso == 0)
    {
        for (i = 0; i < c.nParagens; i++)
        {
            printf("%s", paragens[c.paragens[i]].nome);
            if (i != (c.nParagens - 1))
            {
                printf(", ");
            }
        }
    }
    else
    {
        for (i = (c.nParagens - 1); i >= 0; i--)
        {
            printf("%s", paragens[c.paragens[i]].nome);
            if (i != 0)
            {
                printf(", ");
            }
        }
    }
    putchar('\n');
}

/*Imprime o nome, coordenadas e o numero de carreiras que passam numa paragem*/
void imprimirParagem(Paragem p)
{
    printf("%s: %16.12f %16.12f %d\n", p.nome, p.latitude,
           p.longitude, p.nCarreiras);
}

/*Imprime as coordenadas de uma paragem*/
void imprimirCoordenadas(Paragem p)
{
    printf("%16.12f %16.12f\n", p.latitude, p.longitude);
}

/*Obtem um indice para os argumentos dados*/
void getIndex(char *nome, char *parag1, char *parag2, int *index)
{
    int i, j, k;
    for (i = 0; i < numCarreiras; i++)
    {
        if (strcmp(nome, carreiras[i].nome) == 0)
        {
            break;
        }
        if (i == numCarreiras - 1)
        {
            i = -1;
            break;
        }
    }
    for (j = 0; j < numParagens; j++)
    {
        if (strcmp(parag1, paragens[j].nome) == 0)
        {
            break;
        }
        if (j == numParagens - 1)
        {
            j = -1;
            break;
        }
    }
    for (k = 0; k < numParagens; k++)
    {
        if (strcmp(parag2, paragens[k].nome) == 0)
        {
            break;
        }
        if (k == numParagens - 1)
        {
            k = -1;
            break;
        }
    }
    index[0] = i;
    index[1] = j;
    index[2] = k;
}

/*Funcionalidades base*/
/*A funcao c permite listar todas as carreiras 
se nao forem dados mais argumentos, adicionar uma carreira nao existente
quando dado um nome para tal ou listar todas as paragens de uma carreira
caso ela ja exista*/
void c()
{
    int i, j, k;
    char nome[MAXNOME];
    char inverso[BUFSIZ];

    if (getchar() == '\n')
    {
        for (i = 0; i < numCarreiras; i++)
        {
            /*imprime todas as carreriras*/
            imprimirCarreira(carreiras[i]);
        }
        return;
    }
    if (scanf("%s", nome) != 1)
    {
        return;
    }
    k = strlen(nome);
    for( j=0; j<k; j++){
        if (nome[j] < 'A' || nome[j] > 'Z'){
                printf("invalid line name.\n");
                return;            
        }
    }
    for (i = 0; i < numCarreiras; i++)
    {
        if (strcmp(nome, carreiras[i].nome) == 0)
        {
            if (getchar() == '\n')
            {
                /*imprime as paragens da carreira existente dada pelo input*/
                imprimirCarreiraParagens(carreiras[i], 0);
                return;
            }
            else
            {
                if (scanf("%s\n", inverso) != 1)
                {
                    return;
                }
                if (inverso[0] == 'i' && inverso[1] == 'n' && inverso[2] == 'v')
                {
                    if (strcmp(&inverso[3], "e") == 0 ||
                        strcmp(&inverso[3], "er") == 0 ||
                        strcmp(&inverso[3], "ers") == 0 ||
                        strcmp(&inverso[3], "erso") == 0)
                    {
                        imprimirCarreiraParagens(carreiras[i], 1);
                        return;
                    }
                }
                printf("incorrect sort option.\n");
                return;
            }
        }
    }
    /*adiciona uma carreira*/
    strcpy(carreiras[numCarreiras].nome, nome);
    carreiras[numCarreiras].nParagens = 0;
    carreiras[numCarreiras].custo = 0.0;
    carreiras[numCarreiras].duracao = 0.0;
    strcpy(carreiras[numCarreiras].origem, "");
    strcpy(carreiras[numCarreiras].destino, "");
    numCarreiras++;
}

/*A funcao p permite adicionar paragens se se der
um nome e coordenadas, listar todas as paragens 
em caso de nao serem dados argumentos e listar as coordenadas
quando dada uma paragem apenas como argumento*/
void p()
{
    int i;
    char input;
    char nome[MAXPARAG];
    double lat = 0.0;
    double longi = 0.0;
    if (getchar() == '\n')
    {
        for (i = 0; i < numParagens; i++)
        {
            if (strcmp(paragens[i].nome, "") != 0 &&
             strlen(paragens[i].nome) > 10)
            {
                imprimirParagem(paragens[i]);
            }
        }
    }
    else
    {
        i = 0;
        if ((input = getchar()) == '\"')
        { /*input com espacos*/
            while ((input = getchar()) != '\"')
            {
                nome[i] = input;
                i++;
            }
            nome[i] = '\0';
        }
        else
        { /*input sem espacos*/
            ungetc(input, stdin);
            if (scanf("%s", nome) != 1)
            {
                return;
            }
        }
        if (getchar() == '\n')
        {
            /*imprime carreira existente indicada pelo input*/
            for (i = 0; i < numParagens; i++)
            {
                if (strcmp(nome, paragens[i].nome) == 0)
                {
                    imprimirCoordenadas(paragens[i]);
                    return;
                }
            }
            printf("%s: no such stop.\n", nome);
            return;
        }
        if (scanf("%lf %lf\n", &lat, &longi) != 2)
        {
            return;
        }
        for (i = 0; i < numParagens; i++)
        {
            if (strcmp(nome, paragens[i].nome) == 0)
            {
                printf("%s: stop already exists.\n", nome);
                return;
            }
        }

        strcpy(paragens[numParagens].nome, nome);
        paragens[numParagens].latitude = lat;
        paragens[numParagens].longitude = longi;
        paragens[numParagens].nCarreiras = 0;
        numParagens++;
    }
}

/*A funcao l permite adicionar novas ligacoes, na forma
da extensao de uma carreira e adicionando custos e duracao*/
void l()
{
    int i, j;
    int index[INDEX];
    char input;
    char nome[MAXNOME];
    char parag1[MAXNOME];
    char parag2[MAXNOME];
    double custo;
    double duracao;
    if (scanf(" %s ", nome) != 1)
    {
        return;
    }
    i = 0;
    if ((input = getchar()) == '\"')
    { /*input com espacos*/
        while ((input = getchar()) != '\"')
        {
            parag1[i] = input;
            i++;
        }
        parag1[i] = '\0';
        getchar();
    }
    else
    { /*input sem espacos*/
        ungetc(input, stdin);
        if (scanf("%s ", parag1) != 1)
        {
            return;
        }
    }
    i = 0;
    if ((input = getchar()) == '\"')
    { /*input com espacos*/
        while ((input = getchar()) != '\"')
        {
            parag2[i] = input;
            i++;
        }
        parag2[i] = '\0';
        getchar();
    }
    else
    { /*input sem espacos*/
        ungetc(input, stdin);
        if (scanf("%s ", parag2) != 1)
        {
            return;
        }
    }
    if ((scanf("%lf %lf", &custo, &duracao)) != 2)
    {
        return;
    }
    getIndex(nome, parag1, parag2, index);
    /*Fazer verificacoes*/
    if (custo < 0 || duracao < 0)
    {
        printf("negative cost or duration.\n");
        return;
    }
    if (index[0] == -1)
    {
        printf("%s: no such line.\n", nome);
        return;
    }
    if (index[1] == -1)
    {
        printf("%s: no such stop.\n", parag1);
        return;
    }
    if (index[2] == -1)
    {
        printf("%s: no such stop.\n", parag2);
        return;
    }
    if (carreiras[index[0]].nParagens != 0 &&
        carreiras[index[0]].paragens[0] != index[2] &&
        carreiras[index[0]].paragens[carreiras[index[0]].nParagens - 1]
         != index[1])
    {
        printf("link cannot be associated with bus line.\n");
        return;
    }
    /*criar ligacao*/
    if (carreiras[index[0]].nParagens == 0)
    {
        /* Guarda a primeira ligacao de uma carreira*/
        strcpy(carreiras[index[0]].origem, parag1);
        strcpy(carreiras[index[0]].destino, parag2);
        for (j = 0; j < numParagens; j++)
        {
            if (strcmp(paragens[j].nome, parag1) == 0)
            {
                paragens[j].nCarreiras++;
            }
        }
        for (j = 0; j < numParagens; j++)
        {
            if (strcmp(paragens[j].nome, parag2) == 0)
            {
                paragens[j].nCarreiras++;
            }
        }
        carreiras[index[0]].nParagens = 2;
        carreiras[index[0]].paragens[0] = index[1];
        carreiras[index[0]].paragens[1] = index[2];
        carreiras[index[0]].custo += custo;
        carreiras[index[0]].duracao += duracao;
    }
    else if (strcmp(carreiras[index[0]].origem, parag2) == 0 &&
             strcmp(carreiras[index[0]].destino, parag1) == 0)
    {
        strcpy(carreiras[index[0]].destino, parag2);
        carreiras[index[0]].paragens[carreiras[index[0]].nParagens] = index[2];
        carreiras[index[0]].custo += custo;
        carreiras[index[0]].duracao += duracao;
        carreiras[index[0]].nParagens++;
        numParagens++;
    }
    else if (strcmp(carreiras[index[0]].origem, parag2) == 0)
    {
        for (i = carreiras[index[0]].nParagens; i > 0; i--)
        {
            carreiras[index[0]].paragens[i] = 
            carreiras[index[0]].paragens[i - 1];
        }
        for (j = 0; j < numParagens; j++)
        {
            if (strcmp(paragens[j].nome, parag1) == 0)
            {
                paragens[j].nCarreiras++;
            }
        }
        strcpy(carreiras[index[0]].origem, parag1);
        carreiras[index[0]].paragens[0] = index[1];
        carreiras[index[0]].custo += custo;
        carreiras[index[0]].duracao += duracao;
        carreiras[index[0]].nParagens++;
        numParagens++;
    }
    else if (strcmp(carreiras[index[0]].destino, parag1) == 0)
    {
        for (j = 0; j < numParagens; j++)
        {
            if (strcmp(paragens[j].nome, parag2) == 0)
            {
                paragens[j].nCarreiras++;
            }
        }
        strcpy(carreiras[index[0]].destino, parag2);
        carreiras[index[0]].paragens[carreiras[index[0]].nParagens] = index[2];
        carreiras[index[0]].custo += custo;
        carreiras[index[0]].duracao += duracao;
        carreiras[index[0]].nParagens++;
        numParagens++;
    }
}

/*Acabou por nao ser corretamente implementade,
mas a funcao i permitiria listar alfabeticamente as intersecoes de carreiras
em cada paragem, ou seja, quantas carreiras e quais passam 
em cada paragem*/
void i()
{
    int i, j;
    for (i = 0; i < numParagens; i++)
    {
        if (paragens[i].nCarreiras > 1)
        {
            printf("%s %d:", paragens[i].nome, paragens[i].nCarreiras);
            for (j = 0; j < paragens[i].nCarreiras; j++)
            {
                printf(" %s", carreiras[paragens[j].carreiras[j]].nome);
            }
            putchar('\n');
        }
    }
}

void s()
{   
    int i,j;
    int verifier = 0;
    char nome[MAXNOME];
    if (getchar() == '\n')
    {
        printf("Não é suposto chegar aqui.\n");
        return;
    }
    if (scanf("%s", nome) != 1)
            {   
                printf("Nem aqui.\n");
                return;
            }
    for (i = 0; i < numParagens; i++)
    {
        if (strcmp(nome, paragens[i].nome) == 0)
        {
            verifier++;
            for (j = 0; j < numCarreiras; j++)
            {
                if (strcmp(paragens[i].nome, carreiras[j].origem) == 0)
                {
                    printf("%s ", carreiras[j].nome);
                }
            }
        }
    }
    printf("\n");
    if (verifier == 0)
    {
        printf("%s: no such stop.\n", nome);
        return;
    }
}

/*Main*/
/*A funcao principal, que le os comandos do stdin e 
utiliza as funcionalidades base, ou terminando o programa dado um comando q*/
int main()
{
    char command;
    while ((command = getchar()) != 'q')
    {
        switch (command)
        {
        case 'q':
            return 0;
        case 'c':
            c();
            break;
        case 'p':
            p();
            break;
        case 'l':
            l();
            break;
        case 'i':
            i();
            break;
        case 's':
            s();
            break;
        case '\n':
            break;
        default:
            puts("Insert valid command");
        }
    }
    return 0;
}

