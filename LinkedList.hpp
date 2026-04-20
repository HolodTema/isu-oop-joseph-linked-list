#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

template<class T>
class LinkedList {
public:
	LinkedList() : size_(0),
	               head_(nullptr) {
	}

	LinkedList(const LinkedList &other) : size_(other.size_) {
		if (other.head_ == nullptr) {
			return;
		}

		head_ = new Node<T>;
		head_->data = other.head_->data;

		Node<T> *otherNode = other.head_->nextNode;
		Node<T> *node = head_;
		while (otherNode != nullptr) {
			node->nextNode = new Node<T>;
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
			Node<T>* node = head_;
			while (node != nullptr) {
				Node<T>* nodeToDelete = node;
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
		Node<T>* node = head_;
		while (node != nullptr) {
			Node<T>* nodeToDelete = node;
			node = node->nextNode;
			delete nodeToDelete;
		}
	}

	size_t getSize() const {
		return size_;
	}

	// to add new element in the beginning of the list
	// Difficulty: O(1)
	void add(const T& element) {
		Node<T>* newNode = new Node<T>();
		newNode->data = element;
		newNode->nextNode = head_;
		head_ = newNode;
	}

	// to add new element after element with some index
	// Difficulty: O(n)
	void add(size_t index, const T& element) {
		if (index >= size_) {
			throw std::runtime_error("Error: index out of bounds.");
		}

		Node<T>* node = head_;
		for (int i = 0; i < index; ++i) {
			node = node->nextNode;
		}

		Node<T>* newNode = new Node<T>;
		newNode->data = element;
		newNode->nextNode = node->nextNode;
		node->nextNode = newNode;
		++size_;
	}


	// Difficulty: O(n)
	void remove(size_t index) {
		if (index >= size_) {
			throw std::runtime_error("Error: index out of bounds.");
		}

		Node<T>* node = head_;
		Node<T>* prevNode = nullptr;
		for (int i = 0; i < index; ++i) {
			prevNode = node;
			node = node->nextNode;
		}

		// after loop above we have
		// node - node to delete
		// prevNode - the node before the node to delete
		if (prevNode != nullptr) {
			prevNode->nextNode = node->nextNode;
		}
		delete node;
	}

private:
	template<class T1>
	struct Node {
	public:
		T1 data;
		Node<T1> *nextNode;
	};

	size_t size_ = 0;
	Node<T> *head_ = nullptr;

	void swap(LinkedList &other) noexcept {
		std::swap(size_, other.size_);
		std::swap(head_, other.head_);
	}
};

#endif //LINKED_LIST_HPP
