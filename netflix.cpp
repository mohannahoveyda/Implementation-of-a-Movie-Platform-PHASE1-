#include "netflix.h"
   User* Netflix :: get_currentUserPtr(){ return currentUserPtr;}
    void Netflix :: signup(string _email, string _username, string _password, int _age, bool _is_publisher){
     if(_is_publisher){
      users.push_back(new Publisher(_email,_username,RSHash(_password),_age,_is_publisher));
     }
     else{
      users.push_back(new User(_email,_username,RSHash(_password),_age,_is_publisher));
     }
      int t=users.size()-1;
      currentUserPtr=users[t];
      users[t]->set_user_id(t+1);
    }
    void Netflix :: login(string _username, string _password){
      bool flag=false;

      for (int i = 0; i < users.size(); i++) {
       if (users[i]->login(_username, RSHash(_password)) ) {
         cout<< "ok\n";
         currentUserPtr=users[i];
         flag=true;
       }
     }
     if (!flag) {
       cout<<"NOT FOUND!\n";
     }
    }

    void Netflix :: follow(int user_id){
     // if (!users[user_id-1]->IsPublisher())
     // {
     //  cout<< "permission denied";
     // }
     //cout<<currentUserPtr->get_username()<<"wanted to follow "<< users[user_id-1]->get_username()<<"\n";
      currentUserPtr->add_following(users[user_id-1]);
      users[user_id-1]->add_follower(currentUserPtr);
      users[user_id-1]->add_notif("User "+ users[user_id-1]->get_username() + " with id " + to_string(users[user_id-1]->get_user_id())+ " follow you");


    }
    void Netflix :: print_users(){
      for (int i = 0; i < users.size(); i++) {
       users[i]->print();
      }
    }
    void Netflix :: post_film(string film_name, int year, int length, int price, string summary, string director){
     Publisher* currentPublisherPtr= (Publisher*) currentUserPtr;
     currentPublisherPtr->post_film( film_name, year, length, price, summary, director, films, lastFilmID);
       lastFilmID++;
     }
     void Netflix :: edit_film(int film_id, string film_name, int year, int length, string summary, string director){
     Publisher* currentPublisherPtr= (Publisher*) currentUserPtr;
     currentPublisherPtr->edit_film_info( film_id,film_name, year, length, summary, director);
     }
    void Netflix :: delete_film(int film_id){
     Publisher* currentPublisherPtr= (Publisher*) currentUserPtr;
     currentPublisherPtr->delete_film(film_id,films);
    }
    void Netflix :: print_films(){
     cout<<"#. Film Id | Film Name | Film Length | Film Price | Rate | Production Year | Film Director"<<endl;
     cout<<"all films are:"<<"\n";

     for (int i = 0; i < films.size(); i++)
     {
       films[i]->print();
     }
    }
    void Netflix :: show_followers(int user_id){
     users[user_id-1]->show_followers();
    }

    void Netflix :: print_currentUserFilms(){
     Publisher* currentPublisherPtr= (Publisher*) currentUserPtr;
     cout<<"Publisher's films are:"<<"\n";
     currentPublisherPtr->print_myUploadedFilms();
    }
    void Netflix :: buy_film(int film_id){
      currentUserPtr->buy_film(film_id,films);
    }
    
    void Netflix :: show_film_list(string film_name, int min_rate, int min_year, int price, int max_year, string director){
     Publisher* currentPublisherPtr= (Publisher*) currentUserPtr;
      currentPublisherPtr->show_film_list(film_name,min_rate, min_year, price, max_year, director);      
    }
    void Netflix :: rate_film(int film_id, float score){
      currentUserPtr->rate_film(film_id,score);
    }
    void Netflix :: show_purchased_films(string name, int _price, int min_year,int max_year, string director){
      currentUserPtr->show_purchased_films(name, _price, min_year , max_year, director);
    }
  
    void Netflix :: print_film_detail(int film_id){
      for (int i = 0; i <films.size() ; i++)
      {
        if(films[i]->check_for_equal_filmID(film_id)){
          films[i]->print_film_detail();
        }
      }
      cout<< "Recommendation Film"<< endl;
      cout<< "#. Film Id | Film Name | Film Length | Film Director"<<endl;
      recommend_film(film_id);
    }
    //void Netflix :: recommend_film(){}
    void Netflix :: post_comment(int film_id, string _content){
     currentUserPtr->post_comment( film_id, lastCommentID, _content);
       lastCommentID++;
    }
    void Netflix ::post_reply(int _film_id, int comment_id, string _content){
      Publisher* currentPublisherPtr= (Publisher*) currentUserPtr;
      currentPublisherPtr->post_reply(_film_id, comment_id , _content);    
    }
    void Netflix :: delete_comment(int film_id, int comment_id){
      Publisher* currentPublisherPtr= (Publisher*) currentUserPtr;
     currentPublisherPtr->delete_comment( film_id, comment_id);

    }
    void Netflix :: recommend_film(int film_id){
      int f;
      vector <Film*> unwatched_films;
      for (int i = 0; i < films.size(); i++)
      {
        f=films[i]->get_film_id();
        if (!currentUserPtr->check_if_film_exists_in_purchased_films(f) && f!=film_id)
        {
          unwatched_films.push_back(films[i]);
        }
      }
      Film* best;
      int bestnumber;
      for (int k = 0; k < 4; k++)
      {
        bestnumber=0;
        if(unwatched_films.size()>0){
          best=unwatched_films[0];
          for(int j=1;j<unwatched_films.size();j++){
            if(unwatched_films[j]->is_greater(best)){
             best=unwatched_films[j];
             bestnumber=j;
            }
          }
          unwatched_films.erase(unwatched_films.begin()+bestnumber);
          best->print();
        }
      }
    }
    void Netflix :: show_unread_notifications(){
      currentUserPtr->show_unread_notifications();

    }
    void Netflix :: show_all_notifications(int limit){
      currentUserPtr->show_all_notifications(limit+1);
    }
    void Netflix :: showFollowers(){
      currentUserPtr->show_followers();
    }

    void Netflix :: addCash(int amount){
      currentUserPtr->add_cash(amount);
    }
  
   

   void Netflix :: process(string newline){

    vector<string> parameters;
  vector<string> values;
  int i=newline.find(" ");
  int j=newline.find("?");
  string command=newline.substr(0,i);
  string type=newline.substr(i+1,j-i-1);
  if(type.find("notifications read")==string::npos){type=nospace(type);}else{ type ="notifications read";}
  string rest;
  if(newline.find("?")!=string::npos ){
    rest=newline.substr(j+1) ;
  }else{
    rest="";
  }
  bool flag=true;
  string temp;
  bool shouldbeparameter=true;
  while(flag){
    if(rest.find(" ")==string::npos ){ 
      flag=false;
    }
    i=rest.find(" ");
    temp= rest.substr(0,i);
    if(temp!=" " && temp!=""){
      if(shouldbeparameter){
        parameters.push_back(temp);
      }else{
        values.push_back(temp);
      }
      shouldbeparameter=!shouldbeparameter;
    }
    rest=rest.substr(i+1);
  }
    
    if(command=="POST"){
      if(type=="signup"){
        dastoor order;
        if( parameters.size()==5 && parameters[4]=="publisher" && values[4]=="true"){
          order.set_is_publisher();
        }
        if( parameters.size()==5 && parameters[4]!="publisher" ){
          cout<<"Error"<<endl;
        } else if( (parameters.size()==4 || parameters.size()==5)  && parameters[0]=="email" && parameters[1]=="username" && parameters[2]=="password" && parameters[3]=="age" ){
          signup( values[0],  values[1], values[2], stooi(values[3]), order.get_is_publisher()); 
        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="login"){    
        if(parameters.size()==2 && parameters[0]=="username" && parameters[1]=="password" ){
          login(values[0], values[1]);
        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="films"){
        if(parameters.size()==6 && parameters[0]=="name" && parameters[1]=="year" && parameters[2]=="length" && parameters[3]=="price" && parameters[4]=="summary" && parameters[5]=="director"){
          post_film(values[0], stooi(values[1]),stooi(values[2]), stooi(values[3]), values[4], values[5]);
        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="money"){
        if(parameters.size()==0  ){
          //cout<<"post_money()"<<endl;
        }
      }
      if(type=="replies"){
        if(parameters.size()==3 && parameters[0]=="film_id" && parameters[1]=="comment_id" && parameters[2]=="content"  ){
          post_reply(stooi(values[0]), stooi(values[1]), values[2]);

        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="followers"){
        if(parameters.size()==1 && parameters[0]=="user_id"  ){
          follow(stooi(values[0]));
        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="money"){
        if(parameters.size()==1 && parameters[0]=="amount"  ){
          addCash(stooi(values[0]));
        }else if(parameters.size()!=0){
          cout<<"Error"<<endl;
        }
      }
      if(type=="buy"){
        if(parameters.size()==1 && parameters[0]=="film_id"  ){
           buy_film(stooi(values[0]));

        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="rate"){
        if(parameters.size()==2 && parameters[0]=="film_id" && parameters[1]=="score" ){
         rate_film(stooi(values[0]), stoof(values[0]));

        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="comments"){
        if(parameters.size()==2 && parameters[0]=="film_id" && parameters[1]=="content" ){
            post_comment(stooi(values[0]), values[1]);

        }else{
          cout<<"Error"<<endl;
        }
      }
    }
    if(command=="PUT"){
      if(type=="films"){
        dastoor order;
        for(int k=1;k<parameters.size();k++){
          if(parameters[k]=="name"){ order.set_name(values[k]); }
          if(parameters[k]=="year"){ order.set_min_year(stooi(values[k])); }
          if(parameters[k]=="length"){ order.set_length(stooi(values[k])); }
          if(parameters[k]=="summary"){ order.set_summary(values[k]); }
          if(parameters[k]=="director"){ order.set_director(values[k]); }
        }
        if(parameters[0]=="film_id" ){
          edit_film(stooi(values[0]), order.get_name(), order.get_min_year(), order.get_length() , order.get_summary(), order.get_director());


        }else{
          cout<<"Error"<<endl;
        }
      }
      
      
    }
    if(command=="DELETE"){
      if(type=="films"){
        if(parameters.size()==1 && parameters[0]=="film_id"  ){
          delete_film(stooi(values[0]));
        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="comments"){
        if( parameters.size()==2 && parameters[0]=="film_id" && parameters[1]=="comment_id" ){
          delete_comment(stooi(values[0]),stooi(values[1]));
        }else{
          cout<<"Error"<<endl;
        }
      }
      
    }
    if(command=="GET"){
      if(type=="followers"){
        if(parameters.size()==0 ){
         showFollowers();

        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="published"){
        dastoor order;
        for(int k=0;k<parameters.size();k++){
          if(parameters[k]=="name"){ order.set_name(values[k]); }
          if(parameters[k]=="min_rate"){ order.set_min_rate(stoof(values[k])); }
          if(parameters[k]=="min_year"){ order.set_min_year(stooi(values[k])); }
          if(parameters[k]=="price"){ order.set_price(stoi(values[k])); }
          if(parameters[k]=="max_year"){ order.set_max_year(stooi(values[k])); }
          if(parameters[k]=="director"){ order.set_director(values[k]); }
        }
        if(parameters.size()<7 ){
          show_film_list(order.get_name(), order.get_min_rate(), order.get_min_year(),order.get_price() , order.get_max_year(), order.get_director());

        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="films"){
        dastoor order;
        for(int k=0;k<parameters.size();k++){
          if(parameters[k]=="name"){ order.set_name(values[k]); }
          if(parameters[k]=="min_rate"){ order.set_min_rate(stoof(values[k])); }
          if(parameters[k]=="min_year"){ order.set_min_year(stooi(values[k])); }
          if(parameters[k]=="price"){ order.set_price(stooi(values[k])); }
          if(parameters[k]=="max_year"){ order.set_max_year(stooi(values[k])); }
          if(parameters[k]=="director"){ order.set_director(values[k]); }
        }
        if(parameters.size()==1 && parameters[0]=="film_id" ){
            print_film_detail(stooi(values[0]));

        }else if(parameters.size()<7 ){

          //cout<<"search films("<<order.get_name()<<","<<order.get_min_rate()<<","<<order.get_min_year()<<","<<order.get_price()<<","<<order.get_max_year()<<","<<order.get_director()<<")"<<endl;
        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="purchased"){
        dastoor order;
        for(int k=0;k<parameters.size();k++){
          if(parameters[k]=="name"){ order.set_name(values[k]); }
          if(parameters[k]=="price"){ order.set_price(stooi(values[k])); }
          if(parameters[k]=="min_year"){ order.set_min_year(stooi(values[k])); }
          if(parameters[k]=="max_year"){ order.set_max_year(stooi(values[k])); }
          if(parameters[k]=="director"){ order.set_director(values[k]); }
        }
        if(parameters.size()<6 ){
            show_purchased_films(order.get_name(), order.get_price(), order.get_min_year(), order.get_max_year(), order.get_director());

        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="notifications"){
        if(parameters.size()==0 ){
          show_unread_notifications();
        }else{
          cout<<"Error"<<endl;
        }
      }
      if(type=="notifications read"){
        
         if(parameters.size()==1 && parameters[0]=="limit" ){
          show_all_notifications(stooi(values[0]));

        }else{
          cout<<"Error"<<endl;
        }
      }
    }
  }