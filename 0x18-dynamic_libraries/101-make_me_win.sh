#!/bin/bash
wget -P /tmp libwin.so https://github.com/ahmadalwa/alx-low_level_programming/raw/main/0x18-dynamic_libraries/libwin.so
export LD_PRELOAD=/tmp/libwin.so
