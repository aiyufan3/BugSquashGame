/**
 * @file Score.h
 * @author QZH
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_SCORE_H
#define GAME_GAME_GAMELIB_SCORE_H

#include "Item.h"
#include "OopsScoreVisitor.h"

/** Score Base Class */

class Score: public Item
{
private:

	int mFixed = 0;

	int mMissed = 0;

	int mOops = 0;

	Game *mGame;
public:
	/// Default constructor (disabled)
	Score() = delete;

	/// Copy constructor (disabled)
	Score(const Score &) = delete;

	/// Assignment operator
	void operator=(const Score &) = delete;

	Score(Game* game);

	void SetScore(int score);

	void Draw(std::shared_ptr<wxGraphicsContext> gc) override;

	virtual void Accept(FixedScoreVisitor* visitor) override;

	virtual void Accept(OopsScoreVisitor* visitor) override;

	virtual void Accept(MissedScoreVisitor* visitor) override;
};

#endif //GAME_GAME_GAMELIB_SCORE_H
