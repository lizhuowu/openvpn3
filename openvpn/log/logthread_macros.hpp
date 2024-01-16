//    OpenVPN -- An application to securely tunnel IP networks
//               over a single port, with support for SSL/TLS-based
//               session authentication and key exchange,
//               packet encryption, packet authentication, and
//               packet compression.
//
//    Copyright (C) 2012-2022 OpenVPN Inc.
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License Version 3
//    as published by the Free Software Foundation.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program in the COPYING file.
//    If not, see <http://www.gnu.org/licenses/>.

// This is a general-purpose logging framework that allows for OPENVPN_LOG and
// OPENVPN_LOG_NTNL macros to dispatch logging data to a thread-local handler.

#ifndef OPENVPN_LOG_LOGTHREAD_MACROS_H
#define OPENVPN_LOG_LOGTHREAD_MACROS_H

// Define this parameter before including this header:
// OPENVPN_LOG_INFO  -- converts a log string to the form that should be passed to log()

#ifndef OPENVPN_LOG_INFO
#error OPENVPN_LOG_INFO must be defined
#endif

#define OPENVPN_LOG(args)                                                           \
    do                                                                              \
    {                                                                               \
        if (openvpn::Log::Context::defined())                                       \
        {                                                                           \
            std::ostringstream _ovpn_log;                                           \
            _ovpn_log << args << '\n';                                              \
            (openvpn::Log::Context::obj()->log(OPENVPN_LOG_INFO(_ovpn_log.str()))); \
        }                                                                           \
    } while (0)

// like OPENVPN_LOG but no trailing newline
#define OPENVPN_LOG_NTNL(args)                                                      \
    do                                                                              \
    {                                                                               \
        if (openvpn::Log::Context::defined())                                       \
        {                                                                           \
            std::ostringstream _ovpn_log;                                           \
            _ovpn_log << args;                                                      \
            (openvpn::Log::Context::obj()->log(OPENVPN_LOG_INFO(_ovpn_log.str()))); \
        }                                                                           \
    } while (0)

#define OPENVPN_LOG_STRING(str)                                         \
    do                                                                  \
    {                                                                   \
        if (openvpn::Log::Context::defined())                           \
        {                                                               \
            (openvpn::Log::Context::obj()->log(OPENVPN_LOG_INFO(str))); \
        }                                                               \
    } while (0)


#endif
