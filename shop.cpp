#include <iostream>
using namespace std;

void show_menu() {
    while (true) {
        int option;
        cout << "Welcome to GameShop-PlusPlus!\n";
        cout << "Choose an option:\n";
        cout << "1. Games\n";
        cout << "2. Enquiries\n";
        cout << "3. Exit\n";
        cin >> option;

        if (option == 3) {
            cout << "Goodbye!\n";
            break;
        }

        if (option == 1) {
            while (true) {
                cout << "Displaying categories of games...\n";
                cout << "Categories of Video Games:\n";
                cout << "1. RPG\n";
                cout << "2. Action & Adventure\n";
                cout << "3. Retro\n";
                cout << "4. Puzzle\n";
                cout << "5. Sports\n";
                cout << "6. Go back to main menu\n";
                int choice;
                cin >> choice;

                if (choice == 6) break;

                switch (choice) {
                    case 1:
                        cout << "\nGames in RPG category:\n";
                        cout << "1. The Last of Us\n";
                        cout << "2. The Legend of Zelda\n";
                        cout << "3. The Walking Dead\n";
                        break;
                    case 2:
                        cout << "\nGames in Action & Adventure category:\n";
                        cout << "1. Assassin's Creed\n";
                        cout << "2. God of War\n";
                        cout << "3. Resident Evil\n";
                        break;
                    case 3:
                        cout << "\nGames in Retro category:\n";
                        cout << "1. Tetris\n";
                        cout << "2. Pac-Man\n";
                        cout << "3. Pong\n";
                        break;
                    case 4:
                        cout << "\nGames in Puzzle category:\n";
                        cout << "1. Tetris\n";
                        cout << "2. Pac-Man\n";
                        cout << "3. Pong\n";
                        break;
                    case 5:
                        cout << "\nGames in Sports category:\n";
                        cout << "1. Fifa\n";
                        cout << "2. NHL\n";
                        cout << "3. NBA\n";
                        break;
                    default:
                        cout << "Invalid option. Please choose a valid category\n";
                        break;
                }
            }
        } else if (option == 2) {
            while (true) {
                cout << "You selected Enquiries!\n";
                cout << "What would you like to enquire about?\n";
                cout << "1. Upcoming Releases\n";
                cout << "2. Opening Hours\n";
                cout << "3. Refund Policy?\n";
                cout << "4. Go back to main menu\n";
                int enquiry_choice;
                cin >> enquiry_choice;

                if (enquiry_choice == 4) break;

                switch (enquiry_choice) {
                    case 1:
                        cout << "1. GTA VI\n";
                        cout << "2. Half Life 3\n";
                        cout << "3. Fallout 77\n";
                        break;
                    case 2:
                        cout << "When we feel like it\n";
                        break;
                    case 3:
                        cout << "Sorry, Link, I can't give credit. Come back when you're a little mmm... Richer!\n";
                        break;
                    default:
                        cout << "Invalid option. Please choose a valid option or 0 to go back.\n";
                        break;
                }
            }
        } else {
            cout << "Invalid option. Please choose 1, 2, or 3\n";
        }
    }
}

int main() {
    show_menu();
    return 0;
}
