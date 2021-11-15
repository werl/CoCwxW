//
// Created by peter on 2021-11-09.
//

#ifndef COCWXW_MAIN_FRAME_HPP
#define COCWXW_MAIN_FRAME_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "panels/left_panel.hpp"
#include "panels/right_panel.hpp"
#include "panels/abstract_panel.hpp"

class MainFrame: public wxFrame {
public:
    MainFrame();

    LeftPanel *lp;
    RightPanel *rp;
    AbstractPanel *parent;

private:
    wxString currentDocPath = "";
    wxString currentDocDir = wxGetHomeDir();
    wxString currentDocName = "Untitled.ccf";

    wxMenuBar* createMenuBar();
    void createBinds();

    bool save();
    bool saveAs();
};


#endif //COCWXW_MAIN_FRAME_HPP
