#pragma once
#include <vector>
#include <utility>
using namespace std;
class Node{

    public:
        std::pair<int,int> position;
        bool explored;
        vector<Node*> neighbours;
        int h;
        int g;
        int f;
        Node* connection;

        bool operator==(const Node& other) const;
        
        Node();
        Node(int h,int g,int x,int y,bool expl=true);

        void setF();


};

