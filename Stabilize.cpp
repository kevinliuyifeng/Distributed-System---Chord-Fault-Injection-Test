//
//  Stabilize.cpp
//  Chord
//
//  Created by YIFENG LIU on 2016/12/4.
//
//

#include "Stabilize.hpp"
include <iostream>
#include <vector>
#include <algorithm>
#include "stdio.h"
using namespace std;

struct Node{
    int val;
    Node *pre;
    Node *next;
    void join(Node *head);
    Node* sta();
};

void Node::join(Node *head){
    Node *tmp = head;
    while(tmp->val < this->val){
        tmp = tmp->next;
    }
    tmp->pre = this;
}

Node* Node::sta(){
    return this->next->pre;
}

int main()
{
    Node *node_list = new Node();
    node_list->val=8;
    node_list->pre = NULL;
    node_list->next = NULL;
    
    Node *m = new Node();
    m->val=21;
    m->pre = node_list;
    m->next = NULL;
    
    node_list->next = m;
    
    Node *new_first = new Node();
    new_first->val=12;
    new_first->pre = NULL;
    new_first->next = NULL;
    new_first->join(node_list);
    Node *res = node_list->sta();
    printf("%d\n",res->val);
    
    return 0;
}
