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

void destroy_cell(Reactor *r, Cell *c) {
  size_t id = c->id;
  destroy_callbacks(r->cells[id]);
  free(r->cells[id]->compute_data);
  free(r->cells[id]);
  r->cells[id] = NULL;
}

void destroy_reactor(Reactor *r) {
  for (size_t i = 0; i < r->size; i++) {
    if (r->cells[i] != NULL) {
      destroy_cell(r, r->cells[i]);
    }
  }
  free(r);
}

Cell *create_input_cell(Reactor *r, int initial_value) {
  if (r->size + 1 == MAX_CELLS)
    return NULL;

  Cell *c = malloc(sizeof(Cell));
  r->cells[r->size++] = c;

  c->id = r->size - 1;
  c->value = initial_value;
  c->last_cb_id = 0;
  c->compute_data = NULL;
  c->last_subscriber_id = 0;

  return c;
}

bool add_subscriber(Cell *c, Cell *s) {
  if (c->last_subscriber_id + 1 == MAX_SUBSCRIBERS)
    return false;
  c->subscribers[c->last_subscriber_id++] = s;
  return true;
}

Cell *create_compute1_cell(Reactor *r, Cell *ic, compute1 fn) {
  if (r->size + 1 == MAX_CELLS)
    return NULL;
  
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

  if (!add_subscriber(ic, c)) {
    destroy_cell(r, c);
    return NULL;
  }

  return c;
}

Cell *create_compute2_cell(Reactor *r, Cell *ic1, Cell *ic2, compute2 fn) {
  if (r->size + 1 == MAX_CELLS)
    return NULL;
  
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

  if (!add_subscriber(ic1, c) || !add_subscriber(ic2, c)) {
    destroy_cell(r, c);
    return NULL;
  }

  return c;
}

int get_cell_value(Cell *c) {
  ComputeData *cd = c->compute_data;

  int value = c->value;
  
  if (cd != NULL) {

    if (cd->cmpt1 != NULL) {

      value = cd->cmpt1(get_cell_value(cd->arg1));

    } else if (cd->cmpt2 != NULL) {

      value = cd->cmpt2(get_cell_value(cd->arg1),
		       get_cell_value(cd->arg2));
    }

    c->value = value;
  }

  return value;
}

void run_callbacks(Cell *c) {
  for (callback_id id = 0; id < c->last_cb_id; id++) {
    Callback *cb = c->callbacks[id];
    if (cb != NULL) {
      cb->callback(cb->info, c->value);
    }
  }
}

void propagate_changes(Cell *c) {
  for (size_t id = 0; id < c->last_subscriber_id; id++) {
    Cell *subscriber = c->subscribers[id];
    bool has_no_subscribers = !subscriber->last_subscriber_id;

    if (has_no_subscribers) {
      int old_value = subscriber->value;
      int new_value = get_cell_value(subscriber);

      if (new_value != old_value) {
        run_callbacks(subscriber);
      }
    } else {
      propagate_changes(subscriber);
    }
  }
}

void set_cell_value(Cell *c, int new_value) {
  c->value = new_value;
  propagate_changes(c);
}

callback_id add_callback(Cell *c, void *cb_info, callback cb) {
  if (c->last_cb_id + 1 == MAX_CALLBACKS)
    return MAX_CALLBACKS_REACHED;

  Callback *callback = malloc(sizeof(Callback));
  callback->info = cb_info;
  callback->callback = cb;
  c->callbacks[c->last_cb_id++] = callback;
  return c->last_cb_id - 1;
}

void remove_callback(Cell *c, callback_id id) {
  if (id != MAX_CALLBACKS_REACHED && c->callbacks[id] != NULL) {
    free(c->callbacks[id]);
    c->callbacks[id] = NULL;
  }
}