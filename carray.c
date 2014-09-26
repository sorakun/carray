
#include <stdlib.h>
#include <stdio.h>

#include "carray.h"

Array * Create(void){
	Array * a = malloc(sizeof(Array));
	a->size = 0;
	a->table = null;

	return a;
}

/* given a free function, it will free all elements */
void Free(Array * a, void (f)(void *)){
	int i = 0;
	for(; i < a->size; i++)
		f(a->table[i]);
	free(a->table);
	free(a);
}

void AddElement(Array * a, void * e){
	a->table = realloc(a->table, (a->size+1) * sizeof(void **));
	a->table[a->size] = e;
	a->size++;
}

void * GetElement(Array * a, int i){
	if ((i>a->size) || (i<0)){
		fprintf(stderr, "Invalid index given to Array.GetElement(%d).\n", i);
		printError;
		exit(-1);
	}

	return a->table[i];
}

void DeleteElement(Array * a, int i, void (*f)(void *)){
	if ((i>a->size) || (i<0)){
		fprintf(stderr, "Invalid index given to Array.GetElement(%d).\n", i);
		printError;
		exit (-1);
	}

	void * x = GetElement(a, i);

	f(x);

	int j = i+1;
	for(; j < a->size; j++)
		a->table[j-1] = a->table[j];

	a->table = realloc(a->table, a->size*sizeof(void*));
	a->size--;
}
