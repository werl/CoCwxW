//
// Created by peter on 2021-11-09.
//

#include "main_frame.hpp"
#include "id_enum.hpp"
#include "panels/default_panel.hpp"

MainFrame::MainFrame(): wxFrame(nullptr, wxID_ANY, "Character Creator", wxDefaultPosition, wxSize(800, 600)) {
    auto *menuBar = createMenuBar ();

    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    createBinds ();

    parent = new DefaultPanel (this);
    auto hBox = new wxBoxSizer(wxHORIZONTAL);

    lp = new LeftPanel(parent);
    rp = new RightPanel(parent);

    hBox->Add (lp, 1, wxEXPAND | wxALL, 5);
    hBox->Add (rp, 1, wxEXPAND | wxALL, 5);
    parent->SetSizer (hBox);

    this->Center ();
}

wxMenuBar* MainFrame::createMenuBar () {
    auto *menuFile = new wxMenu;
    menuFile->Append(WindowID::ID_MAIN, "&Hello...\tCtrl-H","Help string shown in status bar for this menu item");

    auto *menuNew = new wxMenu;
    menuNew->Append (ID_NEW_NPC, "NPC", "Create a new NPC");
    menuNew->Append (ID_NEW_PLAYER, "Player", "Create a new Player");

    menuFile->AppendSubMenu (menuNew, wxT("New"));

    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    auto *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    auto *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    return menuBar;
}

void MainFrame::createBinds () {
    Bind(wxEVT_MENU, [=] (wxCommandEvent&)
    {
        wxLogMessage("Hello world from wxWidgets!");
    }, WindowID::ID_MAIN);

    Bind(wxEVT_MENU, [=] (wxCommandEvent& event)
    {
        wxMessageBox("This is a wxWidgets Hello World example","About Hello World", wxOK | wxICON_INFORMATION);
    }, wxID_ABOUT);

    Bind(wxEVT_MENU, [=] (wxCommandEvent&)
    {
        if (parent->shouldPromptForSave ()) {
            bool success = save();
            if (!success)
                return;
        }
        Close();
    }, wxID_EXIT);

    Bind(wxEVT_CLOSE_WINDOW, [=] (wxCloseEvent& event)
    {
        printf("hello");
        if (event.CanVeto() && parent->shouldPromptForSave ()) {
            if ( wxMessageBox("The file has not been saved... continue closing?","Please confirm",wxICON_QUESTION | wxYES_NO) != wxYES )
            {
                event.Veto();
                return;
            }
        }
        event.Skip ();
    }, WindowID::ID_MAIN);
}

bool MainFrame::save () {
    if (currentDocPath.empty()) {
        return saveAs();
    } else {
        return parent->doSave (currentDocPath);
    }
}

bool MainFrame::saveAs () {
    auto saveDialog = new wxFileDialog(this, "Save File as?", currentDocDir, currentDocName, wxT("CoC Character Files (*.ccf"),
                                       wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);
    if (saveDialog->ShowModal() == wxID_OK) {
        currentDocDir = saveDialog->GetDirectory();
        currentDocName = saveDialog->GetFilename();
        currentDocPath = saveDialog->GetPath();
        bool success = parent->doSave (currentDocPath);
        saveDialog->Destroy();
        return success;
    }
    saveDialog->Destroy();
    return false;
}
