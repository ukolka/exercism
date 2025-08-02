#include "sublist.h"
#include <stdbool.h>

bool is_equal(int *, int *, int);
bool is_sublist(int *, int *, int, int);

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) {

  if (list_to_compare_element_count == base_list_element_count)
    return is_equal(list_to_compare, base_list,
		    base_list_element_count) ? EQUAL : UNEQUAL;

  if (list_to_compare_element_count < base_list_element_count)
    if (is_sublist(list_to_compare, base_list,
		   list_to_compare_element_count,
		   base_list_element_count))
      return SUBLIST;

  if (list_to_compare_element_count > base_list_element_count)
    if (is_sublist(base_list, list_to_compare,
		   base_list_element_count,
		   list_to_compare_element_count))
      return SUPERLIST;

  return UNEQUAL;
}

bool is_equal(int *list_to_compare, int *base_list, int count) {
  for (int i = 0; i < count; i++)
    if (list_to_compare[i] != base_list[i]) return false;

  return true;
}

bool is_sublist(int *list_a, int *list_b, int size_a, int size_b) {
  if (size_a == 0) return true;
  if (size_a > size_b) return false;
  
  for (int i = 0; i <= size_b - size_a; i++)
    if (list_b[i] == list_a[0] && is_equal(list_b + i, list_a, size_a)) return true;

  return false;
}