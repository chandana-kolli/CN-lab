import time
import random
bucketSize =512
def bktInput(size,rate):
    if size>bucketSize:
        print("\n Bucket Overflow")
    else:
        time.sleep(1)
        while size>rate:
            print("{} bytes sent".format(rate))
            size -=rate
            time.sleep(1)
        if size >0:
            print(" Last {} bytes sent".format(size))
        print("\n Bucket output successful")

outputRate = int(input("Enter the ouput rate : "))
for i in range(5):
    print(random.randint(0,1000))
    packetSize = random.randint(0,1000)
    print("\n Packet Number : {}  \n Packet Size : {} ".format((i+1),packetSize))
    bktInput(packetSize,outputRate)
