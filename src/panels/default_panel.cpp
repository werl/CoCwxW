//
// Created by peter on 2021-11-13.
//

#include "default_panel.hpp"

DefaultPanel::DefaultPanel (wxWindow *parent): AbstractPanel (parent, wxID_ANY, wxDefaultPosition, wxSize(800, 600)) {

}

bool DefaultPanel::shouldPromptForSave () {
    return true;
}
