#pragma once

#include <string>
#include <vector>

namespace dag
{
	template <class T>
	class Node
	{
	public:
		Node(T pay_load, std::string name, std::vector<Node<T>*> next_nodes)
			: pay_load(pay_load), name(name), next_nodes(next_nodes)
		{
		}

		T PayLoad() const
		{
			return pay_load;
		}

		std::string Name() const
		{
			return name;
		}

		std::vector<Node<T>*> NextNodes() const
		{
			return next_nodes;
		}

	private:
		const T pay_load;
		const std::string name;
		const std::vector<Node*> next_nodes;
	};
}
