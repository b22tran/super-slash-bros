#pragma once
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "Character.hpp"
#include "CommandQueue.hpp"
#include "Command.hpp"
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <array>
#include <queue>

namespace sf{
	class RenderWindow;
}

class World : private sf::NonCopyable{
	public:
		explicit World(sf::RenderWindow& window);
		void update(sf::Time dt);
		void draw();
		float randNum(float min, float max);
		bool charDead() const;
		
		CommandQueue& getCommandQueue();


	private:
		void loadTextures();
		void buildScene();
		void adaptPlayerPosition();
		void adaptPlayerVelocity();
		void adaptEnemyPosition();
		void adaptEnemyVelocity();
	
		sf::FloatRect getViewBounds() const;
		void destroyEntitiesOutsideView();
		void handleCollisions();
		sf::FloatRect getBattlefieldBounds() const;
	
		enum Layer{
			Background,
			Air,
			LayerCount
		};

		struct SpawnPoint{
			SpawnPoint(Character::Type type, float x, float y)
				: type(type)
				, x(x)
				, y(y){
			}

			Character::Type type;
			float x;
			float y;
		};

		sf::RenderWindow& mWindow;
		sf::View mWorldView;
		TextureHolder mTextures;

		SceneNode mSceneGraph;
		std::array<SceneNode*, LayerCount>	mSceneLayers;
		CommandQueue mCommandQueue;

		sf::FloatRect mWorldBounds;
		sf::Vector2f mSpawnPosition;
		float mScrollSpeed;
		Character* mPlayerCharacter;
		Character* mEnemyCharacter;

};
