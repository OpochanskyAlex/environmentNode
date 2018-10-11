#include "simple_buffer.h"

void QueueInit(void){
	QueueIn = QueueOut = 0;
}

int QueuePut(int new)
{
    if(QueueIn == (( QueueOut - 1 + QUEUE_SIZE) % QUEUE_SIZE))
    {
        return -1; /* Queue Full*/
    }

    Queue[QueueIn] = new;

    QueueIn = (QueueIn + 1) % QUEUE_SIZE;

    return 0; // No errors
}

int QueueGet(int *old)
{
    if(QueueIn == QueueOut)
    {
        return -1; /* Queue Empty - nothing to get*/
    }

    *old = Queue[QueueOut];

    QueueOut = (QueueOut + 1) % QUEUE_SIZE;

    return 0; // No errors
}
