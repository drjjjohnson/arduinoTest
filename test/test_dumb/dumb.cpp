#include "unity.h"
#include <sum.h>

void test_static(void)
{
    TEST_ASSERT_EQUAL(2, 1 + 1);
}
void test_static_wrong(void)
{
    TEST_ASSERT_EQUAL(3, 1 + 1);
}

void test_class(void)
{
    Sum s;
    TEST_ASSERT_EQUAL(2, s.sum(1, 1)); // Will run in native env if commented,
    /*otherwise
            Undefined symbols for architecture arm64:
        "Sum::sum(int, int)", referenced from:
            test_class() in dumb.o
        ld: symbol(s) not found for architecture arm64
    For native
CONFIGURATION: https://docs.platformio.org/page/boards/atmelavr/leonardo.html
PLATFORM: Atmel AVR (4.0.0) > Arduino Leonardo
HARDWARE: ATMEGA32U4 16MHz, 2.50KB RAM, 28KB Flash
DEBUG: Current (simavr) On-board (simavr)
PACKAGES:
 - framework-arduino-avr @ 5.1.0
 - tool-avrdude @ 1.60300.200527 (6.3.0)
 - toolchain-atmelavr @ 1.70300.191015 (7.3.0)
LDF: Library Dependency Finder -> https://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
Found 6 compatible libraries
Scanning dependencies...
Dependency Graph
|-- Unity @ 2.5.2 (License: MIT, Path: /Users/quentinhamel/Documents/PlatformIO/Projects/UnitTEst/.pio/libdeps/leonardo/Unity)
Building in test mode
avr-g++ -o .pio/build/leonardo/firmware.elf -mmcu=atmega32u4 -Os -Wl,--gc-sections -flto -fuse-linker-plugin .pio/build/leonardo/unity_config_build/unity_config.cpp.o .pio/build/leonardo/test/test_dumb/dumb.cpp.o -L.pio/build/leonardo -Wl,--start-group .pio/build/leonardo/libd14/libUnity.a .pio/build/leonardo/libFrameworkArduinoVariant.a .pio/build/leonardo/libFrameworkArduino.a -lm -Wl,--end-group
/var/folders/hh/9y21_8rs2qz67ww_s7bscvb00000gn/T//ccyamzkz.ltrans0.ltrans.o: In function `test_class()':
<artificial>:(.text+0x902): undefined reference to `Sum::sum(int, int)'
collect2: error: ld returned 1 exit status
*** [.pio/build/leonardo/firmware.elf] Error 1
Uploading stage has failed, see errors above. Use `pio test -vvv` option to enable verbose output.
For Arduino
    */
}

int runUnityTests(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_static);
    // RUN_TEST(test_static_wrong);
    RUN_TEST(test_class);

    return UNITY_END();
}

int main()
{
    runUnityTests();
    return 0;
}
