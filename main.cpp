#include <iostream>
#include <unordered_map>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    float price;
};

int main() {
    unordered_map<int, Product> inventory;
    int choice;

    do {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Product\n";
        cout << "2. Search Product\n";
        cout << "3. Delete Product\n";
        cout << "4. Update Stock\n";
        cout << "5. Display All Products\n";
        cout << "6. Total Inventory Value\n";
        cout << "7. Update Product Details\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id, qty;
        string name;
        float price;

        switch (choice) {

        case 1:
            cout << "Enter ID: ";
            cin >> id;

            if (id < 0) {
                cout << "Invalid ID!\n";
                break;
            }

            if (inventory.find(id) != inventory.end()) {
                cout << "Product already exists!\n";
                break;
            }

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Quantity: ";
            cin >> qty;
            if (qty < 0) {
                cout << "Invalid quantity!\n";
                break;
            }

            cout << "Enter Price: ";
            cin >> price;
            if (price < 0) {
                cout << "Invalid price!\n";
                break;
            }

            inventory[id] = {id, name, qty, price};
            cout << "Product added successfully!\n";
            break;

        case 2:
            cout << "Enter ID to search: ";
            cin >> id;

            if (inventory.find(id) != inventory.end()) {
                Product p = inventory[id];
                cout << "ID: " << p.id << endl;
                cout << "Name: " << p.name << endl;
                cout << "Quantity: " << p.quantity;
                if (p.quantity < 5)
                    cout << " ⚠ LOW STOCK";
                cout << endl;
                cout << "Price: " << p.price << endl;
            } else {
                cout << "Product not found!\n";
            }
            break;

        case 3:
            cout << "Enter ID to delete: ";
            cin >> id;

            if (inventory.erase(id)) {
                cout << "Product deleted!\n";
            } else {
                cout << "Product not found!\n";
            }
            break;

        case 4:
            cout << "Enter ID: ";
            cin >> id;

            if (inventory.find(id) != inventory.end()) {
                cout << "Enter quantity to add/remove: ";
                cin >> qty;

                if (inventory[id].quantity + qty < 0) {
                    cout << "Invalid operation! Quantity cannot be negative.\n";
                    break;
                }

                inventory[id].quantity += qty;
                cout << "Stock updated!\n";
            } else {
                cout << "Product not found!\n";
            }
            break;

        case 5:
            if (inventory.empty()) {
                cout << "No products available.\n";
            } else {
                for (auto &item : inventory) {
                    Product p = item.second;
                    cout << "\nID: " << p.id << endl;
                    cout << "Name: " << p.name << endl;
                    cout << "Quantity: " << p.quantity;
                    if (p.quantity < 5)
                        cout << " ⚠ LOW STOCK";
                    cout << endl;
                    cout << "Price: " << p.price << endl;
                }
            }
            break;

        case 6: {
            float total = 0;
            for (auto &item : inventory) {
                total += (item.second).price * item.second.quantity;
            }
            cout << "Total Inventory Value: " << total << endl;
            break;
        }

        case 7:
            cout << "Enter ID: ";
            cin >> id;

            if (inventory.find(id) != inventory.end()) {
                cout << "Enter new name: ";
                cin >> name;

                cout << "Enter new price: ";
                cin >> price;

                if (price < 0) {
                    cout << "Invalid price!\n";
                    break;
                }

                inventory[id].name = name;
                inventory[id].price = price;

                cout << "Product details updated!\n";
            } else {
                cout << "Product not found!\n";
            }
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}