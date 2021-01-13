#ifndef NETFLIX_H
#define NETFLIX_H
#include "film.h"
#include "publisher.h"
#include "user.h"
#include "comment.h"
#include "reply.h"
#include "dastoor.h"
#include "functions.h"
#include <iostream>
#include <vector>
using namespace std;

class Netflix{    

private:
  vector <Film*> films;
  vector<User*>users;
  User* currentUserPtr;
  int lastFilmID=1;
  int lastCommentID=1;
  int lastReplyID=1;

 
  int network_cash;

public:
    User* get_currentUserPtr();
    void signup(string _email, string _username, string _password, int _age, bool _is_publisher);
    void login(string _username, string _password);
    void follow(int user_id);
    void print_users();
    void post_film(string film_name, int year, int length, int price, string summary, string director);
     void edit_film(int film_id, string film_name, int year, int length, string summary, string director);
    void delete_film(int film_id);
    void print_films();
    void show_followers(int user_id);
    void print_currentUserFilms();
    void buy_film(int film_id);
    void show_film_list(string film_name, int min_rate, int min_year, int price, int max_year, string director);
    void rate_film(int film_id, float score);
    void show_purchased_films(string name, int _price, int min_year,int max_year, string director);
    void print_film_detail(int film_id);
    void recommend_film(int film_id);
    void post_comment(int film_id, string _content);
    void post_reply(int _film_id, int comment_id, string _content);
    void delete_comment(int film_id, int comment_id);
    void show_unread_notifications();
    void show_all_notifications(int limit);
    void showFollowers();
    void addCash(int amount);
    
    void process(string newline);
};
#endif