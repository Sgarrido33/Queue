#include <iostream>

using namespace std;

template <typename T>
class QueueNode {
public:
    T data;
    QueueNode* next;

    QueueNode(T d) : data(d), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    QueueNode<T>* front;
    QueueNode<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        clear();
    }

    void enqueue(T data) {
        QueueNode<T>* newNode = new QueueNode<T>(data);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            QueueNode<T>* temp = front;
            front = front->next;
            delete temp;
        } else {
            std::cout << "The queue is empty. Cannot dequeue." << std::endl;
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    T getFront() const {
        if (!isEmpty()) {
            return front->data;
        } else {
            std::cout << "The queue is empty." << std::endl;
            return T(); // Sentinel value
        }
    }

    int size() const {
        int count = 0;
        QueueNode<T>* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    Queue& operator=(const Queue& other) {
        if (this == &other) {
            return *this;
        }
        clear(); // Limpiar la cola actual
        QueueNode<T>* current = other.front;
        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
        return *this;
    }
};
int main() {
    Queue<int> myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Size of the queue: " << myQueue.size() << std::endl;

    std::cout << "Front element: " << myQueue.getFront() << std::endl;
    myQueue.dequeue();

    std::cout << "Front element after dequeue: " << myQueue.getFront() << std::endl;

    if (myQueue.isEmpty()) {
        std::cout << "The queue is empty." << std::endl;
    } else {
        std::cout << "The queue is not empty." << std::endl;
    }

    myQueue.clear();

    if (myQueue.isEmpty()) {
        std::cout << "The queue is empty after clearing." << std::endl;
    } else {
        std::cout << "The queue is not empty after clearing." << std::endl;
    }

    return 0;
}
