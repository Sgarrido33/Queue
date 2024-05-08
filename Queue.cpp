#include <iostream>

using namespace std;


class QueueNode {
public:
    int data;
    QueueNode* next;

    QueueNode(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int data) {
        QueueNode* newNode = new QueueNode(data);
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
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        } else {
            cout << "The queue is empty. Cannot dequeue." << endl;
        }
    }


    bool isEmpty() {
        return front == nullptr;
    }


    int getFront() {
        if (!isEmpty()) {
            return front->data;
        } else {
            cout << "The queue is empty." << endl;
            return -1; // Sentinel value
        }
    }

    int size() {
        int count = 0;
        QueueNode* current = front;
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
        QueueNode* current = other.front;
        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
        return *this;
    }
};

int main() {

    Queue queue;


    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    Queue queue2;
    queue2 = queue;
    queue2.enqueue(30);

    cout << "Front element: " << queue2.getFront() << endl;

    cout << "Front element: " << queue.getFront() << endl;

    queue.dequeue();

    cout << "Front element after dequeue: " << queue.getFront() << endl;

    return 0;
}
