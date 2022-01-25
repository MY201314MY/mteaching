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

```
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

