#include "network.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <queue>

// Default constructor
// pre: none
// post: creates a Network object with default values
Network::Network() {}

// Destructor
// pre: none
// post: destroys the Network
Network::~Network() {
    for (User* user : users_) {
        delete user;
    }
}

// pre: fname is a valid filename
// post: initializes the information from the file
int Network::readUsers(const char* fname) {
    std::ifstream myFile(fname);
    
    if (!myFile) {
        return -1;
    }
    std::string numUsersStr;

    if (!std::getline(myFile, numUsersStr)) {
        myFile.close();
        return -1;
    }

    std::stringstream ss(numUsersStr);
    std::size_t numUsers;
    ss >> numUsers;

    for (std::size_t i = 0; i < numUsers; i++) {
        std::string idStr, name_, yearStr, zipStr;

        if (!std::getline(myFile, idStr)) {
            myFile.close();
            return -1;
        }

        std::stringstream ss(idStr);
        std::size_t id_;
        ss >> id_;
        
        if (!std::getline(myFile, name_)) {
            myFile.close();
            return -1;
        }

        if (!std::getline(myFile, yearStr)) {
            myFile.close();
            return -1;
        }

        std::stringstream ds(yearStr);
        std::size_t year_;
        ds >> year_;

        if (!std::getline(myFile, zipStr)) {
            myFile.close();
            return -1;
        }

        std::stringstream xs(zipStr);
        std::size_t zip_;
        xs >> zip_;

        std::string friendsIdStr;

        if (!std::getline(myFile, friendsIdStr)) {
            myFile.close();
            return -1;
        }

        std::stringstream fs(friendsIdStr);
        std::vector<std::size_t> friends_;
        std::size_t friendId;

        while (fs >> friendId) {
            
            friends_.push_back(friendId);  
        }

        User* user = new User(id_, name_, year_, zip_, friends_); 
        addUser(user);
    }

    myFile.close();
    return 0;
}


// pre: fname is a valid filename
// post: writes the information into the file
int Network::writeUsers(const char* fname) {

    std::ofstream outFile(fname);
    if (!outFile) {
        return -1;
    }

    outFile << numUsers() << std::endl;

    for (User* user : users_) {

        outFile << user->getId() << ":" << std::endl;
        outFile << "\t" << user->getName() << std::endl;
        outFile << "\t" << user->getYear() << std::endl;
        outFile << "\t" << user->getZip() << std::endl;
        std::vector<std::size_t> friends = user->getFriends();
        outFile << "\t";

        for (std::size_t friendId : friends) {
            outFile << friendId << " ";
        }

        outFile << std::endl;
    }

    outFile.close();

    return 0;
}

// pre: User is a valid pointer to the User object
// post: adds the User to the network
void Network::addUser(User* user) {
    users_.push_back(user);
}

// pre: s1 and s2 are valid names
// post: creates a connection between the two Users
int Network::addConnection(std::string s1, std::string s2) {
    User* user1 = nullptr;
    User* user2 = nullptr;

    for (User* user : users_) {
        if (user->getName() == s1) {
            user1 = user;
        } 
        else if (user->getName() == s2) {
            user2 = user;
        }
    }

    if (user1 == nullptr || user2 == nullptr) {
        return -1; 
    }

    user1->addFriend(user2->getId());
    user2->addFriend(user1->getId());

    return 0;
}

// pre: s1 and s2 are valid names
// post: removes a connection between the two Users
int Network::removeConnection(std::string s1,std::string s2) {
    User* user1 = nullptr;
    User* user2 = nullptr;

    for (User* user : users_) {
        if (user->getName() == s1) {
            user1 = user;
        } 
        else if (user->getName() == s2) {
            user2 = user;
        }
    }

    if (user1 == nullptr || user2 == nullptr) {
        return -1;
    }

    user1->deleteFriend(user2->getId());
    user2->deleteFriend(user1->getId());

    return 0;
}

// pre: name is a valid name
// post: returns the corresponding ID for the User, or -1 if not found
std::size_t Network::getId(std::string name) {
    for (User* user : users_) {
        if (user->getName() == name) {
            return user->getId();
        }
    }
    return -1;
}

// pre: none
// post: returns the number of Users in the Network
std::size_t Network::numUsers() {
    return users_.size();
}

// pre: id is a valid ID
// post: returns a pointer to the corresponding User, or nullptr if not found
User* Network::getUser(std::size_t id) {
    for (User* user : users_) {
        if (user->getId() == id) {
            return user;
        }
    }

    return nullptr;
}

// pre: from and to are valid IDs
// post: returns a vector containing the shortest path of IDs
std::vector<std::size_t> Network::shortestPath(std::size_t from, std::size_t to) {
    std::vector<std::size_t> shortestpath;
    std::vector<std::size_t> prev(numUsers(), -1);
    std::queue<std::size_t> q;
    std::vector<bool> visited(numUsers(), 0);

    q.push(from);
    visited[from] = true;

    while (!q.empty()) {
        std::size_t currentId = q.front();
        q.pop();

        if (currentId == to) {
                
            while (currentId != from) {
                shortestpath.push_back(currentId);
                currentId = prev[currentId];
            }

            shortestpath.push_back(from);
            std::reverse(shortestpath.begin(), shortestpath.end());
            return shortestpath;
            
        }      
        for (std::size_t friendId : users_[currentId]->getFriends()) {
            
            if (!visited[friendId]) {
                
                visited[friendId] = true;
                prev[friendId] = currentId;
                q.push(friendId);
            
            }
        
        }
    }

    return shortestpath;
}

// pre: from and to are valid ids within the network
// pre: distance is a non-negative integer
// post: if a user is found at the distance, then to is set to the found id
// post: if no user is found at the distance, then to is set to -1
std::vector<std::size_t> Network::distanceUser(std::size_t from, std::size_t& to, std::size_t distance) {
    std::vector<std::size_t> finalpath;
    
    for (std::size_t id_ = 0; id_ < numUsers(); id_++) {
        if (id_ != from) {
            std::vector<std::size_t> shortestpath = shortestPath(from, id_);
            if (shortestpath.size() == distance + 1) {
                to = id_;
                finalpath = shortestpath;
                return finalpath;
            }
        }
    }

    to = -1;
    return finalpath;
}

// pre: who is a valid id
// post: returns a vector containing the ids of users who have the highest score and sets the score to the maximum score found
std::vector<std::size_t> Network::suggestFriends(std::size_t who, std::size_t& score) {
    std::vector<size_t> testdistance(numUsers(), 0);
    score = -1;
    for (std::size_t i = 0; i < numUsers(); i++) {
        
        if (i == who) {
            continue;
        }

        std::vector<std::size_t> currenttestpath = shortestPath(who, i);
        
        if (!currenttestpath.empty()) {
            testdistance[i] = currenttestpath.size() - 1;
        }
    }

    std::vector<size_t> suggestedFriends;
    size_t max = 0;
    for (std::size_t i = 0; i < testdistance.size(); i++) {
        
        if (testdistance[i] == 2) {
            std::vector<size_t> friends = getUser(i)->getFriends();
            size_t count = 0;
            
            for (std::size_t element : friends) {
                std::vector<size_t> friendsWithUser = getUser(element)->getFriends();
                
                for (std::size_t potentialFriend : friendsWithUser) {
                    
                    if (potentialFriend == who) {
                        count ++;
                    }
                }
            }
            
            if (count > max) {
                suggestedFriends.clear();
                suggestedFriends.push_back(i);
                max = count;
                
            } 

            else if (count == max) {
                suggestedFriends.push_back(i);
            }
        }
    }

    score = max;
    return suggestedFriends;
}

// pre: the network is initialized with users and friend connections
// post: returns a vector of vectors where each vector represents a disjoint set of users
std::vector<std::vector<std::size_t>> Network::groups() {
    std::vector<bool> visited(numUsers(), 0);
    std::vector<std::vector<std::size_t>> connectedComponents;

    for (std::size_t id_ = 0; id_ < numUsers(); id_++) {
        if (!visited[id_]) {
            std::vector<std::size_t> connectedComponent = dfs(id_, visited);
            connectedComponents.push_back(connectedComponent);
        }
    }

    return connectedComponents;
}

// pre: from and 'visited are valid vectors with sizes equal to the number of users in the network, id_ is a valid user ID within the network
// post: performs a depth-first search (DFS) starting from the user with ID currentId
std::vector<std::size_t> Network::dfs(std::size_t id_, std::vector<bool>& visited) {
    std::vector<std::size_t> connectedComponent;
    std::stack<std::size_t> stack;

    stack.push(id_);
    visited[id_] = true;

    while (!stack.empty()) {
        std::size_t currentId = stack.top();
        stack.pop();
        connectedComponent.push_back(currentId);

        User* currentUser = getUser(currentId);
        std::vector<std::size_t> friends = currentUser->getFriends();

        for (std::size_t friendId : friends) {
            if (!visited[friendId]) {
                stack.push(friendId);
                visited[friendId] = true;
            }
        }
    }

    return connectedComponent;
}

// pre: ownerId is a valid user ID, incoming is a boolean that specifies whether the post is incoming or not, author is a valid user ID, and isPublic is a boolean that specifies whether the post is public or not
// post: adds a new user post to the network with the provided parameters
void Network::addPost(std::size_t ownerId, std::string message, std::size_t likes, bool incoming, std::size_t author, bool isPublic) {
    User* user = getUser(ownerId);

    if (user != nullptr) {
        Post* newPost;

        if (incoming) {
            std::string authorName = getUser(author)->getName();
            newPost = new IncomingPost(user->getId(), message, likes, isPublic, authorName);
        } 

        else {
            newPost = new Post(user->getId(), message, likes);
        }

        user->addPost(newPost);
    }
}

// pre: name is a valid user name, howMany is a positive integer, showOnlyPublic is a boolean
// post: returns a string containing the most recent howMany posts for the user with the specified name
std::vector<Post*> Network::displayPosts(std::string name, std::size_t howMany, bool showOnlyPublic) {
    User* user = nullptr;
    for (User* curr : users_) {
        
        if (curr->getName() == name) {
            user = curr;
            break;
        }
    }

    if (user != nullptr) {
        return user->displayPosts(howMany, showOnlyPublic);
    } 
}

// Pre: fname is a valid filename
// Post: reads posts from the file and stores them
int Network::readPosts(const char* fname) {
    std::ifstream myFile(fname);
    
    if (!myFile) {
        return -1;
    }
    std::string numPostsStr;

    if (!std::getline(myFile, numPostsStr)) {
        myFile.close();
        return -1;
    }

    std::stringstream ss(numPostsStr);
    std::size_t numPosts;
    ss >> numPosts;

    for (std::size_t i = 0; i < numPosts; i++) {
        std::string messageidStr, message_, ownerIdStr, num_likesStr, accessType, authorName;
        bool isPublic=false;

        if (!std::getline(myFile, messageidStr)) {
            myFile.close();
            return -1;
        }

        std::stringstream ss(messageidStr);
        std::size_t messageid_;
        ss >> messageid_;
        
        if (!std::getline(myFile, message_)) {
            myFile.close();
            return -1;
        }

        if (!std::getline(myFile, ownerIdStr)) {
            myFile.close();
            return -1;
        }

        std::stringstream ds(ownerIdStr);
        std::size_t ownerId;
        ds >> ownerId;

        if (!std::getline(myFile, num_likesStr)) {
            myFile.close();
            return -1;
        }

        std::stringstream xs(num_likesStr);
        std::size_t num_likes;
        xs >> num_likes;

        char nextChar = myFile.peek();

        if (nextChar == 'p') {
            
            if (!std::getline(myFile, accessType)) {
                myFile.close();
                return -1;
            }

            if (!std::getline(myFile, authorName)) {
                myFile.close();
                return -1;
            }
        

            if (accessType == "public") {
                isPublic = true;
            } 

            else if (accessType == "private") {
                isPublic = false;
            } 

            else {
                std::cout<< "error" << std::endl;
            }

            User* user = getUser(ownerId);
            user->addPost(new IncomingPost(messageid_, message_, num_likes, isPublic, authorName));

            User* newUser = getUser(getId(authorName));
            newUser->addPost(new Post(messageid_, message_, num_likes));

        }
        else {
        User* user = getUser(ownerId);
        user->addPost(new Post(messageid_, message_, num_likes));
        }
    }
    return 0;
}




