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

/*      _______   __   __   __   ______   __   __   _______   __   __
 *     / _____/\ / /\ / /\ / /\ / ____/\ / /\ / /\ / ___  /\ /  |\/ /\
 *    / /\____\// / // / // / // /\___\// /_// / // /\_/ / // , |/ / /
 *   / / /__   / / // / // / // / /    / ___  / // ___  / // /| ' / /
 *  / /_// /\ / /_// / // / // /_/_   / / // / // /\_/ / // / |  / /
 * /______/ //______/ //_/ //_____/\ /_/ //_/ //_/ //_/ //_/ /|_/ /
 * \______\/ \______\/ \_\/ \_____\/ \_\/ \_\/ \_\/ \_\/ \_\/ \_\/
 *
 * Copyright (c) 2004 - 2008 Olof Naessén and Per Larsson
 *
 *
 * Per Larsson a.k.a finalman
 * Olof Naessén a.k.a jansem/yakslem
 *
 * Visit: http://guichan.sourceforge.net
 *
 * License: (BSD)
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Guichan nor the names of its contributors may
 *    be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GCN_LISTBOX_HPP
#define GCN_LISTBOX_HPP

#include <list>

#include "gui/base/listmodel.hpp"
#include "gui/base/widget.hpp"

#include "listeners/keylistener.h"
#include "listeners/mouselistener.h"

class SelectionListener;

namespace gcn
{
    /**
     * An implementation of a list box where an item can be selected.
     *
     * To be able display a list the list box uses a user provided list model.
     * A list model can be any class that implements the ListModel interface.
     *
     * If an item is selected in the list box a select event will be sent to
     * all selection listeners of the list box. If an item is selected by using
     * a mouse click or by using the enter or space key an action event will be
     * sent to all action listeners of the list box.
     */
    class ListBox :
        public Widget,
        public MouseListener,
        public KeyListener
    {
    public:
        /**
         * Constructor.
         */
        ListBox();

        /**
         * Constructor.
         *
         * @param listModel the list model to use.
         */
        explicit ListBox(ListModel *listModel);

        A_DELETE_COPY(ListBox)

        /**
         * Destructor.
         */
        virtual ~ListBox()
        { }

        /**
         * Gets the selected item as an index in the list model.
         *
         * @return the selected item as an index in the list model.
         * @see setSelected
         */
        int getSelected() const;

         /**
         * Sets the selected item. The selected item is represented by
         * an index from the list model.
         *
         * @param selected the selected item as an index from the list model.
         * @see getSelected
         */
        void setSelected(int selected);

        /**
         * Sets the list model to use.
         *
         * @param listModel the list model to use.
         * @see getListModel
         */
        void setListModel(ListModel *listModel);

        /**
         * Gets the list model used.
         *
         * @return the list model used.
         * @see setListModel
         */
        ListModel *getListModel();

        /**
         * Adjusts the size of the list box to fit it's list model.
         */
        void adjustSize();

        /**
         * Checks whether the list box wraps when selecting items with a
         * keyboard.
         *
         * Wrapping means that the selection of items will be wrapped. That is,
         * if the first item is selected and up is pressed, the last item will
         * get selected. If the last item is selected and down is pressed, the
         * first item will get selected.
         *
         * @return true if wrapping is enabled, fasle otherwise.
         * @see setWrappingEnabled
         */
        bool isWrappingEnabled() const;

        /**
         * Sets the list box to wrap or not when selecting items with a
         * keyboard.
         *
         * Wrapping means that the selection of items will be wrapped. That is,
         * if the first item is selected and up is pressed, the last item will
         * get selected. If the last item is selected and down is pressed, the
         * first item will get selected.
         *
         * @see isWrappingEnabled
         */
        void setWrappingEnabled(bool wrappingEnabled);

        /**
         * Adds a selection listener to the list box. When the selection
         * changes an event will be sent to all selection listeners of the
         * list box.
         *
         * If you delete your selection listener, be sure to also remove it
         * using removeSelectionListener().
         *
         * @param selectionListener The selection listener to add.
         * @since 0.8.0
         */
        void addSelectionListener(SelectionListener* selectionListener);

        /**
         * Removes a selection listener from the list box.
         *
         * @param selectionListener The selection listener to remove.
         * @since 0.8.0
         */
        void removeSelectionListener(SelectionListener* selectionListener);

        /**
         * Gets the height of a row. Should be overridden if another row
         * height than the font height is preferred.
         *
         * @return The height of a row.
         * @since 0.8.0
         */
        virtual unsigned int getRowHeight() const;


        // Inherited from Widget

        virtual void draw(Graphics* graphics);

        virtual void logic();


        // Inherited from KeyListener

        virtual void keyPressed(KeyEvent& keyEvent) override;


        // Inherited from MouseListener

        virtual void mousePressed(MouseEvent& mouseEvent) override;

        virtual void mouseWheelMovedUp(MouseEvent& mouseEvent) override;

        virtual void mouseWheelMovedDown(MouseEvent& mouseEvent) override;

        virtual void mouseDragged(MouseEvent& mouseEvent) override;


    protected:
        /**
         * Distributes a value changed event to all selection listeners
         * of the list box.
         *
         * @since 0.8.0
         */
        void distributeValueChangedEvent();

        /**
         * The selected item as an index in the list model.
         */
        int mSelected;

        /**
         * The list model to use.
         */
        ListModel *mListModel;

        /**
         * True if wrapping is enabled, false otherwise.
         */
        bool mWrappingEnabled;

        /**
         * Typdef.
         */
        typedef std::list<SelectionListener*> SelectionListenerList;

        /**
         * The selection listeners of the list box.
         */
        SelectionListenerList mSelectionListeners;

        /**
         * Typedef.
         */
        typedef SelectionListenerList::iterator SelectionListenerIterator;
    };
}  // namespace gcn

#endif  // end GCN_LISTBOX_HPP
