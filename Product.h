#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Product {
protected:
    string ID;
    string category;
    string name;
    string expDate;  
    float price;

public:
    Product(string ID, string category, string name, string expDate, float price);
    virtual float computePrice() const;
    virtual void displayInfo() const;
    string getName() const;
    string getCategory() const;
    float getPrice() const;
    virtual ~Product() {};  

    virtual void saveToFile(ostream& os) const {
        os << ID << " " << category << " " << name << " " << expDate << " " << price << " ";
    }
};

class Tobacco : public Product {
    float specialTax;

public:
    Tobacco(string ID, string name, string expDate, float price, float specialTax);
    float computePrice() const override;
    void saveToFile(ostream& os) const override;
};

class LotteryTickets : public Product {
    float cityTax;
    float countyTax;

public:
    LotteryTickets(string ID, string name, string expDate, float price, float cityTax, float countyTax);
    float computePrice() const override;
    void saveToFile(ostream& os) const override;
};