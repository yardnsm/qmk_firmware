#pragma once

#undef MASTER_LEFT
#undef EE_HANDS
#undef MASTER_RIGHT

#define SERIAL_USART_TX_PIN GP1

#ifdef POINTING_DEVICE_CONFIGURATION_TRACKPOINT_TRACKBALL
    #define MASTER_LEFT
    #define POINTING_DEVICE_ROTATION_90_RIGHT
#elif POINTING_DEVICE_CONFIGURATION_TRACKBALL_TRACKPOINT
    #define MASTER_RIGHT
    #define POINTING_DEVICE_ROTATION_270
#elif POINTING_DEVICE_CONFIGURATION_TRACKPOINT_CIRQUE35
    #define MASTER_LEFT
#elif POINTING_DEVICE_CONFIGURATION_CIRQUE35_TRACKPOINT
    #define MASTER_RIGHT
#elif POINTING_DEVICE_CONFIGURATION_PIMORONI_CIRQUE35
    #define MASTER_RIGHT
    // The pimoroni needs frequest updates, set a value so the Cirque configs don't set it to 10ms.
    #define POINTING_DEVICE_TASK_THROTTLE_MS 1
    // A pimoroni on the left side can only go in this orientation.
    #define POINTING_DEVICE_ROTATION_270
#elif POINTING_DEVICE_CONFIGURATION_CIRQUE35_PIMORONI
    #define MASTER_RIGHT
    // The pimoroni needs frequest updates, set a value so the Cirque configs don't set it to 10ms.
    #define POINTING_DEVICE_TASK_THROTTLE_MS 1
    // Determine right side rotation based on POINTING_DEVICE_POSITION flag.
    #if POINTING_DEVICE_POSITION_THUMB_OUTER
      #define POINTING_DEVICE_ROTATION_270_RIGHT
    #elif defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_THUMB_INNER)
    #else
       #define POINTING_DEVICE_ROTATION_90_RIGHT
    #endif
#elif POINTING_DEVICE_CONFIGURATION_PIMORONI_PIMORONI
    #define MASTER_RIGHT
    // A pimoroni on the left side can only go in this orientation.
    #define POINTING_DEVICE_ROTATION_270
    // Determine right side rotation based on POINTING_DEVICE_POSITION flag.
    #if POINTING_DEVICE_POSITION_THUMB_OUTER
      #define POINTING_DEVICE_ROTATION_270_RIGHT
    #elif defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_THUMB_INNER)
    #else
       #define POINTING_DEVICE_ROTATION_90_RIGHT
    #endif
#elif POINTING_DEVICE_CONFIGURATION_PIMORONI
    #ifdef POINTING_DEVICE_POSITION_LEFT
      #define POINTING_DEVICE_ROTATION_270
    #elif POINTING_DEVICE_POSITION_RIGHT
       #define POINTING_DEVICE_ROTATION_90
    #elif POINTING_DEVICE_POSITION_THUMB_OUTER
      #define POINTING_DEVICE_ROTATION_270
    #elif defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_THUMB_INNER) || defined(POINTING_DEVICE_POSITION_MIDDLE)
    #endif
#else
    #ifdef POINTING_DEVICE_POSITION_LEFT
        #define MASTER_LEFT
    #else
        #define MASTER_RIGHT
    #endif
#endif

// Generic Cirque configuration.
#ifdef POINTING_DEVICE_DRIVER_cirque_pinnacle_i2c
    #define CIRQUE_PINNACLE_DIAMETER_MM 35
    // Tap for left click.
    #define CIRQUE_PINNACLE_TAP_ENABLE
    #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#endif

#ifdef POINTING_DEVICE_DRIVER_ps2
    // The default streaming mode is flaky and doesn't always work. This setting doesn't seem to affect performance.
    #define PS2_MOUSE_USE_REMOTE_MODE

    // Serial uses PIO0, change PS2 to PIO1.
    #define PS2_PIO_USE_PIO1

    #define PS2_MOUSE_INVERT_X
    #define PS2_MOUSE_INVERT_Y

    #define PS2_DATA_PIN    GP2
    #define PS2_CLOCK_PIN   GP3

    // Start faster when keyboard resets.
    #define PS2_MOUSE_INIT_DELAY 500
#endif

#ifdef OLED_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
#endif

#undef MASTER_LEFT
#undef MASTER_RIGHT

#define MASTER_LEFT
#define OLED_FLIP
