#ifndef clox_value_h
#define clox_value_h

#include "common.h"

// Tagged Union
// A tagged union is a data structure that can hold values of different types, but each value has an associated tag field which tells you which type it is.
typedef enum {
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER,
} ValueType;
// The size of a union is the size of the largest field.

typedef struct {
    ValueType type;
    union {
        bool boolean;
        double number;
    } as;
} Value;

// The _VAL macros lift a C value into the heavens. The AS_ macros bring it back down.
#define IS_BOOL(value)    ((value).type == VAL_BOOL)
#define IS_NIL(value)     ((value).type == VAL_NIL)
#define IS_NUMBER(value)  ((value).type == VAL_NUMBER)

#define AS_BOOL(value)    ((value).as.boolean)
#define AS_NUMBER(value)  ((value).as.number)

#define BOOL_VAL(value)   ((Value){VAL_BOOL, {.boolean = value}})
#define NIL_VAL           ((Value){VAL_NIL, {.number = 0}})
#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif