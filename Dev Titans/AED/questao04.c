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

Arv* podar_subarvore(Arv* a, int valor)
{
  if (a == NULL)
    return NULL;

  if (a->info == valor) {
    libera(a);
    return NULL;
  }

  a->esq = podar_subarvore(a->esq, valor);
  a->dir = podar_subarvore(a->dir, valor);

  return a;
}

int main()
{
  Arv* arvore = inicializa();

  arvore = cria(100,
                cria(50,
                     cria(25, NULL, cria(34, NULL, NULL)),
                     cria(75, NULL, NULL)),
                cria(150,
                     cria(125, NULL, NULL),
                     cria(175, NULL, NULL)));

  printf("Árvore original:\n");
  printf("Imprimindo pré-fixado: ");
  imprime_pre(arvore);
  printf("\n");

  printf("Imprimindo in-fixado: ");
  imprime_in(arvore);
  printf("\n");

  printf("Imprimindo pós-fixado: ");
  imprime_pos(arvore);
  printf("\n");

  arvore = podar_subarvore(arvore, 34);

  printf("\nÁrvore após a poda:\n");
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