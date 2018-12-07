all:
	gcc List/list.c ListFreq/listFreq.c ListWithSentinel/listWithSentinel.c ArrayBinarySearch/arrayBinarySearch.c AVL/AVL.c BST/BST.c main.c -O2 -o main

list:
	gcc List/list.c -o list

listFreq:
	gcc ListFreq/listFreq.c -o listFreq

listWithSentinel:
	gcc ListWithSentinel/listWithSentinel.c -o listWS

arrayBS:
	gcc ArrayBinarySearch/arrayBinarySearch.c -o abs

avl:
	gcc AVL/AVL.c -o avl

bst:
	gcc BST/BST.c -o bst

run:
	./main

runTAD $2:
	./$2

debug:
	valgrind ./main

debugTAD $2:
	valgrind ./$2