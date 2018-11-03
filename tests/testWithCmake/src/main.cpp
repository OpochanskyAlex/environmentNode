#include <iostream>
#include "simple_buffer.h"
int main() {
    int k = 0;
    QueueInit();
    QueuePut(25);
    QueuePut(65);
    QueuePut(78);
    QueueGet(&k);
    std::cout << "Hello, World!" << k <<   std::endl;
    return 0;
}