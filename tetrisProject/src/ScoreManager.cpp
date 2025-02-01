#include "ScoreManager.hpp"
#include <iostream>

ScoreManager::ScoreManager()
	: totalLinesCleared(0), score(0), level(1), dropInterval(0.5f)
{}

int ScoreManager::getScore()
{
	return score;
}

int ScoreManager::getLevel()
{
	return level;
}

int ScoreManager::getTotalLinesCleared()
{
	return totalLinesCleared;
}

float ScoreManager::getDropInterval()
{
	return dropInterval;
}

void ScoreManager::updateScore(int linesCleared)
{
	totalLinesCleared += linesCleared;
	switch (linesCleared)
	{
	case 1:
		score += 40 * (level + 1);
		break;
	case 2:
		score += 100 * (level + 1);
		break;
	case 3:
		score += 300 * (level + 1);
		break;
	case 4:
		score += 1200 * (level + 1);
		break;
	}
	updateLevel();
}

void ScoreManager::updateLevel()
{
	int newLevel = totalLinesCleared / 10 + 1;
	if (newLevel > level)
	{
		level = newLevel;
		dropInterval += 0.2f;
	}
}

void ScoreManager::resetScore()
{
	score = 0;
}

void ScoreManager::resetLevel()
{
	level = 1;
}

void ScoreManager::resetLines()
{
	totalLinesCleared = 0;
}

void ScoreManager::reset()
{
	resetScore();
	resetLevel();
	resetLines();
}

