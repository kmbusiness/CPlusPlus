#ifndef DateTime_h
#define DateTime_h

class DateTime : public Date, public Time
{
public:
    DateTime();
    DateTime(int d, int mo, int y, int h, int mi, int s);
    
    void printDateTime();
};

#endif /* DateTime_h */
