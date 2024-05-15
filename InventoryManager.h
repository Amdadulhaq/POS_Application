#pragma once
#include "Product.h"
#include <vector>
#include <fstream>

using namespace std;

class InventoryManager {
    vector<Product*> inventory;

public:
    ~InventoryManager();
    void addProduct(Product* product);
    void listProducts();
    Product* findProductByName(string name);
    void removeProduct(string name);
    void saveInventory(const string& filename);
    void loadInventory(const string& filename);
    void listProductsByPriceRange(float low, float high);
};