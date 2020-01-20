#include <bits/stdc++.h>

void my_print(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    for (const char *p = format; *p != '\0'; ++p)
    {
        switch (*p)
        {
        case 'd':
            printf("%d ", va_arg(args, int));
            break;
        case 'f':
            printf("%f ", va_arg(args, double));
            break;
        case 'c':
            printf("%c ", va_arg(args, char));
            break;
        case 's':
            printf("%s ", va_arg(args, const char *));
            break;
        default:
            assert(!"不正な変換指定");
            break;
        }
    }
    printf("\n");
    
    va_end(args);
}

int main()
{
    my_print("dddd", 1, 10, 100, 1000);
    std::cout << "END" << std::endl;
    return 0;
}