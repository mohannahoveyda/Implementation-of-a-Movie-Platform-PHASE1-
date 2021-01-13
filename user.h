#ifndef USER_H
#define USER_H
#include "film.h"
#include <iostream>
#include <vector>
using namespace std;
class Film;
class User{

protected:
  string username;
  int user_id;
  string password;
  string email;
  int age;
  bool is_publisher=false;
  int cash;
  vector<Film*> purchased_films;
  vector<User*> followers;
  vector <User*> followings;
  vector <string> unreadNotif;
  vector <string> allNotif;
  
public:
  User(string _username, string _password, string _email, int _age, bool _is_publisher);
  void set_username(string _username);
  void set_user_id(int _user_id);
  void set_password(string _password);
  void set_email(string _email);
  void set_age(int _age);
  void set_is_publisher(bool _is_publisher);
  void set_cash(double _cash);
  bool IsPublisher();
  string get_username();
  string get_password();
  int get_user_id();
  void add_follower(User* u);
  void add_following(User* u);
  bool login(string _username, string _password);
  void show_followers();
  void print();
  void add_cash(int amount);
  void spend_cash(int amount);
  void search(string film_name, int min_rate, int min_year, int price, int max_year, string director, vector <Film*> &filmsHead);
  void get_film_detail(int film_id);
  void buy_film(int film_id, vector <Film*> &filmsHead);
  void rate_film(int film_id, float score);
 void show_purchased_films(string name, int _price, int min_year,int max_year, string director);
 void post_comment(int film_id,int _comment_id, string _content);
 bool check_if_film_exists_in_purchased_films(int film_id);
 void add_notif(string notif);
  void show_unread_notifications();
  void show_all_notifications(int limit);

};
#endif