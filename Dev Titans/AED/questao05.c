#include <stdio.h>
#include <stdlib.h>

struct arvgen {
  int info;
  struct arvgen *prim;
  struct arvgen *prox;
};
typedef struct arvgen ArvGen;


ArvGen* cria (int info)
{
  ArvGen *a =(ArvGen *)malloc(sizeof(ArvGen));
  a->info = info;
  a->prim = NULL;
  a->prox = NULL;
  return a;
}

void insere (ArvGen* a, ArvGen* f)
{
  f->prox = a->prim;
  a->prim = f;
}



void libera (ArvGen* a)
{
  ArvGen* p = a->prim;
  while (p!=NULL) {
    ArvGen* t = p->prox;
    libera(p);
    p = t;
  }
  free(a);
}

void imprime (ArvGen* a)
{
  ArvGen* p;
  printf("%d\n",a->info);
  for (p=a->prim; p!=NULL; p=p->prox)
    imprime(p);
}

int busca (ArvGen* a, char c)
{
  ArvGen* p;
  if (a->info==c)
    return 1;
  else {
    for (p=a->prim; p!=NULL; p=p->prox) {
      if (busca(p,c))
        return 1;
    }
  }
  return 0;
}

int main()
{
  // Criação da árvore genérica
  ArvGen* arvore = cria(50);

  ArvGen* filho1 = cria(20);
  ArvGen* filho2 = cria(60);
  ArvGen* neto1 = cria(10);
  ArvGen* neto2 = cria(30);
  ArvGen* neto3 = cria(55);
  ArvGen* neto4 = cria(70);
  ArvGen* bisneto1 = cria(5);
  ArvGen* bisneto2 = cria(15);
  ArvGen* bisneto3 = cria(35);
  ArvGen* bisneto4 = cria(65);
  ArvGen* bisneto5 = cria(75);

  insere(arvore, filho1);
  insere(arvore, filho2);
  insere(filho1, neto1);
  insere(filho1, neto2);
  insere(filho2, neto3);
  insere(filho2, neto4);
  insere(neto1, bisneto1);
  insere(neto1, bisneto2);
  insere(neto2, bisneto3);
  insere(neto4, bisneto4);
  insere(neto4, bisneto5);

  // Impressão da árvore
  printf("Árvore genérica:\n");
  imprime(arvore);

  // Verificar se os elementos 12 e 88 estão presentes na árvore
  int busca12 = busca(arvore, 12);
  int busca88 = busca(arvore, 88);

  if (busca12)
    printf("O elemento 12 está presente na árvore.\n");
  else
    printf("O elemento 12 não está presente na árvore.\n");

  if (busca88)
    printf("O elemento 88 está presente na árvore.\n");
  else
    printf("O elemento 88 não está presente na árvore.\n");

  libera(arvore);

  return 0;
}
