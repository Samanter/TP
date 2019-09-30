#pragma once
#include "Base.h"
#include "Pila.h"
#include "Cola.h"
#include "List.h"
#include "_Screen.h"
#include "UserData.h"
#include "Libraries.h"

template <typename T>
class Game {
private:
	Base *player, *platform, *laser;
	UserData *player_info;
	_Screen *menu, *gameover, *game, *highscores, *lastplays, *pause, *controls;

	List<Base*>* lasers;
	List<UserData*>* scores;
	Pila<_Screen*>* current_screen;
	Cola<UserData*>* history;

	System::Drawing::Rectangle game_area;

	int timer, death_time, time_counter, screen_h_border, screen_v_border;
	float grav, jump_spd, walk_spd;
	float laser_spd, laser_width, laser_height, laser_spawn_spd;
	std::string username;
	std::string death_time_text;

public:
	Game() : player(new Base()), platform(new Base()), laser(new Base()), lasers(new List<Base*>()), timer(0), time_counter(0), 
		     screen_h_border(0), screen_v_border(0), current_screen(new Pila<_Screen*>(3)), player_info(new UserData()), 
			 scores(new List<UserData*>()), history(new Cola<UserData*>(10)){}

	~Game() {
	}

	void MarshalString(System::String^ s, std::string& outputstring) {
		const char* kPtoC = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		outputstring = kPtoC;
		Marshal::FreeHGlobal(IntPtr((void*)kPtoC));
	}
	
	/*sobre el juego*/
	void Load() {
		LoadScreenType();
		LoadScreen(menu);
		LoadGame();
	}

	void LoadScreenType() {
		menu = new _Screen(0);
		game = new _Screen(1);
		highscores = new _Screen(2);
		lastplays = new _Screen(3);
		pause = new _Screen(4);
		gameover = new _Screen(5);
		controls = new _Screen(6);
	}

	void LoadGame() {
		player = new Base();
		player->setHeight(10);
		player->setWidth(10);
		player->setHPos((float)(screen_h_border) / 2 - player->getWidth() / 2);
		player->setVPos((float)((float)(screen_v_border) / 2 - 20));

		lasers = new List<Base*>();
		laser_spd = (float)5;
		laser_width = (float)70;
		laser_height = (float)3;
		laser_spawn_spd = (float)40;

		platform = new Base();
		platform->setHeight(5);
		platform->setWidth(300);
		platform->setHPos((float)((float)(screen_h_border) / 2 - platform->getWidth() / 2));
		platform->setVPos((float)((float)(screen_v_border) / 2 + platform->getHeight() / 2));

		game_area = System::Drawing::Rectangle(0, 0, screen_h_border, screen_v_border);
		grav = (float)0.06;
		jump_spd = (float)-2.7;
		walk_spd = (float)2;
		time_counter = 0;
		timer = 0;
	}

	void Run(System::Drawing::Graphics^ g, System::Drawing::Image^ img_player, System::Drawing::Image^ img_platform, System::Drawing::Image^ img_laser) {
		g->Clear(System::Drawing::SystemColors::Window);

		if (current_screen->top() != nullptr && current_screen->top()->getScreenType() == 1) {
			GameRunning(g, img_player, img_platform, img_laser);
		}
	}

	void GameRunning(System::Drawing::Graphics^ g, System::Drawing::Image^ img_player, System::Drawing::Image^ img_platform, System::Drawing::Image^ img_laser) {
		Gravity(grav);
		Boundaries();

		player->Move();

		if (!lasers->isEmpty()) {
			int i = 0;
			for (typename List<Base*>::Iterator it = lasers->begin(); it != lasers->end(); ++it) {
				(*it)->Move();
				if (laserCollision(*it)) {
					death_time = timer;
					LoadScreen(gameover);
					setDeathTimeText(death_time);
					player_info->setData(username, death_time_text, death_time);
					saveData();
					break;
				}
				if (!isInGameArea(*it)) {
					it.operator--();
					lasers->deletePos(i);
					i--;
				}

				i++;
			}
		}

		if (time_counter % (int)laser_spawn_spd == 0) {
			createLaser();

			if (laser_spawn_spd > 10) {
				laser_spawn_spd -= (float)0.5;
			}
			if (laser_spd < 10) {
				laser_spd += (float)0.1;
			}
		}

		platform->Print(g, img_platform);
		player->Print(g, img_player);
		for (typename List<Base*>::Iterator it = lasers->begin(); it != lasers->end() && !lasers->isEmpty(); ++it) {
			(*it)->Print(g, img_laser);
		}

		time_counter++;
		timer++;
	}

	/*pantallas*/
	void LoadScreen(_Screen* sc) {
		current_screen->push(sc);
	}

	void stopScreen() {
		current_screen->pop();
	}

	/*sobre el jugador*/
	void ResetPlayerPosition() {
		player->setHPos((float)(screen_h_border) / 2 - player->getWidth() / 2);
		player->setVPos((float)(screen_v_border) / 2 - 20);
	}

	void Boundaries() {
		if (!isInGameArea(player)) {
			ResetPlayerPosition();
			player->setHSpd(0);
			player->setVSpd(0);
		}
	}

	/*física*/
	void Gravity(float grav, std::function<int(T, T)> compare = [](T a, T b) { return a - b; }) {
		player->setVSpd(player->getVSpd() + grav);

		if (isPlayerOnPlatform() && compare(player->getVPos() + player->getHeight() + player->getVSpd(), platform->getVPos()) > 0 && compare(player->getVPos() + player->getHeight(), platform->getVPos()) <= 0) {
			player->setVSpd(0);
			LimitCollision(player->getVPos() + player->getHeight(), platform->getVPos());
		}
	}

	void LimitCollision(float a, float b) {
		if (a < b) {
			a += (float)0.01;
			LimitCollision(a, b); //recursividad
		}
	}

	bool isPlatformBelow(std::function<int(T, T)> compare = [](T a, T b) { return a - b; }) {
		return (isPlayerOnPlatform() && compare(platform->getVPos(), player->getVPos() + player->getHeight() + 1) == -1);
	}

	bool isPlayerOnPlatform(std::function<int(T, T)> compare = [](T a, T b) { return a - b; }) {
		return compare(player->getHPos() + player->getWidth(), platform->getHPos()) > 0 && compare(player->getHPos(), platform->getHPos() + platform->getWidth()) < 0;
	}

	/*sobre los laser*/
	void createLaser() {
		laser = new Base();
		int v_o_h = rand() % 2;

		if (v_o_h == 0) {
			laser->setWidth(laser_width);
			laser->setHeight(laser_height);

			v_o_h = rand() % 2;

			if (v_o_h == 0) {
				laser->setHPos(-1*(laser->getWidth()));
				laser->setVPos((float)((int)(rand() * (player->getHPos()) + player->getVPos()) % screen_v_border));
				laser->setHSpd(laser_spd);
				laser->setVSpd(0);
			}
			else {
				laser->setHPos((float)screen_h_border);
				laser->setVPos((float)((int)(rand() * (player->getHPos()) + player->getVPos()) % screen_v_border));
				laser->setHSpd(-1*(laser_spd));
				laser->setVSpd(0);
			}
		}
		else {
			laser->setWidth(laser_height);
			laser->setHeight(laser_width);

			v_o_h = rand() % 2;

			if (v_o_h == 0) {
				laser->setHPos((float)((int)(rand() * (player->getHPos()) + player->getVPos()) % screen_h_border));
				laser->setVPos(-1*(laser->getHeight()));
				laser->setVSpd(laser_spd);
				laser->setHSpd(0);
			}
			else {
				laser->setHPos((float)((int)(rand() * (player->getHPos()) + player->getVPos()) % screen_h_border));
				laser->setVPos((float)screen_v_border);
				laser->setVSpd(-1*(laser_spd));
				laser->setHSpd(0);
			}
		}

		lasers->addFirst(laser);
	}
	
	/*otros*/
	bool laserCollision(Base* laser) {
		System::Drawing::Rectangle player_hb = System::Drawing::Rectangle((int)player->getHPos(), (int)player->getVPos(), (int)player->getWidth(), (int)player->getHeight());
		System::Drawing::Rectangle laser_hb = System::Drawing::Rectangle((int)laser->getHPos(), (int)laser->getVPos(), (int)laser->getWidth(), (int)laser->getHeight());

		return player_hb.IntersectsWith(laser_hb);
	}

	bool isInGameArea(Base* base) {
		System::Drawing::Rectangle base_hb = System::Drawing::Rectangle((int)base->getHPos(), (int)base->getVPos(), (int)base->getWidth(), (int)base->getHeight());
		return base_hb.IntersectsWith(game_area);
	}

	/*guardar y cargar partida*/
	void saveData() {
		std::ofstream file("datos.txt", std::ios::app);
		if (file.is_open()) {
			file << player_info->getData() << std::endl;
			file.close();
		}
	}

	void loadData() {
		scores = new List<UserData*>();
		std::ifstream file("datos.txt");
		if (file.is_open()) {
			std::string username;
			std::string time_text;
			int time;

			std::string line;
			while (std::getline(file, line)) {
				std::istringstream iss(line);
				std::getline(iss, username, ',');
				std::getline(iss, time_text, ',');
				iss >> time;
				
				UserData* aux = new UserData();
				aux->setData(username, time_text, time);
				scores->addLast(aux);
			}
		}
	}

	void organizeData() {
		scores->Organize([](UserData* a, UserData* b) { return b->getTime() - a->getTime(); });
	}

	void organizeData2() {
		Pila<UserData*>* aux = new Pila<UserData*>(scores->size());
		for (int i = 0; i < scores->size(); i++) {
			aux->push(scores->getPos(i));
		}
		while (!aux->isEmpty()) {
			history->push(aux->top());
			aux->pop();
		}
	}

	/*getters y setters*/
	//getters
	int getTimer() {
		return timer;
	}

	Base* getPlayer() {
		return player;
	}

	Base* getPlatform() {
		return platform;
	}

	float getJumpSpd() {
		return jump_spd;
	}

	float getWalkSpd() {
		return walk_spd;
	}

	float getGravity() {
		return grav;
	}

	std::string getUsername() {
		return username;
	}

	_Screen* getCurrentScreen() {
		return current_screen->top();
	}

	_Screen* getScreen(int screen) {
		switch (screen) {
		case 1:
			return game;
		case 2:
			return highscores;
		case 3:
			return lastplays;
		case 4:
			return pause;
		case 5:
			return gameover;
		case 6:
			return controls;
		default:
			return menu;
		}
	}

	int getDeathTime() {
		return death_time;
	}

	List<UserData*>* getScores() {
		return scores;
	}

	Cola<UserData*>* getHistory() {
		return history;
	}

	//setters
	void setScreenSize(int a, int b) {
		screen_h_border = a;
		screen_v_border = b;
	}

	void setTimer(int a) {
		timer = a;
	}

	void setGravity(float a) {
		grav = a;
	}

	void setUsername(std::string a) {
		username = a;
	}

	void setDeathTimeText(int a) {
		System::String^ death_time_text2 = "";
		int mins = getDeathTime() / 3900;
		int secs = getDeathTime() / 65;
		int m_secs = (getDeathTime() % 65) * (1000 / 65);
		std::string aux;

		if (mins < 10) {
			death_time_text2 += "0";
		}
		death_time_text2 += mins.ToString() + ":";
		if (secs < 10) {
			death_time_text2 += "0";
		}
		death_time_text2 += secs.ToString() + ":";
		if (m_secs < 100) {
			death_time_text2 += "0";
			if (m_secs < 10) {
				death_time_text2 += "0";

			}
		}
		death_time_text2 += m_secs.ToString();
		MarshalString(death_time_text2, aux);
		death_time_text = aux;
	}
};

