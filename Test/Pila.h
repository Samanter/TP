#pragma once
#include "List.h"

template <typename T, T null = nullptr>
class Pila {
private:
	T* elems;
	int posTop;
	int max;

public:
	Pila(int max) : max(max), elems(new T[max]), posTop(0) {}
	
	~Pila() {
		delete[] elems;
	}

	bool isEmpty() {
		return posTop == 0;
	}

	bool isFull() {
		return posTop == max;
	}

	void push(T elem) {
		if (!isFull()) {
			elems[posTop++] = elem;
		}
	}

	void pop() {
		if (!isEmpty()) {
			--posTop;
		}
	}

	T top() {
		if (!isEmpty()) {
			return elems[posTop - 1];
		}
		return null;
	}
};

