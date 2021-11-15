//
// Created by peter on 2021-11-09.
//

#ifndef COCWXW_RIGHT_PANEL_HPP
#define COCWXW_RIGHT_PANEL_HPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class RightPanel: public wxPanel {
public:
    explicit RightPanel(wxPanel *parent);

    wxStaticText *text;
};


#endif //COCWXW_RIGHT_PANEL_HPP
