#include "Player.h"
#include <iostream>
void Player::InitVariables(){
	this->player_sheet_.loadFromFile("Textures/hero.png");
	this->player_sprite_.setTexture(player_sheet_);
	this->player_sprite_.setPosition(0, 0);
	this->player_sprite_.setTextureRect(IntRect(0, 192, 96, 96));
	this->move_speed_ = 0.5;
}
void Player::InitShape(){
	this->shape_.setFillColor(Color(220, 200, 200));
	this->shape_.setSize(Vector2f(100.f, 100.f));
	this->shape_.setPosition(0, 0);
}
Player::Player(float x, float y){
	this->shape_.setPosition(x, y);

	this->InitVariables();
	this->InitShape();
}
void Player::UpdateInput(float time){
	if (Keyboard::isKeyPressed(Keyboard::A)){
		this->direction_.x = -1.f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)){
		this->direction_.x = 1.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::W)){
		this->direction_.y = -1.f;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)){
		this->direction_.y = 1.f;
	}
	if (abs(this->direction_.x) > 0 || abs(this->direction_.y) > 0){
		if (abs(this->direction_.x) > 0 && abs(this->direction_.y) > 0){
			this->direction_.x = 0.707 * this->direction_.x;
			this->direction_.y = 0.707 * this->direction_.y;
		}
		this->anim_frame_ += (this->move_speed_ * 0.02 * time);
		if (this->anim_frame_ > this->anim_lenght_){
			this->anim_frame_ -= this->anim_lenght_;
		}
		this->shape_.move(this->direction_.x * this->move_speed_ * time, this->direction_.y * this->move_speed_ * time);
		this->player_sprite_.move(this->direction_.x * this->move_speed_ * time, this->direction_.y * this->move_speed_ * time);

		if (abs(this->direction_.y) > abs(this->direction_.x)){
			if (this->direction_.y <= 0){
				this->anim_sheet_row_ = 3;
			}
			else{
				this->anim_sheet_row_ = 0;
			}
		}
		else{
			if (this->direction_.x >= 0){
				this->anim_sheet_row_ = 2;
			}
			else
			{
				this->anim_sheet_row_ = 1;
			}
		}
		this->player_sprite_.setTextureRect(IntRect(96 * int(anim_frame_), 96 *anim_sheet_row_, 96, 96));
		std::cout << this->direction_.x << " " << this->direction_.y << std::endl;
		this->anim_sheet_row_ = 0;
		this->direction_.x = 0;
		this->direction_.y = 0;
	}
}
void Player::Update(float time){
	this->UpdateInput(time);
}

void Player::Render(RenderTarget* target){
	target->draw(this->shape_);
	target->draw(this->player_sprite_);
}
