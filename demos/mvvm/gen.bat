@echo off
node E:\AWStudio\AWTK\SDK\awtk_git\tools\idl_gen\index.js idl.json temperature.h
node ../../../awtk-mvvm/tools/view_model_gen/gen_vm.js idl.json