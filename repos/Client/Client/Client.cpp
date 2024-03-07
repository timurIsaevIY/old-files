#include <fstream>
#include "client.h"
#include <iostream>
#include <string>
#include <vector>
#pragma once

void Client::writeMessage(std::string username, std::string message)
{
	std::string path = getUsername() + username + ".txt";
	std::ofstream fr(path,std::ios::app);
	fr << message;
	fr.close();

	path = username + getUsername() + ".txt";
	std::ofstream br(path, std::ios::app);
	br << message;
	br.close();

}

Client::Client(int id, std::string username)
{
	Client::username = username;
	Client::id = id;
}

void Client::setUsername(std::string username)
{
	Client::username = username;
}

std::string Client::getUsername()
{
	return Client::username;
}

void Client::setId(int id)
{
	Client::id = 0;
}

int Client::getID()
{
	return Client::id;
}

bool Client::addUser()
{
	std::ofstream f("userlist.txt",std:: ios::app);
	if (f.is_open()) {
		f << Client::getID() << " " << Client::getUsername() << std::endl;
		std::cout << "Успешно" << std::endl;
		return 1;
	}
	else {
		std::cout << "Не удалось добавить пользователя" << std::endl;
		return 0;
	}

}

void Client::getFriends()
{
	std::string path = username + "friends.txt";
	std::ifstream fr(path);
	std::string name;
	std::vector<std::string> vec;
	while (getline(fr, name)) vec.push_back(name);
	if (vec.empty()) std::cout << "You haven't got friends";
	else {
		for (std::string nam : vec) {
			std::cout << nam << std::endl;
		}
	}
	fr.close();

}

void Client::addFriend(std::string username)
{
	std::string path = Client::username + "_friends.txt";
	std::ofstream fr(path, std::ios::app);
	fr << username;
	fr.close();

	path = username + "_friends.txt";
	std::ofstream br(path, std::ios::app);
	br << Client::username;
	br.close();

}
