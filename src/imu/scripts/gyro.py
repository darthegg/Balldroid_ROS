#!/usr/bin/env python

from serial import Serial
import time
import rospy
from balldroid_msgs.msg import Imu

import threading


rospy.init_node('imu_talker', anonymous = True)

pub_usb = rospy.Publisher('/imu_usb', Imu, queue_size=30)
#pub_gpio = rospy.Publisher('/imu_gpio', Imu, queue_size=30)

#Serial Setting
ser_usb = Serial('/dev/ttyUSB0', 115200)
#ser_gpio = Serial('/dev/ttyS0', 115200)


def read_from_port(pub,ser):
#    while not rospy.is_shutdown():
    resp = ser.readline()
    data = resp[1:].split(',')
    try:
        euler_x = float(data[0])
        euler_y = float(data[1])
        euler_z = float(data[2])

        gyro_x = float(data[3])
        gyro_y = float(data[4])
        gyro_z = float(data[5])
       
        accel_x = float(data[6])
        accel_y = float(data[7])
        accel_z = float(data[8])
       
        imu = Imu()
        imu.euler.x = euler_x
        imu.euler.y = euler_y
        imu.euler.z = euler_z

        imu.gyro.x = gyro_x
        imu.gyro.y = gyro_y
        imu.gyro.z = gyro_z

        imu.accel.x = accel_x
        imu.accel.y = accel_y
        imu.accel.z = accel_z

        pub.publish(imu)

    except Exception as ex:
        print ex

try:
    ser_usb.open()
    #ser_gpio.open()

except Exception:
    ser_usb.close()
    #ser_gpio.close()
    ser_usb.open()
    #ser_gpio.open()

# Hz setting
ser_usb.write("<sor10>")
#ser_gpio.write("<sor10>")

# Gyro Output setting
ser_usb.write("<sog1>")
#ser_gpio.write("<sog1>")

# Accel Output setting
ser_usb.write("<soa2>")
#ser_gpio.write("<soa2>")
#thread.start()

#thread.join()
while not rospy.is_shutdown():
    read_from_port(pub_usb,ser_usb)
    #read_from_port(pub_gpio,ser_gpio)

ser_usb.close()
#ser_gpio.close()

