#include <stdio.h>
#include <stdlib.h>

struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;

void imprime_in(Arv* a) {
  if (a != NULL) {
    imprime_in(a->esq);
    printf("%d ", a->info);
    imprime_in(a->dir);
  }
}

Arv* busca(Arv* r, int v) {
  if (r == NULL)
    return NULL;
  else if (r->info > v)
    return busca(r->esq, v);
  else if (r->info < v)
    return busca(r->dir, v);
  else
    return r;
}

Arv* insere(Arv* a, int v) {
  if (a == NULL) {
    a = (Arv*)malloc(sizeof(Arv));
    a->info = v;
    a->esq = a->dir = NULL;
  } else if (v < a->info)
    a->esq = insere(a->esq, v);
  else /* v >= a->info */
    a->dir = insere(a->dir, v);
  return a;
}

void libera(Arv* a) {
  if (a != NULL) {
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
  }
}

int main(void) {
  Arv* arvore = NULL;

  // Inserindo elementos na árvore
  arvore = insere(arvore, 1);
  printf("Árvore: ");
  imprime_in(arvore);
  printf("\n");

  arvore = insere(arvore, 2);
  printf("Árvore: ");
  imprime_in(arvore);
  printf("\n");

  arvore = insere(arvore, 3);
  printf("Árvore: ");
  imprime_in(arvore);
  printf("\n");

  arvore = insere(arvore, 5);
  printf("Árvore: ");
  imprime_in(arvore);
  printf("\n");

  arvore = insere(arvore, 15);
  printf("Árvore: ");
  imprime_in(arvore);
  printf("\n");

  arvore = insere(arvore, 7);
  printf("Árvore: ");
  imprime_in(arvore);
  printf("\n");

  // Buscando elementos na árvore
  int elemento1 = 2;
  int elemento2 = 8;

  if (busca(arvore, elemento1) != NULL)
    printf("Elemento %d encontrado na árvore.\n", elemento1);
  else
    printf("Elemento %d não encontrado na árvore.\n", elemento1);

  if (busca(arvore, elemento2) != NULL)
    printf("Elemento %d encontrado na árvore.\n", elemento2);
  else
    printf("Elemento %d não encontrado na árvore.\n", elemento2);

  // Liberando memória
  libera(arvore);

  return 0;
}
