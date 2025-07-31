#include "react.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_SUBSCRIBERS (128)
#define MAX_CELLS (128)
#define MAX_CALLBACKS (128)

typedef struct {
  callback callback;
  void *info;
} Callback;

typedef struct {
  struct cell *arg1;
  struct cell *arg2;
  compute1 cmpt1;
  compute2 cmpt2;
} ComputeData;

typedef struct cell {
  int value;
  int id;
  Callback *callbacks[MAX_CALLBACKS];
  callback_id last_cb_id;
  ComputeData *compute_data;
  struct cell *subscribers[MAX_SUBSCRIBERS];
  size_t last_subscriber_id;
} Cell;

void print_cell(Cell *c) {
  char subscribers[MAX_SUBSCRIBERS * 4];
  memset(subscribers, '\0', MAX_SUBSCRIBERS * 4);
  char digit[4];
  for (size_t i = 0; i < c->last_subscriber_id; i++) {
    sprintf(digit, "%d, ", c->subscribers[i]->id);
    strncat(subscribers, digit, 4);
  }

  printf(
	 "Cell { id: %d, "
	 "value: %d, "
	 "last_cb_id: %d, "
	 "subscribers: [%s], "
	 "is_compute: %d }\n",
	 c->id,
	 c->value,
	 c->last_cb_id,
	 subscribers,
	 c->compute_data != NULL
	 );
}

typedef struct reactor {
  size_t size;
  Cell *cells[MAX_CELLS];
} Reactor;

Reactor *create_reactor() {
  Reactor *r = malloc(sizeof(Reactor));
  r->size = 0;
  return r;
}

void destroy_callbacks(Cell *c) {
  for (callback_id id = 0; id < c->last_cb_id; id++) {
    remove_callback(c, id);
  }
}

void destroy_reactor(Reactor *r) {
  for (size_t i = 0; i < r->size; i++) {
    if (r->cells[i] != NULL) {
      destroy_callbacks(r->cells[i]);
      free(r->cells[i]->compute_data);
      free(r->cells[i]);
      r->cells[i] = NULL;
    }
  }
  free(r);
}

Cell *create_input_cell(Reactor *r, int initial_value) {
  Cell *c = malloc(sizeof(Cell));
  r->cells[r->size++] = c;

  c->id = r->size - 1;
  c->value = initial_value;
  c->last_cb_id = 0;
  c->compute_data = NULL;
  c->last_subscriber_id = 0;

  return c;
}

Cell *create_compute1_cell(Reactor *r, Cell *ic, compute1 fn) {
  Cell *c = malloc(sizeof(Cell));
  r->cells[r->size++] = c;

  c->value = fn(ic->value);
  c->id = r->size - 1;
  c->last_cb_id = 0;
  c->compute_data = malloc(sizeof(ComputeData));
  c->compute_data->arg1 = ic;
  c->compute_data->arg2 = NULL;
  c->compute_data->cmpt1 = fn;
  c->compute_data->cmpt2 = NULL;
  c->last_subscriber_id = 0;

  ic->subscribers[ic->last_subscriber_id++] = c;

  return c;
}

Cell *create_compute2_cell(Reactor *r, Cell *ic1, Cell *ic2, compute2 fn) {
  Cell *c = malloc(sizeof(Cell));
  r->cells[r->size++] = c;

  c->value = fn(ic1->value, ic2->value);
  c->id = r->size - 1;
  c->last_cb_id = 0;
  c->compute_data = malloc(sizeof(ComputeData));
  c->compute_data->arg1 = ic1;
  c->compute_data->arg2 = ic2;
  c->compute_data->cmpt1 = NULL;
  c->compute_data->cmpt2 = fn;
  c->last_subscriber_id = 0;

  ic1->subscribers[ic1->last_subscriber_id++] = c;
  ic2->subscribers[ic2->last_subscriber_id++] = c;

  return c;
}

int get_cell_value(Cell *c) {
  ComputeData *cd = c->compute_data;

  if (cd != NULL) {

    if (cd->cmpt1 != NULL) {

      return cd->cmpt1(get_cell_value(cd->arg1));

    } else if (cd->cmpt2 != NULL) {

      return cd->cmpt2(get_cell_value(cd->arg1),
		       get_cell_value(cd->arg2));
    }
  }

  return c->value;
}

void run_callbacks(Cell *c) {
  for (callback_id id = 0; id < c->last_cb_id; id++) {
    Callback *cb = c->callbacks[id];
    if (cb != NULL) {
      cb->callback(cb->info, c->value);
    }
  }
}

void subscribers_to_run_callbacks(Cell *c, Cell **subscribers) {
  for (size_t id = 0; id < c->last_subscriber_id; id++) {
    bool has_no_subscribers = !c->subscribers[id]->last_subscriber_id;

    if (has_no_subscribers) {
      *subscribers++ = c->subscribers[id];
    }
    subscribers_to_run_callbacks(c->subscribers[id], subscribers);
  }
}

void propagate_changes(Cell *c) {
  Cell *subscribers_with_cb[MAX_CELLS];
  for (int i = 0; i < MAX_CELLS; i++)
    subscribers_with_cb[i] = NULL;

  subscribers_to_run_callbacks(c, subscribers_with_cb);

  Cell *subscriber;
  for (int i = 0; i < MAX_CELLS; i++) {
    subscriber = subscribers_with_cb[i];
    if (!subscriber)
      break;

    int new_value = get_cell_value(subscriber);
    if (new_value != subscriber->value) {
      subscriber->value = new_value;
      run_callbacks(subscriber);
    }
  }
}

void set_cell_value(Cell *c, int new_value) {
  c->value = new_value;
  propagate_changes(c);
}

callback_id add_callback(Cell *c, void *cb_info, callback cb) {
  Callback *callback = malloc(sizeof(Callback));
  callback->info = cb_info;
  callback->callback = cb;
  c->callbacks[c->last_cb_id++] = callback;
  return c->last_cb_id - 1;
}

void remove_callback(Cell *c, callback_id id) {
  if (c->callbacks[id] != NULL) {
    free(c->callbacks[id]);
    c->callbacks[id] = NULL;
  }
}