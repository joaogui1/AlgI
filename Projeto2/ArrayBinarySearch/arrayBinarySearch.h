#define totalSize 100005

typedef int elem;

typedef struct _arrayBS{
	int maxSize;
	int currSize;
	int isSorted;
	int vec[totalSize];
} arrayBS;

arrayBS* createArrayBS(int size);
int insertArrayBS(arrayBS* abs, elem x);
int removeArrayBS(arrayBS* abs, elem x);
int searchArrayBS(arrayBS* abs, elem x);
int isEmptyArrayBS(arrayBS* abs);
int isFullArrayBS(arrayBS* abs);
void printArrayBS(arrayBS* abs);
void destroyArrayBS(arrayBS* abs);