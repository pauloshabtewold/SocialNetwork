#ifndef POST_H
#define POST_H

#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
class User;


class Post {
public:
    // pre: none
    // post: creates a Post object with id = 0, an empty message, zero likes, zero laughs, zero loves, and zero hates
    Post();

    // pre: none
    // post: creates a Post object with the specified id, message, and likes, as well as a random number up to 20 of laughs, loves, and hates
    Post(std::size_t id, std::string message, std::size_t likes);

    // pre: none
    // post: returns a string containing the post message and the number of likes
    virtual std::string displayPost();

    // pre: none
    // post: returns the id of the post
    std::size_t getId();

    // pre: none
    // post: returns the message of the post
    std::string getMessage();

    // pre: none
    // post: returns the number of likes on the post
    std::size_t getLikes();

    //pre: valid user object exists and is called in
    //post: adds a Laugh and adds the user id of the user who laughed it
    void addLaugh(User* user);

    //pre: valid user object exists and is called in
    //post: adds a Love and adds the user id of the user who loved it
    void addLove(User* user);

    //pre: valid user object exists and is called in
    //post: adds a Hate and adds the user id of the user who hated it
    void addHate(User* user);

    //pre: none
    //post: returns the id of the user who laughed
    std::vector<std::size_t>& getUsersWhoLaughed();

    //pre: none
    //post: returns the id of the user who loved
    std::vector<std::size_t>& getUsersWhoLoved();

    //pre: none
    //post: returns the id of the user who hated
    std::vector<std::size_t>& getUsersWhoHated();

    //pre: none
    //post: returns amount of users who laughed
    std::size_t getLaughs();

    //pre: none
    //post: returns amount of users who loved
    std::size_t getLoves();

    //pre: none
    //post: returns amount of users who hated
    std::size_t getHates();

private:
    std::size_t id_;
    std::string message_;
    std::size_t likes_;
    std::size_t laughs_;
    std::size_t loves_;
    std::size_t hates_;
    std::vector<std::size_t> usersWhoLaughed_;
    std::vector<std::size_t> usersWhoLoved_;
    std::vector<std::size_t> usersWhoHated_;

    //pre: none
    //post: creates a random number up to 20
    std::size_t generateRandomNumberToTwenty();

    //pre:valid number count
    //post: creates a vector of random numbers that are not repeated up to count
    std::vector<std::size_t> generateRandomNumbers(std::size_t count);
};

#endif
