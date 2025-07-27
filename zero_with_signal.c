#include <stdio.h>

int zero_with_signal_portable(void *nbr, size_t size)
{
    unsigned char *nbr_bytes = (unsigned char *)nbr;

    int is_little_endian = 1;
    if (*(char *)&is_little_endian)
        return ((nbr_bytes[size - 1] & 0x80) != 0); // little-endian
    else
        return ((nbr_bytes[0] & 0x80) != 0);        // big-endian
}

//Testes (direto na main())

int main(void)
{
    printf("=== Testando zero_with_signal_portable ===\n\n");

    // Testes com int
    int i1 = 0;
    int i2 = -1;
    int i3 = 123456;
    int i4 = -123456;
    int i5 = -0;

    printf("int 0: %d\n", zero_with_signal_portable(&i1, sizeof(i1)));
    printf("int -1: %d\n", zero_with_signal_portable(&i2, sizeof(i2)));
    printf("int 123456: %d\n", zero_with_signal_portable(&i3, sizeof(i3)));
    printf("int -123456: %d\n", zero_with_signal_portable(&i4, sizeof(i4)));
    printf("int -0: %d\n", zero_with_signal_portable(&i5, sizeof(i5)));

    // Testes com float
    float f1 = 0.0f;
    float f2 = -0.0f;
    float f3 = 3.14f;
    float f4 = -3.14f;

    printf("\nfloat +0.0: %d\n", zero_with_signal_portable(&f1, sizeof(f1)));
    printf("float -0.0: %d\n", zero_with_signal_portable(&f2, sizeof(f2)));
    printf("float +3.14: %d\n", zero_with_signal_portable(&f3, sizeof(f3)));
    printf("float -3.14: %d\n", zero_with_signal_portable(&f4, sizeof(f4)));

    // Testes com double
    double d1 = 0.0;
    double d2 = -0.0;
    double d3 = 3.14;
    double d4 = -3.14;

    printf("\ndouble +0.0: %d\n", zero_with_signal_portable(&d1, sizeof(d1)));
    printf("double -0.0: %d\n", zero_with_signal_portable(&d2, sizeof(d2)));
    printf("double +3.14: %d\n", zero_with_signal_portable(&d3, sizeof(d3)));
    printf("double -3.14: %d\n", zero_with_signal_portable(&d4, sizeof(d4)));

    return 0;
}