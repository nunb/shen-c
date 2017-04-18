#include "list.h"

Pair* get_pair (KLObject* list_object)
{
  return list_object->value.pair;
}

void set_pair (KLObject* list_object, Pair* pair)
{
  list_object->value.pair = pair;
}

KLObject* create_kl_list (KLObject* car_object, KLObject* cdr_object)
{
  KLObject* list_object = create_kl_object(KL_TYPE_LIST);
  Pair* pair = create_pair(car_object, cdr_object);

  set_pair(list_object, pair);

  return list_object;
}

KLObject* get_head_kl_list (KLObject* list_object)
{
  return get_pair_car(get_pair(list_object));;
}

void set_head_kl_list (KLObject* list_object, KLObject* car_object)
{
  set_pair_car(get_pair(list_object), car_object);
}

KLObject* get_tail_kl_list (KLObject* list_object)
{
  return get_pair_cdr(get_pair(list_object));
}

void set_tail_kl_list (KLObject* list_object, KLObject* cdr_object)
{
  set_pair_cdr(get_pair(list_object), cdr_object);
}

bool is_kl_list (KLObject* object)
{
  return get_kl_object_type(object) == KL_TYPE_LIST;
}

bool is_non_empty_kl_list (KLObject* object)
{
  return is_kl_list(object) && !is_empty_kl_list(object);
}

size_t get_kl_list_size (KLObject* list_object)
{
  if (!is_kl_list(list_object))
    throw_kl_exception("Not a list");

  if (is_empty_kl_list(list_object))
    return 0;

  KLObject* object = list_object;
  size_t size = 0;

  while (!is_empty_kl_list(object)) {
    ++size;
    object = get_tail_kl_list(object);
  }

  return size;
}
