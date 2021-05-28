
prepare:
	cp   ./templates/Android.mk ./Android.mk
	cp   ./templates/Application.mk ./Application.mk
	
	sed -i 's/<module>/$(MODULE)/g' Android.mk
	sed -i 's/<module>/$(MODULE)/g' Application.mk
	

build_saxpy_serial:
	/opt/android-ndk-r20/ndk-build
	adb push ../libs/armeabi-v7a/saxpy_serial /data/local/tmp
	adb shell /data/local/tmp/saxpy_serial 100
	adb shell /data/local/tmp/saxpy_serial 10000
	adb shell /data/local/tmp/saxpy_serial 1000000

build_saxpy_parallel:
	/opt/android-ndk-r20/ndk-build
	adb push ../libs/armeabi-v7a/saxpy_parallel /data/local/tmp
	adb shell /data/local/tmp/saxpy_parallel 100
	adb shell /data/local/tmp/saxpy_parallel 10000
	adb shell /data/local/tmp/saxpy_parallel 1000000
