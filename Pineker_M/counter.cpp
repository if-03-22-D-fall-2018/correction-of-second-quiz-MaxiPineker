/*-----------------------------------------------------------------------------
*				HTBLA-Leonding / Class: <your class name here>
*-----------------------------------------------------------------------------
* Exercise Number: #exercise_number#
* File:			counter.cpp
* Author(s):	<your name here>
* Due Date:		#due#
*-----------------------------------------------------------------------------
* Description:
* A counter to count up and count down.
*-----------------------------------------------------------------------------
*/

#include "counter.h"
#include <stdbool.h>

struct CounterImplementation{
  enum direction direction;
  int value;
  int increment_value;
  bool isUsed;
};

struct CounterImplementation POS_PRPR_02 = { UNDEFINED, 0, 0 ,false };
struct CounterImplementation POS_PRPR_06 = { UNDEFINED, 0, 0 ,false };
struct CounterImplementation POS_PRPR_07 = { UNDEFINED, 0, 0 ,false };
struct CounterImplementation POS_PRPR_09 = { UNDEFINED, 0, 0 ,false };
struct CounterImplementation POS_PRPR_10 = { UNDEFINED, 0, 0 ,false };
struct CounterImplementation POS_PRPR_12 = { UNDEFINED, 0, 0 ,false };
struct CounterImplementation POS_PRPR_14 = { UNDEFINED, 0, 0 ,false };
struct CounterImplementation POS_PRPR_16 = { UNDEFINED, 0, 0 ,false };


static Counter counters_so_far[COUNTER_COUNT] = {&POS_PRPR_02, &POS_PRPR_06, &POS_PRPR_07, &POS_PRPR_09, &POS_PRPR_10, &POS_PRPR_12, &POS_PRPR_14, & POS_PRPR_16};

void init()
{
  for (int i = 0; i < COUNTER_COUNT; i++) {
    counters_so_far[i]->direction = UNDEFINED;
    counters_so_far[i]->value = 0;
    counters_so_far[i]->isUsed = false;
    counters_so_far[i]->increment_value = 1;
  }
}
Counter new_counter(direction d)
{
  for (int i = 0; i < COUNTER_COUNT; i++) {
    if (counters_so_far[i]->isUsed == false) {
      counters_so_far[i]->isUsed = true;
      counters_so_far[i]->direction = d;
      return counters_so_far[i];
    }
  }
  return 0;
}
direction get_direction(Counter c)
{
  return c->direction;
}
void set_direction(Counter c, direction d)
{
  c->direction = d;
}
int get_increment_value(Counter c)
{
  return c->increment_value;
}
void set_increment_value(Counter c, int increment_value)
{
  if (increment_value >= 0) {
    c->increment_value = increment_value;
  }
}
int get_value(Counter c)
{
  return c->value;
}
void increment(Counter c)
{
  if (c->direction == DOWN) {
    c->value -= c->increment_value;
  }
  else if (c->direction == UP) {
    c->value += c->increment_value;
  }
}
bool set_value(Counter c, int value)
{
  if (c->direction == DOWN) {
    c->value = value;
    return true;
  }
  return false;
}
