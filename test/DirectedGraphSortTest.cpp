#include "DirectedGraph.h"
#include "gtest/gtest.h"

TEST(topology_sort, print_test) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    { 0, 1 }, { 0, 3 }, { 1, 2 },
                    { 1, 3 }, { 2, 4 }, {3, 4}
            };

    DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
    graph.printGraph();
}

TEST(topology_sort, test_5_nodes) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    { 0, 1 }, { 0, 3 }, { 1, 2 },
                    { 1, 3 }, { 2, 4 }, {3, 4}
            };

    DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
    auto v = graph.topologySort();
    vector<int> ans1{0, 1, 3, 2, 4,};
    vector<int> ans2{0, 1, 2, 3, 4,};

    ASSERT_TRUE((*v)==ans1 || (*v)==ans2);

    delete v;
}

TEST(topology_sort, test_2_nodes) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    { 1, 0 }
            };

    DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
    auto v = graph.topologySort();
    vector<int> ans{1, 0};

    ASSERT_TRUE((*v)==ans);

    delete v;
}

TEST(topology_sort, test_1_nodes) {
    Edge edges[] = {};

    DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
    auto v = graph.topologySort();

    ASSERT_TRUE((*v).empty());

    delete v;
}

TEST(topology_sort, test_Additional_nodes) {
Edge edges[] =
        {
                // pair (x, y) represents edge from x to y
                { 5, 2 }, { 5, 0 }, { 4, 0 },
                { 4, 1 }, { 2, 3 }, {3, 1}
        };

DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
auto v = graph.topologySort();
vector<int> ans1{5, 4, 2, 3, 1, 0};

ASSERT_TRUE((*v)==ans1);

delete v;
}

TEST(topology_sort, test_7_nodes) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    { 7, 5 }, { 7, 6 }, { 5, 4 },
                    { 5, 2 }, { 6, 4 }, { 6, 3 },
                    { 2, 1 }, { 3, 1 }, { 1, 0 }
            };

    DirectedGraph graph(edges, sizeof(edges) / sizeof(edges[0]));
    graph.printGraph();
    auto v = graph.topologySort();

    /*There are many different results produced by this graph
     * here is some of them. In general, 6, 5's places are
     * reversible, 2,3,4's places are also changeable
     * */

    vector<int> ans1{7, 6, 5, 4, 3, 2, 1, 0}; // my code produces this answer
    vector<int> ans2{7, 6, 5, 4, 2, 3, 1, 0};
    vector<int> ans3{7, 6, 5, 3, 4, 2, 1, 0};
    vector<int> ans4{7, 6, 5, 3, 2, 4, 1, 0};
    vector<int> ans5{7, 6, 5, 2, 4, 3, 1, 0};
    vector<int> ans6{7, 6, 5, 2, 3, 4, 1, 0};
    vector<int> ans7{7, 5, 6, 4, 3, 2, 1, 0};
    vector<int> ans8{7, 5, 6, 4, 2, 3, 1, 0};
    vector<int> ans9{7, 5, 6, 3, 4, 2, 1, 0};
    vector<int> ans10{7, 5, 6, 3, 2, 4, 1, 0};
    vector<int> ans11{7, 5, 6, 2, 4, 3, 1, 0};
    vector<int> ans12{7, 5, 6, 2, 3, 4, 1, 0};

ASSERT_TRUE((*v)==ans1 || (*v)==ans2 || (*v)==ans3 || (*v)==ans4
|| (*v)==ans5 || (*v)==ans6 || (*v)==ans7 || (*v)==ans8
|| (*v)==ans9 || (*v)==ans10 || (*v)==ans11 || (*v)==ans12);

    delete v;
}
