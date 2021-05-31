
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
	adb shell /data/local/tmp/saxpy_serial 100000000
	

run_saxpy_serial:
	make prepare MODULE=saxpy_serial
	make build_saxpy_serial


build_saxpy_parallel:
	/opt/android-ndk-r20/ndk-build
	adb push ../libs/armeabi-v7a/saxpy_parallel /data/local/tmp
	adb shell /data/local/tmp/saxpy_parallel 100
	adb shell /data/local/tmp/saxpy_parallel 10000
	adb shell /data/local/tmp/saxpy_parallel 1000000
	adb shell /data/local/tmp/saxpy_parallel 100000000

run_saxpy_parallel:
	make prepare MODULE=saxpy_parallel
	make build_saxpy_parallel

build_euler_serial:
	/opt/android-ndk-r20/ndk-build
	adb push ../libs/armeabi-v7a/euler_serial /data/local/tmp
	adb shell /data/local/tmp/euler_serial 100
	adb shell /data/local/tmp/euler_serial 200
	adb shell /data/local/tmp/euler_serial 1000
	adb shell /data/local/tmp/euler_serial 2000
	adb shell /data/local/tmp/euler_serial 10000
	adb shell /data/local/tmp/euler_serial 20000

run_euler_serial:
	make prepare MODULE=euler_serial
	make build_euler_serial


build_euler_parallel:
	/opt/android-ndk-r20/ndk-build
	adb push ../libs/armeabi-v7a/euler_parallel /data/local/tmp
	adb shell /data/local/tmp/euler_parallel 20
	

run_euler_parallel:
	make prepare MODULE=euler_parallel
	make build_euler_parallel



