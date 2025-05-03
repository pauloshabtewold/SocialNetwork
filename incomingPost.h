#ifndef INCOMINGPOST_H
#define INCOMINGPOST_H

#include "post.h"
#include <string>

class IncomingPost : public Post {
public:
    // pre: none
    // post: creates an IncomingPost object with the specified id, message, likes, isPublic, and authorName
    IncomingPost(std::size_t id, std::string message, std::size_t likes, bool isPublic, std::string authorName);

    // pre: none
    // post: creates an IncomingPost object with default values (id = 0, empty message, 0 likes, isPublic = false, empty authorName)
    IncomingPost();

    // pre: none
    // post: returns a string containing the post message, likes, post type ("Public" or "Private"), and author's name
    std::string displayPost() override;

    // pre: none
    // post: returns true if the post is public, false if it's private
    bool isPublic();

private:
    bool isPublic_;
};

#endif

