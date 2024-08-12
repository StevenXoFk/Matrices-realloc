#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"

class list{
private:
	int count;
	node *first;
public:
	list (){
		count = 0;
		first = nullptr;
	}
	void insert(matrices* data){
		node *n = new node (data);
		if (count == 0){
			first = n;
		}
		else {
			node *t = first;
			while (t->getNext() != nullptr)
				t = t->getNext ();
			t->setNext (n);		
		}
		count++;		
	}
	node *remove (matrices* data) {
		node *s = search(data);
		if (s == nullptr) // si no encuentra no hace nada
			return nullptr;
		
		if (s == first) { // busca el primero
			first = s->getNext();
			s->setNext(nullptr);
			
		} else { //otros
			node *prev = first;
			
			while(prev->getNext() != s)
				prev = prev->getNext();
			prev->setNext(s->getNext());
		}
		
		--count;
		s->setNext(nullptr);
		return s; // retorna el nodo borrado
	}
	void print(){
		node *t = first;
		while (t != nullptr){

			std::cout << t ->getData() << "@" << t << std::endl;
			t = t->getNext();
			}
	}
	node *search (matrices* data) {
		node *t = first;
		while(t != nullptr) {
			if (t->getData() == data)
				return t;
			t = t->getNext();
		}
		return nullptr;
	}

	node *indices(int indice) {
		if (indice >= count) {
			throw std::out_of_range("Fuera de rango");
		}
		node *t = first;

		for (int i = 0; i < indice; i++) {
			t = t->getNext();
		}
		return t;
	}

	int len() {
		return count;
	}
	void sort();
};
#endif	//LIST_HPP