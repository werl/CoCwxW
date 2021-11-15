//
// Created by peter on 2021-11-09.
//

#ifndef COCWXW_LEFT_PANEL_HPP
#define COCWXW_LEFT_PANEL_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class LeftPanel: public wxPanel {
public:
    LeftPanel(wxPanel *parent);

    void OnPlus(wxCommandEvent & event);
    void OnMinus(wxCommandEvent & event);

    wxButton *plus;
    wxButton *minus;
    wxPanel *parent;
    int count;
};


#endif //COCWXW_LEFT_PANEL_HPP
