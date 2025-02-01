
class ScoreManager {
public:
	ScoreManager();
	~ScoreManager() = default;

	int getScore();
	int getLevel();
	int getTotalLinesCleared();
	float getDropInterval();

	void updateScore(int linesCleared);
	void updateLevel();

	void resetScore();
	void resetLevel();
	void resetLines();

	void reset();

private:
	int totalLinesCleared;
	int score;
	int level;
	float dropInterval;
};