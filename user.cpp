#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
  public:
      string username;
      string password;
      bool isAdmin;
  
      User(string uname, string pword, bool admin = false)
          : username(uname), password(pword), isAdmin(admin){}
  };
