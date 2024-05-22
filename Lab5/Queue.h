#pragma once

template <typename T, int N>
class Queue
{
    T* data;
    int head;
    int tail;
    int count;
public:
    Queue() : head(0), tail(-1), count(0)
    {
        data = new T[N];
    }

    void Enqueue(const T& value)
    {
        if (IsFull())
            throw std::runtime_error("Queue is full.");
        tail = (tail + 1) % N;
        data[tail] = value;
        count++;
    }

    T Dequeue()
    {
        if (IsEmpty())
            throw std::runtime_error("Queue is empty.");
        T val = data[head];
        head = (head + 1) % N;
        count--;
        return val;
    }

    T Peek()
    {
        if (IsEmpty())
            throw std::runtime_error("Queue is empty.");
        return data[head];
    }

    bool IsEmpty()
    {
        return count == 0;
    }

    bool IsFull()
    {
        return count == N;
    }

    ~Queue()
    {
        delete[] data;
    }
};
