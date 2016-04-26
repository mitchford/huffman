#pragma once
class node
{
public:
	node();
	~node();
	virtual void incrementWeight() = 0;
	virtual char getSymbol() = 0;
	virtual int getWeight() = 0;
	virtual void setRightChild() = 0;
	virtual void setLeftChild() = 0;
	virtual char whichChild() = 0;
	virtual void setParent() = 0;
	virtual int checkParent() = 0;
	virtual void setWeight(int w) = 0;
	virtual void setValue(int val) = 0;
	virtual int getValue() = 0;
	
protected:
	int weight;
	int seq;
	char symbol;
	char child;
	int parent;
	int w;
	int value;
};

