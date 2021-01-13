#ifndef FILM_H
#define FILM_H
//#include "publisher.h"
//#include "comment.h"
#include <iostream>
#include <vector>

using namespace std;
class User;
class Comment;
class Publisher;
class Film{

private:
  string name;
  int year;
  int length;
  int price;
  string summary;
  string director;
  int film_id;
  Publisher* owner;
  vector <Comment*> comments;
  double sum_of_rates=0;
  int num_of_rates=0;
 public:
  void transfer_cash();
  void print();
  bool check_for_equal_filmID(int _film_id);
  int get_price();
  Film();
  Film(string _name, int _year, int _length, int _price, string _summary, string _director,int _film_id ,Publisher* _owner);
  void editFilm(string film_name, double _year, double _length, string _summary, string _director);
  bool search(string film_name, int min_rate, int min_year, int _price, int max_year, string _director);
  void add_rate(float _rate);
  void print_film_detail();
  void  post_comment(int film_id,int _comment_id, string _content, User* _u);
  void post_reply(int _comment_id, string _content);
  void delete_comment( int comment_id);
  int get_film_id();
  void send_notif(string notif);
  bool is_greater(Film* f);
  float get_rate();
};
  #endif