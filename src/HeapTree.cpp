#include "include/HeapTree.h"
template <> HeapTree<int>::HeapTree() {}

int main(void){
	HeapTree<int> Struct;
	Struct.add(3);
	cout << (int)Struct.remove(NULL);
	return 0;
}
