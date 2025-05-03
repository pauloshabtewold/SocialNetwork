#include "incomingPost.h"

// Pre: none
// Post: creates an IncomingPost object with the specified id, message, likes, isPublic, and authorName
IncomingPost::IncomingPost(std::size_t id, std::string message, std::size_t likes, bool isPublic, std::string authorName)
    : Post(id, message + " From: " + authorName, likes), isPublic_(isPublic) {}


// Pre: none
// Post: creates an IncomingPost object with default values (id = 0, empty message, 0 likes, isPublic = false,)
IncomingPost::IncomingPost() : isPublic_(false){}

// pre: none
// post: returns a string containing the post message, likes, post type ("Public" or "Private"), and author's name
std::string IncomingPost::displayPost() {
    std::string postType;
    if (isPublic_) {
        postType = "Public: ";
    }

    else {
        postType = "Private: ";
    }

    return postType + Post::displayPost() + "\n";
}


// pre: none
// post: returns true if the post is public, false if it's private
bool IncomingPost::isPublic() {
    return isPublic_;
}
