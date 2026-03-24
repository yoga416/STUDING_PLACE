# STM32F103C8T6 Keil 点灯工程

这是一个最小可用的点灯示例，目标板默认按 Blue Pill（LED 接 PC13，低电平点亮）。

## 目录
- `User/main.c`：点灯主程序（寄存器方式，无 HAL 依赖）

## 在 Keil uVision 中新建工程
1. 打开 Keil -> `Project` -> `New uVision Project...`
2. 选择目录：本目录 `STM32F103C8T6_LED_Keil`
3. 工程名建议：`STM32F103C8T6_LED`
4. 选择器件：`STMicroelectronics -> STM32F103C8Tx`
5. 弹出是否添加启动文件时，点击 `Yes`
6. 在 `Manage Run-Time Environment` 中勾选：
   - `CMSIS -> Core`
   - `Device -> Startup`
7. 在工程树 `Source Group 1` 右键 -> `Add Existing Files to Group...`
   - 添加 `User/main.c`
8. `Options for Target` 检查：
   - `Target` 页：Xtal 可设 `8.0 MHz`（Blue Pill 常见外部晶振）
   - `Output` 页：勾选 `Create HEX File`
   - `Debug` 页：按你的下载器选择 `ST-Link Debugger` 或 `J-Link`
9. 编译并下载运行。

## 预期现象
- 板载 LED（PC13）周期性闪烁。

## 若不亮的排查
1. 确认你的板子 LED 是否确实在 `PC13`。
2. 若 LED 常亮/常灭，可能电平逻辑相反，检查是否为“低电平点亮”。
3. 确认 `STM32F103C8Tx` 器件型号选择正确。
4. 检查下载器连接与 `BOOT0` 状态。
