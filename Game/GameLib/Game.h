/**
 * @file Game.h
 *
 * @author Spencer Russell
 */

#ifndef GAME_GAME_GAMELIB_GAME_H
#define GAME_GAME_GAMELIB_GAME_H

#include <memory>
#include <random>
#include "Item.h"
#include "Bug.h"
#include "Program.h"
#include "ClockVisitor.h"


class GameView;

/** Game Base Class */

class Game
{
private:



	GameView* mWindow = nullptr;

	/// All of the bugs to populate the game
	std::vector<std::shared_ptr<Item>> mItems;

	/// Represents whether the window should be shrunk
	bool mShrinked = true;

	double mXOffset = 0.0;

	double mYOffset = 0.0;

	double mScale = 1.0;

	int mNumOfBugs = 0;

	int mNumOfPrograms = 0;

	int mNumOfClocks = 0;

	int mCurrentlevel = 0;
	/// Directory containing the system images
	std::wstring mImagesDirectory;

	/// Directory containing the system images
	std::wstring mLevelsDirectory;

	/// Random number generator
	std::mt19937 mRandom;

	void RemoveItem();

	std::vector<Item*> mItemsToRemove;
public:
	/// Game area width in virtual pixels
	const static int Width = 1250;

	/// Game area height in virtual pixels
	const static int Height = 1000;

	Game();

	void SetWindow(GameView* window) { mWindow = window; }

	GameView* GetWindow() { return mWindow; }

	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

	void Add(std::shared_ptr<Item> item);

	void SetImagesDirectory(const std::wstring &dir);

	void SetLevelsDirectory(const std::wstring &dir);

	int GetNumOfBugs() { return mNumOfBugs; }

	int GetNumOfPrograms() { return mNumOfPrograms; }

	/**
     * Get the directory the images are stored in
     * @return Images directory path
     */
	const std::wstring &GetImagesDirectory() const { return mImagesDirectory; }

	/**
     * Get the directory the images are stored in
     * @return Images directory path
     */
	const std::wstring &GetLevelsDirectory() const { return mLevelsDirectory; }

	/**
 	* Get the random number generator
 	* @return Pointer to the random number generator
 	*/
	std::mt19937 &GetRandom() {return mRandom;}

	std::shared_ptr<Item> HitTest(double x, double y);

	void SetToTop(std::shared_ptr<Bug> item);

	std::shared_ptr<Item> DoubleHitTest(double x, double y);

	void OnLeftDown(int x, int y);

	void OnLeftDoubleClick(int x, int y);

	void Update(double elapsed);

	void Shrink() { mShrinked = !mShrinked; }

	void Clear();

	void XmlItem(wxXmlNode *node, std::shared_ptr<Program> program, std::vector<std::shared_ptr<Item>> &bugsList);

	void XmlLoad(const wxString &filename);

	void Accept(ClockVisitor* visitor);

	void Accept(FixedScoreVisitor* visitor);

	void Accept(OopsScoreVisitor* visitor);

	void Accept(MissedScoreVisitor* visitor);

	void Remove(Item* item);

	void Nextlevel();



};

#endif //GAME_GAME_GAMELIB_GAME_H
