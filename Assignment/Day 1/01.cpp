
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class InventoryItem {
public:
    int id;
    string name;
    string category;
    int quantity;
    int reorderLevel;

    InventoryItem(int id, string name, string category, int quantity, int reorderLevel)
        : id(id), name(name), category(category), quantity(quantity), reorderLevel(reorderLevel) {}
};

class InventoryManagementSystem {
private:
    vector<InventoryItem> inventory;

public:
    void addItem() {
        int id, quantity, reorderLevel;
        string name, category;

        cout << "Enter Item ID: ";
        cin >> id;
        cin.ignore(); // Clear newline from input buffer
        cout << "Enter Item Name: ";
        getline(cin, name);
        cout << "Enter Item Category: ";
        getline(cin, category);
        cout << "Enter Item Quantity: ";
        cin >> quantity;
        cout << "Enter Reorder Level: ";
        cin >> reorderLevel;

        inventory.emplace_back(id, name, category, quantity, reorderLevel);
        cout << "Item added successfully!\n";
    }

    void updateStock() {
        int id, quantity;
        cout << "Enter Item ID to update: ";
        cin >> id;

        for (auto& item : inventory) {
            if (item.id == id) {
                cout << "Current Quantity: " << item.quantity << "\n";
                cout << "Enter new quantity: ";
                cin >> quantity;
                item.quantity = quantity;
                cout << "Stock updated successfully!\n";
                return;
            }
        }
        cout << "Item not found!\n";
    }

    void viewInventory() {
        cout << "Inventory:\n";
        for (const auto& item : inventory) {
            cout << "ID: " << item.id << ", Name: " << item.name
                 << ", Category: " << item.category << ", Quantity: " << item.quantity
                 << ", Reorder Level: " << item.reorderLevel << "\n";
            if (item.quantity < item.reorderLevel) {
                cout << "ALERT: Stock for " << item.name << " is below reorder level!\n";
            }
        }
    }

    void searchItem() {
        string name;
        cout << "Enter Item Name to search: ";
        cin.ignore();
        getline(cin, name);

        for (const auto& item : inventory) {
            if (item.name == name) {
                cout << "Found Item - ID: " << item.id << ", Name: " << item.name
                     << ", Category: " << item.category << ", Quantity: " << item.quantity
                     << ", Reorder Level: " << item.reorderLevel << "\n";
                return;
            }
        }
        cout << "Item not found!\n";
    }

    void exportInventory() {
        ofstream outFile("inventory.txt");
        if (outFile.is_open()) {
            for (const auto& item : inventory) {
                outFile << item.id << "," << item.name << "," << item.category << ","
                        << item.quantity << "," << item.reorderLevel << "\n";
            }
            outFile.close();
            cout << "Inventory exported to inventory.txt successfully!\n";
        } else {
            cout << "Error opening file for writing!\n";
        }
    }
};

int main() {
    InventoryManagementSystem ims;
    int choice;

    do {
        cout << "\nWarehouse Inventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Update Stock\n";
        cout << "3. View Inventory\n";
        cout << "4. Search Item\n";
        cout << "5. Export Inventory\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ims.addItem();
                break;
            case 2:
                ims.updateStock();
                break;
            case 3:
                ims.viewInventory();
                break;
            case 4:
                ims.searchItem();
                break;
            case 5:
                ims.exportInventory();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}