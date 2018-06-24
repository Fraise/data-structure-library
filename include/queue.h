#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

typedef struct queue_node
{
    void *value;
    struct queue_node *previous;
} queue_node_t;


/* The queue is defined like this : start -> |  most  recent node <- ... <- least recent node | <- end*/

typedef struct queue
{
    queue_node_t *start;
    queue_node_t *end;
} queue_t;

queue_t* queue_init();
void queue_delete(queue_t *queue);
void queue_node_create(queue_node_t *new_node, void *data_ptr);
int queue_add(queue_node_t *added_node, queue_t **queue);
int queue_remove(queue_node_t *removed_node, queue_t **queue);
int queue_peek(queue_node_t *peeked_node, queue_t *queue);

#endif /* QUEUE_H */