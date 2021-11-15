//
// Created by peter on 2021-11-09.
//

#include "left_panel.hpp"
#include "../main_frame.hpp"
#include "../id_enum.hpp"

LeftPanel::LeftPanel (wxPanel *parent) : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN) {
    count = 0;
    this->parent = parent;
    plus = new wxButton(this, ID_PLUS, wxT("+"), wxPoint(10, 10));
    minus = new wxButton(this, ID_MINUS, wxT("-"), wxPoint(10, 60));
    Connect(ID_PLUS, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnPlus));
    Connect(ID_MINUS, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnMinus));
}

void LeftPanel::OnPlus (wxCommandEvent &event) {
    count++;

    auto frame = (MainFrame *) parent->GetParent();
    frame->rp->text->SetLabel (wxString::Format (wxT("%d"), count));
}

void LeftPanel::OnMinus (wxCommandEvent &event) {
    count--;

    auto frame = (MainFrame *) parent->GetParent();
    frame->rp->text->SetLabel (wxString::Format (wxT("%d"), count));
}
