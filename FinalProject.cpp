#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int Options();
void itemList();
int cartLimit = 0;

class Product{
public:
    string itemName;
    float price;
    int itemID;
    void setitemName(string);
    void setitemID(int);
    void setPrice(float);
    string getitemName();
    int getitemID();
    float getPrice();
    friend std::ostream& operator << (std::ostream& os, Product& product){ //allows the printing of object vector
        os << "Product ID: " << product.getitemID() << ", "
        << "Product Name: " << product.getitemName() << ", "
        << "Price: " << product.getPrice() << endl;
        return os;
    }
    Product();
    Product(string a, float b, int c);
};

Product::Product(){
    itemName = "";
    price = 0.0;
    itemID = 0;
}

Product::Product(string itemName, float itemPrice, int itemID){
    setitemName(itemName);
    setPrice(itemPrice);
    setitemID(itemID);
}

void Product::setitemName(string a){
    itemName = a;
}

void Product::setPrice(float b){
    price = b;
}

void Product::setitemID(int c){
    itemID = c;
}

string Product::getitemName(){
    return itemName;
}

float Product::getPrice(){
    return price;
}

int Product::getitemID(){
    return itemID;
}

class ShoppingCart{
public:
    vector<Product> Cart;
    stack<Product> removalCart;
    queue<Product> noStock;
    void addProduct(vector<Product>& Cart, queue<Product>& noStock);
    void removeItem(int x, vector<Product>& Cart);
    void removeProduct(vector<Product>& Cart, stack<Product>& removalCart, queue<Product>& noStock);
    void recentRemove(stack<Product>& removalCart);
    void outOfStock(queue<Product>& noStock);
    float cartTotal(vector<Product>& Cart);
    void showCart(vector<Product>& Cart);
};

void ShoppingCart::addProduct(vector<Product>& Cart, queue<Product>& noStock){
    char choice;
    int proID;
    do{
        if(cartLimit == 3){
            cout << "Cart Limit reached. Returning to Main Menu.";
            break;
        }
        cout << "Please choose a product by ID.\n";
        itemList();
        cin >> proID;
        if(proID == 101){
            Product p1("Phone Charger", 15.50, 101);
            Cart.push_back(p1);
            cout << "Item has been added to cart.\n";
            cout << "Do you want to add another product?\n";
            cin >> choice;
            cartLimit++;
        }
        else if(proID == 102){
            Product p2("Batteries(24pk)", 25.74, 102);
            Cart.push_back(p2);
            cout << "Item has been added to cart.\n";
            cout << "Do you want to add another product?\n";
            cin >> choice;
            cartLimit++;
        }
        else if(proID == 201){
            Product p3("Bread", 8.99, 201);
            Cart.push_back(p3);
            cout << "Item has been added to cart.\n";
            cout << "Do you want to add another product?\n";
            cin >> choice;
            cartLimit++;
        }
        else if(proID == 202){
            Product p4("Beef", 39.12, 202);
            Cart.push_back(p4);
            cout << "Item has been added to cart.\n";
            cout << "Do you want to add another product?\n";
            cin >> choice;
            cartLimit++;
        }
        else if(proID == 301){
            Product p5("Jordans", 149.99, 301);
            Cart.push_back(p5);
            cout << "Item has been added to cart.\n";
            cout << "Do you want to add another product?\n";
            cin >> choice;
            cartLimit++;
        }
        else{
            cout << "Invalid ID. Returning to Main Menu.\n";
        }
    }while(choice == 'y' || choice == 'Y');
};

void ShoppingCart::removeItem(int x, vector<Product>& Cart){ //handles the actual removal of cart items
    for(int i = 0; i < Cart.size(); ++i){
        if(Cart[i].getitemID() == x){
            Cart.erase(Cart.begin() + i);
            break;
        }
    }
};

void ShoppingCart::removeProduct(vector<Product>& Cart, stack<Product>& removalCart, queue<Product>& noStock){ //remove product menu
    char choice;
    int proID;
    int currentSize = 0;
    cout << "Please choose a product by ID.\n";
    cin >> proID;
    if(proID == 101){
        if(Cart.size() == currentSize){
            cout << "No items in cart to remove.\n";
        }
        else if(Cart[0].getitemID() != proID && Cart[1].getitemID() != proID && Cart[2].getitemID() != proID){
            cout << "Item is not in cart.\n";
        }
        else{
            removeItem(proID, Cart);
            Product p1("Phone Charger", 15.50, 101);
            removalCart.push(p1);
            cout << "Item has been removed.\n";
            cartLimit--;
        }
    }
    else if(proID == 102){
        if(Cart.size() == currentSize){
            cout << "No items in cart to remove.\n";
        }
        else if(Cart[0].getitemID() != proID && Cart[1].getitemID() != proID && Cart[2].getitemID() != proID){
            cout << "Item is not in cart.\n";
        }
        else{
            removeItem(proID, Cart);
            Product p2("Batteries(24pk)", 25.74, 102);
            removalCart.push(p2);
            cout << "Item has been removed.\n";
            cartLimit--;
        }
    }
    else if(proID == 201){
        if(Cart.size() == currentSize){
            cout << "No items in cart to remove.\n";
        }
        else if(Cart[0].getitemID() != proID && Cart[1].getitemID() != proID && Cart[2].getitemID() != proID){
            cout << "Item is not in cart.\n";
        }
        else{
            removeItem(proID, Cart);
            Product p3("Bread", 8.99, 201);
            removalCart.push(p3);
            cout << "Item has been removed.\n";
            cartLimit--;
        }
    }
    else if(proID == 202){
        if(Cart.size() == currentSize){
            cout << "No items in cart to remove.\n";
        }
        else if(Cart[0].getitemID() != proID && Cart[1].getitemID() != proID && Cart[2].getitemID() != proID){
            cout << "Item is not in cart.\n";
        }
        else{
            removeItem(proID, Cart);
            Product p4("Beef", 39.12, 202);
            removalCart.push(p4);
            cout << "Item has been removed.\n";
            cartLimit--;
        }
    }
    else if(proID == 301){
        if(Cart.size() == currentSize){
            cout << "No items in cart to remove.\n";
        }
        else if(Cart[0].getitemID() != proID && Cart[1].getitemID() != proID && Cart[2].getitemID() != proID){
            cout << "Item is not in cart.\n";
        }
        else{
            Product p5("Jordans", 149.99, 301);
            removeItem(proID, Cart);
            removalCart.push(p5);
            cout << "Item has been removed.\n";
            if(noStock.size() > 3){
                noStock.pop();
            }
            noStock.push(p5);
            cartLimit--;
        }
    }
    else{
        cout << "Invalid ID. Returning to Main Menu.\n";
    }
};

void ShoppingCart::recentRemove(stack<Product>& removalCart){ //removes oldest element by flipping stack
    stack<Product> copyCart {removalCart};
    stack<Product> fakeCart;
    if(removalCart.empty() == false){
        cout << "Here's what's been recently removed from your cart.\n";
        for(int i = 0; i < 3; ++i){
            while(copyCart.size()){
                copyCart.top();
                fakeCart.push(copyCart.top());
                copyCart.pop();
            }
            if(fakeCart.size() > 3){
                fakeCart.pop();
            }

            }
        for(int a = 0; a < 3; ++a){
            while(fakeCart.size()){
                cout << fakeCart.top() << endl;
                fakeCart.pop();
            }
        }
    }
    else{
        cout << "Nothing has been recently removed.\n";
    }
};

void ShoppingCart::outOfStock(queue<Product>& noStock){
    queue<Product> copyStock {noStock};
    if(noStock.empty() == false){
        cout << "Here are the out of stock products.\n";
        for(int i = 0; i < copyStock.size(); ++i){
            cout << copyStock.front() << " " << endl;
            copyStock.pop();
        }
    }
    else{
        cout << "Nothing is out of stock.\n";
    }
};

float ShoppingCart::cartTotal(vector<Product>& Cart){
    float total = 0.00;
    if(Cart.empty() == false){
        for(int x = 0; x < Cart.size(); x++){
            total += Cart[x].getPrice();
        }
        cout << "The total price of your items is: " << total << endl;
    }
    else{
        total = 0.00;
        cout << "The total price of your items is: " << total << endl;
    }
    return total;
};

void ShoppingCart::showCart(vector<Product>& Cart){
    bool cartState = Cart.empty();
    if(cartState == false){
        cout << "Here's what is in your cart:\n";
        for(int i = 0; i < Cart.size(); i++){
            cout << Cart[i] << " " << endl;
        }
    }
    else{
        cout << "Nothing's in your cart.\n";
    }
};

int main(){
    cout << fixed << setprecision(2);
    cout << "Welcome to Nondescript Store!";
    int menu = 0;
    ShoppingCart customerBasket;
    vector<Product> siteBasket;
    stack<Product> removedCart;
    queue<Product> noMore;
    do{
        menu = Options();
        switch(menu)
        {
            case 1:
                customerBasket.addProduct(siteBasket, noMore);
                break;
            case 2:
                customerBasket.removeProduct(siteBasket, removedCart, noMore);
                break;
            case 3:
                customerBasket.showCart(siteBasket);
                break;
            case 4:
                customerBasket.cartTotal(siteBasket);
                break;
            case 5:
                customerBasket.recentRemove(removedCart);
                break;
            case 6:
                customerBasket.outOfStock(noMore);
                break;
            case 7:
                cout << "Have a good day!\n";
                break;
        }
    }while(menu != 7);

    return 99;
};

int Options(){
    int MenuChoice;
        cout << endl << endl;
        cout << "Menu:\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. View Cart\n";
        cout << "4. View Total Cost\n";
        cout << "5. View Recently Removed Products\n";
        cout << "6. View Out-Of-Stock Products\n";
        cout << "7. Exit\n";
        cin >> MenuChoice;
        cout << endl;
    return MenuChoice;
};

void itemList(){
        cout << endl;
        cout << "Products:\n";
        cout << "Product ID: 101, Product Name: Phone Charger, Price: 15.50\n";
        cout << "Product ID: 102, Product Name: Batteries(24pk), Price: 25.74\n";
        cout << "Product ID: 201, Product Name: Bread, Price: 8.99\n";
        cout << "Product ID: 202, Product Name: Beef, Price: 39.12\n";
        cout << "Product ID: 301, Product Name: Jordans, Price: 149.99\n";
        cout << endl;
};
