/**
 * @file BugRedundancy.h
 * @author Stavro
 *
 */

#ifndef CSE335PROJECT1HORNET_GAMELIB_BUGREDUNDANCY_H
#define CSE335PROJECT1HORNET_GAMELIB_BUGREDUNDANCY_H

#include "Bug.h"

/** BugRedundancy Base Class */
class BugRedundancy : public Bug
{
private:
	Game* mGame;

	double mWingAngle = 0.0;

	bool mIsCopy = false;
public:
	virtual void Draw(std::shared_ptr<wxGraphicsContext> gc) override;

	BugRedundancy(Game *Game);

	/**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
	virtual void Update(double elapsed) override;

	virtual void Clicked() override;

	void SetCopy() { mIsCopy = true; }
};

#endif //CSE335PROJECT1HORNET_GAMELIB_BUGREDUNDANCY_H
