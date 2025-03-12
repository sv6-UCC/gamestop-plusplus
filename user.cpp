#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct user {
  string username;
  string password;
  bool isAdmin;
  bool isLoggedIn = false;
};
