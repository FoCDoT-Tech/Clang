#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
void demonstrate_basic_time_functions(void);
void demonstrate_time_conversion(void);
void demonstrate_time_formatting(void);
void demonstrate_time_calculations(void);
void demonstrate_performance_timing(void);
void demonstrate_practical_applications(void);

int main(void) {
    printf("=== Time Functions Demo ===\n\n");
    
    demonstrate_basic_time_functions();
    demonstrate_time_conversion();
    demonstrate_time_formatting();
    demonstrate_time_calculations();
    demonstrate_performance_timing();
    demonstrate_practical_applications();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_time_functions(void) {
    printf("1. BASIC TIME FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Get current time
    time_t current_time = time(NULL);
    printf("Current time (time_t): %ld\n", (long)current_time);
    
    // Convert to string representation
    char *time_string = ctime(&current_time);
    printf("Current time string: %s", time_string);  // ctime includes newline
    
    // Get processor time
    clock_t start_clock = clock();
    printf("Processor time (clock_t): %ld\n", (long)start_clock);
    printf("CLOCKS_PER_SEC: %ld\n", (long)CLOCKS_PER_SEC);
    
    // Calculate seconds since program start
    double seconds = (double)start_clock / CLOCKS_PER_SEC;
    printf("Seconds since program start: %.6f\n", seconds);
    
    // Demonstrate time(NULL) vs time(&variable)
    time_t time1, time2;
    time1 = time(NULL);
    time(&time2);
    printf("time(NULL): %ld, time(&var): %ld (difference: %ld)\n", 
           (long)time1, (long)time2, (long)(time2 - time1));
    
    printf("\n");
}

void demonstrate_time_conversion(void) {
    printf("2. TIME CONVERSION\n");
    printf("----------------------------------------\n");
    
    time_t current_time = time(NULL);
    
    // Convert to local time structure
    struct tm *local_tm = localtime(&current_time);
    printf("Local time structure:\n");
    printf("  Year: %d (tm_year + 1900)\n", local_tm->tm_year + 1900);
    printf("  Month: %d (0-11, so %d)\n", local_tm->tm_mon, local_tm->tm_mon + 1);
    printf("  Day: %d\n", local_tm->tm_mday);
    printf("  Hour: %d\n", local_tm->tm_hour);
    printf("  Minute: %d\n", local_tm->tm_min);
    printf("  Second: %d\n", local_tm->tm_sec);
    printf("  Day of week: %d (0=Sunday)\n", local_tm->tm_wday);
    printf("  Day of year: %d (0-365)\n", local_tm->tm_yday);
    printf("  Daylight saving: %d\n", local_tm->tm_isdst);
    
    // Convert to GMT/UTC time structure
    struct tm *gmt_tm = gmtime(&current_time);
    printf("\nGMT/UTC time structure:\n");
    printf("  Year: %d\n", gmt_tm->tm_year + 1900);
    printf("  Month: %d\n", gmt_tm->tm_mon + 1);
    printf("  Day: %d\n", gmt_tm->tm_mday);
    printf("  Hour: %d\n", gmt_tm->tm_hour);
    printf("  Minute: %d\n", gmt_tm->tm_min);
    printf("  Second: %d\n", gmt_tm->tm_sec);
    
    // Convert time structure to string
    char *local_string = asctime(local_tm);
    char *gmt_string = asctime(gmt_tm);
    printf("\nTime structure to string:\n");
    printf("Local: %s", local_string);  // asctime includes newline
    printf("GMT:   %s", gmt_string);
    
    // Convert time structure back to time_t
    time_t reconstructed = mktime(local_tm);
    printf("Original time_t: %ld\n", (long)current_time);
    printf("Reconstructed:   %ld\n", (long)reconstructed);
    printf("Difference: %ld seconds\n", (long)(reconstructed - current_time));
    
    printf("\n");
}

void demonstrate_time_formatting(void) {
    printf("3. TIME FORMATTING\n");
    printf("----------------------------------------\n");
    
    time_t current_time = time(NULL);
    struct tm *tm_info = localtime(&current_time);
    char buffer[200];
    
    // Various formatting options
    printf("Custom time formatting with strftime():\n");
    
    // Basic formats
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_info);
    printf("ISO date: %s\n", buffer);
    
    strftime(buffer, sizeof(buffer), "%H:%M:%S", tm_info);
    printf("24-hour time: %s\n", buffer);
    
    strftime(buffer, sizeof(buffer), "%I:%M:%S %p", tm_info);
    printf("12-hour time: %s\n", buffer);
    
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", tm_info);
    printf("Full date: %s\n", buffer);
    
    strftime(buffer, sizeof(buffer), "%a, %b %d, %Y at %I:%M %p", tm_info);
    printf("Formatted: %s\n", buffer);
    
    // International formats
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", tm_info);
    printf("European date: %s\n", buffer);
    
    strftime(buffer, sizeof(buffer), "%m/%d/%Y", tm_info);
    printf("US date: %s\n", buffer);
    
    // Technical formats
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm_info);
    printf("Filename format: %s\n", buffer);
    
    strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%S", tm_info);
    printf("ISO 8601: %s\n", buffer);
    
    // Week and day information
    strftime(buffer, sizeof(buffer), "Week %U of %Y, day %j", tm_info);
    printf("Week info: %s\n", buffer);
    
    strftime(buffer, sizeof(buffer), "%Z (UTC%z)", tm_info);
    printf("Timezone: %s\n", buffer);
    
    // Custom format
    strftime(buffer, sizeof(buffer), "Today is %A, the %d%s day of %B in the year %Y", tm_info);
    // Add ordinal suffix manually (simplified)
    char *ordinal = "th";
    int day = tm_info->tm_mday;
    if (day == 1 || day == 21 || day == 31) ordinal = "st";
    else if (day == 2 || day == 22) ordinal = "nd";
    else if (day == 3 || day == 23) ordinal = "rd";
    
    printf("Descriptive: ");
    strftime(buffer, sizeof(buffer), "Today is %A, the %d", tm_info);
    printf("%s%s", buffer, ordinal);
    strftime(buffer, sizeof(buffer), " day of %B in the year %Y", tm_info);
    printf("%s\n", buffer);
    
    printf("\n");
}

void demonstrate_time_calculations(void) {
    printf("4. TIME CALCULATIONS\n");
    printf("----------------------------------------\n");
    
    time_t current_time = time(NULL);
    
    // Time differences
    time_t one_hour_ago = current_time - 3600;
    time_t one_day_ago = current_time - (24 * 3600);
    time_t one_week_ago = current_time - (7 * 24 * 3600);
    
    printf("Time differences:\n");
    printf("Current time: %s", ctime(&current_time));
    printf("1 hour ago:   %s", ctime(&one_hour_ago));
    printf("1 day ago:    %s", ctime(&one_day_ago));
    printf("1 week ago:   %s", ctime(&one_week_ago));
    
    // Using difftime
    double diff_seconds = difftime(current_time, one_hour_ago);
    printf("difftime(now, 1h_ago) = %.0f seconds\n", diff_seconds);
    
    diff_seconds = difftime(current_time, one_day_ago);
    printf("difftime(now, 1d_ago) = %.0f seconds (%.1f hours)\n", 
           diff_seconds, diff_seconds / 3600.0);
    
    // Calculate age in days
    struct tm birthday = {0};
    birthday.tm_year = 2000 - 1900;  // Year 2000
    birthday.tm_mon = 0;             // January
    birthday.tm_mday = 1;            // 1st
    birthday.tm_hour = 0;
    birthday.tm_min = 0;
    birthday.tm_sec = 0;
    birthday.tm_isdst = -1;          // Let system determine DST
    
    time_t birthday_time = mktime(&birthday);
    if (birthday_time != -1) {
        double age_seconds = difftime(current_time, birthday_time);
        double age_days = age_seconds / (24 * 3600);
        double age_years = age_days / 365.25;
        
        printf("\nAge calculation (from Jan 1, 2000):\n");
        printf("Days: %.1f\n", age_days);
        printf("Years: %.2f\n", age_years);
    }
    
    // Calculate next occurrence of a specific time
    struct tm *current_tm = localtime(&current_time);
    struct tm next_midnight = *current_tm;
    next_midnight.tm_hour = 0;
    next_midnight.tm_min = 0;
    next_midnight.tm_sec = 0;
    next_midnight.tm_mday += 1;  // Next day
    
    time_t midnight_time = mktime(&next_midnight);
    double seconds_to_midnight = difftime(midnight_time, current_time);
    
    printf("\nTime until next midnight: %.0f seconds (%.1f hours)\n",
           seconds_to_midnight, seconds_to_midnight / 3600.0);
    
    printf("\n");
}

void demonstrate_performance_timing(void) {
    printf("5. PERFORMANCE TIMING\n");
    printf("----------------------------------------\n");
    
    // Time a simple operation
    clock_t start = clock();
    
    // Simulate some work
    volatile long sum = 0;
    for (long i = 0; i < 1000000; i++) {
        sum += i;
    }
    
    clock_t end = clock();
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Performance measurement:\n");
    printf("Operation: Sum of numbers 0 to 999,999\n");
    printf("Result: %ld\n", sum);
    printf("CPU time: %.6f seconds\n", cpu_time);
    printf("Clock ticks: %ld\n", (long)(end - start));
    
    // Time multiple operations
    printf("\nTiming different operations:\n");
    
    // String operations
    start = clock();
    char test_string[1000];
    for (int i = 0; i < 10000; i++) {
        sprintf(test_string, "Test string number %d", i);
    }
    end = clock();
    printf("10,000 sprintf operations: %.6f seconds\n", 
           ((double)(end - start)) / CLOCKS_PER_SEC);
    
    // Memory operations
    start = clock();
    char *buffer = malloc(1000000);
    if (buffer) {
        memset(buffer, 'A', 1000000);
        free(buffer);
    }
    end = clock();
    printf("1MB memory allocation/set/free: %.6f seconds\n", 
           ((double)(end - start)) / CLOCKS_PER_SEC);
    
    // Wall clock time vs CPU time
    time_t wall_start = time(NULL);
    start = clock();
    
    // Simulate mixed CPU and I/O work
    for (int i = 0; i < 100000; i++) {
        volatile int x = i * i;  // CPU work
        (void)x;  // Suppress unused variable warning
    }
    
    end = clock();
    time_t wall_end = time(NULL);
    
    printf("\nWall clock vs CPU time:\n");
    printf("Wall clock time: %.0f seconds\n", difftime(wall_end, wall_start));
    printf("CPU time: %.6f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("6. PRACTICAL APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    // Log timestamp generation
    time_t current_time = time(NULL);
    struct tm *tm_info = localtime(&current_time);
    char timestamp[100];
    
    strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", tm_info);
    printf("Log timestamp: %s Application started\n", timestamp);
    
    // Filename with timestamp
    char filename[200];
    strftime(filename, sizeof(filename), "backup_%Y%m%d_%H%M%S.tar.gz", tm_info);
    printf("Backup filename: %s\n", filename);
    
    // Calculate business days
    printf("\nBusiness day calculation:\n");
    time_t start_date = current_time;
    int business_days = 0;
    int total_days = 0;
    
    for (int i = 0; i < 14; i++) {  // Check next 14 days
        time_t check_date = start_date + (i * 24 * 3600);
        struct tm *check_tm = localtime(&check_date);
        
        total_days++;
        
        // Monday = 1, ..., Friday = 5, Saturday = 6, Sunday = 0
        if (check_tm->tm_wday >= 1 && check_tm->tm_wday <= 5) {
            business_days++;
        }
        
        if (i < 7) {  // Show first week
            char day_str[50];
            strftime(day_str, sizeof(day_str), "%A, %b %d", check_tm);
            printf("  %s %s\n", day_str, 
                   (check_tm->tm_wday >= 1 && check_tm->tm_wday <= 5) ? "(business day)" : "(weekend)");
        }
    }
    
    printf("In next %d days: %d business days, %d weekend days\n", 
           total_days, business_days, total_days - business_days);
    
    // Time zone demonstration (simplified)
    printf("\nTime representation:\n");
    printf("Local time: %s", ctime(&current_time));
    
    struct tm *gmt_tm = gmtime(&current_time);
    printf("UTC time:   %s", asctime(gmt_tm));
    
    // Calculate time difference (rough timezone offset)
    struct tm *local_tm = localtime(&current_time);
    int local_hour = local_tm->tm_hour;
    int utc_hour = gmt_tm->tm_hour;
    int timezone_offset = local_hour - utc_hour;
    
    // Handle day boundary crossing
    if (timezone_offset > 12) timezone_offset -= 24;
    if (timezone_offset < -12) timezone_offset += 24;
    
    printf("Timezone offset: %+d hours from UTC\n", timezone_offset);
    
    // Uptime calculation (simulated)
    printf("\nUptime simulation:\n");
    time_t boot_time = current_time - (5 * 24 * 3600 + 3 * 3600 + 45 * 60 + 30);  // 5 days, 3:45:30 ago
    double uptime_seconds = difftime(current_time, boot_time);
    
    int days = (int)(uptime_seconds / (24 * 3600));
    uptime_seconds -= days * 24 * 3600;
    int hours = (int)(uptime_seconds / 3600);
    uptime_seconds -= hours * 3600;
    int minutes = (int)(uptime_seconds / 60);
    int seconds = (int)(uptime_seconds - minutes * 60);
    
    printf("System uptime: %d days, %d hours, %d minutes, %d seconds\n", 
           days, hours, minutes, seconds);
    
    printf("\n");
}
