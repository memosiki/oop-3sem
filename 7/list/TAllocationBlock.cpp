#include "TAllocationBlock.h"

int TAllocationBlock::freeCount() {
	return _freeBlocks.Size();
}
TAllocationBlock::TAllocationBlock(size_t size, size_t count) :
		_size(size), _count(count) {
	_usedBlocks = (char*) malloc(_size * _count);
	//_free_blocks = (void**) malloc(sizeof(void*) * _count);
	for (int i = 0; i < _count; i++)
		_freeBlocks.Insert(i, (void*) (_usedBlocks + i * _size));

	//std::cout << "//TAllocationBlock: Memory init" << std::endl;
}
void *TAllocationBlock::allocate() {
	void *result = nullptr;
	if (freeCount() > 0) {
		result = _freeBlocks.Fetch(freeCount() - 1);
		_freeBlocks.Delete(freeCount() - 1);
	//	std::cout << "//TAllocationBlock: Allocate " << (_count - freeCount())
	//			<< " of " << _count << std::endl;
	} else {
		std::cerr<< "//TAllocationBlock: No memory exception" << std::endl;
		result = nullptr;
	}
	return result;
}
void TAllocationBlock::deallocate(void *pointer) {
	//std::cout << "//TAllocationBlock: Deallocate block " << std::endl;
	_freeBlocks.Insert(freeCount(), pointer);
}

bool TAllocationBlock::hasFreeBlocks() {
	return freeCount() > 0;
}
TAllocationBlock::~TAllocationBlock() {
	if (freeCount() < _count)
		std::cerr << "//TAllocationBlock: Memory leaked" << std::endl;
	//else
	//	std::cout << "//TAllocationBlock: Memory freed" << std::endl;
//	_free_blocks will be deleted after exiting this deconstructor
	delete _usedBlocks;
}
