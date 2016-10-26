#include <iostream>

#include "finder_and_shower.h"

void show_list_by_name(Array<Product> &obj, const std::string &name)
{
    std::cout << "==========================SHOW BY NAME========================" << std::endl;

    for(size_t i = 0; i < obj.getsize(); ++i){

        if(obj[i].getName() == name){
            std::cout << obj[i];
        }
    }
}

void show_list_by_name_lowerPrice(Array<Product> &obj, const std::__cxx11::string &name, const int price)
{
    std::cout << "======================SHOW BY NAME AND PRICE==================" << std::endl;

    for(size_t i = 0; i < obj.getsize(); ++i){

        if(obj[i].getName() == name && obj[i].getPrice() <= price){
            std::cout << obj[i];
        }
    }
}

void show_list_by_name_overTerm_storage(Array<Product> &obj, const int Term_storage)
{
    std::cout << "====================SHOW BY OVER TERM STORAGE=================" << std::endl;

    for(size_t i = 0; i < obj.getsize(); ++i){

        if(obj[i].getTerm_storage() > Term_storage){
            std::cout << obj[i];
        }
    }
}
