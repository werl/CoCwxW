//
// Created by peter on 2021-11-09.
//

#ifndef COCWXW_ID_ENUM_HPP
#define COCWXW_ID_ENUM_HPP

#include "wx/defs.h"

enum WindowID
{
    ID_MAIN = wxID_HIGHEST + 1,
    ID_WIN_HIGHEST
};

enum ButtonID {
    ID_MINUS = ID_WIN_HIGHEST + 1,
    ID_PLUS,
    ID_NEW_NPC,
    ID_NEW_PLAYER
};
#endif //COCWXW_ID_ENUM_HPP
