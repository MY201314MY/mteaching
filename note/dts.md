##### SPI

###### real spi

```
&spi5 {
	cs-gpios = <&gpiof 6 0>;
    status = "okay";
	spidev@0{
        compatible = "spidev";
        reg = <0>;
        spi-max-frequency = <100000000>;
    };
};
```

###### mcp2515

```shell
&spi5 {
	cs-gpios = <&gpiof 6 0>;
    status = "okay";
		
    mcp2515@0{
    	compatible = "microchip,mcp2515";
        reg = <0>;
        spi-max-frequency = <100000000>;
	};
};
```

##### PWM

```
/sys/class/pwm
```

```sh
/*ACT*/
pwm1_pins_a: pwm1-0 {
	pins {
		pinmux = <STM32_PINMUX('E', 9, AF1)>, /* TIM1_CH1 */
				 <STM32_PINMUX('E', 11, AF1)>, /* TIM1_CH2 */
				 <STM32_PINMUX('E', 14, AF1)>; /* TIM1_CH4 */
		bias-pull-down;
		drive-push-pull;
		slew-rate = <0>;
		};
	};
/*NO ACT*/
pwm1_pins_a: pwm1-0 {
	pins {
    	pinmux = <STM32_PINMUX('E', 9, AF1)>,  /* TIM1_CH1 */
				 <STM32_PINMUX('D', 15, AF1)>,  /* TIM1_CH4 */
        bias-pull-down;
		drive-push-pull;
		slew-rate = <0>;
		};
	};
```

