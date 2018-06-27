#include <stddef.h>
#include <stdlib.h>

#include "stack.h"

/*
 *  This function initialize the stack.
 *  It is not really needed but kept for coherence of the library.
 */

stack_t* stack_init()
{
    return NULL;
}


/*
 *  This function free all the remaining nodes in the stack.
 */

void stack_delete(stack_t *head)
{
    if (head == NULL) return;

    stack_node_t *prev_node;

    /* Go through all the remaining nodes */
    while (head->next != NULL)
    {
        free(head->value);

        prev_node = head;
        head = head->next;

        free(prev_node);
    }

    /* Free the last node */
    free(head->value);
    free(head);
}

/*
 *  This function initialize a node with a pointer to the data it points to.
 *  The data it points to needs to be malloc'ed first!
 */

void stack_node_create(stack_node_t *new_node, void *data_ptr)
{
    new_node->value = data_ptr;
    new_node->next = NULL;
}


/*
 *  This function pushes a node on the stack.
 */

int stack_push(stack_node_t *pushed_node, stack_t **head)
{
    stack_node_t *new_head = (stack_node_t*) malloc(sizeof(stack_node_t));

    /* Check if the malloc worked */
    if (new_head == NULL) return 1;

    new_head->next = *head;
    new_head->value = pushed_node->value;

    *head = new_head;

    return 0;
}


/*
 *  This function pop a node from the stack.
 *  pop only free the node popped from the stack, not its value.
 *  It needs to be freed after accessing it.
 */

int stack_pop(stack_node_t *popped_node, stack_t **head)
{
    if (*head == NULL) return 1;

    popped_node->next = (*head)->next;
    popped_node->value = (*head)->value;

    stack_node_t *prev_head = *head;

    *head = (*head)->next;

    free(prev_head);

    return 0;
}


/*
 *  This function peek the node on top of the stack.
 */

int stack_peek(stack_node_t *peeked_node, stack_t *head)
{
    if (head == NULL || head->next == NULL) return 1;

    peeked_node->next = head->next;
    peeked_node->value = head->value;

    return 0;
}
