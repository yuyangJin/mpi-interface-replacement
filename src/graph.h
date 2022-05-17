#include <iostream>
#include <vector>
#include <string>

int32_t cur_id = 0;

class Node;
class Edge;


class Node {
private:
    int32_t _id;
    std::string _name;
    std::vector<Edge*> _in_edges;
    std::vector<Edge*> _out_edges;

public:
    Node (std::string name): _name(name) {
        _id = cur_id++;
    }

    const std::string& getName() {
        return _name;
    }
    std::vector<Edge*>& getInEdges() {
        return _in_edges;
    }
    std::vector<Edge*>& getOutEdges() {
        return _out_edges;
    }
    bool addInEdge(Edge* e) {
        _in_edges.push_back(e);
        return true;
    }
    bool addOutEdge(Edge* e) {
        _out_edges.push_back(e);
        return true;
    }
};

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
        return true;
    }
    bool setDestNode(Node* dest_node) {
        _dest = dest_node;
        return true;
    }
    
};



class Graph {
private:
    std::string _name;
    std::vector<Node*> _nodelist;
    std::vector<Edge*> _edgelist;

public:
    Graph(std::string name): _name(name) {}

    Node* addNode(std::string node_name) {
        Node* n = new Node(node_name);
        _nodelist.push_back(n);
        return n;
    }
    Edge* addEdge(Node* src, Node* dest) {
        // Check whether src and dest exist
        if (!src || !dest) {
            std::cout << "src or dest does not exist!" << std::endl;
            return nullptr;
        }
        Edge* e = new Edge(src, dest);
        _edgelist.push_back(e);

        src->addOutEdge(e);
        dest->addInEdge(e);
        return e;
    }

};