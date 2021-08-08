/**
 * File:   window_button.cpp
 * Author: AWTK Develop Team
 * Brief:  button window
 *
 * Copyright (c) 2018 - 2021  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2021-08-08 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "window_button.hpp"

ret_t WindowButton::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK) {
    const char* name = target.GetName();
    log_debug("%s clicked\n", name);
    if (strstr(name, "close") != NULL) {
      this->Back();
    } else if (strstr(name, "fullscreen") != NULL) {
      TWindow win = TWindow::Cast(this->GetWindow());
      win.SetFullscreen(!win.GetFullscreen());
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t WindowButton::Open(TRequestPtr request) {
  WindowButton* win = new WindowButton(TWindow::Open("button"), request);

  win->OnChild(EVT_CLICK, "fullscreen");
  win->OnChild(EVT_CLICK, "close");

  return RET_OK;
}