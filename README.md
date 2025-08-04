Control ESP32 board from your Android phone, using the RoboRemo app.

RoboRemo can connect via Bluetooth (RFCOMM / BLE), WiFi (TCP / UDP / TCP Server), USB Serial.

In this example, the ESP32 creates a WiFi Access Point (AP) and starts a TCP Server.

Android Phone is connected to the WiFi AP createc by the ESP32.

RoboRemo connects (as TCP client) to the TCP Server that is running on the ESP32.

Bi-directional real-time communication is achieved.

Project can be extended further to build an IoT device, robot, etc. based on ESP32 boards.
