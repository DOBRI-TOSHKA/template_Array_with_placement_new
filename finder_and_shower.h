#ifndef FINDER_AND_SHOWER_H
#define FINDER_AND_SHOWER_H

#include <string>
#include "Array_with_placement_new.h"
#include "product.h"

void show_list_by_name(Array<Product> &obj, const std::string &name);
void show_list_by_name_lowerPrice(Array<Product> &obj, const std::string &name, const int price);
void show_list_by_name_overTerm_storage(Array<Product> &obj, const int Term_storage);

#endif // FINDER_AND_SHOWER_H
