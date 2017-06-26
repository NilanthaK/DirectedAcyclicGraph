#include "Node.h"

#include <string>
#include <vector>
#include <set>

using namespace std;

class Graph
{
public:
	~Graph()
	{
		for (Node* n : nodes)
			delete n;
	}

	bool AddNode(const string& name, const vector<string>& next_node_names, const vector<string>& prev_node_names)
	{
		vector<Node*> next_nodes = FindNextNodes(next_node_names);


		Node* new_node = new Node(name, next_nodes);

		LinkToPrevNodes(new_node, prev_node_names);

		nodes.push_back(new_node);

		return true;
	}

	vector<Node*> NextNodes(Node* node) const
	{
		return node->NextNodes();
	}

	vector<Node*> PrevNodes(Node* node) const
	{
		vector<Node*> prev_nodes;



		return prev_nodes;
	}

private:
	vector<Node*> FindNextNodes(const vector<string>& next_node_names)
	{
		vector<Node*> next_nodes;

		return next_nodes;
	}

	bool LinkToPrevNodes(Node* new_node, const vector<string>& prev_node_names)
	{
		vector<Node*> prev_nodes = FindPrevNodes(prev_node_names);


		return true;
	}

	vector<Node*> FindPrevNodes(const vector<string>& prev_node_names)
	{
		vector<Node*> prev_nodes;

		return prev_nodes;
	}

	vector<Node*> nodes;
};

class Cursor
{
public:
	Cursor(const Graph& g)
		: g(g)
	{
	}

	vector<Node*> ReadyToProcess()
	{
		vector<Node*> ready_to_process;

		// read lock on processed_nodes and in_process_nodes
		// unlock

		return ready_to_process;
	}

	void AddToProcessed(Node* processed_node)
	{
		// write lock on processed_nodes and in_process_nodes
		in_process_nodes.erase(processed_node);
		processed_nodes.push_back(processed_node);
		// unlock
	}

private:
	vector<Node*> processed_nodes;
	set<Node*> in_process_nodes;
	const Graph& g;
};

int main()
{
	Graph g;

	Cursor c(g);

    return 0;
}

