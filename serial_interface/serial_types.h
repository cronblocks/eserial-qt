#ifndef SERIAL_TYPES_H
#define SERIAL_TYPES_H

enum class BaudRate {
    _300     = 300,
    _600     = 600,
    _1200    = 1200,
    _1800    = 1800,
    _2400    = 2400,
    _4800    = 4800,
    _7200    = 7200,
    _9600    = 9600,
    _14400   = 14400,
    _19200   = 19200,
    _28800   = 28800,
    _38400   = 38400,
    _57600   = 57600,
    _115200  = 115200,
    _230400  = 230400,
    _460800  = 460800,
    _921600  = 921600,
    _1000000 = 1000000,
    _2000000 = 2000000,
};

enum class DataBits {
    _5 = 5,
    _6 = 6,
    _7 = 7,
    _8 = 8,
};

enum class Parity {
    None,
    Even,
    Odd,
};

enum class StopBits {
    One,
    OnePtFive,
    Two,
};

enum class LineEnding {
    None,
    CR,
    LF,
    CRLF,
};

#endif // SERIAL_TYPES_H
