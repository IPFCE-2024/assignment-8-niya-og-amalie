#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

int main() {
    {
    // Opgave 3 tests
    queue q;
    initialize(&q);
    
    // Test 1: After init, queue must be empty
    assert(empty(&q));
    assert(q.front == NULL);
    assert(q.rear == NULL);
    assert(q.size == 0);
    
    // Test 2: Enqueue and dequeue must return the same value
    int x = 10;
    enqueue(&q, x);
    int y = dequeue(&q);
    assert(empty(&q));
    assert(q.front == NULL);
    assert(q.rear == NULL);
    assert(q.size == 0);
    assert(x == y);
    
    // Test 3: Enqueue multiple elements and ensure they dequeue in the same order
    int x0 = 20, x1 = 30;
    enqueue(&q, x0);
    enqueue(&q, x1);
    int y0 = dequeue(&q);
    int y1 = dequeue(&q);
    assert(empty(&q));
    assert(q.front == NULL);
    assert(q.rear == NULL);
    assert(q.size == 0);
    assert(x0 == y0);
    assert(x1 == y1);
    
    printf("All tests passed!\n");
    return 0;

}