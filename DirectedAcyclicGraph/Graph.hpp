#pragma once

#include "Node.hpp"

#include <map>
#include <string>
#include <vector>

namespace dag
{
	template <class T>
	class Graph
	{
	public:
		~Graph()
		{
			for (Node<T>* n : nodes)
				delete n;
		}

		Node<T>* AddNode(T pay_load, std::string name, std::vector<std::string> next_node_names)
		{
			std::vector<Node<T>*> next_nodes = FindNextNodes(next_node_names);

			Node<T>* new_node = new Node<T>(pay_load, name, next_nodes);
			nodes.push_back(new_node);
			return new_node;
		}

		std::vector<Node<T>*> NextNodes(Node<T>* node) const
		{
			return node->NextNodes();
		}

		// UpdatePrevNodesCacheAndFindStartingNodes() must be called before this
		// A cache valid flag may be used to ensure calling UpdatePrevNodesCacheAndFindStartingNodes() at the start
		std::vector<Node<T>*> PrevNodes(Node<T>* node) const
		{
			auto temp = prev_nodes_cache;
			return temp[node];
		}

		std::vector<Node<T>*> UpdatePrevNodesCacheAndFindStartingNodes()
		{
			std::vector<Node<T>*> starting_nodes;

			prev_nodes_cache.clear();
			for (Node<T>* n : nodes)
			{
				std::vector<Node<T>*> prev_nodes;
				for (Node<T>* p : nodes)
				{
					std::vector<Node<T>*> p_next_nodes = p->NextNodes();
					if (std::find(p_next_nodes.begin(), p_next_nodes.end(), n) != p_next_nodes.end())
						prev_nodes.push_back(p);
				}

				prev_nodes_cache[n] = prev_nodes;

				if (prev_nodes.size() == 0)
					starting_nodes.push_back(n);
			}

			return starting_nodes;
		}

	private:
		std::vector<Node<T>*> FindNextNodes(std::vector<std::string> next_node_names)
		{
			std::vector<Node<T>*> next_nodes;

			for (Node<T>* n : nodes)
			{
				if (std::find(next_node_names.begin(), next_node_names.end(), n->Name()) != next_node_names.end())
					next_nodes.push_back(n);
			}

			return next_nodes;
		}

		std::vector<Node<T>*> nodes;
		std::map<Node<T>*, std::vector<Node<T>*>> prev_nodes_cache;
	};
}