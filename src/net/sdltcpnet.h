/*
 *  The ManaPlus Client
 *  Copyright (C) 2013-2017  The ManaPlus Developers
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

#ifndef NET_SDLTCPNET_H
#define NET_SDLTCPNET_H

#ifdef USE_SDL2
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch-default"
#endif  // USE_SDL2
#include <SDL_stdinc.h>
_SDL_stdinc_h
#ifdef USE_SDL2
#pragma GCC diagnostic pop
#endif  // USE_SDL2

#include <SDL_net.h>

#include "localconsts.h"

namespace TcpNet
{
    typedef ::SDLNet_SocketSet SocketSet;
    typedef ::TCPsocket Socket;

    void init();

    void quit();

    void closeSocket(const TcpNet::Socket socket);

    int send(const TcpNet::Socket sock, const void *const data, const int len);

    const char *getError();

    int resolveHost(IPaddress *const address, const char *const host,
                    const Uint16 port);

    TcpNet::Socket open(IPaddress *const ip);

    SocketSet allocSocketSet(const int maxsockets);

    int addSocket(const TcpNet::SocketSet set, const TcpNet::Socket sock);

    int socketReady(const TcpNet::Socket sock);

    int checkSockets(const TcpNet::SocketSet set, const Uint32 timeout);

    int recv(const TcpNet::Socket sock, void *const data, const int maxlen);

    int delSocket(const TcpNet::SocketSet set, const TcpNet::Socket sock);

    void freeSocketSet(const TcpNet::SocketSet set);

    TcpNet::Socket accept(const TcpNet::Socket sock);
}  // namespace TcpNet

#endif  // NET_SDLTCPNET_H
