/**
 * File:   window_edit.cpp
 * Author: AWTK Develop Team
 * Brief:  edit window
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

#include "window_edit.hpp"

ret_t WindowEdit::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK) {
    const char* name = target.GetName();
    log_debug("%s clicked\n", name);

    if (strstr(name, "close") != NULL) {
      this->Back();
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t WindowEdit::Open(TRequestPtr request) {
  WindowEdit* win = new WindowEdit(TWindow::Open("edit"), request);

  win->OnChild(EVT_CLICK, "close");

  return RET_OK;
}