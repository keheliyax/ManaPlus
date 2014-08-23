/*
 *  The ManaPlus Client
 *  Copyright (C) 2011-2014  The ManaPlus Developers
 *
 *  This file is part of The ManaPlus Client.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gui/setupactiondata.h"

#include "input/inputaction.h"
#include "input/inputactiondata.h"

#include "utils/gettext.h"
#include "utils/stringutils.h"

#include "debug.h"

SetupActionData setupActionDataChat[] =
{
    {
        // TRANSLATORS: input action name
        N_("Toggle Chat"),
        InputAction::TOGGLE_CHAT,
        "",
    },
    {
        // TRANSLATORS: input action name
        N_("Scroll Chat Up"),
        InputAction::SCROLL_CHAT_UP,
        "",
    },
    {
        // TRANSLATORS: input action name
        N_("Scroll Chat Down"),
        InputAction::SCROLL_CHAT_DOWN,
        "",
    },
    {
        // TRANSLATORS: input action name
        N_("Previous Chat Tab"),
        InputAction::PREV_CHAT_TAB,
        "",
    },
    {
        // TRANSLATORS: input action name
        N_("Next Chat Tab"),
        InputAction::NEXT_CHAT_TAB,
        "",
    },
    {
        // TRANSLATORS: input action name
        N_("Close current Chat Tab"),
        InputAction::CLOSE_CHAT_TAB,
        "",
    },
    {
        // TRANSLATORS: input action name
        N_("Close all chat tabs"),
        InputAction::CLOSE_ALL_CHAT_TABS,
        "",
    },
    {
        // TRANSLATORS: input action name
        N_("Previous chat line"),
        InputAction::CHAT_PREV_HISTORY,
        "",
    },
    {
        // TRANSLATORS: input action name
        N_("Next chat line"),
        InputAction::CHAT_NEXT_HISTORY,
        "",
    },
    {
        // TRANSLATORS: input action name
        N_("Chat modifier key"),
        InputAction::CHAT_MOD,
        "",
    },
    {
        // TRANSLATORS: input action name
        N_("Show smiles"),
        InputAction::GUI_F1,
        "",
    },
    {
        "F2",
        InputAction::GUI_F2,
        "",
    },
    {
        "F3",
        InputAction::GUI_F3,
        "",
    },
    {
        "F4",
        InputAction::GUI_F4,
        "",
    },
    {
        "F5",
        InputAction::GUI_F5,
        "",
    },
    {
        "F6",
        InputAction::GUI_F6,
        "",
    },
    {
        "F7",
        InputAction::GUI_F7,
        "",
    },
    {
        "F8",
        InputAction::GUI_F8,
        "",
    },
    {
        "F9",
        InputAction::GUI_F9,
        "",
    },
    {
        "F10",
        InputAction::GUI_F10,
        "",
    },
    {
        "F11",
        InputAction::GUI_F11,
        "",
    },
    {
        "F12",
        InputAction::GUI_F12,
        "",
    },
    {
        "",
        InputAction::NO_VALUE,
        ""
    }
};
