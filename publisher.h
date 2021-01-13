 #ifndef PUBLISHER_H
 #define PUBLISHER_H
#include "user.h"
//#include "film.h"

#include <iostream>
#include <vector>
class Film;

using namespace std;

class Publisher : public User{
private:
  vector<Film*> published_films;
  Publisher* myAddress;
public:
  Publisher(string _username, string _password, string _email, int _age, bool _is_publisher);
  void post_film(string film_name, int year, int length, int price, string summary, string director, vector <Film*> &filmsHead,int _lastFilmID);
  void edit_film_info(int film_id, string film_name, double year, double length, string summary, string director);
  void delete_film(int film_id, vector <Film*> &filmsHead);
  
  void get_money();
  void show_film_list(string film_name, int min_rate, int min_year, int _price, int max_year, string director);
  void print_myUploadedFilms();
  void post_reply(int film_id, int _comment_id, string _content);
  void delete_comment(int film_id, int comment_id);
};
 #endif