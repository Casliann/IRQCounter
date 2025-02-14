#ifndef IRQCOUNTER_H
#define IRQCOUNTER_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef VERSION
#define VERSION "1.0.0"
#endif 

#ifndef SYSFS_PROJ_DIR
#define SYSFS_PROJ_DIR "/sys/module/irqcounter/irq_count"
#endif

#endif  /*IRQCOUNTER_H*/