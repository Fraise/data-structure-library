#include <stddef.h>
#include <stdlib.h>

#include "stack.h"

stack_t* stack_init()
{
    return NULL;
}

void stack_delete(stack_t *head)
{
    if (head != NULL)
    {
        stack_node_t *prev_node;

        while (head->next != NULL)
        {
            free(head->value);

            prev_node = head;
            head = head->next;

            free(prev_node);
        }

        free(head);
    }
}

void stack_node_create(stack_node_t *new_node, void *data_ptr)
{
    new_node->value = data_ptr;
    new_node->next = NULL;
}

int stack_push(stack_node_t *pushed_node, stack_t **head)
{
    stack_node_t* new_head = (stack_node_t*) malloc(sizeof(stack_node_t));

    if (new_head == NULL) return 1;

    new_head->next = *head;
    new_head->value = pushed_node->value;

    *head = new_head;

    return 0;
}

//pop only free the node popped from the stack, not it's value.
//It needs to be freed after accessing it

int stack_pop(stack_node_t *popped_node, stack_node_t **head)
{
    if (*head == NULL) return 1;

    popped_node->next = (*head)->next;
    popped_node->value = (*head)->value;

    stack_node_t *prev_head = *head;

    *head = (*head)->next;

    free(prev_head);

    return 0;
}

void stack_peek(stack_node_t *peeked_node, stack_t *head)
{
    peeked_node->next = head->next;
    peeked_node->value = head->value;
}
