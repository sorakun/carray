
#include "carray.h"

typedef struct Student{
    int age;
    char * name;
}Student;

int main(void)
{
	Array * e = Create();
	int x[10] = {10, 20, 30, 40, 5, 60, 70, 80, 90, 100};
	int i = 0;
	for(; i < 5; i++){
        Student * s = malloc(sizeof(Student));
        s->age = x[i];
        s->name = strdup("student");
		AddElement(e, s);
	}

	for(i = 0; i < e->size; i++){
        Student * x = GetElement(e, i);
		printf("element at %d is %d\n", i, x->age);
	}
}
