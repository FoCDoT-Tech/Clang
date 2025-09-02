#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Tagged union example
enum DataType {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
};

struct TaggedUnion {
    enum DataType type;
    union {
        int int_val;
        float float_val;
        char string_val[50];
    } data;
};

// Function prototypes
void demonstrate_basic_unions(void);
void demonstrate_union_vs_structure(void);
void demonstrate_memory_sharing(void);
void demonstrate_tagged_unions(void);
void demonstrate_practical_applications(void);
void demonstrate_union_safety(void);
void print_tagged_value(struct TaggedUnion *val);

// Union definitions
union BasicData {
    int i;
    float f;
    char c;
};

union LargeData {
    int i;
    float f;
    char str[20];
    double d;
};

// Structure for comparison
struct StructData {
    int i;
    float f;
    char str[20];
    double d;
};

// Practical union examples
union FloatBytes {
    float f;
    unsigned char bytes[4];
};

union Converter {
    int as_int;
    float as_float;
    unsigned int as_uint;
    char as_bytes[4];
};

int main(void) {
    printf("=== Unions Demo ===\n\n");
    
    demonstrate_basic_unions();
    demonstrate_union_vs_structure();
    demonstrate_memory_sharing();
    demonstrate_tagged_unions();
    demonstrate_practical_applications();
    demonstrate_union_safety();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_unions(void) {
    printf("1. BASIC UNION USAGE\n");
    printf("----------------------------------------\n");
    
    union BasicData data;
    
    printf("Union declaration and basic usage:\n");
    printf("  Union address: %p\n", (void*)&data);
    printf("  Member addresses:\n");
    printf("    data.i: %p\n", (void*)&data.i);
    printf("    data.f: %p\n", (void*)&data.f);
    printf("    data.c: %p\n", (void*)&data.c);
    printf("  All members share the same address!\n");
    
    // Store different values
    printf("\nStoring different values:\n");
    
    data.i = 42;
    printf("  After data.i = 42:\n");
    printf("    data.i = %d\n", data.i);
    printf("    data.f = %f (garbage)\n", data.f);
    printf("    data.c = %c (garbage)\n", data.c);
    
    data.f = 3.14159f;
    printf("  After data.f = 3.14159:\n");
    printf("    data.i = %d (garbage)\n", data.i);
    printf("    data.f = %f\n", data.f);
    printf("    data.c = %c (garbage)\n", data.c);
    
    data.c = 'A';
    printf("  After data.c = 'A':\n");
    printf("    data.i = %d (garbage)\n", data.i);
    printf("    data.f = %f (garbage)\n", data.f);
    printf("    data.c = %c\n", data.c);
    
    printf("\nUnion size: %zu bytes (size of largest member)\n", sizeof(union BasicData));
    printf("Individual member sizes:\n");
    printf("  int: %zu bytes\n", sizeof(int));
    printf("  float: %zu bytes\n", sizeof(float));
    printf("  char: %zu bytes\n", sizeof(char));
    printf("\n");
}

void demonstrate_union_vs_structure(void) {
    printf("2. UNION VS STRUCTURE COMPARISON\n");
    printf("----------------------------------------\n");
    
    union LargeData union_data;
    struct StructData struct_data;
    
    printf("Memory usage comparison:\n");
    printf("  Union size: %zu bytes\n", sizeof(union LargeData));
    printf("  Structure size: %zu bytes\n", sizeof(struct StructData));
    printf("  Memory saved by union: %zu bytes\n", 
           sizeof(struct StructData) - sizeof(union LargeData));
    
    printf("\nMember sizes:\n");
    printf("  int: %zu bytes\n", sizeof(int));
    printf("  float: %zu bytes\n", sizeof(float));
    printf("  char[20]: %zu bytes\n", sizeof(char[20]));
    printf("  double: %zu bytes\n", sizeof(double));
    
    // Initialize union
    strcpy(union_data.str, "Hello Union!");
    printf("\nUnion with string:\n");
    printf("  union_data.str = \"%s\"\n", union_data.str);
    printf("  union_data.i = %d (shares memory with string)\n", union_data.i);
    printf("  union_data.f = %f (shares memory with string)\n", union_data.f);
    
    // Initialize structure
    struct_data.i = 42;
    struct_data.f = 3.14f;
    strcpy(struct_data.str, "Hello Struct!");
    struct_data.d = 2.718;
    
    printf("\nStructure with all members:\n");
    printf("  struct_data.i = %d\n", struct_data.i);
    printf("  struct_data.f = %f\n", struct_data.f);
    printf("  struct_data.str = \"%s\"\n", struct_data.str);
    printf("  struct_data.d = %f\n", struct_data.d);
    printf("  All members can coexist in structure!\n");
    printf("\n");
}

void demonstrate_memory_sharing(void) {
    printf("3. MEMORY SHARING VISUALIZATION\n");
    printf("----------------------------------------\n");
    
    union Converter conv;
    
    printf("Demonstrating memory sharing with different interpretations:\n");
    
    // Store as integer
    conv.as_int = 0x41414141;  // Hex value
    printf("  Stored as int: 0x%08X (%d)\n", conv.as_int, conv.as_int);
    printf("  Read as float: %f\n", conv.as_float);
    printf("  Read as uint: %u\n", conv.as_uint);
    printf("  Read as bytes: [0x%02X, 0x%02X, 0x%02X, 0x%02X]\n",
           conv.as_bytes[0], conv.as_bytes[1], conv.as_bytes[2], conv.as_bytes[3]);
    
    // Store as float
    conv.as_float = 3.14159f;
    printf("\n  Stored as float: %f\n", conv.as_float);
    printf("  Read as int: %d\n", conv.as_int);
    printf("  Read as uint: %u\n", conv.as_uint);
    printf("  Read as bytes: [0x%02X, 0x%02X, 0x%02X, 0x%02X]\n",
           conv.as_bytes[0], conv.as_bytes[1], conv.as_bytes[2], conv.as_bytes[3]);
    
    // Modify individual bytes
    printf("\n  Modifying individual bytes:\n");
    conv.as_bytes[0] = 0xFF;
    conv.as_bytes[1] = 0x00;
    conv.as_bytes[2] = 0xFF;
    conv.as_bytes[3] = 0x00;
    printf("  After byte modification:\n");
    printf("    as_int: 0x%08X (%d)\n", conv.as_int, conv.as_int);
    printf("    as_float: %f\n", conv.as_float);
    printf("    as_uint: %u\n", conv.as_uint);
    
    printf("\nMemory layout visualization:\n");
    printf("  Union address: %p\n", (void*)&conv);
    printf("  All members point to the same location:\n");
    printf("    as_int:   %p\n", (void*)&conv.as_int);
    printf("    as_float: %p\n", (void*)&conv.as_float);
    printf("    as_uint:  %p\n", (void*)&conv.as_uint);
    printf("    as_bytes: %p\n", (void*)conv.as_bytes);
    printf("\n");
}

void demonstrate_tagged_unions(void) {
    printf("4. TAGGED UNIONS (SAFE USAGE)\n");
    printf("----------------------------------------\n");
    
    printf("Tagged union provides type safety:\n");
    
    // Create array of tagged unions
    struct TaggedUnion values[3];
    
    // Initialize with different types
    values[0].type = TYPE_INT;
    values[0].data.int_val = 42;
    
    values[1].type = TYPE_FLOAT;
    values[1].data.float_val = 3.14159f;
    
    values[2].type = TYPE_STRING;
    strcpy(values[2].data.string_val, "Hello Tagged Union!");
    
    printf("  Array of tagged unions:\n");
    for (int i = 0; i < 3; i++) {
        printf("    values[%d]: ", i);
        switch (values[i].type) {
            case TYPE_INT:
                printf("INT = %d\n", values[i].data.int_val);
                break;
            case TYPE_FLOAT:
                printf("FLOAT = %f\n", values[i].data.float_val);
                break;
            case TYPE_STRING:
                printf("STRING = \"%s\"\n", values[i].data.string_val);
                break;
            default:
                printf("UNKNOWN TYPE\n");
                break;
        }
    }
    
    // Function to safely access tagged union (defined at end of file)
    
    printf("\n  Safe access through functions:\n");
    for (int i = 0; i < 3; i++) {
        print_tagged_value(&values[i]);
    }
    
    // Demonstrate type checking
    printf("\n  Type checking prevents errors:\n");
    struct TaggedUnion test_val;
    test_val.type = TYPE_INT;
    test_val.data.int_val = 100;
    
    printf("    Current type: INT, value: %d\n", test_val.data.int_val);
    printf("    Attempting to read as float would be unsafe!\n");
    printf("    Tag prevents accidental misuse\n");
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("5. PRACTICAL APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    // Application 1: Float to bytes conversion
    printf("Application 1: Float to bytes conversion\n");
    union FloatBytes fb;
    fb.f = 3.14159f;
    
    printf("  Float value: %f\n", fb.f);
    printf("  As bytes: [");
    for (int i = 0; i < 4; i++) {
        printf("0x%02X", fb.bytes[i]);
        if (i < 3) printf(", ");
    }
    printf("]\n");
    
    // Reverse: bytes to float
    union FloatBytes fb2;
    fb2.bytes[0] = 0x40;
    fb2.bytes[1] = 0x49;
    fb2.bytes[2] = 0x0F;
    fb2.bytes[3] = 0xDB;
    printf("  Bytes [0x40, 0x49, 0x0F, 0xDB] as float: %f\n", fb2.f);
    
    // Application 2: Variant data storage
    printf("\nApplication 2: Variant data storage\n");
    
    union VariantData {
        int error_code;
        float temperature;
        char status_message[16];
    };
    
    struct Sensor {
        int id;
        enum { ERROR, TEMP, STATUS } data_type;
        union VariantData data;
    };
    
    struct Sensor sensors[3] = {
        {1, ERROR, .data.error_code = 404},
        {2, TEMP, .data.temperature = 23.5f},
        {3, STATUS, .data.status_message = "OK"}
    };
    
    printf("  Sensor readings:\n");
    for (int i = 0; i < 3; i++) {
        printf("    Sensor %d: ", sensors[i].id);
        switch (sensors[i].data_type) {
            case ERROR:
                printf("Error code %d\n", sensors[i].data.error_code);
                break;
            case TEMP:
                printf("Temperature %.1f°C\n", sensors[i].data.temperature);
                break;
            case STATUS:
                printf("Status: %s\n", sensors[i].data.status_message);
                break;
        }
    }
    
    // Application 3: Memory-efficient configuration
    printf("\nApplication 3: Memory-efficient configuration\n");
    
    union ConfigValue {
        int int_config;
        float float_config;
        char string_config[32];
    };
    
    struct ConfigItem {
        char name[20];
        enum { CONFIG_INT, CONFIG_FLOAT, CONFIG_STRING } type;
        union ConfigValue value;
    };
    
    struct ConfigItem config[] = {
        {"max_connections", CONFIG_INT, .value.int_config = 100},
        {"timeout", CONFIG_FLOAT, .value.float_config = 30.5f},
        {"server_name", CONFIG_STRING, .value.string_config = "MyServer"}
    };
    
    int config_count = sizeof(config) / sizeof(config[0]);
    printf("  Configuration settings:\n");
    for (int i = 0; i < config_count; i++) {
        printf("    %s = ", config[i].name);
        switch (config[i].type) {
            case CONFIG_INT:
                printf("%d\n", config[i].value.int_config);
                break;
            case CONFIG_FLOAT:
                printf("%.1f\n", config[i].value.float_config);
                break;
            case CONFIG_STRING:
                printf("\"%s\"\n", config[i].value.string_config);
                break;
        }
    }
    
    printf("  Memory saved vs separate variables: significant for large configs\n");
    printf("\n");
}

void demonstrate_union_safety(void) {
    printf("6. UNION SAFETY AND PITFALLS\n");
    printf("----------------------------------------\n");
    
    union BasicData unsafe;
    
    printf("Common pitfalls and safety practices:\n");
    
    // Pitfall 1: Reading wrong member
    printf("\n1. Reading wrong member (undefined behavior):\n");
    unsafe.i = 42;
    printf("  Stored integer: %d\n", unsafe.i);
    printf("  Reading as float: %f (UNDEFINED BEHAVIOR!)\n", unsafe.f);
    printf("  This could give garbage values or crash\n");
    
    // Pitfall 2: Uninitialized union
    printf("\n2. Uninitialized union:\n");
    union BasicData uninitialized;
    printf("  Uninitialized union contains garbage:\n");
    printf("    i = %d (garbage)\n", uninitialized.i);
    printf("    f = %f (garbage)\n", uninitialized.f);
    printf("    c = %c (garbage)\n", uninitialized.c);
    
    // Safe practice 1: Initialize properly
    printf("\n3. Safe initialization:\n");
    union BasicData safe = {0};  // Initialize first member
    printf("  Zero-initialized union:\n");
    printf("    i = %d\n", safe.i);
    printf("    f = %f\n", safe.f);
    printf("    c = %c\n", safe.c);
    
    // Safe practice 2: Use designated initializers
    union BasicData safe2 = {.f = 3.14f};
    printf("  Designated initializer:\n");
    printf("    f = %f (initialized)\n", safe2.f);
    printf("    i = %d (shares memory)\n", safe2.i);
    
    // Safe practice 3: Document active member
    printf("\n4. Best practices:\n");
    printf("  ✓ Always use tagged unions for type safety\n");
    printf("  ✓ Initialize unions properly\n");
    printf("  ✓ Document which member is active\n");
    printf("  ✓ Never read a member that wasn't last written\n");
    printf("  ✓ Use unions for memory optimization, not type punning\n");
    
    printf("\n5. When to use unions:\n");
    printf("  ✓ Memory-constrained environments\n");
    printf("  ✓ Variant data types (with tags)\n");
    printf("  ✓ Low-level data manipulation\n");
    printf("  ✓ Protocol parsing and serialization\n");
    printf("  ✗ Avoid for general-purpose programming\n");
    printf("  ✗ Avoid without proper type tracking\n");
    printf("\n");
}

void print_tagged_value(struct TaggedUnion *val) {
    if (val == NULL) return;
    
    printf("    Tagged value: ");
    switch (val->type) {
        case TYPE_INT:
            printf("Integer: %d\n", val->data.int_val);
            break;
        case TYPE_FLOAT:
            printf("Float: %.6f\n", val->data.float_val);
            break;
        case TYPE_STRING:
            printf("String: \"%s\"\n", val->data.string_val);
            break;
        default:
            printf("Invalid type!\n");
            break;
    }
}
