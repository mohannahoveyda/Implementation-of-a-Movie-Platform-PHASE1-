	#include "comment.h"
	#include "film.h"

	Comment::Comment(int _comment_id, string _content, Film* _f, User* _u){
		comment_id=_comment_id;
		content=_content;
		f=_f;
		u=_u;

	}
	void Comment :: print(){

       cout<<comment_id<<". "<<content<<endl;
       for (int i = 0; i < replies.size(); i++)
       {
       	cout<<comment_id<<"."<< i+1<<". ";
       	replies[i]->print();
       }
	}
	void Comment :: post_reply(string _content){
		replies.push_back(new Reply(_content));
		
	}
	bool Comment :: check_for_equal_commentID(int _comment_id){
   return _comment_id==comment_id;
  }
	void Comment :: notif_writer(string notif){
		u->add_notif(notif);
	}


