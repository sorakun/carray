/*
 * CArray
 * C library to handle dynamic arrays
 */

#ifndef CARRAY_H
#define CARRAY_H

#define printError fprintf(stderr, "CriticalError in File \"%s\" Function \"%s\" Line %d.\n", __FILE__, __func__, __LINE__);
#define null NULL

typedef struct Array{
	void ** table;
	int size;
}Array;

Array * Create(void);
void Free(Array * a, void (f)(void *));
void AddElement(Array * a, void * e);
void * GetElement(Array * a, int i);
void DeleteElement(Array * a, int i, void (*f)(void *));

#endif
