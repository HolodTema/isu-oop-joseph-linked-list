#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

template<class T>
class LinkedList {
public:
	LinkedList() : size_(0),
	               head_(nullptr) {
	}

	LinkedList(const LinkedList &other) : size_(other.size_),
	                                      head_(nullptr) {
		if (other.head_ == nullptr) {
			return;
		}

		head_ = new Node;
		head_->data = other.head_->data;

		Node *otherNode = other.head_->nextNode;
		Node *node = head_;
		while (otherNode != nullptr) {
			node->nextNode = new Node;
			node->nextNode->data = otherNode->data;

			node = node->nextNode;
			otherNode = otherNode->nextNode;
		}
	}

	LinkedList(LinkedList &&other) noexcept : size_(other.size_),
	                                          head_(other.head_) {
		other.head_ = nullptr;
		other.size_ = 0;
	}

	LinkedList &operator=(const LinkedList &other) {
		if (this != &other) {
			LinkedList copy(other);
			swap(copy);
		}
		return *this;
	}

	LinkedList &operator=(LinkedList &&other) noexcept {
		if (this != &other) {
			// delete all our nodes
			Node *node = head_;
			while (node != nullptr) {
				Node *nodeToDelete = node;
				node = node->nextNode;
				delete nodeToDelete;
			}

			// then move other nodes to our object
			head_ = other.head_;
			size_ = other.size_;

			// and other object is not host to these nodes anymore
			other.head_ = nullptr;
			other.size_ = 0;
		}
		return *this;
	}

	~LinkedList() {
		Node * node = head_;
		while (node != nullptr) {
			Node *nodeToDelete = node;
			node = node->nextNode;
			delete nodeToDelete;
		}
	}

	size_t getSize() const {
		return size_;
	}

	// to add new element in the beginning of the list
	// Difficulty: O(1)
	void add(const T &element) {
		Node *newNode = new Node();
		newNode->data = element;
		newNode->nextNode = head_;
		head_ = newNode;
		++size_;
	}

	// to add new element after element with some index
	// Difficulty: O(n)
	void add(const size_t index, const T &element) {
		if (index >= size_) {
			throw std::runtime_error("Error: index out of bounds.");
		}

		Node *node = head_;
		for (size_t i = 0; i < index; ++i) {
			node = node->nextNode;
		}

		Node *newNode = new Node;
		newNode->data = element;
		newNode->nextNode = node->nextNode;
		node->nextNode = newNode;
		++size_;
	}


	// Difficulty: O(n)
	void remove(const size_t index) {
		if (index >= size_) {
			throw std::runtime_error("Error: index out of bounds.");
		}

		if (index == 0) {
			Node *nodeToDelete = head_;
			head_ = head_->nextNode;
			delete nodeToDelete;
			--size_;
			return;
		}

		Node *node = head_;
		Node *prevNode = nullptr;
		for (size_t i = 0; i < index; ++i) {
			prevNode = node;
			node = node->nextNode;
		}

		// after loop above we have
		// node - node to delete
		// prevNode - the node before the node to delete
		prevNode->nextNode = node->nextNode;
		delete node;
		--size_;
	}

	T get(const size_t index) const {
		if (index >= size_) {
			throw std::runtime_error("Error: index out of bounds.");
		}

		Node *node = head_;
		for (size_t i = 0; i < index; ++i) {
			node = node->nextNode;
		}
		return node->data;
	}

	template<typename T1>
	friend std::ostream &operator<<(std::ostream &, const LinkedList<T1> &);

private:
	struct Node {
	public:
		T data;
		Node *nextNode = nullptr;
	};

	size_t size_ = 0;
	Node *head_ = nullptr;

	void swap(LinkedList &other) noexcept {
		std::swap(size_, other.size_);
		std::swap(head_, other.head_);
	}
};

template<class T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &linkedList) {
	std::ostream::sentry s(os);
	if (!s) {
		return os;
	}

	typename LinkedList<T>::Node *node = linkedList.head_;
	for (size_t i = 0; i < linkedList.size_; ++i) {
		os << node->data << " ";
		node = node->nextNode;
	}
	return os;
}

#endif //LINKED_LIST_HPP
