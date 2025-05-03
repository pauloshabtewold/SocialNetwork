#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "user.h"
#include <queue>
#include "post.h"
#include "incomingPost.h"

class Network {
public:
    // Default constructor
    // pre: none
    // post: creates a Network object with default values
    Network();

    // Destructor
    // pre: none
    // post: destroys the Network
    ~Network();

    // pre: fname is a valid filename
    // post: initializes the information from the file
    int readUsers(const char* fname);

    // pre: fname is a valid filename
    // post: writes the information into the file
    int writeUsers(const char* fname);

    // pre: User is a valid pointer to the User object
    // post: adds the User to the network
    void addUser(User*);

    // pre: s1 and s2 are valid names
    // post: creates a connection between the two Users
    int addConnection(std::string s1, std::string s2);

    // pre: s1 and s2 are valid names
    // post: removes a connection between the two Users
    int removeConnection(std::string s1, std::string s2);

    // pre: name is a valid name
    // post: returns the corresponding ID for the User, or -1 if not found
    std::size_t getId(std::string name);

    // pre: none
    // post: returns the number of Users in the Network
    std::size_t numUsers();

    // pre: id is a valid ID
    // post: returns a pointer to the corresponding User, or nullptr if not found
    User* getUser(std::size_t id);
    
    // pre: from and to are valid IDs
    // post: returns a vector containing the shortest path of IDs
    std::vector<std::size_t> shortestPath(std::size_t from, std::size_t to);

    // pre: from and to are valid ids within the network
    // pre: distance is a non-negative integer
    // post: if a user is found at the distance, then to is set to the found id
    // post: if no user is found at the distance, then to is set to -1
    std::vector<std::size_t> distanceUser(std::size_t from, std::size_t& to, std::size_t distance);

    // pre: who is a valid id
    // post: returns a vector containing the ids of users who have the highest score and sets the score to the maximum score found
    std::vector<std::size_t> suggestFriends(std::size_t who, std::size_t& score);

    // pre: the network is initialized with users and friend connections
    // post: returns a vector of vectors where each vector represents a disjoint set of users
    std::vector<std::vector<std::size_t>> groups();

    // pre: fname is a valid filename
    // post: reads posts from the file and stores them
    int readPosts(const char* fname);

    // pre: ownerId is a valid ID, incoming is a boolean that specifies whether the post is incoming or not, author is a valid ID, and isPublic is a boolean that specifies whether the post is public or not
    // post: adds a new user post to the network with the provided parameters
    void addPost(std::size_t ownerId, std::string message, std::size_t likes, bool incoming, std::size_t author, bool isPublic);

    // pre: name is a valid name, howMany is a positive integer, showOnlyPublic is a boolean
    // post: returns a string containing the most recent howMany posts for the user with the specified name
    std::vector<Post*> displayPosts(std::string name, std::size_t howMany, bool showOnlyPublic);

private:
    std::vector<User*> users_;

    // pre: from and 'visited are valid vectors with sizes equal to the number of users in the network, id_ is a valid user ID within the network
    // post: performs a depth-first search (DFS) starting from the user with ID currentId
    std::vector<std::size_t> dfs(std::size_t userId, std::vector<bool>& visited);
};

#endif // NETWORK_H
