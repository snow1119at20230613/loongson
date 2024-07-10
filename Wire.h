#ifndef Wire_h
#define Wire_h

#include <inttypes.h>
#include <Stream.h>
#include <Arduino.h>

class TwoWire : public Stream {
  public:
    TwoWire();
    void begin();
    void begin(uint8_t);
    void begin(int);
    void end();
    void setClock(uint32_t);
    
    size_t requestFrom(uint8_t address, size_t size, bool stop);
    size_t requestFrom(uint8_t address, size_t size);
    size_t requestFrom(int address, int size);
    virtual size_t write(uint8_t data);
    virtual int available();
    virtual int read();
    virtual int peek();
    virtual void flush();

    inline size_t write(const uint8_t *data, size_t size) { return Stream::write(data, size); }
    inline size_t write(const char *str) { return Stream::write(str); }

  private:
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

    static uint8_t transmitting;
    static uint8_t lastStop;
};

extern TwoWire Wire; // Pre-instantiated I2C bus

#endif
