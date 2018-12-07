#include<stdio.h>
#include<stdlib.h>
#include "arrayBinarySearch.h"

#define DEBUG 0

int main(int argc, const char *argv[]){
	arrayBS* abs = createArrayBS(10);
	int op = 1;
	elem info;

	printf("1 - Insert element\n");
	printf("2 - Remove element\n");
	printf("3 - search element\n");
	printf("4 - Print list\n");
	printf("0 - Quit\n");

	while(scanf("%d", &op), op){
		switch(op){
			case 1:
				printf("Type the element to insert: ");
				scanf("%d", &info);
				insertArrayBS(abs, info);
				break;
			case 2:
				printf("Type the element to remove: ");
				scanf("%d", &info);
				removeArrayBS(abs, info);
				break;
			case 3:
				printf("Type the element to search: ");
				scanf("%d", &info);
				printf("%d\n", searchArrayBS(abs, info));
				break;
			case 4:
				printArrayBS(abs);
				break;
		}
		printf("New option: \n");
	}

	destroyArrayBS(abs);
	
	return 0;
}