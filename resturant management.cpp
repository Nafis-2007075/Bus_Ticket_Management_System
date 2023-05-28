#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const double VAT_RATE = 0.05; // VAT rate (5%)

class FoodItem {
protected:
    string name;
    double price;

public:
    FoodItem(const string& itemName, double itemPrice)
    {
        name=itemName;
        price=itemPrice;
    }

    virtual double calculateTotal(int quantity) {
        return price * quantity;
    }

    virtual void displayDetails() {
        std::cout << "Item: " << name << "& Price: " << price << endl;
    }
    string getName()
    {
        return name;
    }
    double getPrice()
    {
        return price;
    }

};

class MenuItem : public FoodItem {
private:
    string description;

public:
    MenuItem(const string& itemName, double itemPrice, const string& itemDescription) : FoodItem(itemName, itemPrice), description(itemDescription) {}

    void displayDetails() {
        cout << "Item: " << name << ", Price: " << price << ", Description: " << description <<endl;
    }
};

class ComboItem : public FoodItem {
private:
    vector<FoodItem*> items;

public:
    ComboItem(const string& itemName, const vector<FoodItem*>& itemItems)
        : FoodItem(itemName, 0.0), items(itemItems) {
        for (const auto& item : items) {
            price += item->getPrice();
        }
    }

    double calculateTotal(int quantity) {
        return price * quantity; 
    }

    void displayDetails()  {
        cout << "Combo: " << name << ", Price: " << price <<endl;
        cout << "Items included:" << std::endl;
        for (const auto& item : items) {
            item->displayDetails();
        }
    }
};

class Restaurant {
private:
    vector<FoodItem*> menu;

public:
    void addToMenu(FoodItem* item) {
        menu.push_back(item);
    }

    void displayMenu() {
        std::cout << "Menu:\n";
        for (size_t i = 0; i < menu.size(); i++) {
            std::cout << i + 1 << ". ";
            menu[i]->displayDetails();
        }
        std::cout << std::endl;
    }

    double calculateVAT(double amount) {
        return amount * VAT_RATE;
    }

    double calculateTotal(double subtotal) {
        return subtotal + calculateVAT(subtotal);
    }

    void clearMenu() {
        for (const auto& item : menu) {
            delete item;
        }
        menu.clear();
    }
    int getMenuSize(){
        return menu.size();
    }
    FoodItem * getMenuItem(int index)
    {
        if(index>=0 && index < getMenuSize())
        {
            return menu[index];
        }
    }

    ~Restaurant() {
        clearMenu();
    }
};

int main() {
    Restaurant restaurant;
    restaurant.addToMenu(new MenuItem("Burger", 9.99, "Juicy beef patty with fresh vegetables."));
    restaurant.addToMenu(new MenuItem("Pizza", 12.99, "Thin crust pizza with a variety of toppings."));
    restaurant.addToMenu(new ComboItem("Combo Meal", { new MenuItem("Burger", 0.0, ""), new MenuItem("Fries", 0.0, "") }));
    restaurant.addToMenu(new MenuItem("Salad", 6.99, "Healthy mix of greens with dressing."));

    int choice;
    int quantity;
    double subtotal = 0.0;

    std::cout << "Welcome to the Restaurant"<<endl;
    restaurant.displayMenu();

    while (true) {
        cout << "Enter item number (0 to finish): ";
        cin >> choice;

        if (choice < 1 || choice > restaurant.getMenuSize()) {
            if (choice == 0) {
                break;
            }
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        if (quantity < 1) {
            cout << "Invalid quantity. Please try again.\n";
            continue;
        }

        FoodItem* selectedItem = restaurant.getMenuItem(choice - 1);
        double itemTotal = selectedItem->calculateTotal(quantity);
        subtotal += itemTotal;

        cout << selectedItem->getName() << " - $" << selectedItem->getPrice() << " x " << quantity << " = $" << itemTotal <<endl;
    }

    double vatAmount = restaurant.calculateVAT(subtotal);
    double totalAmount = restaurant.calculateTotal(subtotal);

    cout << "Subtotal: " <<fixed  << subtotal <<endl;
    cout << "VAT (" << (VAT_RATE * 100) << "%): " <<fixed <<setprecision(2) << vatAmount <<endl;
    cout << "Total: " <<fixed << totalAmount <<endl;

    restaurant.clearMenu();

    return 0;
}