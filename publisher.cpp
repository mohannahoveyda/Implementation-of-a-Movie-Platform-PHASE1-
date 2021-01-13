#include "publisher.h"
#include "film.h"
   Publisher :: Publisher(string _email, string _username, string _password, int _age, bool _is_publisher): User( _email, _username, _password, _age, _is_publisher){ myAddress=this;}
  void Publisher:: post_film(string film_name, int year, int length, int price, string summary, string director, vector <Film*> &filmsHead,int _lastFilmID){
     Film* newFilm= new Film(film_name,year,length,price, summary,director, _lastFilmID,this);
     filmsHead.push_back(newFilm);
     published_films.push_back(newFilm);
     string message;
     string SUserID=to_string(user_id);
     for (int i = 0; i <followers.size() ; i++)
     {
       followers[i]->add_notif("Publisher "+ username +" with id " + SUserID + " register new film.");
     }
  }
  void Publisher :: edit_film_info(int film_id, string film_name, double year, double length, string summary, string director){
   for (int i = 0; i < published_films.size(); i++)
   {
     if(published_films[i]->check_for_equal_filmID(film_id)){
      published_films[i]->editFilm(film_name,year, length, summary, director);
     }
   }
  }
  void Publisher :: delete_film(int film_id, vector <Film*> &filmsHead){
   for (int i = 0; i < published_films.size(); i++)
   {
     if(published_films[i]->check_for_equal_filmID(film_id)){
      published_films.erase(published_films.begin()+i);
     }
   }
   for (int j = 0; j < filmsHead.size(); j++)
   { 
    if (filmsHead[j]->check_for_equal_filmID(film_id))
    {
      filmsHead.erase(filmsHead.begin()+j);
     
    }
   }
  }
  
  void Publisher :: get_money(){
    
  }
  void Publisher :: show_film_list(string film_name, int min_rate, int min_year, int price, int max_year, string director){
    search(film_name, min_rate, min_year, price, max_year, director,published_films );
  }
  
  void Publisher :: print_myUploadedFilms(){
     cout<<"#. Film Id | Film Name | Film Length | Film Price | Rate | Production Year | Film Director"<<endl;
   for (int i = 0; i < published_films.size(); i++)
   {
     published_films[i]->print();
   }
  }

  void Publisher :: post_reply(int film_id, int _comment_id, string _content){
    for (int i = 0; i < published_films.size(); i++)
    {
       if(published_films[i]->check_for_equal_filmID(film_id)){
      published_films[i]->post_reply(_comment_id,_content);

     }

    }

  }

  void Publisher :: delete_comment(int film_id, int comment_id){
    for (int i = 0; i < published_films.size(); i++)
    {
      if (published_films[i]->check_for_equal_filmID(film_id))
      {
        published_films[i]->delete_comment(comment_id);
      }
    }
  }



 






