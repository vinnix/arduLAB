#!/bin/env python


#[NEW] Device 88:C2:55:32:FD:57 HMSoft


import bluepy.btle as btle
 
class ReadDelegate(btle.DefaultDelegate):
    def handleNotification(self, cHandle, data):
        print(data.decode("utf-8"))
 
p = btle.Peripheral("88:C2:55:32:FD:57")
p.withDelegate(ReadDelegate())
 
while True:
    while p.waitForNotifications(1):
        pass
 
p.disconnect()
 
