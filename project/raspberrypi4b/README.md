### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(aht30 REQUIRED)
```

### 3. AHT30

#### 3.1 Command Instruction

1. Show aht30 chip and driver information.

   ```shell
   aht30 (-i | --information)
   ```

2. Show aht30 help.

   ```shell
   aht30 (-h | --help)
   ```

3. Show aht30 pin connections of the current board.

   ```shell
   aht30 (-p | --port)
   ```

4. Run aht30 read test, num means test times.

   ```shell
   aht30 (-t read | --test=read) [--times=<num>]
   ```

5. Run aht30 read function, num means test times.

   ```shell
   aht30 (-e read | --example=read) [--times=<num>]
   ```

#### 3.2 Command Example

```shell
./aht30 -i

aht30: chip is ASAIR AHT30.
aht30: manufacturer is ASAIR.
aht30: interface is IIC.
aht30: driver version is 1.0.
aht30: min supply voltage is 2.2V.
aht30: max supply voltage is 5.5V.
aht30: max current is 0.60mA.
aht30: max temperature is 85.0C.
aht30: min temperature is -40.0C.
```

```shell
./aht30 -p

aht30: SCL connected to GPIO3(BCM).
aht30: SDA connected to GPIO2(BCM).
```

```shell
./aht30 -t read --times=3

aht30: chip is ASAIR AHT30.
aht30: manufacturer is ASAIR.
aht30: interface is IIC.
aht30: driver version is 1.0.
aht30: min supply voltage is 2.2V.
aht30: max supply voltage is 5.5V.
aht30: max current is 0.60mA.
aht30: max temperature is 85.0C.
aht30: min temperature is -40.0C.
aht30: start read test.
aht30: temperature: 27.5C.
aht30: humidity: 24%.
aht30: temperature: 27.5C.
aht30: humidity: 24%.
aht30: temperature: 27.5C.
aht30: humidity: 24%.
aht30: finish read test.
```

```shell
./aht30 -e read --times=3

aht30: 1/3.
aht30: temperature is 27.49C.
aht30: humidity is 24%.
aht30: 2/3.
aht30: temperature is 27.49C.
aht30: humidity is 24%.
aht30: 3/3.
aht30: temperature is 27.48C.
aht30: humidity is 25%.
```

```shell
./aht30 -h

Usage:
  aht30 (-i | --information)
  aht30 (-h | --help)
  aht30 (-p | --port)
  aht30 (-t read | --test=read) [--times=<num>]
  aht30 (-e read | --example=read) [--times=<num>]

Options:
  -e <read>, --example=<read>    Run the driver example.
  -h, --help                     Show the help.
  -i, --information              Show the chip information.
  -p, --port                     Display the pin connections of the current board.
  -t <read>, --test=<read>       Run the driver test.
      --times=<num>              Set the running times.([default: 3])
```

