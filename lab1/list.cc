#include <iostream>
#include "list.h"

List::List() {
	first = nullptr;
}

List::~List() {
	Node* f = first;
	while (f != nullptr) {
		Node* current = f;
		f = f->next;
		delete current;
	}
}

bool List::exists(int d) const {
	Node* f = first;
	while (f != nullptr) {
		if (f->value == d) {
			return true;
		}
		f = f->next;
	}
	return false;
}

int List::size() const {
	Node* f = first;
	int s = 0;
	while (f != nullptr) {
		s++;
		f = f->next;
	}
	return s;
}

// Check if empty, not using size for some performance improvements
bool List::empty() const {
	return first == nullptr;
}

void List::insertFirst(int d) {
	first = new Node(d, first);
}

void List::remove(int d, DeleteFlag df) {
	Node* prev = nullptr;
	Node* f = first;
	while (f != nullptr) {
		switch (df) {
			case DeleteFlag::EQUAL:
				if (f->value == d) {
					prev->next = f->next;
					delete f;
					f = prev;
				}
				break;
			case DeleteFlag::GREATER:
				if (f->value > d) {
					prev->next = f->next;
					delete f;
					f = prev;
				}
				break;
			case DeleteFlag::LESS:
				if (f->value < d) {
					// Modify start of list
					if (prev == nullptr) {
						first = f->next;
						delete f;
						f = first;
						continue;
					}
					// Modify in middle
					prev->next = f->next;
					delete f;
					f = prev;
				}
				break;
		}

		prev = f;
		f = f->next;
	}
}

void List::print() const {
	Node* f = first;
	while (f != nullptr) {
		std::cout << f->value << " ";
		f = f->next;
	}
}

