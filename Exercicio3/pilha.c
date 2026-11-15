#include <stdio.h>

#define MAX 5

typedef struct{
    int itens[MAX];
    int topo;
} Pilha;

void iniciarPilha(Pilha *p){
    p->topo = -1;
}

void empilhar(Pilha *p, int valor){
    if (p->topo == MAX - 1) {
        printf("\n[ERRO] A pilha esta cheia (Stack Overflow)!\n");
    } else {
        p->topo++; 
        p->itens[p->topo] = valor;
        printf("\n[SUCESSO] %d foi empilhado no topo!\n", valor);
    }
}

int desempilhar(Pilha *p, int *valor) {
    if (p->topo == -1) {
        printf("\n[ERRO] A pilha esta vazia (Stack Underflow)!\n");
        return 0;
    }
       *valor = p->itens[p->topo];
        p->topo--;
    return 1;
}

void mostrarPilha(Pilha *p) {
    if (p->topo == -1) {
        printf("\nA pilha esta vazia.\n");
    } else {
        printf("\n--- ESTADO ATUAL DA PILHA ---\n");
        for (int i = p->topo; i >= 0; i--) {
            printf("| %4d |\n", p->itens[i]);
        }
        printf("--------\n");
    }
}

int main() {
    Pilha minhaPilha;
    iniciarPilha(&minhaPilha);
    int qtd, valor;

    // 1) Pede a quantidade, repetindo até estar entre 1 e MAX
    do {
        printf("Quantos numeros deseja informar (1 a %d)? ", MAX);
        scanf("%d", &qtd);
    } while (qtd < 1 || qtd > MAX);

    // 2) Lê e empilha
    for (int i = 0; i < qtd; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &valor);
        empilhar(&minhaPilha, valor);
    }

    // 3) Retira tudo e mostra na ordem de retirada
    printf("\nOrdem inversa: ");
    while (desempilhar(&minhaPilha, &valor)) {
        printf("%d ", valor);
    }
    printf("\n");

    // 4) Confirma que a pilha ficou vazia
    mostrarPilha(&minhaPilha);

    return 0;
}