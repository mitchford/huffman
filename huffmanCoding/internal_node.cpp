#include "stdafx.h"
#include "internal_node.h"


internal_node::internal_node(int s, int w, char c)
{
	seq = s;
	weight = w;
	child = c;
}


internal_node::~internal_node()
{
}

char internal_node::getSymbol(){
	// will not have a symbol
	return NULL;
}

void internal_node::incrementWeight(){
	weight++;
}

int internal_node::getWeight(){
	return weight;
}

void internal_node::setWeight(int w){
	weight = w;
}

void internal_node::setRightChild(){
	child = 'r';
}

void internal_node::setLeftChild(){
	child = 'l';
}

char internal_node::whichChild(){
	return child;
}

void internal_node::setParent(){
	parent = 1;
}

int internal_node::checkParent(){
	return parent;
}

void internal_node::setValue(int val){
	value = val;
}

int internal_node::getValue(){
	return value;
}