/**
 * File:   button.cpp
 * Author: AWTK Develop Team
 * Brief:  button demo
 *
 * Copyright (c) 2018 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
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
 * 2019-12-21 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "mvvm/mvvm.h"
#include "awtk_cpp.hpp"
#include "application.hpp"
#include "temperature_view_model.h"

static ret_t ClickToQuit(void* ctx, event_t* e) {
  TGlobal::Quit();

  return RET_OK;
}

bool Application::Init(void) {
  view_model_factory_register("temperature", temperature_view_model_create);

  // 使用 awtk-mvvm 开发的时候, 页面的导航必须用 awtk-mvvm 提供的 navigator_to() 函数
  // 而不是 TWidget::Open() 函数, 因为 TWidget::Open() 函数会导致页面的生命周期管理混乱
  // 导致页面的生命周期管理混乱, 导致页面的生命周期管理混乱, 导致页面的生命周期管理混乱
  // TWidget win = TWindow::Open("my_homepage");
  navigator_to("my_homepage");

  return true;
}

bool Application::Exit(void) {
  log_debug("application_exit\n");

  return true;
}

