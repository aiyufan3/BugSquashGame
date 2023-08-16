/**
 * @file CodeDlg.h
 *
 * @author Spencer Russell
 */

#ifndef GAME_GAME_GAMELIB_CODEDLG_H
#define GAME_GAME_GAMELIB_CODEDLG_H

#include <wx/dialog.h>
#include "GameView.h"

/** CodeDialog Base Class */
class CodeDlg : public wxDialog
{
private:
	std::string mCode = "";

	wxTextCtrl* codeText = nullptr;

	GameView* mWindow = nullptr;
public:
	CodeDlg(GameView* window, std::string code);

	~CodeDlg();

	int ShowModal() override;

	std::string GetText() { return codeText->GetValue().ToStdString(); }

	void OnOK(wxCommandEvent& event);

	void OnClose(wxCloseEvent& event);
};

#endif //GAME_GAME_GAMELIB_CODEDLG_H
