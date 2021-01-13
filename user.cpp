#include "user.h"
#include "film.h"
  User :: User(string _email, string _username, string _password, int _age, bool _is_publisher): username(_username), password(_password), email(_email), age(_age), is_publisher(_is_publisher){}
  void User :: set_username(string _username){ username=_username;}
  void User :: set_user_id(int _user_id){user_id=_user_id;}
  void User :: set_password(string _password){ password=_password;}
  void User :: set_email(string _email){ email=_email; }
  void User :: set_age(int _age){age=_age;}
  void User :: set_is_publisher(bool _is_publisher){ is_publisher=_is_publisher;}
  void User :: set_cash(double _cash){ cash=_cash;}
  bool User :: IsPublisher(){return is_publisher;}
  string User :: get_username(){return username;}
  string User :: get_password(){return password;}
  
  int User :: get_user_id(){return user_id;}

  void User :: add_follower(User* u){
    followers.push_back(u);
  }
  void User :: add_following(User* u){
    followings.push_back(u);
  }


  bool User :: login(string _username, string _password){
    if(_username==username && _password==password){
      return true;
    }
    else{
      return false;
    }
  }
  void User :: show_followers(){
   cout<<"#. User Id | User Username | User Email" <<endl;
    for (int i = 0; i < followers.size(); ++i)
    {
     followers[i]->print();
    }
  }


  void User :: print(){
   cout<< user_id<< "|" << username<<"|"<<email<<endl;
  }

  void User :: add_cash(int amount){ cash+=amount; cout<< "cash is: "<< cash<< endl; }
  void User :: spend_cash(int amount){ cash-=amount;  cout<< "cash is: "<< cash<< endl;}
  void User :: search(string film_name, int min_rate, int min_year, int _price, int max_year, string _director, vector <Film*> &filmsHead){
     cout<<"#. Film Id | Film Name | Film Length | Film Price | Rate | Production Year | Film Director"<<endl;
    for(int i=0; i<filmsHead.size(); i++){
     if (filmsHead[i]->search(film_name, min_rate,min_year, _price,  max_year,  _director))
     {
      filmsHead[i]->print();

     }
    }
  }
  void User :: buy_film(int film_id, vector <Film*> &filmsHead){
    for(int i=0; i<filmsHead.size(); i++){
     if (filmsHead[i]->check_for_equal_filmID(film_id))
     {
       purchased_films.push_back(filmsHead[i]);
       spend_cash(filmsHead[i]->get_price());
       filmsHead[i]->transfer_cash();
       filmsHead[i]->send_notif("User "+ username + " with id " + to_string(user_id) + " buy your film ");

     }
    }
  }
  

  void User :: rate_film(int film_id, float score){
    for (int i = 0; i < purchased_films.size(); i++)
    {
      if(purchased_films[i]->check_for_equal_filmID(film_id)){
        purchased_films[i]->add_rate(score);
        purchased_films[i]->send_notif("User "+ username + " with id " + to_string(user_id)  + " rate your film ");
      }
    }
  }
   void User :: show_purchased_films(string name, int _price, int min_year,int max_year, string _director){

     search(name, -1, min_year, _price, max_year, _director,purchased_films );
    
   }
 void User :: post_comment(int film_id, int _comment_id, string _content){
  for (int i = 0; i < purchased_films.size(); i++)
  {
    if(purchased_films[i]->check_for_equal_filmID(film_id)){
      purchased_films[i]->post_comment(film_id, _comment_id, _content, this );
    }
  }
 }
 
 bool User :: check_if_film_exists_in_purchased_films(int film_id){
  bool flag=false;
  for (int i = 0; i < purchased_films.size(); i++)
  {
    if(purchased_films[i]->check_for_equal_filmID(film_id)){
      flag=true;
    }
  }
  return flag;
 }

 void User :: add_notif(string notif){
  allNotif.push_back(notif);
  unreadNotif.push_back(notif);
 }


  void User :: show_unread_notifications(){
    for (int i = unreadNotif.size()-1; i>= 0; i--)
  {
    cout<< unreadNotif[i]<<endl;
  }
  unreadNotif.clear();
 
}
  void User :: show_all_notifications(int limit){
    if (limit<allNotif.size())
    {
      for (int i = allNotif.size()-1; i>allNotif.size()-limit; i--)
  {
    cout<< allNotif[i]<<endl;
  }
    }
    else{
  for (int i = allNotif.size()-1; i>= 0; i--)
  {
    cout<< allNotif[i]<<endl;
  }
}
}


