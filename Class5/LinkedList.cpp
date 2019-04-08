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
	Node* myList = list;
	while (myList->nextNodePtr != nullptr)
	{
		Node *& lastNode = myList->nextNodePtr;
		if (lastNode->nextNodePtr == nullptr) {
			return lastNode;
		}
		myList = myList->nextNodePtr;
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

void cpp_class5::clear(Node*& list) {
	assert(list);
	if (Node* nodeToClear = list->nextNodePtr) {
		while (nodeToClear) {
			Node* nodeCopy = nodeToClear->nextNodePtr;
			free(nodeToClear);
			nodeToClear = nodeCopy;
		}
	}
	free(list);
	list = nullptr;
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

cpp_class5::Node* cpp_class5::clone(Node* listToClone) {
	assert(listToClone);
	Node* clonedList = createList(listToClone->val);
	const unsigned int count = getElementCount(listToClone);
	for (unsigned int i = 1;i<count;i++){
		push_back(clonedList,getElementAtIndex(listToClone,i));
	}
	return clonedList;
}

cpp_class5::Node* cpp_class5::getNodeAtIndex(Node* list,const unsigned int index) {
	if (index > getElementCount(list)-1) {
		return nullptr;
	}
	unsigned int indexGoal = index;
	while (indexGoal != 0)
	{
		list = list->nextNodePtr;
		indexGoal--;
	}
	assert(list != nullptr);
	return list;
}

float cpp_class5::getElementAtIndex(Node* list, const unsigned int index) {
	assert(list);
	Node* nodeToRead = getNodeAtIndex(list,index);
	assert(nodeToRead);
	return nodeToRead->val;
}

void cpp_class5::insert(Node*& list,const unsigned int index,const float value) {
	
	assert(list&& index < getElementCount(list));
	Node* nodeToRead = getNodeAtIndex(list, index);
	Node* newNode= reinterpret_cast<Node*>(malloc(sizeof(Node)));
	newNode->val = nodeToRead->val;
	newNode->nextNodePtr = nodeToRead->nextNodePtr;
	nodeToRead->val = value;
	nodeToRead->nextNodePtr = newNode;
}

void cpp_class5::erase(Node*&list,const unsigned int index) {
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
	
	unsigned int occurence = 0;
	while (list!= nullptr)
	{
		if (list->val== num) {
			occurence++;
		}
		list = list->nextNodePtr;
	}
	return occurence;
}

void cpp_class5::eraseAllOccurrences(Node *& list, const float num)
{
	assert(list);
	Node* listCounter = list;
	unsigned int counter = 0;
	while (listCounter!= nullptr)
	{
		if (areEqual(listCounter->val,num)) {
			erase(list,counter);
			listCounter = getNodeAtIndex(list,counter);
			continue;
		}
		counter++;
		listCounter = listCounter->nextNodePtr;
	}
}

void cpp_class5::reverse(Node *& list)
{
	if (getLastNode(list) == list) {
		return;
	}
	Node* listCopy = list;
	Node* nodeBuffer[2] = { nullptr ,nullptr};
	
	nodeBuffer[0] = listCopy->nextNodePtr;
	nodeBuffer[1] = nodeBuffer[0]->nextNodePtr;
	listCopy->nextNodePtr = nullptr;
		
	while (nodeBuffer[0] != nullptr) {
		nodeBuffer[0]->nextNodePtr = listCopy;
		listCopy = nodeBuffer[0];
		nodeBuffer[0] = nodeBuffer[1] ? nodeBuffer[1] : nullptr;
		nodeBuffer[1] = (nodeBuffer[1] && nodeBuffer[1]->nextNodePtr) ? nodeBuffer[1]->nextNodePtr : nullptr;
	}

	list = listCopy;
}
