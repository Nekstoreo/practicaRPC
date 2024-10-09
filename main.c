
#include <stdio.h>
#include <rpc/rpc.h>
#include "sumador.h"

int main(int argc, char *argv[]) {
    CLIENT *clnt;
    sum_args args;
    int *result;

    if (argc < 2 || argc > 11) {
        printf("Usage: %s num1 [num2 ... num10]\n", argv[0]);
        return 1;
    }

    args.count = argc - 1;
    for (int i = 0; i < args.count; i++) {
        args.numbers[i] = atoi(argv[i + 1]);
    }

    clnt = clnt_create("localhost", SUMADOR_PROG, SUMADOR_VERS, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror("Error creating RPC client");
        return 1;
    }

    result = sumar_1(&args, clnt);
    if (result == NULL) {
        clnt_perror(clnt, "Error calling RPC function");
        return 1;
    }

    printf("The sum is: %d\n", *result);
    clnt_destroy(clnt);
    return 0;
}