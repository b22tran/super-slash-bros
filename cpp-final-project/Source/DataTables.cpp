#include "DataTables.h"
#include "Character.hpp"
#include "Weapon.h"

// For std::bind() placeholders
using namespace std::placeholders;

float randNum(float min, float max) {
	float r = (float)rand() / (float)RAND_MAX;
	return min + r * (max - min);
}
std::vector<CharacterData> initializeCharacterData(){
	//typecount is is the last in the enum..
	std::vector<CharacterData> data(Character::TypeCount);

	data[Character::Player].hp = 200;
	data[Character::Player].speed = 400.f;
	data[Character::Player].fireInterval = sf::seconds(1);
	data[Character::Player].texture = Textures::Player;

	data[Character::Enemy].hp = 200;
	data[Character::Enemy].speed = 400.f;
	data[Character::Enemy].fireInterval = sf::seconds(1);
	data[Character::Enemy].texture = Textures::Player;

	return data;
}


std::vector<WeaponData> initializeWeaponData()
{
	std::vector<WeaponData> data(Weapon::TypeCount);

	data[Weapon::PlayerBullet].dmg = 10;
	data[Weapon::PlayerBullet].speed = 350.f;
	data[Weapon::PlayerBullet].texture = Textures::Ball;

	return data;
}

