#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <vector>

#include "Array_with_placement_new.h"
#include "product.h"
#include "finder_and_shower.h"

static void generate_vector_Names(std::vector<std::string> &v){
    v.push_back("Protein");
    v.push_back("BCA");
    v.push_back("Creatine");
    v.push_back("Amino acids");
    v.push_back("Pre-workout");
    v.push_back("Isotonic");
    v.push_back("Vitamins");
}

static void generate_vector_Manufacturers(std::vector<std::string> &v){
    v.push_back("Dymatize");
    v.push_back("Fitness & Life");
    v.push_back("IronMaxx");
    v.push_back("MuscleMeds");
    v.push_back("Optimum Nutrition");
    v.push_back("Performance");
    v.push_back("Power System");
    v.push_back("SAN");
    v.push_back("Syntrax");
    v.push_back("Trec Nutrition");
    v.push_back("Universal Nutrition");
}

static void showAll(const Array<Product> &products){

    std::cout.setf(std::ios::left);

    std::cout << "============================SHOW ALL==========================" << std::endl;

    std::cout << std::setw(14) << "Name";
    std::cout << std::setw(20) << "Manufacturer";
    std::cout << std::setw(8)  << "Price";
    std::cout << std::setw(14) << "Term_storage";
    std::cout << std::setw(8)  << "Amount" << std::endl;


    for(size_t i = 0; i < products.getsize(); ++i){
        std::cout << products[i];
    }
}

int main()
{

    std::vector<std::string> vName;
    std::vector<std::string> vManufacturer;

    generate_vector_Names(vName);
    generate_vector_Manufacturers(vManufacturer);

    // construct a trivial random generator engine from a time-based seed:
    unsigned long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);

    std::uniform_int_distribution<int> distribution_number_gen (30, 100);

    std::uniform_int_distribution<int> distribution_index_Name (0, vName.size() - 1);
    std::uniform_int_distribution<int> distribution_index_Manufacturer (0, vManufacturer.size() - 1);

    std::uniform_int_distribution<int> distribution_Price (50, 100);
    std::uniform_int_distribution<int> distribution_Term_storage (2, 30);
    std::uniform_int_distribution<int> distribution_Amount (0, 1000);


    int size_array = distribution_number_gen(generator);
    Array<Product> product_array(size_array);

    try{

        std::cout << "input random value" << std::endl << std::endl;

        for (int i = 0; i < size_array; ++i){

            Product insert_product(vName[distribution_index_Name(generator)],
                                   vManufacturer[distribution_index_Manufacturer(generator)],
                                   distribution_Price(generator),
                                   distribution_Term_storage(generator),
                                   distribution_Amount(generator));

            product_array.replace(i, insert_product);
        }

        showAll(product_array);

        show_list_by_name(product_array, "Creatine");
        show_list_by_name_lowerPrice(product_array, "Creatine", 75);
        show_list_by_name_overTerm_storage(product_array, 14);
    }
    catch(int err){
        std::cout << "ERROR = " << err << std::endl;
    }

    return 0;
}
