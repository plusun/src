/* Copyright (C) 2009-2017 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#if !defined(GDB_USLEEP_H)
#define GDB_USLEEP_H

/* Suspend execution for USEC microseconds.

   Limitation: If a signal is raised during the delay, gdb_usleep
   might return earlier than requested.

   It returns 0 on success or -1 on error.  */
extern int gdb_usleep (int usect);

#endif /* !defined(GDB_USLEEP_H) */

