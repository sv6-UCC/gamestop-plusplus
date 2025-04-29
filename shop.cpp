
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "user.cpp"
#include "game.cpp"

using namespace std;

class ShoppingCart {
    private:
        vector<Game> cart;
    public:
        void addGame(const Game& game) {
            cart.push_back(game);
        }
    
        void viewCart() const {
            if (cart.empty()) {
                cout << "Your cart is empty.\n";
            } else {
                cout << "Your Shopping Cart:\n";
                int count = 1;
                for (auto& game : cart) {
                    cout << count++ << ". " << game.title << " - $" << game.price << endl;
                }
            }
        }
    
        void checkout() {
            if (cart.empty()) {
                cout << "Your cart is empty. Nothing to checkout.\n";
                return;
            }
            double total = 0;
            for (auto& game : cart) {
                total += game.price;
            }
            cout << "Your total is: $" << total << ". Thank you for your purchase!\n";
        
            cart.clear(); //
        }
    };
    
    
    void showGamesMenu(vector<Game>& games, ShoppingCart& cart) {
        while (true) {
            cout << "\nGames Available:\n";
            int idx = 1;
            for (auto& game : games) {
                cout << idx++ << ". " << game.title << " (" << game.category << ") - $" << game.price << endl;
            }
            cout << idx << ". Go back\n";
    
            int choice;
            cout << "Select a game to add to cart: ";
            cin >> choice;
    
            if (choice == idx) break;
    
            if (choice >= 1 && choice < idx) {
                cart.addGame(games[choice - 1]);
                cout << games[choice - 1].title << " added to cart.\n";
            } else {
                cout << "Invalid choice.\n";
            }
        }
    }
    
    void handleUserMenu(User& currentUser, vector<Game>& games) {
        ShoppingCart cart;
        int option;
    
        while (true) {
            cout << "\nWelcome, " << currentUser.username << "!\n";
            cout << "1. Browse Games\n2. View Cart\n3. Checkout\n4. Donate\n5. Logout\n";
            cout << "Enter option: ";
            cin >> option;
    
            switch (option) {
                case 1: showGamesMenu(games, cart); break;
                case 2: cart.viewCart(); break;
                case 3: cart.checkout(); break;
                case 4: cout << "Thank you for your donation!\n"; break;
                case 5: cout << "Logging out...\n"; return;
                default: cout << "Invalid choice.\n";
            }
        }
    }
    
    void handleAdminMenu(User& adminUser, vector<User>& users) {
        int option;
        while (true) {
            cout << "\nAdmin Menu:\n";
            cout << "1. View Users\n2. Logout\n";
            cout << "Enter option: ";
            cin >> option;
    
            if (option == 2) break;
    
            switch (option) {
                case 1:
                    cout << "\nRegistered Users:\n";
                    for (auto& u : users) {
                        cout << "- " << u.username << (u.isAdmin ? " [Admin]" : "") << endl;
                    }
                    break;
                default: cout << "Invalid choice.\n";
            }
        }
    }
    
    void mainMenu() {
        vector<User> users = { User("admin", "admin123", true) };
        vector<Game> games = {
            Game("The Last of Us", "RPG", 59.99),
            Game("Zelda", "RPG", 49.99),
            Game("Walking Dead", "RPG", 39.99),
            Game("Assassin's Creed", "Action", 59.99),
            Game("God of War", "Action", 69.99),
            Game("Resident Evil", "Action", 39.99),
            Game("Tetris", "Puzzle", 9.99),
            Game("Pac-Man", "Retro", 14.99),
            Game("FIFA", "Sports", 59.99)
        };
    
        int option;
        while (true) {
            cout << "\nWelcome to GameShop-PlusPlus!\n";
            cout << "1. Sign Up\n2. Log In\n3. Exit\n";
            cout << "Choose an option: ";
            cin >> option;
    
            if (option == 3) {
                cout << "Goodbye!\n";
                break;
            }
    
            if (option == 1) {
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
            
                bool exists = false;
                for (auto& u : users) {
                    if (u.username == username) {
                        exists = true;
                        break;
                    }
                }
            
                if (exists) {
                    cout << "Username already exists.\n";
                } else {
                    User newUser(username, password);
                    users.push_back(newUser);
                    cout << "Account created successfully!\n";
                    handleUserMenu(newUser, games);
                }
            }
    
            if (option == 2) {
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
    
                bool found = false;
                for (auto& u : users) {
                    if (u.username == username && u.password == password) {
                        found = true;
                        if (u.isAdmin) {
                            handleAdminMenu(u, users);
                        } else {
                            handleUserMenu(u, games);
                        }
                        break;
                    }
                }
    
                if (!found) {
                    cout << "Incorrect username or password.\n";
                }
            }
        }
    }
    
    int main() {
        mainMenu();
        return 0;
    }
