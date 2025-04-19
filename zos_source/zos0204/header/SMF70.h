/* SPDX-License-Identifier: GPL-3.0-only or GPL-3.0-or-later */
/*
 * SMF70 Header File for supporting the generation of JSON.
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
#define TARGET_SMF_TYPE 70
#define SMF70           70
#define SMF70ST1        1
#define SMF70ST2        2

#include "smf70h.h"

void printSMFHeaderST1(struct smf70hdr *recPtr,FILE* fp) {
  fprintf(fp,"\"header\":{");
  fprintf(fp,"\"recLen\":%u",*(short *)recPtr->smf70len);
  fprintf(fp,",\"sysInd\":\"0x%2.2X\"",recPtr->smf70flg);
  fprintf(fp,",\"recType\":%u",recPtr->smf70rty);
  fprintPkChTDate(fp,"dateTime",recPtr->smf70tme, recPtr->smf70dte,
                  TRUE);
  fprintf(fp,",\"sysId\":\"%.4s\"",recPtr->smf70sid);
  fprintf(fp,",\"subSysId\":\"%.4s\"",recPtr->smf70ssi);
  fprintf(fp,",\"subType\":%d",*(short *)recPtr->smf70sty);
  fprintf(fp,",\"smf70prn\":%u",*(short *)recPtr->smf70prn);
  fprintf(fp,",\"smf70ccn\":%u",*(short *)recPtr->smf70ccn);
  fprintf(fp,",\"smf70cpn\":%u",*(short *)recPtr->smf70cpn);
  fprintf(fp,",\"smf70asn\":%u",*(short *)recPtr->smf70asn);
  fprintf(fp,",\"smf70bcn\":%u",*(short *)recPtr->smf70bcn);
  fprintf(fp,",\"smf70bvn\":%u",*(short *)recPtr->smf70bvn);
  fprintf(fp,",\"smf70cnn\":%u",*(short *)recPtr->smf70cnn);
  fprintf(fp,",\"smf70con\":%u",*(short *)recPtr->smf70con);
  fprintf(fp,",\"smf70tnn\":%u",*(short *)recPtr->smf70tnn);
  fprintf(fp,"}");
}

void printSMFHeaderST2(struct smf70hdr *recPtr,FILE* fp) {
  fprintf(fp,"\"header\":{");
  fprintf(fp,"\"recLen\":%u",*(short *)recPtr->smf70len);
  fprintf(fp,",\"sysInd\":\"0x%2.2X\"",recPtr->smf70flg);
  fprintf(fp,",\"recType\":%u",recPtr->smf70rty);
  fprintPkChTDate(fp,"dateTime",recPtr->smf70tme, recPtr->smf70dte,
                  TRUE);
  fprintf(fp,",\"sysId\":\"%.4s\"",recPtr->smf70sid);
  fprintf(fp,",\"subSysId\":\"%.4s\"",recPtr->smf70ssi);
  fprintf(fp,",\"subType\":%d",*(short *)recPtr->smf70sty);
  fprintf(fp,",\"smf70prn\":%u",*(short *)recPtr->smf70prn);
  fprintf(fp,",\"smf7023n\":%u",*(short *)recPtr->smf7023n);
  fprintf(fp,",\"smf7024n\":%u",*(short *)recPtr->smf7024n);
  fprintf(fp,",\"smf702cn\":%u",*(short *)recPtr->smf702cn);
  fprintf(fp,",\"smf7025n\":%u",*(short *)recPtr->smf7025n);
  fprintf(fp,"}");
}

void printReasmInform(struct smf70rbl *rbl, short recLen,
                   short count, FILE *fp)
{
  struct smf70rbl *recPtr;
  fprintf(fp,",\"smf70rbl\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct smf70rbl *)((void *)rbl + i*recLen);
    fprintf(fp,"\"smf70rnn\":%u",*(short *)recPtr->smf70rnn);
    fprintf(fp,",\"smf70rpp\":%u",*(short *)recPtr->smf70rpp);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printReasm(struct smf70rhd *recPtr, FILE *fp) {
  struct smf70rbl *rbl;
  fprintf(fp,",\"smf70rbr\":%u",*(short *)recPtr->smf70rbr);
  fprintf(fp,",\"smf70rsq\":%u",*(short *)recPtr->smf70rsq);
  fprintf(fp,",\"smf70rio\":%u",*(int *)recPtr->smf70rio);
  fprintf(fp,",\"smf70ril\":%u",*(short *)recPtr->smf70ril);
  fprintf(fp,",\"smf70rin\":%u",*(short *)recPtr->smf70rin);

  if(*(short *)recPtr->smf70rin > 0)
  {
    rbl = (struct smf70rbl *)((void *)recPtr +
                              *(int *)(recPtr->smf70rio));
    printReasmInform(rbl,*(short *)recPtr->smf70ril,
                         *(short *)recPtr->smf70rin, fp);
  }
}

void printProdSect(struct smf70pro *recPtr, FILE *fp) {
  struct smf70rhd *rhd;
  int temp=0;
  fprintf(fp,",\"smf70pro\":{");
  frompd(recPtr->smf70mfv,3,&temp);
  fprintf(fp,"\"smf70mfv\":%u",temp);
  fprintEbcdicStr(fp,"smf70prd",8,recPtr->smf70prd,TRUE,TRUE);
  fprintPkDate(fp,"smf70ist",recPtr->smf70ist, recPtr->smf70dat, TRUE);
  fprintPkMilliTime(fp,"smf70int",recPtr->smf70int,TRUE);
  fprintf(fp,",\"smf70sam\":%u",*(int *)recPtr->smf70sam);
  fprintHexString(fp,"smf70fla",2,recPtr->smf70fla,FALSE,TRUE);

  frompd(recPtr->smf70cyc,7,&temp);
  fprintf(fp,",\"smf70cyc\":%u",temp);

  fprintEbcdicStr(fp,"smf70mvs",8, recPtr->smf70mvs,TRUE,TRUE);
  fprintf(fp,",\"smf70iml\":%u",recPtr->smf70iml);
  fprintf(fp,",\"smf70prf\":\"0x%2.2X\"",recPtr->smf70prf);
  fprintf(fp,",\"smf70ptn\":%u",recPtr->smf70ptn);
  fprintf(fp,",\"smf70srl\":\"0x%2.2X\"",recPtr->smf70srl);
  fprintHexString(fp,"smf70iet",8,recPtr->smf70iet,FALSE,TRUE);
  fprintStckTimeConv(fp,"smf70lgo",recPtr->smf70lgo,TRUE,TRUE);
  fprintf(fp,",\"smf70rao\":%u",*(int *)recPtr->smf70rao);
  fprintf(fp,",\"smf70ral\":%u",*(short *)recPtr->smf70ral);
  fprintf(fp,",\"smf70ran\":%u",*(short *)recPtr->smf70ran);
  fprintf(fp,",\"smf70oil\":%u",*(short *)recPtr->smf70oil);
  fprintf(fp,",\"smf70syn\":%u",*(short *)recPtr->smf70syn);
  fprintStckConv(fp,"smf70gie",recPtr->smf70gie,TRUE);
  fprintEbcdicStr(fp,"smf70xnm",8, recPtr->smf70xnm,TRUE,TRUE);
  fprintEbcdicStr(fp,"smf70snm",8, recPtr->smf70snm,TRUE,TRUE);

  if(*(short *)recPtr->smf70ral > 0)
  {
    rhd = (struct smf70rhd *)((void *)recPtr +
                              *(int *)(recPtr->smf70rao));
    printReasm(rhd, fp);
  }
  fprintf(fp,"}");
}


void printCpuCtlSect(struct smf70ctl *recPtr, FILE *fp) {
  fprintf(fp,",\"smf70ctl\":{");
  fprintHexString(fp,"smf70mod",2,recPtr->smf70mod,FALSE,FALSE);
  fprintf(fp,",\"smf70ver\":%u",recPtr->smf70ver);
  fprintf(fp,",\"smf70bnp\":%u",recPtr->smf70bnp);
  fprintf(fp,",\"smf70inb\":\"0x%2.2X\"",recPtr->smf70inb);
  fprintf(fp,",\"smf70stf\":\"0x%2.2X\"",recPtr->smf70stf);
  fprintMilliTime(fp,"smf70gts",*(short *)recPtr->smf70gts,1,TRUE);
  fprintEbcdicStr(fp,"smf70mdl",16, recPtr->smf70mdl,TRUE,TRUE);
  fprintf(fp,",\"smf70dsa\":%u",*(short *)recPtr->smf70dsa);
  fprintf(fp,",\"smf70ifa\":%u",*(short *)recPtr->smf70ifa);
  fprintf(fp,",\"smf70cpa\":%u",*(int *)recPtr->smf70cpa);
  fprintf(fp,",\"smf70wla\":%u",*(int *)recPtr->smf70wla);
  fprintf(fp,",\"smf70lac\":%u",*(int *)recPtr->smf70lac);
  fprintStckTimeConv(fp,"smf70hof",recPtr->smf70hof,TRUE,TRUE);
  fprintEbcdicStr(fp,"smf70hwm",16, recPtr->smf70hwm,TRUE,TRUE);
  fprintf(fp,",\"smf70sup\":%u",*(short *)recPtr->smf70sup);
  fprintStckConv(fp,"smf70gjt",recPtr->smf70gjt,TRUE);
  fprintEbcdicStr(fp,"smf70pom",4, recPtr->smf70pom,FALSE,TRUE);
  fprintEbcdicStr(fp,"smf70csc",16, recPtr->smf70csc,TRUE,TRUE);
  fprintf(fp,",\"smf70hhf\":\"0x%2.2X\"",recPtr->smf70hhf);
  fprintf(fp,",\"smf70cr\":%u",recPtr->smf70cr);
  fprintf(fp,",\"smf70pmi\":%u",recPtr->smf70pmi);
  fprintf(fp,",\"smf70pmu\":%u",recPtr->smf70pmu);
  fprintf(fp,",\"smf70pmw\":%u",recPtr->smf70pmw);
  fprintf(fp,",\"smf70pmp\":%u",recPtr->smf70pmp);
  fprintMilliTime(fp,"smf70pmt",recPtr->smf70pmt,1,TRUE);
  fprintf(fp,",\"smf70pml\":%u",recPtr->smf70pml);
  fprintEbcdicStr(fp,"smf70mpc",16, recPtr->smf70mpc,TRUE,TRUE);
  fprintEbcdicStr(fp,"smf70mtc",16, recPtr->smf70mtc,TRUE,TRUE);
  fprintf(fp,",\"smf70mcr\":%u",recPtr->smf70mcr);
  fprintf(fp,",\"smf70mpr\":%u",recPtr->smf70mpr);
  fprintf(fp,",\"smf70mtr\":%u",recPtr->smf70mtr);
  fprintf(fp,",\"smf70zep\":%u",recPtr->smf70zep);
  fprintf(fp,",\"smf70zer\":%llu",*(ull)recPtr->smf70zer);
  fprintf(fp,",\"smf70zee\":%llu",*(ull)recPtr->smf70zee);
  fprintf(fp,",\"smf70zec\":%llu",*(ull)recPtr->smf70zec);
  fprintf(fp,",\"smf70nrm\":%u",recPtr->smf70nrm);
  fprintf(fp,",\"smf70gau\":%d",recPtr->smf70gau);
  fprintf(fp,",\"smf70zei\":%llu",*(ull)recPtr->smf70zei);
  fprintf(fp,",\"smf70ncr\":%u",recPtr->smf70ncr);
  fprintf(fp,",\"smf70npr\":%u",recPtr->smf70npr);
  fprintf(fp,",\"smf70ntr\":%u",recPtr->smf70ntr);
  fprintf(fp,",\"smf70cai\":%u",recPtr->smf70cai);
  fprintf(fp,",\"smf70ccr\":%u",recPtr->smf70ccr);
  fprintf(fp,",\"smf70mcp\":%u",recPtr->smf70mcp);
  fprintf(fp,",\"smf70icp\":%u",recPtr->smf70icp);
  fprintf(fp,",\"smf70ccp\":%u",recPtr->smf70ccp);
  fprintf(fp,",\"smf70cpa_actual\":%u",*(int*)recPtr->smf70cpa_actual);
  fprintf(fp,",\"smf70cpa_scaling_factor\":%u",
   *(int *)recPtr->smf70cpa_scaling_factor);
  fprintf(fp,",\"smf70mcf\":%u",recPtr->smf70mcf);
  fprintf(fp,",\"smf70mcfs\":%u",recPtr->smf70mcfs);
  fprintf(fp,",\"smf70mcfi\":%u",recPtr->smf70mcfi);
  fprintf(fp,",\"smf70cf\":%u",recPtr->smf70cf);
  fprintf(fp,",\"smf70cfs\":%u",recPtr->smf70cfs);
  fprintf(fp,",\"smf70cfi\":%u",recPtr->smf70cfi);
  fprintf(fp,",\"smf70atd\":%u",recPtr->smf70atd);
  fprintf(fp,",\"smf70atds\":%u",recPtr->smf70atds);
  fprintf(fp,",\"smf70atdi\":%u",recPtr->smf70atdi);
  fprintf(fp,",\"smf70lacm\":%u",*(int *)recPtr->smf70lacm);
  fprintf(fp,",\"smf70laca\":%u",*(int *)recPtr->smf70laca);
  fprintf(fp,",\"smf70lacb\":%u",*(int *)recPtr->smf70lacb);
  fprintf(fp,",\"smf70adj\":%u",*(int *)recPtr->smf70adj);
  fprintf(fp,",\"smf70laccr\":%u",*(int *)recPtr->smf70laccr);
  fprintf(fp,",\"smf70maxpu\":%u",recPtr->smf70maxpu);
  fprintf(fp,",\"smf70os_prtct\":%u",recPtr->smf70os_prtct);
  fprintEbcdicStr(fp,"smf70mdl_cbp",16,recPtr->smf70mdl_cbp,TRUE,TRUE);
  fprintf(fp,",\"smf70mcr_cbp\":%u",recPtr->smf70mcr_cbp);
  fprintf(fp,",\"smf70ncr_cbp\":%u",recPtr->smf70ncr_cbp);
  fprintf(fp,",\"smf70lac_cbp\":%u",*(int *)recPtr->smf70lac_cbp);
  fprintStckConv(fp,"smf70_ipl_time",recPtr->smf70_ipl_time,TRUE);
  fprintf(fp,",\"smf70_trg_m_cnt\":%u",
   *(int *)recPtr->smf70_trg_m_cnt);
  fprintHexString(fp,"smf70crw",4,recPtr->smf70crw,FALSE,TRUE);
  fprintEbcdicStr(fp,"smf70cpc_type",4,recPtr->smf70cpc_type,TRUE,TRUE);

  fprintf(fp,"}");
}

void printCpuDataSect(struct smf70cpu *cpu, short recLen,
                   short count, FILE *fp)
{
  struct smf70cpu *recPtr;
  char* temp;
  temp = malloc(4);
  memset(temp, '\0', 4);

  fprintf(fp,",\"smf70cpu\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct smf70cpu *)((void *)cpu + i*recLen);
    fprintStckTimeConv(fp,"smf70wat",recPtr->smf70wat,FALSE,FALSE);
    fprintf(fp,",\"smf70cid\":%u",*(short *)recPtr->smf70cid);
    fprintf(fp,",\"smf70cnf\":\"0x%2.2X\"",recPtr->smf70cnf);
    fprintHexString(fp,"smf70ser",3,recPtr->smf70ser,FALSE,TRUE);
    fprintf(fp,",\"smf70typ\":%u",recPtr->smf70typ);
    fprintf(fp,",\"smf70slh\":%u",*(int *)recPtr->smf70slh);
    fprintf(fp,",\"smf70tpi\":%u",*(int *)recPtr->smf70tpi);
    fprintf(fp,",\"smf70vfs\":%u",*(int *)recPtr->smf70vfs);
    fprintf(fp,",\"smf70v\":\"0x%2.2X\"",recPtr->smf70v);
    fprintStckTimeConv(fp,"smf70pat",recPtr->smf70pat,FALSE,TRUE);
    fprintf(fp,",\"smf70tcb\":%llu",*(ull)recPtr->smf70tcb);
    fprintf(fp,",\"smf70srb\":%llu",*(ull)recPtr->smf70srb);
    fprintf(fp,",\"smf70nio\":%llu",*(ull)recPtr->smf70nio);
    fprintf(fp,",\"smf70sig\":%llu",*(ull)recPtr->smf70sig);
    strncpy(temp, recPtr->smf70wtd, 4);
    if (*(int *)temp == 0xFFFFFFFF)
      fprintf(fp,",\"smf70wtd\":%u",*(int *)((void*)recPtr->smf70wtd+4));
    else
      fprintf(fp,",\"smf70wtd\":%llu",*(ull)recPtr->smf70wtd);
    fprintf(fp,",\"smf70wts\":%u",*(int *)recPtr->smf70wts);
    fprintf(fp,",\"smf70wtu\":%u",*(int *)recPtr->smf70wtu);

    fprintMilliTime(fp,"smf70wti",*(int *)recPtr->smf70wti,1,TRUE);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printAsidDataSect(struct smf70aid *aid, short recLen,
                   short count, FILE *fp)
{
  struct smf70aid *recPtr;

  fprintf(fp,",\"smf70aid\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct smf70aid *)((void *)aid + i*recLen);
    fprintf(fp,"\"smf70rmn\":%u",recPtr->smf70rmn);
    fprintf(fp,",\"smf70rmm\":%u",recPtr->smf70rmm);
    fprintf(fp,",\"smf70rtt\":%u",recPtr->smf70rtt);
    fprintf(fp,",\"smf70r00\":%u",recPtr->smf70r00);
    fprintf(fp,",\"smf70r01\":%u",recPtr->smf70r01);
    fprintf(fp,",\"smf70r02\":%u",recPtr->smf70r02);
    fprintf(fp,",\"smf70r03\":%u",recPtr->smf70r03);
    fprintf(fp,",\"smf70r04\":%u",recPtr->smf70r04);
    fprintf(fp,",\"smf70r05\":%u",recPtr->smf70r05);
    fprintf(fp,",\"smf70r06\":%u",recPtr->smf70r06);
    fprintf(fp,",\"smf70r07\":%u",recPtr->smf70r07);
    fprintf(fp,",\"smf70r08\":%u",recPtr->smf70r08);
    fprintf(fp,",\"smf70r09\":%u",recPtr->smf70r09);
    fprintf(fp,",\"smf70r10\":%u",recPtr->smf70r10);
    fprintf(fp,",\"smf70r11\":%u",recPtr->smf70r11);
    fprintf(fp,",\"smf70r12\":%u",recPtr->smf70r12);
    fprintf(fp,",\"smf70r13\":%u",recPtr->smf70r13);
    fprintf(fp,",\"smf70r14\":%u",recPtr->smf70r14);
    fprintf(fp,",\"smf70r15\":%u",recPtr->smf70r15);
    fprintf(fp,",\"smf70imn\":%u",recPtr->smf70imn);
    fprintf(fp,",\"smf70imm\":%u",recPtr->smf70imm);
    fprintf(fp,",\"smf70itt\":%u",recPtr->smf70itt);
    fprintf(fp,",\"smf70i00\":%u",recPtr->smf70i00);
    fprintf(fp,",\"smf70i01\":%u",recPtr->smf70i01);
    fprintf(fp,",\"smf70i02\":%u",recPtr->smf70i02);
    fprintf(fp,",\"smf70i03\":%u",recPtr->smf70i03);
    fprintf(fp,",\"smf70i04\":%u",recPtr->smf70i04);
    fprintf(fp,",\"smf70i05\":%u",recPtr->smf70i05);
    fprintf(fp,",\"smf70i06\":%u",recPtr->smf70i06);
    fprintf(fp,",\"smf70i07\":%u",recPtr->smf70i07);
    fprintf(fp,",\"smf70i08\":%u",recPtr->smf70i08);
    fprintf(fp,",\"smf70i09\":%u",recPtr->smf70i09);
    fprintf(fp,",\"smf70i10\":%u",recPtr->smf70i10);
    fprintf(fp,",\"smf70i11\":%u",recPtr->smf70i11);
    fprintf(fp,",\"smf70omn\":%u",recPtr->smf70omn);
    fprintf(fp,",\"smf70omm\":%u",recPtr->smf70omm);
    fprintf(fp,",\"smf70ott\":%u",recPtr->smf70ott);
    fprintf(fp,",\"smf70o00\":%u",recPtr->smf70o00);
    fprintf(fp,",\"smf70o01\":%u",recPtr->smf70o01);
    fprintf(fp,",\"smf70o02\":%u",recPtr->smf70o02);
    fprintf(fp,",\"smf70o03\":%u",recPtr->smf70o03);
    fprintf(fp,",\"smf70o04\":%u",recPtr->smf70o04);
    fprintf(fp,",\"smf70o05\":%u",recPtr->smf70o05);
    fprintf(fp,",\"smf70o06\":%u",recPtr->smf70o06);
    fprintf(fp,",\"smf70o07\":%u",recPtr->smf70o07);
    fprintf(fp,",\"smf70o08\":%u",recPtr->smf70o08);
    fprintf(fp,",\"smf70o09\":%u",recPtr->smf70o09);
    fprintf(fp,",\"smf70o10\":%u",recPtr->smf70o10);
    fprintf(fp,",\"smf70o11\":%u",recPtr->smf70o11);
    fprintf(fp,",\"smf70wmn\":%u",recPtr->smf70wmn);
    fprintf(fp,",\"smf70wmm\":%u",recPtr->smf70wmm);
    fprintf(fp,",\"smf70wtt\":%u",recPtr->smf70wtt);
    fprintf(fp,",\"smf70w00\":%u",recPtr->smf70w00);
    fprintf(fp,",\"smf70w01\":%u",recPtr->smf70w01);
    fprintf(fp,",\"smf70w02\":%u",recPtr->smf70w02);
    fprintf(fp,",\"smf70w03\":%u",recPtr->smf70w03);
    fprintf(fp,",\"smf70w04\":%u",recPtr->smf70w04);
    fprintf(fp,",\"smf70w05\":%u",recPtr->smf70w05);
    fprintf(fp,",\"smf70w06\":%u",recPtr->smf70w06);
    fprintf(fp,",\"smf70w07\":%u",recPtr->smf70w07);
    fprintf(fp,",\"smf70w08\":%u",recPtr->smf70w08);
    fprintf(fp,",\"smf70w09\":%u",recPtr->smf70w09);
    fprintf(fp,",\"smf70w10\":%u",recPtr->smf70w10);
    fprintf(fp,",\"smf70w11\":%u",recPtr->smf70w11);
    fprintf(fp,",\"smf70bmn\":%u",recPtr->smf70bmn);
    fprintf(fp,",\"smf70bmm\":%u",recPtr->smf70bmm);
    fprintf(fp,",\"smf70btt\":%u",recPtr->smf70btt);
    fprintf(fp,",\"smf70b00\":%u",recPtr->smf70b00);
    fprintf(fp,",\"smf70b01\":%u",recPtr->smf70b01);
    fprintf(fp,",\"smf70b02\":%u",recPtr->smf70b02);
    fprintf(fp,",\"smf70b03\":%u",recPtr->smf70b03);
    fprintf(fp,",\"smf70b04\":%u",recPtr->smf70b04);
    fprintf(fp,",\"smf70b05\":%u",recPtr->smf70b05);
    fprintf(fp,",\"smf70b06\":%u",recPtr->smf70b06);
    fprintf(fp,",\"smf70b07\":%u",recPtr->smf70b07);
    fprintf(fp,",\"smf70b08\":%u",recPtr->smf70b08);
    fprintf(fp,",\"smf70b09\":%u",recPtr->smf70b09);
    fprintf(fp,",\"smf70b10\":%u",recPtr->smf70b10);
    fprintf(fp,",\"smf70b11\":%u",recPtr->smf70b11);
    fprintf(fp,",\"smf70smn\":%u",recPtr->smf70smn);
    fprintf(fp,",\"smf70smm\":%u",recPtr->smf70smm);
    fprintf(fp,",\"smf70stt\":%u",recPtr->smf70stt);
    fprintf(fp,",\"smf70s00\":%u",recPtr->smf70s00);
    fprintf(fp,",\"smf70s01\":%u",recPtr->smf70s01);
    fprintf(fp,",\"smf70s02\":%u",recPtr->smf70s02);
    fprintf(fp,",\"smf70s03\":%u",recPtr->smf70s03);
    fprintf(fp,",\"smf70s04\":%u",recPtr->smf70s04);
    fprintf(fp,",\"smf70s05\":%u",recPtr->smf70s05);
    fprintf(fp,",\"smf70s06\":%u",recPtr->smf70s06);
    fprintf(fp,",\"smf70s07\":%u",recPtr->smf70s07);
    fprintf(fp,",\"smf70s08\":%u",recPtr->smf70s08);
    fprintf(fp,",\"smf70s09\":%u",recPtr->smf70s09);
    fprintf(fp,",\"smf70s10\":%u",recPtr->smf70s10);
    fprintf(fp,",\"smf70s11\":%u",recPtr->smf70s11);
    fprintf(fp,",\"smf70tmn\":%u",recPtr->smf70tmn);
    fprintf(fp,",\"smf70tmm\":%u",recPtr->smf70tmm);
    fprintf(fp,",\"smf70ttt\":%u",recPtr->smf70ttt);
    fprintf(fp,",\"smf70t00\":%u",recPtr->smf70t00);
    fprintf(fp,",\"smf70t01\":%u",recPtr->smf70t01);
    fprintf(fp,",\"smf70t02\":%u",recPtr->smf70t02);
    fprintf(fp,",\"smf70t03\":%u",recPtr->smf70t03);
    fprintf(fp,",\"smf70t04\":%u",recPtr->smf70t04);
    fprintf(fp,",\"smf70t05\":%u",recPtr->smf70t05);
    fprintf(fp,",\"smf70t06\":%u",recPtr->smf70t06);
    fprintf(fp,",\"smf70t07\":%u",recPtr->smf70t07);
    fprintf(fp,",\"smf70t08\":%u",recPtr->smf70t08);
    fprintf(fp,",\"smf70t09\":%u",recPtr->smf70t09);
    fprintf(fp,",\"smf70t10\":%u",recPtr->smf70t10);
    fprintf(fp,",\"smf70t11\":%u",recPtr->smf70t11);
    fprintf(fp,",\"smf70lmn\":%u",recPtr->smf70lmn);
    fprintf(fp,",\"smf70lmm\":%u",recPtr->smf70lmm);
    fprintf(fp,",\"smf70ltt\":%u",recPtr->smf70ltt);
    fprintf(fp,",\"smf70l00\":%u",recPtr->smf70l00);
    fprintf(fp,",\"smf70l01\":%u",recPtr->smf70l01);
    fprintf(fp,",\"smf70l02\":%u",recPtr->smf70l02);
    fprintf(fp,",\"smf70l03\":%u",recPtr->smf70l03);
    fprintf(fp,",\"smf70l04\":%u",recPtr->smf70l04);
    fprintf(fp,",\"smf70l05\":%u",recPtr->smf70l05);
    fprintf(fp,",\"smf70l06\":%u",recPtr->smf70l06);
    fprintf(fp,",\"smf70l07\":%u",recPtr->smf70l07);
    fprintf(fp,",\"smf70l08\":%u",recPtr->smf70l08);
    fprintf(fp,",\"smf70l09\":%u",recPtr->smf70l09);
    fprintf(fp,",\"smf70l10\":%u",recPtr->smf70l10);
    fprintf(fp,",\"smf70l11\":%u",recPtr->smf70l11);
    fprintf(fp,",\"smf70amn\":%u",recPtr->smf70amn);
    fprintf(fp,",\"smf70amm\":%u",recPtr->smf70amm);
    fprintf(fp,",\"smf70att\":%u",recPtr->smf70att);
    fprintf(fp,",\"smf70a00\":%u",recPtr->smf70a00);
    fprintf(fp,",\"smf70a01\":%u",recPtr->smf70a01);
    fprintf(fp,",\"smf70a02\":%u",recPtr->smf70a02);
    fprintf(fp,",\"smf70a03\":%u",recPtr->smf70a03);
    fprintf(fp,",\"smf70a04\":%u",recPtr->smf70a04);
    fprintf(fp,",\"smf70a05\":%u",recPtr->smf70a05);
    fprintf(fp,",\"smf70a06\":%u",recPtr->smf70a06);
    fprintf(fp,",\"smf70a07\":%u",recPtr->smf70a07);
    fprintf(fp,",\"smf70a08\":%u",recPtr->smf70a08);
    fprintf(fp,",\"smf70a09\":%u",recPtr->smf70a09);
    fprintf(fp,",\"smf70a10\":%u",recPtr->smf70a10);
    fprintf(fp,",\"smf70a11\":%u",recPtr->smf70a11);
    fprintf(fp,",\"smf70pmn\":%u",recPtr->smf70pmn);
    fprintf(fp,",\"smf70pmm\":%u",recPtr->smf70pmm);
    fprintf(fp,",\"smf70ptt\":%u",recPtr->smf70ptt);
    fprintf(fp,",\"smf70p00\":%u",recPtr->smf70p00);
    fprintf(fp,",\"smf70p01\":%u",recPtr->smf70p01);
    fprintf(fp,",\"smf70p02\":%u",recPtr->smf70p02);
    fprintf(fp,",\"smf70p03\":%u",recPtr->smf70p03);
    fprintf(fp,",\"smf70p04\":%u",recPtr->smf70p04);
    fprintf(fp,",\"smf70p05\":%u",recPtr->smf70p05);
    fprintf(fp,",\"smf70p06\":%u",recPtr->smf70p06);
    fprintf(fp,",\"smf70p07\":%u",recPtr->smf70p07);
    fprintf(fp,",\"smf70p08\":%u",recPtr->smf70p08);
    fprintf(fp,",\"smf70p09\":%u",recPtr->smf70p09);
    fprintf(fp,",\"smf70p10\":%u",recPtr->smf70p10);
    fprintf(fp,",\"smf70p11\":%u",recPtr->smf70p11);
    fprintf(fp,",\"smf70xmn\":%u",recPtr->smf70xmn);
    fprintf(fp,",\"smf70xmm\":%u",recPtr->smf70xmm);
    fprintf(fp,",\"smf70xtt\":%u",recPtr->smf70xtt);
    fprintf(fp,",\"smf70x00\":%u",recPtr->smf70x00);
    fprintf(fp,",\"smf70x01\":%u",recPtr->smf70x01);
    fprintf(fp,",\"smf70x02\":%u",recPtr->smf70x02);
    fprintf(fp,",\"smf70x03\":%u",recPtr->smf70x03);
    fprintf(fp,",\"smf70x04\":%u",recPtr->smf70x04);
    fprintf(fp,",\"smf70x05\":%u",recPtr->smf70x05);
    fprintf(fp,",\"smf70x06\":%u",recPtr->smf70x06);
    fprintf(fp,",\"smf70x07\":%u",recPtr->smf70x07);
    fprintf(fp,",\"smf70x08\":%u",recPtr->smf70x08);
    fprintf(fp,",\"smf70x09\":%u",recPtr->smf70x09);
    fprintf(fp,",\"smf70x10\":%u",recPtr->smf70x10);
    fprintf(fp,",\"smf70x11\":%u",recPtr->smf70x11);
    fprintf(fp,",\"smf70q00\":%u",recPtr->smf70q00);
    fprintf(fp,",\"smf70q01\":%u",recPtr->smf70q01);
    fprintf(fp,",\"smf70q02\":%u",recPtr->smf70q02);
    fprintf(fp,",\"smf70q03\":%u",recPtr->smf70q03);
    fprintf(fp,",\"smf70q04\":%u",recPtr->smf70q04);
    fprintf(fp,",\"smf70q05\":%u",recPtr->smf70q05);
    fprintf(fp,",\"smf70q06\":%u",recPtr->smf70q06);
    fprintf(fp,",\"smf70q07\":%u",recPtr->smf70q07);
    fprintf(fp,",\"smf70q08\":%u",recPtr->smf70q08);
    fprintf(fp,",\"smf70q09\":%u",recPtr->smf70q09);
    fprintf(fp,",\"smf70q10\":%u",recPtr->smf70q10);
    fprintf(fp,",\"smf70q11\":%u",recPtr->smf70q11);
    fprintf(fp,",\"smf70q12\":%u",recPtr->smf70q12);
    fprintf(fp,",\"smf70srm\":%u",recPtr->smf70srm);
    fprintf(fp,",\"smf70cmn\":%u",recPtr->smf70cmn);
    fprintf(fp,",\"smf70cmm\":%u",recPtr->smf70cmm);
    fprintf(fp,",\"smf70ctt\":%u",recPtr->smf70ctt);
    fprintf(fp,",\"smf70dmn\":%u",recPtr->smf70dmn);
    fprintf(fp,",\"smf70dmm\":%u",recPtr->smf70dmm);
    fprintf(fp,",\"smf70dtt\":%u",recPtr->smf70dtt);
    fprintf(fp,",\"smf70emn\":%u",recPtr->smf70emn);
    fprintf(fp,",\"smf70emm\":%u",recPtr->smf70emm);
    fprintf(fp,",\"smf70ett\":%u",recPtr->smf70ett);
    fprintf(fp,",\"smf70u00\":%u",recPtr->smf70u00);
    fprintf(fp,",\"smf70u01\":%u",recPtr->smf70u01);
    fprintf(fp,",\"smf70u02\":%u",recPtr->smf70u02);
    fprintf(fp,",\"smf70u03\":%u",recPtr->smf70u03);
    fprintf(fp,",\"smf70u04\":%u",recPtr->smf70u04);
    fprintf(fp,",\"smf70u05\":%u",recPtr->smf70u05);
    fprintf(fp,",\"smf70u06\":%u",recPtr->smf70u06);
    fprintf(fp,",\"smf70u07\":%u",recPtr->smf70u07);
    fprintf(fp,",\"smf70u08\":%u",recPtr->smf70u08);
    fprintf(fp,",\"smf70u09\":%u",recPtr->smf70u09);
    fprintf(fp,",\"smf70u10\":%u",recPtr->smf70u10);
    fprintf(fp,",\"smf70u11\":%u",recPtr->smf70u11);
    fprintf(fp,",\"smf70u12\":%u",recPtr->smf70u12);
    fprintf(fp,",\"smf70u13\":%u",recPtr->smf70u13);
    fprintf(fp,",\"smf70u14\":%u",recPtr->smf70u14);
    fprintf(fp,",\"smf70u15\":%u",recPtr->smf70u15);

    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printPrsmPartSect(struct smf70bct *bct, short recLen,
                   short count, FILE *fp)
{
  struct smf70bct *recPtr;

  fprintf(fp,",\"smf70bct\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct smf70bct *)((void *)bct + i*recLen);
    fprintEbcdicStr(fp,"smf70lpm",8, recPtr->smf70lpm,TRUE,FALSE);
    fprintf(fp,",\"smf70lpn\":%u",recPtr->smf70lpn);
    fprintf(fp,",\"smf70pfg\":\"0x%2.2X\"",recPtr->smf70pfg);
    fprintf(fp,",\"smf70bdn\":%u",*(short *)recPtr->smf70bdn);
    fprintf(fp,",\"smf70bds\":%u",*(int *)recPtr->smf70bds);
    fprintf(fp,",\"smf70bda\":%u",*(int *)recPtr->smf70bda);
    fprintEbcdicStr(fp,"smf70spn",8, recPtr->smf70spn,TRUE,TRUE);
    fprintEbcdicStr(fp,"smf70stn",8, recPtr->smf70stn,TRUE,TRUE);
    fprintf(fp,",\"smf70csf\":\"%uMB\"",*(int *)recPtr->smf70csf);
    fprintf(fp,",\"smf70esf\":\"%uMB\"",*(int *)recPtr->smf70esf);
    fprintf(fp,",\"smf70msu\":%u",*(int *)recPtr->smf70msu);
    fprintHexString(fp,"smf70pfl",2,recPtr->smf70pfl,FALSE,TRUE);
    fprintf(fp,",\"smf70upi\":%u",recPtr->smf70upi);
    fprintf(fp,",\"smf70mtid\":%u",recPtr->smf70mtid);
    fprintEbcdicStr(fp,"smf70gnm",8, recPtr->smf70gnm,TRUE,TRUE);
    fprintf(fp,",\"smf70gmu\":%u",*(int *)recPtr->smf70gmu);
    fprintEbcdicStr(fp,"smf70hwgr_name",8,
                             recPtr->smf70hwgr_name,TRUE,TRUE);
    fprintf(fp,",\"smf70_boostinfo\":\"0x%2.2X\"",recPtr->smf70_boostinfo);
 /* fprintBits(fp,"smf70_boostinfo",recPtr->smf70_boostinfo,1,TRUE);*/

    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printPrsmLogicSect(struct smf70bpd *bpd, short recLen,
                   short count, FILE *fp)
{
  struct smf70bpd *recPtr;

  fprintf(fp,",\"smf70bpd\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct smf70bpd *)((void *)bpd + i*recLen);
    fprintMicsLongTime(fp,"smf70pdt",recPtr->smf70pdt,1,FALSE);
    fprintHexString(fp,"smf70vpa",2,recPtr->smf70vpa,FALSE,TRUE);
    fprintHexString(fp,"smf70bps",2,recPtr->smf70bps,FALSE,TRUE);
    fprintf(fp,",\"smf70vpf\":\"0x%2.2X\"",recPtr->smf70vpf);
    fprintf(fp,",\"smf70pof\":\"0x%2.2X\"",recPtr->smf70pof);
    fprintf(fp,",\"smf70cix\":%u",*(short *)recPtr->smf70cix);
    fprintMicsLongTime(fp,"smf70edt",recPtr->smf70edt,1,TRUE);
    fprintf(fp,",\"smf70acs\":%u",*(int *)recPtr->smf70acs);
    fprintHexString(fp,"smf70mis",2,recPtr->smf70mis,FALSE,TRUE);
    fprintHexString(fp,"smf70mas",2,recPtr->smf70mas,FALSE,TRUE);
    fprintf(fp,",\"smf70nsi\":%u",*(int *)recPtr->smf70nsi);
    fprintf(fp,",\"smf70nsa\":%u",*(int *)recPtr->smf70nsa);
    fprintMicsLongTime(fp,"smf70ont",recPtr->smf70ont,1,TRUE);
    fprintMicsLongTime(fp,"smf70wst",recPtr->smf70wst,1,TRUE);
    fprintf(fp,",\"smf70pma\":%d",*(int *)recPtr->smf70pma);
    fprintf(fp,",\"smf70nsw\":%u",*(int *)recPtr->smf70nsw);
    fprintf(fp,",\"smf70pow\":%u",*(int *)recPtr->smf70pow);
    fprintf(fp,",\"smf70nca\":%u",recPtr->smf70nca);
    fprintf(fp,",\"smf70hw_cap_limit\":%u",
                   *(int *)recPtr->smf70hw_cap_limit);
    fprintf(fp,",\"smf70hwgr_cap_limit\":%u",
                   *(int *)recPtr->smf70hwgr_cap_limit);
    fprintMicsLongTime(fp,"smf70mtit",recPtr->smf70mtit,1,TRUE);

    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printCpuIdSect(struct smf70cis *cis, short recLen,
                   short count, FILE *fp)
{
  struct smf70cis *recPtr;

  fprintf(fp,",\"smf70cis\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct smf70cis *)((void *)cis + i*recLen);
    fprintEbcdicStr(fp,"smf70cin",16, recPtr->smf70cin,TRUE,FALSE);
    fprintf(fp,",\"smf70ctn\":%u",*(short *)recPtr->smf70ctn);
    fprintf(fp,",\"smf70can\":%u",recPtr->smf70can);

    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printCoreDataSect(struct smf70lcs *lcs, short recLen,
                   short count, FILE *fp)
{
  struct smf70lcs *recPtr;

  fprintf(fp,",\"smf70lcs\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct smf70lcs *)((void *)lcs + i*recLen);
    fprintf(fp,"\"smf70_core_id\":%u",recPtr->smf70_core_id);
    fprintf(fp,",\"smf70_core_flg\":\"0x%2.2X\"",recPtr->smf70_core_flg);
    fprintf(fp,",\"smf70_cpu_skip\":%u",recPtr->smf70_cpu_skip);
    fprintf(fp,",\"smf70_cpu_num\":%u",recPtr->smf70_cpu_num);
    fprintf(fp,",\"smf70_prod\":%u",recPtr->smf70_prod);
    fprintMilliTime(fp,"smf70_lpar_busy",recPtr->smf70_lpar_busy,1,TRUE);

    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printTenantDataSect(struct smf70tnt *tnt, short recLen,
                   short count, FILE *fp)
{
  struct smf70tnt *recPtr;

  fprintf(fp,",\"smf70tnt\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct smf70tnt *)((void *)tnt + i*recLen);
    fprintEbcdicStr(fp,"smf70_trg_name",8,
                     recPtr->smf70_trg_name,TRUE,FALSE);
    fprintEbcdicStr(fp,"smf70_trg_desc",32,
                     recPtr->smf70_trg_desc,TRUE,TRUE);
    fprintEbcdicStr(fp,"smf70_trg_tntid",8,
                     recPtr->smf70_trg_tntid,TRUE,TRUE);
    fprintEbcdicStr(fp,"smf70_trg_tntname",32,
                     recPtr->smf70_trg_tntname,TRUE,TRUE);
    fprintEbcdicStr(fp,"smf70_trg_sbid",64,
                     recPtr->smf70_trg_sbid,TRUE,TRUE);
    fprintf(fp,",\"smf70_trg_sucp\":%llu",
     *(ull)recPtr->smf70_trg_sucp);
    fprintf(fp,",\"smf70_trg_suifa\":%llu",
     *(ull)recPtr->smf70_trg_suifa);
    fprintf(fp,",\"smf70_trg_susup\":%llu",
     *(ull)recPtr->smf70_trg_susup);
    fprintf(fp,",\"smf70_trg_lac\":%u",
     *(int *)recPtr->smf70_trg_lac);
    fprintf(fp,",\"smf70_trg_lac_cbp\":%u",
     *(int *)recPtr->smf70_trg_lac_cbp);
    fprintHexString(fp,"smf70_trg_flags",2,recPtr->smf70_trg_flags,FALSE,TRUE);
    fprintf(fp,",\"smf70_trg_mem\":%llu",
     *(ull)recPtr->smf70_trg_mem);

    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printCcaCoproSect(struct r702typ3 *typ3, short recLen,
                   short count, FILE *fp)
{
  struct r702typ3 *recPtr;

  fprintf(fp,",\"r702typ3\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r702typ3 *)((void *)typ3 + i*recLen);
    fprintf(fp,"\"r7023ax\":%u",recPtr->r7023ax);
    fprintf(fp,",\"r7023ct\":%u",recPtr->r7023ct);
    fprintf(fp,",\"r7023msk\":\"0x%2.2X\"",recPtr->r7023msk);
    fprintf(fp,",\"r7023mt\":%u",recPtr->r7023mt);
    fprintf(fp,",\"r7023sf\":%le",*(double*)recPtr->r7023sf);
    fprintf(fp,",\"r7023t0\":%le",*(double*)recPtr->r7023t0);
    fprintf(fp,",\"r7023c0\":%le",*(double*)recPtr->r7023c0);
    fprintf(fp,",\"r7023c1\":%le",*(double*)recPtr->r7023c1);
    fprintf(fp,",\"r7023scope\":%u",recPtr->r7023scope);
    fprintf(fp,",\"r7023did\":%u",recPtr->r7023did);

    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printAccelerSect(struct r702typ4 *typ4, short recLen,
                   short count, FILE *fp)
{
  struct r702typ4 *recPtr;

  fprintf(fp,",\"r702typ4\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r702typ4 *)((void *)typ4 + i*recLen);
    fprintf(fp,"\"r7024ax\":%u",recPtr->r7024ax);
    fprintf(fp,",\"r7024ct\":%u",recPtr->r7024ct);
    fprintf(fp,",\"r7024msk\":\"0x%2.2X\"",recPtr->r7024msk);
    fprintf(fp,",\"r7024mt\":%u",recPtr->r7024mt);
    fprintf(fp,",\"r7024en\":%u",*(int *)recPtr->r7024en);
    fprintf(fp,",\"r7024sf\":%le",*(double*)recPtr->r7024sf);

    fprintf(fp,",\"r7024tc\":[");
    for (short j=0;j < 5;j++) {
      if (j > 0)
        fprintf(fp,",{");
      else
        fprintf(fp,"{");
      fprintf(fp,"\"r7021met\":%le",*(double*)recPtr->r7021met);
      fprintf(fp,",\"r7021mec\":%le",*(double*)recPtr->r7021mec);
      fprintf(fp,",\"r7022met\":%le",*(double*)recPtr->r7022met);
      fprintf(fp,",\"r7022mec\":%le",*(double*)recPtr->r7022mec);
      fprintf(fp,",\"r7021crt\":%le",*(double*)recPtr->r7021crt);
      fprintf(fp,",\"r7021crc\":%le",*(double*)recPtr->r7021crc);
      fprintf(fp,",\"r7022crt\":%le",*(double*)recPtr->r7022crt);
      fprintf(fp,",\"r7022crc\":%le",*(double*)recPtr->r7022crc);

      fprintf(fp,"}");
    }
    fprintf(fp,"]");

    fprintf(fp,",\"r7023met\":%le",*(double*)recPtr->r7023met);
    fprintf(fp,",\"r7023mec\":%le",*(double*)recPtr->r7023mec);
    fprintf(fp,",\"r7023crt\":%le",*(double*)recPtr->r7023crt);
    fprintf(fp,",\"r7023crc\":%le",*(double*)recPtr->r7023crc);
    fprintf(fp,",\"r7024scope\":%u",recPtr->r7024scope);
    fprintf(fp,",\"r7024did\":%u",recPtr->r7024did);

    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printIcsfSect(struct r702ccf *recPtr, FILE *fp) {
  fprintf(fp,",\"r702ccf\":{");
  fprintf(fp,"\"r702snec\":%le",*(double*)recPtr->r702snec);
  fprintf(fp,",\"r702sneb\":%le",*(double*)recPtr->r702sneb);
  fprintf(fp,",\"r702snei\":%le",*(double*)recPtr->r702snei);
  fprintf(fp,",\"r702tnec\":%le",*(double*)recPtr->r702tnec);
  fprintf(fp,",\"r702tneb\":%le",*(double*)recPtr->r702tneb);
  fprintf(fp,",\"r702tnei\":%le",*(double*)recPtr->r702tnei);
  fprintf(fp,",\"r702sndc\":%le",*(double*)recPtr->r702sndc);
  fprintf(fp,",\"r702sndb\":%le",*(double*)recPtr->r702sndb);
  fprintf(fp,",\"r702sndi\":%le",*(double*)recPtr->r702sndi);
  fprintf(fp,",\"r702tndc\":%le",*(double*)recPtr->r702tndc);
  fprintf(fp,",\"r702tndb\":%le",*(double*)recPtr->r702tndb);
  fprintf(fp,",\"r702tndi\":%le",*(double*)recPtr->r702tndi);
  fprintf(fp,",\"r702nmgc\":%le",*(double*)recPtr->r702nmgc);
  fprintf(fp,",\"r702nmgb\":%le",*(double*)recPtr->r702nmgb);
  fprintf(fp,",\"r702nmgi\":%le",*(double*)recPtr->r702nmgi);
  fprintf(fp,",\"r702nmvc\":%le",*(double*)recPtr->r702nmvc);
  fprintf(fp,",\"r702nmvb\":%le",*(double*)recPtr->r702nmvb);
  fprintf(fp,",\"r702nmvi\":%le",*(double*)recPtr->r702nmvi);
  fprintf(fp,",\"r702nhac\":%le",*(double*)recPtr->r702nhac);
  fprintf(fp,",\"r702nhab\":%le",*(double*)recPtr->r702nhab);
  fprintf(fp,",\"r702nhai\":%le",*(double*)recPtr->r702nhai);
  fprintf(fp,",\"r702nptc\":%le",*(double*)recPtr->r702nptc);
  fprintf(fp,",\"r702npvc\":%le",*(double*)recPtr->r702npvc);
  fprintf(fp,",\"r702nh2c\":%le",*(double*)recPtr->r702nh2c);
  fprintf(fp,",\"r702nh2b\":%le",*(double*)recPtr->r702nh2b);
  fprintf(fp,",\"r702nh2i\":%le",*(double*)recPtr->r702nh2i);
  fprintf(fp,",\"r702nh5c\":%le",*(double*)recPtr->r702nh5c);
  fprintf(fp,",\"r702nh5b\":%le",*(double*)recPtr->r702nh5b);
  fprintf(fp,",\"r702nh5i\":%le",*(double*)recPtr->r702nh5i);
  fprintf(fp,",\"r702cdlv\":%u",recPtr->r702cdlv);

  fprintf(fp,",\"r702aesc\":%le",*(double*)recPtr->r702aesc);
  fprintf(fp,",\"r702aesb\":%le",*(double*)recPtr->r702aesb);
  fprintf(fp,",\"r702aesi\":%le",*(double*)recPtr->r702aesi);
  fprintf(fp,",\"r702asdc\":%le",*(double*)recPtr->r702asdc);
  fprintf(fp,",\"r702asdb\":%le",*(double*)recPtr->r702asdb);
  fprintf(fp,",\"r702asdi\":%le",*(double*)recPtr->r702asdi);

  fprintf(fp,",\"r702drgc\":%le",*(double*)recPtr->r702drgc);
  fprintf(fp,",\"r702drvc\":%le",*(double*)recPtr->r702drvc);
  fprintf(fp,",\"r702degc\":%le",*(double*)recPtr->r702degc);
  fprintf(fp,",\"r702devc\":%le",*(double*)recPtr->r702devc);

  fprintf(fp,",\"r702amgc\":%le",*(double*)recPtr->r702amgc);
  fprintf(fp,",\"r702amgb\":%le",*(double*)recPtr->r702amgb);
  fprintf(fp,",\"r702amgi\":%le",*(double*)recPtr->r702amgi);
  fprintf(fp,",\"r702amvc\":%le",*(double*)recPtr->r702amvc);
  fprintf(fp,",\"r702amvb\":%le",*(double*)recPtr->r702amvb);
  fprintf(fp,",\"r702amvi\":%le",*(double*)recPtr->r702amvi);

  fprintf(fp,",\"r702fpec\":%le",*(double*)recPtr->r702fpec);
  fprintf(fp,",\"r702fpeb\":%le",*(double*)recPtr->r702fpeb);
  fprintf(fp,",\"r702fpei\":%le",*(double*)recPtr->r702fpei);
  fprintf(fp,",\"r702fpdc\":%le",*(double*)recPtr->r702fpdc);
  fprintf(fp,",\"r702fpdb\":%le",*(double*)recPtr->r702fpdb);
  fprintf(fp,",\"r702fpdi\":%le",*(double*)recPtr->r702fpdi);
  fprintf(fp,",\"r702fptc\":%le",*(double*)recPtr->r702fptc);
  fprintf(fp,",\"r702fptb\":%le",*(double*)recPtr->r702fptb);
  fprintf(fp,",\"r702fpti\":%le",*(double*)recPtr->r702fpti);

  fprintf(fp,",\"r702fxec\":%le",*(double*)recPtr->r702fxec);
  fprintf(fp,",\"r702fxeb\":%le",*(double*)recPtr->r702fxeb);
  fprintf(fp,",\"r702fxei\":%le",*(double*)recPtr->r702fxei);
  fprintf(fp,",\"r702fxdc\":%le",*(double*)recPtr->r702fxdc);
  fprintf(fp,",\"r702fxdb\":%le",*(double*)recPtr->r702fxdb);
  fprintf(fp,",\"r702fxdi\":%le",*(double*)recPtr->r702fxdi);
  fprintf(fp,",\"r702fxtc\":%le",*(double*)recPtr->r702fxtc);
  fprintf(fp,",\"r702fxtb\":%le",*(double*)recPtr->r702fxtb);
  fprintf(fp,",\"r702fxti\":%le",*(double*)recPtr->r702fxti);
  fprintf(fp,",\"r702dqgc\":%le",*(double*)recPtr->r702dqgc);
  fprintf(fp,",\"r702dqvc\":%le",*(double*)recPtr->r702dqvc);
  fprintf(fp,"}");
}

void printPkcs11Sect(struct r702typ5 *typ5, short recLen,
                   short count, FILE *fp)
{
  struct r702typ5 *recPtr;

  fprintf(fp,",\"r702typ5\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r702typ5 *)((void *)typ5 + i*recLen);
    fprintf(fp,"\"r7025ax\":%u",recPtr->r7025ax);
    fprintf(fp,",\"r7025ct\":%u",recPtr->r7025ct);
    fprintf(fp,",\"r7025msk\":\"0x%2.2X\"",recPtr->r7025msk);
    fprintf(fp,",\"r7025mt\":%u",recPtr->r7025mt);
    fprintf(fp,",\"r7025sf\":%le",*(double*)recPtr->r7025sf);
    fprintf(fp,",\"r7025sat\":%le",*(double*)recPtr->r7025sat);
    fprintf(fp,",\"r7025sac\":%le",*(double*)recPtr->r7025sac);
    fprintf(fp,",\"r7025fat\":%le",*(double*)recPtr->r7025fat);
    fprintf(fp,",\"r7025fac\":%le",*(double*)recPtr->r7025fac);
    fprintf(fp,",\"r7025spt\":%le",*(double*)recPtr->r7025spt);
    fprintf(fp,",\"r7025spc\":%le",*(double*)recPtr->r7025spc);
    fprintf(fp,",\"r7025sct\":%le",*(double*)recPtr->r7025sct);
    fprintf(fp,",\"r7025scc\":%le",*(double*)recPtr->r7025scc);
    fprintf(fp,",\"r7025agt\":%le",*(double*)recPtr->r7025agt);
    fprintf(fp,",\"r7025agc\":%le",*(double*)recPtr->r7025agc);

    fprintf(fp,",\"r7025scope\":%u",recPtr->r7025scope);
    fprintf(fp,",\"r7025did\":%u",recPtr->r7025did);

    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

int parse_rec(struct smf70hdr *p,FILE *fp)
{
  struct smf70pro *pro;
  struct smf70ctl *ctl;
  struct smf70cpu *cpu;
  struct smf70aid *aid;
  struct smf70bct *bct;
  struct smf70bpd *bpd;
  struct smf70cis *cis;
  struct smf70lcs *lcs;
  struct smf70tnt *tnt;
  struct r702typ3 *typ3;
  struct r702typ4 *typ4;
  struct r702ccf  *ccf;
  struct r702typ5 *typ5;

  /* SMF Header */
  if(*(short *)p->smf70sty == 1)
    printSMFHeaderST1(p ,fp);
  else
    printSMFHeaderST2(p ,fp);

  if(*(short *)p->smf70prn ==1)
  {
    pro = (struct smf70pro *)((void *)p + *(int *)(p->smf70prs));

    /* Product Section */
    printProdSect(pro, fp);

  }
  if(*(short *)p->smf70sty == 1)
  {
    if(*(short *)p->smf70ccn ==1)
    {
      ctl = (struct smf70ctl *)((void *)p + *(int *)(p->smf70ccs));

      /* CPU control Section */
      printCpuCtlSect(ctl, fp);
    }

    if(*(short *)p->smf70cpn > 0)
    {
      cpu = (struct smf70cpu *)((void *)p + *(int *)(p->smf70cps));

      /* CPU data Section */
      printCpuDataSect(cpu,*(short *)p->smf70cpl,
                           *(short *)p->smf70cpn, fp);
    }

    if(*(short *)p->smf70asn > 0)
    {
      aid = (struct smf70aid *)((void *)p + *(int *)(p->smf70ass));

      /* ASID data Area Section */
      printAsidDataSect(aid,*(short *)p->smf70asl,
                            *(short *)p->smf70asn, fp);
    }

    if(*(short *)p->smf70bcn > 0)
    {
      bct = (struct smf70bct *)((void *)p + *(int *)(p->smf70bcs));

      /* PR/SM Partition data Section */
      printPrsmPartSect(bct,*(short *)p->smf70bcl,
                            *(short *)p->smf70bcn, fp);
    }

    if(*(short *)p->smf70bvn > 0)
    {
      bpd = (struct smf70bpd *)((void *)p + *(int *)(p->smf70bvs));

      /* PR/SM Logical Processor data Section */
      printPrsmLogicSect(bpd,*(short *)p->smf70bvl,
                            *(short *)p->smf70bvn, fp);
    }

    if(*(short *)p->smf70cnn > 0)
    {
      cis = (struct smf70cis *)((void *)p + *(int *)(p->smf70cns));

      /* CPU-Identification name Section */
      printCpuIdSect(cis,*(short *)p->smf70cnl,
                         *(short *)p->smf70cnn, fp);
    }

    if(*(short *)p->smf70con > 0)
    {
      lcs = (struct smf70lcs *)((void *)p + *(int *)(p->smf70cos));

      /* Logical core data Section */
      printCoreDataSect(lcs,*(short *)p->smf70col,
                         *(short *)p->smf70con, fp);
    }

    if(*(short *)p->smf70tnn > 0)
    {
      tnt = (struct smf70tnt *)((void *)p + *(int *)(p->smf70tns));

      /* Tenant Resource data Section */
      printTenantDataSect(tnt,*(short *)p->smf70tnl,
                         *(short *)p->smf70tnn, fp);
    }
  }

  if(*(short *)p->smf70sty == 2)
  {
    if(*(short *)p->smf7023n > 0)
    {
      typ3 = (struct r702typ3 *)((void *)p + *(int *)(p->smf7023s));

      /* Cryptographic CCA Coprocessor data section */
      printCcaCoproSect(typ3, *(short *)p->smf7023l,
                              *(short *)p->smf7023n, fp);
    }

    if(*(short *)p->smf7024n > 0)
    {
      typ4 = (struct r702typ4 *)((void *)p + *(int *)(p->smf7024s));

      /* Cryptographic Accelerator data section */
      printAccelerSect(typ4, *(short *)p->smf7024l,
                             *(short *)p->smf7024n, fp);
    }

    if(*(short *)p->smf702cn == 1)
    {
      ccf = (struct r702ccf *)((void *)p + *(int *)(p->smf702cs));

      /* ICSF Services data section */
      printIcsfSect(ccf, fp);
    }

    if(*(short *)p->smf7025n > 0)
    {
      typ5 = (struct r702typ5 *)((void *)p + *(int *)(p->smf7025s));

      /* Cryptographic RKCS11 data section */
      printPkcs11Sect(typ5, *(short *)p->smf7025l,
                            *(short *)p->smf7025n, fp);
    }

  }

  return 0;
}

#pragma pack(reset)
