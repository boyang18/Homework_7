#include "DirectedGraph.h"
#include <iostream>

DirectedGraph::DirectedGraph(Edge *edges, int size) {
    for (int i = 0; i < size; i++) {
        int src = edges[i].src, dest = edges[i].dest;
        if (nodes.count(src) == 0) {
            nodes[src] = new SingleLinkedList<int>();
        }
        nodes[src]->add(dest);
        if (nodes.count(dest) == 0) {
            nodes[dest] = new SingleLinkedList<int>();
        }
    }
}

DirectedGraph::~DirectedGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        delete (*it).second;
    }
}

void DirectedGraph::printGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        printf("node(%d) has edges: ", (*it).first);
        for (auto itl = (*it).second->begin(); itl != (*it).second->end(); itl++) {
            printf("%d ", (*itl));
        }
        printf("\n");
    }
}

void DirectedGraph::topologySort(int root, LinkedStack<int> &stack, set<int> &visited) {
    visited.insert(root);
    //https://iq.opengenus.org/topological-sorting-dfs/
    //https://www.geeksforgeeks.org/topological-sorting/

    for (auto it = nodes[root]->begin(); it != nodes[root]->end(); it++) {
        if (!(visited.find((*it)) != visited.end())) {
            topologySort((*it), stack, visited);
        }
    }
    //put result on stack
    stack.push(root);
}

vector<int> *DirectedGraph::topologySort() {
    // homework
    //https://www.geeksforgeeks.org/topological-sorting/
    vector<int> *vec = new vector<int>;
    LinkedStack<int> stack;
    set<int> visited;
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        if (!(visited.find((*it).first) != visited.end())) {
            topologySort((*it).first, stack, visited);
        }
    }

    while (!stack.isEmpty()) {
        std::cout << stack.peek() << " ";
        vec->push_back(stack.peek());
        stack.pop();
    }
    return vec;
}

