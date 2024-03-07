#pragma once
#include <string>
class Client {
	std::string username;
	int id;
public:
	void setUsername(std::string);
	std::string getUsername();
	void setId(int id);
	int getID();
	bool addUser();
	void getFriends();
	void addFriend(std:: string);
	void writeMessage(std::string, std::string);
	//void sendMessage(Client,std::string);
	//void removeFriend(Client);
	Client(int,std::string);
	
};
