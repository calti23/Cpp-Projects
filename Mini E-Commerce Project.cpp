#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int stock;

public:
    Product(int id, string name, double price, int stock) 
        : id(id), name(name), price(price), stock(stock) {}

    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    bool reduceStock(int quantity) {
        if (stock >= quantity) {
            stock -= quantity;
            return true;
        }
        return false;
    }

    void displayProduct() const {
        cout << left << setw(8) << id 
             << setw(25) << name 
             << setw(12) << fixed << setprecision(2) << price 
             << setw(8) << stock << endl;
    }
};

struct CartItem {
    Product* product;
    int quantity;

    double getTotalPrice() const {
        return product->getPrice() * quantity;
    }
};

class Cart {
private:
    vector<CartItem> items;

public:
    void addToCart(Product* product, int quantity) {
        if (quantity <= 0) {
            cout << "Gecersiz miktar!\n";
            return;
        }

        if (product->getStock() < quantity) {
            cout << "Yetersiz stok! Mevcut stok: " << product->getStock() << endl;
            return;
        }

        for (auto& item : items) {
            if (item.product->getId() == product->getId()) {
                if (product->getStock() < (item.quantity + quantity)) {
                    cout << "Sepetinizdeki miktar ile birlikte stok sinirini asiyorsunuz!\n";
                    return;
                }
                item.quantity += quantity;
                cout << "Urun sepetteki miktari guncellendi.\n";
                return;
            }
        }

        items.push_back({product, quantity});
        cout << product->getName() << " sepete eklendi.\n";
    }

    void viewCart() const {
        if (items.empty()) {
            cout << "\nSepetiniz bos!\n";
            return;
        }

        cout << "\n================= ALISVERIS SEPETI =================\n";
        cout << left << setw(25) << "Urun Adi" 
             << setw(10) << "Adet" 
             << setw(12) << "Birim Fiyat" 
             << setw(12) << "Toplam" << endl;
        cout << "----------------------------------------------------\n";

        double grandTotal = 0;
        for (const auto& item : items) {
            double total = item.getTotalPrice();
            grandTotal += total;
            cout << left << setw(25) << item.product->getName()
                 << setw(10) << item.quantity
                 << setw(12) << fixed << setprecision(2) << item.product->getPrice()
                 << setw(12) << total << " TL" << endl;
        }
        cout << "----------------------------------------------------\n";
        cout << "GENEL TOPLAM: " << grandTotal << " TL\n";
        cout << "====================================================\n";
    }

    bool checkout() {
        if (items.empty()) {
            cout << "Sepetiniz bos, satin alma islemi yapilamaz!\n";
            return false;
        }

        for (auto& item : items) {
            item.product->reduceStock(item.quantity);
        }

        cout << "\n--- ODEME BASARILI! ---";
        viewCart();
        cout << "Siparisiniz alinmistir. Bizi tercih ettiginiz icin tesekkur ederiz!\n";
        
        items.clear(); 
        return true;
    }
};

class Store {
private:
    vector<Product> products;
    Cart cart;

public:
    void addProduct(const Product& p) {
        products.push_back(p);
    }

    void displayCatalog() const {
        cout << "\n================ URUNT KATALOGU ================\n";
        cout << left << setw(8) << "ID" 
             << setw(25) << "Urun Adi" 
             << setw(12) << "Fiyat (TL)" 
             << setw(8) << "Stok" << endl;
        cout << "------------------------------------------------\n";
        for (const auto& p : products) {
            p.displayProduct();
        }
        cout << "================================================\n";
    }

    Product* findProduct(int id) {
        for (auto& p : products) {
            if (p.getId() == id) {
                return &p;
            }
        }
        return nullptr;
    }

    void run() {
        int choice;
        while (true) {
            cout << "\n=== C++ MINI E-COMMERCE SISTEMI ===\n";
            cout << "1. Urun Katalogunu Goruntule\n";
            cout << "2. Sepete Urun Ekle\n";
            cout << "3. Sepeti Goruntule\n";
            cout << "4. Siparisi Tamamla (Checkout)\n";
            cout << "5. Cikis\n";
            cout << "Seciminiz: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Gecersiz giris! Lütfen bir sayi girin.\n";
                continue;
            }

            switch (choice) {
                case 1:
                    displayCatalog();
                    break;
                case 2: {
                    displayCatalog();
                    int id, qty;
                    cout << "Eklenecek Urun ID: ";
                    cin >> id;
                    Product* p = findProduct(id);
                    if (p) {
                        cout << "Kac adet eklemek istiyorsunuz?: ";
                        cin >> qty;
                        cart.addToCart(p, qty);
                    } else {
                        cout << "Urun bulunamadi!\n";
                    }
                    break;
                }
                case 3:
                    cart.viewCart();
                    break;
                case 4:
                    cart.checkout();
                    break;
                case 5:
                    cout << "Cikis yapiliyor. Iyi gunler!\n";
                    return;
                default:
                    cout << "Gecersiz secim, tekrar deneyin.\n";
            }
        }
    }
};

int main() {
    Store myStore;

    myStore.addProduct(Product(101, "Laptop", 25000.00, 5));
    myStore.addProduct(Product(102, "Kablosuz Fare", 450.50, 15));
    myStore.addProduct(Product(103, "Mekanik Klavye", 1200.00, 8));
    myStore.addProduct(Product(104, "Kulaklik", 850.00, 10));

    myStore.run();

    return 0;
}
