#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma sala da mansao
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

//Funcao para criar uma sala dinamicamente      
Sala* criarsala(const char* nome) {
    Sala* novaSala = (Sala*) malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro ao alocar memoria para a sala.\n");
        exit(1);
    }
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}
// Explorar as salas a partir da raiz
void explorarSala(Sala* atual) {
    char escolha;

    while (atual != NULL){
        printf("\nVoce esta na sala: %s.\n", atual->nome);

        //Se nao a caminhos pra explorar, fim da exploracao.
        if (atual->esquerda == NULL&& atual->direita == NULL){
            printf("Fim da exploracao! Voce chegou a um comodo sem saidas.\n");
            break;      
        }
        printf("Escolha um caminho para explorar: (e) esquerda, (d) direita, (s) sair:");
        scanf(" %c", &escolha); 
        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (escolha == 's') {
            printf("Saindo da exploracao.\n");
            break;
        } else {
            printf("Caminho invalido. Tente novamente.\n");
        }
    }
}   

// Criando as salas e conectando-as
int main() {        
    Sala* salaEntrada = criarsala("Entrada");
    Sala* salaSalao = criarsala("Salao");
    Sala* salaCozinha = criarsala("Cozinha");
    Sala* salaBiblioteca = criarsala("Biblioteca");
    Sala* salaJardim = criarsala("Jardim");

    // Conectando as salas
    salaEntrada->esquerda = salaSalao;
    salaEntrada->direita = salaCozinha;
    salaSalao->esquerda = salaBiblioteca;
    salaSalao->direita = salaJardim;

    // Iniciando a exploração a partir da entrada
    explorarSala(salaEntrada);

    // Liberando a memoria alocada
    free(salaEntrada);
    free(salaSalao);
    free(salaCozinha);
    free(salaBiblioteca);
    free(salaJardim);

    return 0;
}
