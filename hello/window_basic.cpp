/**
 * File:   window_basic.cpp
 * Author: AWTK Develop Team
 * Brief:  basic window
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

#include "window_basic.hpp"

ret_t WindowBasic::OnEvent(TWidget& target, TEvent& e) {
  if (e.GetType() == EVT_CLICK) {
    const char* name = target.GetName();
    log_debug("%s clicked\n", name);

    if (strstr(name, "inc_value") != NULL) {
      this->Lookup("bar1").AddValue(10);
      this->Lookup("bar2").AddValue(10);
    } else if (strstr(name, "dec_value") != NULL) {
      this->Lookup("bar1").AddValue(-10);
      this->Lookup("bar2").AddValue(010);
    } else if (strstr(name, "switch_to:main") != NULL) {
      TAppWindow::SwitchTo("main", false);
    }
  }

  return TAppWindow::OnEvent(target, e);
}

ret_t WindowBasic::Open(TRequestPtr request) {
  if (TAppWindow::isWindowOpen("basic")) {
    log_debug("basic exist, switch to it");
    TAppWindow::SwitchTo("basic", false);
  } else {
    WindowBasic* win = new WindowBasic(TWindow::Open("basic"), request);
    int value = request->GetInt("value", 10);

    win->OnChild(EVT_CLICK, "inc_value");
    win->OnChild(EVT_CLICK, "dec_value");
    win->OnChild(EVT_CLICK, "switch_to:main");

    win->Lookup("bar1").SetValue(value);
    win->Lookup("bar2").SetValue(value);
  }
  return RET_OK;
}