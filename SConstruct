import os
import platform
import scripts.app_helper as app

ARGUMENTS['WITH_MVVM'] = 'true'
ARGUMENTS['FONT'] = 'default_full'
helper = app.Helper(ARGUMENTS);

APP_CXXFLAGS=''
if platform.system() == 'Windows':
  APP_CXXFLAGS += ' /std:c++17 '
else:
  APP_CXXFLAGS += ' -std=c++17 '

CUSTOM_WIDGET_LIBS = []

DEPENDS_LIBS = CUSTOM_WIDGET_LIBS + [
  {
    "root" : '../awtk-mvvm',
    'shared_libs': ['mvvm'],
    'static_libs': []
  }
]

helper.add_cxxflags(APP_CXXFLAGS)
helper.add_libs(['awtk-cpp']).call(DefaultEnvironment)
helper.set_deps(DEPENDS_LIBS)

SConscriptFiles = ['3rd/quickjs/SConscript', 'src/SConscript', 'demos/SConscript', 'hello/SConscript']
helper.SConscript(SConscriptFiles)
