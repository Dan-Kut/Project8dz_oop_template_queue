#include <iostream>
using namespace std;

template<typename T, int Size>
class Queue {
private:
    T data[Size];    
    int front;       
    int rear;         
    int count;       

public:
    Queue() : front(0), rear(0), count(0) {}


    bool IsEmpty() const {
        return count == 0;
    }

  
    bool IsFull() const {
        return count == Size;
    }

  
    bool Enqueue(const T& value) {
        if (IsFull()) {
            cout << "Queue is full\n";
            return false;
        }
        data[rear] = value;
        rear = (rear + 1) % Size;
        ++count;
        return true;
    }


    bool Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty\n";
            return false;
        }
        front = (front + 1) % Size;
        --count;
        return true;
    }

    
    void Show() const {
        if (IsEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Elements of queue: ";
        for (int i = 0; i < count; ++i) {
            cout << data[(front + i) % Size] << " ";
        }
        cout << "\n";
    }
};