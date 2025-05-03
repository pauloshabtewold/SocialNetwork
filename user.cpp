//user.cpp
#include "user.h"
#include <vector>
#include <algorithm>
	//pre: none
	//post: creates user object with default values for id, name, birthyear, zipcode, and an empty friends vector
	User::User() : id_(0), name_(""), year_(0), zip_(0), friends_(0){}

	//pre: id is an actual ID
	//post: creates a user object with values for id, name, birthyear, zipcode, and friends
	User::User(std::size_t id_, std::string name_, std::size_t year_, std::size_t zip_, std::vector<std::size_t>& friends_) : id_(id_),name_(name_), year_(year_), zip_(zip_),friends_(friends_){}

	//pre: none
	//post: returns the ID of the User
	std::size_t User:: getId(){
		return id_;
	}

	//pre: none
	//post: returns the name of the User
    std::string User:: getName(){
    	return name_;
    }

    //pre: none
    //post: returns the birth year of the user
    std::size_t User:: getYear(){
    	return year_;
    }

    //pre: none
    //post returns the zipcode of the user
    std::size_t User:: getZip(){
    	return zip_;
    }

    //pre: none
    //post: returns a reference to the friends vector which has the user's friends
    std::vector<std::size_t> User:: getFriends(){
    	return friends_;
    }

	//pre: id is an actual ID
	//post: adds a friend with the id to the user's friends list
	void User:: addFriend(std::size_t id){
		if (std::find(friends_.begin(), friends_.end(),id)==friends_.end()){
			friends_.push_back(id);
		}
	}

	//pre: id is an actual ID
	//post deletes a friend with the given id, if they exist, from the user's friends list
	void User:: deleteFriend(std::size_t id){
		std::vector<std::size_t>::iterator it=std::find(friends_.begin(),friends_.end(), id);
		if (it!=friends_.end()||friends_.back()==id){
			friends_.erase(it);
		}
	}

	//pre: post is a valid pointer to a Post
	//post: Adds the post to messages vector
	void User::addPost(Post* post) {
    	messages_.push_back(post);
	}

	// pre: howMany is positive , showOnlyPublic is a boolean
    // post: returns a vector of the posts up to howMany
    std::vector<Post*> User::displayPosts(std::size_t howMany, bool showOnlyPublic) {
    std::vector<Post*> filteredMessages;

        std::size_t count = 0;

    for (auto post : messages_) {
            if (count < howMany) {
            filteredMessages.push_back(post);
            count++;
        }
    }

    return filteredMessages;
}

