#pragma once

class Base {
private:
	float h_pos, v_pos, h_spd, v_spd;
	float height, width;

public:
	Base() : h_pos(0), v_pos(0), h_spd(0), v_spd(0), width(0), height(0) {}

	~Base() {
	}

	void setHPos(float h_pos) {
		this->h_pos = h_pos;
	}

	void setVPos(float v_pos) {
		this->v_pos = v_pos;
	}

	void setHSpd(float h_spd) {
		this->h_spd = h_spd;
	}

	void setVSpd(float v_spd) {
		this->v_spd = v_spd;
	}

	void setHeight(float height) {
		this->height = height;
	}

	void setWidth(float width) {
		this->width = width;
	}

	float getHPos() {
		return h_pos;
	}

	float getVPos() {
		return v_pos;
	}

	float getHSpd() {
		return h_spd;
	}

	float getVSpd() {
		return v_spd;
	}

	float getHeight() {
		return height;
	}

	float getWidth() {
		return width;
	}

	void Move() {
		h_pos += h_spd;
		v_pos += v_spd;
	}

	void Print(System::Drawing::Graphics^ g, System::Drawing::Image^ img) {
		g->DrawImage(img, h_pos, v_pos, width, height);
	}
};