#pragma once

#include "Graph.hpp"

#include <set>
#include <vector>

namespace dag
{
	template <class T>
	class Cursor
	{
	public:
		Cursor(const Graph<T>& g)
			: g(g)
		{
		}

		std::vector<Node<T>*> ReadyToProcess()
		{
			std::vector<Node<T>*> ready_to_process;

			// read lock on processed_nodes and in_process_nodes
			// unlock

			return ready_to_process;
		}

		void AddToProcessed(Node<T>* processed_node)
		{
			// write lock on processed_nodes and in_process_nodes
			in_process_nodes.erase(processed_node);
			processed_nodes.push_back(processed_node);
			// unlock
		}

	private:
		std::vector<Node<T>*> processed_nodes;
		std::set<Node<T>*> in_process_nodes;
		const Graph<T>& g;
	};

}