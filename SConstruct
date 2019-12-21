import os
import sys
import platform

sys.path.insert(0, '../awtk/')
import awtk_config as awtk

APP_ROOT    = os.path.normpath(os.getcwd())
APP_BIN_DIR = os.path.join(APP_ROOT, 'bin')
APP_LIB_DIR = os.path.join(APP_ROOT, 'lib')
APP_SRC_DIR = os.path.join(APP_ROOT, 'src')
RES_ROOT    = awtk.TK_DEMO_ROOT.replace("\\", "\\\\")

os.environ['APP_ROOT'] = APP_ROOT;
os.environ['BIN_DIR'] = APP_BIN_DIR;
os.environ['LIB_DIR'] = APP_LIB_DIR;

APP_LIBS = ['awtk-cpp']
APP_LIBPATH = [APP_LIB_DIR]
APP_CPPPATH= [APP_SRC_DIR]
APP_CCFLAGS = ''

DefaultEnvironment(
  CPPPATH   = awtk.CPPPATH + APP_CPPPATH,
  LINKFLAGS = awtk.LINKFLAGS,
  LIBS      = APP_LIBS + awtk.LIBS,
  LIBPATH   = APP_LIBPATH + awtk.LIBPATH,
  CCFLAGS   = APP_CCFLAGS + awtk.CCFLAGS, 
  OS_SUBSYSTEM_CONSOLE=awtk.OS_SUBSYSTEM_CONSOLE,
  OS_SUBSYSTEM_WINDOWS=awtk.OS_SUBSYSTEM_WINDOWS)

SConscript(['src/SConscript', 'demos/SConscript'])

