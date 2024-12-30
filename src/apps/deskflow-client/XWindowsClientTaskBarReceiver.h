/*
 * Deskflow -- mouse and keyboard sharing utility
 * Copyright (C) 2012-2016 Symless Ltd.
 * Copyright (C) 2003 Chris Schoeneman
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "deskflow/ClientTaskBarReceiver.h"

class BufferedLogOutputter;
class IEventQueue;

//! Implementation of ClientTaskBarReceiver for X Windows
class CXWindowsClientTaskBarReceiver : public ClientTaskBarReceiver
{
public:
  CXWindowsClientTaskBarReceiver(const BufferedLogOutputter *, IEventQueue *events);
  CXWindowsClientTaskBarReceiver(const CXWindowsClientTaskBarReceiver &) = delete;
  CXWindowsClientTaskBarReceiver(CXWindowsClientTaskBarReceiver &&) = delete;
  virtual ~CXWindowsClientTaskBarReceiver();

  CXWindowsClientTaskBarReceiver &operator=(const CXWindowsClientTaskBarReceiver &) = delete;
  CXWindowsClientTaskBarReceiver &operator=(CXWindowsClientTaskBarReceiver &&) = delete;

  // IArchTaskBarReceiver overrides
  void showStatus() override;
  void runMenu(int x, int y) override;
  void primaryAction() override;
  Icon getIcon() const override;
};