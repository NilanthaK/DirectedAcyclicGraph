#pragma once

#include <string>
#include <vector>

using namespace std;

class Node
{
public:
	Node(string name, vector<Node*> next_nodes);

	void LinkNewNextNode(Node* new_node);

	vector<Node*> NextNodes() const;

	string Name() const;

private:
	string name;
	vector<Node*> next_nodes;
};
