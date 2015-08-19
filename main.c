/**
 * 
 *  A simple demo of dynamic queue
 *
 *  Alberto Todde <alberto.tdd@gmail.com>
 *
 */

#include "queue.h"  // Only include this header.
#include <stdio.h>


int main(void) {
    Queue *fifo = queue_new();
    if (fifo) {

        printf("\nQueue is empty: %s\n",
                queue_isempty(fifo) ? "Yes" : "No");

        puts("\nPress any key to continue...");
        getchar();

        for (int i = 1; i < 11; i++) {
            Article *tmp = article_new(i, "A title here", 12.3 * i, i * 2);
            if (tmp != 0) {
                queue_push(fifo, tmp);
                article_delete(tmp);    // Remember this
                printf("\nAritcle %d pushed", i);
            } else {
                printf("\nArticle error %d\n", i);
                return 1;
            }
        }
    }

    printf("\nQueue:\n");
    queue_iterator_const(fifo, article_print);
    
    printf("\n\nQueue is empty: %s\n",
            queue_isempty(fifo) ? "Yes" : "No");

    printf("Queue size is: %zu", queue_size(fifo));

    puts("\nPress any key to continue...");
    getchar();

    printf("\n*** Peek from queue ***\n");
    for (int i = 0; i < 5; i++) {
        const Article *pop = queue_peek(fifo);
        article_print(pop);
        //NB don't use article_delete(pop);
    }
    printf("\n\nQueue size is: %zu", queue_size(fifo));


    puts("\nPress any key to continue...");
    getchar();

    printf("\n*** Pop from queue ***\n");
    for (int i = 0; i < 5; i++) {
        Article *pop = queue_pop(fifo);
        article_print(pop);
        // ... 
        article_delete(pop);    // Remeber this
    }
    printf("\nQueue size is: %zu", queue_size(fifo));

    puts("\nPress any key to continue...");
    getchar();

    printf("\nQueue delete.\n\n");
    queue_delete(fifo);
    fifo = 0;   // Optional statement.
                // fifo should be not set to zero after queue_delete

    return 0;
}
