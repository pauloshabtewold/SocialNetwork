#include <iostream>
#include "network.h"
#include "user.h"
#include "post.h"
#include "incomingPost.h"
using namespace std;

void printUsers(Network& network);
void printFriends(Network& network, string name);

int main() {
    Network network;   
    string userFile;
    cout << "enter the name of the input users file: ";
    cin >> userFile;
    int result = network.readUsers(userFile.c_str());
    
    if (result == 0) {
        cout << "data loaded from file." << endl;
    } 

    else {
        cout << "error reading user data from file." << endl;
    }

    string postsFile;
    cout << "enter the name of the input posts file: ";
    cin >> postsFile;
    int secondresult = network.readPosts(postsFile.c_str());
    
    if (secondresult == 0) {
        cout << "data loaded from file." << endl;
    } 

    else {
        cout << "error reading user data from file." << endl;
    }
    
    while (true) {
        cout << "menu options:" << endl;
        cout << "1. add a user" << endl;
        cout << "2. add friend connection" << endl;
        cout << "3. remove friend connection" << endl;
        cout << "4. print users" << endl;
        cout << "5. print friends" << endl;
        cout << "6. write to file" << endl;
        cout << "7. compute shortest path" << endl;
        cout << "8. find a friend with a certain distance" << endl;
        cout << "9. most suggested friend/s" << endl;
        cout << "10. disjoint sets of users" << endl;
        cout << "11. most recent posts" << endl;
        cout << "12. exit" << endl;
        cout << "select an option (1-12): ";
        
        size_t option;
        cin >> option;
        
        if (option == 1) {
            string firstName, lastName;
            size_t year_;
            size_t zip_;
            vector<size_t> emptyfriends;
            cin >> firstName >> lastName >> year_ >> zip_;
            User* newUser = new User(network.numUsers(), firstName + " " + lastName, year_, zip_, emptyfriends);
            network.addUser(newUser);
            cout << "user added." << endl;
        } 

        else if (option == 2) {

            string s1FirstName, s1LastName, s2FirstName, s2LastName, s2, s1;
            cin >> s1FirstName >> s1LastName >> s2FirstName >> s2LastName;

            s1 = s1FirstName + " " + s1LastName;
            s2 = s2FirstName + " " + s2LastName;

            if (network.addConnection(s1, s2) == 0) {
                cout << "friend connection added." << endl;
            } 

            else {
                cout << "user not found." << endl;
            }
        } 

        else if (option == 3) {
            
            string s1FirstName, s1LastName, s2FirstName, s2LastName, s2, s1;
            cin >> s1FirstName >> s1LastName >> s2FirstName >> s2LastName;

            s1 = s1FirstName + " " + s1LastName;
            s2 = s2FirstName + " " + s2LastName;
            
            if (network.removeConnection(s1, s2) == 0) {
                cout << "friend connection removed." << endl;
            } 

            else {
                cout << "user not found or not friends." << endl;
            }
        } 

        else if (option == 4) {
            printUsers(network);
        } 

        else if (option == 5) {
            
            string name_, first_name, last_name;
            cin >> first_name >> last_name;
            name_ = first_name + " " + last_name;
            printFriends(network, name_);

        } 

        else if (option == 6) {
            string fileName;
            cin >> fileName;
            
            if (network.writeUsers(fileName.c_str()) == 0) {
                cout << "data written to file." << endl;
            }

            else {
                cout << "error writing to file." << endl;
            }
        } 

        else if (option == 7) {

            string s1FirstName, s1LastName, s2FirstName, s2LastName, s2, s1;
            cin >> s1FirstName >> s1LastName >> s2FirstName >> s2LastName;

            s1 = s1FirstName + " " + s1LastName;
            s2 = s2FirstName + " " + s2LastName;

            size_t id1_ = network.getId(s1);
            size_t id2_ = network.getId(s2);

            vector<size_t> shortestPath = network.shortestPath(id1_, id2_);
            
            if (shortestPath.empty()) {
            
            cout << "None." << endl;

            }
            cout << "Distance: " << shortestPath.size()-1 << endl;

            for (size_t id_ : shortestPath) {

                User* user = network.getUser(id_);
                cout << user->getName();
        
                if (id_ != shortestPath.back()) {

                    cout << "  ->  ";
                }
            }
            cout << endl;
        }

        else if (option == 8) {
            string s1, s1FirstName, s1LastName;
            cin >> s1FirstName >> s1LastName;
            s1 = s1FirstName + " " + s1LastName;

            size_t id1_ = network.getId(s1);
    
            size_t distance;
            cin >> distance;

            size_t to;
            vector<size_t> distancePath = network.distanceUser(id1_, to, distance);

            if (to == -1) {
                cout << "no user found at distance " << endl;
            } 
            
            else {
                cout<<to<<endl;
                cout << network.getUser(to)->getName() << ": ";
                
                for (size_t id_ : distancePath) {
                    User* user = network.getUser(id_);
                    cout << user->getName();

                    if (id_ != distancePath.back()) {
                        cout << ", ";
                    }
                }
            
            cout << endl;
            }
        }

        else if (option == 9) {
        
        string s1, s1FirstName, s1LastName;
        cin >> s1FirstName >> s1LastName;
        s1 = s1FirstName + " " + s1LastName;

        size_t who = network.getId(s1);
        size_t score;
    
        vector<size_t> suggestedFriends = network.suggestFriends(who, score);

        cout << "The suggested friend(s) is/are:" << endl;
    
        if (score == -1) {
        cout << "None" << endl;
        }

        else if (option == 10) {
            vector<vector<size_t>> connectedComponents = network.groups();
    
            if (connectedComponents.empty()) {
                cout << "no connected components" << endl;
            } 
            else {
                
                for (size_t i = 0; i < connectedComponents.size(); i++) {
                    cout << "Set " << i + 1 << " => ";
                    
                    for (size_t j = 0; j < connectedComponents[i].size(); j++) {
                        size_t id_ = connectedComponents[i][j];
                        User* user = network.getUser(id_);
                        cout << user->getName();
                
                        if (j < connectedComponents[i].size() - 1) {
                            cout << ", ";
                        }
                    }
                    cout << endl;
                }
            }
        }


        else {
            for (size_t id_ : suggestedFriends) {
            User* user = network.getUser(id_);
            cout << user->getName() << " Score: " << score << endl;
            }
        }
    }
    else if (option == 11) {
        string s1, s1FirstName, s1LastName;
        cin >> s1FirstName >> s1LastName;
        s1 = s1FirstName + " " + s1LastName;
        size_t howMany;
        cin >> howMany;
        size_t id_ = network.getId(s1);
        User* user = network.getUser(id_);
        string posts = user->displayPosts(howMany, false);
        cout << "Most Recent Posts for " << user->getName() << ":" << endl;
        cout << posts << endl;
}

    else  {
        break;
        } 
    }
    return 0;
}

void printUsers(Network& network) {
    cout << "ID\tName\tBirth Year\tZip Code" << endl;
    size_t numUsers = network.numUsers();

    for (size_t i = 0; i < numUsers; i++) {
        User* user = network.getUser(i);

        if (user!=nullptr) {
            cout << user->getId() << "\t" << user->getName() << "\t" << user->getYear() << "\t" << user->getZip() << endl;
        } 

        else {
            cout << "invalid user at index " << i << endl;
        }
    }
}


void printFriends(Network& network, string name) {
    size_t userId = network.getId(name);
    
    if (userId != -1) {
        User* user = network.getUser(userId);
        vector<size_t> friends = user->getFriends();
        cout << "ID" << "\t" << "Name" << "\t" << "Birth Year"<< "\t" << "Zip Code" << endl;
        
        for (size_t friendId : friends) {
            User* friendUser = network.getUser(friendId);
            cout << friendUser->getId() << "\t" << friendUser->getName() << "\t" << friendUser->getYear() << "\t" << friendUser->getZip() << endl;
        } 
    }

    else {
        cout << "user not found." << endl;
    }
}


