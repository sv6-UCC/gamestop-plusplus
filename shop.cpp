#include <iostream>
using namespace std;

void show_menu(int option) {
    if (option == 1) { 
        std::cout << "Displaying categories of games...\n";
        std::cout << "Categories of Video Games:\n";
        std::cout << "1. RPG\n";
        std::cout << "2. Action & Adventure\n";
        std::cout << "3. Retro\n";
        std::cout << "4. Puzzle\n";
        std::cout << "5. Sports\n";
        int choice;
        cin >> choice; // Get user choice for a category

        switch(choice) {
            case 1: {
                cout << "\nGames in RPG category:\n";
                cout << "1. The Last of Us\n";
                cout << "2. The Legend of Zelda\n";
                cout << "3. The Walking Dead\n";
                break;
            }
            case 2: {
                cout << "\nGames in Action & Adventure category:\n";
                cout << "1. Assassin's Creed\n";
                cout << "2. God of War\n";
                cout << "3. Resident Evil\n";
                break;
            }
            case 3: {
                cout << "\nGames in retro category:\n";
                cout << "1. Tetris\n";
                cout << "2. Pac-Man \n";
                cout << "3. Pong\n";
                break;
            }
            case 4: {
                cout << "\nGames in Puzzle category:\n";
                cout << "1. Tetris\n";
                cout << "2. Pac-Man\n";
                cout << "3. Pong\n";
                break;
            }
            case 5: {
                cout << "\nGames in Sports category:\n";
                cout << "1. Fifa\n";
                cout << "2. NHL\n";
                cout << "3. NBA\n";
                break;
            }
            default:
                cout << "Invalid option. Please choose a valid category.\n";
                break;
        }
    } else if (option == 2) {
        std::cout << "You selected Enquiries!\n";
        std::cout << "What would you like to enquire about?\n";
        std::cout << "1. Upcoming Releases\n";
        std::cout << "2. Opening Hours\n";
        std::cout << "3. Refund Policy?\n";
        int enquiry_choice;
        cin >> enquiry_choice;

        switch(enquiry_choice) {
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
                cout << "Learn to count.\n";
                break;
        }
    } else {
        std::cout << "Invalid option.\n";
    }
}

int main() {
    int option;
    cout << "Enter option (1 to view categories of video games, 2 for enquiries): ";
    cin >> option;
    show_menu(option);
    return 0;
}