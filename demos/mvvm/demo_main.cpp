/**
 * File:   demo_main.cpp
 * Author: AWTK Develop Team
 * Brief:  demo main
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

#include "awtk.h"
#include "mvvm_app.inc"
#include "application.hpp"

static ret_t global_init(void) {
  mvvm_app_init();
  mvvm_app_run_default_scripts();

#ifdef LINUX
  signal(SIGINT, on_signal);
#endif /*LINUX*/

  return RET_OK;
}
#define GLOBAL_INIT() global_init()
#define GLOBAL_EXIT() mvvm_app_deinit()


static ret_t application_init(void) {
  Application::Init();

  return RET_OK;
}

static ret_t application_exit(void) {
  Application::Exit();

  return RET_OK;
}

#define APP_DEFAULT_FONT "default_full"

#include "awtk_main.inc"


