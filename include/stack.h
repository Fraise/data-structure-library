#ifndef STACK_H
#define STACK_H

#include <stdint.h>

typedef struct stack_node
{
    void *value;
    struct stack_node *next;
} stack_node_t;

typedef stack_node_t stack_t;

stack_t* stack_init();
void stack_delete(stack_t *head);
void stack_node_create(stack_node_t *new_node, void *data_ptr);
int stack_push(stack_node_t *pushed_node, stack_t **head);
int stack_pop(stack_node_t *popped_node, stack_node_t **head);
int stack_peek(stack_node_t *peeked_node, stack_t *head);

#endif /* STACK_H */