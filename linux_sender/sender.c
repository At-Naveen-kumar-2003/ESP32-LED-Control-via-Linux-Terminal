#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

#define SERIAL_PORT "/dev/ttyUSB0"
#define BAUDRATE B115200

int main() {
    int fd;
    struct termios options;
    char input[10];

    fd = open(SERIAL_PORT, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        perror("Unable to open serial port");
        return 1;
    }

    sleep(2); // Allow ESP32 reset

    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    tcsetattr(fd, TCSANOW, &options);

    printf("Enter number (1-4) to blink LED, q to quit\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'q')
            break;

        write(fd, input, strlen(input));
    }

    close(fd);
    return 0;
}
