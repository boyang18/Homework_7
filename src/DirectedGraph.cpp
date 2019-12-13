#include "DirectedGraph.h"
#include <iostream>

DirectedGraph::DirectedGraph(Edge *edges, int size) {
    root = edges[0].src;
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
    if (nodes.empty()) {
        return;
    }
    vector<int> vector = nodes[root]->toVector();

    for (int i = 0; i < vector.size(); i++) {
        if (visited.find(vector[i]) == visited.end()) {
            visited.insert(vector[i]);
            topologySort(vector[i], stack, visited);
        }
    }
    stack.push(root);
}

vector<int> *DirectedGraph::topologySort() {
    // homework
    vector<int> *vec = new vector<int>;
    int val = root;
    LinkedStack<int> stack;
    set<int> visited;

    topologySort(val, stack, visited);

    while (!stack.isEmpty()) {
        std::cout << stack.peek() << ", ";
        vec->push_back(stack.peek());
        stack.pop();
    }
    return vec;
}

