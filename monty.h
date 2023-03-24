#ifndef monty_h
#define monty_h

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct queue_s
{
	char *line;
	int line_number;
	struct queue_s *prev;
	struct queue_s *next;
} queue_t;

void enqueue(char *, int);
void print_queue(void);
queue_t *deque(void);
stack_t *deque_value(void);
void enqueue_values(int);
void interpret(void);

void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);

#endif /* monty_h */
