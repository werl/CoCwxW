//
// Created by peter on 2021-11-13.
//

#ifndef COCWXW_DEFAULT_PANEL_HPP
#define COCWXW_DEFAULT_PANEL_HPP


#include "abstract_panel.hpp"

class DefaultPanel: public AbstractPanel {
public:
    explicit DefaultPanel (wxWindow *parent);

    bool shouldPromptForSave () override;
};


#endif //COCWXW_DEFAULT_PANEL_HPP
