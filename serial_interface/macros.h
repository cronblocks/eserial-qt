#ifndef MACROS_H
#define MACROS_H

#if _DEBUGGING_MESSAGES == 1
    #define DEBUG_MSG(msg)      {std::cout << msg;}
    #define DEBUG_MSG_LINE(msg) {std::cout << msg << std::endl;}
#else
    #define DEBUG_MSG(msg)
    #define DEBUG_MSG_LINE(msg)
#endif

#endif // MACROS_H
