/*
 *  The ManaPlus Client
 *  Copyright (C) 2013  The ManaPlus Developers
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

#ifndef DRAGDROP_H
#define DRAGDROP_H

#include "item.h"
#include "textcommand.h"

#include "gui/widgets/skilldata.h"
#include "gui/widgets/skillinfo.h"

#include "resources/image.h"

#include "localconsts.h"

enum DragDropSource
{
    DRAGDROP_SOURCE_EMPTY = 0,
    DRAGDROP_SOURCE_INVENTORY,
    DRAGDROP_SOURCE_STORAGE,
    DRAGDROP_SOURCE_CART,
    DRAGDROP_SOURCE_TRADE,
    DRAGDROP_SOURCE_OUTFIT,
    DRAGDROP_SOURCE_SPELLS,
    DRAGDROP_SOURCE_SKILLS,
    DRAGDROP_SOURCE_GROUND,
    DRAGDROP_SOURCE_DROP,
    DRAGDROP_SOURCE_SHORTCUTS,
    DRAGDROP_SOURCE_CRAFT,
    DRAGDROP_SOURCE_NPC,
    DRAGDROP_SOURCE_EQUIPMENT
};

class DragDrop final
{
    public:
        DragDrop(Item *const item, const DragDropSource source) :
            mItem(item ? item->getId() : 0),
            mItemColor(item ? item->getColor() : 1),
            mItemImage(item ? item->getImage() : nullptr),
            mSelItem(0),
            mSelItemColor(1),
            mSource(source),
            mText(),
            mTag(-1)
        {
            if (mItemImage)
                mItemImage->incRef();
        }

        A_DELETE_COPY(DragDrop)

        ~DragDrop()
        {
            if (mItemImage)
                mItemImage->decRef();
        }

        int getItem()
        { return mItem; }

        int getItemColor()
        { return mItemColor; }

        Image *getItemImage()
        { return mItemImage; }

        DragDropSource getSource() const
        { return mSource; }

        void dragItem(const Item *const item,
                      const DragDropSource source,
                      const int tag = 0)
        {
            if (mItemImage)
                mItemImage->decRef();

            mText.clear();
            if (item)
            {
                mItem = item->getId();
                mItemColor = item->getColor();
                mItemImage = item->getImage();
                if (mItemImage)
                    mItemImage->incRef();
                mSource = source;
                mTag = tag;
            }
            else
            {
                mItem = 0;
                mItemColor = 1;
                mItemImage = nullptr;
                mSource = DRAGDROP_SOURCE_EMPTY;
                mTag = -1;
            }
        }

        void dragCommand(const TextCommand *const command,
                         const DragDropSource source,
                         const int tag = 0)
        {
            if (mItemImage)
                mItemImage->decRef();
            mItem = 0;
            mItemColor = 1;

            if (command)
            {
                mText = command->getSymbol();
                mItemImage = command->getImage();
                if (mItemImage)
                {
                    mItemImage->incRef();
                }
                else if (mText.empty())
                {
                    mSource = source;
                    mTag = -1;
                    return;
                }
                mItem = command->getId();
            }
            else
            {
                mText.clear();
                mItemImage = nullptr;
            }
            mSource = source;
            mTag = tag;
        }

        void dragSkill(const SkillInfo *const info,
                       const DragDropSource source,
                       const int tag = 0)
        {
            if (mItemImage)
                mItemImage->decRef();
            mItem = 0;
            mItemColor = 1;
            mText.clear();
            mItemImage = nullptr;
            mSource = DRAGDROP_SOURCE_EMPTY;
            mTag = -1;
            if (info)
            {
                const SkillData *const data = info->data;
                if (data)
                {
                    mText = data->name;
                    mItemImage = data->icon;
                    if (mItemImage)
                        mItemImage->incRef();
                    mItem = info->id;
                    mSource = source;
                    mTag = tag;
                }
            }
        }

        void clear()
        {
            if (mItemImage)
                mItemImage->decRef();
            mItem = 0;
            mItemColor = 1;
            mItemImage = nullptr;
            mSource = DRAGDROP_SOURCE_EMPTY;
            mText.clear();
            mTag = -1;
        }

        bool isEmpty() const
        { return mSource == DRAGDROP_SOURCE_EMPTY; }

        void select(Item *const item)
        {
            if (item)
            {
                mSelItem = item->getId();
                mSelItemColor = item->getColor();
            }
            else
            {
                mSelItem = 0;
                mSelItemColor = 1;
            }
        }

        void deselect()
        {
            mSelItem = 0;
            mSelItemColor = 1;
        }

        int getSelected() const
        { return mSelItem; }

        int getSelectedColor() const
        { return mSelItemColor; }

        bool isSelected() const
        { return mSelItem > 0; }

        void clearItem(const Item *const item A_UNUSED)
        {
        }

        const std::string &getText() const
        { return mText; }

        int getTag() const
        { return mTag; }

        void setItem(const int item)
        { mItem = item; }

        bool isSourceItemContainer() const
        {
            return mSource == DRAGDROP_SOURCE_INVENTORY
                || mSource == DRAGDROP_SOURCE_STORAGE
                || mSource == DRAGDROP_SOURCE_CART
                || mSource == DRAGDROP_SOURCE_TRADE
                || mSource == DRAGDROP_SOURCE_OUTFIT
                || mSource == DRAGDROP_SOURCE_GROUND
                || mSource == DRAGDROP_SOURCE_DROP
                || mSource == DRAGDROP_SOURCE_CRAFT;
        }

    private:
        int mItem;
        uint8_t mItemColor;
        Image *mItemImage;
        int mSelItem;
        uint8_t mSelItemColor;
        DragDropSource mSource;
        std::string mText;
        int mTag;
};

extern DragDrop dragDrop;

#endif  // DRAGDROP_H
