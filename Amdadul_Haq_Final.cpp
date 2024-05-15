// Amdadul_Haq_Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "InventoryManager.h"

void displayMenu() {
    cout << "\n*** POS System Menu ***\n";
    cout << "1. List Products\n";
    cout << "2. Add Product\n";
    cout << "3. Remove Product\n";
    cout << "4. Find Product\n";
    cout << "5. Sell Product\n";
    cout << "6. Load Inventory\n";
    cout << "7. Save Inventory\n";
    cout << "8. List Products by Price Range\n";
    cout << "9. Exit\n";
}

int main() {
    InventoryManager manager;
    int choice;
    string filename = "inventory.txt"; // Default filename for saving and loading
    string name, ID, expDate, category;
    float price, tax1, tax2, lowPrice, highPrice;

    while (true) {
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  

        switch (choice) {
        case 1:
            manager.listProducts();
            break;
        case 2: {
            cout << "Enter product ID: ";
            getline(cin, ID);
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Expiry Date (MM-DD-YY): ";
            getline(cin, expDate);
            cout << "Enter Price: ";
            cin >> price;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Enter Category (e.g., Tobacco, LotteryTickets, General): ";
            getline(cin, category);

            if (category == "Tobacco") {
                cout << "Enter tax percentage for Tobacco: ";
                cin >> tax1; // Read tax as a percentage
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                manager.addProduct(new Tobacco(ID, name, expDate, price, tax1));
            }
            else if (category == "LotteryTickets") {
                cout << "Enter city tax percentage for Lottery Tickets: ";
                cin >> tax1; // First tax percentage
                cout << "Enter county tax percentage for Lottery Tickets: ";
                cin >> tax2; // Second tax percentage
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                manager.addProduct(new LotteryTickets(ID, name, expDate, price, tax1, tax2));
            }
            else {
                manager.addProduct(new Product(ID, category, name, expDate, price));
            }
            break;
        }

        case 3:
            cout << "Enter product name to remove: ";
            getline(cin, name);
            manager.removeProduct(name);
            break;
        case 4:
            cout << "Enter product name to find: ";
            getline(cin, name);
            if (auto product = manager.findProductByName(name)) {
                product->displayInfo();
            }
            else {
                cout << "Product not found.\n";
            }
            break;
        case 5:
            cout << "Enter product name to sell: ";
            getline(cin, name);
            if (auto product = manager.findProductByName(name)) {
                cout << "Selling Price: $" << product->computePrice() << endl;
            }
            else {
                cout << "Product not found or out of stock.\n";
            }
            break;
        case 6:
            manager.loadInventory(filename);
            cout << "Inventory loaded successfully.\n";
            break;
        case 7:
            manager.saveInventory(filename);
            cout << "Inventory saved successfully.\n";
            break;
        case 8:
            cout << "Enter low price: ";
            cin >> lowPrice;
            cout << "Enter high price: ";
            cin >> highPrice;
            manager.listProductsByPriceRange(lowPrice, highPrice);
            break;
        case 9:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
