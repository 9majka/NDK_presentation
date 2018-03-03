#ifndef PRESENTATION_LOGGER_H
#define PRESENTATION_LOGGER_H

#include <android/log.h>
#define APPNAME "NDK_DEMO"

#define DEMO_LOG(...) __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, __VA_ARGS__);

#endif //PRESENTATION_LOGGER_H
