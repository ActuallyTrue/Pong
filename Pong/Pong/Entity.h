#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite { //sf::Sprite is public so that all of its methods are publicly accessible.
public:
	Entity() {
		this->texture = new sf::Texture();
	}

	void Load(std::string filename) {
		this->texture->loadFromFile("Graphics/Sprites/" + filename);
		this->setTexture(*this->texture);
	}

	virtual void Update() {
		this->move(this->velocity);
	}

	bool CheckCollision(Entity* entity) {
		return this->getGlobalBounds().intersects(entity->getGlobalBounds());
	}

	~Entity() {
		delete this->texture;
	}
private:
	sf::Texture* texture;
protected:
	sf::Vector2f velocity;

};