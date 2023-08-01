#include "FineGrainedQueue.h"

void printQueue(FineGrainedQueue& queue)
{
	Node* curr = queue.head->next;
	while (curr != nullptr) {
		std::cout << curr->value << " ";
		curr = curr->next;
	}
	std::cout << std::endl;
}

void testInsertIntoMiddle()
{
	FineGrainedQueue queue;
	queue.head = new Node;
	queue.head->next = nullptr;

	// Вставляем несколько элементов
	queue.insertIntoMiddle(1, 1);
	queue.insertIntoMiddle(3, 2);
	queue.insertIntoMiddle(5, 3);

	std::cout << "Queue after initial insertions: ";
	printQueue(queue); // Ожидаемый вывод: 1 3 5

	// Вставляем новый элемент в середину списка
	std::thread t1([&queue]() { queue.insertIntoMiddle(2, 2); });
	t1.join();

	std::cout << "Queue after inserting 2: ";
	printQueue(queue); // Ожидаемый вывод: 1 2 3 5

	// Вставляем новый элемент в конец списка
	std::thread t2([&queue]() { queue.insertIntoMiddle(7, 5); });
	t2.join();

	std::cout << "Queue after inserting 7: ";
	printQueue(queue); // Ожидаемый вывод: 1 2 3 5 7
}

int main()
{
	testInsertIntoMiddle();

	return 0;
}
