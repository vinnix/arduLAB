#!/bin/env python


#[NEW] Device 88:C2:55:32:FD:57 HMSoft
#[NEW] Primary Service
# /org/bluez/hci0/dev_88_C2_55_32_FD_57/service0010
# 0000ffe0-0000-1000-8000-00805f9b34fb
# Unknown
#


import bluepy.btle as btle
 
p = btle.Peripheral("88:C2:55:32:FD:57")
s = p.getServiceByUUID("0000ffe0-0000-1000-8000-00805f9b34fb")
c = s.getCharacteristics()[0]
 
#c.write(bytes("Hello world\n", "utf-8"))
#c.write(bytes("Test"))
#c.write(bytes("Test"))
#c.write(bytes("gr"))
c.write(bytes("GR"))
#c.write(bytes("s"))
p.disconnect()
