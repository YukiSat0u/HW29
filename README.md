Задача написать реализацию метода insertIntoMiddle(int value, int pos) для списка мелкогранулярной блокировкой. Часть кода уже написана — сама структура списка взята из юнита про мелкогранулярную блокировку и приведена ниже.

struct Node
{
  int value;
  Node* next;
  std::mutex* node_mutex;
};

class FineGrainedQueue
{
  Node* head;
  std::mutex* queue_mutex;
};

Функция должна вставить узел с переданным значением value в позицию pos. Чтобы не переусложнять реализацию, предполагается следующее:
1. очередь не пустая,
2. вставляется элемент в середину или конец списка, то есть вставку в начало списка не нужно рассматривать,
3. если pos больше длины списка, то нужно вставить элемент в конец списк
