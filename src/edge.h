#ifndef _EDGE_H
#define _EDGE_H

#include <iostream>
#include <vector>
#include <string>

extern class Node;

class Edge {
private:
    int32_t _id;
    Node* _src;
    Node* _dest;    

public:
    Edge(Node* src, Node* dest):
        _src(src), _dest(dest) {}
    Node* getSrcNode() {
        return _src;
    }
    Node* getDestNode() {
        return _dest;
    }
    bool setSrcNode(Node* src_node) {
        _src = src_node;
    }
    bool setDestNode(Node* dest_node) {
        _dest = dest_node;
    }
    
};

#endif