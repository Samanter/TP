#pragma once
#include <functional>

template <typename T, T null = nullptr>
class List {
private:
	struct Node;
	typedef std::function<int(T, T)> Compare;

	Node* ini;
	int length;
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

		void operator --() {
			pos--;
			aux = aux->prev;
		}

		bool operator != (Iterator x) {
			return pos != x.pos;
		}

		T operator *() {
			return aux->elem;
		}
	};
	
	List() : ini(nullptr), length(0), compare([](T a, T b) { return a - b; }) {}

	List(Compare compare) : ini(nullptr), length(0), compare(compare) {}

	~List() {
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
		Node* prev;

		Node(T elem = null, Node* next = nullptr, Node* prev = nullptr) : elem(elem), next(next), prev(prev) {}
	};

	int size() {
		return length;
	}

	bool isEmpty() {
		return length == 0;
	}

	void addFirst(T a) {
		Node* added = new Node(a, ini);
		Node* aux = ini;
		if (added != nullptr) {
			ini = added;
			added->next = aux;
			if (aux != nullptr) {
				aux->prev = ini;
			}
			length++;
		}
	}

	void addPos(T a, int pos) {
		if (pos == 0) {
			addFirst(a);
		}
		if (pos == length - 1) {
			addLast(a);
		}
		if (pos < 0 || pos >= length) {
			return;
		}

		Node* added = new Node(a);
		if (added != nullptr) {
			Node* aux = ini;
			for (int i = 0; i < pos - 1; i++) {
				aux = aux->next;
			}
			added->next = aux->next;
			added->prev = aux;
			aux->next->prev = added;
			aux->next = added;
			length++;
		}
	}

	void addLast(T a) {
		if (isEmpty()) {
			addFirst(a);
		}
		else {
			Node* added = new Node(a);
			if (added != nullptr) {
				Node* aux = ini;
				while (aux->next != nullptr) {
					aux = aux->next;
				}
				aux->next = added;
				added->prev = aux;
				length++;
			}
		}
	}

	void setFirst(T a) {
		ini->elem = a;
	}

	void setPos(T a, int pos) {
		Node* aux = ini;
		for (int i = 0; i < pos; i++) {
			aux = aux->next;
		}
		aux->elem = a;
	}

	void setLast(T a) {
		Node* aux = ini;
		while (aux->next != nullptr) {
			aux = aux->next;
		}
		aux->elem = a;
	}

	void deleteFirst() {
		Node* aux = ini;
		ini = ini->next;
		ini->prev = nullptr;
		delete aux;
		length--;
	}

	void deletePos(int pos) {
		if (pos == 0) {
			deleteFirst();
		}
		if (pos == length - 1) {
			deleteLast();
		}
		if (pos < 0 || pos >= length) {
			return;
		}

		Node* aux = ini;
		for (int i = 0; i < pos - 1; i++) {
			aux = aux->next;
		}
		Node* aux2 = aux->next;
		aux->next = aux2->next;
		aux2->next->prev = aux;
		delete aux2;
		length--;
	}

	void deleteLast() {
		Node* aux = ini;
		for (int i = 0; i < length - 1; i++) {
			aux = aux->next;
		}
		Node* aux2 = aux->next;
		aux->next = nullptr;
		delete aux2;
		length--;
	}

	T getFirst() {
		return ini->elem;
	}

	T getPos(int pos) {
		if (pos == 0) {
			return getFirst();
		}
		if (pos == length - 1) {
			return getLast();
		}
		if (pos < 0 || pos >= length) {
			return null;
		}

		Node* aux = ini;
		for (int i = 0; i < pos; i++) {
			aux = aux->next;
		}
		return aux->elem;
	}

	T getLast() {
		Node* aux = ini;
		while (aux->next != nullptr) {
			aux = aux->next;
		}
		return aux->elem;
	}

	T Find(T a) {
		Node* aux = ini;
		while (aux != nullptr) {
			if (compare(aux->elem, a) == 0) {
				return aux->elem;
			}
			aux = aux->next;
		}
		return null;
	}

	void Organize(Compare compare) {
		for (int i = 0; i < size() - 1; i++) {
			for (int j = 0; j < size() - 1 - i; j++) {
				if (compare(getPos(j), getPos(j + 1)) > 0) {
					T aux = getPos(j);
					setPos(getPos(j + 1), j);
					setPos(aux, j + 1);
				}
			}
		}
	}
};