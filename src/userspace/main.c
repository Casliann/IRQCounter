# include "../common/irqcounter.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_help() {
   printf("Usage: irqcounter [options]\n");
    printf("Description:\n");
    printf("  irqcounter is a tool that tracks and displays interrupt request (IRQ) counts.\n");
    printf("Options:\n");
    printf("  --help                Show this help message.\n");
    printf("  --version             Display the version of irqcounter.\n"); 
    printf("  --debug               Display debugging information.\n");
    printf("  --verbose             Show additional debug information.\n");   
}

int main (int argc, char *argv[]) {
    char sysfs_path[] = "/sys/module/irqcounter/irq_count";
    int irq_count;

    bool debug_mode = false;
    bool verbose_mode = false; 

    FILE *file = fopen(sysfs_path, "r");
    if (!file) {
        perror("ERROR opening file\n");
        return EXIT_FAILURE;
    }

    if(fscanf(file,"%d", &irq_count) != 1) {
        perror("ERROR reading irq count from file\n");
        return EXIT_FAILURE;
    }

    if(argc < 2) {
        print_help();
        return EXIT_FAILURE;
    }

    if(strcmp(argv[1], "--help") == 0) {
        print_help();
    }
    else if(strcmp(argv[1], "--version") == 0) {
        printf("irqcounter v%s", VERSION); 
    }
    else if(strcmp(argv[1], "--debug") == 0) {
        printf("Debug mode: Additional debugging information...\n");
        debug_mode = true; 
        
    } 
    else if(strcmp(argv[1], "--verbose") == 0) {
        printf("Verbose mode: Showing detailed information...\n");
        verbose_mode = true;
    }
    else {
        printf("Unknown argument: \"%s\". type --help to get a help message.", argv[1]);
    }

    fclose(file);
    return EXIT_SUCCESS;
}