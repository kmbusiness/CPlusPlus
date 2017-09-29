#ifndef Time_h
#define Time_h

class Time
{
protected:
    int hour, min, sec;
public:
    Time(int h = 0, int m = 0, int s = 0);
    void printTime();
    
};

#endif /* Time_h */
