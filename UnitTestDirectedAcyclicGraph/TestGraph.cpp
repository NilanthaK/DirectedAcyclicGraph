#include "CppUnitTest.h"
#include "Graph.hpp"

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace dag;

namespace UnitTestDirectedAcyclicGraph
{
	TEST_CLASS(TestGraph)
	{
	public:

		TEST_METHOD(UpdatePrevNodesCacheAndFindStartingNodes)
		{
			const string AddReagent1 = "Add Reagent 1";
			const string AddReagent2 = "Add Reagent 2";
			const string PreheatHeater = "Preheat Heater";
			const string MixReagents = "Mix Reagents";
			const string HeatSample = "Heat Sample";
			const string ExtractSample = "Extract Sample";

			Graph<int> g;

			vector<string> next_node_names, prev_node_names;
			g.AddNode(6, ExtractSample, next_node_names);
			
			next_node_names.push_back(ExtractSample);
			g.AddNode(5, HeatSample, next_node_names);

			next_node_names.clear();
			next_node_names.push_back(HeatSample);
			g.AddNode(4, MixReagents, next_node_names);
			g.AddNode(3, PreheatHeater, next_node_names);

			next_node_names.clear();
			next_node_names.push_back(PreheatHeater);
			next_node_names.push_back(MixReagents);
			Node<int>* expected_second_node = g.AddNode(2, AddReagent2, next_node_names);

			next_node_names.clear();
			next_node_names.push_back(AddReagent2);
			Node<int>* expected_first_node = g.AddNode(1, AddReagent1, next_node_names);
			
			vector<Node<int>*> starting_nodes = g.UpdatePrevNodesCacheAndFindStartingNodes();

			Assert::IsTrue(1 == starting_nodes.size());
			Assert::IsTrue(expected_first_node == starting_nodes[0]);
			
			Assert::IsTrue(AddReagent1 == expected_first_node->Name());
			Assert::IsTrue(1 == expected_first_node->PayLoad());
			Assert::IsTrue(expected_second_node == expected_first_node->NextNodes()[0]);
			
			Assert::IsTrue(g.PrevNodes(expected_second_node)[0] == expected_first_node);
		}
	};
}