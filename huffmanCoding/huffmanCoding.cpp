// huffmanCoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "node.h"
#include "leaf_node.h"
#include "internal_node.h"
using namespace std;

int main()
{

	string s;
	int seq = 10000;
	int weight;
	int topWeight;
	vector<node*> nodes;

	cout << "enter string to compress:" << endl;
	getline(cin, s);
	const char* symbols = s.c_str();

	internal_node* root = new internal_node(0, 0, 'l');
	nodes.push_back(root);

	topWeight = nodes.at(0)->getWeight;
	
	while (*symbols != '\0')
	{
		for (int i = 0; i < nodes.size(); i++){
			//search if node already exists
			if (nodes.at(i)->getSymbol() == *symbols)
			{
				//Add weight to node object for letter. Follow tree up and keep incrementing weight till root.
				nodes.at(i)->incrementWeight();
				
			} else {
				//if node is 'nyt', create 2 new nodes, one 'nyt' node and one leaf node for character, add leaf node to vector.
				if (nodes.at(i)->getWeight() == 0)
				{
					nodes.at(i)->incrementWeight();
					nodes.at(i)->setParent();
					leaf_node* symbol = new leaf_node(seq, 1, *symbols, 'r');
					seq--;
					internal_node* branch = new internal_node(seq, 0, 'l');
					seq--;
					branch->setLeftChild();
					symbol->setRightChild();
					nodes.push_back(symbol);
					nodes.push_back(branch);
					
				}
			}
			//check if current node is a parent
			if (nodes.at(i)->checkParent() == 1)
			{
				//set parent weight to weight of children
				weight = nodes.at(i + 1)->getWeight() + 1;
				nodes.at(i)->setWeight(weight);
			}

			if (nodes.at(i)->getWeight > topWeight)
			{
				topWeight = nodes.at(i)->getWeight();
				if (topWeight == nodes.at(i)->getWeight())
				{
					 //swap values in the vector so it is ordered ready for tree to print.
					iter_swap(nodes.begin() + 1, nodes.begin() + (i-1));
					if(nodes.at(i)->whichChild() == 'l')
					{
						nodes.at(i)->setRightChild();
					} 
					else if (nodes.at(i)->whichChild() == 'r')
					{
						nodes.at(i)->setLeftChild();
					}
				}
			}

			//asign 1 or 0 depending on which side of the tree the node is
			nodes.at(0)->incrementWeight();
			if (nodes.at(i)->whichChild() == 'r')
			{
				nodes.at(i)->setValue(1);
			} else {
				nodes.at(i)->setValue(0);
			}
		}

		
		*symbols++;
	}

	//write to file
	ofstream myfile;
	myfile.open ("tree.txt");
	for (int i = 0; i < nodes.size(); i++){
	myfile << nodes.at(i);
	}
	myfile.close();
	

	return 0;
}

