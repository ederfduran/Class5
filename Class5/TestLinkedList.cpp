#include <cassert>
#include "LinkedList.h"
#include <stdlib.h>
#include "TestLinkedList.h"


void cpp_class5_test::testCreateList(){
	cpp_class5::Node* const myList = cpp_class5::createList(10.f);
	assert(myList && myList->val==10.f);
	free(myList);
}

void cpp_class5_test::testPush_back()
{
	const float mockArray[] = {10.f,20.f,30.f,40.f,50.f};
	cpp_class5::Node* myList = cpp_class5::createList(10.f);
	cpp_class5::push_back(myList,20.f);
	cpp_class5::push_back(myList, 30.f);
	cpp_class5::push_back(myList, 40.f);
	cpp_class5::push_back(myList, 50.f);
	for (unsigned int i = 0;i<5;i++) {
		assert(cpp_class5::getElementAtIndex(myList,i)==mockArray[i]);
	}
	
	cpp_class5::clear(myList);
}

void cpp_class5_test::testpop_back()
{
	const float mockArray[] = { 1.5f,2.5f};
	cpp_class5::Node* myList = cpp_class5::createList(1.5f);
	cpp_class5::push_back(myList, 2.5f);
	cpp_class5::push_back(myList, 3.5f);
	cpp_class5::push_back(myList, 4.5f);
	cpp_class5::pop_back(myList);
	cpp_class5::pop_back(myList);
	for (unsigned int i = 0; i<2; i++) {
		assert(cpp_class5::getElementAtIndex(myList, i) == mockArray[i]);
	}
	assert(cpp_class5::getElementCount(myList)==2);
	cpp_class5::clear(myList);

	//-----------> popback with size 0
	cpp_class5::Node* myList2 = cpp_class5::createList(1.f);
	cpp_class5::pop_back(myList2);
	assert(myList2==nullptr);
}

void cpp_class5_test::testClear()
{
	cpp_class5::Node* myList = cpp_class5::createList(1.5f);
	cpp_class5::push_back(myList, 2.5f);
	cpp_class5::push_back(myList, 3.5f);
	cpp_class5::clear(myList);
	assert(myList==nullptr);
}

void cpp_class5_test::testGetElementCount()
{
	cpp_class5::Node* myList = cpp_class5::createList(10.f);
	cpp_class5::push_back(myList, 20.f);
	cpp_class5::push_back(myList, 30.f);
	cpp_class5::push_back(myList, 40.f);
	cpp_class5::push_back(myList, 50.f);
	assert(cpp_class5::getElementCount(myList)==5);
	for (unsigned int i=0;i<4;i++) {
		cpp_class5::pop_back(myList);
	}
	assert(cpp_class5::getElementCount(myList) == 1);
	cpp_class5::clear(myList);
}

void cpp_class5_test::testClone()
{
	cpp_class5::Node* myList = cpp_class5::createList(10.f);
	cpp_class5::Node* myListCloned = cpp_class5::clone(myList);
	assert(myList!=myListCloned && myListCloned->val==10.f);
	
	cpp_class5::Node* myList2 = cpp_class5::createList(10.f);
	cpp_class5::push_back(myList2, 20.f);
	cpp_class5::push_back(myList2, 30.f);
	cpp_class5::push_back(myList2, 40.f);
	cpp_class5::push_back(myList2, 50.f);

	cpp_class5::Node * myListCloned2 = cpp_class5::clone(myList2);
	for (unsigned int i = 0;i<5;i++) {
		assert(cpp_class5::getElementAtIndex(myList2,i) == cpp_class5::getElementAtIndex(myListCloned2, i));
	}
}

void cpp_class5_test::testGetElementAtIndex()
{
	cpp_class5::Node* myList = cpp_class5::createList(10.f);
	cpp_class5::push_back(myList, 20.f);
	cpp_class5::push_back(myList, 30.f);
	cpp_class5::push_back(myList, 40.f);
	cpp_class5::push_back(myList, 50.f);
	assert(cpp_class5::getElementAtIndex(myList,3)==40.f && cpp_class5::getElementAtIndex(myList,0)==10.f);
	cpp_class5::clear(myList);
}

void cpp_class5_test::testInsert()
{
	const float mockArray[5] = {40.f,1.f,2.5f,40.f,3.5f};
	cpp_class5::Node* myList = cpp_class5::createList(1.f);
	cpp_class5::push_back(myList, 2.5f);
	cpp_class5::push_back(myList, 3.5f);
	cpp_class5::insert(myList,0,40.f);
	cpp_class5::insert(myList, 3, 40.f);
	for (unsigned int i = 0;i<5;i++) {
		assert(mockArray[i]== cpp_class5::getElementAtIndex(myList,i));
	}
	
	cpp_class5::clear(myList);
}

void cpp_class5_test::testErase()
{
	const float mockArray[5] = { 2.5f,3.5f,4.f};
	cpp_class5::Node* myList = cpp_class5::createList(1.f);
	cpp_class5::push_back(myList, 2.5f);
	cpp_class5::push_back(myList, 3.5f);
	cpp_class5::push_back(myList, 4.f);
	cpp_class5::push_back(myList, 5.5f);
	cpp_class5::erase(myList,0);
	cpp_class5::erase(myList,3);
	for (unsigned int i=0;i<3;i++) {
		assert(mockArray[i]== cpp_class5::getElementAtIndex(myList,i));
	}
	cpp_class5::clear(myList);
}

void cpp_class5_test::testGetOccurrenceCount()
{
	cpp_class5::Node* myList = cpp_class5::createList(1.f);
	cpp_class5::push_back(myList, 2.5f);
	cpp_class5::push_back(myList, 3.5f);
	cpp_class5::push_back(myList, 4.f);
	cpp_class5::push_back(myList, 5.5f);
	cpp_class5::push_back(myList, 2.5f);
	cpp_class5::push_back(myList, 3.f);
	cpp_class5::push_back(myList, 4.f);
	cpp_class5::push_back(myList, 5.5f);
	cpp_class5::push_back(myList, 2.5f);
	cpp_class5::push_back(myList, 3.55f);
	cpp_class5::push_back(myList, 45.f);
	cpp_class5::push_back(myList, 5.500000000001f);
	assert(cpp_class5::getOccurrenceCount(myList,5.5f)==3 && cpp_class5::getOccurrenceCount(myList, 4.5f) == 0);
	cpp_class5::clear(myList);
}

void cpp_class5_test::testEraseAllOccurrences()
{
	const float mockArray[] = {1.f,3.5f,4.f,3.f,4.f,3.55f,45.f };
	cpp_class5::Node* myList = cpp_class5::createList(1.f);
	cpp_class5::push_back(myList, 2.5f);  // -> delete
	cpp_class5::push_back(myList, 3.5f);
	cpp_class5::push_back(myList, 4.f);
	cpp_class5::push_back(myList, 5.5f); // -> delete
	cpp_class5::push_back(myList, 2.5f); // -> delete
	cpp_class5::push_back(myList, 3.f);
	cpp_class5::push_back(myList, 4.f);
	cpp_class5::push_back(myList, 5.5f); // -> delete
	cpp_class5::push_back(myList, 2.5f); // -> delete
	cpp_class5::push_back(myList, 3.55f);
	cpp_class5::push_back(myList, 45.f);
	cpp_class5::push_back(myList, 5.500000000001f);// -> delete
	cpp_class5::eraseAllOccurrences(myList,2.5f);
	cpp_class5::eraseAllOccurrences(myList, 5.5f);
	cpp_class5::eraseAllOccurrences(myList, 0.f);
	const unsigned int count = cpp_class5::getElementCount(myList);
	for (unsigned int i=0;i<count;i++) {
		assert(mockArray[i]== cpp_class5::getElementAtIndex(myList,i));
	}
	cpp_class5::clear(myList);
}

void cpp_class5_test::testReverse()
{
	const float mockArray[] = { 50.f,40.f,30.f,20.f,10.f };
	cpp_class5::Node* myList = cpp_class5::createList(10.f);
	cpp_class5::push_back(myList, 20.f);
	cpp_class5::push_back(myList, 30.f);
	cpp_class5::push_back(myList, 40.f);
	cpp_class5::push_back(myList, 50.f);
	cpp_class5::reverse(myList);
	for (unsigned int i = 0;i<5;i++) {
		assert(mockArray[i] == cpp_class5::getElementAtIndex(myList,i) );
	}
	cpp_class5::clear(myList);
}
