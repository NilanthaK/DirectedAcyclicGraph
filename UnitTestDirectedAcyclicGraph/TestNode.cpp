#include "CppUnitTest.h"

#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDirectedAcyclicGraph
{		
	TEST_CLASS(TestNode)
	{
	public:
		
		TEST_METHOD(LinkNewNextNode)
		{
			vector<Node*> empty_next_nodes;
			Node node1("Add Reagent 1", empty_next_nodes);
			Node node2("Add Reagent 2", empty_next_nodes);

			node1.LinkNewNextNode(&node2);
			vector<Node*> next_nodes = node1.NextNodes();

			Assert::IsTrue(&node2 == next_nodes[0]);
		}

	};
}