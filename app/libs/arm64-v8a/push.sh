#!/bin/bash

adb push android.hardware.graphics.bufferqueue@1.0.so /data/app/$1/lib/arm64/
adb push android.hardware.graphics.common@1.0.so /data/app/$1/lib/arm64/
adb push android.hidl.token@1.0-utils.so /data/app/$1/lib/arm64/
adb push android.hardware.media@1.0.so /data/app/$1/lib/arm64/
adb push android.hidl.token@1.0.so /data/app/$1/lib/arm64/
