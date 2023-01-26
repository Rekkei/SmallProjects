#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product {
public:
    //Constructor for product
    Product(const string& name, const string& language,
        const string& genre, const string& category, int stock,
        float price, const string& product_code)
        : name(name),
        language(language),
        genre(genre),
        category(category),
        stock(stock),
        price(price),
        product_code(product_code) {}

    //Destructor for product
    virtual ~Product() = default;

    // Accessor methods
    string get_name() const { return name; }
    string get_language() const { return language; }
    string get_genre() const { return genre; }
    string get_category() const { return category; }
    int get_stock() const { return stock; }
    float get_price() const { return price; }
    string get_product_code() const { return product_code; }

    // Mutator methods
    void set_name(const string& name) { this->name = name; }
    void set_language(const string& language) { this->language = language; }
    void set_genre(const string& genre) { this->genre = genre; }
    void set_category(const string& category) { this->category = category; }
    void set_stock(int stock) { this->stock = stock; }
    void set_price(float price) { this->price = price; }
    void set_product_code(const string& product_code) {
        this->product_code = product_code;
    }

    virtual double calculate_discount() const { return 0.0; }
    virtual bool check_stock() const { return get_stock() > 0; }

    virtual void display() {
        cout << "Product name: " << name << endl;
        cout << "Language: " << language << endl;
        cout << "Genre: " << genre << endl;
        cout << "Category: " << category << endl;
        cout << "Stock: " << stock << endl;
        cout << "Price: " << price << endl;
        cout << "Product code: " << product_code << endl;
    }
    //Overloaded operator
    bool operator==(const Product& other) const {
        return name == other.name && language == other.language &&
            genre == other.genre && category == other.category &&
            stock == other.stock && price == other.price &&
            product_code == other.product_code;
    }

    bool operator!=(const Product& other) const { return !(*this == other); }

private:
    string name;
    string language;
    string genre;
    string category;
    int stock;
    float price;
    string product_code;
};

class Book : public Product {
private:
    string publisher;
    string isbn;

public:
    //Constructor for book
    Book(const string& name, const string& language, const string& genre,
        const string& category, int stock, float price, const string& product_code,
        const string& publisher, const string& isbn)
        : Product(name, language, genre, category, stock, price, product_code),
        publisher(publisher),
        isbn(isbn) {}

    // Accessor methods
    const string& get_publisher() const { return publisher; }
    const string& get_isbn() const { return isbn; }

    // Mutator methods
    void set_publisher(const string& publisher) { this->publisher = publisher; }
    void set_isbn(const string& isbn) { this->isbn = isbn; }

    // Virtual methods
    double calculate_discount() const override { return  get_price() * 0.12f; }
    bool check_stock() const override { return get_stock() > 0; }

    // Book-specific method
    void display() const {
        cout << "Name: " << get_name() << endl;
        cout << "Language: " << get_language() << endl;
        cout << "Genre: " << get_genre() << endl;
        cout << "Category: " << get_category() << endl;
        cout << "Stock:" << get_stock() << endl;
        cout << "Price: " << get_price() << endl;
        cout << "Product Code: " << get_product_code() << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "ISBN: " << isbn << endl;
    }
};


class Movie : public Product {
private:
    string director1;
    string director2;
    string starring1;
    string starring2;
    string starring3;
    string subtitles;
    string audio_language;

public:
    //Constructor for movie
    Movie(const string& name, const string& language, const string& genre,
        const string& category, int stock, float price, const string& product_code,
        const string& director1, const string& director2, const string& starring1,
        const string& starring2, const string& starring3, string subtitles,
        const string& audio_language)
        : Product(name, language, genre, category, stock, price, product_code),
        director1(director1),
        director2(director2),
        starring1(starring1),
        starring2(starring2),
        starring3(starring3),
        subtitles(subtitles),
        audio_language(audio_language) {}

    // Accessor methods
    const string& get_director1() const { return director1; }
    const string& get_director2() const { return director2; }
    const string& get_starring1() const { return starring1; }
    const string& get_starring2() const { return starring2; }
    const string& get_starring3() const { return starring3; }
    string has_subtitles() const { return subtitles; }
    const string& get_audio_language() const { return audio_language; }

    // Mutator methods
    void set_director1(const string& director1) { this->director1 = director1; }
    void set_director2(const string& director2) { this->director2 = director2; }
    void set_starring1(const string& starring1) { this->starring1 = starring1; }
    void set_starring2(const string& starring2) { this->starring2 = starring2; }
    void set_starring3(const string& starring3) { this->starring3 = starring3; }
    void set_subtitles(bool subtitles) { this->subtitles = subtitles; }
    void set_audio_language(const string& audio_language) {
        this->audio_language = audio_language;
    }

    // Virtual methods
    double calculate_discount() const override { return get_price() * 0.05f; }
    bool check_stock() const override { return get_stock() > 0; }

    // Movie-specific method
    void display() const {
        cout << "Name: " << get_name() << endl;
        cout << "Language: " << get_language() << endl;
        cout << "Genre: " << get_genre() << endl;
        cout << "Category: " << get_category() << endl;
        cout << "Stock: " << get_stock() << endl;
        cout << "Price: " << get_price() << endl;
        cout << "Product Code: " << get_product_code() << endl;
        cout << "Director 1: " << director1 << endl;
        cout << "Director 2: " << director2 << endl;
        cout << "Starring 1: " << starring1 << endl;
        cout << "Starring 2: " << starring2 << endl;
        cout << "Starring 3: " << starring3 << endl;
        cout << "Audio Language: " << audio_language << endl;
    }
};


class Music : public Product {
private:
    string artist;
    string format;
    int run_time;

public:
    //Constructor for music
    Music(const string& name, const string& language, const string& genre,
        const string& category, int stock, float price, const string& product_code,
        const string& artist, const string& format, int run_time)
        : Product(name, language, genre, category, stock, price, product_code),
        artist(artist),
        format(format),
        run_time(run_time) {}

    // Accessor methods
    const string& get_artist() const { return artist; }
    const string& get_format() const { return format; }
    int get_run_time() const { return run_time; }

    // Mutator methods
    void set_artist(const string& artist) { this->artist = artist; }
    void set_format(const string& format) { this->format = format; }
    void set_run_time(int run_time) { this->run_time = run_time; }

    // Virtual methods
    double calculate_discount() const override { return  get_price() * 0.15f; }
    bool check_stock() const override { return get_stock() > 0; }

    // Music-specific method
    void display() const {
        cout << "Name: " << get_name() << endl;
        cout << "Language: " << get_language() << endl;
        cout << "Genre: " << get_genre() << endl;
        cout << "Category: " << get_category() << endl;
        cout << "Stock: " << get_stock() << endl;
        cout << "Price: " << get_price() << endl;
        cout << "Product Code: " << get_product_code() << endl;
        cout << "Artist: " << artist << endl;
        cout << "Format: " << format << endl;
        cout << "Run Time: " << run_time << endl;
    }
};

class Cart {
private:
    vector<Product*> products;
    float total_price;

public:
    //Constrcutor for cart
    Cart() : total_price(0.0f) {}

    // Accessor methods
    const vector<Product*>& get_products() const { return products; }
    float get_total_price() const { return total_price; }

    // Mutator methods
    void set_products(const vector<Product*>& products) { this->products = products; }
    void set_total_price(float total_price) { this->total_price = total_price; }

    // Cart-specific methods
    void add_product(Product* product) {
        if (products.size() >= 5) {
            cout << "Error: Cart is full!" << endl;
            return;
        }
        products.push_back(product);
        total_price += product->get_price();
    }

    void remove_product(int index) {
        if (index < 0 || index >= products.size()) {
            cout << "Error: Invalid product index!" << endl;
            return;
        }
        total_price -= products[index]->get_price();
        products.erase(products.begin() + index);
    }

    void display() const {
        cout << "Total price: " << total_price << endl;
        cout << "Products: " << endl;
        for (int i = 0; i < products.size(); i++) {
            cout << i << ": " << endl;
            cout << "  Name: " << products[i]->get_name() << endl;
            cout << "  Price: " << products[i]->get_price() << endl;
        }
    }
};


//Update total templete function
/*template <typename T>
void update_total_price(Cart& cart, const T& product, double discount_rate) {
    float updated_price = product.get_price() - product.get_price() * discount_rate;
    cart.set_total_price(cart.get_total_price() + updated_price);
}*/

int main() {
    // Create some sample products for each category


    vector<Book> books = {
       {"The Alchemist", "English", "Fiction", "Book", 10, 20.0, "B001", "Harper Collins", "1234567890123"},
       {"Pride and Prejudice", "English", "Fiction", "Book", 5, 15.0, "B002", "Penguin Books", "2345678901234"},
       {"1984", "English", "Dystopian", "Book", 7, 17.0, "B003", "Signet Classics", "3456789012345"}
    };
    vector<Movie> movies;
    vector<Music> musics;
    bool flag;
    float pricenumber;
    string login_type, yes_no;
    int firstchoice, listchoice, productchoice, lastchoice, categorychoice, choose, removechoose, stocknumber;
    cout << "Welcome to the online shopping website!" << endl;
    cout << "Press Enter to login as a customer or type * to login as an admin: ";
    getline(cin, login_type);
    if (login_type == "*") {
        // Admin login
        while (true) {
        menu1:
            cout << "Admin Menu:" << endl;
            cout << "1)Update product information" << endl;
            cout << "2)Exit" << endl;
            cin >> firstchoice;
            if (firstchoice == 2) {
                //Exit
                break;
            }
            if (firstchoice == 1) {
                //Update product
            menu2:
                cout << "1)Book" << endl;
                cout << "1)Movie" << endl;
                cout << "1)Music" << endl;
                cout << "4)Exit" << endl;
                cout << "Enter your choice: ";
                cin >> listchoice;
            }
            if (listchoice == 1) {
                //Update product-book
                for (int i = 0; i < books.size(); i++) {
                    cout << i + 1 << ")";
                    books[i].display();
                }
                cout << "Choose a product:";
                cin >> productchoice;
                cout << "1)Update stock" << endl;
                cout << "2)Update price" << endl;
                cout << "3)Exit" << endl;
                cin >> lastchoice;
                if (lastchoice == 1) {
                    //Update stock-book
                    cout << "Enter new stock:";
                    cin >> stocknumber;
                    books[productchoice - 1].set_stock(stocknumber);

                }
                else if (lastchoice == 2) {
                    //Update price-book
                    cout << "Enter new price:";
                    cin >> pricenumber;
                    books[productchoice - 1].set_price(pricenumber);
                }
                else if (lastchoice == 3) {
                    //Exit to second menu
                    goto menu2;
                }
            }
            else if (listchoice == 2) {
                //Update product-movie
                for (int i = 0; i < movies.size(); i++) {
                    cout << i + 1 << ")";
                    movies[i].display();
                }
                cout << "Choose a product:";
                cin >> productchoice;
                cout << "1)Update stock" << endl;
                cout << "2)Update price" << endl;
                cout << "3)Exit" << endl;
                if (lastchoice == 1) {
                    //Update stock-movie
                    cout << "Enter new stock:";
                    cin >> stocknumber;
                    movies[productchoice - 1].set_stock(stocknumber);

                }
                else if (lastchoice == 2) {
                    //Update price-movie
                    cout << "Enter new price:";
                    cin >> pricenumber;
                    movies[productchoice - 1].set_price(pricenumber);
                }
                else if (lastchoice == 3) {
                    //Exit to second menu
                    goto menu2;
                }
            }
            else if (listchoice == 3) {
                //Update product-music
                for (int i = 0; i < musics.size(); i++) {
                    cout << i + 1 << ")";
                    musics[i].display();
                }
                cout << "Choose a product:";
                cin >> productchoice;
                cout << "1)Update stock" << endl;
                cout << "2)Update price" << endl;
                cout << "3)Exit" << endl;
                if (lastchoice == 1) {
                    //Update stock-music
                    cout << "Enter new stock";
                    cin >> stocknumber;
                    musics[productchoice - 1].set_stock(stocknumber);

                }
                else if (lastchoice == 2) {
                    //Update price-music
                    cout << "Enter new price";
                    cin >> pricenumber;
                    musics[productchoice - 1].set_price(pricenumber);
                }
                else if (lastchoice == 3) {
                    //Exit to second menu
                    goto menu2;
                }
            }
            else if (listchoice == 4) {
                //Exit to first menu
                goto menu1;
            }


        }
    }
    else {
        //Customer login
        while (true) {
            Cart cart;
        menu3:
            cout << "1)View cart" << endl;
            cout << "2)Select category" << endl;
            cout << "3)Exit" << endl;
            cin >> firstchoice;
            if (firstchoice == 1) {
                //Show cart
                cart.display();
            }
            else if (firstchoice == 2) {
                cout << "1)Book" << endl;
                cout << "2)Movie" << endl;
                cout << "3)Music" << endl;
                cout << "4)Exit" << endl;
                cin >> categorychoice;
                if (categorychoice == 1) {
                    //Display the list of books
                    for (int i = 0; i < books.size(); i++) {
                        cout << i + 1 << ")";
                        books[i].display();

                    }
                    cout << "1)Select product" << endl;
                    cout << "2)Remove product" << endl;
                    cout << "3)Exit" << endl;
                    cin >> productchoice;
                    if (productchoice == 1) {
                        //Select and add product-book
                        cout << "Choose a book:";
                        cin >> choose;
                        Product* book_ptr = static_cast<Product*>(&books[choose - 1]);
                        cart.add_product(book_ptr);

                        //update_total_price(cart,&books,book_ptr->calculate_discount());
                    }
                    else if (productchoice == 2) {
                        //Remove product-book
                        cout << "Choose a book to remove";
                        cin >> removechoose;
                        cart.remove_product(removechoose);
                    }
                    else if (productchoice == 3) {
                        //Exit to first menu
                        goto menu3;
                    }
                }
                else if (categorychoice == 2) {
                    //Display the list of movies
                    for (int i = 0; i < movies.size(); i++) {
                        cout << i + 1 << ")";
                        movies[i].display();
                    }
                    cout << "1)Select product" << endl;
                    cout << "2)Remove product" << endl;
                    cout << "2)Exit" << endl;
                    cin >> productchoice;
                    if (productchoice == 1) {
                        //Select and product-movie
                        cout << "Choose a movie";
                        cout << choose;
                        Product* movie_ptr = static_cast<Product*>(&movies[choose]);
                        cart.add_product(movie_ptr);
                        //update_total_price(cart, movie_ptr, movie_ptr->calculate_discount());
                    }
                    else if (productchoice == 2) {
                        //Select and product-movie
                        cout << "Choose a movie to remove";
                        cin >> removechoose;
                        cart.remove_product(removechoose);
                    }
                    else if (productchoice == 3) {
                        //Exit to first menu
                        goto menu3;
                    }
                }
                else if (categorychoice == 3) {
                    //Display the list of musics
                    for (int i = 0; i < musics.size(); i++) {
                        cout << i + 1 << ")";
                        musics[i].display();
                    }
                    cout << "1)Select product" << endl;
                    cout << "2)Remove product" << endl;
                    cout << "2)Exit" << endl;
                    cin >> productchoice;
                    if (productchoice == 1) {
                        //Select and add product-music
                        cout << "Choose a music";
                        cin >> choose;
                        Product* music_ptr = static_cast<Product*>(&musics[choose]);
                        cart.add_product(music_ptr);
                        //update_total_price(cart, music_ptr, music_ptr->calculate_discount());
                    }
                    else if (productchoice == 2) {
                        //Remove product-music
                        cout << "Choose a movie to remove";
                        cin >> removechoose;
                        cart.remove_product(removechoose);
                    }
                    else if (productchoice == 3) {
                        //Exit to first menu
                        goto menu3;
                    }
                }

                else if (categorychoice == 4) {
                    //Exit
                    if (flag = true) {
                        goto menu3;
                    }
                    else if (flag = false) {
                        cout << "You did not confirm your cart!!";
                        goto menu3;
                    }

                }
                cout << "Do you confirm your cart(y/n):";
                cin >> yes_no;
                if (yes_no == "y") {
                    cout << "Your cart confirmed." << endl;
                    flag = true;
                }
                else if (yes_no == "n") {
                    flag = false;
                }

            }
            else if (firstchoice == 3) {
                cout << "Are you sure to exit(y/n):";
                cin >> yes_no;
                if (yes_no == "y") {

                    break;
                }
            }
        }


    }
    return 0;
}
