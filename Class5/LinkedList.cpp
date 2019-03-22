#include <cassert>
#include <stdlib.h>
#include <limits>
#include "LinkedList.h"


cpp_class5::Node * cpp_class5::createList(const float inVal)
{
	Node* const newNode = reinterpret_cast<Node*>(malloc(sizeof(Node)) );
	newNode->val = inVal;
	newNode->nextNodePtr = nullptr;
	return newNode;
}

cpp_class5::Node *& cpp_class5::getLastNode(Node *& list)
{
	assert(list);
	if (list->nextNodePtr!=nullptr) {
		return getLastNode(list->nextNodePtr);
	}
	return list;
}

void cpp_class5::push_back( Node * list,const float inVal) {
	assert(list);
	Node* lastNode = getLastNode(list);
	lastNode->nextNodePtr = reinterpret_cast<Node*>(malloc(sizeof(Node)));
	lastNode->nextNodePtr->val = inVal;
	lastNode->nextNodePtr->nextNodePtr = nullptr;
}

void cpp_class5::pop_back(Node* & node ) {
	assert(node);
	Node* &lastNode = getLastNode(node);
	free(lastNode);
	lastNode = nullptr;
}

void cpp_class5::clear(Node*& node) {
	if (!node) {
		return;
	}
	Node*& nodeToClear = getLastNode(node);
	if (nodeToClear) {
		free(nodeToClear);
		nodeToClear = nullptr;
		clear(node);
	}
}

unsigned int cpp_class5::getElementCount(Node* list) {
	if (list==nullptr) {
		return 0;
	}
	unsigned int elementCounter = 0;
	while (list!=nullptr) {
		elementCounter++;
		list = list->nextNodePtr;
	}
	return elementCounter;
}

cpp_class5::Node* cpp_class5::clone(Node* nodeToClone) {
	assert(nodeToClone);
	Node* clonedNode = createList(nodeToClone->val);
	*clonedNode = *nodeToClone;
	return clonedNode;
}

cpp_class5::Node* cpp_class5::getNodeAtIndex(Node* list, unsigned int index) {
	if (index > getElementCount(list)-1) {
		return nullptr;
	}
	while (index != 0)
	{
		list = list->nextNodePtr;
		index--;
	}
	assert(list != nullptr);
	return list;
}

float cpp_class5::getElementAtIndex(Node* list, unsigned int index) {
	assert(list);
	Node* nodeToRead = getNodeAtIndex(list,index);
	assert(nodeToRead);
	return nodeToRead->val;
}

void cpp_class5::insert(Node*& list, unsigned int index, float value) {
	
	assert(list&& index < getElementCount(list));
	Node* nodeToRead = getNodeAtIndex(list, index);
	Node* newNode= reinterpret_cast<Node*>(malloc(sizeof(Node)));
	newNode->val = nodeToRead->val;
	newNode->nextNodePtr = nodeToRead->nextNodePtr;
	nodeToRead->val = value;
	nodeToRead->nextNodePtr = newNode;
}

void cpp_class5::erase(Node*&list,unsigned int index) {
	assert(list && index < getElementCount(list));
	if (index==0) {
		Node* newListPtr = list->nextNodePtr;
		free(list);
		list = newListPtr;
	}
	else {
		Node* nodeToRead = getNodeAtIndex(list, index - 1);
		Node* nodeToDelete = nodeToRead->nextNodePtr;
		assert(nodeToDelete);
		nodeToRead->nextNodePtr = nodeToDelete->nextNodePtr;
		free(nodeToDelete);
	}
	
}

bool cpp_class5::areEqual(const float a, const float b) {
	return std::abs(a - b) <= std::numeric_limits<float>::epsilon();
}

unsigned int cpp_class5::getOccurrenceCount(Node* list, const float num){
	const unsigned int count = getElementCount(list);
	unsigned int occurence = 0;
	for (unsigned int i = 0;i<count;i++) {
		if (areEqual(getElementAtIndex(list, i),num)) {
			occurence++;
		}
	}
	return occurence;
}

void cpp_class5::eraseAllOccurrences(Node *& list, const float num)
{
	assert(list);
	unsigned int count = getElementCount(list);
	for (unsigned int i = 0;i < count ;i++) {
		float a = getElementAtIndex(list, i);
		if (areEqual(getElementAtIndex(list, i), num)) {
			erase(list,i);
			// the list is runtime updated 
			count = getElementCount(list);
			i--;  
		}
	}
}

void cpp_class5::reverse(Node *& list)
{
	unsigned const int count = getElementCount(list);
	unsigned const int halfCount = static_cast<int>(count / 2);
	for (unsigned int i = 0; i < halfCount; i++) {
		float buff = getElementAtIndex(list,count-1-i);
		getNodeAtIndex(list, count - 1 - i)->val = getElementAtIndex(list,i);
		getNodeAtIndex(list, i)->val = buff;
	}
}
