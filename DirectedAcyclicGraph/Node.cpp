#include "Node.h"

Node::Node(string name, vector<Node*> next_nodes)
	: name(name), next_nodes(next_nodes)
{
}

void Node::LinkNewNextNode(Node* new_node)
{
	next_nodes.push_back(new_node);
}

vector<Node*> Node::NextNodes() const
{
	return next_nodes;
}

string Node::Name() const
{
	return name;
}
