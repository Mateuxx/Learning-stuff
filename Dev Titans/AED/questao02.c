#include <stdio.h>
#include <stdlib.h>

struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;

Arv* inicializa(void)
{
  return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad)
{
  Arv* p = (Arv*)malloc(sizeof(Arv));
  p->info = c;
  p->esq = sae;
  p->dir = sad;
  return p;
}

int vazia(Arv* a)
{
  return a == NULL;
}

Arv* libera(Arv* a)
{
  if (!vazia(a)) {
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
  }
  return NULL;
}

void imprime_pre(Arv* a)
{
  if (a != NULL) {
    printf("%d ", a->info); /* imprime raiz */
    imprime_pre(a->esq); /* imprime sae */
    imprime_pre(a->dir); /* imprime sad */
  }
}

void imprime_in(Arv* a)
{
  if (a != NULL) {
    imprime_in(a->esq); /* imprime sae */
    printf("%d ", a->info); /* imprime raiz */
    imprime_in(a->dir); /* imprime sad */
  }
}

void imprime_pos(Arv* a)
{
  if (a != NULL) {
    imprime_pos(a->esq); /* imprime sae */
    imprime_pos(a->dir); /* imprime sad */
    printf("%d ", a->info); /* imprime raiz */
  }
}

int main()
{
  Arv* arvore = inicializa();
  arvore = cria(1,
                cria(2, cria(4, NULL, NULL), cria(5, NULL, NULL)),
                cria(3, cria(6, NULL, NULL), cria(7, NULL, NULL)));

  printf("Imprimindo pré-fixado: ");
  imprime_pre(arvore);
  printf("\n");

  printf("Imprimindo in-fixado: ");
  imprime_in(arvore);
  printf("\n");

  printf("Imprimindo pós-fixado: ");
  imprime_pos(arvore);
  printf("\n");

  libera(arvore);

  return 0;
}
