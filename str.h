#ifndef STR_H
#define STR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string {
    char* str;
    size_t len;
} String;

String* new_strstr(const char* str);
String* new_strdec(size_t cnt);
String* new_strdup(const String* s);
void destroy_str(String* s);

size_t len(String* s);//++
char* cstring(String* s);//++
int concat_str(String* s, const String* add);//++
String* slice(String* s, size_t start, size_t end);//++
int cmp_str(const String* s1, const String* s2);//++

int read_string(String* s);//++
int read_string_stream(String* s, FILE *restrict stream);//++
int read_line_stream(String* s, FILE* restrict stream);//++
int write_stream(const String* s, FILE* restrict stream);//++


void to_upper_str(String* s); //++
void to_lower_str(String* s); //++
#endif
