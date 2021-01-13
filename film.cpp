
#include "film.h"
#include "publisher.h"
#include "user.h"
#include "comment.h"

  int Film :: get_film_id(){ return film_id;}
  float Film :: get_rate(){
    if(num_of_rates==0){
      return 0;
    }else{return sum_of_rates/num_of_rates;}
  }
  bool Film :: is_greater(Film* f){
    if( f->get_rate()< get_rate()  ){ return true; }
    if(f->get_rate()== get_rate() && f->get_film_id()> film_id){ return true;}
    return false;
  }
  
  void Film :: transfer_cash(){
   if(get_rate()<5){
   owner->add_cash(0.8*price);
   }
   if(get_rate()>=5 && get_rate()<8){
   owner->add_cash(0.9*price);
   }
   else{
   owner->add_cash(0.95*price);
   }
  }
  void Film :: print(){
  
   cout<<film_id<<"|"<< name<<"|"<<length<<"|"<<price<<"|"<<get_rate()<<"|"<<year<<"|"<<director<<endl;

    }

  bool Film :: check_for_equal_filmID(int _film_id){
   return _film_id==film_id;
  }
  int Film :: get_price(){ return price;}
  Film :: Film(){};
  Film :: Film(string _name, int _year, int _length, int _price, string _summary, string _director,int _film_id ,Publisher* _owner): name(_name), year(_year), length(_length), price(_price), summary(_summary),director(_director), film_id(_film_id), owner(_owner){}
  void Film :: editFilm(string film_name, double _year, double _length, string _summary, string _director){
   if(film_name!=""){
    name=film_name;
   }
   if(_year>0){
    year=_year;
   }
   if(_length>0){
    length=_length;
   }
   if (_summary!="")
   {
    summary!=_summary;
   }
   if(_director!=""){
    director=_director;
   }
  }
  bool Film :: search(string film_name, int min_rate, int min_year, int _price, int max_year, string _director){
   bool flag=true;
   if(film_name!="" && film_name!=name){
    flag=false;
   }
   if(_director!="" && _director!=director){
    flag=false;
   }
   if(get_rate()<min_rate){
    flag=false;
   }
   if (year< min_year || year>max_year)
   {
     flag=false;
   }
   if(price>_price){
    flag=false;
   }
   return flag;
  }
void Film :: print_film_detail(){
    cout<<"Details of Film "<<name<<endl;
    cout<<"Id = "<< film_id<<endl;
    cout<<"Director = "<<director<<endl;
    cout<<"length = "<<length<<endl;
    cout<<"Year = "<<year<<endl;
    cout<<"summary = "<<summary<<endl;
    cout<<"Rate = "<<get_rate();
    cout<<"Price = "<<price<<endl;
     cout << "Comments"<< endl;
    for(int j=0; j< comments.size(); j++){
       comments[j]->print();
    }
  }
  void  Film :: post_comment(int film_id,int _comment_id ,string _content, User* writer){
    Comment* c=new Comment(_comment_id,_content,this,writer);
    comments.push_back(c);
    owner->add_notif("User "+ writer->get_username() +" with id "+ to_string(writer->get_user_id()) +" comment on your film "+ name+ " with id "+ to_string(film_id)+".");

  }
  void  Film :: add_rate(float _rate){
    sum_of_rates+=_rate;
    num_of_rates++;
  }
  
  void Film::post_reply(int _comment_id, string _content){
    for (int i = 0; i < comments.size(); i++)
    {
      if (comments[i]->check_for_equal_commentID(_comment_id))
      {

        comments[i]->post_reply(_content);
        comments[i]->notif_writer("Publisher "+ owner->get_username()+" with id " + to_string(owner->get_user_id()) +" reply to your comment.");
      }
    }
  }

 void Film :: send_notif(string notif){
   owner->add_notif(notif + name + " with id "+ to_string(film_id)+".");
 }

  void Film :: delete_comment(int comment_id){
   for (int i = 0; i < comments.size(); i++)
    {
     if(comments[i]->check_for_equal_commentID(comment_id)){
      comments.erase(comments.begin()+i);
     }
    }
  }
  

