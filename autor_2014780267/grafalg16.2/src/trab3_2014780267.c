#include <graph.h>
//#include "trab3.h"

#define true 1
#define false 0
#define VALOR_GRANDE 100000000
 
int count = 0;

typedef unsigned int Vertice;

typedef unsigned int Dist_V;

typedef struct No_Vertice_L_ No_Vertice_L;

typedef struct No_Aresta_L_ No_Aresta_L;
 
/**Structs****/
typedef struct No_Vertice_L_
{
	Node node;
	Vertice vertice;
	Dist_V distancia;

	No_Vertice_L * anterior;  //pode ser que necessite de malloc


};

typedef struct No_Aresta_L_
{
	No_Vertice_L no1;
	No_Vertice_L no2;
	//Dist_V distancia;

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
	return no->vertice;
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

Dist_V distancia(No_Vertice_L * const no)
{
	if(no->anterior != NULL)
    	return no->distancia = no->anterior->distancia + 1;

    else
    {
    	return no->distancia = 0;

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////

void freeNo_Aresta_L(No_Aresta_L * no) 
{
	free(no);
}

Vertice alvo_menor(No_Aresta_L * const no) 
{
	if(no->no1.distancia <= no->no2.distancia)
		return no->no1.vertice;

	else
		return no->no2.vertice;
}

Vertice alvo_maior(No_Aresta_L * const no) 
{
	if(no->no1.distancia >= no->no2.distancia)
		return no->no1.vertice;

	else
		return no->no2.vertice;

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
