#include "InventoryManager.h"

InventoryManager::~InventoryManager() {
    for (auto& product : inventory) {
        delete product;
    }
    inventory.clear();
}

void InventoryManager::addProduct(Product* product) {
    inventory.push_back(product);
}

void InventoryManager::listProducts() {
    for (const auto& product : inventory) {
        product->displayInfo();
    }
}

Product* InventoryManager::findProductByName(string name) {
    for (auto& product : inventory) {
        if (product->getName() == name) {
            return product;
        }
    }
    return nullptr;
}

void InventoryManager::removeProduct(string name) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->getName() == name) {
            delete* it;
            inventory.erase(it);
            return;
        }
    }
}

void InventoryManager::saveInventory(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    for (auto& product : inventory) {
        // Save the type of product first
        file << product->getCategory() << " ";
        product->saveToFile(file);
    }
    file.close();
}

void InventoryManager::loadInventory(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading.\n";
        return;
    }
    string type, ID, name, expDate;
    float price, tax1, tax2;

    while (file >> type) {
        file >> ID >> name >> expDate >> price;
        if (type == "Tobacco") {
            file >> tax1;
            inventory.push_back(new Tobacco(ID, name, expDate, price, tax1));
        }
        else if (type == "LotteryTickets") {
            file >> tax1 >> tax2;
            inventory.push_back(new LotteryTickets(ID, name, expDate, price, tax1, tax2));
        }
        else {
            inventory.push_back(new Product(ID, type, name, expDate, price));
        }
    }
    file.close();
}

void InventoryManager::listProductsByPriceRange(float low, float high) {
    for (const auto& product : inventory) {
        if (product->getPrice() >= low && product->getPrice() <= high) {
            product->displayInfo();
        }
    }
}
