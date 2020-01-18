# YABL - Yet Another Blinking LED

YABL is a small Arduino-Tool which converts a Digispark and a WS2812 LED/Neopixel to a Serial Controllable LED.

## Contents

This repository contains the following contents:

- Arduino Code
- Build Example/Layout
- Golang Example
- Bash-Example
- Installation Steps

## The Build

The Hardware used in this buildis a Digispark ATTINY85 Board, a WS2812B-LED / Neopixel and Some jumper Wire.
To build this it takes approx >10 Minutes.

As this can be quite beginner Friendly i documented those steps.

![alt text][layout]

## Arduino Code Commentary

```c
Basically the Code reads in a string of the Format '#AABBCC'.
If the format is met, the Colors R,G,B are written to the Neopixel LED.
Not much magic.
```

## Installation

The system should be Plug and Play.
Depending on the OS it might be necessary to give the user the rights to access the Serial-Port beeing opened and grant access to the device.

Windows users might need to install drivers.
Haven't tested it with windows yet.

### Linux

Make sure your user has the correct rights to Access the Serial Device or is part of the Dialout Group.

### Windows

Make sure the Digispark USB-Driver is installed.

## Usage

Bash Example:

```bash
echo '#FF0000' > /dev/ttyACM0
```

Golang Example:

```go
package main

import (
	"fmt"
	"log"
	"time"

	"github.com/jacobsa/go-serial/serial"
)

func main() {

	// Set up options.
	options := serial.OpenOptions{
		PortName:        "/dev/ttyACM0",
		BaudRate:        9600,
		DataBits:        8,
		StopBits:        1,
		MinimumReadSize: 4,
	}
	//declare color array
	colors := []string{"#FF0000", "#00FF00", "#0000FF"}
	// Open the port.
	port, err := serial.Open(options)
	if err != nil {
		log.Fatalf("serial.Open: %v", err)
	}

	// Make sure to close it later.
	defer port.Close()
	// send colors to serial port
	for _, color := range colors {
		_, err := port.Write([]byte(color))
		if err != nil {
			log.Fatalf("port.Write: %v", err)
		}
		fmt.Println("showcolor: " + color)

		time.Sleep(1 * time.Second)
	}

}
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)

[layout]: ./Layout/YABL_Layout.svg "YABL_Layout"
