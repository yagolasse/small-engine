#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <vector>

struct Player
{
	float size;
	float angle;
	glm::vec3 color;
	glm::vec2 position;
};

struct Map
{
	glm::i16vec2 size;
	std::vector<int> data;
	float cellSize;

	glm::vec2 closestWallPositionFrom(glm::vec2 point, float angleRad) 
	{
		float mapSize = size.x * size.y;

		float rayCos = cos(angleRad) / cellSize;
		float raySin = sin(angleRad) / cellSize;

		glm::vec2 rayOffset = { rayCos, raySin };

		int wall = 0;

		while (wall == 0)
		{
			point += rayOffset;

			int index = size.x * floor(point.y / mapSize) + floor(point.x / mapSize);

			if (index >= mapSize)
			{
				break;
			}

			wall = data[index];
		}

		return point;
	}
};

class Scene
{
public: 
	Scene();
	~Scene();

	void start();
	void update(const float delta);
private:
	Map map;
	Player player;
};
