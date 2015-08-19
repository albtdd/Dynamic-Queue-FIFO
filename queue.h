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


#ifndef _QUEUE_H_
#define _QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __unix__
#include "../node/node.h"
#else
#include "..\node\node.h"
#endif

#include <stdlib.h>


// Early declaration of the struct. See queue.c    
typedef struct queue_t Queue;


// Defines pointer to a function that returns void and 
// gets const Article* as a parameter.
//
// Usefull for the const iterator's functions defined below
typedef void (*const_iter_action)(const Article *);

// Usefull for the iterator's functions defined below
typedef void (*iter_action)(Article *);


/**
 * @brief Creates a new empty Queue
 *
 * @param nothing
 *
 * @return The Queue pointer or NULL on error
 *
 * @note You must use this function before any other action
 *       You must free memory allocated with queue_delete
 */
Queue* queue_new(void);


/**
 * @brief Frees memory area allocated with queue_new
 *
 * @param queue The pointer to the Queue
 *
 * @return nothing
 *
 * @note No crash if param is NULL, returns 0
 *       Undefined behavior if param is an invalid pointer
 */
void queue_delete(Queue *queue);


/**
 * @brief Gets the actual size of the queue
 *
 * @param queue The pointer to the queue
 *
 * @return The size of the queue
 *
 * @note No crash if param is NULL, returns 0
 *       Undefined behavior if param is an invalid pointer
 */
size_t queue_size(const Queue *queue);


/**
 * @brief Checks if the queue is empty or no
 *
 * @param queue The pointer to the queue
 *
 * @return true if the queue is empty, false otherwise
 *
 * @note No crash if param is NULL, returns false
 *       Undefined behavior if param is an invalid pointer
 */
bool queue_isempty(const Queue *queue);


/**
 * @brief Inserts an Article to the top of the queue
 *
 * @param queue The queue pointer
 * @param article The article pointer
 *
 * @see article_new, article_delete
 *
 * @return bool if the insertion had success, false otherwise
 *
 * @note A deep copy af the *article is inserted to the queue
 * @note No crash if param is NULL, returns false
 *       Undefined behavior if param is an invalid pointer
 */
bool queue_push(Queue *queue, const Article *article);


/**
 * @brief Gets an article from the top of queue and remove it from the queue
 *
 * @param queue The queue pointer
 *
 * @return The const pointer to the article
 *
 * @note You must use article_delete with this pointer after the use
 * @note No crash if param is NULL, returns 0
 *       Undefined behavior if param is an invalid pointer
 */
Article* queue_pop(Queue *queue);


/**
 * @brief Gets an article from the top of queue without remove it
 *
 * @param queue The queue pointer
 *
 * @return The const pointer to the article
 *
 * @note Don't use article_delete with this pointer
 * @note No crash if the param is NULL, returns 0
 *       Undefined behavior if param is an invalid pointer
 */
const Article* queue_peek(const Queue *queue);


/**
 * @brief A const Iter from top to bottom of the queue
 *
 * @param queue The queue pointer
 * @param action Pointer to the const function that acts on every item
 *
 * @return nothing
 *
 * @note You can't modify any items of the queue
 * @note No crash if any param is NULL
 *       Undefined behavior any param is an invalid pointer
 */
void queue_iterator_const(const Queue *queue, const_iter_action action);


#ifdef __cplusplus
}
#endif

#endif // _STACK_H_
