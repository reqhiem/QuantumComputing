#ifndef _TOOLS_H_
#define _TOOLS_H_

unsigned long long optimized_choose_by_misael_svante_vilchez_molina(unsigned long long n, unsigned long long k) {
    unsigned long long r = n - k;
    r = (r < k) ? r : k;
    unsigned long long num = 1, den = 1;
    for (int i = 0; i < r; ++i)
        num *= (n - i), den *= (r - i);
    return num / den;
}

#endif