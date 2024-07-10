#ifndef Stream_h
#define Stream_h

class Stream {
  public:
    Stream() {}

    // 从流中读取一个字节
    int read() {
      // 需要具体实现
    }

    // 读取多个字节直到可用的字节数
    int readBytes(char *buffer, size_t length) {
      // 需要具体实现
    }

    // 读取直到指定的终止字符
    int readBytesUntil(char terminator, char *buffer, size_t length) {
      // 需要具体实现
    }

    // 写入一个字节到流中
    size_t write(uint8_t data) {
      // 需要具体实现
    }

    // 写入一个字符串到流中
    size_t write(const char *str) {
      // 需要具体实现
    }

    // 检查流中是否有可用于读取的数据
    int available() {
      // 需要具体实现
    }

    // 等待直到有数据可读
    void flush() {
      // 需要具体实现
    }

    // 检查流是否已连接
    virtual bool connected() {
      // 需要具体实现
    }

    // Peek at the next byte in the stream without consuming it
    int peek() {
      // 需要具体实现
    }

  protected:
    // 其他可能的成员变量和函数
};

extern Stream Serial; // 预实例化的串行通信对象

#endif
