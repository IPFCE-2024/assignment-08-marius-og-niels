#include "exercise3.h"
#include <stdio.h>
#include <assert.h>

int main() {
    queue *test;
    initialize(test);
    assert(test->front==NULL);
    
    int x = 10;
    int y = 0;
    enqueue(test, x);
    y = dequeue(test);
    assert(y==x);
    

    int x0 = 5;
    int x1 = 7;
    int y0 = 0;
    int y1 = 0;

    queue *test2 = test;
    enqueue(test,x0);
    enqueue(test,x1);
    print_queue(test);
    y0 = dequeue(test);
    y1 = dequeue(test);
    assert(y0 == x0 && y1 == x1 && test == test2);
    return 0;
}
