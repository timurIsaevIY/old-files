#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <fstream>
#include<string>
#include"client.h"
#pragma once
#pragma warning(disable: 4996)


SOCKET Connection;

void ClientHandler() {
	char msg[256];
	while (true) {
		recv(Connection, msg, sizeof(msg), NULL);
		std::cout << msg << std::endl;
	}
}



int main() {
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "error 3" << std::endl;
	}
	else {
		std::cout << "Client connected" << std::endl;
	}
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);
	char got[256];
	while (true) {
		std::cin.getline(got, sizeof(got));
		send(Connection, got, sizeof(got), NULL);

	}
	
	std::cout << "1.�����" << std::endl << "2.������������������" << std::endl;
	int w;
	std::string username;
	std::cin >> w;
	std::ifstream fr("userlist.txt");
	std::string line;
	switch (w) {
	case 1:
		std::cout << "������� ���";
		std::cin >> username;
		while (getline(fr, line)) {
			if (line.substr(2, -1) == username) {
				std::cout << "���� ������� ��������" << std::endl;
				line = line[0];
				Client client = Client(std::stoi(line), username);
				break;
			}
			else
			{
				std::cout << "������� ������������ �� ����������";
				break;
			}
		}
		fr.close();
	case 2:
		std::cout << "���������� �����";
		std::cin >> username;
		Client client = Client(setClientId(), username);
	}
	


}