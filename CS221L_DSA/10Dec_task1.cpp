#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct user {
    int ID;
    vector<user*> friends;

    user(int ID) : ID(ID), friends() {}
};

class network {
private:
    vector<user*> users;

public:
    network() : users() {}

    void insert(int id) {
        users.push_back(new user(id));
    }

    user* find(int ID) {
        for (user* User : users) {
            if (User->ID == ID) {
                return User;
            }
        }

        return nullptr;
    }

    void findAllFriends(int startID) {
        user* startUser = find(startID);
        if (!startUser) {
            cout << "User not found." << endl;
            return;
        }

        queue<user*> q;
        int maxUserID = 0; // Assuming user IDs start from 1
        for (user* u : users) {
            maxUserID = max(maxUserID, u->ID);
        }
        vector<bool> visited(maxUserID + 1, false);

        q.push(startUser);
        visited[startUser->ID] = true;

        int level = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            cout << "Level " << level << ":" << endl;

            for (int i = 0; i < levelSize; ++i) {
                user* current = q.front();
                q.pop();

                if (level == 0) {
                    cout << "  - Friend: " << current->ID << endl;
                } else {
                    cout << "  - Friend of a friend: " << current->ID << endl;
                }

                for (user* friendUser : current->friends) {
                    if (!visited[friendUser->ID]) {
                        q.push(friendUser);
                        visited[friendUser->ID] = true;
                    }
                }
            }
            level++;
        }
    }
};

int main() {
    // Example usage
    network net;
    net.insert(1);
    net.insert(2);
    net.insert(3);
    net.insert(4);
    net.insert(5);

    // Add friendships (adjust as needed)
    net.find(1)->friends.push_back(net.find(2));
    net.find(1)->friends.push_back(net.find(3));
    net.find(2)->friends.push_back(net.find(4));
    net.find(3)->friends.push_back(net.find(5));

    net.findAllFriends(1); // Find friends and friends-of-friends of user 1

    return 0;
}