#include <graph.h>
#include "trab3.h"

#define true 1
#define false 0
#define VALOR_GRANDE 100000000
 
int count = 0;
 
/**Structs****/
struct No_Vertice_L
{
	Node node;
	Vertice vertice;

};

struct No_Aresta_L
{
	Dist_V distancia;

};

//******Funções
unsigned int ident3() 
{
	return 2014780267;
}

void freeNo_Vertice_L(No_Vertice_L * no) 
{
	free(no);
}

Vertice alvo(No_Vertice_L * const no) 
{
	Vertice *v;
	v = (Vertice) &no.vertice;
	//return &no.vertice;
	return v;
}

No_Vertice_L * avancar_VL(No_Vertice_L * no) 
{
	return NULL;
}

No_Vertice_L * partida_VL(Graph * const g, Vertice u) 
{
	return NULL;
}

int chegada_VL(No_Vertice_L * no) 
{
	return 0;
}

int eh_subbipartido(Graph * const g, BitMap const * r, BitMap * s, BitMap * t) 
{
	return 0;
}



int eh_bipartido(Graph * const g, BitMap * s, BitMap * t)
{
	BitMap *F;
	F = newBitMap(g->n);
	BitMap *A;
	A = newBitMap(g->n);

	Node node;
	begin(g->matrix, &node);
	addNode(F, &node);

    Node u;
    Dist_V d = 0;
	while(isNotEmpty(F))
	{
		//printf("LOOP\n");
		//Node u;
	//	int Fila[g->n];
		int *Fila = unpack(F);
		int ini = Fila[0];		
		delElement(F,ini);
		BitMap *B;
		B = newBitMap(g->n);
		B = neig(g,ini);
		removeAll(B,A);
		addAll(A,B);
	//	int *aux = unpack(B); 
		Node w;
		begin(B,&w);
	//	w.cur = aux[0];
		while(!end(&w))
		{
			addNode(F,&w);

			if(d % 2 == 0)
			{
				printf("PAR\n");
				addNode(s,&w);
			}

			else
			{
				printf("ÍMPAR\n");
				addNode(t,&w);
			}

			next(&w);
			
		}

		d++;
	}

	Node aux;


	for(begin(s,&aux);!end(&aux); next(&aux))
	{
	//	printf("----------------------------------------\n");
		BitMap *vizinhos =  newBitMap(g->n);
		vizinhos = neig(g,getElement(&aux));
	//	printf("tam %d\n",cardOf(vizinhos));
		BitMap *intesecao = newBitMap(g->n);
		intersectOf(intesecao,vizinhos,s);
		if(cardOf(intesecao) > 0)
			return 0;
	}

	Node aux2;

	for(begin(t,&aux2);!end(&aux2); next(&aux2))
	{
		BitMap *vizinhos =  newBitMap(g->n);
		vizinhos = neig(g,getElement(&aux2));
		BitMap *intesecao = newBitMap(g->n);
		intersectOf(intesecao,vizinhos,t);
		if(cardOf(intesecao) > 0)
		{
			//printf("não é\n");
			return 0;
		}
	}

	return 1;
}

/*int eh_bipartido(Graph * const g, BitMap * s, BitMap * t) 
{
	BitMap *F[2];
	F[0] = newBitMap(g->n);
	F[1] = newBitMap(g->n);
	BitMap * A = newBitMap(g->n);
	BitMap * B = newBitMap(g->n);

	Node inicio;
	begin(g->matrix, &inicio);
	addNode(A, &inicio);

	//printf("Alvo inicial: %d\n",getElement(&inicio));

	int d = 0;
	int tipo = 0;
	addNode(F[d + 1 % 2],&inicio);
	addAll(F[0],neig(g,getElement(&inicio)));
	Node u;
	begin(F[tipo],&u);

	do
	{
		//printf("NO LOOP\n");
		next(&u);
		if(end(&u))
		{
			printf("End\n");
			tipo = (d + 1) % 2; //era d
			addAll(F[tipo],neig(g,getElement(&u)));
			begin(F[tipo],&u);
			if(tipo % 2 == 0)
			{
				printf("TIpo 0\n");
				addAll(s,F[tipo]);
			} 

			else if(tipo % 2 != 0)
			{
				printf("Tipo 1\n");
				addAll(t,F[tipo]);
			}
			d++;

		}
		if(!end(&u))
		{
			printf("Nao end\n");
			delNode(F[tipo], &u);
			B = neig(g, getElement(&u)); 
			removeAll(B, A);
			addAll(A, B);
			addAll(F[((tipo + 1) % 2)],B);
		}

	}while(isNotEmpty(F[0]) && isNotEmpty(F[1]));

	Node aux;


	for(begin(s,&aux);!end(&aux); next(&aux))
	{
		printf("----------------------------------------\n");
		BitMap *vizinhos =  newBitMap(g->n);
		vizinhos = neig(g,getElement(&aux));
		printf("tam %d\n",cardOf(vizinhos));
		BitMap *intesecao = newBitMap(g->n);
		intersectOf(intesecao,vizinhos,s);
		if(cardOf(intesecao) > 0)
			return 0;
	}

	Node aux2;

	for(begin(t,&aux2);!end(&aux2); next(&aux2))
	{
		BitMap *vizinhos =  newBitMap(g->n);
		vizinhos = neig(g,getElement(&aux2));
		BitMap *intesecao = newBitMap(g->n);
		intersectOf(intesecao,vizinhos,t);
		if(cardOf(intesecao) > 0)
		{
			printf("não é\n");
			return 0;
		}
	}

	return 1;
}*/

Dist_V distancia(No_Vertice_L * const no)
{
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void freeNo_Aresta_L(No_Aresta_L * no) 
{
}

Vertice alvo_menor(No_Aresta_L * const no) 
{
	return 0;
}

Vertice alvo_maior(No_Aresta_L * const no) 
{
	return 0;
}

int chegada_AL(No_Aresta_L * no) 
{
	return 0;
}

No_Aresta_L * avancar_AL(No_Aresta_L * no)
 {
	return NULL;
}

No_Aresta_L * partida_AL(Graph * const g, Vertice u) 
{
	return NULL;
}
