#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

/// НА семинаре такая же ситуация была
//class Product;
//std::ostream &operator << (const std::ostream &stream, const Product &product);

class Product
{
public:

    Product(std::string _Name = "",
            std::string _Manufacturer = "",
            int _Price = 0,
            int _Term_storage = 0,
            int _Amount = 0);

    Product(const Product &other_product);

    friend std::ostream &operator << (std::ostream &stream, const Product &product);

    std::string getName() const;
    std::string getManufacturer() const;
    int getPrice() const;
    int getTerm_storage() const;
    int getAmount() const;

private:

    Product &operator = (const Product &other_product);

    std::string Name;           //Наименование
    std::string Manufacturer;   //производитель
    int Price;                  //Цена
    int Term_storage;           //Срок хранения
    int Amount;                 //Количество
};

#endif // PRODUCT_H
