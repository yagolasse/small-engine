#include  "scene.h"

#include "input.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>

Scene::Scene()
{

}

Scene::~Scene()
{
}

void Scene::start()
{
	// Size | Position | Color
	player = { 8.0, -90.0, { 1.0f, 1.0f, 0.0f }, { 160, 100 } };


	map = { { 8, 8 }, {
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	}, 32.0 };
}

void Scene::update(const float delta)
{
	float degreeToRad = 0.0174532925;
	float playerSpeed = 50;

	if (Input::getKey(GLFW_KEY_W))
	{
		player.position += glm::vec2(cos(player.angle * degreeToRad), sin(player.angle * degreeToRad)) * playerSpeed * delta;
	}
	if (Input::getKey(GLFW_KEY_S))
	{
		player.position -= glm::vec2(cos(player.angle * degreeToRad), sin(player.angle * degreeToRad)) * playerSpeed * delta;
	}

	if (Input::getKey(GLFW_KEY_A))
	{
		player.angle -= 50 * delta;
	}

	if (Input::getKey(GLFW_KEY_D))
	{
		player.angle += 50 * delta;

	}

	glPointSize(map.cellSize);

	glBegin(GL_POINTS);

	int mapSize = map.size.x * map.size.y;

	for (int i = 0; i < mapSize; i++) // Iterating over the map
	{
		if (map.data[i]) {
			glColor3f(1.0, 1.0, 1.0);
		}
		else {
			glColor3f(0.0, 0.0, 0.0);
		}

		int x = (i % map.size.x * map.cellSize) + map.cellSize / 2;
		int y = (i / map.size.y * map.cellSize) + map.cellSize / 2;

		glVertex2i(x, y);
	}

	glEnd();

	glm::vec2 rayPosition = glm::vec2{ player.position };

	for (int a = 0; a < 1; a++)
	{
		glLineWidth(4);

		glBegin(GL_LINES);

		glColor3f(1.0, 0.0, 0.0);

		glVertex2f(player.position.x, player.position.y);

		glm::vec2 rayPosition = map.closestWallPositionFrom(player.position, player.angle * degreeToRad);

		glVertex2f(rayPosition.x, rayPosition.y);

		float distance = glm::length(player.position - rayPosition);

		// Half screen height
		// float wallHeight = floor(100 / distance);

		glEnd();
	}

	glPointSize(player.size);

	glBegin(GL_POINTS);

	glColor3f(player.color.r, player.color.g, player.color.b);

	glVertex2i(player.position.x, player.position.y);

	glEnd();
}
