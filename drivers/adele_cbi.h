<<<<<<< HEAD
<<<<<<< HEAD
/*  adele_cbi.h - Driver for ADELE CB/CBI DC-UPS
 *
 *  Copyright (C)
 *    2022 Dimitris Economou <dimitris.s.economou@gmail.com>
<<<<<<< HEAD
=======
/*  adele_cbi.h - Driver for generic UPS connected via modbus RIO
=======
/*  adele_cbi.h - Driver for ADELE CB/CBI DC-UPS
>>>>>>> structure device data, code get_dev_state, in progress
 *
 *  Copyright (C)
 *    2021 Dimitris Economou <dimitris.s.economou@gmail.com>
>>>>>>> under construction
=======
>>>>>>> ghost alarms bug fix, other bug fixes
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#ifndef ADELE_CBI_H
#define ADELE_CBI_H

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> register status values and masks added
#include <stdint.h>

/* UPS device details */
#define DEVICE_MFR  "ADELE"
#define DEVICE_TYPE "DC-UPS"
<<<<<<< HEAD
=======
/* UPS device details */
#define DEVICE_MFR  "ADELE"
>>>>>>> under construction
=======
>>>>>>> alrm_t, alrm_ar_t data structures, construction of upsdrv_updateinfo in progress
#define DEVICE_MODEL "CB/CBI"

/* serial access parameters */
#define BAUD_RATE 9600
#define PARITY 'N'
#define DATA_BIT 8
#define STOP_BIT 1

/*
 * modbus response and byte timeouts
 * us: 1 - 999999
 */
#define MODRESP_TIMEOUT_s 0
#define MODRESP_TIMEOUT_us 200000
#define MODBYTE_TIMEOUT_s 0
#define MODBYTE_TIMEOUT_us 50000

/* modbus access parameters */
#define MODBUS_SLAVE_ID 5

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> structure device data, code get_dev_state, in progress
/* number of modbus registers */
#define MODBUS_NUMOF_REGS 98

/* max registers */
#define MAX_REGS 116

/* read all regs */
#define READALL_REGS 1

/* number of device models */
#define DEV_NUMOF_MODELS 10

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> first testing release
/* shutdown repeat on error */
#define FSD_REPEAT_CNT 3

/* shutdown repeat interval in ms */
#define FSD_REPEAT_INTRV 1500

<<<<<<< HEAD
/* definition of register type */
enum regtype {
    COIL = 0,
    INPUT_B,
    INPUT_R,
    HOLDING
};
typedef enum regtype regtype_t;

/* product name info, "device.model" */
struct prodname {
    uint16_t val;
    char *name;
};
typedef struct prodname prodname_t;
static prodname_t prdnm_i[] = {
        {1, "CBI1235A"},
        {2, "CBI2420A"},
        {3, "CBI4810A"},
        {4, "CBI2801224"},
        {7, "CBI480W"},
        {8, "CB122410A"},
        {9, "CB480W"},
        {11, "CB12245AJ"},
        {12, "CB1235A"},
        {13, "CB2420A"},
        {14, "CB4810A"}
};

/* charging status info, "battery.charger.status" */
static char *chrgs_i[] = {
        "none",
        "resting",     /* recovering */
        "charging",    /* bulk */
        "charging",    /* absorb */
        "floating"     /* float */
};
struct chrgs {
    int state;
    char *info;
};
typedef struct chrgs chrgs_t;

/* power management info, "ups.status", "battery.charger.status" */
static char *pwrmng_i[] = {
        "backup",       /* "OB", "discharging" */
        "charging",     /* "OL" */
        "boost",
        "not charging"
};
struct pwrmng {
    int state;
    char *info;
};
typedef struct pwrmng pwrmng_t;

/* general modbus register value */
struct reg {
    union {
        uint16_t val16;
        uint8_t val8;
    };
    char *strval;
};
typedef struct reg reg_t;

/* general alarm struct */
struct alrm {
    int actv;               /* active flag */
    char *descr;            /* description field */
};
typedef struct alrm alrm_t;

/* general alarm array */
struct alrm_ar {
    int alrm_c;             /* alarm count */
    alrm_t alrm[];          /* alarm array */
};
typedef struct alrm_ar alrm_ar_t;

/*
 * BIT MASKS and VALUES
 */

/* Charging status */
=======
=======
>>>>>>> structure device data, code get_dev_state, in progress
=======
>>>>>>> first testing release
/* definition of register type */
enum regtype {
    COIL = 0,
    INPUT_B,
    INPUT_R,
    HOLDING
};
typedef enum regtype regtype_t;

/* product name info, "device.model" */
struct prodname {
    uint16_t val;
    char *name;
};
typedef struct prodname prodname_t;
<<<<<<< HEAD
<<<<<<< HEAD

<<<<<<< HEAD
/* BIT MASKS and VALUES */
>>>>>>> under construction
=======
/* product name */
prodname_t prdn[] = {
=======
prodname_t prdnm_i[] = {
>>>>>>> structure device data, code get_dev_state, in progress
=======
static prodname_t prdnm_i[] = {
>>>>>>> ghost alarms bug fix, other bug fixes
        {1, "CBI1235A"},
        {2, "CBI2420A"},
        {3, "CBI4810A"},
        {4, "CBI2801224"},
        {7, "CBI480W"},
        {8, "CB122410A"},
        {9, "CB480W"},
        {11, "CB12245AJ"},
        {12, "CB1235A"},
        {13, "CB2420A"},
        {14, "CB4810A"}
};

/* charging status info, "battery.charger.status" */
static char *chrgs_i[] = {
        "none",
        "resting",     /* recovering */
        "charging",    /* bulk */
        "charging",    /* absorb */
        "floating"     /* float */
};
struct chrgs {
    int state;
    char *info;
};
typedef struct chrgs chrgs_t;

/* power management info, "ups.status", "battery.charger.status" */
static char *pwrmng_i[] = {
        "backup",       /* "OB", "discharging" */
        "charging",     /* "OL" */
        "boost",
        "not charging"
};
struct pwrmng {
    int state;
    char *info;
};
typedef struct pwrmng pwrmng_t;

/* general modbus register value */
struct reg {
    union {
        uint16_t val16;
        uint8_t val8;
    };
    char *strval;
};
typedef struct reg reg_t;

/* general alarm struct */
struct alrm {
    int actv;               /* active flag */
    char *descr;            /* description field */
};
typedef struct alrm alrm_t;

/* general alarm array */
struct alrm_ar {
    int alrm_c;             /* alarm count */
    alrm_t alrm[];          /* alarm array */
};
typedef struct alrm_ar alrm_ar_t;

/*
 * BIT MASKS and VALUES
 */

/* Charging status */
>>>>>>> register status values and masks added
#define CHRG_NONE 0
#define CHRG_RECV 1
#define CHRG_BULK 2
#define CHRG_ABSR 3
#define CHRG_FLOAT 4
<<<<<<< HEAD
<<<<<<< HEAD

/* power management */
#define PMNG_BCKUP 0
#define PMNG_CHRGN 1
#define PMNG_BOOST 2
#define PMNG_NCHRG 3

/* product name */
#define PRDN_MAX 14

/* Mains alarm masks */
#define MAINS_AVAIL_M 0x0001    /* 0: available (OL) 1: not available (OB) */
#define SHUTD_REQST_M 0x0002    /* shutdown requested */

/* Mains alarm indices */
#define MAINS_AVAIL_I 0         /* 0: available (OL) 1: not available (OB) */
#define SHUTD_REQST_I 1         /* shutdown requested */

/* AC input voltage alarm masks */
#define VACA_HIALRM_M 0x0001    /* high alarm */
#define VACA_LOALRM_M 0x0002    /* low alarm */

/* AC input voltage alarm indices */
#define VACA_HIALRM_I 0         /* high alarm */
#define VACA_LOALRM_I 1         /* low alarm */

/* Onboard temperature alarm value */
#define OBTA_HIALRM_V 1         /* high alarm */

/* Onboard temperature alarm index */
#define OBTA_HIALRM_I 0         /* high alarm */
<<<<<<< HEAD

/* Device failure alarm masks */
#define DEVF_RCALRM_M 0x0001    /* rectifier failure */
#define DEVF_INALRM_M 0x0006    /* internal failure */
#define DEVF_LFNAVL_M 0x0008    /* lifetest not available */

/* Device failure alarm indices */
#define DEVF_RCALRM_I 0         /* rectifier failure */
#define DEVF_INALRM_I 1         /* internal failure */
#define DEVF_LFNAVL_I 2         /* lifetest not available */

/* Battery temp sensor failure alarm masks */
#define BTSF_FCND_M 0x0001      /* connection fault */
#define BTSF_NCND_M 0x0002      /* not connected */

/* Battery temp sensor failure alarm indices */
#define BTSF_FCND_I 0           /* connection fault */
#define BTSF_NCND_I 1           /* not connected */

/* Battery voltage alarm masks */
#define BVAL_HIALRM_M 0x0001    /* high voltage */
#define BVAL_LOALRM_M 0x0002    /* low voltage */
#define BVAL_BSTSFL_M 0x0004    /* battery start with battery flat */

/* Battery voltage alarm indices */
#define BVAL_HIALRM_I 0         /* high voltage */
#define BVAL_LOALRM_I 1         /* low voltage */
#define BVAL_BSTSFL_I 2         /* battery start with battery flat */

/* SoH and SoC alarm masks */
#define SHSC_HIRESI_M 0x0001    /* high internal resistance */
#define SHSC_LOCHEF_M 0x0002    /* low charge efficiency */
#define SHSC_LOEFCP_M 0x0004    /* low effective capacity */
#define SHSC_LOWSOC_M 0x0040    /* low state of charge */

/* SoH and SoC alarm indices */
#define SHSC_HIRESI_I 0         /* high internal resistance */
#define SHSC_LOCHEF_I 1         /* low charge efficiency */
#define SHSC_LOEFCP_I 2         /* low effective capacity */
#define SHSC_LOWSOC_I 3         /* low state of charge */

/* Battery status alarm masks */
#define BSTA_REVPOL_M 0x0001    /* reversed polarity */
#define BSTA_NOCNND_M 0x0002    /* not connected */
#define BSTA_CLSHCR_M 0x0004    /* cell short circuit */
#define BSTA_SULPHD_M 0x0008    /* sulphated */
#define BSTA_CHEMNS_M 0x0010    /* chemistry not supported */
#define BSTA_CNNFLT_M 0x0020    /* connection fault */

/* Battery status alarm indices */
#define BSTA_REVPOL_I 0         /* reversed polarity */
#define BSTA_NOCNND_I 1         /* not connected */
#define BSTA_CLSHCR_I 2         /* cell short circuit */
#define BSTA_SULPHD_I 3         /* sulphated */
#define BSTA_CHEMNS_I 4         /* chemistry not supported */
#define BSTA_CNNFLT_I 5         /* connection fault */

/* input mains and shutdown alarms */
static alrm_ar_t mains = {
        2,
        {
                {0, "input voltage not available"},
                {0, "ups shutdown requested"}
        }
};

/* AC input voltage alarms */
static alrm_ar_t vaca = {
        2,
        {
                {0, "input voltage high alarm"},
                {0, "input voltage low alarm"}
        }
};

/* device failure alarms */
static alrm_ar_t devf = {
        3,
        {
                {0, "UPS rectifier failure"},
                {0, "UPS internal failure"},
                {0, "UPS lifetest not available"}
        }
};

/* battery sensor failure alarms */
static alrm_ar_t btsf = {
        2,
        {
                {0, "battery temp sensor connection fault"},
                {0, "battery temp sensor not connected"}
        }
};

/* battery voltage alarms */
static alrm_ar_t bval = {
        3,
        {
                {0, "battery high voltage"},
                {0, "battery low voltage"},
                {0, "battery start with battery flat"}
        }
};

/* battery SoH and SoC alarms */
static alrm_ar_t shsc = {
        4,
        {
                {0, "battery high internal resistance"},
                {0, "battery low charge efficiency"},
                {0, "battery low effective capacity"},
                {0, "battery low state of charge"}
        }
};

/* battery status alarm */
static alrm_ar_t bsta = {
        6,
        {
                {0, "battery reversed polarity"},
                {0, "battery not connected"},
                {0, "battery cell short circuit"},
                {0, "battery sulphated"},
                {0, "battery chemistry not supported"},
                {0, "battery connection fault"}
        }
};

/* onboard temperature alarm */
static alrm_ar_t obta = {
        1,
        {
                {0, "onboard temperature high"}
        }
};

/* UPS device reg enum */
enum devreg {
    CHRG = 4,           /* Charging status, "battery.charger.status" */
    BATV = 7,           /* Battery voltage, "battery.voltage" */
    BCEF = 18,          /* Battery charge efficiency factor (CEF) */
    BSOH = 20,          /* Battery state-of-health */
    BSOC = 22,          /* Battery state-of-charge, "battery.charge" */
    BTMP = 25,          /* Battery temperature in Kelvin units, "battery.temperature" */
    PMNG = 5,           /* Power management, "ups.status" */
    OTMP = 28,          /* Onboard temperature, "ups.temperature" */
    PRDN = 67,          /* Product name, "ups.model" */
    VAC  = 29,          /* AC voltage, "input.voltage" */
    LVDC = 10,          /* Load voltage, "output.voltage" */
    LCUR = 19,          /* Load current, "output.current" */
    BINH = 87,          /* Backup inhibit */
    FSD  = 40,          /* Force shutdown */
    TBUF = 103,         /* Time buffering, "battery.runtime" */
    BSTA = 31,          /* Battery status alarms */
    SCSH,               /* SoH and SoC alarms */
    BVAL = 34,          /* Battery voltage alarm */
    BTSF = 43,          /* Battery temp sensor failure */
    DEVF = 42,          /* Device failure */
    OBTA = 46,          /* On board temp alarm */
    VACA = 44,          /* VAC alarms */
    MAIN                /* Mains status */
};
typedef enum devreg devreg_t;

/* UPS register attributes */
struct regattr {
    int num;
    int saddr;          /* register start address */
    int xaddr;          /* register hex address */
    float scale;        /* scale */
    regtype_t type;     /* register type */
};
typedef struct regattr regattr_t;

/* UPS device state info union */
union devstate {
    prodname_t product; /* ups model name */
    chrgs_t charge;     /* charging status */
    pwrmng_t power;     /* ups status */
    reg_t reg;          /* state register*/
    alrm_ar_t *alrm;    /* alarm statuses */
};

typedef union devstate devstate_t;

/* device register memory image */
static uint16_t regs_data[MAX_REGS];

/* ADELE CBI registers */
static regattr_t regs[] = {
<<<<<<< HEAD
=======
=======

/* power management */
<<<<<<< HEAD
>>>>>>> register status values and masks added
#define PMNG_BKUP 0
#define PMNG_CHRG 1
=======
#define PMNG_BCKUP 0
#define PMNG_CHRGN 1
>>>>>>> structure device data, code get_dev_state, in progress
#define PMNG_BOOST 2
#define PMNG_NCHRG 3

/* product name */
#define PRDN_MAX 14

/* Mains alarm masks */
#define MAINS_AVAIL_M 0x0001    /* 0: available (OL) 1: not available (OB) */
#define SHUTD_REQST_M 0x0002    /* shutdown requested */

/* Mains alarm indices */
#define MAINS_AVAIL_I 0         /* 0: available (OL) 1: not available (OB) */
#define SHUTD_REQST_I 1         /* shutdown requested */

/* AC input voltage alarm masks */
#define VACA_HIALRM_M 0x0001    /* high alarm */
#define VACA_LOALRM_M 0x0002    /* low alarm */

/* AC input voltage alarm indices */
#define VACA_HIALRM_I 0         /* high alarm */
#define VACA_LOALRM_I 1         /* low alarm */

/* Onboard temperature alarm */
#define OBTA_HIALRM 1           /* high alarm */
=======
>>>>>>> ghost alarms bug fix, other bug fixes

/* Device failure alarm masks */
#define DEVF_RCALRM_M 0x0001    /* rectifier failure */
#define DEVF_INALRM_M 0x0006    /* internal failure */
#define DEVF_LFNAVL_M 0x0008    /* lifetest not available */

/* Device failure alarm indices */
#define DEVF_RCALRM_I 0         /* rectifier failure */
#define DEVF_INALRM_I 1         /* internal failure */
#define DEVF_LFNAVL_I 2         /* lifetest not available */

/* Battery temp sensor failure alarm masks */
#define BTSF_FCND_M 0x0001      /* connection fault */
#define BTSF_NCND_M 0x0002      /* not connected */

/* Battery temp sensor failure alarm indices */
#define BTSF_FCND_I 0           /* connection fault */
#define BTSF_NCND_I 1           /* not connected */

/* Battery voltage alarm masks */
#define BVAL_HIALRM_M 0x0001    /* high voltage */
#define BVAL_LOALRM_M 0x0002    /* low voltage */
#define BVAL_BSTSFL_M 0x0004    /* battery start with battery flat */

/* Battery voltage alarm indices */
#define BVAL_HIALRM_I 0         /* high voltage */
#define BVAL_LOALRM_I 1         /* low voltage */
#define BVAL_BSTSFL_I 2         /* battery start with battery flat */

/* SoH and SoC alarm masks */
#define SHSC_HIRESI_M 0x0001    /* high internal resistance */
#define SHSC_LOCHEF_M 0x0002    /* low charge efficiency */
#define SHSC_LOEFCP_M 0x0004    /* low effective capacity */
#define SHSC_LOWSOC_M 0x0040    /* low state of charge */

/* SoH and SoC alarm indices */
#define SHSC_HIRESI_I 0         /* high internal resistance */
#define SHSC_LOCHEF_I 1         /* low charge efficiency */
#define SHSC_LOEFCP_I 2         /* low effective capacity */
#define SHSC_LOWSOC_I 3         /* low state of charge */

/* Battery status alarm masks */
#define BSTA_REVPOL_M 0x0001    /* reversed polarity */
#define BSTA_NOCNND_M 0x0002    /* not connected */
#define BSTA_CLSHCR_M 0x0004    /* cell short circuit */
#define BSTA_SULPHD_M 0x0008    /* sulphated */
#define BSTA_CHEMNS_M 0x0010    /* chemistry not supported */
#define BSTA_CNNFLT_M 0x0020    /* connection fault */

/* Battery status alarm indices */
#define BSTA_REVPOL_I 0         /* reversed polarity */
#define BSTA_NOCNND_I 1         /* not connected */
#define BSTA_CLSHCR_I 2         /* cell short circuit */
#define BSTA_SULPHD_I 3         /* sulphated */
#define BSTA_CHEMNS_I 4         /* chemistry not supported */
#define BSTA_CNNFLT_I 5         /* connection fault */

/* input mains and shutdown alarms */
static alrm_ar_t mains = {
        2,
        {
                {0, "input voltage not available"},
                {0, "ups shutdown requested"}
        }
};

/* AC input voltage alarms */
static alrm_ar_t vaca = {
        2,
        {
                {0, "input voltage high alarm"},
                {0, "input voltage low alarm"}
        }
};

/* device failure alarms */
static alrm_ar_t devf = {
        3,
        {
                {0, "UPS rectifier failure"},
                {0, "UPS internal failure"},
                {0, "UPS lifetest not available"}
        }
};

/* battery sensor failure alarms */
static alrm_ar_t btsf = {
        2,
        {
                {0, "battery temp sensor connection fault"},
                {0, "battery temp sensor not connected"}
        }
};

/* battery voltage alarms */
static alrm_ar_t bval = {
        3,
        {
                {0, "battery high voltage"},
                {0, "battery low voltage"},
                {0, "battery start with battery flat"}
        }
};

/* battery SoH and SoC alarms */
static alrm_ar_t shsc = {
        4,
        {
                {0, "battery high internal resistance"},
                {0, "battery low charge efficiency"},
                {0, "battery low effective capacity"},
                {0, "battery low state of charge"}
        }
};

/* battery status alarm */
static alrm_ar_t bsta = {
        6,
        {
                {0, "battery reversed polarity"},
                {0, "battery not connected"},
                {0, "battery cell short circuit"},
                {0, "battery sulphated"},
                {0, "battery chemistry not supported"},
                {0, "battery connection fault"}
        }
};

/* onboard temperature alarm */
static alrm_ar_t obta = {
        1,
        {
                {0, "onboard temperature high"}
        }
};

/* UPS device reg enum */
enum devreg {
    CHRG = 0,       /* Charging status, "battery.charger.status" */
    BATV,           /* Battery voltage, "battery.voltage" */
    BCEF = 6,       /* Battery charge efficiency factor (CEF) */
    BSOH,           /* Battery state-of-health */
    BSOC = 9,       /* Battery state-of-charge, "battery.charge" */
    BTMP = 11,      /* Battery temperature in Kelvin units, "battery.temperature" */
    PMNG = 15,      /* Power management, "ups.status" */
    OTMP = 20,      /* Onboard temperature, "ups.temperature" */
    PRDN,           /* Product name, "ups.model" */
    VAC  = 24,      /* AC voltage, "input.voltage" */
    LVDC,           /* Load voltage, "output.voltage" */
    LCUR,           /* Load current, "output.current" */
    BINH = 79,      /* Backup inhibit */
    FSD,            /* Force shutdown */
    TBUF,           /* Time buffering, "battery.runtime" */
    BSTA = 89,      /* Battery status alarms */
    SCSH,           /* SoH and SoC alarms */
    BVAL,           /* Battery voltage alarm */
    BTSF,           /* Battery temp sensor failure */
    DEVF,           /* Device failure */
    OBTA,           /* On board temp alarm */
    VACA,           /* VAC alarms */
    MAIN            /* Mains status */
};
typedef enum devreg devreg_t;

/* UPS register attributes */
struct regattr {
    int num;
    int saddr;          /* register start address */
    int xaddr;          /* register hex address */
    float scale;        /* scale */
    regtype_t type;     /* register type */
};
typedef struct regattr regattr_t;

/* UPS device state info union */
union devstate {
    prodname_t product; /* ups model name */
    chrgs_t charge;     /* charging status */
    pwrmng_t power;     /* ups status */
    reg_t reg;          /* state register*/
    alrm_ar_t *alrm;    /* alarm statuses */
};

typedef union devstate devstate_t;

/* ADELE CBI registers */
<<<<<<< HEAD
regattr_t regs[] = {
>>>>>>> under construction
=======
static regattr_t regs[] = {
>>>>>>> ghost alarms bug fix, other bug fixes
         {40005, 0, 0, 1, HOLDING},    /* Charging status */
         {40008, 0, 0, 1, HOLDING},    /* Battery voltage */
         {40014, 0, 0, 1, HOLDING},    /* Battery charge current */
         {40016, 0, 0, .1, HOLDING},   /* Battery capacity consumed */
         {40017, 0, 0, 1, HOLDING},    /* Battery discharge current */
         {40018, 0, 0, .1, HOLDING},   /* Effective battery capacity */
         {40019, 0, 0, 1, HOLDING},    /* Battery charge efficiency factor (CEF) */
         {40021, 0, 0, 1, HOLDING},    /* Battery state-of-health */
         {40022, 0, 0, 1, HOLDING},    /* Time remaining to 100% discharge */
         {40023, 0, 0, .1, HOLDING},   /* Battery state-of-charge */
         {40024, 0, 0, 1, HOLDING},   /* Battery type currently selected */
         {40026, 0, 0, 1, HOLDING},   /* Battery temperature in Kelvin units */
         {40028, 0, 0, .1, HOLDING},  /* Battery net internal resistance */
         {40089, 0, 0, 1, HOLDING},   /* Number of battery cells */
         {40100, 0, 0, 1, HOLDING},   /* SoC/SoH test possible */
         {40006, 0, 0, 1, HOLDING},   /* Power management
<<<<<<< HEAD
<<<<<<< HEAD
                                       * 0:Backup 1:Charging 2:boost 3:Not charging
                                       */
=======
                                                                        * 0:Backup 1:Charging 2:boost 3:Not charging
                                                                        */
>>>>>>> under construction
=======
                                       * 0:Backup 1:Charging 2:boost 3:Not charging
                                       */
>>>>>>> ghost alarms bug fix, other bug fixes
         {40007, 0, 0, 1, HOLDING},   /* Nominal output voltage */
         {40009, 0, 0, 1, HOLDING},   /* Parameter map version ID */
         {40010, 0, 0, 1, HOLDING},   /* Software ID */
         {40027, 0, 0, 1, HOLDING},   /* Configuration mode */
         {40029, 0, 0, 1, HOLDING},   /* On-board temperature */
         {40067, 0, 0, 1, HOLDING},   /* Product name */
         {40039, 0, 0, 1, HOLDING},   /* Device variant */
         {40103, 0, 0, 1, HOLDING},   /* Firmware ID */
         {40030, 0, 0, 1, HOLDING},   /* AC input voltage */
         {40011, 0, 0, 1, HOLDING},   /* Output load voltage */
         {40020, 0, 0, 1, HOLDING},   /* Output load current */
         {40048, 0, 0, 1, HOLDING},   /* Number of charge cycles completed */
         {40049, 0, 0, 1, HOLDING},   /* Charge cycles not completed */
         {40050, 0, 0, .1, HOLDING},  /* Ah charged */
         {40051, 0, 0, 1, HOLDING},   /* Total run time */
         {40052, 0, 0, 1, HOLDING},   /* Number of low battery voltage events */
         {40053, 0, 0, 1, HOLDING},   /* Number of high battery voltage events */
         {40058, 0, 0, 1, HOLDING},   /* Number power boost events */
         {40059, 0, 0, 1, HOLDING},   /* Highest battery voltage */
         {40062, 0, 0, 1, HOLDING},   /* Lowest battery voltage */
         {40061, 0, 0, .1, HOLDING},  /* Maximum depth of discharge */
         {40064, 0, 0, .1, HOLDING},  /* Average depth of discharge */
<<<<<<< HEAD
<<<<<<< HEAD
         {40056, 0, 0, 1, HOLDING},   /* Number of over temperature inside events */
         {40054, 0, 0, 1, HOLDING},   /* Number of low VAC events at mains input */
         {40055, 0, 0, 1, HOLDING},   /* Number of High VAC events at mains input */
=======
         {40056, 0, 0, 1, HOLDING},   /* Number of overtemperature inside events */
         {40054, 0, 0, 1, HOLDING},   /* Number of low AC input voltage events at mains input */
         {40055, 0, 0, 1, HOLDING},   /* Number of High AC input voltage events at mains input */
>>>>>>> under construction
=======
         {40056, 0, 0, 1, HOLDING},   /* Number of over temperature inside events */
         {40054, 0, 0, 1, HOLDING},   /* Number of low VAC events at mains input */
         {40055, 0, 0, 1, HOLDING},   /* Number of High VAC events at mains input */
>>>>>>> register status values and masks added
         {40057, 0, 0, 1, HOLDING},   /* Number of mains-backup transitions */
         {40060, 0, 0, 1, HOLDING},   /* Highest output load voltage */
         {40063, 0, 0, 1, HOLDING},   /* Lowest output load voltage */
         {40069, 0, 0, 1, HOLDING},   /* Reset internal battery model */
         {40098, 0, 0, 1, HOLDING},   /* SoC/SoH test period */
         {40099, 0, 0, 1, HOLDING},   /* Manual SoC/SoH test request */
         {40101, 0, 0, .1, HOLDING},  /* Nominal battery internal resistance */
         {40102, 0, 0, .1, HOLDING},  /* Nominal battery cables resistance */
         {40105, 0, 0, .1, HOLDING},  /* Battery capacity C20 */
         {40106, 0, 0, .1, HOLDING},  /* Battery Capacity C10 */
         {40108, 0, 0, .1, HOLDING},  /* Battery Capacity C5 */
         {40109, 0, 0, .1, HOLDING},  /* Battery Capacity C2 */
         {40112, 0, 0, .1, HOLDING},  /* Battery Capacity C1 */
         {40113, 0, 0, .1, HOLDING},  /* Low state-of-charge */
         {40120, 0, 0, 1, HOLDING},   /* Zero-SoC reference */
         {40071, 0, 0, 1, HOLDING},   /* Deep discharge battery prevention */
         {40072, 0, 0, 1, HOLDING},   /* Maximum charge current */
         {40073, 0, 0, 1, HOLDING},   /* Bulk voltage */
         {40074, 0, 0, 1, HOLDING},   /* Max bulk timer */
         {40075, 0, 0, 1, HOLDING},   /* Min bulk timer */
         {40077, 0, 0, 1, HOLDING},   /* Absorption voltage */
         {40078, 0, 0, 1, HOLDING},   /* Max absorption timer */
         {40079, 0, 0, 1, HOLDING},   /* Min absorption timer */
         {40080, 0, 0, 1, HOLDING},   /* Return Amperes to float */
         {40081, 0, 0, 1, HOLDING},   /* Return amps timer */
         {40082, 0, 0, 1, HOLDING},   /* Float voltage */
         {40083, 0, 0, 1, HOLDING},   /* Force boost charge */
         {40084, 0, 0, 1, HOLDING},   /* Return to bulk voltage from float */
         {40085, 0, 0, 1, HOLDING},   /* Return to bulk delay */
         {40087, 0, 0, 1, HOLDING},   /* Switchoff voltage without mains */
         {40090, 0, 0, 1, HOLDING},   /* Temperature compensation coefficient */
         {40092, 0, 0, 1, HOLDING},   /* Lifetest enable */
         {40093, 0, 0, 1, HOLDING},   /* Max alarm temp */
         {40094, 0, 0, 1, HOLDING},   /* Min alarm temp */
         {40097, 0, 0, 1, HOLDING},   /* Low battery threshold */
         {40034, 0, 0, 1, HOLDING},   /* Load output off duration after PC shutdown */
         {40065, 0, 0, 1, HOLDING},   /* History clear all */
         {40066, 0, 0, 1, HOLDING},   /* Factory settings */
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> register status values and masks added
         {40088, 0, 0, 1, HOLDING},   /* Backup Inhibit 0 = Backup allowed
                                                                        * 1 = Backup not allowed 0
                                                                        * */
         {40041, 0, 0, 1, HOLDING},   /* Force shutdown */
<<<<<<< HEAD
=======
         {40088, 0, 0, 1, HOLDING},   /* Backup Inhibit 0 = Backup allowed 1 = Backup not allowed 0 */
>>>>>>> under construction
=======
>>>>>>> register status values and masks added
         {40104, 0, 0, 1, HOLDING},   /* Time buffering */
         {40111, 0, 0, 1, HOLDING},   /* PC power supply removal delay */
         {40036, 0, 0, 1, HOLDING},   /* Low AC input voltage alarm threshold */
         {40037, 0, 0, 1, HOLDING},   /* High AC input voltage alarm threshold */
         {40107, 0, 0, 1, HOLDING},   /* Device switchoff delay */
         {40001, 0, 0, 1, HOLDING},   /* Address of slave unit */
         {40002, 0, 0, 1, HOLDING},   /* Baud rate for serial communication */
         {40003, 0, 0, 1, HOLDING},   /* Parity bit for serial communication */
         {40032, 0, 0, 1, HOLDING},   /* Battery status alarm */
         {40033, 0, 0, 1, HOLDING},   /* Battery State of Charge and State of Health */
         {40035, 0, 0, 1, HOLDING},   /* Battery voltage alarm */
         {40044, 0, 0, 1, HOLDING},   /* Battery temperature sensor failure */
         {40043, 0, 0, 1, HOLDING},   /* Device failure */
         {40047, 0, 0, 1, HOLDING},   /* On board temperature alarm */
         {40045, 0, 0, 1, HOLDING},   /* AC input voltage alarm */
<<<<<<< HEAD
<<<<<<< HEAD
         {40046, 0, 0, 1, HOLDING},   /* Mains status */
         {40038, 0, 0, 1, HOLDING}    /* Load alarm */
=======
         {40001, 0, 0, 1, HOLDING},     /* Address of slave unit */
         {40002, 0, 0, 1, HOLDING},     /* Baud rate for serial communication */
         {40003, 0, 0, 1, HOLDING},     /* Parity bit for serial communication */
         {40004, 0, 0, 1, HOLDING},
         {40005, 0, 0, 1, HOLDING},     /* Charging status */
         {40006, 0, 0, 1, HOLDING},     /* Power management
                                         * 0:Backup 1:Charging 2:boost 3:Not charging
                                         */
         {40007, 0, 0, 1, HOLDING},     /* Nominal output voltage */
         {40008, 0, 0, 1, HOLDING},     /* Battery voltage */
         {40009, 0, 0, 1, HOLDING},     /* Parameter map version ID */
         {40010, 0, 0, 1, HOLDING},     /* Software ID */
         {40011, 0, 0, 1, HOLDING},     /* Output load voltage */
         {40012, 0, 0, 1, HOLDING}, 
         {40013, 0, 0, 1, HOLDING}, 
         {40014, 0, 0, 1, HOLDING},     /* Battery charge current */
         {40015, 0, 0, 1, HOLDING}, 
         {40016, 0, 0, .1, HOLDING},    /* Battery capacity consumed */
         {40017, 0, 0, 1, HOLDING},     /* Battery discharge current */
         {40018, 0, 0, .1, HOLDING},    /* Effective battery capacity */
         {40019, 0, 0, 1, HOLDING},     /* Battery charge efficiency factor (CEF) */
         {40020, 0, 0, 1, HOLDING},     /* Output load current */
         {40021, 0, 0, 1, HOLDING},     /* Battery state-of-health */
         {40022, 0, 0, 1, HOLDING},     /* Time remaining to 100% discharge */
         {40023, 0, 0, .1, HOLDING},    /* Battery state-of-charge */
         {40024, 0, 0, 1, HOLDING},     /* Battery type currently selected */
         {40025, 0, 0, 1, HOLDING}, 
         {40026, 0, 0, 1, HOLDING},     /* Battery temperature in Kelvin units */
         {40027, 0, 0, 1, HOLDING},     /* Configuration mode */
         {40028, 0, 0, .1, HOLDING},    /* Battery net internal resistance */
         {40029, 0, 0, 1, HOLDING},     /* On-board temperature */
         {40030, 0, 0, 1, HOLDING},     /* AC input voltage */
         {40031, 0, 0, 1, HOLDING}, 
         {40032, 0, 0, 1, HOLDING},     /* Battery status alarm */
         {40033, 0, 0, 1, HOLDING},     /* Battery State of Charge and State of Health */
         {40034, 0, 0, 1, HOLDING},     /* Load output off duration after PC shutdown */
         {40035, 0, 0, 1, HOLDING},     /* Battery voltage alarm */
         {40036, 0, 0, 1, HOLDING},     /* Low AC input voltage alarm threshold */
         {40037, 0, 0, 1, HOLDING},     /* High AC input voltage alarm threshold */
         {40038, 0, 0, 1, HOLDING},     /* Load alarm */         
         {40039, 0, 0, 1, HOLDING},     /* Device variant */
         {40040, 0, 0, 1, HOLDING}, 
         {40041, 0, 0, 1, HOLDING},     /* Force shutdown */
         {40042, 0, 0, 1, HOLDING}, 
         {40043, 0, 0, 1, HOLDING},     /* Device failure */
         {40044, 0, 0, 1, HOLDING},     /* Battery temperature sensor failure */
         {40045, 0, 0, 1, HOLDING},     /* AC input voltage alarm */
         {40046, 0, 0, 1, HOLDING},     /* Mains status */
         {40047, 0, 0, 1, HOLDING},     /* On board temperature alarm */
         {40048, 0, 0, 1, HOLDING},     /* Number of charge cycles completed */
         {40049, 0, 0, 1, HOLDING},     /* Charge cycles not completed */
         {40050, 0, 0, .1, HOLDING},    /* Ah charged */
         {40051, 0, 0, 1, HOLDING},     /* Total run time */
         {40052, 0, 0, 1, HOLDING},     /* Number of low battery voltage events */
         {40053, 0, 0, 1, HOLDING},     /* Number of high battery voltage events */
         {40054, 0, 0, 1, HOLDING},     /* Number of low VAC events at mains input */
         {40055, 0, 0, 1, HOLDING},     /* Number of High VAC events at mains input */
         {40056, 0, 0, 1, HOLDING},     /* Number of over temperature inside events */
         {40057, 0, 0, 1, HOLDING},     /* Number of mains-backup transitions */
         {40058, 0, 0, 1, HOLDING},     /* Number power boost events */
         {40059, 0, 0, 1, HOLDING},     /* Highest battery voltage */
         {40060, 0, 0, 1, HOLDING},     /* Highest output load voltage */
         {40061, 0, 0, .1, HOLDING},    /* Maximum depth of discharge */
         {40062, 0, 0, 1, HOLDING},     /* Lowest battery voltage */
         {40063, 0, 0, 1, HOLDING},     /* Lowest output load voltage */
         {40064, 0, 0, .1, HOLDING},    /* Average depth of discharge */
         {40065, 0, 0, 1, HOLDING},     /* History clear all */
         {40066, 0, 0, 1, HOLDING},     /* Factory settings */
         {40067, 0, 0, 1, HOLDING},     /* Product name */
         {40068, 0, 0, 1, HOLDING}, 
         {40069, 0, 0, 1, HOLDING},     /* Reset internal battery model */         
         {40070, 0, 0, 1, HOLDING}, 
         {40071, 0, 0, 1, HOLDING},     /* Deep discharge battery prevention */
         {40072, 0, 0, 1, HOLDING},     /* Maximum charge current */
         {40073, 0, 0, 1, HOLDING},     /* Bulk voltage */
         {40074, 0, 0, 1, HOLDING},     /* Max bulk timer */
         {40075, 0, 0, 1, HOLDING},     /* Min bulk timer */
         {40076, 0, 0, 1, HOLDING},     
         {40077, 0, 0, 1, HOLDING},     /* Absorption voltage */
         {40078, 0, 0, 1, HOLDING},     /* Max absorption timer */
         {40079, 0, 0, 1, HOLDING},     /* Min absorption timer */
         {40080, 0, 0, 1, HOLDING},     /* Return Amperes to float */
         {40081, 0, 0, 1, HOLDING},     /* Return amps timer */
         {40082, 0, 0, 1, HOLDING},     /* Float voltage */
         {40083, 0, 0, 1, HOLDING},     /* Force boost charge */
         {40084, 0, 0, 1, HOLDING},     /* Return to bulk voltage from float */
         {40085, 0, 0, 1, HOLDING},     /* Return to bulk delay */
         {40086, 0, 0, 1, HOLDING},     
         {40087, 0, 0, 1, HOLDING},     /* Switchoff voltage without mains */
         {40088, 0, 0, 1, HOLDING},     /* Backup Inhibit 0 = Backup allowed
                                         *                1 = Backup not allowed
                                         */ 
         {40089, 0, 0, 1, HOLDING},     /* Number of battery cells */
         {40090, 0, 0, 1, HOLDING},     /* Temperature compensation coefficient */
         {40091, 0, 0, 1, HOLDING}, 
         {40092, 0, 0, 1, HOLDING},     /* Lifetest enable */
         {40093, 0, 0, 1, HOLDING},     /* Max alarm temp */
         {40094, 0, 0, 1, HOLDING},     /* Min alarm temp */
         {40095, 0, 0, 1, HOLDING}, 
         {40096, 0, 0, 1, HOLDING}, 
         {40097, 0, 0, 1, HOLDING},     /* Low battery threshold */         
         {40098, 0, 0, 1, HOLDING},     /* SoC/SoH test period */
         {40099, 0, 0, 1, HOLDING},     /* Manual SoC/SoH test request */
         {40100, 0, 0, 1, HOLDING},     /* SoC/SoH test possible */
         {40101, 0, 0, .1, HOLDING},    /* Nominal battery internal resistance */
         {40102, 0, 0, .1, HOLDING},    /* Nominal battery cables resistance */
         {40103, 0, 0, 1, HOLDING},     /* Firmware ID */
         {40104, 0, 0, 1, HOLDING},     /* Time buffering */
         {40105, 0, 0, .1, HOLDING},    /* Battery capacity C20 */
         {40106, 0, 0, .1, HOLDING},    /* Battery Capacity C10 */
         {40107, 0, 0, 1, HOLDING},     /* Device switchoff delay */
         {40108, 0, 0, .1, HOLDING},    /* Battery Capacity C5 */
         {40109, 0, 0, .1, HOLDING},    /* Battery Capacity C2 */
         {40110, 0, 0, 1, HOLDING},     
         {40111, 0, 0, 1, HOLDING},     /* PC power supply removal delay */
         {40112, 0, 0, .1, HOLDING},    /* Battery Capacity C1 */
         {40113, 0, 0, .1, HOLDING},    /* Low state-of-charge */
         {40114, 0, 0, 1, HOLDING},     
         {40115, 0, 0, 1, HOLDING}, 
         {40116, 0, 0, 1, HOLDING}, 
         {40117, 0, 0, 1, HOLDING}, 
         {40118, 0, 0, 1, HOLDING}, 
         {40119, 0, 0, 1, HOLDING}, 
         {40120, 0, 0, 1, HOLDING}      /* Zero-SoC reference */


>>>>>>> modify regs_data memory, devreg enum rearrangement
};
=======
         {40046, 0, 0, 1, HOLDING},   /* Input mains on / backup */
=======
         {40046, 0, 0, 1, HOLDING},   /* Mains status */
>>>>>>> register status values and masks added
         {40038, 0, 0, 1, HOLDING}    /* Load alarm */
};
<<<<<<< HEAD

#define NUMOF_REGS 14
#define NOTUSED -1

>>>>>>> under construction
=======
>>>>>>> structure device data, code get_dev_state, in progress
#endif /* ADELE_CBI_H */
