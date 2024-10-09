#include "sumador.h"

int * sumar_1_svc(sum_args *args, struct svc_req *req) {
    static int result;
    result = 0;
    for (int i = 0; i < args->count; i++) {
        result += args->numbers[i];
    }
    return &result;
}