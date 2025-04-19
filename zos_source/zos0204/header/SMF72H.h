/* SPDX-License-Identifier: GPL-3.0-only or GPL-3.0-or-later */
/*
 * Smf72 Structures Header File.
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

struct smf72hdr {
  union {
    unsigned char  _smf72hdc[36]; /* COMPLETE HEADER+PRODUCT SECTION TRIPL @WA05544 */
    struct {
      unsigned char  _smf72len[2]; /* RECORD LENGTH                     */
      unsigned char  _smf72seg[2]; /* SEGMENT DESCRIPTOR                */
      unsigned char  _smf72flg;    /* HEADER FLAG BYTE                  */
      unsigned char  _smf72rty;    /* RECORD TYPE                       */
      unsigned char  _smf72tme[4]; /* TOD RECORD WRITTEN                */
      unsigned char  _smf72dte[4]; /* DATE RECORD WRITTEN               */
      unsigned char  _smf72sid[4]; /* SYSTEM ID FROM INSTALLATION       */
      unsigned char  _smf72ssi[4]; /* SUBSYSTEM ID (RMF)                */
      unsigned char  _smf72sty[2]; /* SUBTYPE                           */
      unsigned char  _smf72trn[2]; /* NUMBER OF TRIPLETS IN THIS RECORD */
      unsigned char  _filler1[2];  /* RESERVED                          */
      unsigned char  _smf72prs[4]; /* OFFSET TO RMF PRODUCT SECTION     */
      unsigned char  _smf72prl[2]; /* LENGTH OF RMF PRODUCT SECTION     */
      unsigned char  _smf72prn[2]; /* NUMBER OF RMF PRODUCT SECTIONS    */
      } _smf72hdr_struct1;
    } _smf72hdr_union1;
  union {
    struct {
      struct {
        unsigned char  _smf72wls[4]; /* Offset to workload control section (Subtype 1) */
        } smf72hdx;
      unsigned char  _smf72wll[2];  /* Length of workload control section (Subtype 1) */
      unsigned char  _smf72wln[2];  /* Number of workload control sections            */
      unsigned char  _smf72pgs[4];  /* Offset to performance group period             */
      unsigned char  _smf72pgl[2];  /* Length of performance group period             */
      unsigned char  _smf72pgn[2];  /* Number of performance group period             */
      unsigned char  _smf72sws[4];  /* Offset to swap reason data section             */
      unsigned char  _smf72swl[2];  /* Length of swap reason data section             */
      unsigned char  _smf72swn[2];  /* Number of swap reason data sections            */
      unsigned char  _filler2[88];
      } _smf72hdr_struct2;
    struct {
      struct {
        unsigned char  _smf72wms[4]; /* Offset to workload manager control        @C1A */
        unsigned char  _smf72wml[2]; /* Length of workload manager control        @C1A */
        unsigned char  _smf72wmn[2]; /* Number of workload manager control        @C1A */
        unsigned char  _smf72sss[4]; /* Offset to service class served data       @C1A */
        unsigned char  _smf72ssl[2]; /* Length to service class served data       @C1A */
        unsigned char  _smf72ssn[2]; /* Number of service class served data       @C1A */
        unsigned char  _smf72rgs[4]; /* Offset to resource group data section     @C1A */
        unsigned char  _smf72rgl[2]; /* Length of resource group data section     @C1A */
        unsigned char  _smf72rgn[2]; /* Number of resource group data sections    @C1A */
        unsigned char  _smf72scs[4]; /* Offset to period data section (Subtype 3) @J2C */
        unsigned char  _smf72scl[2]; /* Length of period data section (Subtype 3) @J2C */
        unsigned char  _smf72scn[2]; /* Number of period data sections            @J2C */
        unsigned char  _smf72rts[4]; /* Offset to response time distribution      @C1A */
        unsigned char  _smf72rtl[2]; /* Length of response time distribution      @C1A */
        unsigned char  _smf72rtn[2]; /* Number of response time distribution      @C1A */
        unsigned char  _smf72wrs[4]; /* Offset to work/resource manager state     @C1A */
        unsigned char  _smf72wrl[2]; /* Length of work/resource manager state     @C1A */
        unsigned char  _smf72wrn[2]; /* Number of work/resource manager state     @C1A */
        } smf723hx;
      unsigned char  _smf72dns[4];  /* Offset to resource delay names section    @21A */
      unsigned char  _smf72dnl[2];  /* Length of resource delay names section    @21A */
      unsigned char  _smf72dnn[2];  /* Number of resource delay names sections   @21A */
      unsigned char  _filler3[56];
      } _smf72hdr_struct3;
    struct {
      struct {
        unsigned char  _smf72cps[4]; /* Offset to service class period data       @C2A */
        unsigned char  _smf72cpl[2]; /* Length of service class period data       @C2A */
        unsigned char  _smf72cpn[2]; /* Number of service class period data       @C2A */
        unsigned char  _smf72sps[4]; /* Offset to swap reason data                @C2A */
        unsigned char  _smf72spl[2]; /* Length of swap reason data                @C2A */
        unsigned char  _smf72spn[2]; /* Number of swap reason data                @C2A */
        } smf724hx;
      unsigned char  _filler4[96];
      } _smf72hdr_struct4;
    struct {
      unsigned char  _smf72ses[4]; /* Offset to serialization control           @51A */
      unsigned char  _smf72sel[2]; /* Length of serialization control           @51A */
      unsigned char  _smf72sen[2]; /* Number of serialization control           @51A */
      unsigned char  _smf72cms[4]; /* Offset to CMS lock data                   @51A */
      unsigned char  _smf72cml[2]; /* Length of CMS lock data                   @51A */
      unsigned char  _smf72cmn[2]; /* Number of CMS lock data                   @51A */
      unsigned char  _smf72eds[4]; /* Offset to CMS EnqueueDequeue lock data    @51A */
      unsigned char  _smf72edl[2]; /* Length of CMS EnqueueDequeue lock data    @51A */
      unsigned char  _smf72edn[2]; /* Number of CMS EnqueueDequeue lock data    @51A */
      unsigned char  _smf72las[4]; /* Offset to CMS Latch lock data             @51A */
      unsigned char  _smf72lal[2]; /* Length of CMS Latch lock data             @51A */
      unsigned char  _smf72lan[2]; /* Number of CMS Latch lock data             @51A */
      unsigned char  _smf72sms[4]; /* Offset to CMS SMF lock data               @51A */
      unsigned char  _smf72sml[2]; /* Length of CMS SMF lock data               @51A */
      unsigned char  _smf72smn[2]; /* Number of CMS SMF lock data               @51A */
      unsigned char  _smf72los[4]; /* Offset to Local lock data                 @51A */
      unsigned char  _smf72lol[2]; /* Length of Local lock data                 @51A */
      unsigned char  _smf72lon[2]; /* Number of Local lock data                 @51A */
      unsigned char  _smf72cos[4]; /* Offset to CML lock Owner data             @51A */
      unsigned char  _smf72col[2]; /* Length of CML lock Owner data             @51A */
      unsigned char  _smf72con[2]; /* Number of CML lock Owner data             @51A */
      unsigned char  _smf72crs[4]; /* Offset to CML lock Requestor data         @51A */
      unsigned char  _smf72crl[2]; /* Length of CML lock Requestor data         @51A */
      unsigned char  _smf72crn[2]; /* Number of CML lock Requestor data         @51A */
      unsigned char  _smf72lcs[4]; /* Offset to GRS Latch Set Creator data      @51A */
      unsigned char  _smf72lcl[2]; /* Length of GRS Latch Set Creator data      @51A */
      unsigned char  _smf72lcn[2]; /* Number of GRS Latch Set Creator data      @51A */
      unsigned char  _smf72lrs[4]; /* Offset to GRS Latch Requestor data        @51A */
      unsigned char  _smf72lrl[2]; /* Length of GRS Latch Requestor data        @51A */
      unsigned char  _smf72lrn[2]; /* Number of GRS Latch Requestor data        @51A */
      unsigned char  _smf72tds[4]; /* Offset to GRS ENQ SCOPE=STEP data         @51A */
      unsigned char  _smf72tdl[2]; /* Length of GRS ENQ SCOPE=STEP data         @51A */
      unsigned char  _smf72tdn[2]; /* Number of GRS ENQ SCOPE=STEP data         @51A */
      unsigned char  _smf72yds[4]; /* Offset to GRS ENQ SCOPE=SYSTEM data       @51A */
      unsigned char  _smf72ydl[2]; /* Length of GRS ENQ SCOPE=SYSTEM data       @51A */
      unsigned char  _smf72ydn[2]; /* Number of GRS ENQ SCOPE=SYSTEM data       @51A */
      unsigned char  _smf72sds[4]; /* Offset to GRS ENQ SCOPE=SYSTEMS data      @51A */
      unsigned char  _smf72sdl[2]; /* Length of GRS ENQ SCOPE=SYSTEMS data      @51A */
      unsigned char  _smf72sdn[2]; /* Number of GRS ENQ SCOPE=SYSTEMS data      @51A */
      unsigned char  _smf72qss[4]; /* Offset to GRS QScan data                  @63A */
      unsigned char  _smf72qsl[2]; /* Length of GRS QScan data                  @63A */
      unsigned char  _smf72qsn[2]; /* Number of GRS QScan data                  @63A */
      } smf725hx;
    } _smf72hdr_union2;

#define smf72hdc _smf72hdr_union1._smf72hdc
#define smf72len _smf72hdr_union1._smf72hdr_struct1._smf72len
#define smf72seg _smf72hdr_union1._smf72hdr_struct1._smf72seg
#define smf72flg _smf72hdr_union1._smf72hdr_struct1._smf72flg
#define smf72rty _smf72hdr_union1._smf72hdr_struct1._smf72rty
#define smf72tme _smf72hdr_union1._smf72hdr_struct1._smf72tme
#define smf72dte _smf72hdr_union1._smf72hdr_struct1._smf72dte
#define smf72sid _smf72hdr_union1._smf72hdr_struct1._smf72sid
#define smf72ssi _smf72hdr_union1._smf72hdr_struct1._smf72ssi
#define smf72sty _smf72hdr_union1._smf72hdr_struct1._smf72sty
#define smf72trn _smf72hdr_union1._smf72hdr_struct1._smf72trn
#define smf72prs _smf72hdr_union1._smf72hdr_struct1._smf72prs
#define smf72prl _smf72hdr_union1._smf72hdr_struct1._smf72prl
#define smf72prn _smf72hdr_union1._smf72hdr_struct1._smf72prn
#define smf72wls _smf72hdr_union2._smf72hdr_struct2.smf72hdx._smf72wls
#define smf72wll _smf72hdr_union2._smf72hdr_struct2._smf72wll
#define smf72wln _smf72hdr_union2._smf72hdr_struct2._smf72wln
#define smf72pgs _smf72hdr_union2._smf72hdr_struct2._smf72pgs
#define smf72pgl _smf72hdr_union2._smf72hdr_struct2._smf72pgl
#define smf72pgn _smf72hdr_union2._smf72hdr_struct2._smf72pgn
#define smf72sws _smf72hdr_union2._smf72hdr_struct2._smf72sws
#define smf72swl _smf72hdr_union2._smf72hdr_struct2._smf72swl
#define smf72swn _smf72hdr_union2._smf72hdr_struct2._smf72swn
#define smf72wms _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72wms
#define smf72wml _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72wml
#define smf72wmn _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72wmn
#define smf72sss _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72sss
#define smf72ssl _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72ssl
#define smf72ssn _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72ssn
#define smf72rgs _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72rgs
#define smf72rgl _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72rgl
#define smf72rgn _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72rgn
#define smf72scs _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72scs
#define smf72scl _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72scl
#define smf72scn _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72scn
#define smf72rts _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72rts
#define smf72rtl _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72rtl
#define smf72rtn _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72rtn
#define smf72wrs _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72wrs
#define smf72wrl _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72wrl
#define smf72wrn _smf72hdr_union2._smf72hdr_struct3.smf723hx._smf72wrn
#define smf72dns _smf72hdr_union2._smf72hdr_struct3._smf72dns
#define smf72dnl _smf72hdr_union2._smf72hdr_struct3._smf72dnl
#define smf72dnn _smf72hdr_union2._smf72hdr_struct3._smf72dnn
#define smf72cps _smf72hdr_union2._smf72hdr_struct4.smf724hx._smf72cps
#define smf72cpl _smf72hdr_union2._smf72hdr_struct4.smf724hx._smf72cpl
#define smf72cpn _smf72hdr_union2._smf72hdr_struct4.smf724hx._smf72cpn
#define smf72sps _smf72hdr_union2._smf72hdr_struct4.smf724hx._smf72sps
#define smf72spl _smf72hdr_union2._smf72hdr_struct4.smf724hx._smf72spl
#define smf72spn _smf72hdr_union2._smf72hdr_struct4.smf724hx._smf72spn
#define smf72ses _smf72hdr_union2.smf725hx._smf72ses
#define smf72sel _smf72hdr_union2.smf725hx._smf72sel
#define smf72sen _smf72hdr_union2.smf725hx._smf72sen
#define smf72cms _smf72hdr_union2.smf725hx._smf72cms
#define smf72cml _smf72hdr_union2.smf725hx._smf72cml
#define smf72cmn _smf72hdr_union2.smf725hx._smf72cmn
#define smf72eds _smf72hdr_union2.smf725hx._smf72eds
#define smf72edl _smf72hdr_union2.smf725hx._smf72edl
#define smf72edn _smf72hdr_union2.smf725hx._smf72edn
#define smf72las _smf72hdr_union2.smf725hx._smf72las
#define smf72lal _smf72hdr_union2.smf725hx._smf72lal
#define smf72lan _smf72hdr_union2.smf725hx._smf72lan
#define smf72sms _smf72hdr_union2.smf725hx._smf72sms
#define smf72sml _smf72hdr_union2.smf725hx._smf72sml
#define smf72smn _smf72hdr_union2.smf725hx._smf72smn
#define smf72los _smf72hdr_union2.smf725hx._smf72los
#define smf72lol _smf72hdr_union2.smf725hx._smf72lol
#define smf72lon _smf72hdr_union2.smf725hx._smf72lon
#define smf72cos _smf72hdr_union2.smf725hx._smf72cos
#define smf72col _smf72hdr_union2.smf725hx._smf72col
#define smf72con _smf72hdr_union2.smf725hx._smf72con
#define smf72crs _smf72hdr_union2.smf725hx._smf72crs
#define smf72crl _smf72hdr_union2.smf725hx._smf72crl
#define smf72crn _smf72hdr_union2.smf725hx._smf72crn
#define smf72lcs _smf72hdr_union2.smf725hx._smf72lcs
#define smf72lcl _smf72hdr_union2.smf725hx._smf72lcl
#define smf72lcn _smf72hdr_union2.smf725hx._smf72lcn
#define smf72lrs _smf72hdr_union2.smf725hx._smf72lrs
#define smf72lrl _smf72hdr_union2.smf725hx._smf72lrl
#define smf72lrn _smf72hdr_union2.smf725hx._smf72lrn
#define smf72tds _smf72hdr_union2.smf725hx._smf72tds
#define smf72tdl _smf72hdr_union2.smf725hx._smf72tdl
#define smf72tdn _smf72hdr_union2.smf725hx._smf72tdn
#define smf72yds _smf72hdr_union2.smf725hx._smf72yds
#define smf72ydl _smf72hdr_union2.smf725hx._smf72ydl
#define smf72ydn _smf72hdr_union2.smf725hx._smf72ydn
#define smf72sds _smf72hdr_union2.smf725hx._smf72sds
#define smf72sdl _smf72hdr_union2.smf725hx._smf72sdl
#define smf72sdn _smf72hdr_union2.smf725hx._smf72sdn
#define smf72qss _smf72hdr_union2.smf725hx._smf72qss
#define smf72qsl _smf72hdr_union2.smf725hx._smf72qsl
#define smf72qsn _smf72hdr_union2.smf725hx._smf72qsn
  };

/* Values for field "smf72flg" */
#define smf72rrf 0x80 /* NEW RECORD FORMAT                              */
#define smf72sut 0x40 /* SUBTYPES USED                             @R0A */
#define smf72v4  0x10 /* MVS/ESA Version 4                         @A1A */
#define smf72esa 0x08 /* MVS/ESA VERSION                           @W1A */
#define smf72vxa 0x04 /* MVS/XA VERSION                            @R0A */
#define smf72os  0x02 /* OPERATING SYSTEM IS OS/VS2                     */
#define smf72bfy 0x01 /* System running in PR/SM mode              @J1C */

struct smf72pro {
  unsigned char  smf72mfv[2]; /* RMF version number in PACKED decimal 'nnnF'     */
  unsigned char  smf72prd[8]; /* PRODUCT NAME                                    */
  unsigned char  smf72ist[4]; /* TOD MONITOR INTERVAL START: 0HHMMSSF            */
  unsigned char  smf72dat[4]; /* DATE MONITOR INTERVAL START: 00YYDDDF           */
  unsigned char  smf72int[4]; /* DURATION OF MONITOR INTERVAL: MMSSTTTF          */
  unsigned char  smf72mfl[2]; /* RESERVED                                   @J1C */
  unsigned char  smf72sam[4]; /* Number of RMF samples                           */
  unsigned char  smf72rv2[2]; /* RESERVED                                        */
  unsigned char  smf72fla[2]; /* Flags                                           */
  unsigned char  smf72rls[4]; /* RESERVED                                   @J1C */
  unsigned char  smf72cyc[4]; /* CYCLE IN PACKED DECIMAL 000TTTTF                */
  unsigned char  smf72mvs[8]; /* MVS software level (consists of an acronym @J1C */
  unsigned char  smf72iml;    /* Indicates the type of processor complex    @J1C */
  unsigned char  smf72prf;    /* Processor flags                            @P2A */
  unsigned char  smf72ptn;    /* PR/SM PARTITION NUMBER                     @Z1C */
  unsigned char  smf72srl;    /* SMF record level                       @YA28449 */
  unsigned char  smf72iet[8]; /* Interval expiration time token             @B1A */
  unsigned char  smf72lgo[8]; /* Offset GMT to local time                   @C1A */
  unsigned char  smf72rao[4]; /* Offset to reassembly area relative to      @C2A */
  unsigned char  smf72ral[2]; /* Length of reassembly area. Length depends  @C2A */
  unsigned char  smf72ran[2]; /* Number of reassembly area. This field is   @C2A */
  unsigned char  smf72oil[2]; /* Original interval length                   @C2A */
  unsigned char  smf72syn[2]; /* SYNC value in seconds                      @C2A */
  unsigned char  smf72gie[8]; /* Projected gathering interval end           @C2A */
  unsigned char  smf72xnm[8]; /* Sysplex name                               @C1A */
  unsigned char  smf72snm[8]; /* System name for current system             @C1A */
  };

/* Values for field "smf72fla" */
#define smf72cnv 0x80 /* DATA CONVERT.FROM VER.2                         */
#define smf72iss 0x40 /* INVALID SAMPLES TO BE SKIPPED              @Q1A */
#define smf72m3r 0x20 /* Record was written by RMF Monitor III      @B1A */
#define smf72ism 0x10 /* Interval was written under SMF control     @B1A */
#define smf72cbp 0x80 /* Reserved for future use                    @92C */
#define smf72iip 0x40 /* zIIP boost was active                      @93A */
#define smf72eed 0x20 /* Speed boost was active during              @93A */
#define smf72boo 0x07 /* Boost class is set at end of interval,    @A02C */
#define smf72brp 0x03 /* Boost class: 011 Recovery Process         @A02A */
#define smf72bsh 0x02 /* Boost class: 010 Shutdown                  @93A */
#define smf72bip 0x01 /* Boost class: 001 IPL                       @93A */

/* Values for field "smf72prf" */
#define smf72qes 0x80 /* System has expanded storage                @P2A */
#define smf72cne 0x40 /* Equipped with ESCON Channel                @Z1A */
#define smf72drc 0x20 /* ESCON Director in configuration            @Z1A */
#define smf72eme 0x10 /* System in z/ARCH mode                      @I1A */
#define smf72prx 0x08 /* Reserved for future use                    @92C */
#define smf72pri 0x08 /* At least one zAAP is currently installed   @92C */
#define smf72prp 0x04 /* At least one zIIP is currently installed   @22C */
#define smf72ped 0x02 /* Enhanced DAT facility 1 available          @81C */
#define smf72pe2 0x01 /* Enhanced DAT facility 2 available          @81A */

struct smf72rhd {
  unsigned char  smf72rbr[2]; /* Total number of broken records build from  @C2A */
  unsigned char  smf72rsq[2]; /* Sequence number of this broken record.     @C2A */
  unsigned char  smf72rio[4]; /* Offset to first reassembly information     @C2A */
  unsigned char  smf72ril[2]; /* Length of reassembly information block     @C2A */
  unsigned char  smf72rin[2]; /* Number of reassembly information blocks    @C2A */
  unsigned char  _filler1[4]; /* Reserved                                   @C2A */
  };

struct smf72rbl {
  unsigned char  smf72rnn[2]; /* Total number of sections in the original   @C2A */
  unsigned char  smf72rpp[2]; /* Position of the first of one or more       @C2A */
  };

struct smf72ctl {
  unsigned char  smf72fg1;     /* FLAGS                                          */
  unsigned char  smf72rv3;     /* RESERVED                                       */
  unsigned char  smf72sub[2];  /* SUB-CATEGORY CODE,PERF.GROUP #                 */
  unsigned char  smf72hpg[2];  /* HIGHEST PERF GROUP(PG) # DEFINED IN IPS        */
  unsigned char  smf72ips[8];  /* NAME OF INSTALLATION PERF SPEC                 */
  unsigned char  _filler1[3];  /* Reserved                                 @A2C  */
  unsigned char  _filler2[3];  /* Reserved                                 @A2C  */
  unsigned char  smf72erf[6];  /* ERV RESOURCE MANAGER COEFFICIENT               */
  unsigned char  smf72isd[4];  /* IOC SERVICE DEFINITION COEFFICIENT             */
  unsigned char  smf72csd[4];  /* CPU SERVICE DEFINITION COEFFICIENT             */
  unsigned char  smf72rv4[4];  /* RESERVED SINCE RMF 4.2.0                       */
  unsigned char  smf72ssd[4];  /* SRB SERVICE DEFINITION COEFFICIENT             */
  unsigned char  smf72opt[8];  /* NAME OF OPT                                    */
  unsigned char  smf72ics[8];  /* NAME OF ICS                                    */
  unsigned char  smf72sys[4];  /* SUBSYSTEM FOR THIS PGN                         */
  unsigned char  smf72cls[10]; /* CLASS                                          */
  unsigned char  smf72usr[10]; /* USER ID                                        */
  unsigned char  smf72nam[10]; /* TRANSACTION NAME FOR THIS PGN                  */
  int            smf72adj;     /* VALUE RMCTADJC - ADJ. FACTOR FOR CPU RATE @P1A */
  unsigned char  smf72msd[8];  /* MSO SERVICE DEFINITION COEFFICIENT        @Y1A */
  unsigned char  smf72srv[10]; /* Service class (SRVCLASS) as specified in  @C3A */
  unsigned char  smf72rv5[2];  /* Reserved                                  @C3A */
  };

/* Values for field "smf72fg1" */
#define smf72ove 0x10 /* WLM I/O Priority Management = YES        @F1A */
#define smf72caa 0x08 /* RCAA data not available -                @C1A */
#define smf72acn 0x04 /* ACCOUNT INFORMATION                      @R0A */
#define smf72rpt 0x02 /* REPORT CLASS                                  */
#define smf72chf 0x01 /* CHANGE TO PERFORMANCE SENSITIVE               */

struct smf72wkl {
  unsigned char  smf72ttx[4]; /* # OF TERMINATED TRANSACTIONS                   */
  unsigned char  smf72act[4]; /* ALL TRANSACTIONS ACTIVE TIME-1K MIC SEC        */
  unsigned char  smf72ser[4]; /* ALL TRANSACTIONS SERVICE UNITS                 */
  unsigned char  smf72ttm[4]; /* TERM TRANS ELAPSED TIME-1K MIC SEC             */
  unsigned char  _filler1[4]; /* Now reserved (was WLL up to 4.2.0)        @A2A */
  unsigned char  smf72mts[4]; /* MSO TOTAL SERVICE                              */
  unsigned char  smf72its[4]; /* I/O TOTAL SERVICE                              */
  unsigned char  smf72cts[4]; /* CPU TOTAL SERVICE                              */
  unsigned char  smf72tat[4]; /* TRANSACTION ACTIVE TIME IN STORAGE             */
  unsigned char  smf72spp[4]; /* NO. SWAPS IN PERIOD                            */
  unsigned char  smf72cdn[2]; /* CURRENT DOMAIN NUMBER                          */
  unsigned char  _filler2;    /* Reserved                                  @A2C */
  unsigned char  smf72tsg;    /* TIME SLICE GROUP NUMBER                        */
  unsigned char  smf72sts[4]; /* SRB TOTAL SERVICE                              */
  struct {
    unsigned char  _smf72et1[4]; /* WORD1-SUM OF SQUARES OF ENDED TRANS */
    unsigned char  _smf72et2[4]; /* WORD2-SUM OF SQUARES OF ENDED TRANS */
    } smf72ets;
  unsigned char  smf72pin[4]; /* NUMBER OF PAGE-INS                    @YA04880 */
  struct {
    unsigned char  _smf72ft1[4]; /* WORD1-ACTIVE FRAME-TIME               @YA04880 */
    unsigned char  _smf72ft2[4]; /* WORD2-ACTIVE FRAME-TIME               @YA04880 */
    } smf72frs;
  unsigned char  smf72hin[4]; /* Number of hiperspace page-ins             @W2A */
  unsigned char  smf72hrm[4]; /* Number of hiperspace read misses          @W2A */
  unsigned char  smf72bpi[4]; /* Number of blocked pages paged in          @A2A */
  unsigned char  smf72pie[4]; /* Single pages in from exp. incl. 1st page  @A2A */
  unsigned char  smf72bpe[4]; /* Blocked pages in from exp. excl. 1st page @A2A */
  unsigned char  smf72bka[4]; /* Number of blocks paged in from AUX        @A2A */
  unsigned char  smf72bke[4]; /* Number of blocks paged in from expanded   @A2A */
  unsigned char  smf72er1[4]; /* High order word                        @A2A    */
  unsigned char  smf72er2[4]; /* Low  order word                        @A2A    */
  unsigned char  smf72rct[4]; /* Region Control Task time                  @A2A */
  unsigned char  smf72iit[4]; /* I/O interrupt processing time             @A2A */
  unsigned char  smf72hst[4]; /* Hiperspace service time                   @A2A */
  unsigned char  smf72tst[4]; /* Total system transaction time             @A1A */
  struct {
    unsigned char  _smf72cus[4]; /* CPU using samples. These are included in */
    unsigned char  _smf72tot[4]; /* Total delay samples used in SRM's        */
    } smf72vel;
  unsigned char  smf72srs[8]; /* Total shared page residency time               */
  unsigned char  smf72spa[8]; /* Total shared page-ins from auxiliary storage   */
  unsigned char  smf72spe[8]; /* Total shared page-ins from expanded storage    */
  unsigned char  smf72ict[8]; /* Total DASD I/O connect time in 128 microsecond */
  unsigned char  smf72iwt[8]; /* Total DASD I/O wait time (queue time + pending */
  unsigned char  smf72idt[8]; /* Total DASD I/O disconnect time in              */
  int            smf72irc;    /* Total DASD I/O count. This can be used with    */
  int            smf72tou;    /* Total usings. Velocity should be calculated    */
  int            smf72iou;    /* Total I/O usings. These are included in        */
  int            smf72ndi;    /* Non DASD I/O using or delay               @E1A */
  int            smf72iod;    /* Total I/O delays.                         @F1A */
  unsigned char  smf72tsa[8]; /* Total execution samples. It is the sum of      */
  unsigned char  smf72iot[8]; /* Total DASD IOS queue time in 128 microsecond   */
  unsigned char  smf72qdt[4]; /* Total queue delay time. For batch jobs this    */
  unsigned char  smf72adt[4]; /* Total time batch jobs were ineligible to run   */
  unsigned char  smf72cvt[4]; /* Total time batch jobs spent in JCL conversion. */
  unsigned char  smf72iqt[4]; /* Total time batch jobs spend on job queue       */
  unsigned char  smf72iea[4]; /* Independent enclave total transaction active   */
  unsigned char  smf72xea[4]; /* Exported enclave total transaction active      */
  unsigned char  smf72fea[4]; /* Foreign enclave total transaction active time  */

#define smf72et1 smf72ets._smf72et1
#define smf72et2 smf72ets._smf72et2
#define smf72ft1 smf72frs._smf72ft1
#define smf72ft2 smf72frs._smf72ft2
#define smf72cus smf72vel._smf72cus
#define smf72tot smf72vel._smf72tot
  };

struct r722wkl {
  unsigned char  r722tsr[2];  /* Total number of small records in interval @W1A */
  unsigned char  _filler1[2]; /* Reserved for future use                   @W1A */
  unsigned char  r722tot[4];  /* Total number of data sections in interval @W1A */
  unsigned char  r722nxt[4];  /* Number of data sections in following      @W1A */
  unsigned char  r722ips[8];  /* Name of IPS                               @W1A */
  };

struct r722data {
  unsigned char  r722pg[2];   /* Performance group number                  @W1A */
  unsigned char  r722dmn[2];  /* Domain number                             @W1A */
  unsigned char  r722user[4]; /* Sum of all users found                    @W1A */
  unsigned char  r722actv[4]; /* Sum of all active users found             @W1A */
  unsigned char  r722page[4]; /* Sum of all users delayed for paging            */
  unsigned char  r722swap[4]; /* Sum of all users delayed for swapping          */
  unsigned char  r722outr[4]; /* Sum of all out and ready users                 */
  unsigned char  r722actf[4]; /* Sum of all active frames.                 @B1C */
  unsigned char  r722acts[4]; /* Sum of all active samples (except OUTR)   @W1A */
  unsigned char  r722idle[4]; /* Sum of all idle frames.                   @B1C */
  unsigned char  r722idls[4]; /* Sum of all idle samples                   @W1A */
  unsigned char  r722pgin[4]; /* Sum of all page-ins                       @W1A */
  unsigned char  r722slot[4]; /* Sum of all slots used                     @B1C */
  unsigned char  r722div[4];  /* Sum of all DIV frames                     @B1C */
  unsigned char  r722divs[4]; /* Sum of all DIV samples                    @W1A */
  unsigned char  r722fix[4];  /* Sum of all fixed frames                   @B1C */
  unsigned char  r722et[8];   /* Total elapsed time for all transactions        */
  unsigned char  r722qt[8];   /* Total time spent on JES or APPC queues by      */
  unsigned char  r722end[4];  /* The number of transactions that ended in       */
  unsigned char  r722upro[4]; /* Total processor using samples for the group    */
  unsigned char  r722udev[4]; /* Total device using samples for the group  @B1A */
  unsigned char  r722dpro[4]; /* Total processor delay samples for the group    */
  unsigned char  r722ddev[4]; /* Total device delay samples for the group  @B1A */
  unsigned char  r722dsto[4]; /* Total storage delay samples for the group @B1A */
  unsigned char  r722djes[4]; /* Total JES delay samples for the group     @B1A */
  unsigned char  r722dhsm[4]; /* Total HSM delay samples for the group     @B1A */
  unsigned char  r722dxcf[4]; /* Total XCF delay samples for the group     @B1A */
  unsigned char  r722denq[4]; /* Total ENQ delay samples for the group     @B1A */
  unsigned char  r722dmnt[4]; /* Total mount delay samples for the group   @B1A */
  unsigned char  r722dmsg[4]; /* Total message delay samples for the group @B1A */
  unsigned char  r722unkn[4]; /* Total unknown state samples for the group @B1A */
  unsigned char  r722vald[4]; /* Total valid samples for the group              */
  unsigned char  r722lsct[4]; /* Count of "long" logical swaps for the group    */
  unsigned char  r722esct[4]; /* Count of "long" swaps to expanded storage      */
  unsigned char  r722psct[4]; /* Count of "long" physical swaps for the group   */
  unsigned char  r722lscf[4]; /* Sum of all central frames for all logically    */
  unsigned char  r722lsef[4]; /* Sum of all expanded frames for all logically   */
  unsigned char  r722lssa[4]; /* Total logically swapped samples for the group  */
  unsigned char  r722psef[4]; /* Sum of all expanded frames for all swapped     */
  unsigned char  r722pssa[4]; /* Total swapped samples for the group            */
  unsigned char  r722vect[4]; /* Total vector utilization time for the group    */
  unsigned char  r722acff[4]; /* Sum of all active frames.                      */
  unsigned char  r722idlf[4]; /* Sum of all idle frames.                        */
  unsigned char  r722sltf[4]; /* Sum of all slots used                          */
  unsigned char  r722divf[4]; /* Sum of all DIV frames.                         */
  unsigned char  r722fixf[4]; /* Sum of all fixed frames.                       */
  unsigned char  r722tsv[8];  /* Sum of shared page views                       */
  unsigned char  r722vin[8];  /* Sum of shared pages in central storage, that   */
  unsigned char  r722vlc[8];  /* Sum of shared page validations                 */
  unsigned char  r722gpi[8];  /* Sum of shared page-ins from auxiliary storage  */
  };

struct r722swre {
  unsigned char  r722or1[4];  /* STOR/OUTR delay samples for swap reason 1:  */
  unsigned char  r722or2[4];  /* STOR/OUTR delay samples for swap reason 2:  */
  unsigned char  r722or3[4];  /* STOR/OUTR delay samples for swap reason 3:  */
  unsigned char  r722or4[4];  /* STOR/OUTR delay samples for swap reason 4:  */
  unsigned char  r722or5[4];  /* STOR/OUTR delay samples for swap reason 5:  */
  unsigned char  r722or6[4];  /* STOR/OUTR delay samples for swap reason 6:  */
  unsigned char  r722or7[4];  /* STOR/OUTR delay samples for swap reason 7:  */
  unsigned char  r722or8[4];  /* STOR/OUTR delay samples for swap reason 8:  */
  unsigned char  r722or9[4];  /* STOR/OUTR delay samples for swap reason 9:  */
  unsigned char  r722or10[4]; /* STOR/OUTR delay samples for swap reason 10: */
  unsigned char  r722or11[4]; /* STOR/OUTR delay samples for swap reason 11: */
  unsigned char  r722or12[4]; /* STOR/OUTR delay samples for swap reason 12: */
  unsigned char  r722or13[4]; /* STOR/OUTR delay samples for swap reason 13: */
  unsigned char  r722or14[4]; /* STOR/OUTR delay samples for swap reason 14: */
  unsigned char  r722or15[4]; /* STOR/OUTR delay samples for swap reason 15: */
  unsigned char  r722or16[4]; /* STOR/OUTR delay samples for swap reason 16: */
  unsigned char  r722or17[4]; /* STOR/OUTR delay samples for swap reason 17: */
  unsigned char  r722or18[4]; /* STOR/OUTR delay samples for swap reason 18: */
  };

struct r723wms {
  unsigned char  r723mscf;               /* Service class flags                       @C1A */
  unsigned char  r723mflg;               /* Flags                                     @K2A */
  unsigned char  r723mfl2;               /* Additional flags                          @92A */
  unsigned char  r723mrs2;               /* Reserved                                  @92C */
  unsigned char  r723mnsp[8];            /* Service policy name                       @C1A */
  unsigned char  r723mdsp[32];           /* Service policy description                @C1A */
  unsigned char  r723mtpa[8];            /* Local time/date (STCK format) of policy   @C1A */
  unsigned char  r723mcpu[4];            /* CPU service coefficient * 10,000          @C1A */
  unsigned char  r723mioc[4];            /* I/O service coefficient * 10,000          @C1A */
  unsigned char  r723mmso[4];            /* Storage service coefficient * 10,000      @C1A */
  unsigned char  r723msrb[4];            /* SRB service coefficient * 10,000          @C1A */
  unsigned char  r723mtvl[4];            /* Current sample interval (in milliseconds) @C1A */
  unsigned char  r723mtv_[4];            /* Total number of times WLM sampling code   @C1A */
  unsigned char  r723mopt[2];            /* OPT member suffix (from RCAAOPT)          @C1A */
  unsigned char  r723mrs3[2];            /* Reserved                                  @C1A */
  unsigned char  r723mwnm[8];            /* Workload group name                       @C1A */
  unsigned char  r723mwde[32];           /* Workload group description                @C1A */
  unsigned char  r723mcnm[8];            /* Service/Report class name                 @C1A */
  unsigned char  r723mcde[32];           /* Service/Report class description          @C1A */
  unsigned char  r723mcpg[2];            /* Number of periods belonging to this       @J2C */
  unsigned char  r723msub;               /* Number of entries belonging to a          @C1A */
  unsigned char  r723mrs4[3];            /* Reserved                                  @C1A */
  unsigned char  r723merf[6];            /* ERV resource factor coefficient           @C1A */
  int            r723madj;               /* Value of RMCTADJC - adjustment factor     @C1A */
  unsigned char  r723midn[8];            /* Service definition name                   @C1A */
  unsigned char  r723midd[32];           /* Service definition description            @C1A */
  unsigned char  r723mtdi[8];            /* Local time/date (STCK format) the service @C1A */
  unsigned char  r723midu[8];            /* Userid that installed the service         @C1A */
  unsigned char  r723clsc[8];            /* Service class that last contributed to    @J2A */
  struct {
    int            _r723nffi; /* Normalization factor for zAAP (IFA). Multiply */
    } r723nffcbp;
  int            r723nffs;               /* Normalization factor for zIIP. Multiply zIIP   */
  int            r723nadj;               /* Nominal adjustment factor for CPU rate         */
  int            r723ceca;               /* CEC adjustment factor                     @42A */
  int            r723mcf;                /* Multithreading maximum capacity numerator      */
  int            r723mcfs;               /* Multithreading maximum capacity numerator      */
  int            r723mcfi;               /* Multithreading maximum capacity numerator      */
  int            r723cpa_actual;
  int            r723cpa_scaling_factor;
  int            r723cpa_actual_zcbp;    /* Reserved for future use              @93C      */

#define r723nffi r723nffcbp._r723nffi
  };

/* Values for field "r723mscf" */
#define r723mrcl 0x80 /* This is a report class (RCAARCL)          @C1A */
#define r723mcaa 0x40 /* RCAA data not available                   @C1A */
#define r723mpol 0x20 /* SVPOL data not available                  @C1A */
#define r723move 0x10 /* System is calculating velocity using      @E2A */
#define r723mcpp 0x08 /* Indicator for CPU protection              @I2A */
#define r723mstp 0x04 /* Indicator for Storage protection          @I2A */
#define r723mdat 0x02 /* Indicator for dynamic alias management    @I2A */
#define r723mipg 0x01 /* Indicator for I/O priority group HIGH     @64A */

/* Values for field "r723mflg" */
#define r723mico 0x80 /* Indicator for zAAP (IFA) crossover        @K2A */
#define r723mhpo 0x40 /* Indicator for zAAP (IFA) honor priority   @K2A */
#define r723mhpz 0x20 /* Indicator for zIIP honor priority         @12A */
#define r723hisf 0x10 /* Failure returned by HISMT service.        @71A */
#define r723mnhp 0x08 /* Indicates ineligibility for honor priority.    */
#define r723mtrc 0x04 /* Indicator for a tenant report class       @91A */
#define r723mdis 0x02 /* Service class and tenant report class          */

/* Values for field "r723mfl2" */
#define r723mapo 0x80 /* At least one zAAP online in sysplex (or local  */
#define r723mcbo 0x40 /* Reserved for future use                   @93C */

/* Values for field "r723cpa_actual_zcbp" */
#define r723msec 2    /* Number (constant) of entries belonging to @C1A */

struct r723sss {
  unsigned char  r723scsn[8]; /* Name of service class being served        @C1A */
  unsigned char  r723scs_[4]; /* Number of times an AS running with this   @C1A */
  };

struct r723rgs {
  unsigned char  r723ggnm[8];  /* Resource group name                       @C1A */
  unsigned char  r723ggde[32]; /* Resource group description                @C1A */
  unsigned char  r723gglt;     /* Resource group flag bits                  @C1A */
  unsigned char  r723ggtf;     /* Tenant resource group flags               @91A */
  unsigned char  r723grs2[2];  /* Reserved                                  @91C */
  int            r723ggmn;     /* If R723GMNS is ON, minimum capacity of the     */
  int            r723ggmx;     /* If R723GMXS is ON, maximum capacity of the     */
  int            r723ggml;     /* If R723GMLS is ON, memory limit of the         */
  unsigned char  r723ggti[8];  /* Tenant identifier. Only valid if R723GTRG      */
  unsigned char  r723ggtn[32]; /* Tenant name. Only valid if R723GTRG is ON @91A */
  unsigned char  r723ggky[64]; /* Solution identifier. Only valid if R723GTRG    */
  };

/* Values for field "r723gglt" */
#define r723gmxs 0x80 /* Maximum capacity was specified            @C1A */
#define r723gmns 0x40 /* Minimum capacity was specified            @C1A */
#define r723ggpv 0x20 /* Specification of R723GGMN and R723GGMX is      */
#define r723ggpc 0x10 /* Specification of R723GGMN and R723GGMX is      */
#define r723gmls 0x08 /* Memory limit was specified                @83A */
#define r723ggms 0x04 /* Specification of R723GGMN and R723GGMX is      */
#define r723gisp 0x02 /* Specialty processor consumption is included    */
#define r723grs1 0x01 /* Reserved                                  @91C */

/* Values for field "r723ggtf" */
#define r723gtrg 0x80 /* Indicator for a tenant resource group     @91A */
#define r723gcbp 0x40 /* Reserved for future use                   @93C */

struct r723scs {
  unsigned char  r723crtx[2];     /* Index into the response time distribution @C1A    */
  unsigned char  r723cwmx[2];     /* Index into the work/resource manager      @C1A    */
  unsigned char  r723cwmn[2];     /* Number of entries in the work/resource    @C1A    */
  unsigned char  r723crs1;        /* Report class period flags                 @J2C    */
  unsigned char  r723cadf;        /* Actuals data section flag                 @C1A    */
  struct {
    unsigned char  _r723cper; /* Period number                             @J2C */
    } r723coal;
  unsigned char  r723crtf;        /* Response time flags                       @C1A    */
  unsigned char  r723crgf;        /* Response time goal flags                  @C1A    */
  unsigned char  r723crs4;        /* Reserved                                  @C1A    */
  unsigned char  r723cval[4];     /* Response time goal - or                   @C1A    */
  unsigned char  r723cpct[2];     /* Goal percentile value                     @C1A    */
  unsigned char  r723cimp[2];     /* Relative importance of the goal to be     @C1A    */
  unsigned char  r723cdur[4];     /* Service class period duration in service  @C1A    */
  struct {
    unsigned char  _r723csrv[8]; /* Total service units                       @C1A */
    } r723crcd;
  unsigned char  r723ccpu[8];     /* Total CPU service units                   @C1A    */
  unsigned char  r723cioc[8];     /* Total I/O service units                   @C1A    */
  unsigned char  r723cmso[8];     /* Total storage service units               @C1A    */
  unsigned char  r723csrb[8];     /* Total SRB service units                   @C1A    */
  unsigned char  r723cpir[8];     /* Total page-in count                       @C1A    */
  unsigned char  r723chpi[8];     /* Total hiperspace page-in count            @C1A    */
  unsigned char  r723cbpi[8];     /* Total block page-in from aux count        @C1A    */
  unsigned char  r723cpie[8];     /* Total page-in from expanded count         @C1A    */
  unsigned char  r723cbpe[8];     /* Total block page-in from expanded count   @C1A    */
  unsigned char  r723cbka[8];     /* Total aux blocks paged in                 @C1A    */
  unsigned char  r723cbke[8];     /* Total expanded blocks paged in            @C1A    */
  unsigned char  r723cprs[8];     /* Total Page residency time                 @C1A    */
  unsigned char  r723cers[8];     /* Total Expanded page residency time        @C1A    */
  unsigned char  r723ctrr[8];     /* Total in storage residency time           @C1A    */
  unsigned char  r723ctat[8];     /* Total transaction active time             @C1A    */
  unsigned char  r723crct[8];     /* Total RCT time (microseconds)             @C1A    */
  unsigned char  r723ciit[8];     /* Total I/O interrupt time (microseconds)   @C1A    */
  unsigned char  r723chst[8];     /* Total hiperspace service time             @C1A    */
  int            r723cswc;        /* Total swap count                          @C1A    */
  int            r723ccrm;        /* Total hiperspace eso read miss count      @C1A    */
  struct {
    int            _r723crcp; /* Count of transaction completions          @C1A */
    int            _r723carc; /* Count of transaction completed            @C1A */
    } r723crtd;
  int            r723cncp;        /* Count of transactions that completed      @C1A    */
  int            r723canc;        /* Count of transactions that completed      @C1A    */
  unsigned char  r723ctet[8];     /* Total transaction elapsed time            @C1A    */
  unsigned char  r723cxet[8];     /* Total transaction execution time          @C1A    */
  unsigned char  r723cets[8];     /* Sum of transaction elapsed times squared  @C1A    */
  struct {
    struct {
      int            _r723ccus; /* CPU using samples. These are included in    */
      int            _r723ctot; /* Total delay samples used in SRM's execution */
      } r723cevd;
    } r723cgde;
  struct {
    int            _r723ccde; /* CPU delay                                 @C1A */
    int            _r723ccca; /* CPU capping delay. A TCB or SRB is marked @C1A */
    } r723cedl;
  int            r723cswi;        /* Swap-in delay                             @C1A    */
  int            r723cmpl;        /* MPL delay                                 @C1A    */
  int            r723capr;        /* Aux page from private                     @C1A    */
  int            r723caco;        /* Aux page from common                      @C1A    */
  int            r723caxm;        /* Aux page from cross memory                @C1A    */
  int            r723cvio;        /* Aux page from VIO                         @C1A    */
  int            r723chsp;        /* Aux page from standard hiperspaces        @C1A    */
  int            r723cchs;        /* Aux page from eso hiperspaces             @C1A    */
  int            r723cunk;        /* Unknown                                   @C1A    */
  int            r723cidl;        /* Idle                                      @C1A    */
  int            r723cpde;        /* Resource group capping count              @C1A    */
  int            r723cpqu;        /* Quiesce count                             @C1A    */
  int            r723csac;        /* Sampled address space count. Number of    @C1A    */
  unsigned char  r723csrs[8];     /* Total shared page residency time                  */
  unsigned char  r723cspa[8];     /* Total shared page-ins from auxiliary storage      */
  unsigned char  r723cspe[8];     /* Total shared page-ins from expanded storage       */
  unsigned char  r723cict[8];     /* Total DASD I/O connect time in 128 micro-         */
  unsigned char  r723ciwt[8];     /* Total DASD I/O wait time (queue time + pending    */
  unsigned char  r723cidt[8];     /* Total DASD I/O disconnect time in 128 micro-      */
  int            r723circ;        /* Total DASD I/O count. This can be used with       */
  int            r723ctou;        /* Total usings. Velocity should be calculated as    */
  int            r723ciou;        /* Total I/O usings. These are included in R723CTOU. */
  int            r723ciod;        /* DASD I/O delay samples                      @E1A  */
  int            r723cq;          /* Queue delay samples. Work is waiting for a        */
  int            r723cspv;        /* Server private area paging delay samples    @E1A  */
  int            r723csvi;        /* Server space VIO paging delay samples       @E1A  */
  int            r723cshs;        /* Server hiperspace paging delay samples      @E1A  */
  int            r723csmp;        /* Server MPL delay samples                    @E1A  */
  int            r723cssw;        /* Server swap-in delay samples                @E1A  */
  int            r723cndi;        /* Non DASD I/O using or delay samples         @E1A  */
  int            r723ctdq;        /* Total delay samples always including batch        */
  unsigned char  r723ctsa[8];     /* Total execution samples. It is the sum of         */
  unsigned char  r723ciot[8];     /* Total DASD IOS queue time in 128 microsecond      */
  unsigned char  r723cqdt[8];     /* Total queue delay time. For batch jobs this       */
  unsigned char  r723cadt[8];     /* Total time batch jobs were ineligible to run      */
  unsigned char  r723ccvt[8];     /* Total time batch jobs spent in JCL conversion.    */
  unsigned char  r723ciqt[8];     /* Total time batch jobs spend on job queue          */
  unsigned char  r723ciea[8];     /* Independent enclave total transaction active      */
  unsigned char  r723cxea[8];     /* Exported enclave total transaction active         */
  unsigned char  r723cfea[8];     /* Foreign enclave total transaction active time     */
  int            r723camu;        /* No longer used                              @82C  */
  int            r723camd;        /* No longer used                              @82C  */
  int            r723apu;         /* AP crypto using samples. A TCB was found          */
  int            r723apd;         /* AP crypto delay samples. A TCB was found          */
  int            r723fqd;         /* Feature queue delay samples. A TCB was found      */
  unsigned char  r723plsc[8];     /* Service class that last contributed to  @WA56739  */
  int            r723rcod;        /* Contention delay sample count of work             */
  int            r723rcou;        /* Contention using sample count of work             */
  unsigned char  r723ectc[8];     /* CPU time consumed while dispatching priority      */
  struct {
    int            _r723ifau; /* zAAP (IFA) using samples                    @93C */
    } r723cbpu;
  struct {
    int            _r723ifcu; /* zAAP (IFA) on CP using samples. */
    } r723cbpcu;
  struct {
    int            _r723ifad; /* zAAP (IFA) delay samples                    @93C */
    } r723cbpd;
  unsigned char  r723ifat[8];     /* Reserved. Use R723CIFA to calculate zAAP          */
  unsigned char  r723ifct[8];     /* Reserved. Use R723CIFC to calculate zAAP          */
  int            r723supu;        /* zIIP using samples                      @OA13499  */
  int            r723sucu;        /* zIIP on CP using samples.                         */
  int            r723supd;        /* zIIP delay samples                      @OA13499  */
  unsigned char  r723csup[8];     /* Total service units on zIIPs                      */
  unsigned char  r723csuc[8];     /* Total service units on CPs by zIIP eligible       */
  struct {
    unsigned char  _r723cifa[8]; /* Total service units on zAAPs */
    } r723ccbp;
  struct {
    unsigned char  _r723cifc[8]; /* Total service units on CPs by zAAP eligible */
    } r723ccbpc;
  unsigned char  r723tpdp[8];     /* CPU time consumed while dispatching priority      */
  unsigned char  r723cpdp[8];     /* CPU time consumed while dispatching priority      */
  unsigned char  r723lpdp[8];     /* CPU time consumed while dispatching priority      */
  unsigned char  r723spdp[8];     /* CPU time consumed while dispatching priority      */
  int            r723rtdm;        /* Midpoint of all response times that were          */
  int            r723rtdc;        /* Number of midpoint changes that occurred          */
  unsigned char  r723rtdt[8];     /* Timestamp in STCK format, showing the last        */
  unsigned char  r723tsucp[8];    /* Total service units consumed by transactions,     */
  unsigned char  r723tsusp[8];    /* Total service units consumed by transactions,     */
  unsigned char  r723tsuocp[8];   /* Total service units consumed by transactions,     */
  unsigned char  r723msucp[8];    /* Service units consumed by transactions,           */
  unsigned char  r723msusp[8];    /* Service units consumed by transactions,           */
  unsigned char  r723msuocp[8];   /* Service units consumed by transactions,           */
  unsigned char  r723asucp[8];    /* Service units consumed by transactions,           */
  unsigned char  r723asusp[8];    /* Service units consumed by transactions,           */
  unsigned char  r723asuocp[8];   /* Service units consumed by transactions,           */
  unsigned char  r723bsucp[8];    /* Service units consumed by transactions,           */
  unsigned char  r723bsusp[8];    /* Service units consumed by transactions,           */
  unsigned char  r723bsuocp[8];   /* Service units consumed by transactions,           */
  unsigned char  r723ctetx[8];    /* Total transaction elapsed time.                   */
  unsigned char  r723cxetx[8];    /* Total transaction execution time.                 */
  unsigned char  r723cetsx[8];    /* Sum of transaction elapsed times squared.         */
  unsigned char  r723cqdtx[8];    /* Total queue delay time.                           */
  unsigned char  r723cadtx[8];    /* Total time batch jobs were ineligible to run      */
  unsigned char  r723ccvtx[8];    /* Total time batch jobs spent in JCL conversion.    */
  unsigned char  r723ciqtx[8];    /* Total time batch jobs spend on job queue          */
  unsigned char  r723tsucbp[8];   /* Reserved for future use                     @93C  */
  unsigned char  r723tsucbpcp[8]; /* Reserved for future use                     @93C  */

#define r723cper r723coal._r723cper
#define r723csrv r723crcd._r723csrv
#define r723crcp r723crtd._r723crcp
#define r723carc r723crtd._r723carc
#define r723ccus r723cgde.r723cevd._r723ccus
#define r723ctot r723cgde.r723cevd._r723ctot
#define r723ccde r723cedl._r723ccde
#define r723ccca r723cedl._r723ccca
#define r723ifau r723cbpu._r723ifau
#define r723ifcu r723cbpcu._r723ifcu
#define r723ifad r723cbpd._r723ifad
#define r723cifa r723ccbp._r723cifa
#define r723cifc r723ccbpc._r723cifc
  };

/* Values for field "r723crs1" */
#define r723crph 0x80 /* This report class period is heterogeneous @J2A */
#define r723crs6 0x7F /* Reserved                                  @J2A */

/* Values for field "r723cadf" */
#define r723crca 0x80 /* Resource consumption data actuals         @C1A */
#define r723crta 0x40 /* Response time data actuals (R723CRTD) are @C1A */
#define r723ceda 0x20 /* General execution delay data actuals      @C1A */
#define r723crs5 0x1F /* Reserved                                  @C1A */

/* Values for field "r723crtf" */
#define r723cmil 0x80 /* Response time specified in milliseconds   @C1A */
#define r723csec 0x40 /* Response time specified in seconds        @C1A */
#define r723cmin 0x20 /* Response time specified in minutes        @C1A */
#define r723chou 0x10 /* Response time specified in hours          @C1A */
#define r723crs2 0x0F /* Reserved                                  @C1A */

/* Values for field "r723crgf" */
#define r723cprc 0x80 /* Percentile response time goal             @C1A */
#define r723cavg 0x40 /* Average response time goal                @C1A */
#define r723cvel 0x20 /* Execution velocity goal                   @C1A */
#define r723cdsc 0x10 /* Discretionary goal                        @C1A */
#define r723cstm 0x08 /* System specified goal                     @C1A */
#define r723crs3 0x07 /* Reserved                                  @C1A */

struct r723rts {
  int            r723trdb; /* Response time distribution map and counts @C1A */
  };

/* Values for field "r723trdb" */
#define r723tent 14  /* Number of entries in an array. For RMF510 @C1A */

struct r723wrs {
  struct {
    unsigned char  _r723rtyp[4]; /* Subsystem name                            @C1A */
    unsigned char  _r723rflg;    /* Work/Resource manager flags               @C1A */
    unsigned char  _r723rrs2[3]; /* Reserved                                  @C1A */
    } r723rent;
  int            r723ress;    /* Total number of transaction states             */
  int            r723ract;    /* Total number of active state samples      @C1A */
  int            r723rrdy;    /* Total number of ready state samples       @C1A */
  int            r723ridl;    /* Total number of idle state samples. Idle  @C1A */
  int            r723rwlo;    /* Total number of waiting for lock state         */
  int            r723rwio;    /* Total number of waiting for I/O state          */
  int            r723rwco;    /* Total number of waiting for conversation       */
  int            r723rwds;    /* Total number of waiting for distributed        */
  int            r723rwsl;    /* Waiting for a session to be established        */
  int            r723rwsn;    /* Waiting for a session to be established        */
  int            r723rwss;    /* Waiting for a session to be established        */
  int            r723rwtm;    /* Waiting for a timer                       @C1A */
  int            r723rwo;     /* Waiting for another product               @C1A */
  int            r723rwms;    /* Waiting for unidentified resource         @C1A */
  int            r723rssl;    /* State representing transactions for            */
  int            r723rsss;    /* State representing transactions for            */
  int            r723rssn;    /* State representing transactions for            */
  int            r723rwst;    /* Total number of waiting for SSL thread         */
  int            r723rwrt;    /* Total number of waiting for regular            */
  int            r723rwwr;    /* Total number of waiting for work table         */
  int            r723rapp;    /* Total number of active application             */
  int            r723rwnl;    /* Total number of state samples reflecting       */
  int            r723rw01;    /* Total number of waiting for resource           */
  int            r723rw02;    /* Total number of waiting for resource           */
  int            r723rw03;    /* Total number of waiting for resource           */
  int            r723rw04;    /* Total number of waiting for resource           */
  int            r723rw05;    /* Total number of waiting for resource           */
  int            r723rw06;    /* Total number of waiting for resource           */
  int            r723rw07;    /* Total number of waiting for resource           */
  int            r723rw08;    /* Total number of waiting for resource           */
  int            r723rw09;    /* Total number of waiting for resource           */
  int            r723rw10;    /* Total number of waiting for resource           */
  int            r723rw11;    /* Total number of waiting for resource           */
  int            r723rw12;    /* Total number of waiting for resource           */
  int            r723rw13;    /* Total number of waiting for resource           */
  int            r723rw14;    /* Total number of waiting for resource           */
  int            r723rw15;    /* Total number of waiting for resource           */
  int            r723rbpm;    /* Number of state samples representing      @01A */
  unsigned char  r723rdnx[2]; /* Index into resource delay names table     @21A */
  unsigned char  r723rdnn[2]; /* Number of entries in the resource delay   @21A */
  unsigned char  r723rrs3[8]; /* Reserved                                  @21C */

#define r723rtyp r723rent._r723rtyp
#define r723rflg r723rent._r723rflg
#define r723rrs2 r723rent._r723rrs2
  };

/* Values for field "r723rflg" */
#define r723rdbe 0x80 /* Represents states sampled in the               */
#define r723rexe 0x40 /* Represents states sampled in the          @C1A */
#define r723rrs1 0x3F /* Reserved                                  @C1A */

struct r723dns {
  unsigned char  r723dnst[4];  /* Subsystem type as used in the classification   */
  unsigned char  r723dnnu[2];  /* Number of the resource delay type. Values      */
  unsigned char  r723dnde[16]; /* Resource delay description                @21A */
  unsigned char  r723rrs4[2];  /* Reserved                                  @21A */
  };

struct r724data {
  unsigned char  r724pnam[8]; /* Name of active service policy             @C2A */
  unsigned char  r724ptm[8];  /* Time policy was activated                      */
  unsigned char  r724lcnm[8]; /* Service class name                        @C2A */
  unsigned char  r724per_;    /* Service class period number               @C2A */
  unsigned char  _filler1[3]; /* Free for future use                       @C2A */
  unsigned char  r724user[4]; /* Sum of all users found                    @C2A */
  unsigned char  r724actv[4]; /* Sum of all active users found             @C2A */
  unsigned char  r724acts[4]; /* Sum of all active samples (except OUTR)   @C2A */
  unsigned char  r724idls[4]; /* Sum of all idle samples                   @C2A */
  unsigned char  r724page[4]; /* Sum of all users delayed for paging            */
  unsigned char  r724swap[4]; /* Sum of all users delayed for swapping          */
  unsigned char  r724outr[4]; /* Sum of all out and ready users                 */
  unsigned char  r724pgin[4]; /* Sum of all page-ins                       @C2A */
  unsigned char  r724divs[4]; /* Sum of all DIV samples                    @C2A */
  unsigned char  r724lssa[4]; /* Total logically swapped samples for the group  */
  unsigned char  r724pssa[4]; /* Total swapped samples for the group            */
  unsigned char  r724upro[4]; /* Total processor using samples for the group    */
  unsigned char  r724udev[4]; /* Total device using samples for the group  @C2A */
  unsigned char  r724dpro[4]; /* Total processor delay samples for the group    */
  unsigned char  r724ddev[4]; /* Total device delay samples for the group  @C2A */
  unsigned char  r724dsto[4]; /* Total storage delay samples for the group @C2A */
  unsigned char  r724djes[4]; /* Total JES delay samples for the group     @C2A */
  unsigned char  r724dhsm[4]; /* Total HSM delay samples for the group     @C2A */
  unsigned char  r724dxcf[4]; /* Total XCF delay samples for the group     @C2A */
  unsigned char  r724denq[4]; /* Total ENQ delay samples for the group     @C2A */
  unsigned char  r724dmnt[4]; /* Total mount delay samples for the group   @C2A */
  unsigned char  r724dmsg[4]; /* Total message delay samples for the group @C2A */
  unsigned char  r724unkn[4]; /* Total unknown state samples for the group @C2A */
  unsigned char  r724vald[4]; /* Total valid samples for the group              */
  unsigned char  r724lsct[4]; /* Count of "long" logical swaps for the group    */
  unsigned char  r724esct[4]; /* Count of "long" swaps to expanded storage      */
  unsigned char  r724psct[4]; /* Count of "long" physical swaps for the group   */
  unsigned char  r724actf[8]; /* Sum of all active frames                       */
  unsigned char  r724idle[8]; /* Sum of all idle frames                         */
  unsigned char  r724slot[8]; /* Sum of all slots used                          */
  unsigned char  r724div[8];  /* Sum of all DIV frames                          */
  unsigned char  r724fix[8];  /* Sum of all fixed frames                        */
  unsigned char  r724lscf[8]; /* Sum of all central frames for all logically    */
  unsigned char  r724lsef[8]; /* Sum of all expanded frames for all logically   */
  unsigned char  r724psef[8]; /* Sum of all expanded frames for all swapped     */
  unsigned char  r724vect[8]; /* Total vector utilization time for the group    */
  unsigned char  r724et[8];   /* Total execution time for all transactions      */
  unsigned char  r724qt[8];   /* Total time spent on JES or APPC queues by      */
  unsigned char  r724end[8];  /* The number of transactions that ended in       */
  unsigned char  r724tsv[8];  /* Sum of shared page views                       */
  unsigned char  r724vin[8];  /* Sum of shared pages in central storage, that   */
  unsigned char  r724vlc[8];  /* Sum of shared page validations                 */
  unsigned char  r724gpi[8];  /* Sum of shared page-ins from auxiliary storage  */
  unsigned char  r724etx[8];  /* Total execution time for all transactions      */
  unsigned char  r724qtx[8];  /* Total time spent on JES or APPC queues by      */
  };

struct r724swre {
  unsigned char  r724or1[4];  /* STOR/OUTR delay samples for swap reason 1:  */
  unsigned char  r724or2[4];  /* STOR/OUTR delay samples for swap reason 2:  */
  unsigned char  r724or3[4];  /* STOR/OUTR delay samples for swap reason 3:  */
  unsigned char  r724or4[4];  /* STOR/OUTR delay samples for swap reason 4:  */
  unsigned char  r724or5[4];  /* STOR/OUTR delay samples for swap reason 5:  */
  unsigned char  r724or6[4];  /* STOR/OUTR delay samples for swap reason 6:  */
  unsigned char  r724or7[4];  /* STOR/OUTR delay samples for swap reason 7:  */
  unsigned char  r724or8[4];  /* STOR/OUTR delay samples for swap reason 8:  */
  unsigned char  r724or9[4];  /* STOR/OUTR delay samples for swap reason 9:  */
  unsigned char  r724or10[4]; /* STOR/OUTR delay samples for swap reason 10: */
  unsigned char  r724or11[4]; /* STOR/OUTR delay samples for swap reason 11: */
  unsigned char  r724or12[4]; /* STOR/OUTR delay samples for swap reason 12: */
  unsigned char  r724or13[4]; /* STOR/OUTR delay samples for swap reason 13: */
  unsigned char  r724or14[4]; /* STOR/OUTR delay samples for swap reason 14: */
  unsigned char  r724or15[4]; /* STOR/OUTR delay samples for swap reason 15: */
  unsigned char  r724or16[4]; /* STOR/OUTR delay samples for swap reason 16: */
  unsigned char  r724or17[4]; /* STOR/OUTR delay samples for swap reason 17: */
  unsigned char  r724or18[4]; /* STOR/OUTR delay samples for swap reason 18: */
  unsigned char  r724or7a[4]; /* STOR/OUTR delay samples for swap reason 7:  */
  };

struct r725sctl {
  unsigned char  r725sgmo;     /* GRS Mode                                  @51A */
  unsigned char  _filler1[15]; /* Reserved                                  @51A */
  unsigned char  r725scms[8];  /* Total number of times that a unit of work      */
  unsigned char  r725scma[8];  /* Total number of times that a unit of work      */
  unsigned char  r725scmt[8];  /* Total amount of time in milliseconds that      */
  unsigned char  _filler2[8];  /* Reserved                                  @51A */
  unsigned char  r725seds[8];  /* Total number of times that a unit of work      */
  unsigned char  r725seda[8];  /* Total number of times that a unit of work      */
  unsigned char  r725sedt[8];  /* Total amount of time in milliseconds that      */
  unsigned char  _filler3[8];  /* Reserved                                  @51A */
  unsigned char  r725slas[8];  /* Total number of times that a unit of work      */
  unsigned char  r725slaa[8];  /* Total number of times that a unit of work      */
  unsigned char  r725slat[8];  /* Total amount of time in milliseconds that      */
  unsigned char  _filler4[8];  /* Reserved                                  @51A */
  unsigned char  r725ssms[8];  /* Total number of times that a unit of work      */
  unsigned char  r725ssma[8];  /* Total number of times that a unit of work      */
  unsigned char  r725ssmt[8];  /* Total amount of time in milliseconds that      */
  unsigned char  _filler5[8];  /* Reserved                                  @51A */
  unsigned char  r725slos[8];  /* Total number of times that a unit of work      */
  unsigned char  r725sloa[8];  /* Total number of times that a unit of work      */
  unsigned char  r725slot[8];  /* Total amount of time in milliseconds that      */
  unsigned char  _filler6[8];  /* Reserved                                  @51A */
  unsigned char  r725scls[8];  /* Total number of times that a unit of work      */
  unsigned char  r725scla[8];  /* Total number of times that a unit of work      */
  unsigned char  r725sclt[8];  /* Total amount of time in milliseconds that      */
  unsigned char  _filler7[8];  /* Reserved                                  @51A */
  unsigned char  r725slrc[8];  /* Total number of suspended Latch Obtain         */
  unsigned char  r725slrt[8];  /* Total amount of time in milliseconds that      */
  unsigned char  r725slrq[16]; /* Total sum of squares of time in milliseconds   */
  unsigned char  r725sstr[8];  /* Total number of ENQ SCOPE=STEP requests   @51A */
  unsigned char  r725ssts[8];  /* Total number of ENQ SCOPE=STEP requests        */
  unsigned char  r725sstt[8];  /* Total amount of suspend time in milliseconds   */
  unsigned char  _filler8[8];  /* Reserved                                  @51A */
  unsigned char  r725sstq[16]; /* Total sum of squares of suspend time in        */
  unsigned char  r725ssyr[8];  /* Total number of ENQ SCOPE=SYSTEM requests @51A */
  unsigned char  r725ssys[8];  /* Total number of ENQ SCOPE=SYSTEM requests      */
  unsigned char  r725ssyt[8];  /* Total amount of suspend time in milliseconds   */
  unsigned char  _filler9[8];  /* Reserved                                  @51A */
  unsigned char  r725ssyq[16]; /* Total sum of squares of suspend time in        */
  unsigned char  r725sssr[8];  /* Total number of ENQ SCOPE=SYSTEMS requests@51A */
  unsigned char  r725ssss[8];  /* Total number of ENQ SCOPE=SYSTEMS requests     */
  unsigned char  r725ssst[8];  /* Total amount of suspend time in milliseconds   */
  unsigned char  _filler10[8]; /* Reserved                                  @51A */
  unsigned char  r725sssq[16]; /* Total sum of squares of suspend time in        */
  };

struct r725cmsd {
  struct {
    unsigned char  _r725cmjn[8]; /* Name of job                               @51A */
    unsigned char  _filler1[3];  /* Reserved                                  @51A */
    unsigned char  _r725cmsp;    /* Service class period                      @51A */
    unsigned char  _r725cmas[2]; /* Address space ID                          @51A */
    short int      _filler2;     /* Reserved                                  @51A */
    } r725cmky;
  unsigned char  r725cmst[8]; /* Address space SToken                      @51A */
  unsigned char  r725cmsn[8]; /* Service class name                        @51A */
  unsigned char  r725cmty;    /* Lock Type                                 @51A */
  unsigned char  _filler3[7]; /* Reserved                                  @51A */
  unsigned char  r725cmsu[8]; /* Number of times that a unit of work of this    */
  unsigned char  r725cmal[8]; /* Number of times that a unit of work of this    */
  unsigned char  r725cmti[8]; /* Total amount of time in milliseconds that      */

#define r725cmjn r725cmky._r725cmjn
#define r725cmsp r725cmky._r725cmsp
#define r725cmas r725cmky._r725cmas
  };

struct r725lotd {
  struct {
    unsigned char  _r725lojn[8]; /* Name of job                               @51A */
    unsigned char  _filler1[3];  /* Reserved                                  @51A */
    unsigned char  _r725losp;    /* Service class period                      @51A */
    unsigned char  _r725loas[2]; /* Address space ID                          @51A */
    short int      _filler2;     /* Reserved                                  @51A */
    } r725loky;
  unsigned char  r725lost[8]; /* Address space SToken                      @51A */
  unsigned char  r725losn[8]; /* Service class name                        @51A */
  unsigned char  _filler3[8]; /* Reserved                                  @51A */
  unsigned char  r725losu[8]; /* Number of times that a unit of work of this    */
  unsigned char  r725loal[8]; /* Number of times that a unit of work of this    */
  unsigned char  r725loti[8]; /* Total amount of time in milliseconds that a    */
  unsigned char  r725lcsu[8]; /* Number of times that a unit of work from       */
  unsigned char  r725lcal[8]; /* Number of times that a unit of work from       */
  unsigned char  r725lcti[8]; /* Total amount of time in milliseconds that      */

#define r725lojn r725loky._r725lojn
#define r725losp r725loky._r725losp
#define r725loas r725loky._r725loas
  };

struct r725clod {
  struct {
    unsigned char  _r725cojn[8]; /* Name of job                               @51A */
    unsigned char  _filler1[3];  /* Reserved                                  @51A */
    unsigned char  _r725cosp;    /* Service class period                      @51A */
    unsigned char  _r725coas[2]; /* Address space ID                          @51A */
    short int      _filler2;     /* Reserved                                  @51A */
    } r725coky;
  unsigned char  r725cost[8]; /* Address space SToken                      @51A */
  unsigned char  r725cosn[8]; /* Service class name                        @51A */
  unsigned char  _filler3[8]; /* Reserved                                  @51A */
  unsigned char  r725cosu[8]; /* Number of times that a unit of work from       */
  unsigned char  r725coal[8]; /* Number of times that a unit of work from       */
  unsigned char  r725coti[8]; /* Total amount of time in milliseconds that      */
  unsigned char  r725clsu[8]; /* Number of times that a unit of work            */
  unsigned char  r725clal[8]; /* Number of times that a unit of work            */
  unsigned char  r725clti[8]; /* Total amount of time in milliseconds that      */

#define r725cojn r725coky._r725cojn
#define r725cosp r725coky._r725cosp
#define r725coas r725coky._r725coas
  };

struct r725clrd {
  struct {
    unsigned char  _r725crjn[8]; /* Name of job                               @51A */
    unsigned char  _filler1[3];  /* Reserved                                  @51A */
    unsigned char  _r725crsp;    /* Service class period                      @51A */
    unsigned char  _r725cras[2]; /* Address space ID                          @51A */
    short int      _filler2;     /* Reserved                                  @51A */
    } r725crky;
  unsigned char  r725crst[8]; /* Address space SToken                      @51A */
  unsigned char  r725crsn[8]; /* Service class name                        @51A */
  unsigned char  _filler3[8]; /* Reserved                                  @51A */
  unsigned char  r725crsu[8]; /* Number of times that a unit of work from       */
  unsigned char  r725cral[8]; /* Number of times that a unit of work from       */
  unsigned char  r725crti[8]; /* Total amount of time in milliseconds that      */

#define r725crjn r725crky._r725crjn
#define r725crsp r725crky._r725crsp
#define r725cras r725crky._r725cras
  };

struct r725latd {
  struct {
    unsigned char  _r725lajn[8]; /* Name of job                               @51A */
    unsigned char  _filler1[3];  /* Reserved                                  @51A */
    unsigned char  _r725lasp;    /* Service class period                      @51A */
    unsigned char  _r725laas[2]; /* Address space ID                          @51A */
    short int      _filler2;     /* Reserved                                  @51A */
    } r725laky;
  unsigned char  r725last[8];  /* Address space SToken                      @51A */
  unsigned char  r725lasn[8];  /* Service class name                        @51A */
  unsigned char  r725laty;     /* Lock Type                                 @51A */
  unsigned char  _filler3[7];  /* Reserved                                  @51A */
  unsigned char  r725lasu[8];  /* Number of times a Latch request for this       */
  unsigned char  r725lati[8];  /* Total amount of suspend time in milliseconds   */
  unsigned char  r725lasq[16]; /* Sum of squares of the individual suspend times */

#define r725lajn r725laky._r725lajn
#define r725lasp r725laky._r725lasp
#define r725laas r725laky._r725laas
  };

struct r725entd {
  struct {
    unsigned char  _r725enjn[8]; /* Name of job                               @51A */
    unsigned char  _filler1[3];  /* Reserved                                  @51A */
    unsigned char  _r725ensp;    /* Service class period                      @51A */
    unsigned char  _r725enas[2]; /* Address space ID                          @51A */
    short int      _filler2;     /* Reserved                                  @51A */
    } r725enky;
  unsigned char  r725enst[8];  /* Address space SToken                      @51A */
  unsigned char  r725ensn[8];  /* Service class name                        @51A */
  unsigned char  r725ensc;     /* Enqueue Scope Type                        @51A */
  unsigned char  _filler3[7];  /* Reserved                                  @51A */
  unsigned char  r725enrc[8];  /* Number of GRS ENQ requests with the scope      */
  unsigned char  r725ensu[8];  /* Number of GRS ENQ requests with the scope      */
  unsigned char  r725enti[8];  /* Total amount of suspend time in milliseconds   */
  unsigned char  r725ensq[16]; /* Sum of squares of the individual suspend times */

#define r725enjn r725enky._r725enjn
#define r725ensp r725enky._r725ensp
#define r725enas r725enky._r725enas
  };

struct r725qsad {
  struct {
    unsigned char  _r725qsjn[8]; /* Name of job                               @63A */
    unsigned char  _filler1[3];  /* Reserved                                  @63A */
    unsigned char  _r725qssp;    /* Service class period                      @63A */
    unsigned char  _r725qsas[2]; /* Address space ID                          @63A */
    short int      _filler2;     /* Reserved                                  @63A */
    } r725qsky;
  unsigned char  r725qsst[8];  /* Address space SToken                      @63A */
  unsigned char  r725qssn[8];  /* Service class name                        @63A */
  unsigned char  _filler3[8];  /* Reserved                                  @63A */
  unsigned char  r725qsrc[8];  /* Number of requests including START and RESUME, */
  unsigned char  r725qssc[8];  /* Number of specific requests with GQSCAN        */
  unsigned char  r725qsrr[8];  /* Total number of resources returned for         */
  unsigned char  r725qsrq[16]; /* Sum of squares of number of resources          */
  unsigned char  r725qsti[8];  /* Total amount of execution times within         */
  unsigned char  r725qstq[16]; /* Sum of squares of individual request           */

#define r725qsjn r725qsky._r725qsjn
#define r725qssp r725qsky._r725qssp
#define r725qsas r725qsky._r725qsas
  };

#pragma pack(reset)
