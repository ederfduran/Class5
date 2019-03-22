#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace cpp_class5 {

	struct Node
	{
		float val=0;
		Node * nextNodePtr = nullptr;
	};

	Node* createList(const float val);
	Node*& getLastNode(Node*& list);
	void push_back(Node * list, const float val);
	void pop_back(Node* & node);
	void clear(Node *& node);
	unsigned int getElementCount(Node* node);
	Node* clone(Node* nodeToClone);
	Node* getNodeAtIndex(Node* list, unsigned int index);
	float getElementAtIndex(Node* node,unsigned int index);
	void insert(Node *& list,unsigned int index, float value);
	void erase(Node*& list, unsigned int index);
	bool areEqual(const float a, const float b);
	unsigned int getOccurrenceCount(Node * list, const float num);
	void eraseAllOccurrences(Node*& list, const float num);
	void reverse(Node *& list);
}

#endif // !LINKED_LIST_H
