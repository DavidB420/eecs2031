#ifndef BINSRCH_H
#define BINSRCH_H

typedef struct binstruct* binptr;

struct binstruct {
	int val;
	binptr l;
	binptr r;
};

extern void bininsert(binptr* bin, int v);
extern int binsearch(binptr* bin, int v);

binptr makebinstruct();

#endif