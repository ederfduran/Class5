#include <stdlib.h>
#include <iostream>
#include "LinkedList.h"
#include "TestLinkedList.h"

int main() {

	cpp_class5_test::testCreateList();
	cpp_class5_test::testPush_back();
	cpp_class5_test::testpop_back();
	cpp_class5_test::testClear();
	cpp_class5_test::testGetElementCount();
	cpp_class5_test::testClone();
	cpp_class5_test::testGetElementAtIndex();
	cpp_class5_test::testInsert();
	cpp_class5_test::testErase();
	cpp_class5_test::testEraseAllOccurrences();
	cpp_class5_test::testGetOccurrenceCount();
	cpp_class5_test::testReverse();
	std::cin.get();
	return 0;
}