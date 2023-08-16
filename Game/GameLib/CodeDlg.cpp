/**
 * @file CodeDlg.cpp
 *
 * @author Spencer Russell
 */
#include "pch.h"
#include "CodeDlg.h"
#include "Game.h"

CodeDlg::CodeDlg(GameView* window, std::string code) : mWindow(window), mCode(code)
{
	Create(mWindow, wxID_ANY, "Bug Squash IDE",wxDefaultPosition,wxDefaultSize);
	SetSize(0, 0, 600, 480);

	auto vsizer = new wxBoxSizer( wxVERTICAL );

	mWindow->StopStopwatch();

	Bind(wxEVT_CLOSE_WINDOW, &CodeDlg::OnClose, this, wxID_EXIT);

	codeText = new wxTextCtrl(this, wxID_ANY, code, wxDefaultPosition, wxDefaultSize,
										  wxNO_BORDER | wxTE_MULTILINE  | wxTE_RICH);

	codeText->SetMinSize(wxSize(400,380));

	vsizer->Add(&(*codeText), wxSizerFlags().Border(wxALL, 10));

	wxButton* okButton = new wxButton(this, wxID_OK, "OK");

	okButton->SetMinSize(wxDefaultSize);

	// Bind an event handler to the button
	okButton->Bind(wxEVT_BUTTON, &CodeDlg::OnOK, this, wxID_ANY);

	// Add the button to the vertical sizer and set its position
	vsizer->Add(okButton, 0, wxALIGN_CENTER_HORIZONTAL, 0);

	SetSizer(vsizer);
}

int CodeDlg::ShowModal()
{
	CenterOnParent();
	return wxDialog::ShowModal();
}
CodeDlg::~CodeDlg()
{
	delete codeText;
}

void CodeDlg::OnOK(wxCommandEvent& event)
{
	mWindow->ResumeStopwatch();
	EndModal(wxID_OK);
}

void CodeDlg::OnClose(wxCloseEvent& event)
{
	mWindow->ResumeStopwatch();
	EndModal(wxID_CANCEL);
}