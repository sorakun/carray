#CARRAY

A library to handle dynamic arrays in C programming.
It lowers the burden of allocating, reallocating and 
freeing the object each time you update the array.

#About

Because arrays can be very complex, the library was made to make handling
arrays easier. The user can add/remove elements and also specify the way
elements are freed by passing the responsable function as a parameter
while removing any element from the array.

#DOCS

`Array * Create(void)`
Creates an instance of the array. No parameter given.

`void Free(Array * a, void (f)(void *))`
Frees all elements of a given array. The second argument is a function
that must be able to free the element of the array. It will be applied 
to all array elements.

`void AddElement(Array * a, void * e)`
Adds an element in the end of the array.

`void * GetElement(Array * a, int i);`
Returns a reference of the ith item in the array. 

`void DeleteElement(Array * a, int i, void (*f)(void *))`
Removes the ith item in the array and free it using a given function.

