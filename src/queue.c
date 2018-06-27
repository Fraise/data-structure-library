#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

/*
 *  This function initialize the stack.
 */

queue_t* queue_init()
{
    queue_t *queue_ptr = (queue_t*)malloc(sizeof(queue_t));

    queue_ptr->end = NULL;
    queue_ptr->start = NULL;

    return queue_ptr;
}

/*
 *  This function free all the remaining nodes in the stack.
 */

void queue_delete(queue_t *queue)
{
    if (queue == NULL) return;

    if (queue->end == NULL)
    {
        free(queue);
        return;
    }

    queue_node_t *prev_node;

    /* Go through all the remaining nodes */
    while (queue->end->previous != NULL)
    {
        free(queue->end->value);

        prev_node = queue->end;
        queue->end = queue->end->previous;

        free(prev_node);
    }

    /* Free the last node */
    free(queue->end->value);
    free(queue->end);

    free(queue);
}


/*
 *  This function initialize a node with a pointer to the data it points to.
 *  The data it points to needs to be malloc'ed first!
 */

void queue_node_create(queue_node_t *new_node, void *data_ptr)
{
    new_node->value = data_ptr;
    new_node->previous = NULL;
}


/*
 *  This function adds a node to the queue.
 */

int queue_add(queue_node_t *added_node, queue_t **queue)
{
    queue_node_t *new_start = (queue_node_t*) malloc(sizeof(queue_node_t));

    if (new_start == NULL) return 1;

    /* If the queue is empty */
    if ((*queue)->start == NULL && (*queue)->end == NULL)
    {
        new_start->previous = NULL;
        new_start->value = added_node->value;

        (*queue)->start = new_start;
        (*queue)->end = new_start;
    }
    else
    {
        new_start->previous = NULL;
        new_start->value = added_node->value;

        (*queue)->start->previous = new_start; 
        (*queue)->start = new_start;
    }

    return 0;
}


/*
 *  This function removes a node at the end of the queue.
 *  remove only free the node popped from the stack, not its value.
 *  It needs to be freed after accessing it.
 */

int queue_remove(queue_node_t *removed_node, queue_t **queue)
{
    if (*queue == NULL || (*queue)->end == NULL ) return 1;

    removed_node->previous = (*queue)->end->previous;
    removed_node->value = (*queue)->end->value;

    queue_node_t *queue_end = (*queue)->end;

    (*queue)->end = (*queue)->end->previous;

    if ((*queue)->end == NULL)
    {
        (*queue)->start = NULL;
    }

    free(queue_end);

    return 0;
}


/*
 *  This function peek the node at the end of the queue.
 */

int queue_peek(queue_node_t *peeked_node, queue_t *queue)
{
    if (queue == NULL || queue->end == NULL || queue->start == NULL) return 1;

    peeked_node->previous = queue->end->previous;
    peeked_node->value = queue->end->value;

    return 0;
}