/**
 * @file Clock.h
 * @author Kellen Lear
 *
 * Clock Base Class
 */

#ifndef GAMELIB_GAME_GAMELIB_CLOCK_H
#define GAMELIB_GAME_GAMELIB_CLOCK_H
#include "Item.h"
#include "Program.h"

/** Clock Base Class */
class Clock : public Item
{
private:
	/// Current game
	Game* mGame;

	/// Speed that the clock moves
	double mSpeed = 75.0;

	/// Angle the clock is moving in radians
	double mDirection = 0.0;

	/// Elapsed time change variable for update animation
	double mTimeChange = 0.0;

	/// shared pointer mProgram
	std::shared_ptr<Program> mProgram;

public:
	/**
	 * Handle updates for set program
	 * @param program The time since the last update
	 */
	void SetProgram(std::shared_ptr<Program> program) { mProgram = program; }

	/// Default constructor (disabled)
	Clock() = delete;

	/// Copy constructor (disabled)
	Clock(const Clock &) = delete;

	/// Assignment operator
	void operator=(const Clock &) = delete;

	Clock(Game* game);

	virtual void Clicked() override;

	void Draw(std::shared_ptr<wxGraphicsContext> gc) override;

	virtual void Update(double elapsed) override;
	void XmlLoad(wxXmlNode *node);
};

#endif //GAMELIB_GAME_GAMELIB_CLOCK_H
