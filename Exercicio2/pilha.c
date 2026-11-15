#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void iniciarPilha(Pilha *p) {
    p->topo = -1;
}

void empilhar(Pilha *p, int valor) {
    if (p->topo == MAX - 1) {
        printf("\n[ERRO] A pilha de bandejas esta cheia!\n");
    } else {
        p->topo++; 
        p->itens[p->topo] = valor;
        printf("\n[SUCESSO] Bandeja numero %d foi empilhada no topo!\n", valor);
    }
}

void desempilhar(Pilha *p) {
    if (p->topo == -1) {
        printf("\n[ERRO] A pilha esta vazia!\n");
    } else {
        printf("\n[SUCESSO] Bandeja numero %d foi desempilhada!\n", p->itens[p->topo]);
        p->topo--;
    }
}

void mostrarPilha(Pilha *p) {
    if (p->topo == -1) {
        printf("\nA pilha esta vazia.\n");
    } else {
        printf("\n--- ESTADO ATUAL DA PILHA DE BANDEJAS ---\n");
        for (int i = p->topo; i >= 0; i--) {
            printf("| %4d |\n", p->itens[i]);
        }
        printf("--------\n");
    }
}

void consultarTopo(Pilha *p){
    if (p->topo == -1)
    {
        printf("\nA pilha esta vazia!\n");
        return;
    }
    printf("\nProxima bandeja: numero %d\n", p->itens[p->topo]);
}

void mostrarQuantidade(Pilha *p){
    if (p->topo == -1)
    {
        printf("\nA pilha esta vazia!\n");
    }else{
    printf("\nQuantidade de bandejas: %d\n", p->topo + 1);
    }
}

int main() {
    Pilha minhaPilha;
    iniciarPilha(&minhaPilha);
    int opcao, valor;

    do {
        printf("\n=== MENU BANDEJAS ===\n");
        printf("1. Adicionar Bandeja\n");
        printf("2. Retirar Bandeja\n");
        printf("3. Mostrar Pilha\n");
        printf("4. Consultar proxima bandeja\n");
        printf("5. Mostrar Quantidade\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o codigo da bandeja para empilhar: ");
                scanf("%d", &valor);
                empilhar(&minhaPilha, valor);
                break;
            case 2:
                desempilhar(&minhaPilha);
                break;
            case 3:
                mostrarPilha(&minhaPilha);
                break;
            case 4:
                consultarTopo(&minhaPilha);
                break;
            case 5:
                mostrarQuantidade(&minhaPilha);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}