# Blinky project template

The **Blinky Button and LED** project can be used to verify the basic tool setup.

It is compliant to the
[Cortex Microcontroller Software Interface Standard (CMSIS)](https://arm-software.github.io/CMSIS_5/General/html/index.html)
and uses the [CMSIS-RTOS v2 API](https://arm-software.github.io/CMSIS_5/RTOS2/html/index.html) for RTOS functionality.
The CMSIS-RTOS v2 API is supported by various real-time operating systems, for example
[Keil RTX5](https://arm-software.github.io/CMSIS_5/RTOS2/html/rtx5_impl.html) or
[FreeRTOS](https://github.com/ARM-software/CMSIS-FreeRTOS).

## Operation

- At start the `vioLED0` blinks in 1 sec interval.
- The `vioBUTTON0` changes the blink frequency.

The board hardware mapping of `vioLED0` and `vioBUTTON0` depends on the 
configuration of the
[CMSIS-Driver VIO](https://arm-software.github.io/CMSIS_5/Driver/html/group__vio__interface__gr.html).

### Keil RTX5 real-time operating system

The real-time operating system [Keil RTX5](https://arm-software.github.io/CMSIS-RTX/latest/index.html) implements
the resource management.

It is configured with the following settings:

- [Global Dynamic Memory size](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html#systemConfig_glob_mem):
  2048 bytes
- [Default Thread Stack size](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html#threadConfig): 512 bytes
- [Stack Overflow Checking](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html#threadConfig_ovfcheck) and
  [Stack Usage Watermark](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html#threadConfig_watermark)
  enabled

Refer to [Configure RTX v5](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html) for a detailed
description of all configuration options.

## How to use the template

1. Open VS Code with the
   [Keil Studio Pack extension](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack) installed.
2. Open the **CMSIS** view and select "Create a solution".
3. Select your development board and device, click **Select**.
4. From **Templates, Reference Applications, and Examples** select the ""Blinky Button and LED" template.
5. Select an appropriate **Solution Base Folder** and click **Create**. The CMSIS solution is opened.
6. Select a GPIO or peripheral driver library component for your board/device, if available.
7. Open the `vio_XYZ.c` file in VS Code.
8. In GitHub Copilot, use the following prompt to get the custom VIO file generated:

   ```txt
   Can you help me creating the CMSIS-Driver VIO file for this board? The LED is connected to ABC and the button is
   connected to DEF on the microcontroller. Can you use functions from the GPIO/Peripheral Driver Library?
   ```

9. Copilot should generate the required file. Then, continue
   [building](https://mdk-packs.github.io/vscode-cmsis-solution-docs/create_app.html#build) and
   [running](https://mdk-packs.github.io/vscode-cmsis-solution-docs/create_app.html#load-and-run) the project.
