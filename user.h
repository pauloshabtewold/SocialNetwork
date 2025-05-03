#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "post.h"
#include "incomingPost.h"

class User {
public:
	//CONSTRUCTOR

	//Default constructor
	//pre: none
	//post: creates user object with default values for id, name, birthyear, zipcode, and an empty friends vector
	User();
	
	//Parameterized Constructor
	//pre: id is an actual ID
	//post: creates a user object with values for id, name, birthyear, zipcode, and friends
	User(std::size_t id_, std::string name_, std::size_t year_, std::size_t zip_, std::vector<std::size_t>& friends_);
	
	//CONSTANT MEMBERS

	//pre: none
	//post: returns the ID of the User
	std::size_t getId();

	//pre: none
	//post: returns the name of the User
    std::string getName();

    //pre: none
    //post: returns the birth year of the user
    std::size_t getYear();

    //pre: none
    //post returns the zipcode of the user
    std::size_t getZip();

    //pre: none
    //post: returns a reference to the friends vector which has the user's friends
    std::vector<std::size_t> getFriends();

    //MUTATING MEMBERS

	//pre: id is an actual ID
	//post: adds a friend with the id to the user's friends list
	void addFriend(std::size_t id);

	//pre: id is an actual ID
	//post deletes a friend with the given id, if they exist, from the user's friends list
	void deleteFriend(std::size_t id);

	// pre: post is a valid pointer to a Post
    // post: Adds the post to the user's messages vector
    void addPost(Post* post);

	// pre: howMany is a positive integer, showOnlyPublic is a boolean
    // post: returns a vector of the posts up to howMany
    std::vector<Post*> displayPosts(std::size_t howMany, bool showOnlyPublic);

private:
	std::size_t id_;
    std::string name_;
    std::size_t year_;
    std::size_t zip_;
    std::vector<std::size_t> friends_;
    std::vector<Post*> messages_;
};

#endif // USER_H
