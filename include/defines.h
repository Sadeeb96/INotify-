#include "common.h"

#define EVENT_SIZE (sizeof(inotify_event))
#define BUFFER_LEN (1024 * (EVENT_SIZE + 16))
