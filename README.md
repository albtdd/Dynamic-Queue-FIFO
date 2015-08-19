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

Author
======

Alberto Todde <alberto.tdd@gmail.com>
