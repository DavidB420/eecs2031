#include "binsrch.h"
#include <stdlib.h>
#include <stdio.h>

void bininsert(binptr* bin, int v)
{
	if (*bin == NULL)
	{
		*bin = makebinstruct();
		(*bin)->val = v;
	}

	if (v < (*bin)->val)
		bininsert((&(*bin)->l), v);
	else if (v > (*bin)->val)
		bininsert(&((*bin)->r), v);
}

int binsearch(binptr* bin, int v)
{
	if (*bin == NULL)
		return -1;

	if ((*bin)->val == v)
		return 0;

	if (v < (*bin)->val)
		binsearch((&(*bin)->l), v);
	else if (v > (*bin)->val)
		binsearch(&((*bin)->r), v);
}

binptr makebinstruct()
{
	binptr newPointer = (binptr) malloc(sizeof(struct binstruct));

	if (newPointer == NULL)
	{
		printf("Out of memory!\n");
		exit(1);
	}

	newPointer->l = NULL;
	newPointer->r = NULL;
	
	return newPointer;
}
