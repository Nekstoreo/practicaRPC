struct sum_args {
    int numbers[10];
    int count;
};

program SUMADOR_PROG {
    version SUMADOR_VERS {
        int SUMAR(sum_args) = 1;
    } = 1;
} = 0x20000001;