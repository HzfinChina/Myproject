import time

class Clock:
    def __init__(self, hour:int=0, minute:int =0, second:int=0):
        self.hour = hour;
        self.minute = minute;
        self.second = second;
    def run(self):
        self.second += 1
        if self.second == 60:
            self.minute += 1
            if self.minute == 60:
                self.hour += 1
                if self.hour == 24:
                    self.hour = 0
    def show(self):
        while 1:
            time.sleep(1)
            self.run()
            print(f"\r{self.hour}:{self.minute}:{self.second}",end="")

clock = Clock(hour = 3, minute = 1,second = 55)
print(clock)
