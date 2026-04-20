#include "str.h"

String* new_strstr(const char* str) {
    if (!str) return NULL;
    String* s = malloc(sizeof(String));
    if (!s) return NULL;
    size_t len = strlen(str);
    s->str = malloc(sizeof(char)*len + 1);
    if (!s->str){
        free(s);
        return NULL;
    }
    strcpy(s->str, str);
    s->len = len;
    return s;
}

String* new_strdec(size_t cnt){
    if (cnt > 1000000) return NULL;
    String* s = malloc(sizeof(String));
    s->str = malloc(sizeof(char)*cnt);
    if (!s->str){
        free(s);
        return NULL;
    }
    memset(s->str, 0, cnt);
    s->len = cnt;
    return s;
}

String* new_strdup(const String* s) {
    if (!s) return NULL;
    String* str = malloc(sizeof(String));
    if (!str) return NULL;
    str->str = malloc(sizeof(char)*s->len);
    if (!str->str) {
        free(str);
        return NULL;
    }
    strcpy(str->str, s->str);
    str->len = s->len;
    return str;
}

void destroy_str(String* s){
    if (s) {
        free(s->str);
        free(s);
    }
}

size_t len(String* s) {
    if (s) return s->len;
    return 0;
}

char* cstring(String* s) {
    if (s) return s->str;
    return NULL;
}

int concat_str(String* s, const String* add) {
    if (!s || !add) return -1;
    s->str = realloc(s->str, s->len + add->len);
    if (!s->str) return -1;
    strcat(s->str, add->str);
    s->len += add->len + 1; 
    return 0;
}

String* slice(String* s, size_t start, size_t end) {
    if (!s) return NULL;
    if (start >= end) return NULL;
    if (end > s->len) return NULL;
    
    String* newstr = new_strdec(end - start);
    if (!newstr) return NULL;
    
    int j = 0;
    for (int i = start; i < end; i++) {
        newstr->str[j++] = s->str[i];
    }
    newstr->len = end-start;
    return newstr;
}

int cmp_str(const String* s1, const String* s2){
    if (!s1 || !s2) return -1;
    if (!strcmp(s1->str, s2->str)) {
        return 0;
    }
    return -1;
}

int read_string(String* s) {
    if (!s) return -1;
    memset(s->str, 0, s->len);
    size_t len_buff = fread(s->str, sizeof(char), s->len - 1, stdin);
    if (len_buff > 0) {
        return 0;
    }
    else { 
        puts("Error: read stdin");
    }
    return -1;
}

int read_string_stream(String* s, FILE *restrict stream){
    if (!s || !stream) return -1;
    memset(s->str, 0, s->len);
    size_t len_buff = fread(s->str, sizeof(char), s->len-1, stream);
    if (len_buff > 0) {
        return 0;
    } 
    else {
        puts("Error: read stream");
    }
    return -1;
}


int read_line_stream(String* s, FILE* restrict stream) {
    if (!s || !stream) return -1;
    memset(s->str, 0, s->len);
    char* err = fgets(s->str, s->len, stream);
    if (!err) return -1;
    return 0;
}
int write_stream(const String* s, FILE* restrict stream) {
    if (!s || !stream) return -1;
    suze_t len_wr = fwrite(s->str, sizeof(char), s->len, stream);
    if (len_wr > 0) {
        return 0;
    }
    else {
        puts("Error: write stream");
    }
    return -1;
}

int is_empty(const String* s) {
    if (!s) return -1;
    if (s->str && s->len > 0) return 0;
    return -1;
}

void to_upper_str(String* s) {
    if (!s) return;
    for (int i = 0; i < s->len; i++) {
        if (s->str[i] > 96 && s->str[i] < 123) {
            s->str[i] -= 32;
        }
        if (s->str[i] == '\0') break;
    }
}
void to_lower_str(String* s) {
    if (!s) return;
    for (int i = 0; i < s->len; i++) {
        if (s->str[i] > 64 && s->str[i] < 91) {
            s->str[i] += 32;
        }
        if (s->str[i] == '\0') break;
    }
}
