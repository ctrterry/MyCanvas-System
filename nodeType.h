#pragma once

using namespace std;

template <class Type>
struct NodeType {
    Type info;
    NodeType<Type>* next;   // link to the next node
    NodeType<Type>* back;   // link to the previous node
};

