//
// Created by peter on 2021-11-09.
//

#include "right_panel.hpp"

RightPanel::RightPanel (wxPanel *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(270, 150), wxBORDER_SUNKEN) {
    text = new wxStaticText(this, -1, wxT("0"), wxPoint(40, 60));
}
