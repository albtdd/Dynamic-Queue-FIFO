/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2011 Alberto Todde <alberto.tdd@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 */


#include "queue.h"
#include <stdlib.h>

#include <stdio.h>


struct queue_t {
    Node *top;
    Node *bottom;
    size_t size;
};


Queue* queue_new(void) {
    Queue *queue = malloc(sizeof *queue);
    if (queue != 0) {
        queue->top = 0;
        queue->bottom = 0;
        queue->size = 0;
    }
    return queue;
}


void queue_delete(Queue *queue) {
    if (queue != 0) {
        Node *ptr = queue->top;
        Node *last;
        while (ptr != 0) {
            last = ptr;
            ptr = node_get_next(ptr);
            node_delete(last);
        }
        free(queue);
    }
}


size_t queue_size(const Queue *queue) {
    return queue != 0 ? queue->size : 0;
}


bool queue_isempty(const Queue *queue) {
    return queue != 0 ? queue->size == 0 : false;
}


bool queue_push(Queue *queue, const Article *article) {
    if (queue != 0) {
        Node *node = node_new(article);
        if (node != 0) {
            if (queue_isempty(queue)) {
                queue->top = node;
                queue->bottom = queue->top;
            } else {
                node_set_next(queue->bottom, node);
                queue->bottom = node;
            }
            queue->size++;
            return true;
        }
    }
    return false;
}


Article* queue_pop(Queue *queue) {
    if (!queue_isempty(queue)) {
        Article *ptr = node_get_ptr(queue->top);
        Node *old_top = queue->top;
        queue->top = node_get_next(queue->top);
        node_remove(old_top); // Don't delete article in the node
        queue->size--;
        return ptr;
    }
    return 0;
}


const Article* queue_peek(const Queue *queue) {
    if (!queue_isempty(queue)) {
        const Article *const_ptr = node_get_const_ptr(queue->bottom);
        return const_ptr;
    }
    return 0;
}


void queue_iterator_const(const Queue *queue, const_iter_action action) {
    if (queue != 0 && action != 0) {
        const Node *ptr = queue->top;
        while (ptr != 0) {
            action(node_get_const_ptr(ptr));
            ptr = node_get_next(ptr);
        }
    }
}


void queue_iterator(Queue *queue, iter_action action) {
    if (queue != 0 && action != 0) {
        const Node *ptr = queue->top;
        while (ptr != 0) {
            action(node_get_ptr(ptr));
            ptr = node_get_next(ptr);
        }
    }
}
