#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "queue.h"

void print_int_stack(stack_node_t* head)
{
    if (head != NULL)
    {
        stack_node_t *node = head;
        while (node->next != NULL)
        {
            printf("int = %d\n", *((int*)node->value));
            node = node->next;
        }
    }
}

void stack_test()
{
    stack_t *stack_head = stack_init();

    for (int i = 0; i < 50; i ++)
    {
        int* value = (int*)malloc(sizeof(int));
        *value = i;

        stack_node_t new_node;
        
        stack_node_create(&new_node, (void*) value);

        stack_push(&new_node, &stack_head);
    }

    stack_node_t peeked_node;

    stack_peek(&peeked_node, stack_head);

    printf("peeked int = %d\n", *((int*)peeked_node.value));

    for (int i = 0; i < 100; i ++)
    {
        stack_node_t new_node;

        if (stack_pop(&new_node, &stack_head) == 0)
        {
            printf("popped int = %d\n", *((int*)new_node.value));

            free(new_node.value);
        }
    }

    print_int_stack(stack_head);

    stack_delete(stack_head);
}

void queue_test()
{
    queue_t *queue = queue_init();


    for (int i = 0; i < 50; i ++)
    {
        int* value = (int*)malloc(sizeof(int));
        *value = i;

        queue_node_t new_node;
        
        queue_node_create(&new_node, (void*) value);

        queue_add(&new_node, &queue);
    }

    queue_node_t peeked_node;

    queue_peek(&peeked_node, queue);

    printf("peeked int = %d\n", *((int*)peeked_node.value));

    for (int i = 0; i < 100; i ++)
    {
        queue_node_t new_node;

        if (queue_remove(&new_node, &queue) == 0)
        {
            printf("removed int = %d\n", *((int*)new_node.value));

            free(new_node.value);
        }
    }

    queue_delete(queue);
}

int main(void)
{
    stack_test();

    return 0;
}