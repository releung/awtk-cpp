/**
 * File:   window_main.hpp
 * Author: AWTK Develop Team
 * Brief:  main window
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

#ifndef TK_WINDOW_BUTTON_H
#define TK_WINDOW_BUTTON_H

#include "awtk_cpp.hpp"
#include "app_window.hpp"

class WindowButton : public TAppWindow {
 public:
  WindowButton(TWidget win, TRequestPtrRef request) : TAppWindow(win, request) {
  }

 public:
  virtual ret_t OnEvent(TWidget& target, TEvent& e);

 public:
  static ret_t Open(TRequestPtr request);
};

#endif /*TK_WINDOW_BUTTON_H*/
