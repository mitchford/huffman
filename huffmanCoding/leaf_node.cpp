#include "stdafx.h"
#include "leaf_node.h"


leaf_node::leaf_node(int s, int w, char sym, char c)
{
	seq = s;
	weight = w;
	symbol = sym;
	child = c;
}

leaf_node::~leaf_node()
{
}

char leaf_node::getSymbol(){
	return symbol;
}

void leaf_node::incrementWeight(){
	weight++;
}

int leaf_node::getWeight(){
	return weight;
}

void leaf_node::setWeight(int w){
	weight = w;
}

void leaf_node::setRightChild(){
	child = 'r';
}

void leaf_node::setLeftChild(){
	child = 'l';
}

char leaf_node::whichChild(){
	return child;
}

void leaf_node::setParent(){
	parent = 1;
}

int leaf_node::checkParent(){
	return parent;
}

void leaf_node::setValue(int val){
	value = val;
}

int leaf_node::getValue(){
	return value;
}