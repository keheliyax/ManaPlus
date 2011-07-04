/*
 *  The ManaPlus Client
 *  Copyright (C) 2004-2009  The Mana World Development Team
 *  Copyright (C) 2009-2010  The Mana Developers
 *  Copyright (C) 2011  The ManaPlus Developers
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

#ifndef WINDOWMENU_H
#define WINDOWMENU_H

#include "gui/widgets/container.h"
#include "gui/widgets/button.h"

#include <guichan/actionlistener.hpp>
#include <guichan/selectionlistener.hpp>

#include <map>
#include <vector>

#ifdef __GNUC__
#define _UNUSED_  __attribute__ ((unused))
#else
#define _UNUSED_
#endif

class EmotePopup;
class TextPopup;

/**
 * The window menu. Allows showing and hiding many of the different windows
 * used in the game.
 *
 * \ingroup Interface
 */
class WindowMenu : public Container,
                   public gcn::ActionListener,
                   public gcn::SelectionListener,
                   public gcn::MouseListener
{
    public:
        WindowMenu();
        ~WindowMenu();

        void action(const gcn::ActionEvent &event);

        void valueChanged(const gcn::SelectionEvent &event);

        void mousePressed(gcn::MouseEvent &event);

        void mouseMoved(gcn::MouseEvent &event);

        void mouseExited(gcn::MouseEvent& mouseEvent _UNUSED_);

        std::map <std::string, gcn::Button*> &getButtonNames()
        { return mButtonNames; }

        std::vector <gcn::Button*> &getButtons()
        { return mButtons; }

        void showButton(std::string name, bool isVisible);

        void loadButtons();

        void saveButtons();

    private:
        inline void addButton(const char* text, std::string description,
                              int &x, int &h, int key);

        void updateButtons();

        EmotePopup *mEmotePopup;
        TextPopup *mTextPopup;
        std::vector <gcn::Button*> mButtons;
        std::map <std::string, gcn::Button*> mButtonNames;
};

extern WindowMenu *windowMenu;

#endif
