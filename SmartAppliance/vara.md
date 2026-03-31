In this I created a UI and generate the Zephyr project from Gui Guider in simulator mode and install wsl and required libraries like sdl2 for native_sim 

1. Change and added the kconfig componets
2. modified few lvgl functions as per the zephyr libraries and built
3. Getting output in native simulator


$ west build -p always -b native_sim/native/64 ../SmartAppliance/ --build-dir ../SmartAppliance/build

$ ../SmartAppliance/build/zephyr/zephyr.exe