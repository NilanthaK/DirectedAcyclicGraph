#include "CppUnitTest.h"
#include "Node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace dag;

namespace UnitTestDirectedAcyclicGraph
{		
	TEST_CLASS(TestNode)
	{
	public:
		
		TEST_METHOD(NextNodes)
		{
			const string AddReagent1 = "Add Reagent 1";
			const string AddReagent2 = "Add Reagent 2";

			vector<Node<int>*> next_nodes;
			Node<int> node2(2, AddReagent2, next_nodes);

			next_nodes.push_back(&node2);
			Node<int> node1(1, AddReagent1, next_nodes);

			next_nodes = node1.NextNodes();

			Assert::IsTrue(1 == next_nodes.size());
			Assert::IsTrue(&node2 == next_nodes[0]);

			Assert::IsTrue(AddReagent1 == node1.Name());
			Assert::IsTrue(1 == node1.PayLoad());
		}

	};
}