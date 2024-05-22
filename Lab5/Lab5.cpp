#include <iostream>
#include <stdexcept>

#include "empty_queue_exception.h"
#include "overflow_queue_exception.h"
#include "Queue.h"

template <typename T>
T GetMax(T* arr, int size)
{
    if (size == 0)
        throw std::invalid_argument("Array cannot be empty");
    T max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Варинат 9
int main(int argc, char* argv[])
{
    try
    {
        Queue<int, 5> queue;
        queue.Enqueue(1);
        queue.Enqueue(2);
        queue.Enqueue(3);
        queue.Enqueue(4);
        queue.Enqueue(5);
        std::cout << queue.Peek() << '\n';
        std::cout << queue.Dequeue() << '\n';
        std::cout << queue.Peek() << '\n';
        std::cout << queue.Dequeue() << '\n';
        std::cout << queue.Dequeue() << '\n';
        std::cout << queue.Dequeue() << '\n';
        std::cout << queue.Dequeue() << '\n';
    }
    catch (const empty_queue_exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const overflow_queue_exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
