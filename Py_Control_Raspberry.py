import socket
import json
from tabnanny import check
import serial

def connectSocket():
    global receptor
    receptor = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    receptor.bind(("0.0.0.0", 5000))
    receptor.settimeout(1)
    print("Socket established")

def readInputs():
    data, address = receptor.recvfrom(2048)
    json_message = data.decode("utf-8")
    message = json.loads(json_message)
    return message

def finishProgram():
    receptor.close()

#return true if port exists and false if it doesn't
def check_port(port):
    try:
        #try to connect to port (if so, return true)
        with serial.Serial(port, 9600, timeout=1, exclusive=True):
            return True
    except serial.SerialException:
        #if port doesn't connect, return false
        return False
            
connectSocket()
try:
    while True:
        try:
            inputs = readInputs()
        except socket.timeout:
            print("Stopped receiving data")
            inputs = {
                "left_x": 0,
                "left_y": 0,
                "right_x": 0,
                "right_y": 0,
                "a_button": 0,
                "b_button": 0,
                "x_button": 0,
                "y_button": 0,
                "left_button": 0,
                "right_button": 0
            }
        
        active_port = "/dev/ttyACM0"
        ser = serial.Serial(active_port, 9600, timeout = 1)
        print ("connected to port \"/dev/ttyACM0\"")
        
        #inputs to json callsed json_inputs
        json_inputs = json.dumps(inputs)

        #json_inputs to utf-8 called utf-8_bytes
        utf8_bytes = json_inputs.encode("utf-8")

        #write utf-8_bytes to ser (connected arduino)
        ser.write(utf8_bytes)

        print(inputs)
except KeyboardInterrupt:
    finishProgram()

