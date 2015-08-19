# Dynamic-Queue-FIFO

A simple dynamic queue. A Queue follows the FIFO pattern's rules.

A queue is a simple data structure that follows the simple rule: First In - First Out
The first item inserted (push) into the queue is the first that comes out (pop).

Dynamic queue is not limited in size. You can add all the items you want. The only limit is the memory of your system.

You can create a new queue with:
```C
Queue *my_fifo = queue_new();
```

I have created an item to push into the queue called Article. It's only an example.
```C
Article *art = new_article(1, "title of art", 12.55, 5);

queue_push(my_lifo, art);
```
NB: queue_push creates a own copy (deep copy) of Article. It's your responsibility delete all the articles created,
when they are not more useful, with:
```C
article_delete(art)
```

To extract an item from the queue you can simply use:
```C
Article *res = queue_pop(my_lifo);
```
See "article.h" for to know all the functions to manage it.

NB: It's again your responsibility delete all the items extracted from the queue (see above).

If you only want to know which is the top of the queue (without extract anything) you will use:
```C
Article *res_const = queue_peek(my_lifo);
```

NB: *res_const it's only a constant pointer. No memory to frees in that case.

When you have finished to usingthe queue:
```C
queue_delete(my_lifo);
````

To iter the Queue:
```C
void stack_iterator_const(const Stack *stack, const_iter_action action);
void stack_iterator(Stack *stack, iter_action action);
```
The functions iter, have as parameters, the stack in use and the pointer to the function to be applied to the elements of the stack. 
The const-function can only read the elements, the non-const-functions can read and write to the elements.


To know how many entries contain the stack is used:
```C
size_t stack_size(const Stack *stack);
```

To know if the stack is empty or no is used:
```C
bool stack_isempty(const Stack *stack);
```
returns true if the stack is empty (or NULL), false otherwise


Author
======

Alberto Todde <alberto.tdd@gmail.com>
