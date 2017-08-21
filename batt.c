int initUART(int mgrnum, char *uartnum) {
  // return the int reference to the port
  struct termios old;
  struct termios new;
  int fd;

  fd = open("/dev/ttyO4", O_RDWR | O_NOCTTY);
  if (fd < 0) {
    printf("Port failed to open\n");
    return fd;
  }

  tcgetattr(fd, &old);
  bzero(&new, sizeof(new));

  new.c_cflag = B4800 | CS8 | CLOCAL | CREAD;
  new.c_iflag = IGNPAR | ICRNL;
  new.c_oflag = 0;
  new.c_lflag = 0;

  new.c_cc[VTIME] = 5;
  new.c_cc[VMIN] = 1;

  // clean the line and set the attributes
  tcflush(fd, TCIFLUSH);
  tcsetattr(fd, TCSANOW, &new);

  return fd;
}

void closeUART(int fd) { close(fd); }

int configUART(UART u, int property, char *value) {
  // This is used to set the configuration values
  // for the uart module

  return 0;
}

int txUART(int uart, unsigned char data) {
  // write a single byte

  write(uart, &data, 1);
  tcdrain(uart);

  return 0;
}

unsigned char rxUART(int uart) {
  // read in a single byte
  unsigned char data;

  read(uart, &data, 1);
  return data;
}

int strUART(int uart, char *buf) {
  size_t i;
  for (i = 0; i < strlen(buf); i++)
    txUART(uart, buf[i]);

  return 0;
}

int get_current(){

}

void main() {

};
