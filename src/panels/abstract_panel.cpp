//
// Created by peter on 2021-11-13.
//

#include "abstract_panel.hpp"

AbstractPanel::AbstractPanel (wxWindow *parent, wxWindowID winid, const wxPoint& pos, const wxSize& size, long style, const wxString& name):
        wxPanel (parent, winid, pos, size, style, name){

}

bool AbstractPanel::doSave (const wxString& filePath) {
    return true;
}

void AbstractPanel::doOpen (const wxString &filePath) {

}
