#ifndef NODE_HPP
#define NODE_HPP
#include "matrices.hpp"

class node{
private:
	matrices* data;
	node  *next;
public:
	node (matrices* d);
	node *getNext();
	matrices* getData();
	void setNext(node*);
};

node::node (matrices* d) {
	this->data = d;
	next = nullptr;
}

node* node::getNext (){
	return next;
}

matrices* node::getData (){
	return data;
}

void node::setNext(node *next){
	this->next = next;	
};

#endif //NODE_HPP