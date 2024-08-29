#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    struct timespec start, end;
    double elapsed;
    clock_gettime(CLOCK_REALTIME,&start);

    FILE *file;
    file = fopen("test2.in", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    int size;
    int *array = NULL;
    fscanf(file, "%d", &size);

    array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error al asignar memoria\n");
        fclose(file);
        exit(1);
    }

    long int sum = 0;
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &array[i]);
        sum += array[i];
    }
    clock_gettime(CLOCK_REALTIME,&end);
    elapsed = (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec) / 1.0e9);


    printf("Suma: %ld\n", sum);
    printf("Tiempo transcurrido: %f segundos\n", elapsed);

    fclose(file);
    free(array);

    return 0;
}