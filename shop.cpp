
#include <iostream>
#include <vector>
#include "user.cpp"

using namespace std;

void show_menu() {
    vector<user> listOfUsers = {
        {"admin", "password", true, false}
    };

    while (true) {
        int option;
        cout << "Welcome to GameShop-PlusPlus!\n";
        cout << "Choose an option:\n";
        cout << "1. Games\n";
        cout << "2. Enquiries\n";
        cout << "3. Admin\n";
        cout << "4. Sign Up\n";
        cout << "5. Log In\n";
        cout << "6. Exit\n";
        cin >> option;

        if (option == 6) {
            cout << "Goodbye!\n";
            break;
        }

        if (option == 4) {
            string username, password;
            bool usernameExists = false;

            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            for (user aUser : listOfUsers) {
                if (aUser.username == username) {
                    cout << "Sorry, username already exists. Try another.\n";
                    usernameExists = true;
                    break;
                }
            }

            if (!usernameExists) {
                user newUser = {username, password, false, false};
                listOfUsers.push_back(newUser);
                cout << "Welcome, " << username << "!\n";

                while (true) {
                    cout << "1. Send a donation\n";
                    cout << "2. Log Out\n";
                    int user_choice;
                    cin >> user_choice;

                    switch (user_choice) {
                        case 1:
                            cout << "Thank you for your donation!\n\n";
                            break;
                        case 2:
                            cout << "You are now logged out!\n\n";
                            goto MainMenu;
                        default:
                            cout << "Invalid option. Please choose 1 or 2\n";
                    }
                }
            }
        }

        if (option == 5) {
            string username, password;
            bool found = false;

            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            for (user aUser : listOfUsers) {
                if (aUser.username == username && aUser.password == password) {
                    cout << "Welcome back, " << username << "!\n";
                    found = true;

                    while (true) {
                        cout << "1. Send a donation\n";
                        cout << "2. Log Out\n";
                        int user_choice;
                        cin >> user_choice;

                        switch (user_choice) {
                            case 1:
                                cout << "Thank you for your donation!\n\n";
                                break;
                            case 2:
                                cout << "You are now logged out!\n\n";
                                goto MainMenu;
                            default:
                                cout << "Invalid option. Please choose 1 or 2\n";
                        }
                    }
                }
            }

            if (!found) {
                cout << "Incorrect username or password. Please try again.\n";
            }
        }

        if (option == 1) {
            while (true) {
                cout << "Categories of Video Games:\n";
                cout << "1. RPG\n2. Action & Adventure\n3. Retro\n4. Puzzle\n5. Sports\n6. Go back\n";
                int choice;
                cin >> choice;

                if (choice == 6) break;

                switch (choice) {
                    case 1: cout << "RPG Games: The Last of Us, Zelda, Walking Dead\n"; break;
                    case 2: cout << "Action Games: Assassin's Creed, God of War, Resident Evil\n"; break;
                    case 3: cout << "Retro Games: Tetris, Pac-Man, Pong\n"; break;
                    case 4: cout << "Puzzle Games: Tetris, Pac-Man, Pong\n"; break;
                    case 5: cout << "Sports Games: FIFA, NHL, NBA\n"; break;
                    default: cout << "Invalid option. Try again.\n";
                }
            }
        }

        if (option == 2) {
            while (true) {
                cout << "Enquiries:\n1. Upcoming Releases\n2. Opening Hours\n3. Refund Policy\n4. Go back\n";
                int enquiry_choice;
                cin >> enquiry_choice;

                if (enquiry_choice == 4) break;

                switch (enquiry_choice) {
                    case 1: cout << "Upcoming Releases: GTA VI, Half-Life 3, Fallout 77\n"; break;
                    case 2: cout << "Opening Hours: Whenever we feel like it.\n"; break;
                    case 3: cout << "Refund Policy: No refunds, sorry!\n"; break;
                    default: cout << "Invalid option. Try again.\n";
                }
            }
        }

        if (option == 3) {
            string username, password;
            bool isAdmin = false;

            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            for (user aUser : listOfUsers) {
                if (aUser.username == username && aUser.password == password) {
                    if (aUser.isAdmin) {
                        cout << "Welcome Admin, " << username << "!\n";
                        isAdmin = true;
                        break;
                    } else {
                        cout << "You are not an admin.\n";
                        break;
                    }
                }
            }

            if (isAdmin) {
                while (true) {
                    cout << "Admin Menu:\n1. Admin Stuff\n2. Log Out\n";
                    int admin_choice;
                    cin >> admin_choice;

                    if (admin_choice == 2) break;

                    switch (admin_choice) {
                        case 1: cout << "<Insert boring admin tasks here>\n"; break;
                        default: cout << "Invalid option. Try again.\n";
                    }
                }
            }
        }
        MainMenu:;
    }
}

int main() {
    show_menu();
    return 0;
}
