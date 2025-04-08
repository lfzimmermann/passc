// DEFINES
#define KEY_ESC 27

// MACROS
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void setup();
void quit();

void free_items(ITEM** items, const size_t size);
