#include "product.h"
#include <iostream>
#include <iomanip>

Product::Product(std::string _Name,
                 std::string _Manufacturer,
                 int _Price,
                 int _Term_storage,
                 int _Amount): Name(_Name),
                               Manufacturer(_Manufacturer),
                               Price(_Price),
                               Term_storage(_Term_storage),
                               Amount(_Amount)
{
}

Product::Product(const Product &other_product)
{
    this->Name = other_product.getName();
    this->Manufacturer = other_product.getManufacturer();
    this->Price = other_product.getPrice();
    this->Term_storage = other_product.getTerm_storage();
    this->Amount = other_product.getAmount();
}

std::string Product::getName() const
{
    return Name;
}

///ВОПРОС: std::__cxx11::string ???
std::__cxx11::string Product::getManufacturer() const
{
    return Manufacturer;
}

int Product::getPrice() const
{
    return Price;
}

int Product::getTerm_storage() const
{
    return Term_storage;
}

int Product::getAmount() const
{
    return Amount;
}

std::ostream &operator <<(std::ostream &stream, const Product &product)
{

    stream << std::setw(14) << product.Name;
    stream << std::setw(20) << product.Manufacturer;
    stream << std::setw(8)  << product.Price;
    stream << std::setw(14) << product.Term_storage;
    stream << std::setw(8)  << product.Amount << std::endl;

    return stream;
}
