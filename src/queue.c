#include <stdlib.h>

#include "queue.h"

queue_t* queue_init()
{
    return NULL;
}

void queue_delete(queue_t *queue)
{
    if (queue != NULL)
    {
        queue_node_t *prev_node;
        queue_node_t *curr_node = queue->start;

        /* Go through all the remaining nodes */
        while (curr_node->next != NULL)
        {
            free(curr_node->value);

            prev_node = curr_node;
            curr_node = curr_node->next;

            free(prev_node);
        }

        free(curr_node);
    }
}

void queue_node_create(queue_node_t *new_node, void *data_ptr)
{
    new_node->value = data_ptr;
    new_node->next = NULL;
}

int queue_add(queue_node_t *added_node, queue_t **queue)
{
    queue_node_t *new_start = (queue_node_t*) malloc(sizeof(queue_node_t));

    if (new_start == NULL) return 1;

    new_start->next = (*queue)->start;
    new_start->value = added_node->value;

    (*queue)->start->previous = new_start; 
    (*queue)->start = new_start;

    return 0;
}

int queue_remove(queue_node_t *removed_node, queue_t **queue)
{
    if (*queue == NULL) return 1;

    removed_node->next = (*queue)->end->next;
    removed_node->previous = (*queue)->end->previous;
    removed_node->value = (*queue)->end->value;

    (*queue)->end = (*queue)->end->previous;

    return 0;
}

void queue_peek(queue_node_t *peeked_node, queue_t *queue)
{
    peeked_node->next = queue->end->next;
    peeked_node->previous = queue->end->previous;
    peeked_node->value = queue->end->value;
}