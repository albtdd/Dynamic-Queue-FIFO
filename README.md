# Dynamic-Queue-FIFO

A simple dynamic queue. A Queue follows the FIFO pattern's rules.

A queue is a simple data structure that follows the simple rule: First In - First Out
The first item inserted (push) into the queue is the first that comes out (pop).

Dynamic queue is not limited in size. You can add all the items you want. The only limit is the memory of your system.

You can create a new queue with:
```C
Queue *my_fifo = queue_new(size_t max_size);
```

max_size defines the max item allowed into the stack. 0 means infinity size. I have defined INF for this purpose

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
void queue_iterator_const(const Queue *queue, const_iter_action action);
void queue_iterator(Queue *queue, iter_action action);
```
The functions iter, have as parameters, the queue in use and the pointer to the function to be applied to the elements of the queue. 
The const-function can only read the elements, the non-const-functions can read and write to the elements.


To know how many entries contain the queue is used:
```C
size_t queue_size(const Queue *queue);
```

To know if the queue is empty or no is used:
```C
bool queue_isempty(const Queue *queue);
```
returns true if the queue is empty (or NULL), false otherwise

To know if the queue is full or no is used:
```C
bool queue_isfull(const Queue *queue);
```
returns true if the queue is full (or NULL), false otherwise

Note
====
I added a repository (Node) with which to create the node used in this project.

Author
======

Alberto Todde <alberto.tdd@gmail.com>
