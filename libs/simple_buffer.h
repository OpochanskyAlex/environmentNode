#ifndef APPLICATION_LIBS_SIMPLE_BUFFER_H_
#define APPLICATION_LIBS_SIMPLE_BUFFER_H_

/* Very simple queue
 * These are FIFO queues which discard the new data when full.
 *
 * Queue is empty when in == out.
 * If in != out, then
 *  - items are placed into in before incrementing in
 *  - items are removed from out before incrementing out
 * Queue is full when in == (out-1 + QUEUE_SIZE) % QUEUE_SIZE;
 *
 * The queue will hold QUEUE_ELEMENTS number of items before the
 * calls to QueuePut fail.
 */

/* Queue structure */
#define QUEUE_ELEMENTS 100
#define QUEUE_SIZE (QUEUE_ELEMENTS + 1)
int Queue[QUEUE_SIZE];
int QueueIn, QueueOut;

void QueueInit(void);
int QueuePut(int new);
int QueueGet(int *old);

#endif /* APPLICATION_LIBS_SIMPLE_BUFFER_H_ */
