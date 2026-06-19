#pragma once

#include <stdexcept>
#include "List.h"
#include <iostream>
#include "DNode.h"
//Sigue apuntando al anterior
using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class DLinkedList : public List<E> {
private:
	DNode<E>* head;
	DNode<E>* tail;
	DNode<E>* current;
	int size;

public:
	DLinkedList() {
		head = current = new DNode<E>(nullptr, nullptr);
		head->next = tail = new DNode<E>(nullptr, head);
		size = 0;
	}

	~DLinkedList() {
		clear();
		delete head;
		delete tail;
	}

	void insert(E element) {
		current->next = current->next->previous
			= new DNode<E>(element, current->next, current);
		size++;
	}

	void append(E element) {
		tail->previous = tail->previous->next
			= new DNode<E>(element, tail, tail->previous);
		size++;
	}

	void set_element(E element) {
		if (size == 0)
			throw runtime_error("List is empty");
		if (current->next == tail)
			throw runtime_error("No current element");
		current->next->element = element;
	}

	E get_Element() {
		if (size == 0)
			throw runtime_error("List is empty");
		if (current->next == tail)
			throw runtime_error("No current element");
		return current->next->element;
	}

	E remove() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (current->next == tail)
			throw runtime_error("No current element.");
		E result = current->next->element;
		current->next = current->next->next;
		delete current->next->previous;
		current->next->previous = current;
		size--;
		return result;
	}

	void clear() {
		current = head->next;
		while (head->next != tail) {
			head->next = current->next;
			delete current;
			current = head->next;
		}
		current = head;
		size = 0;
	}

	void go_to_start() {
		current = head;
	}

	void go_to_end() {
		current = tail->previous;
	}

	void go_to_pos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of bounds");
		current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;
	}

	void next() {
		if (current->next != tail)
			current = current->next;
	}

	void previous() {
		if (current != head)
			current = current->previous;
	}

	bool at_start() {
		return current == head;
	}

	bool at_end() {
		return current->next == tail;
	}

	int get_pos() {
		DNode <E>* temp = head;
		int pos = 0;
		while (temp != current) {
			temp = temp->next;
			pos++;
		}
		return pos;
	}

	int get_size() {
		return size;
	}

	void print() {
		DNode <E>* temp = head->next;
		cout << "[";
		for (int i = size - 1; i >= 0; i--) {
			cout << temp->element;
			if (temp == current->next)
				cout << "*";
			if (i != 0)
				cout << ", ";
			temp = temp->next;
		}
		cout << "]" << endl;
	}
};

