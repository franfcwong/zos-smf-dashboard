/* SPDX-License-Identifier: GPL-3.0-only or GPL-3.0-or-later */
/*
 * Smf70 Structures Header File.
 *
 * Copyright (C) 2025  Fran Wong <franwongau@gmail.com>.
 *
 * This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>
 */
#pragma pack(packed) nomargins nosequence

struct smf70hdr {
  union {
    unsigned char  _smf70hdc[36]; /* COMPLETE HEADER+PRODUCT SECTION TRIPL @WA05544 */
    struct {
      unsigned char  _smf70len[2]; /* RECORD LENGTH                     */
      unsigned char  _smf70seg[2]; /* SEGMENT DESCRIPTOR                */
      unsigned char  _smf70flg;    /* HEADER FLAG BYTE                  */
      unsigned char  _smf70rty;    /* RECORD TYPE                       */
      unsigned char  _smf70tme[4]; /* TOD RECORD WRITTEN                */
      unsigned char  _smf70dte[4]; /* DATE RECORD WRITTEN               */
      unsigned char  _smf70sid[4]; /* SYSTEM ID FROM INSTALLATION       */
      unsigned char  _smf70ssi[4]; /* SUBSYSTEM ID (RMF)                */
      unsigned char  _smf70sty[2]; /* SUBTYPE                           */
      unsigned char  _smf70trn[2]; /* NUMBER OF TRIPLETS IN THIS RECORD */
      unsigned char  _filler1[2];  /* RESERVED                          */
      unsigned char  _smf70prs[4]; /* OFFSET TO RMF PRODUCT SECTION     */
      unsigned char  _smf70prl[2]; /* LENGTH OF RMF PRODUCT SECTION     */
      unsigned char  _smf70prn[2]; /* NUMBER OF RMF PRODUCT SECTIONS    */
      } _smf70hdr_struct1;
    } _smf70hdr_union1;
  union {
    struct {
      unsigned char  _smf70ccs[4]; /* Offset to CPU Control section                   */
      unsigned char  _smf70ccl[2]; /* Length of CPU Control section                   */
      unsigned char  _smf70ccn[2]; /* Number of CPU Control sections                  */
      unsigned char  _smf70cps[4]; /* Offset to CPU Data section                      */
      unsigned char  _smf70cpl[2]; /* Length of CPU Data section                      */
      unsigned char  _smf70cpn[2]; /* Number of CPU Data sections                     */
      unsigned char  _smf70ass[4]; /* Offset to ASID Data section                     */
      unsigned char  _smf70asl[2]; /* Length of ASID Data section                     */
      unsigned char  _smf70asn[2]; /* Number of ASID Data sections                    */
      unsigned char  _smf70bcs[4]; /* Offset to PR/SM Partition data sections         */
      unsigned char  _smf70bcl[2]; /* Length of PR/SM Partition data section          */
      unsigned char  _smf70bcn[2]; /* Number of PR/SM Partition data sections         */
      unsigned char  _smf70bvs[4]; /* Offset to PR/SM Processor data sections         */
      unsigned char  _smf70bvl[2]; /* Length of PR/SM Processor data section          */
      unsigned char  _smf70bvn[2]; /* Number of PR/SM Processor data sections         */
      unsigned char  _smf70cns[4]; /* Offset to CPU-identification name section  @I1A */
      unsigned char  _smf70cnl[2]; /* Length of CPU-identification name section  @I1A */
      unsigned char  _smf70cnn[2]; /* Number of CPU-identification name sections @I1A */
      unsigned char  _smf70cos[4]; /* Offset to Logical Core data sections       @71A */
      unsigned char  _smf70col[2]; /* Length of Logical Core data section        @71A */
      unsigned char  _smf70con[2]; /* Number of Logical Core data sections       @71A */
      unsigned char  _smf70tns[4]; /* Offset to Tenant Resource Group sections   @91A */
      unsigned char  _smf70tnl[2]; /* Length of Tenant Resource Group section    @91A */
      unsigned char  _smf70tnn[2]; /* Number of Tenant Resource Group sections   @91A */
      } smf70hdx;
    struct {
      struct {
        unsigned char  _smf7023s[4]; /* Offset to crypto CCA coprocessor section        */
        unsigned char  _smf7023l[2]; /* Length of crypto CCA coprocessor section        */
        unsigned char  _smf7023n[2]; /* Number of crypto CCA coprocessor sections       */
        unsigned char  _smf7024s[4]; /* Offset to crypto accelerator section       @K1C */
        unsigned char  _smf7024l[2]; /* Length of crypto accelerator section       @K1C */
        unsigned char  _smf7024n[2]; /* Number of crypto accelerator section       @K1C */
        unsigned char  _smf702cs[4]; /* Offset to ICSF section                     @K1C */
        unsigned char  _smf702cl[2]; /* Length of ICSF section                     @K1C */
        unsigned char  _smf702cn[2]; /* Number of ICSF section                     @K1C */
        unsigned char  _smf7025s[4]; /* Offset to crypto PKCS11 coprocessor section     */
        unsigned char  _smf7025l[2]; /* Length of crypto PKCS11 coprocessor section     */
        unsigned char  _smf7025n[2]; /* Number of crypto PKCS11 coprocessor sections    */
        } smf702hx;
      unsigned char  _filler2[32];
      } _smf70hdr_struct2;
    } _smf70hdr_union2;

#define smf70hdc _smf70hdr_union1._smf70hdc
#define smf70len _smf70hdr_union1._smf70hdr_struct1._smf70len
#define smf70seg _smf70hdr_union1._smf70hdr_struct1._smf70seg
#define smf70flg _smf70hdr_union1._smf70hdr_struct1._smf70flg
#define smf70rty _smf70hdr_union1._smf70hdr_struct1._smf70rty
#define smf70tme _smf70hdr_union1._smf70hdr_struct1._smf70tme
#define smf70dte _smf70hdr_union1._smf70hdr_struct1._smf70dte
#define smf70sid _smf70hdr_union1._smf70hdr_struct1._smf70sid
#define smf70ssi _smf70hdr_union1._smf70hdr_struct1._smf70ssi
#define smf70sty _smf70hdr_union1._smf70hdr_struct1._smf70sty
#define smf70trn _smf70hdr_union1._smf70hdr_struct1._smf70trn
#define smf70prs _smf70hdr_union1._smf70hdr_struct1._smf70prs
#define smf70prl _smf70hdr_union1._smf70hdr_struct1._smf70prl
#define smf70prn _smf70hdr_union1._smf70hdr_struct1._smf70prn
#define smf70ccs _smf70hdr_union2.smf70hdx._smf70ccs
#define smf70ccl _smf70hdr_union2.smf70hdx._smf70ccl
#define smf70ccn _smf70hdr_union2.smf70hdx._smf70ccn
#define smf70cps _smf70hdr_union2.smf70hdx._smf70cps
#define smf70cpl _smf70hdr_union2.smf70hdx._smf70cpl
#define smf70cpn _smf70hdr_union2.smf70hdx._smf70cpn
#define smf70ass _smf70hdr_union2.smf70hdx._smf70ass
#define smf70asl _smf70hdr_union2.smf70hdx._smf70asl
#define smf70asn _smf70hdr_union2.smf70hdx._smf70asn
#define smf70bcs _smf70hdr_union2.smf70hdx._smf70bcs
#define smf70bcl _smf70hdr_union2.smf70hdx._smf70bcl
#define smf70bcn _smf70hdr_union2.smf70hdx._smf70bcn
#define smf70bvs _smf70hdr_union2.smf70hdx._smf70bvs
#define smf70bvl _smf70hdr_union2.smf70hdx._smf70bvl
#define smf70bvn _smf70hdr_union2.smf70hdx._smf70bvn
#define smf70cns _smf70hdr_union2.smf70hdx._smf70cns
#define smf70cnl _smf70hdr_union2.smf70hdx._smf70cnl
#define smf70cnn _smf70hdr_union2.smf70hdx._smf70cnn
#define smf70cos _smf70hdr_union2.smf70hdx._smf70cos
#define smf70col _smf70hdr_union2.smf70hdx._smf70col
#define smf70con _smf70hdr_union2.smf70hdx._smf70con
#define smf70tns _smf70hdr_union2.smf70hdx._smf70tns
#define smf70tnl _smf70hdr_union2.smf70hdx._smf70tnl
#define smf70tnn _smf70hdr_union2.smf70hdx._smf70tnn
#define smf7023s _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf7023s
#define smf7023l _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf7023l
#define smf7023n _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf7023n
#define smf7024s _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf7024s
#define smf7024l _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf7024l
#define smf7024n _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf7024n
#define smf702cs _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf702cs
#define smf702cl _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf702cl
#define smf702cn _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf702cn
#define smf7025s _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf7025s
#define smf7025l _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf7025l
#define smf7025n _smf70hdr_union2._smf70hdr_struct2.smf702hx._smf7025n
  };

/* Values for field "smf70flg" */
#define smf70rrf 0x80 /* NEW RECORD FORMAT                              */
#define smf70sut 0x40 /* SUBTYPES USED                             @R0A */
#define smf70v4  0x10 /* MVS/ESA Version 4                         @A1A */
#define smf70esa 0x08 /* MVS/ESA VERSION                           @W1A */
#define smf70vxa 0x04 /* MVS/XA VERSION                            @R0A */
#define smf70os  0x02 /* OPERATING SYSTEM IS OS/VS2                     */
#define smf70bfy 0x01 /* System running in PR/SM mode              @J1C */

struct smf70pro {
  unsigned char  smf70mfv[2]; /* RMF version number in PACKED decimal 'nnnF'     */
  unsigned char  smf70prd[8]; /* PRODUCT NAME                                    */
  unsigned char  smf70ist[4]; /* TOD MONITOR INTERVAL START: 0HHMMSSF            */
  unsigned char  smf70dat[4]; /* DATE MONITOR INTERVAL START: 00YYDDDF           */
  unsigned char  smf70int[4]; /* DURATION OF MONITOR INTERVAL: MMSSTTTF          */
  unsigned char  smf70mfl[2]; /* RESERVED                                   @J1C */
  unsigned char  smf70sam[4]; /* Number of RMF samples                           */
  unsigned char  smf70rv2[2]; /* RESERVED                                        */
  unsigned char  smf70fla[2]; /* Flags                                           */
  unsigned char  smf70rls[4]; /* RESERVED                                   @J1C */
  unsigned char  smf70cyc[4]; /* CYCLE IN PACKED DECIMAL 000TTTTF                */
  unsigned char  smf70mvs[8]; /* MVS software level (consists of an acronym @J1C */
  unsigned char  smf70iml;    /* Indicates the type of processor complex    @J1C */
  unsigned char  smf70prf;    /* Processor flags                            @P2A */
  unsigned char  smf70ptn;    /* PR/SM PARTITION NUMBER                     @Z1C */
  unsigned char  smf70srl;    /* SMF record level                       @YA28449 */
  unsigned char  smf70iet[8]; /* Interval expiration time token             @B1A */
  unsigned char  smf70lgo[8]; /* Offset GMT to local time                   @C1A */
  unsigned char  smf70rao[4]; /* Offset to reassembly area relative to      @C2A */
  unsigned char  smf70ral[2]; /* Length of reassembly area. Length depends  @C2A */
  unsigned char  smf70ran[2]; /* Number of reassembly area. This field is   @C2A */
  unsigned char  smf70oil[2]; /* Original interval length                   @C2A */
  unsigned char  smf70syn[2]; /* SYNC value in seconds                      @C2A */
  unsigned char  smf70gie[8]; /* Projected gathering interval end           @C2A */
  unsigned char  smf70xnm[8]; /* Sysplex name                               @C1A */
  unsigned char  smf70snm[8]; /* System name for current system             @C1A */
  };

/* Values for field "smf70fla" */
#define smf70cnv 0x80 /* DATA CONVERT.FROM VER.2                         */
#define smf70iss 0x40 /* INVALID SAMPLES TO BE SKIPPED              @Q1A */
#define smf70m3r 0x20 /* Record was written by RMF Monitor III      @B1A */
#define smf70ism 0x10 /* Interval was written under SMF control     @B1A */
#define smf70cbp 0x80 /* Reserved for future use                    @92C */
#define smf70iip 0x40 /* zIIP boost was active                      @93A */
#define smf70eed 0x20 /* Speed boost was active during              @93A */
#define smf70boo 0x07 /* Boost class is set at end of interval,    @A02C */
#define smf70brp 0x03 /* Boost class: 011 Recovery Process         @A02A */
#define smf70bsh 0x02 /* Boost class: 010 Shutdown                  @93A */
#define smf70bip 0x01 /* Boost class: 001 IPL                       @93A */

/* Values for field "smf70prf" */
#define smf70qes 0x80 /* System has expanded storage                @P2A */
#define smf70cne 0x40 /* Equipped with ESCON Channel                @Z1A */
#define smf70drc 0x20 /* ESCON Director in configuration            @Z1A */
#define smf70eme 0x10 /* System in z/ARCH mode                      @I1A */
#define smf70prx 0x08 /* Reserved for future use                    @92C */
#define smf70pri 0x08 /* At least one zAAP is currently installed   @92C */
#define smf70prp 0x04 /* At least one zIIP is currently installed   @22C */
#define smf70ped 0x02 /* Enhanced DAT facility 1 available          @81C */
#define smf70pe2 0x01 /* Enhanced DAT facility 2 available          @81A */

struct smf70rhd {
  unsigned char  smf70rbr[2]; /* Total number of broken records build from  @C2A */
  unsigned char  smf70rsq[2]; /* Sequence number of this broken record.     @C2A */
  unsigned char  smf70rio[4]; /* Offset to first reassembly information     @C2A */
  unsigned char  smf70ril[2]; /* Length of reassembly information block     @C2A */
  unsigned char  smf70rin[2]; /* Number of reassembly information blocks    @C2A */
  unsigned char  _filler1[4]; /* Reserved                                   @C2A */
  };

struct smf70rbl {
  unsigned char  smf70rnn[2]; /* Total number of sections in the original   @C2A */
  unsigned char  smf70rpp[2]; /* Position of the first of one or more       @C2A */
  };

struct smf70ctl {
  unsigned char  smf70mod[2];                /* CPU processor family                       @I2C */
  unsigned char  smf70ver;                   /* CPU version number                              */
  unsigned char  smf70bnp;                   /* Number of physical processors assigned for      */
  unsigned char  smf70inb;                   /* PR/SM indicator bits                            */
  unsigned char  smf70stf;                   /* Control section flags                      @I2C */
  unsigned char  smf70gts[2];                /* PR/SM - Dispatch interval                       */
  unsigned char  smf70mdl[16];               /* EBCDIC CPC model identifier.                    */
  unsigned char  smf70dsa[2];                /* Number of Diagnose samples                 @I3A */
  struct {
    unsigned char  _smf70ifa[2]; /* zAAPs (IFAs) online at the end of the */
    } smf70cbponl;
  unsigned char  smf70cpa[4];                /* Physical CPU adjustment factor based on         */
  unsigned char  smf70wla[4];                /* Millions of service units available to MVS      */
  unsigned char  smf70lac[4];                /* Long-term average CPU service in millions       */
  unsigned char  smf70hof[8];                /* Hypervisor date/time offset in STCK format      */
  unsigned char  smf70hwm[16];               /* EBCDIC CPC physical model identifier. Valid     */
  unsigned char  smf70sup[2];                /* zIIPs online at end of the interval    @OA13499 */
  unsigned char  smf70gjt[8];                /* Time in STCK format when the partition          */
  unsigned char  smf70pom[4];                /* EBCDIC plant code that identifies the plant     */
  unsigned char  smf70csc[16];               /* EBCDIC sequence code of the configuration.      */
  unsigned char  smf70hhf;                   /* Additional flags                       @OA24074 */
  unsigned char  smf70cr;                    /* ZEP field 0                            @OA29310 */
  int            smf70pmi;                   /* Accumulated number of blocked dispatchable      */
  int            smf70pmu;                   /* Number of blocked dispatchable units being      */
  int            smf70pmw;                   /* Accumulated number of address spaces and        */
  int            smf70pmp;                   /* Maximum number of address spaces and enclaves   */
  short int      smf70pmt;                   /* 1/1000s of the CPU capacity for promote         */
  short int      smf70pml;                   /* Swapped-in starvation threshold. When an        */
  unsigned char  smf70mpc[16];               /* When non-zero, EBCDIC model permanent           */
  unsigned char  smf70mtc[16];               /* When non-zero, EBCDIC model temporary           */
  int            smf70mcr;                   /* Model capacity rating. When non-zero,           */
  int            smf70mpr;                   /* Model permanent capacity rating. When           */
  int            smf70mtr;                   /* Model temporary capacity rating. When           */
  int            smf70zep;                   /* ZEP field 1                            @OA25078 */
  unsigned char  smf70zer[8];                /* ZEP field 2                            @OA25078 */
  unsigned char  smf70zee[8];                /* ZEP field 3                            @OA25078 */
  unsigned char  smf70zec[8];                /* ZEP field 4                            @OA25078 */
  int            smf70nrm;                   /* Normalization factor for zIIP. Multiply         */
  int            smf70gau;                   /* Long-term average of CPU service in millions    */
  unsigned char  smf70zei[8];                /* ZEP field 5                            @OA29310 */
  int            smf70ncr;                   /* Nominal model-capacity rating.                  */
  int            smf70npr;                   /* Nominal permanent model-capacity rating.        */
  int            smf70ntr;                   /* Nominal temporary model-capacity rating.        */
  unsigned char  smf70cai;                   /* Capacity-adjustment indication. When zero, the  */
  unsigned char  smf70ccr;                   /* Capacity-change reason.                         */
  short int      smf70mcp;                   /* Maximum CPU address available at this IPL  @62C */
  short int      smf70icp;                   /* Highest CPU Id installed at IPL time       @62A */
  short int      smf70ccp;                   /* Maximum CPU Id currently installed. This   @62A */
  unsigned char  smf70cpa_actual[4];
  unsigned char  smf70cpa_scaling_factor[4];
  int            smf70mcf;                   /* Multithreading maximum capacity numerator       */
  int            smf70mcfs;                  /* Multithreading maximum capacity numerator       */
  struct {
    int            _smf70mcfi; /* Multithreading maximum capacity numerator */
    } smf70mcfx;
  int            smf70cf;                    /* Multithreading capacity numerator for           */
  int            smf70cfs;                   /* Multithreading capacity numerator for zIIP.     */
  struct {
    int            _smf70cfi; /* Multithreading capacity numerator for zAAP. */
    } smf70cfx;
  int            smf70atd;                   /* Average Thread Density numerator for general    */
  int            smf70atds;                  /* Average Thread Density numerator for zIIP.      */
  struct {
    int            _smf70atdi; /* Average Thread Density numerator for zAAP. */
    } smf70atdx;
  unsigned char  smf70lacm[4];               /* Long-term average CPU service (millions         */
  unsigned char  smf70laca[4];               /* Long-term average CPU service (millions         */
  unsigned char  smf70lacb[4];               /* Long-term average CPU service (millions         */
  unsigned char  smf70adj[4];                /* Logical adjustment factor for CPU rate.    @91A */
  unsigned char  smf70laccr[4];              /* Long-term average of CPU service (millions      */
  short int      smf70maxpu;                 /* When non-zero, this field indicates how many    */
  unsigned char  smf70os_prtct;              /* When non-zero, OSPROTECT system parameter with  */
  unsigned char  _filler1;                   /* Reserved                                   @94C */
  unsigned char  smf70mdl_cbp[16];           /* Reserved for future use                    @98C */
  int            smf70mcr_cbp;               /* Reserved for future use                    @98C */
  int            smf70ncr_cbp;               /* Reserved for future use                    @98C */
  unsigned char  smf70lac_cbp[4];            /* Reserved for future use                    @98C */
  unsigned char  smf70cpa_actual_cbp[4];     /* Reserved for future use             @98C        */
  unsigned char  smf70_ipl_time[8];          /* IPL time of partition (TOD format).        @96A */
  unsigned char  smf70_trg_m_cnt[4];         /* Number of times sampling of tenant resource     */
  unsigned char  smf70crw[4];                /* Reserved for IBM internal use only         @96A */
  unsigned char  smf70cpc_type[4];           /* CPC Type                                   @95A */

#define smf70ifa  smf70cbponl._smf70ifa
#define smf70mcfi smf70mcfx._smf70mcfi
#define smf70cfi  smf70cfx._smf70cfi
#define smf70atdi smf70atdx._smf70atdi
  };

/* Values for field "smf70inb" */
#define smf70dif 0x80 /* PR/SM - Diagnose X'204' failure                 */
#define smf70npc 0x40 /* PR/SM - Number of phys procrs has changed       */
#define smf70tsc 0x20 /* PR/SM - Dispatch interval value changed         */
#define smf70phy 0x10 /* PR/SM - An additional partition is presented    */
#define smf70dge 0x08 /* PR/SM - Diagnose X'204' extended data is        */
#define smf70vmg 0x04 /* Simplified Diagnose X'204' data provided for    */

/* Values for field "smf70stf" */
#define smf70sts 0x80 /* Store-system-information facility          @I2A */
#define smf70adc 0x40 /* Physical CPU adjustment factor changed @WA46477 */
#define smf70wuc 0x20 /* Service units available to MVS image            */
#define smf70rcu 0x10 /* SMF70LAC is provided for systems running        */
#define smf70hwv 0x08 /* SMF70MDL is the model-capacity identifier       */
#define smf70ptc 0x04 /* CP promote slices (OPT parameter BLWLTRPCT)     */
#define smf70plc 0x02 /* Swapped-in starvation threshold                 */
#define smf70gav 0x01 /* SMF70GAU is valid                          @34A */

/* Values for field "smf70hhf" */
#define smf70hhs 0x80 /* HiperDispatch supported                @OA24074 */
#define smf70hha 0x40 /* HiperDispatch is active                @OA24074 */
#define smf70hhc 0x20 /* HiperDispatch status changed during             */
#define smf70hif 0x10 /* Failure returned by HisMT service.              */
#define smf70ham 0x08 /* Absolute MSU capping is active             @81A */
#define smf70hop 0x04 /* SMF70OS_PRTCT is valid                     @94A */

struct smf70cpu {
  unsigned char  smf70wat[8]; /* CPU wait time, where bit 51 = 1 microsecond     */
  unsigned char  smf70cid[2]; /* CPU identification                              */
  unsigned char  smf70cnf;    /* Configuration activity indicator                */
  unsigned char  smf70rv3;    /* Reserved                                        */
  unsigned char  smf70ser[3]; /* CPU serial number (6 hexadecimal digits)        */
  unsigned char  smf70typ;    /* CPU type                                        */
  unsigned char  smf70slh[4]; /* Number of entries to the I/O SLIH               */
  unsigned char  smf70tpi[4]; /* Number of TPI with CC=1                         */
  unsigned char  smf70vfs[4]; /* Number of samples when the vector bit           */
  unsigned char  smf70v;      /* Vector configuration                            */
  unsigned char  smf70cpm[3]; /* Reserved                                   @I2C */
  unsigned char  smf70pat[8]; /* CPU parked time, bit 51 = 1 microsecond    @11C */
  unsigned char  smf70tcb[8]; /* Number of TCB dispatches for this CPU      @32A */
  unsigned char  smf70srb[8]; /* Number of SRB dispatches for this CPU      @32A */
  unsigned char  smf70nio[8]; /* Number of I/Os for this CPU                @32A */
  unsigned char  smf70sig[8]; /* Total number of SIGPs for this CPU     @OA29820 */
  unsigned char  smf70wtd[8]; /* Wait dispatch count for this CPU           @41A */
  unsigned char  smf70wts[4]; /* The number of times PR/SM issued a warning-     */
  unsigned char  smf70wtu[4]; /* The number of times PR/SM issued a warning-     */
  unsigned char  smf70wti[4]; /* Amount of time in milliseconds that a logical   */
  };

/* Values for field "smf70cnf" */
#define smf70mti 16   /* CPU is offline while core is online        @71A */
#define smf70dci 8    /* Data available for a complete interval @WA27840 */
#define smf70par 4    /* CPU was varied during Postprocessor             */
#define smf70vac 2    /* Data invalid, CPU varied on or offline          */
#define smf70sta 1    /* CPU is online at end of interval                */

/* Values for field "smf70v" */
#define smf70von 0x80 /* Vector was online                               */

/* Values for field "smf70wti" */
#define smf70tcp 0    /* General purpose CP                         @K2A */
#define smf70tif 1    /* zAAP (IFA)                                 @K2A */
#define smf70tsu 2    /* zIIP                                   @OA13499 */

struct smf70aid {
  short int      smf70rmn; /* READY MINIMUM VALUE OVER INTERVAL               */
  short int      smf70rmm; /* READY MAXIMUM VALUE OVER INTERVAL               */
  int            smf70rtt; /* READY TOTAL VALUE OVER INTERVAL                 */
  int            smf70r00; /* COUNT OF TIMES READY VALUE WAS 0                */
  int            smf70r01; /* COUNT OF TIMES READY VALUE WAS 1                */
  int            smf70r02; /* COUNT OF TIMES READY VALUE WAS 2                */
  int            smf70r03; /* COUNT OF TIMES READY VALUE WAS 3                */
  int            smf70r04; /* COUNT OF TIMES READY VALUE WAS 4                */
  int            smf70r05; /* COUNT OF TIMES READY VALUE WAS 5                */
  int            smf70r06; /* COUNT OF TIMES READY VALUE WAS 6                */
  int            smf70r07; /* COUNT OF TIMES READY VALUE WAS 7                */
  int            smf70r08; /* COUNT OF TIMES READY VALUE WAS 8                */
  int            smf70r09; /* COUNT OF TIMES READY VALUE WAS 9                */
  int            smf70r10; /* COUNT OF TIMES READY VALUE WAS 10               */
  int            smf70r11; /* COUNT OF TIMES READY VALUE WAS 11               */
  int            smf70r12; /* COUNT OF TIMES READY VALUE WAS 12               */
  int            smf70r13; /* COUNT OF TIMES READY VALUE WAS 13               */
  int            smf70r14; /* COUNT OF TIMES READY VALUE WAS 14               */
  int            smf70r15; /* COUNT OF TIMES READY VALUE WAS 14+              */
  short int      smf70imn; /* IN USERS MINIMUM OVER INTERVAL                  */
  short int      smf70imm; /* IN USERS MAXIMUM OVER INTERVAL                  */
  int            smf70itt; /* IN USERS TOTAL VALUE OVER INTERVAL              */
  int            smf70i00; /* COUNT OF TIMES IN USERS WAS 0                   */
  int            smf70i01; /* COUNT OF TIMES IN USERS WAS 1-2                 */
  int            smf70i02; /* COUNT OF TIMES IN USERS WAS 3-4                 */
  int            smf70i03; /* COUNT OF TIMES IN USERS WAS 5-6                 */
  int            smf70i04; /* COUNT OF TIMES IN USERS WAS 7-8                 */
  int            smf70i05; /* COUNT OF TIMES IN USERS WAS 9-10                */
  int            smf70i06; /* COUNT OF TIMES IN USERS WAS 11-15               */
  int            smf70i07; /* COUNT OF TIMES IN USERS WAS 16-20               */
  int            smf70i08; /* COUNT OF TIMES IN USERS WAS 21-25               */
  int            smf70i09; /* COUNT OF TIMES IN USERS WAS 26-30               */
  int            smf70i10; /* COUNT OF TIMES IN USERS WAS 31-35               */
  int            smf70i11; /* COUNT OF TIMES IN USERS WAS 35+                 */
  short int      smf70omn; /* OUT USERS MINIMUM OVER INTERVAL                 */
  short int      smf70omm; /* OUT USERS MAXIMUM OVER INTERVAL                 */
  int            smf70ott; /* OUT USERS TOTAL VALUE OVER INTERVAL             */
  int            smf70o00; /* COUNT OF TIMES OUT USERS WAS 0                  */
  int            smf70o01; /* COUNT OF TIMES OUT USERS WAS 1-2                */
  int            smf70o02; /* COUNT OF TIMES OUT USERS WAS 3-4                */
  int            smf70o03; /* COUNT OF TIMES OUT USERS WAS 5-6                */
  int            smf70o04; /* COUNT OF TIMES OUT USERS WAS 7-8                */
  int            smf70o05; /* COUNT OF TIMES OUT USERS WAS 9-10               */
  int            smf70o06; /* COUNT OF TIMES OUT USERS WAS 11-15              */
  int            smf70o07; /* COUNT OF TIMES OUT USERS WAS 16-20              */
  int            smf70o08; /* COUNT OF TIMES OUT USERS WAS 21-25              */
  int            smf70o09; /* COUNT OF TIMES OUT USERS WAS 26-30              */
  int            smf70o10; /* COUNT OF TIMES OUT USERS WAS 31-35              */
  int            smf70o11; /* COUNT OF TIMES OUT USERS WAS 35+                */
  short int      smf70wmn; /* WAIT USERS MINIMUM OVER INTERVAL                */
  short int      smf70wmm; /* WAIT USERS MAXIMUM OVER INTERVAL                */
  int            smf70wtt; /* WAIT USERS TOTAL VALUE OVER INTERVAL            */
  int            smf70w00; /* COUNT OF TIMES WAIT USERS WAS 0                 */
  int            smf70w01; /* COUNT OF TIMES WAIT USERS WAS 1-2               */
  int            smf70w02; /* COUNT OF TIMES WAIT USERS WAS 3-4               */
  int            smf70w03; /* COUNT OF TIMES WAIT USERS WAS 5-6               */
  int            smf70w04; /* COUNT OF TIMES WAIT USERS WAS 7-8               */
  int            smf70w05; /* COUNT OF TIMES WAIT USERS WAS 9-10              */
  int            smf70w06; /* COUNT OF TIMES WAIT USERS WAS 11-15             */
  int            smf70w07; /* COUNT OF TIMES WAIT USERS WAS 16-20             */
  int            smf70w08; /* COUNT OF TIMES WAIT USERS WAS 21-25             */
  int            smf70w09; /* COUNT OF TIMES WAIT USERS WAS 26-30             */
  int            smf70w10; /* COUNT OF TIMES WAIT USERS WAS 31-35             */
  int            smf70w11; /* COUNT OF TIMES WAIT USERS WAS 35+               */
  short int      smf70bmn; /* BATCH USERS MINIMUM OVER INTERVAL               */
  short int      smf70bmm; /* BATCH USERS MAXIMUM OVER INTERVAL               */
  int            smf70btt; /* BATCH USERS TOTAL VALUE OVER INTERVAL           */
  int            smf70b00; /* COUNT OF TIMES BATCH USERS WAS 0                */
  int            smf70b01; /* COUNT OF TIMES BATCH USERS WAS 1-2              */
  int            smf70b02; /* COUNT OF TIMES BATCH USERS WAS 3-4              */
  int            smf70b03; /* COUNT OF TIMES BATCH USERS WAS 5-6              */
  int            smf70b04; /* COUNT OF TIMES BATCH USERS WAS 7-8              */
  int            smf70b05; /* COUNT OF TIMES BATCH USERS WAS 9-10             */
  int            smf70b06; /* COUNT OF TIMES BATCH USERS WAS 11-15            */
  int            smf70b07; /* COUNT OF TIMES BATCH USERS WAS 16-20            */
  int            smf70b08; /* COUNT OF TIMES BATCH USERS WAS 21-25            */
  int            smf70b09; /* COUNT OF TIMES BATCH USERS WAS 26-30            */
  int            smf70b10; /* COUNT OF TIMES BATCH USERS WAS 31-35            */
  int            smf70b11; /* COUNT OF TIMES BATCH USERS WAS 35+              */
  short int      smf70smn; /* STARTED USERS MINIMUM OVER INTERVAL             */
  short int      smf70smm; /* STARTED USERS MAXIMUM OVER INTERVAL             */
  int            smf70stt; /* STARTED USERS TOTAL VALUE OVER INTERVAL         */
  int            smf70s00; /* COUNT OF TIMES STARTED USERS WAS 0              */
  int            smf70s01; /* COUNT OF TIMES STARTED USERS WAS 1-2            */
  int            smf70s02; /* COUNT OF TIMES STARTED USERS WAS 3-4            */
  int            smf70s03; /* COUNT OF TIMES STARTED USERS WAS 5-6            */
  int            smf70s04; /* COUNT OF TIMES STARTED USERS WAS 7-8            */
  int            smf70s05; /* COUNT OF TIMES STARTED USERS WAS 9-10           */
  int            smf70s06; /* COUNT OF TIMES STARTED USERS WAS 11-15          */
  int            smf70s07; /* COUNT OF TIMES STARTED USERS WAS 16-20          */
  int            smf70s08; /* COUNT OF TIMES STARTED USERS WAS 21-25          */
  int            smf70s09; /* COUNT OF TIMES STARTED USERS WAS 26-30          */
  int            smf70s10; /* COUNT OF TIMES STARTED USERS WAS 31-35          */
  int            smf70s11; /* COUNT OF TIMES STARTED USERS WAS 35+            */
  short int      smf70tmn; /* TSO USERS MINIMUM OVER INTERVAL                 */
  short int      smf70tmm; /* TSO USERS MAXIMUM OVER INTERVAL                 */
  int            smf70ttt; /* TSO USERS TOTAL VALUE OVER INTERVAL             */
  int            smf70t00; /* COUNT OF TIMES TSO USERS WAS 0                  */
  int            smf70t01; /* COUNT OF TIMES TSO USERS WAS 1-2                */
  int            smf70t02; /* COUNT OF TIMES TSO USERS WAS 3-4                */
  int            smf70t03; /* COUNT OF TIMES TSO USERS WAS 5-6                */
  int            smf70t04; /* COUNT OF TIMES TSO USERS WAS 7-8                */
  int            smf70t05; /* COUNT OF TIMES TSO USERS WAS 9-10               */
  int            smf70t06; /* COUNT OF TIMES TSO USERS WAS 11-15              */
  int            smf70t07; /* COUNT OF TIMES TSO USERS WAS 16-20              */
  int            smf70t08; /* COUNT OF TIMES TSO USERS WAS 21-25              */
  int            smf70t09; /* COUNT OF TIMES TSO USERS WAS 26-30              */
  int            smf70t10; /* COUNT OF TIMES TSO USERS WAS 31-35              */
  int            smf70t11; /* COUNT OF TIMES TSO USERS WAS 35+                */
  short int      smf70lmn; /* LOGICAL RDY USERS MINIMUM                       */
  short int      smf70lmm; /* LOGICAL RDY USERS MAXIMUM                       */
  int            smf70ltt; /* LOGICAL RDY USERS TOTAL                         */
  int            smf70l00; /* COUNT OF TIMES LOGICAL RDY USERS WAS 0          */
  int            smf70l01; /* COUNT OF TIMES LOGICAL RDY USERS WAS 1-2        */
  int            smf70l02; /* COUNT OF TIMES LOGICAL RDY USERS WAS 3-4        */
  int            smf70l03; /* COUNT OF TIMES LOGICAL RDY USERS WAS 5-6        */
  int            smf70l04; /* COUNT OF TIMES LOGICAL RDY USERS WAS 7-8        */
  int            smf70l05; /* COUNT OF TIMES LOGICAL RDY USERS WAS 9-10       */
  int            smf70l06; /* COUNT OF TIMES LOGICAL RDY USERS WAS 11-15      */
  int            smf70l07; /* COUNT OF TIMES LOGICAL RDY USERS WAS 16-20      */
  int            smf70l08; /* COUNT OF TIMES LOGICAL RDY USERS WAS 21-25      */
  int            smf70l09; /* COUNT OF TIMES LOGICAL RDY USERS WAS 26-30      */
  int            smf70l10; /* COUNT OF TIMES LOGICAL RDY USERS WAS 31-35      */
  int            smf70l11; /* COUNT OF TIMES LOGICAL RDY USERS WAS 35+        */
  short int      smf70amn; /* LOGICAL WAIT USERS MINIMUM                      */
  short int      smf70amm; /* LOGICAL WAIT USERS MAXIMUM                      */
  int            smf70att; /* LOGICAL WAIT USERS TOTAL                        */
  int            smf70a00; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 0         */
  int            smf70a01; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 1-2       */
  int            smf70a02; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 3-4       */
  int            smf70a03; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 5-6       */
  int            smf70a04; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 7-8       */
  int            smf70a05; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 9-10      */
  int            smf70a06; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 11-15     */
  int            smf70a07; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 16-20     */
  int            smf70a08; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 21-25     */
  int            smf70a09; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 26-30     */
  int            smf70a10; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 31-35     */
  int            smf70a11; /* COUNT OF TIMES LOGICAL WAIT USERS WAS 35+       */
  short int      smf70pmn; /* ASCH USERS MINIMUM                              */
  short int      smf70pmm; /* ASCH USERS MAXIMUM                              */
  int            smf70ptt; /* ASCH USERS TOTAL                                */
  int            smf70p00; /* COUNT OF TIMES ASCH USERS WAS 0                 */
  int            smf70p01; /* COUNT OF TIMES ASCH USERS WAS 1-2               */
  int            smf70p02; /* COUNT OF TIMES ASCH USERS WAS 3-4               */
  int            smf70p03; /* COUNT OF TIMES ASCH USERS WAS 5-6               */
  int            smf70p04; /* COUNT OF TIMES ASCH USERS WAS 7-8               */
  int            smf70p05; /* COUNT OF TIMES ASCH USERS WAS 9-10              */
  int            smf70p06; /* COUNT OF TIMES ASCH USERS WAS 11-15             */
  int            smf70p07; /* COUNT OF TIMES ASCH USERS WAS 16-20             */
  int            smf70p08; /* COUNT OF TIMES ASCH USERS WAS 21-25             */
  int            smf70p09; /* COUNT OF TIMES ASCH USERS WAS 26-30             */
  int            smf70p10; /* COUNT OF TIMES ASCH USERS WAS 31-35             */
  int            smf70p11; /* COUNT OF TIMES ASCH USERS WAS 35+               */
  short int      smf70xmn; /* OMVS USERS MINIMUM                              */
  short int      smf70xmm; /* OMVS USERS MAXIMUM                              */
  int            smf70xtt; /* OMVS USERS TOTAL                                */
  int            smf70x00; /* COUNT OF TIMES OMVS USERS WAS 0                 */
  int            smf70x01; /* COUNT OF TIMES OMVS USERS WAS 1-2               */
  int            smf70x02; /* COUNT OF TIMES OMVS USERS WAS 3-4               */
  int            smf70x03; /* COUNT OF TIMES OMVS USERS WAS 5-6               */
  int            smf70x04; /* COUNT OF TIMES OMVS USERS WAS 7-8               */
  int            smf70x05; /* COUNT OF TIMES OMVS USERS WAS 9-10              */
  int            smf70x06; /* COUNT OF TIMES OMVS USERS WAS 11-15             */
  int            smf70x07; /* COUNT OF TIMES OMVS USERS WAS 16-20             */
  int            smf70x08; /* COUNT OF TIMES OMVS USERS WAS 21-25             */
  int            smf70x09; /* COUNT OF TIMES OMVS USERS WAS 26-30             */
  int            smf70x10; /* COUNT OF TIMES OMVS USERS WAS 31-35             */
  int            smf70x11; /* COUNT OF TIMES OMVS USERS WAS 35+               */
  int            smf70q00; /* Count of times In Ready was <= N while N is     */
  int            smf70q01; /* Count of times In Ready was N+1            @L2A */
  int            smf70q02; /* Count of times In Ready was N+2            @L2A */
  int            smf70q03; /* Count of times In Ready was N+3            @L2A */
  int            smf70q04; /* Count of times In Ready was N+4 or N+5     @L2A */
  int            smf70q05; /* Count of times In Ready was N+6 to N+10    @L2A */
  int            smf70q06; /* Count of times In Ready was N+11 to N+15   @L2A */
  int            smf70q07; /* Count of times In Ready was N+16 to N+20   @L2A */
  int            smf70q08; /* Count of times In Ready was N+21 to N+30   @L2A */
  int            smf70q09; /* Count of times In Ready was N+31 to N+40   @L2A */
  int            smf70q10; /* Count of times In Ready was N+41 to N+60   @L2A */
  int            smf70q11; /* Count of times In Ready was N+61 to N+80   @L2A */
  int            smf70q12; /* Count of times In Ready was > N+80         @L2A */
  int            smf70srm; /* Number of SRM samples for WEB calculation  @41A */
  int            smf70cmn; /* General purpose processors minimum         @41A */
  int            smf70cmm; /* General purpose processors maximum         @41A */
  int            smf70ctt; /* General purpose processors total           @41A */
  int            smf70dmn; /* zAAP processor minimum                     @98C */
  int            smf70dmm; /* zAAP processor maximum                     @98C */
  int            smf70dtt; /* zAAP processor total                       @98C */
  int            smf70emn; /* IIP processors minimum                     @41A */
  int            smf70emm; /* IIP processors maximum                     @41A */
  int            smf70ett; /* IIP processors total                       @41A */
  int            smf70u00; /* Count of times the number of work units         */
  int            smf70u01; /* Count of times the number of work units         */
  int            smf70u02; /* Count of times the number of work units         */
  int            smf70u03; /* Count of times the number of work units         */
  int            smf70u04; /* Count of times the number of work units         */
  int            smf70u05; /* Count of times the number of work units         */
  int            smf70u06; /* Count of times the number of work units         */
  int            smf70u07; /* Count of times the number of work units         */
  int            smf70u08; /* Count of times the number of work units         */
  int            smf70u09; /* Count of times the number of work units         */
  int            smf70u10; /* Count of times the number of work units         */
  int            smf70u11; /* Count of times the number of work units         */
  int            smf70u12; /* Count of times the number of work units         */
  int            smf70u13; /* Count of times the number of work units         */
  int            smf70u14; /* Count of times the number of work units         */
  int            smf70u15; /* Count of times the number of work units         */
  };

struct smf70bct {
  struct {
    unsigned char  _smf70lpm[8];       /* Logical Partition name                          */
    unsigned char  _smf70lpn;          /* Logical Partition number                        */
    unsigned char  _smf70pfg;          /* Partition flags                                 */
    unsigned char  _smf70bdn[2];       /* Number of logical CPUs assigned to this         */
    unsigned char  _smf70bds[4];       /* Start of data section block number              */
    unsigned char  _smf70bda[4];       /* Accumulated number of logical CPUs active for   */
    unsigned char  _smf70spn[8];       /* Name of the logical-partition cluster. Zeros    */
    unsigned char  _smf70stn[8];       /* Name of the operating-system instance. Zeros    */
    unsigned char  _filler1[4];        /* Reserved                                   @I3A */
    unsigned char  _smf70csf[4];       /* Number of megabytes of central storage          */
    unsigned char  _filler2[4];        /* Reserved                                   @I3A */
    unsigned char  _smf70esf[4];       /* Number of megabytes of expanded storage         */
    unsigned char  _smf70msu[4];       /* Defined capacity limit (in millions             */
    unsigned char  _smf70pfl[2];       /* Additional partition flags             @OA10346 */
    unsigned char  _smf70upi;          /* User partition ID. Valid if bit 0          @33C */
    unsigned char  _smf70mtid;         /* Maximum Thread Identification                   */
    unsigned char  _smf70gnm[8];       /* Name of the capacity group this partition       */
    unsigned char  _smf70gmu[4];       /* Group maximum licensing units.                  */
    unsigned char  _smf70hwgr_name[8];
    } smf70bpc;
  unsigned char  smf70_boostinfo; /* Boost information                @9BA           */
  unsigned char  _filler3[3];     /* Reserved                                   @9BA */

#define smf70lpm       smf70bpc._smf70lpm
#define smf70lpn       smf70bpc._smf70lpn
#define smf70pfg       smf70bpc._smf70pfg
#define smf70bdn       smf70bpc._smf70bdn
#define smf70bds       smf70bpc._smf70bds
#define smf70bda       smf70bpc._smf70bda
#define smf70spn       smf70bpc._smf70spn
#define smf70stn       smf70bpc._smf70stn
#define smf70csf       smf70bpc._smf70csf
#define smf70esf       smf70bpc._smf70esf
#define smf70msu       smf70bpc._smf70msu
#define smf70pfl       smf70bpc._smf70pfl
#define smf70upi       smf70bpc._smf70upi
#define smf70mtid      smf70bpc._smf70mtid
#define smf70gnm       smf70bpc._smf70gnm
#define smf70gmu       smf70bpc._smf70gmu
#define smf70hwgr_name smf70bpc._smf70hwgr_name
  };

/* Values for field "smf70pfg" */
#define smf70pdv              0x80   /* Partition deactivated during interval           */
#define smf70nvc              0x40   /* Number of logical procrs has changed            */
#define smf70ndc              0x20   /* Number of dedicated procrs has changed     @H1A */
#define smf70nsc              0x10   /* Number of shared procrs has changed        @H1A */
#define smf70wlm              0x08   /* WLM LPAR Management is active for this          */
#define smf70wtf              0x04   /* Wait Time field is defined             @WA46477 */
#define smf70msc              0x02   /* Defined capacity limit has been changed    @K2C */
#define smf70msf              0x01   /* No longer used                             @L4C */

/* Values for field "smf70pfl" */
#define smf70uvf              0x8000 /* Content of SMF70UPI is valid           @OA10346 */
#define smf70grp              0x4000 /* Group flag. This partition is member            */
#define smf70pwf              0x2000 /* Polarization flag. This partition is            */
#define smf70uiw              0x1000 /* Initial weight instead of current weight        */

/* Values for field "smf70_boostinfo" */
#define smf70_boostinfo_ziip  0x80   /* zIIP boost was active            @9BA           */
#define smf70_boostinfo_speed 0x40   /* Speed boost was active at some   @9BA           */

struct smf70bpd {
  unsigned char  smf70pdt[8];            /* Logical processor total dispatch time,           */
  unsigned char  smf70vpa[2];            /* Logical processor address                        */
  unsigned char  smf70bps[2];            /* Processor relative share                         */
  unsigned char  smf70vpf;               /* Logical processor flags                          */
  unsigned char  smf70pof;               /* Polarization flags                      @OA21140 */
  unsigned char  smf70cix[2];            /* Index to the CPU-identification name section     */
  unsigned char  smf70edt[8];            /* Logical processor effective dispatch time,       */
  unsigned char  smf70acs[4];            /* Accumulated processor actual share      @WA46477 */
  unsigned char  smf70mis[2];            /* Processor minimum share                     @I3A */
  unsigned char  smf70mas[2];            /* Processor maximum share                     @I3A */
  unsigned char  smf70nsi[4];            /* Number of Diagnose samples within the            */
  unsigned char  smf70nsa[4];            /* Number of Diagnose samples within the            */
  unsigned char  smf70ont[8];            /* Logical processor online time               @I3A */
  unsigned char  smf70wst[8];            /* Logical processor wait state time           @I3A */
  unsigned char  smf70pma[4];            /* Average pricing management adjustment weight     */
  unsigned char  smf70nsw[4];            /* Number of Diagnose samples where WLM             */
  unsigned char  smf70pow[4];            /* Weight for the logical CPU when HiperDispatch    */
  int            smf70nca;               /* Number of Diagnose samples where capping         */
  unsigned char  smf70hw_cap_limit[4];
  unsigned char  smf70hwgr_cap_limit[4]; /* @81C                                             */
  unsigned char  smf70mtit[8];           /* Multithreading Idle Time in microseconds         */
  };

/* Values for field "smf70vpf" */
#define smf70wsa 0x80 /* Wait Completion state enabled                    */
#define smf70wsc 0x40 /* Wait Completion state changed during interval    */
#define smf70rsc 0x20 /* Relative share changed during interval           */
#define smf70cap 0x10 /* 'Initial Capping' was set to 'ON' on        @66C */
#define smf70cpc 0x08 /* 'Initial Capping' status has changed        @66C */
#define smf70lpo 0x04 /* Logical processor varied online during           */
#define smf70hcc 0x02 /* SMF70HW_Cap_Limit has changed during        @66A */
#define smf70hgc 0x01 /* SMF70HWGr_Name or SMF70HWGr_Cap_Limit has   @81A */

/* Values for field "smf70pof" */
#define smf70poi 0xC0 /* Polarization indicator (2 bits)         @OA21140 */
#define smf70poc 0x20 /* Polarization indication changed during  @OA21140 */

struct smf70cis {
  unsigned char  smf70cin[16]; /* CPU-identification name                     @I1A */
  unsigned char  smf70ctn[2];  /* Number of physical CPUs of this type             */
  unsigned char  _filler1[2];  /* Reserved                                @OA13499 */
  int            smf70can;     /* Accumulated number of physical CPUs.             */
  };

struct smf70lcs {
  short int      smf70_core_id;   /* Core identification                        @71A */
  unsigned char  smf70_core_flg;  /* Logical Core Information                   @71A */
  unsigned char  _filler1;        /* Reserved                                   @71A */
  short int      smf70_cpu_skip;  /* The CPU data sections for this core are grouped */
  short int      smf70_cpu_num;   /* Number of CPU data sections for this core.      */
  int            smf70_prod;      /* Multithreading core productivity numerator.     */
  int            smf70_lpar_busy; /* Multithreading Core LPAR Busy time in           */
  };

/* Values for field "smf70_core_flg" */
#define smf70_lpb_valid 0x80 /* Multithreading Core LPAR Busy Time valid @71A */

struct smf70tnt {
  unsigned char  smf70_trg_name[8];     /* Tenant resource group name.                @91A */
  unsigned char  smf70_trg_desc[32];    /* Tenant resource group description.         @91A */
  unsigned char  smf70_trg_tntid[8];    /* Tenant identifier.                         @91A */
  unsigned char  smf70_trg_tntname[32]; /* Tenant name.                             @91A   */
  unsigned char  smf70_trg_sbid[64];    /* Solution identifier.                     @91A   */
  unsigned char  smf70_trg_sucp[8];     /* Unweighted service units on CPs consumed by     */
  struct {
    unsigned char  _smf70_trg_suifa[8]; /* Unweighted service units on zAAPs consumed by */
    } smf70_trg_sucbp;
  unsigned char  smf70_trg_susup[8];    /* Unweighted service units on zIIPs consumed by   */
  unsigned char  smf70_trg_lac[4];      /* Long-term average service on general purpose    */
  unsigned char  smf70_trg_lac_cbp[4];  /* Reserved for future use               @98C      */
  unsigned char  smf70_trg_flags[2];    /* Reserved for future use                    @98C */
  unsigned char  _filler1[2];           /* Reserved                                   @92A */
  unsigned char  smf70_trg_mem[8];      /* Memory consumption of tenant resource group     */

#define smf70_trg_suifa smf70_trg_sucbp._smf70_trg_suifa
  };

/* Values for field "smf70_trg_flags" */
#define smf70_trg_fcbp 0x8000 /* Reserved for future use                @98C */

struct r702typ3 {
  unsigned char  r7023ax;     /* Crypto processor index                     @J1A */
  unsigned char  r7023ct;     /* Crypto processor type                      @J1A */
  unsigned char  r7023msk;    /* Validity bit mask. Each bit position            */
  unsigned char  r7023mt;     /* Reserved for diagnostic purpose        @OA37016 */
  unsigned char  _filler1[4]; /* Reserved                               @OA37016 */
  unsigned char  r7023sf[8];  /* Scaling factor for the indicating               */
  unsigned char  r7023t0[8];  /* Execution time of all operations on the         */
  unsigned char  r7023c0[8];  /* Execution number of all operations on the       */
  unsigned char  _filler2[8]; /* Reserved                                   @J1C */
  unsigned char  r7023c1[8];  /* Execution number of RSA-key-genaration          */
  unsigned char  r7023scope;  /* Specifies the scope of the data section         */
  unsigned char  r7023did;    /* Domain ID                                       */
  unsigned char  _filler3[2]; /* Reserved                                   @93A */
  };

struct r702typ4 {
  unsigned char  r7024ax;     /* Crypto processor index                     @J1A */
  unsigned char  r7024ct;     /* Crypto processor type                      @J1A */
  unsigned char  r7024msk;    /* Validity bit mask. Each bit position   @OA31349 */
  unsigned char  r7024mt;     /* Reserved for diagnostic purpose        @OA37016 */
  unsigned char  r7024en[4];  /* Number of engines. This is the number of   @K1A */
  unsigned char  r7024sf[8];  /* Scaling factor for the indicating               */
  union {
    unsigned char  _r7024tc[5][64]; /* Timers & counters for the cryptographic */
    struct {
      unsigned char  _r7021met[8];   /* Execution time for 1024-bit ME-format    */
      unsigned char  _r7021mec[8];   /* Execution number for 1024-bit ME-format  */
      unsigned char  _r7022met[8];   /* Execution time for 2048-bit ME-format    */
      unsigned char  _r7022mec[8];   /* Execution number for 2048-bit ME-format  */
      unsigned char  _r7021crt[8];   /* Execution time for 1024-bit CRT-format   */
      unsigned char  _r7021crc[8];   /* Execution number for 1024-bit CRT-format */
      unsigned char  _r7022crt[8];   /* Execution time for 2048-bit CRT-format   */
      unsigned char  _r7022crc[8];   /* Execution number for 2048-bit CRT-format */
      unsigned char  _filler1[256];
      } _r702typ4_struct1;
    } _r702typ4_union1;
  unsigned char  r7023met[8]; /* Execution time for 4096-bit ME-format           */
  unsigned char  r7023mec[8]; /* Execution number for 4096-bit ME-format         */
  unsigned char  r7023crt[8]; /* Execution time for 4096-bit CRT-format          */
  unsigned char  r7023crc[8]; /* Execution number for 4096-bit CRT-format        */
  unsigned char  r7024scope;  /* Specifies the scope of the data section         */
  unsigned char  r7024did;    /* Domain ID                                       */
  unsigned char  _filler2[2]; /* Reserved                                   @93A */

#define r7024tc  _r702typ4_union1._r7024tc
#define r7021met _r702typ4_union1._r702typ4_struct1._r7021met
#define r7021mec _r702typ4_union1._r702typ4_struct1._r7021mec
#define r7022met _r702typ4_union1._r702typ4_struct1._r7022met
#define r7022mec _r702typ4_union1._r702typ4_struct1._r7022mec
#define r7021crt _r702typ4_union1._r702typ4_struct1._r7021crt
#define r7021crc _r702typ4_union1._r702typ4_struct1._r7021crc
#define r7022crt _r702typ4_union1._r702typ4_struct1._r7022crt
#define r7022crc _r702typ4_union1._r702typ4_struct1._r7022crc
  };

/* Values for field "r7024msk" */
#define r7021km  0x80 /* 1024-bit ME-format RSA operations      @OA31349 */
#define r7022km  0x40 /* 2048-bit ME-format RSA operations      @OA31349 */
#define r7021kc  0x20 /* 1024-bit CRT-format RSA operations     @OA31349 */
#define r7022kc  0x10 /* 2048-bit CRT-format RSA operations     @OA31349 */
#define r7023km  0x08 /* 4096-bit ME-format RSA operations      @OA31349 */
#define r7023kc  0x04 /* 4096-bit CRT-format RSA operations     @OA31349 */

/* Values for field "r7022crc" */
#define r702neng 5    /* Max number of entries in the R7024TC array @K1C */

struct r702typ5 {
  unsigned char  r7025ax;     /* Crypto processor index                 @OA39562 */
  unsigned char  r7025ct;     /* Crypto processor type                  @OA39562 */
  unsigned char  r7025msk;    /* Validity bit mask. Each bit position            */
  unsigned char  r7025mt;     /* Reserved for diagnostic purpose        @OA39562 */
  unsigned char  _filler1[4]; /* Reserved                               @OA39562 */
  unsigned char  r7025sf[8];  /* Scaling factor for the indicating               */
  unsigned char  r7025sat[8]; /* Aggregate execution time of operations executed */
  unsigned char  r7025sac[8]; /* Number of operations executed by slow           */
  unsigned char  r7025fat[8]; /* Aggregate execution time of operations executed */
  unsigned char  r7025fac[8]; /* Number of operations executed by fast           */
  unsigned char  r7025spt[8]; /* Aggregate execution time of operations executed */
  unsigned char  r7025spc[8]; /* Number of operations executed by symmetric-key  */
  unsigned char  r7025sct[8]; /* Aggregate execution time of operations executed */
  unsigned char  r7025scc[8]; /* Number of operations executed by symmetric-key  */
  unsigned char  r7025agt[8]; /* Aggregate execution time of operations executed */
  unsigned char  r7025agc[8]; /* Number of operations executed by asymmetric-key */
  unsigned char  r7025scope;  /* Specifies the scope of the data section         */
  unsigned char  r7025did;    /* Domain ID                                       */
  unsigned char  _filler2[2]; /* Reserved                                   @93A */
  };

/* Values for field "r7025msk" */
#define r7025sa 0x80 /* Slow asymmetric-key functions          @OA39562 */
#define r7025fa 0x40 /* Fast asymmetric-key functions          @OA39562 */
#define r7025sp 0x20 /* Symmetric-key functions returning partial       */
#define r7025sc 0x10 /* Symmetric-key functions returning complete      */
#define r7025ag 0x08 /* Symmetric-key generation function      @OA39562 */

struct r702ccf {
  unsigned char  r702snec[8]; /* Single DES: Number of calls                     */
  unsigned char  r702sneb[8]; /* Single DES: Number of bytes                     */
  unsigned char  r702snei[8]; /* Single DES: Number of CMD instructions          */
  unsigned char  r702tnec[8]; /* Triple DES: Number of calls                     */
  unsigned char  r702tneb[8]; /* Triple DES: Number of bytes                     */
  unsigned char  r702tnei[8]; /* Triple DES: Number of CMD instructions          */
  unsigned char  r702sndc[8]; /* Single DES: Number of calls                     */
  unsigned char  r702sndb[8]; /* Single DES: Number of bytes                     */
  unsigned char  r702sndi[8]; /* Single DES: Number of CMD instructions          */
  unsigned char  r702tndc[8]; /* Triple DES: Number of calls to decipher         */
  unsigned char  r702tndb[8]; /* Triple DES: Number of bytes                     */
  unsigned char  r702tndi[8]; /* Triple DES: Number of CMD instructions          */
  unsigned char  r702nmgc[8]; /* Number of calls to MAC generate                 */
  unsigned char  r702nmgb[8]; /* Number of bytes of data MAC generated           */
  unsigned char  r702nmgi[8]; /* Number of PCMF instructions                     */
  unsigned char  r702nmvc[8]; /* Number of calls to MAC verify                   */
  unsigned char  r702nmvb[8]; /* Number of bytes of data MAC verified            */
  unsigned char  r702nmvi[8]; /* Number of PCMF instructions                     */
  unsigned char  r702nhac[8]; /* For SHA-1: Number of calls to hash              */
  unsigned char  r702nhab[8]; /* For SHA-1: Number of bytes of data hashed       */
  unsigned char  r702nhai[8]; /* For SHA-1: Number of PCMF instructions          */
  unsigned char  r702nptc[8]; /* Number of calls to PIN translate                */
  unsigned char  r702npvc[8]; /* Number of calls to PIN verify                   */
  unsigned char  r702nh2c[8]; /* For SHA-224 and SHA-256:                   @21C */
  unsigned char  r702nh2b[8]; /* For SHA-224 and SHA-256:                   @21C */
  unsigned char  r702nh2i[8]; /* For SHA-224 and SHA-256:                   @21C */
  unsigned char  r702nh5c[8]; /* For SHA-384 and SHA-512:                        */
  unsigned char  r702nh5b[8]; /* For SHA-384 and SHA-512:                        */
  unsigned char  r702nh5i[8]; /* For SHA-384 and SHA-512:                        */
  int            r702cdlv;    /* ICSF data level                        @OA28670 */
  unsigned char  r702aesc[8]; /* Number of AES encipher calls sent to a          */
  unsigned char  r702aesb[8]; /* Number of bytes processed by the AES            */
  unsigned char  r702aesi[8]; /* Number of operations required to complete       */
  unsigned char  r702asdc[8]; /* Number of AES decipher calls sent to a          */
  unsigned char  r702asdb[8]; /* Number of bytes processed by the AES            */
  unsigned char  r702asdi[8]; /* Number of operations required to complete       */
  unsigned char  r702drgc[8]; /* Number of calls to generate the                 */
  unsigned char  _filler1[8]; /* Reserved                               @OA43493 */
  unsigned char  _filler2[8]; /* Reserved                               @OA43493 */
  unsigned char  r702drvc[8]; /* Number of calls to verify the RSA               */
  unsigned char  _filler3[8]; /* Reserved                               @OA43493 */
  unsigned char  _filler4[8]; /* Reserved                               @OA43493 */
  unsigned char  r702degc[8]; /* Number of calls to generate the                 */
  unsigned char  _filler5[8]; /* Reserved                               @OA43493 */
  unsigned char  _filler6[8]; /* Reserved                               @OA43493 */
  unsigned char  r702devc[8]; /* Number of calls to verify the ECC               */
  unsigned char  _filler7[8]; /* Reserved                               @OA43493 */
  unsigned char  _filler8[8]; /* Reserved                               @OA43493 */
  unsigned char  r702amgc[8]; /* Number of calls to generate the AES MACs        */
  unsigned char  r702amgb[8]; /* Number of bytes of data for which the           */
  unsigned char  r702amgi[8]; /* Number of instructions used to generate         */
  unsigned char  r702amvc[8]; /* Number of calls to verify the AES MACs          */
  unsigned char  r702amvb[8]; /* Number of bytes of data for which the           */
  unsigned char  r702amvi[8]; /* Number of instructions used to verify           */
  unsigned char  r702fpec[8]; /* Number of calls to encipher data using FPE      */
  unsigned char  r702fpeb[8]; /* Number of bytes of data enciphered using FPE    */
  unsigned char  r702fpei[8]; /* Number of instructions used to encipher         */
  unsigned char  r702fpdc[8]; /* Number of calls to decipher data using FPE      */
  unsigned char  r702fpdb[8]; /* Number of bytes of data deciphered using FPE    */
  unsigned char  r702fpdi[8]; /* Number of instructions used to decipher         */
  unsigned char  r702fptc[8]; /* Number of calls to translate data using FPE     */
  unsigned char  r702fptb[8]; /* Number of bytes of data translated using FPE    */
  unsigned char  r702fpti[8]; /* Number of instructions used to translate        */

  unsigned char  r702fxec[8];
  unsigned char  r702fxeb[8];
  unsigned char  r702fxei[8];
  unsigned char  r702fxdc[8];
  unsigned char  r702fxdb[8];
  unsigned char  r702fxdi[8];
  unsigned char  r702fxtc[8];
  unsigned char  r702fxtb[8];
  unsigned char  r702fxti[8];
  unsigned char  r702dqgc[8];
  unsigned char  _filler9[16];
  unsigned char  r702dqvc[8];
  unsigned char  _filler10[16];
  };

#pragma pack(reset)
