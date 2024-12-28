#include <iostream>
#include "node.h"
#include <utility>

using namespace std;

Node::Node(){
    cout<<"Node created";
    g=h=99999;
    f=99999;
    position = make_pair(0, 0);
};

Node::Node(int h,int g,int x,int y,bool expl){
    this->h=h;
    this->g=g;
    this->explored=expl;
    this->f = h+g;

    this->connection=nullptr;
    position=make_pair(x,y);
};

void Node::setF(){
    f=h+g;
};

bool Node::operator == (const Node& other) const {
    if (position.first == other.position.first && position.second==other.position.second)
    {
        return true;
    }else {
        return false;
    }
};

