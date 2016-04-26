#pragma once
#include "node.h"
class leaf_node :
	public node
{
public:
	char getSymbol();
	void incrementWeight();
	int getWeight();
	void setRightChild();
	void setLeftChild();
	char whichChild();
	void setParent();
	int checkParent();
	void setWeight(int w);
	void setValue(int val);
	int getValue();
	leaf_node(int s, int w, char sym, char c);
	~leaf_node();
};

