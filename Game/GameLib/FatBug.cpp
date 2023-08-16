/**
 * @file FatBug.cpp
 * @author QZH
 */
#include "pch.h"
#include "FatBug.h"
#include "CodeDlg.h"
#include <wx/regex.h>


/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"garbagebug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"garbagebugsplat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;

/// Image filenames
const std::wstring NullBugImageName = L"scarlet-gray-bug.png";

/// Null bug image splat name
const std::wstring NullBugSplatImageName = L"scarlet-gray-splat.png";

/// Number of sprites
const int NullBugNumSpriteImages = 6;

void FatBug::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	if(mBugBitmaps[0].IsNull())
	{
		std::wstring fileName = mGame->GetImagesDirectory() + L"/" + mFatBugImageName;
		std::wstring splatFileName = mGame->GetImagesDirectory() + L"/" + mFatBugSplatImageName;
		mBugImage = std::make_unique<wxImage>(fileName, wxBITMAP_TYPE_ANY);
		mBugSplatImage = std::make_unique<wxImage>(splatFileName, wxBITMAP_TYPE_ANY);
		mBugBitmaps.clear();
		for(int i = 0; i < mFatBugNumSpriteImages - 1; i++)
			mBugBitmaps.push_back(wxGraphicsBitmap());

		wxGraphicsBitmap BugBitmap = gc->CreateBitmapFromImage(*mBugImage);
		for(int i = 0; i <= mBugBitmaps.size(); i++)
		{
			if(i == mBugBitmaps.size())
				mBugBitmapStationary = gc->CreateSubBitmap(BugBitmap, 0, 100*(i+1), 100, 100);
			else
				mBugBitmaps[i] = gc->CreateSubBitmap(BugBitmap, 0, 100*i, 100, 100);
		}
		mBugBitmapSplat = gc->CreateBitmapFromImage(*mBugSplatImage);
	}
	double wid = 0.0;
	double hit = 0.0;

	if(GetSplat())
	{
		wid = mBugBitmapSplat.ConvertToImage().GetWidth() * 1.25;
		hit = mBugBitmapSplat.ConvertToImage().GetHeight() * 1.25;
		gc->PushState();
		gc->Translate(GetX(), GetY());
		gc->Rotate(-mFacingAngle);
		gc->DrawBitmap(mBugBitmapSplat, -wid/2, -hit/2, wid, hit);
		gc->PopState();
		return;
	}

	wid = mBugBitmaps[mSpriteIndex].ConvertToImage().GetWidth() * 1.25;
	hit = mBugBitmaps[mSpriteIndex].ConvertToImage().GetHeight() * 1.25;
	gc->PushState();
	gc->Translate(GetX(), GetY());
	gc->Rotate(-mFacingAngle);
	gc->DrawBitmap(mBugBitmaps[mSpriteIndex], -wid/2, -hit/2, wid, hit);
	gc->PopState();
}

bool FatBug::DoubleHitTest(double x, double y)
{
	if(Bug::HitTest(x, y) && !GetSplat())
	{
		CodeDlg dlg(mGame->GetWindow(), mCode);
		dlg.ShowModal();
		wxString code = dlg.GetText();
		wxRegEx regex(mPass);
		dlg.Destroy();
		if(regex.Matches(code))
			return true;
	}
	return false;
}

FatBug::FatBug(Game* game) : Bug(game, GarbageBugSpriteImageName, GarbageBugSplatImageName, GarbageBugNumSpriteImages)
{
	mGame = game;
}

void FatBug::SetType(std::string type)
{
	if(type == "garbage")
	{
		mFatBugImageName = GarbageBugSpriteImageName;
		mFatBugSplatImageName = GarbageBugSplatImageName;
		mFatBugNumSpriteImages = GarbageBugNumSpriteImages;
	}
	else
	{
		mFatBugImageName = NullBugImageName;
		mFatBugSplatImageName = NullBugSplatImageName;
		mFatBugNumSpriteImages = NullBugNumSpriteImages;
	}
}