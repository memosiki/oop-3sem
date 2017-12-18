#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H
#include <cstdlib>
#include <iostream>
#include <memory>
#include "TListSimple.h"
#include "TListSimple.cpp"
class TAllocationBlock {
public:
	TAllocationBlock(size_t size, size_t count);
	virtual ~TAllocationBlock();
	void *allocate();
	void deallocate(void *pointer);
	bool hasFreeBlocks();
	int freeCount();
private:
	size_t _size;	 //sizeof blocks in bytes
	int _count;	//quantity of blocks
	char*_usedBlocks;
	TListSimple<void*> _freeBlocks;

};
#endif
/* TALLOCATIONBLOCK_H */
