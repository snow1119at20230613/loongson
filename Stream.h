#ifndef Stream_h
#define Stream_h

class Stream {
  public:
    Stream() {}

    // �����ж�ȡһ���ֽ�
    int read() {
      // ��Ҫ����ʵ��
    }

    // ��ȡ����ֽ�ֱ�����õ��ֽ���
    int readBytes(char *buffer, size_t length) {
      // ��Ҫ����ʵ��
    }

    // ��ȡֱ��ָ������ֹ�ַ�
    int readBytesUntil(char terminator, char *buffer, size_t length) {
      // ��Ҫ����ʵ��
    }

    // д��һ���ֽڵ�����
    size_t write(uint8_t data) {
      // ��Ҫ����ʵ��
    }

    // д��һ���ַ���������
    size_t write(const char *str) {
      // ��Ҫ����ʵ��
    }

    // ��������Ƿ��п����ڶ�ȡ������
    int available() {
      // ��Ҫ����ʵ��
    }

    // �ȴ�ֱ�������ݿɶ�
    void flush() {
      // ��Ҫ����ʵ��
    }

    // ������Ƿ�������
    virtual bool connected() {
      // ��Ҫ����ʵ��
    }

    // Peek at the next byte in the stream without consuming it
    int peek() {
      // ��Ҫ����ʵ��
    }

  protected:
    // �������ܵĳ�Ա�����ͺ���
};

extern Stream Serial; // Ԥʵ�����Ĵ���ͨ�Ŷ���

#endif
