#pragma once
#include "Libraries.h"

class UserData {
	std::string username, time_text;
	int time;

public:
	UserData() : username(""), time_text(""), time(0) {}

	~UserData() {}

	void setData(std::string un, std::string tt, int t) {
		username = un;
		time_text = tt;
		time = t;
	}

	std::string getData() {
		std::string aux;
		MarshalString(time.ToString(), aux);
		return username + "," + time_text + "," + aux + ",";
	}

	std::string getDataString() {
		std::string s;
		s += username;
		if (s.size() < 19) {
			for (int i = (int)s.size(); i < 19; i++) {
				s += ".";
			}
		}
		s += time_text;
		return s;
	}

	std::string getUsername() {
		return username;
	}

	std::string getTimeText() {
		return time_text;
	}

	int getTime() {
		return time;
	}
};