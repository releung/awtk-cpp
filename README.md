# awtk-cpp

ZLG 开源 GUI 引擎 [awtk](https://github.com/zlgopen/awtk) 针对 C++ 的绑定。

## 准备

1. 获取 awtk 并编译

```
git clone https://github.com/zlgopen/awtk.git
cd awtk; scons; cd -
```

2. 获取 awtk-cpp 并编译

```
git clone https://github.com/zlgopen/awtk-cpp.git
cd awtk-cpp

# 使用默认配置
scons

# 或者指定 AWTK_ROOT MVVM_ROOT 路径
# 需要提前编译好 awtk-mvvm 库
scons AWTK_ROOT="E:/AWStudio/AWTK/SDK/awtk_git" MVVM_ROOT="E:/leung/wp/QTProjects/AllAboutQtAndCPlusPlus/projects/awtk/awtk-mvvm" -j4
```

* 生成资源

```
# 使用默认配置
python ./scripts/update_res.py all

# 或者指定 AWTK_ROOT 路径
python .\scripts\update_res.py all --awtk_root=E:\AWStudio\AWTK\SDK\awtk_git
```

> 或者通过 designer 生成资源

> designer 可能需要修改 project.json 配置路径

```json
  "awtkRoot": "${AWTK_SDK_PATH}/awtk_git",
  "awtkMvvmRoot": "E:/leung/wp/QTProjects/AllAboutQtAndCPlusPlus/projects/awtk/awtk-mvvm"
```

* 编译PC版本

```
scons
```

* 编译LINUX FB版本

```
scons LINUX_FB=true
```

> 完整编译选项请参考[编译选项](https://github.com/zlgopen/awtk-widget-generator/blob/master/docs/build_options.md)


## 运行

```
./bin/demo_basic
```

## 更新绑定（由本项目的维护人员完成）

```
./sync.sh
```

> 在非 bash 终端（如 Windows 平台的 cmd.exe)，需要根据 sync.sh 的内容手工执行相应的命令。

## 代码示例

```cpp
  TWidget win = TWindow::CreateDefault();
  TWidget ok = TButton::Create(win, 0, 0, 0, 0);

  ok.SetText("quit");
  ok.SetSelfLayoutParams("center", "middle", "50%", "30");

  ok.On(EVT_CLICK, ClickToQuit, NULL);
```

## 文档

[AWTK 脚本绑定原理](https://github.com/zlgopen/awtk/blob/master/docs/script_binding.md)

> 本文以 Linux/MacOS 为例，Windows 可能会微妙差异，请酌情处理。

## C++应用程序框架

请参考：hello目录。

> 感谢staunchheart(QQ:36380047)兄提供C++框架(包括代码生成)的思路和各种建议。

