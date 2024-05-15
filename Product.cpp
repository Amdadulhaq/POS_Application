#include "Product.h"

Product::Product(string ID, string category, string name, string expDate, float price)
    : ID(ID), category(category), name(name), expDate(expDate), price(price) {}

float Product::computePrice() const {
    return price;
}

void Product::displayInfo() const {
    cout << "ID: " << ID << ", Category: " << category << ", Name: " << name
        << ", Expiration Date: " << expDate << ", Price: $" << price << endl;
}

string Product::getName() const { return name; }
string Product::getCategory() const { return category; }
float Product::getPrice() const { return price; }

Tobacco::Tobacco(string ID, string name, string expDate, float price, float specialTax)
    : Product(ID, "Tobacco", name, expDate, price), specialTax(specialTax) {}


float Tobacco::computePrice() const {
    return price * (1.0 + specialTax / 100.0);  // Convert tax to a percentage
}




void Tobacco::saveToFile(ostream& os) const {
    Product::saveToFile(os);
    os << specialTax << "\n";
}

LotteryTickets::LotteryTickets(string ID, string name, string expDate, float price, float cityTax, float countyTax)
    : Product(ID, "LotteryTickets", name, expDate, price), cityTax(cityTax), countyTax(countyTax) {}

// LotteryTickets.cpp
float LotteryTickets::computePrice() const {
    return price * (1.0 + (cityTax + countyTax) / 100.0);  // Sum of city and county tax
}

void LotteryTickets::saveToFile(ostream& os) const {
    Product::saveToFile(os);
    os << cityTax << " " << countyTax << "\n";
}
