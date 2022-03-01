## Assembly

> Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/c++/4.2.1
> Apple clang version 12.0.0 (clang-1200.0.32.29)
> Target: **x86_64-apple-darwin19.6.0**
> Thread model: posix
> InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin

##### Example

A **constant** that can be produced by rotating an 8-bitvalue by any even number of bits within a 32-bit word.

**Example 1**

```assembly
		MOV		R0,	#0x100
		LDR		R1,	=0x1234
		STR		R1,	[R0]
		STR		R1,	[R0,	#4]
```

**Example 2**

```assembly
		LDR		R0,	=0x0010
		LDR		R1,	=0x0001
		MOV		R2,	#0x0200
		CMP		R0,	R1
		;<=
		STRLE	R1,	[R2]
		;>
		STRGT	R0,	[R2]
```

**Example 3**

```assembly
		MOV		R0,	#0x0200
		MOV		R1,	#0x10
		MOV		R2,	#0x28
		STR		R2,	[R0]
		STR		R2,	[R0,	#4]
		STR		R2,	[R0,	#8]	!
		STR		R2,	[R0,	R1]
		;R0		NOT CHANGED
		STR		R2,	[R0,	R1,	LSL	#4]
		;R1		CHANGED
		STR		R2,	[R0],	+R1,	LSL	#3
```

**Example 3**

```assembly
		MOV		R0,	#0x0200
		MOV		R1,	#0x01
		MOV		R2,	#0x02
		MOV		R3	,	#0x04
		;R1:[R0], R2:[R0, #4], R3:[R0, #8]
		STMIA	R0,	{R1-R3}
		;R1:[R0, #4], R2:[R0, #8], R3:[R0, #12]
		STMIB	R0,	{R1-R3}
```

**Example 3**

```assembly
		MOV		R0,	#0x0200
		MOV		R1,	#0x01
		MOV		R2,	#0x02
		MOV		R3,	#0x04
		;R3:0x200 R2:0x1FC R1:0x1F8
		STMDA	R0,	{R1-R3}
```

**Example 4**

```assembly
		MOV		SP,	#0x2000
		MOV		R1,	#0x01
		MOV		R2,	#0x02
		MOV		R3	,	#0x04
		;(PUSH:Sub-->Store)R3:0x1FFC
		STMFD	SP!,	{R1-R3}
		MOV		R1,	#0
		MOV		R2,	#0
		MOV		R3,	#0
		;(PULL:LOAD-->Add)SP:)0x2000
		LDMFD	SP!,	{R1-R3}
```

**Example 5**

```assembly
		MOV		R1,	#0x01
		MOV		R2,	#0x02
		ADD		R0,	R1,	R2
		ADD		R0,	R1,	#0x12
		SUB		R3,	R0,	R2
```

**AND**

```assembly
		MOV		R0,	#0xFFFFFFFF
		MOV		R1,	#0x02
		AND		R0,	R0,	R1
```

**~**

```assembly
		MOV		R0,	#0xFFFFFFFF
		MOV		R1,	#0x02
		BIC		R0,	R0,	R1
```

**OR**

```assembly
		MOV		R0,	#0x01
		MOV		R1,	#0xB0
		ORR		R2,	R0,	R1
```

###### CPSR

CPSR Status Bits

##### S3C2440 LED Blinker

```assembly
.text
.global _start

_start:
    LDR R0,=0x56000050
    MOV R1,#0x00000100
    STR R1,[R0]
    LDR R0,=0X56000054
    MOV R1,#0X00000000
    STR R1,[R0]
loop:
    B   loop
```

Makefile

```makefile
led.bin : led.S
	arm-linux-gcc -g -c -o led.o led.S
	arm-linux-ld -Ttext 0x0000000 -g led.o -o led.elf
	arm-linux-objcopy -O binary -S led.elf led.bin
	arm-linux-objdump -D led.elf > led.dis
clean:
	rm -f   led.bin led.elf led.dis *.o
```

