#ifndef COMMENT_H
#define COMMENT_H
//#include "film.h"
#include "user.h"
#include "reply.h"

#include <iostream>
using namespace std;
class Film;
class Comment{
private:
	int comment_id;
	string content;
	Film* f;
	User* u;
	vector<Reply*> replies;
public:
	Comment(int _comment_id, string _content,Film* _f, User* _u);
	void print();
	void post_reply(string _content);
	bool check_for_equal_commentID(int _comment_id);
	void notif_writer(string notif);

};
#endif