#include "FineGrainedQueue.h"

void FineGrainedQueue::insertIntoMiddle(int value, int pos)
{
	// Создаем новый узел
	Node* newNode = new Node;
	newNode->value = value;
	newNode->next = nullptr;
	newNode->node_mutex = new std::mutex;

	// Захватываем мьютекс очереди
	queue_mutex.lock();

	// Идем по списку, чтобы найти место для вставки
	Node* curr = head;
	int currPos = 1;
	while (currPos < pos && curr->next != nullptr) {
		curr = curr->next;
		currPos++;
	}

	// Если достигли конца списка, вставляем новый узел в конец
	if (curr->next == nullptr) {
		curr->next = newNode;
	}
	else {
		// Иначе, вставляем новый узел в середину списка
		Node* nextNode = curr->next;
		curr->next = newNode;
		newNode->next = nextNode;
	}

	// Освобождаем мьютекс очереди
	queue_mutex.unlock();
}
