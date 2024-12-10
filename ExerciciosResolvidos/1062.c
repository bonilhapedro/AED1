#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 1000

typedef struct {
    int items[MAX_CARS];
    int top;
} Stack;

void init_stack(Stack *stack) {
    stack->top = -1;
}

int is_stack_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    stack->items[++(stack->top)] = value;
}

int pop(Stack *stack) {
    if (!is_stack_empty(stack)) {
        return stack->items[(stack->top)--];
    }
    return -1;
}

int peek(Stack *stack) {
    if (!is_stack_empty(stack)) {
        return stack->items[stack->top];
    }
    return -1;
}

int can_rearrange(int n, int *output) {
    Stack stack;
    init_stack(&stack);

    int output_index = 0;

    for (int car = 1; car <= n; car++) {
        push(&stack, car);
        while (!is_stack_empty(&stack) && peek(&stack) == output[output_index]) {
            pop(&stack);
            output_index++;
        }
    }

    return is_stack_empty(&stack);
}

int main() {
    int n, i;
    int output[MAX_CARS];

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (1) {
            scanf("%d", &output[0]);
            if (output[0] == 0) break;

            for (i = 1; i < n; i++) {
                scanf("%d", &output[i]);
            }

            if (can_rearrange(n, output)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n");
    }

    return 0;
}
