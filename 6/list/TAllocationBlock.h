#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H
#include <cstdlib>
#include "TLista.h"
#include "TLista.cpp"
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
	TLista<void*> _freeBlocks;

};
#endif
/* TALLOCATIONBLOCK_H */
