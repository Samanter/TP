#pragma once
#include <functional>

template<typename T, T null = nullptr>
class Cola {
private:
	struct Node;
	typedef std::function<int(T, T)> Compare;

	Node* ini;
	int length, max;
	Compare compare;

public:
	class Iterator {
		int pos;
		Node* aux;

	public:
		Iterator(int pos = 0, Node* aux = nullptr) : pos(pos), aux(aux) {}

		void operator ++() {
			pos++;
			aux = aux->next;
		}

		bool operator != (Iterator x) {
			return pos != x.pos;
		}

		T operator *() {
			return aux->elem;
		}
	};

	Cola(int max) : max(max), ini(nullptr), length(0), compare([](T a, T b) { return a - b; }) {}

	Cola(int max, Compare compare) : max(max), ini(nullptr), length(0), compare(compare) {}

	~Cola() {
		Node* aux = ini;
		while (aux != nullptr) {
			aux = ini;
			ini = ini->next;
			delete aux;
		}
	}

	Iterator begin() {
		return Iterator(0, ini);
	}

	Iterator end() {
		return Iterator(length - 1, nullptr);
	}

	struct Node {
		T elem;
		Node* next;

		Node(T elem = null, Node* next = nullptr) : elem(elem), next(next) {}
	};

	bool isEmpty() {
		return length == 0;
	}

	int size() {
		return length;
	}

	void push(T elem) {
		Node* added = new Node(elem);
		if (added != nullptr) {
			if (isEmpty()) {
				ini = added;
				length++;
			}
			else {
				Node* aux = ini;
				while (aux->next != nullptr) {
					aux = aux->next;
				}
				aux->next = added;
				length++;
				if (length > max) {
					pop();
				}
			}
		}
		
	}

	void pop() {
		if (!isEmpty()) {
			Node* aux = ini;
			ini = ini->next;
			delete aux;
			length--;
		}
	}

	T first() {
		return ini->elem;
	}
};