
class ScoreManager {
public:
	ScoreManager();
	~ScoreManager() = default;
	void addScore(int score);
	int getScore() const;
	void resetScore();
	void addLines(int lines);
	int getLines() const;
	void resetLines();
	void addLevel();
	int getLevel() const;
	void resetLevel();
	void updateScore(int linesCleared);
	void drawScore(sf::RenderWindow* window);
	void drawLevel(sf::RenderWindow* window);
	void drawLines(sf::RenderWindow* window);
	void drawGameOver(sf::RenderWindow* window);
	void drawPause(sf::RenderWindow* window);
	void drawControls(sf::RenderWindow* window);
	void drawTitle(sf::RenderWindow* window);
	void drawScoreBoard(sf::RenderWindow* window);
	void drawHighScore(sf::RenderWindow* window);
	void drawHighScoreBoard(sf::RenderWindow* window);
	void drawScoreBoardTitle(sf::RenderWindow* window);
	void drawHighScoreBoardTitle(sf::RenderWindow* window);
	void drawScoreBoardControls(sf::RenderWindow* window);
	void drawHighScoreBoardControls(sf::RenderWindow* window);
	void drawScoreBoardBack(sf::RenderWindow* window);
	void drawHighScoreBoardBack(sf::RenderWindow* window);
	void drawScoreBoardReset(sf::RenderWindow* window);
	void drawHighScoreBoardReset(sf::RenderWindow* window);
	void drawScoreBoardSave(sf::RenderWindow* window);
	void drawHighScoreBoardSave(sf::RenderWindow* window);
	void drawScoreBoardLoad(sf::RenderWindow* window);
	void drawHighScoreBoardLoad(sf::RenderWindow* window);
	void drawScoreBoardSaveSuccess(sf::RenderWindow* window);
	void drawHighScoreBoardSaveSuccess(sf::RenderWindow* window);
	void drawScoreBoardSaveFailure(sf::RenderWindow* window);
	void drawHighScoreBoardSaveFailure(sf::RenderWindow* window);
	void drawScoreBoardLoadSuccess(sf::RenderWindow* window);
	void drawHighScoreBoardLoadSuccess(sf::RenderWindow* window);
	void drawScoreBoardLoadFailure(sf::RenderWindow* window);
	void drawHighScoreBoardLoadFailure(sf::RenderWindow* window);
	void drawScoreBoardResetSuccess(sf::RenderWindow* window);
	void drawHighScoreBoardResetSuccess(sf::RenderWindow* window);
	void drawScoreBoardResetFailure(sf::RenderWindow* window);
	void drawHighScoreBoardResetFailure(sf::RenderWindow* window);
	void drawScoreBoardBackSuccess(sf::RenderWindow* window);
	void drawHighScoreBoardBackSuccess(sf::RenderWindow* window);
	void drawScoreBoardBackFailure(sf::RenderWindow* window);
	void drawHighScoreBoardBackFailure(sf::RenderWindow* window);
	void drawScoreBoardControlsSuccess(sf::RenderWindow* window);
	void drawHighScoreBoardControlsSuccess(sf::RenderWindow* window);
	void drawScoreBoardControlsFailure(sf::RenderWindow* window);
	void drawHighScoreBoardControlsFailure(sf::RenderWindow* window);
	void drawScoreBoardTitleSuccess(sf::RenderWindow* window);
	void drawHighScoreBoardTitleSuccess(sf::RenderWindow* window);



private:
};