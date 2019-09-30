#pragma once

class _Screen {
private:
	int screen_type;
	bool selected;
	
public:
	_Screen(int screen_type) : screen_type(screen_type), selected(true) {}

	~_Screen() {
	}

	void deselect() {
		selected = false;
	}

	int getScreenType() {
		return screen_type;
	}

	bool getSelected() {
		return selected;
	}
};