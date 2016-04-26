#pragma once
#include "node.h"
class internal_node :
	public node
{
public:
	internal_node(int s, int w, char c);
	~internal_node();
	char getSymbol();
	void setRightChild();
	void setLeftChild();
	void incrementWeight();
	char whichChild();
	void setParent();
	int getWeight();
	int checkParent();
	void setWeight(int w);
	void setValue(int val);
	int getValue();
};

