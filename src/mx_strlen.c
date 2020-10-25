int mx_strlen(const char *s) {
    int lenght = 0;
    for (; s[lenght]; lenght++);
    return lenght;
}
