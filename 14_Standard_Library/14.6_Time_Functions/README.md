# 14.6 Time Functions (`time.h`)

Functions for time manipulation, measurement, and formatting.

## Key Functions

### Time Retrieval
- `time()` - Get current time
- `clock()` - Get processor time
- `difftime()` - Calculate time difference

### Time Conversion
- `localtime()` - Convert to local time structure
- `gmtime()` - Convert to GMT/UTC time structure
- `mktime()` - Convert time structure to time_t
- `asctime()` - Convert time structure to string
- `ctime()` - Convert time_t to string

### Time Formatting
- `strftime()` - Format time string with custom patterns

### Time Types
- `time_t` - Time value type
- `clock_t` - Clock value type
- `struct tm` - Time structure with components

## Code Example

**Run:** `make run`

The demo covers time measurement, formatting, calculations, and practical timing applications.
