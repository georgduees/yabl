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
