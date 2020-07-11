<p align="center">
    <img src="https://github.com/AmayaHena/Nyx/blob/master/images/nyx_logo.png" width="550">
</p>

## Description
A try to make a useful lib to parse things & manage file(s).

Working on linux only.

You can find the documentation in the Wiki section of this repo.

WARNING: This lib is based on my personals needs in general, you can contact if you have an idea.

## Utility
File Management

File Parsing

JSON Parsing

XML Parsing

## Build
To build the project, CMake is required.

You can use the script:
```
./build.sh
```

You can also do the manual command line:
```
mkdir build && cd build && cmake .. && make
```

## Clean
If needed a cute script to clean the files generated after a build:
```
#!/bin/bash

rm -rf build/
rm -rf libNyx.so
```

## Preview

![](https://github.com/AmayaHena/Nyx/blob/master/images/nyx_preview.gif)
