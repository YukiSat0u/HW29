#pragma once
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

struct Node
{
	int value;
	Node* next;
	std::mutex* node_mutex;
};

class FineGrainedQueue
{
public:
	Node* head;

	FineGrainedQueue()
	{
		head = nullptr;
	}

	void insertIntoMiddle(int value, int pos);

private:
	std::mutex queue_mutex;
};
