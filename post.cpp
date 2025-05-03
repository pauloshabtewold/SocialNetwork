#include "post.h"
#include "user.h"

// pre: none
// post: creates a Post object with id = 0, an empty message, zero likes, zero laughs, zero loves, and zero hates
Post::Post() : id_(0), message_(""), likes_(0), laughs_(0), loves_(0), hates_(0) {}

// pre: none
// post: creates a Post object with the specified id, message, and likes, as well as a random number up to 20 of laughs, loves, and hates
Post::Post(std::size_t id, std::string message, std::size_t likes) : id_(id), message_(message), likes_(likes) {
    std::srand(static_cast<unsigned>(std::time(0)));
    laughs_ = generateRandomNumberToTwenty();
    loves_ = generateRandomNumberToTwenty();
    hates_ = generateRandomNumberToTwenty();
    usersWhoLaughed_ = generateRandomNumbers(laughs_);
    usersWhoLoved_ = generateRandomNumbers(loves_);
    usersWhoHated_ = generateRandomNumbers(hates_);
}

// pre: none
// post: returns a string containing the post message and the number of likes
std::string Post::displayPost() {
    return message_ + "\nLiked by " + std::to_string(likes_);
}

// pre: none
// post: returns the id of the post
std::size_t Post::getId() {
    return id_;
}

// pre: none
// post: returns the message of the post
std::string Post::getMessage() {
    return message_;
}

// pre: none
// post: returns the number of likes on the post
std::size_t Post::getLikes() {
    return likes_;
}

//pre: none
//post: creates a random number up to 20
std::size_t Post::generateRandomNumberToTwenty() {
    return std::rand() % 20 + 1;
}

//pre: valid user object exists and is called in
//post: adds a Laugh and adds the user id of the user who laughed it
void Post::addLaugh(User* user) {
    laughs_++;
    usersWhoLaughed_.push_back(user->getId());
}

//pre: valid user object exists and is called in
//post: adds a Love and adds the user id of the user who loved it
void Post::addLove(User* user) {
    loves_++;
    usersWhoLoved_.push_back(user->getId());
}

//pre: valid user object exists and is called in
//post: adds a Hate and adds the user id of the user who hated it
void Post::addHate(User* user) {
    hates_++;
    usersWhoHated_.push_back(user->getId());
}

//pre: none
//post: returns the id of the user who laughed
std::vector<std::size_t>& Post::getUsersWhoLaughed(){
    return usersWhoLaughed_;
}

//pre: none
//post: returns the id of the user who loved
std::vector<std::size_t>& Post::getUsersWhoLoved() {
    return usersWhoLoved_;
}

//pre: none
//post: returns the id of the user who hated
std::vector<std::size_t>& Post::getUsersWhoHated(){
    return usersWhoHated_;
}

//pre:valid number count
//post: creates a vector of random numbers that are not repeated up to count
std::vector<std::size_t> Post::generateRandomNumbers(std::size_t count){
    std::vector<std::size_t> randomNumbers;

    while (randomNumbers.size() <= count) {
        std::size_t randomNumber = std::rand() % 148 + 1;
        if (std::find(randomNumbers.begin(), randomNumbers.end(), randomNumber) == randomNumbers.end()) {
            randomNumbers.push_back(randomNumber);
        }
    }

    return randomNumbers;
}

//pre: none
//post: returns amount of users who laughed
std::size_t Post::getLaughs(){
    return laughs_;
}

//pre: none
//post: returns amount of users who loved
std::size_t Post::getLoves(){
    return loves_;
}

//pre: none
//post: returns amount of users who hated
std::size_t Post::getHates(){
    return hates_;
}
