/*
 *  The ManaPlus Client
 *  Copyright (C) 2004-2009  The Mana World Development Team
 *  Copyright (C) 2009-2010  The Mana Developers
 *  Copyright (C) 2011-2013  The ManaPlus Developers
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

#ifndef NET_TA_ADMINHANDLER_H
#define NET_TA_ADMINHANDLER_H

#include "net/adminhandler.h"
#include "net/net.h"

#include "net/ea/adminhandler.h"

#include "net/tmwa/messagehandler.h"

namespace TmwAthena
{

class AdminHandler final : public MessageHandler, public Ea::AdminHandler
{
    public:
        AdminHandler();

        A_DELETE_COPY(AdminHandler)

        void handleMessage(Net::MessageIn &msg);

        void announce(const std::string &text);

        void localAnnounce(const std::string &text);

        void hide(bool h);

        void kick(int playerId);
};

} // namespace TmwAthena

#endif // NET_TA_ADMINHANDLER_H
