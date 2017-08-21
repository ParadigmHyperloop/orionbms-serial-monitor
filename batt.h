int initUART(int mgrnum, char *uartnum);
void closeUART(int fd);
int configUART(UART u, int property, char *value);
int txUART(int uart, unsigned char data);
unsigned char rxUART(int uart);
int strUART(int uart, char *buf);
