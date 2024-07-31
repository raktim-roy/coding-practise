#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CIRCULAR_BUFFER_SIZE 10


struct circular_buf_t {
	uint8_t* buffer;
	size_t head;
	size_t tail;
	bool full;
	size_t capacity;
};
typedef struct circular_buf_t circular_buf_t;

typedef circular_buf_t* cbuf_handle_t;

cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size) {
	cbuf_handle_t cbuf = malloc(sizeof(circular_buf_t));
	if (!cbuf) return NULL;
	
	cbuf->buffer = buffer;
	cbuf->capacity = size;
}

void circular_buf_free(cbuf_handle_t me) {
	free(me);
}

void circular_buf_reset(cbuf_handle_t me) {
	if (!me) return;
	
	me->head = me->tail = 0;
	me->full = false;
	
	
}

bool circular_buf_is_full(cbuf_handle_t me) {
	return me->full;
}

bool circular_buf_is_empty(cbuf_handle_t me) {
	return !(me->full) && (me->head == me->tail);
}

void circular_buf_put(cbuf_handle_t me, uint8_t data) {
	if(!me) return;
	
	me->buffer[me->head] = data;
	
	if (circular_buf_is_full(me)) {
		// increment tail first since buf full and new data
		// has overwriten old data.
		me->tail = (me->tail + 1)%(me->capacity);
	}
	
	me->head = (me->head + 1) % (me->capacity);
	me->full = (me->head == me->tail);
}
	

/// Put that rejects new data if the buffer is full
/// Note: if you are using the threadsafe version, *this* is the put you should use
/// Requires: me is valid and created by circular_buf_init
/// Returns 0 on success, -1 if buffer is full
int circular_buf_try_put(cbuf_handle_t me, uint8_t data) {

	if (!me) return -1;
	
	if (circular_buf_is_full(me)) {
		return -1;
	}
	
	me->buffer[me->head] = data;
	
	me->head = (me->head + 1) % (me->capacity);
	
	return 0;
}


/// Retrieve a value from the buffer
/// Requires: me is valid and created by circular_buf_init
/// Returns 0 on success, -1 if the buffer is empty
int circular_buf_get(cbuf_handle_t me, uint8_t *data) {
	if (!me) return -1;
	
	if (circular_buf_is_empty(me)) return -1;
	
	*data = me->buffer[me->tail];
	
	me->tail = (me->tail + 1) % (me->capacity);
	
	me->full = false;
	
	return 0;
	
}




size_t circular_buf_capacity(cbuf_handle_t me) {
	return me->capacity;
}

size_t circular_buf_size(cbuf_handle_t me) {

	size_t buf_size = me->capacity;
	
	if (!circular_buf_is_full(me)) {
		if (me->head >= me->tail) {
			buf_size = me->head - me->tail;
		} else {
			buf_size = me->head - me->tail + me->capacity;
		}
	}
	
	return buf_size;
}

static uint8_t circular_buffer_storage_[CIRCULAR_BUFFER_SIZE] = {0};

int main()
{
   cbuf_handle_t me = 
   circular_buf_init(circular_buffer_storage_, CIRCULAR_BUFFER_SIZE);
   
   circular_buf_put(me, 10);
   circular_buf_put(me, 20);
   circular_buf_put(me, 30);
   circular_buf_put(me, 40);
   circular_buf_put(me, 50);
   circular_buf_put(me, 60);
   circular_buf_put(me, 70);
   circular_buf_put(me, 80);
   circular_buf_put(me, 90);
   circular_buf_put(me, 100);
   
   printf("size of circ buff: %ld \n", circular_buf_size(me));
   
   
   uint8_t* data = (uint8_t *)malloc(CIRCULAR_BUFFER_SIZE * sizeof(uint8_t));
  
   int x = CIRCULAR_BUFFER_SIZE;
  
   while(x) {
  	 circular_buf_get(me, data + CIRCULAR_BUFFER_SIZE - x);
  	 x--;
   }
   
   printf("read back from circ buff: %d \n", data[9]);
   
   free(data);
   circular_buf_reset(me);
   return 0;
}

