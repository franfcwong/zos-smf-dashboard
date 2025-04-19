/* SPDX-License-Identifier: GPL-3.0-only or GPL-3.0-or-later */
/*
 * SMF72 Header File for supporting the generation of JSON.
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
#define TARGET_SMF_TYPE 72
#define SMF72           72
#define SMF72ST3        3
#define SMF72ST4        4
#define SMF72ST5        5
#define CMS_LOCK        0x01
#define CMS_ENQDEQ_LOCK 0x02
#define CMS_LATCH_LOCK  0x03
#define CMS_SMF_LOCK    0x04
#define LATCH_CREATOR   0x01
#define LATCH_REQUESTOR 0x02
#define SCOPE_STEP      0x01
#define SCOPE_SYSTEM    0x02
#define SCOPE_SYSTEMS   0x03

#include "smf72h.h"

void printSMFHeader(struct smf72hdr *recPtr,FILE* fp) {
  fprintf(fp,"\"header\":{");
  fprintf(fp,"\"recLen\":%u",*(short *)recPtr->smf72len);
  fprintf(fp,",\"sysInd\":\"0x%2.2X\"",recPtr->smf72flg);
  fprintf(fp,",\"recType\":%u",recPtr->smf72rty);
  fprintPkChTDate(fp,"dateTime",recPtr->smf72tme, recPtr->smf72dte,
                  TRUE);
  fprintf(fp,",\"sysId\":\"%.4s\"",recPtr->smf72sid);
  fprintf(fp,",\"subSysId\":\"%.4s\"",recPtr->smf72ssi);
  fprintf(fp,",\"subType\":%d",*(short *)recPtr->smf72sty);
  fprintf(fp,",\"smf72trn\":%u",*(short *)recPtr->smf72trn);
  fprintf(fp,",\"smf72prs\":%u",*(int   *)recPtr->smf72prs);
  fprintf(fp,",\"smf72prl\":%u",*(short *)recPtr->smf72prl);
  fprintf(fp,",\"smf72prn\":%u",*(short *)recPtr->smf72prn);

  switch(*(short *)recPtr->smf72sty) {
    case SMF72ST3:
      fprintf(fp,",\"smf72wms\":%u",*(int   *)recPtr->smf72wms);
      fprintf(fp,",\"smf72wml\":%u",*(short *)recPtr->smf72wml);
      fprintf(fp,",\"smf72wmn\":%u",*(short *)recPtr->smf72wmn);
      fprintf(fp,",\"smf72sss\":%u",*(int   *)recPtr->smf72sss);
      fprintf(fp,",\"smf72ssl\":%u",*(short *)recPtr->smf72ssl);
      fprintf(fp,",\"smf72ssn\":%u",*(short *)recPtr->smf72ssn);
      fprintf(fp,",\"smf72rgs\":%u",*(int   *)recPtr->smf72rgs);
      fprintf(fp,",\"smf72rgl\":%u",*(short *)recPtr->smf72rgl);
      fprintf(fp,",\"smf72rgn\":%u",*(short *)recPtr->smf72rgn);
      fprintf(fp,",\"smf72scs\":%u",*(int   *)recPtr->smf72scs);
      fprintf(fp,",\"smf72scl\":%u",*(short *)recPtr->smf72scl);
      fprintf(fp,",\"smf72scn\":%u",*(short *)recPtr->smf72scn);
      fprintf(fp,",\"smf72rts\":%u",*(int   *)recPtr->smf72rts);
      fprintf(fp,",\"smf72rtl\":%u",*(short *)recPtr->smf72rtl);
      fprintf(fp,",\"smf72rtn\":%u",*(short *)recPtr->smf72rtn);
      fprintf(fp,",\"smf72wrs\":%u",*(int   *)recPtr->smf72wrs);
      fprintf(fp,",\"smf72wrl\":%u",*(short *)recPtr->smf72wrl);
      fprintf(fp,",\"smf72wrn\":%u",*(short *)recPtr->smf72wrn);
      fprintf(fp,",\"smf72dns\":%u",*(int   *)recPtr->smf72dns);
      fprintf(fp,",\"smf72dnl\":%u",*(short *)recPtr->smf72dnl);
      fprintf(fp,",\"smf72dnn\":%u",*(short *)recPtr->smf72dnn);
      break;
    case SMF72ST4:
      fprintf(fp,",\"smf72cps\":%u",*(int   *)recPtr->smf72cps);
      fprintf(fp,",\"smf72cpl\":%u",*(short *)recPtr->smf72cpl);
      fprintf(fp,",\"smf72cpn\":%u",*(short *)recPtr->smf72cpn);
      fprintf(fp,",\"smf72sps\":%u",*(int   *)recPtr->smf72sps);
      fprintf(fp,",\"smf72spl\":%u",*(short *)recPtr->smf72spl);
      fprintf(fp,",\"smf72spn\":%u",*(short *)recPtr->smf72spn);
      break;
    case SMF72ST5:
      fprintf(fp,",\"smf72ses\":%u",*(int   *)recPtr->smf72ses);
      fprintf(fp,",\"smf72sel\":%u",*(short *)recPtr->smf72sel);
      fprintf(fp,",\"smf72sen\":%u",*(short *)recPtr->smf72sen);
      fprintf(fp,",\"smf72cms\":%u",*(int   *)recPtr->smf72cms);
      fprintf(fp,",\"smf72cml\":%u",*(short *)recPtr->smf72cml);
      fprintf(fp,",\"smf72cmn\":%u",*(short *)recPtr->smf72cmn);
      fprintf(fp,",\"smf72eds\":%u",*(int   *)recPtr->smf72eds);
      fprintf(fp,",\"smf72edl\":%u",*(short *)recPtr->smf72edl);
      fprintf(fp,",\"smf72edn\":%u",*(short *)recPtr->smf72edn);
      fprintf(fp,",\"smf72las\":%u",*(int   *)recPtr->smf72las);
      fprintf(fp,",\"smf72lal\":%u",*(short *)recPtr->smf72lal);
      fprintf(fp,",\"smf72lan\":%u",*(short *)recPtr->smf72lan);
      fprintf(fp,",\"smf72sms\":%u",*(int   *)recPtr->smf72sms);
      fprintf(fp,",\"smf72sml\":%u",*(short *)recPtr->smf72sml);
      fprintf(fp,",\"smf72smn\":%u",*(short *)recPtr->smf72smn);
      fprintf(fp,",\"smf72los\":%u",*(int   *)recPtr->smf72los);
      fprintf(fp,",\"smf72lol\":%u",*(short *)recPtr->smf72lol);
      fprintf(fp,",\"smf72lon\":%u",*(short *)recPtr->smf72lon);
      fprintf(fp,",\"smf72cos\":%u",*(int   *)recPtr->smf72cos);
      fprintf(fp,",\"smf72col\":%u",*(short *)recPtr->smf72col);
      fprintf(fp,",\"smf72con\":%u",*(short *)recPtr->smf72con);
      fprintf(fp,",\"smf72crs\":%u",*(int   *)recPtr->smf72crs);
      fprintf(fp,",\"smf72crl\":%u",*(short *)recPtr->smf72crl);
      fprintf(fp,",\"smf72crn\":%u",*(short *)recPtr->smf72crn);
      fprintf(fp,",\"smf72lcs\":%u",*(int   *)recPtr->smf72lcs);
      fprintf(fp,",\"smf72lcl\":%u",*(short *)recPtr->smf72lcl);
      fprintf(fp,",\"smf72lcn\":%u",*(short *)recPtr->smf72lcn);
      fprintf(fp,",\"smf72lrs\":%u",*(int   *)recPtr->smf72lrs);
      fprintf(fp,",\"smf72lrl\":%u",*(short *)recPtr->smf72lrl);
      fprintf(fp,",\"smf72lrn\":%u",*(short *)recPtr->smf72lrn);
      fprintf(fp,",\"smf72tds\":%u",*(int   *)recPtr->smf72tds);
      fprintf(fp,",\"smf72tdl\":%u",*(short *)recPtr->smf72tdl);
      fprintf(fp,",\"smf72tdn\":%u",*(short *)recPtr->smf72tdn);
      fprintf(fp,",\"smf72yds\":%u",*(int   *)recPtr->smf72yds);
      fprintf(fp,",\"smf72ydl\":%u",*(short *)recPtr->smf72ydl);
      fprintf(fp,",\"smf72ydn\":%u",*(short *)recPtr->smf72ydn);
      fprintf(fp,",\"smf72sds\":%u",*(int   *)recPtr->smf72sds);
      fprintf(fp,",\"smf72sdl\":%u",*(short *)recPtr->smf72sdl);
      fprintf(fp,",\"smf72sdn\":%u",*(short *)recPtr->smf72sdn);
      fprintf(fp,",\"smf72qss\":%u",*(int   *)recPtr->smf72qss);
      fprintf(fp,",\"smf72qsl\":%u",*(short *)recPtr->smf72qsl);
      fprintf(fp,",\"smf72qsn\":%u",*(short *)recPtr->smf72qsn);
      break;
  }
  fprintf(fp,"}");
}

void printReasmInform(struct smf72rbl *rbl, short recLen,
                   short count, FILE *fp)
{
  struct smf72rbl *recPtr;
  fprintf(fp,",\"smf72rbl\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct smf72rbl *)((void *)rbl + i*recLen);
    fprintf(fp,"\"smf72rnn\":%u",*(short *)recPtr->smf72rnn);
    fprintf(fp,",\"smf72rpp\":%u",*(short *)recPtr->smf72rpp);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printReasm(struct smf72rhd *recPtr, FILE *fp) {
  struct smf72rbl *rbl;
  fprintf(fp,",\"smf72rbr\":%u",*(short *)recPtr->smf72rbr);
  fprintf(fp,",\"smf72rsq\":%u",*(short *)recPtr->smf72rsq);
  fprintf(fp,",\"smf72rio\":%u",*(int *)recPtr->smf72rio);
  fprintf(fp,",\"smf72ril\":%u",*(short *)recPtr->smf72ril);
  fprintf(fp,",\"smf72rin\":%u",*(short *)recPtr->smf72rin);

  if(*(short *)recPtr->smf72rin > 0)
  {
    rbl = (struct smf72rbl *)((void *)recPtr +
                              *(int *)(recPtr->smf72rio));
    printReasmInform(rbl,*(short *)recPtr->smf72ril,
                         *(short *)recPtr->smf72rin, fp);
  }
}

void printProdSect(struct smf72pro *recPtr, FILE *fp) {
  struct smf72rhd *rhd;
  int temp=0;
  fprintf(fp,",\"smf72pro\":{");
  frompd(recPtr->smf72mfv,3,&temp);
  fprintf(fp,"\"smf72mfv\":%u",temp);
  fprintEbcdicStr(fp,"smf72prd",8,recPtr->smf72prd,TRUE,TRUE);
  fprintPkDate(fp,"smf72ist",recPtr->smf72ist, recPtr->smf72dat, TRUE);
  fprintPkMilliTime(fp,"smf72int",recPtr->smf72int,TRUE);
  fprintf(fp,",\"smf72sam\":%u",*(int *)recPtr->smf72sam);
  fprintHexString(fp,"smf72fla",2,recPtr->smf72fla,FALSE,TRUE);

  frompd(recPtr->smf72cyc,7,&temp);
  fprintf(fp,",\"smf72cyc\":%u",temp);

  fprintEbcdicStr(fp,"smf72mvs",8,recPtr->smf72mvs,TRUE,TRUE);
  fprintf(fp,",\"smf72iml\":%u",recPtr->smf72iml);
  fprintf(fp,",\"smf72prf\":\"0x%2.2X\"",recPtr->smf72prf);
  fprintf(fp,",\"smf72ptn\":%u",recPtr->smf72ptn);
  fprintf(fp,",\"smf72srl\":\"0x%2.2X\"",recPtr->smf72srl);
  fprintHexString(fp,"smf72iet",8,recPtr->smf72iet,FALSE,TRUE);
  fprintStckTimeConv(fp,"smf72lgo",recPtr->smf72lgo,TRUE,TRUE);
  fprintf(fp,",\"smf72rao\":%u",*(int *)recPtr->smf72rao);
  fprintf(fp,",\"smf72ral\":%u",*(short *)recPtr->smf72ral);
  fprintf(fp,",\"smf72ran\":%u",*(short *)recPtr->smf72ran);
  fprintf(fp,",\"smf72oil\":%u",*(short *)recPtr->smf72oil);
  fprintf(fp,",\"smf72syn\":%u",*(short *)recPtr->smf72syn);
  fprintStckConv(fp,"smf72gie",recPtr->smf72gie,TRUE);
  fprintEbcdicStr(fp,"smf72xnm",8, recPtr->smf72xnm,TRUE,TRUE);
  fprintEbcdicStr(fp,"smf72snm",8, recPtr->smf72snm,TRUE,TRUE);

  if(*(short *)recPtr->smf72ral > 0)
  {
    rhd = (struct smf72rhd *)((void *)recPtr +
                              *(int *)(recPtr->smf72rao));
    printReasm(rhd, fp);
  }
  fprintf(fp,"}");
}

void printR723wms(struct r723wms *wms,short recLen,short count,FILE *fp)
{
  struct r723wms *recPtr;

  fprintf(fp,",\"r723wms\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r723wms *)((void *)wms + i*recLen);
    fprintf(fp,"\"r723mscf\":\"0x%2.2X\"",recPtr->r723mscf);
    fprintf(fp,",\"r723mflg\":\"0x%2.2X\"",recPtr->r723mflg);
    fprintEbcdicStr(fp,"r723mnsp",8,recPtr->r723mnsp,TRUE,TRUE);
    fprintEbcdicStr(fp,"r723mdsp",32, recPtr->r723mdsp,TRUE,TRUE);
    fprintStckConv(fp,"r723mtpa",recPtr->r723mtpa,TRUE);
    fprintf(fp,",\"r723mcpu\":%u",*(int *)recPtr->r723mcpu);
    fprintf(fp,",\"r723mioc\":%u",*(int *)recPtr->r723mioc);
    fprintf(fp,",\"r723mmso\":%u",*(int *)recPtr->r723mmso);
    fprintf(fp,",\"r723msrb\":%u",*(int *)recPtr->r723msrb);
    fprintMilliTime(fp,"r723mtvl",*(int *)recPtr->r723mtvl,1,TRUE);
    fprintf(fp,",\"r723mtv_\":%u",*(int *)recPtr->r723mtv_);
    fprintEbcdicStr(fp,"r723mopt",2, recPtr->r723mopt,TRUE,TRUE);
    fprintEbcdicStr(fp,"r723mwnm",8, recPtr->r723mwnm,TRUE,TRUE);
    fprintEbcdicStr(fp,"r723mwde",32, recPtr->r723mwde,TRUE,TRUE);
    fprintEbcdicStr(fp,"r723mcnm",8, recPtr->r723mcnm,TRUE,TRUE);
    fprintEbcdicStr(fp,"r723mcde",32,recPtr->r723mcde,TRUE,TRUE);
    fprintf(fp,",\"r723mcpg\":%u",*(short *)recPtr->r723mcpg);
    fprintf(fp,",\"r723msub\":%u",recPtr->r723msub);
    fprintEbcdicStr(fp,"r723merf",6,recPtr->r723merf,TRUE,TRUE);
    fprintf(fp,",\"r723madj\":%u",recPtr->r723madj);
    fprintEbcdicStr(fp,"r723midn",8,recPtr->r723midn,TRUE,TRUE);
    fprintEbcdicStr(fp,"r723midd",32, recPtr->r723midd,TRUE,TRUE);
    fprintStckConv(fp,"r723mtdi",recPtr->r723mtdi,TRUE);
    fprintEbcdicStr(fp,"r723midu",8, recPtr->r723midu,TRUE,TRUE);
    fprintEbcdicStr(fp,"r723clsc",8, recPtr->r723clsc,TRUE,TRUE);
    fprintf(fp,",\"r723nffi\":%u",recPtr->r723nffi);
    fprintf(fp,",\"r723nffs\":%u",recPtr->r723nffs);
    fprintf(fp,",\"r723nadj\":%u",recPtr->r723nadj);
    fprintf(fp,",\"r723ceca\":%u",recPtr->r723ceca);
    fprintf(fp,",\"r723mcf\":%u",recPtr->r723mcf);
    fprintf(fp,",\"r723mcfs\":%u",recPtr->r723mcfs);
    fprintf(fp,",\"r723mcfi\":%u",recPtr->r723mcfi);
    fprintf(fp,",\"r723cpa_actual\":%u",recPtr->r723cpa_actual);
    fprintf(fp,",\"r723cpa_scaling_factor\":%u",
          recPtr->r723cpa_scaling_factor);
    fprintf(fp,",\"r723cpa_actual_zcbp\":%u",
          recPtr->r723cpa_actual_zcbp);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR723sss(struct r723sss *sss,short recLen,short count,FILE *fp)
{
  struct r723sss *recPtr;

  fprintf(fp,",\"r723sss\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r723sss *)((void *)sss + i*recLen);
    fprintEbcdicStr(fp,"r723scsn",8,recPtr->r723scsn,TRUE,FALSE);
    fprintf(fp,",\"r723scs_\":%u",*(int *)recPtr->r723scs_);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR723rgs(struct r723rgs *rgs,short recLen,short count,FILE *fp)
{
  struct r723rgs *recPtr;

  fprintf(fp,",\"r723rgs\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r723rgs *)((void *)rgs + i*recLen);
    fprintEbcdicStr(fp,"r723ggnm",8,recPtr->r723ggnm,TRUE,FALSE);
    fprintEbcdicStr(fp,"r723ggde",32, recPtr->r723ggde,TRUE,TRUE);
    fprintf(fp,",\"r723gglt\":\"0x%2.2X\"",recPtr->r723gglt);
    fprintf(fp,",\"r723ggtf\":\"0x%2.2X\"",recPtr->r723ggtf);
    fprintf(fp,",\"r723ggmn\":%u",recPtr->r723ggmn);
    fprintf(fp,",\"r723ggmx\":%u",recPtr->r723ggmx);
    fprintf(fp,",\"r723ggml\":%u",recPtr->r723ggml);
    if(recPtr->r723ggtf == r723gtrg) {
      fprintEbcdicStr(fp,"r723ggti",8,recPtr->r723ggti,TRUE,TRUE);
      fprintEbcdicStr(fp,"r723ggtn",32, recPtr->r723ggtn,TRUE,TRUE);
      fprintEbcdicStr(fp,"r723ggky",64, recPtr->r723ggky,TRUE,TRUE);
    }
    else {
      fprintf(fp,",\"r723ggti\":\"\"");
      fprintf(fp,",\"r723ggtn\":\"\"");
      fprintf(fp,",\"r723ggky\":\"\"");
    }
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR723scs(struct r723scs *scs,short recLen,short count,FILE *fp)
{
  struct r723scs *recPtr;

  fprintf(fp,",\"r723scs\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r723scs *)((void *)scs + i*recLen);
    fprintf(fp,"\"r723crtx\":%u",*(short *)recPtr->r723crtx);
    fprintf(fp,",\"r723cwmx\":%u",*(short *)recPtr->r723cwmx);
    fprintf(fp,",\"r723cwmn\":%u",*(short *)recPtr->r723cwmn);
    fprintf(fp,",\"r723crs1\":\"0x%2.2X\"",recPtr->r723crs1);
    fprintf(fp,",\"r723cadf\":\"0x%2.2X\"",recPtr->r723cadf);
    fprintf(fp,",\"r723cper\":%u",recPtr->r723cper);
    fprintf(fp,",\"r723crtf\":\"0x%2.2X\"",recPtr->r723crtf);
    fprintf(fp,",\"r723crgf\":\"0x%2.2X\"",recPtr->r723crgf);
    fprintf(fp,",\"r723cval\":%u",*(int *)recPtr->r723cval);
    fprintf(fp,",\"r723cpct\":%u",*(short *)recPtr->r723cpct);
    fprintf(fp,",\"r723cimp\":%u",*(short *)recPtr->r723cimp);
    fprintf(fp,",\"r723cdur\":%u",*(int *)recPtr->r723cdur);
    fprintf(fp,",\"r723csrv\":%le",*(double *)recPtr->r723csrv);
    fprintf(fp,",\"r723ccpu\":%le",*(double *)recPtr->r723ccpu);
    fprintf(fp,",\"r723cioc\":%le",*(double *)recPtr->r723cioc);
    fprintf(fp,",\"r723cmso\":%le",*(double *)recPtr->r723cmso);
    fprintf(fp,",\"r723csrb\":%le",*(double *)recPtr->r723csrb);
    fprintf(fp,",\"r723cpir\":%le",*(double *)recPtr->r723cpir);
    fprintf(fp,",\"r723chpi\":%le",*(double *)recPtr->r723chpi);
    fprintf(fp,",\"r723cbpi\":%le",*(double *)recPtr->r723cbpi);
    fprintf(fp,",\"r723cpie\":%le",*(double *)recPtr->r723cpie);
    fprintf(fp,",\"r723cbpe\":%le",*(double *)recPtr->r723cbpe);
    fprintf(fp,",\"r723cbka\":%le",*(double *)recPtr->r723cbka);
    fprintf(fp,",\"r723cbke\":%le",*(double *)recPtr->r723cbke);
    fprintf(fp,",\"r723cprs\":%le",*(double *)recPtr->r723cprs);
    fprintf(fp,",\"r723cers\":%le",*(double *)recPtr->r723cers);
    fprintf(fp,",\"r723ctrr\":%le",*(double *)recPtr->r723ctrr);
    fprintf(fp,",\"r723ctat\":%le",*(double *)recPtr->r723ctat);
    fprintf(fp,",\"r723crct\":%le",*(double *)recPtr->r723crct);
    fprintf(fp,",\"r723ciit\":%le",*(double *)recPtr->r723ciit);
    fprintf(fp,",\"r723chst\":%le",*(double *)recPtr->r723chst);
    fprintf(fp,",\"r723cswc\":%u",recPtr->r723cswc);
    fprintf(fp,",\"r723ccrm\":%u",recPtr->r723ccrm);
    fprintf(fp,",\"r723crcp\":%u",recPtr->r723crcp);
    fprintf(fp,",\"r723carc\":%u",recPtr->r723carc);
    fprintf(fp,",\"r723cncp\":%u",recPtr->r723cncp);
    fprintf(fp,",\"r723canc\":%u",recPtr->r723canc);
    fprintf(fp,",\"r723ctet\":%le",*(double *)recPtr->r723ctet);
    fprintf(fp,",\"r723cxet\":%le",*(double *)recPtr->r723cxet);
    fprintf(fp,",\"r723cets\":%le",*(double *)recPtr->r723cets);
    fprintf(fp,",\"r723ccus\":%u",recPtr->r723ccus);
    fprintf(fp,",\"r723ctot\":%u",recPtr->r723ctot);
    fprintf(fp,",\"r723ccde\":%u",recPtr->r723ccde);
    fprintf(fp,",\"r723ccca\":%u",recPtr->r723ccca);
    fprintf(fp,",\"r723cswi\":%u",recPtr->r723cswi);
    fprintf(fp,",\"r723cmpl\":%u",recPtr->r723cmpl);
    fprintf(fp,",\"r723capr\":%u",recPtr->r723capr);
    fprintf(fp,",\"r723caco\":%u",recPtr->r723caco);
    fprintf(fp,",\"r723caxm\":%u",recPtr->r723caxm);
    fprintf(fp,",\"r723cvio\":%u",recPtr->r723cvio);
    fprintf(fp,",\"r723chsp\":%u",recPtr->r723chsp);
    fprintf(fp,",\"r723cchs\":%u",recPtr->r723cchs);
    fprintf(fp,",\"r723cunk\":%u",recPtr->r723cunk);
    fprintf(fp,",\"r723cidl\":%u",recPtr->r723cidl);
    fprintf(fp,",\"r723cpde\":%u",recPtr->r723cpde);
    fprintf(fp,",\"r723cpqu\":%u",recPtr->r723cpqu);
    fprintf(fp,",\"r723csac\":%u",recPtr->r723csac);
    fprintf(fp,",\"r723csrs\":%le",*(double *)recPtr->r723csrs);
    fprintf(fp,",\"r723cspa\":%le",*(double *)recPtr->r723cspa);
    fprintf(fp,",\"r723cspe\":%le",*(double *)recPtr->r723cspe);
    fprintf(fp,",\"r723cict\":%le",*(double *)recPtr->r723cict);
    fprintf(fp,",\"r723ciwt\":%le",*(double *)recPtr->r723ciwt);
    fprintf(fp,",\"r723cidt\":%le",*(double *)recPtr->r723cidt);
    fprintf(fp,",\"r723circ\":%u",recPtr->r723circ);
    fprintf(fp,",\"r723ctou\":%u",recPtr->r723ctou);
    fprintf(fp,",\"r723ciou\":%u",recPtr->r723ciou);
    fprintf(fp,",\"r723ciod\":%u",recPtr->r723ciod);
    fprintf(fp,",\"r723cq\":%u",recPtr->r723cq);
    fprintf(fp,",\"r723cspv\":%u",recPtr->r723cspv);
    fprintf(fp,",\"r723csvi\":%u",recPtr->r723csvi);
    fprintf(fp,",\"r723cshs\":%u",recPtr->r723cshs);
    fprintf(fp,",\"r723csmp\":%u",recPtr->r723csmp);
    fprintf(fp,",\"r723cssw\":%u",recPtr->r723cssw);
    fprintf(fp,",\"r723cndi\":%u",recPtr->r723cndi);
    fprintf(fp,",\"r723ctdq\":%u",recPtr->r723ctdq);
    fprintf(fp,",\"r723ctsa\":%le",*(double *)recPtr->r723ctsa);
    fprintf(fp,",\"r723ciot\":%le",*(double *)recPtr->r723ciot);
    fprintf(fp,",\"r723cqdt\":%le",*(double *)recPtr->r723cqdt);
    fprintf(fp,",\"r723cadt\":%le",*(double *)recPtr->r723cadt);
    fprintf(fp,",\"r723ccvt\":%le",*(double *)recPtr->r723ccvt);
    fprintf(fp,",\"r723ciqt\":%le",*(double *)recPtr->r723ciqt);
    fprintf(fp,",\"r723ciea\":%le",*(double *)recPtr->r723ciea);
    fprintf(fp,",\"r723cxea\":%le",*(double *)recPtr->r723cxea);
    fprintf(fp,",\"r723cfea\":%le",*(double *)recPtr->r723cfea);
    fprintf(fp,",\"r723apu\":%u",recPtr->r723apu);
    fprintf(fp,",\"r723apd\":%u",recPtr->r723apd);
    fprintf(fp,",\"r723fqd\":%u",recPtr->r723fqd);
    fprintEbcdicStr(fp,"r723plsc",8,recPtr->r723plsc,TRUE,TRUE);
    fprintf(fp,",\"r723rcod\":%u",recPtr->r723rcod);
    fprintf(fp,",\"r723rcou\":%u",recPtr->r723rcou);
    fprintf(fp,",\"r723ectc\":%le",*(double *)recPtr->r723ectc);
    fprintf(fp,",\"r723ifau\":%u",recPtr->r723ifau);
    fprintf(fp,",\"r723ifcu\":%u",recPtr->r723ifcu);
    fprintf(fp,",\"r723ifad\":%u",recPtr->r723ifad);
    fprintf(fp,",\"r723supu\":%u",recPtr->r723supu);
    fprintf(fp,",\"r723sucu\":%u",recPtr->r723sucu);
    fprintf(fp,",\"r723supd\":%u",recPtr->r723supd);
    fprintf(fp,",\"r723csup\":%le",*(double *)recPtr->r723csup);
    fprintf(fp,",\"r723csuc\":%le",*(double *)recPtr->r723csuc);
    fprintf(fp,",\"r723cifa\":%le",*(double *)recPtr->r723cifa);
    fprintf(fp,",\"r723cifc\":%le",*(double *)recPtr->r723cifc);
    fprintf(fp,",\"r723tpdp\":%le",*(double *)recPtr->r723tpdp);
    fprintf(fp,",\"r723cpdp\":%le",*(double *)recPtr->r723cpdp);
    fprintf(fp,",\"r723lpdp\":%le",*(double *)recPtr->r723lpdp);
    fprintf(fp,",\"r723spdp\":%le",*(double *)recPtr->r723spdp);
    fprintf(fp,",\"r723rtdm\":%u",recPtr->r723rtdm);
    fprintf(fp,",\"r723rtdc\":%u",recPtr->r723rtdc);
    fprintStckConv(fp,"r723rtdt",recPtr->r723rtdt,TRUE);
    fprintf(fp,",\"r723tsucp\":%le",*(double *)recPtr->r723tsucp);
    fprintf(fp,",\"r723tsusp\":%le",*(double *)recPtr->r723tsusp);
    fprintf(fp,",\"r723tsuocp\":%le",*(double *)recPtr->r723tsuocp);
    fprintf(fp,",\"r723msucp\":%le",*(double *)recPtr->r723msucp);
    fprintf(fp,",\"r723msusp\":%le",*(double *)recPtr->r723msusp);
    fprintf(fp,",\"r723msuocp\":%le",*(double *)recPtr->r723msuocp);
    fprintf(fp,",\"r723asucp\":%le",*(double *)recPtr->r723asucp);
    fprintf(fp,",\"r723asusp\":%le",*(double *)recPtr->r723asusp);
    fprintf(fp,",\"r723asuocp\":%le",*(double *)recPtr->r723asuocp);
    fprintf(fp,",\"r723bsucp\":%le",*(double *)recPtr->r723bsucp);
    fprintf(fp,",\"r723bsusp\":%le",*(double *)recPtr->r723bsusp);
    fprintf(fp,",\"r723bsuocp\":%le",*(double *)recPtr->r723bsuocp);

    fprintf(fp,",\"r723ctetx\":%le",*(double *)recPtr->r723ctetx);
    fprintf(fp,",\"r723cxetx\":%le",*(double *)recPtr->r723cxetx);
    fprintf(fp,",\"r723cetsx\":%le",*(double *)recPtr->r723cetsx);
    fprintf(fp,",\"r723cqdtx\":%le",*(double *)recPtr->r723cqdtx);
    fprintf(fp,",\"r723cadtx\":%le",*(double *)recPtr->r723cadtx);
    fprintf(fp,",\"r723ccvtx\":%le",*(double *)recPtr->r723ccvtx);
    fprintf(fp,",\"r723ciqtx\":%le",*(double *)recPtr->r723ciqtx);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR723rts(struct r723rts *rts,short recLen,short count,FILE *fp)
{
  struct r723rts *recPtr;

  fprintf(fp,",\"r723rts\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",[");
    else
      fprintf(fp,"[");
    recPtr=(struct r723rts *)((void *)rts + i*recLen);
    for(short k=0;k<r723tent;k++) {
      if((i==0) & (k==(r723tent-1)))
        fprintHexString(fp,NULL,4,(void*)recPtr+k*4,FALSE,TRUE);
      else if(k==0)
        fprintf(fp,"%u",*(int*)((void*)recPtr+k*4));
      else
        fprintf(fp,",%u",*(int*)((void*)recPtr+k*4));
    }
    fprintf(fp,"]");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR723wrs(struct r723wrs *wrs,short recLen,short count,FILE *fp)
{
  struct r723wrs *recPtr;

  fprintf(fp,",\"r723wrs\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r723wrs *)((void *)wrs + i*recLen);
    fprintEbcdicStr(fp,"r723rtyp",4, recPtr->r723rtyp,TRUE,FALSE);
    fprintf(fp,",\"r723rflg\":\"0x%2.2X\"",recPtr->r723rflg);
    fprintf(fp,",\"r723ress\":%u",recPtr->r723ress);
    fprintf(fp,",\"r723ract\":%u",recPtr->r723ract);
    fprintf(fp,",\"r723rrdy\":%u",recPtr->r723rrdy);
    fprintf(fp,",\"r723ridl\":%u",recPtr->r723ridl);
    fprintf(fp,",\"r723rwlo\":%u",recPtr->r723rwlo);
    fprintf(fp,",\"r723rwio\":%u",recPtr->r723rwio);
    fprintf(fp,",\"r723rwco\":%u",recPtr->r723rwco);
    fprintf(fp,",\"r723rwds\":%u",recPtr->r723rwds);
    fprintf(fp,",\"r723rwsl\":%u",recPtr->r723rwsl);
    fprintf(fp,",\"r723rwsn\":%u",recPtr->r723rwsn);
    fprintf(fp,",\"r723rwss\":%u",recPtr->r723rwss);
    fprintf(fp,",\"r723rwtm\":%u",recPtr->r723rwtm);
    fprintf(fp,",\"r723rwo\":%u",recPtr->r723rwo);
    fprintf(fp,",\"r723rwms\":%u",recPtr->r723rwms);
    fprintf(fp,",\"r723rssl\":%u",recPtr->r723rssl);
    fprintf(fp,",\"r723rsss\":%u",recPtr->r723rsss);
    fprintf(fp,",\"r723rssn\":%u",recPtr->r723rssn);
    fprintf(fp,",\"r723rwst\":%u",recPtr->r723rwst);
    fprintf(fp,",\"r723rwrt\":%u",recPtr->r723rwrt);
    fprintf(fp,",\"r723rwwr\":%u",recPtr->r723rwwr);
    fprintf(fp,",\"r723rapp\":%u",recPtr->r723rapp);
    fprintf(fp,",\"r723rwnl\":%u",recPtr->r723rwnl);
    fprintf(fp,",\"r723rw01\":%u",recPtr->r723rw01);
    fprintf(fp,",\"r723rw02\":%u",recPtr->r723rw02);
    fprintf(fp,",\"r723rw03\":%u",recPtr->r723rw03);
    fprintf(fp,",\"r723rw04\":%u",recPtr->r723rw04);
    fprintf(fp,",\"r723rw05\":%u",recPtr->r723rw05);
    fprintf(fp,",\"r723rw06\":%u",recPtr->r723rw06);
    fprintf(fp,",\"r723rw07\":%u",recPtr->r723rw07);
    fprintf(fp,",\"r723rw08\":%u",recPtr->r723rw08);
    fprintf(fp,",\"r723rw09\":%u",recPtr->r723rw09);
    fprintf(fp,",\"r723rw10\":%u",recPtr->r723rw10);
    fprintf(fp,",\"r723rw11\":%u",recPtr->r723rw11);
    fprintf(fp,",\"r723rw12\":%u",recPtr->r723rw12);
    fprintf(fp,",\"r723rw13\":%u",recPtr->r723rw13);
    fprintf(fp,",\"r723rw14\":%u",recPtr->r723rw14);
    fprintf(fp,",\"r723rw15\":%u",recPtr->r723rw15);
    fprintf(fp,",\"r723rbpm\":%u",recPtr->r723rbpm);
    fprintf(fp,",\"r723rdnx\":%u",*(short*)recPtr->r723rdnx);
    fprintf(fp,",\"r723rdnn\":%u",*(short*)recPtr->r723rdnn);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR723dns(struct r723dns *dns,short recLen,short count,FILE *fp)
{
  struct r723dns *recPtr;

  fprintf(fp,",\"r723dns\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r723dns *)((void *)dns + i*recLen);
    fprintEbcdicStr(fp,"r723dnst",4, recPtr->r723dnst,TRUE,FALSE);
    fprintf(fp,",\"r723dnnu\":%u",*(short *)recPtr->r723dnnu);
    fprintEbcdicStr(fp,"r723dnde",16, recPtr->r723dnde,TRUE,TRUE);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR724data(struct r724data *data,short recLen,short count,
                   FILE *fp)
{
  struct r724data *recPtr;

  fprintf(fp,",\"r724data\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r724data *)((void *)data + i*recLen);
    fprintEbcdicStr(fp,"r724pnam",8,recPtr->r724pnam,TRUE,FALSE);
    fprintStckConv(fp,"r724ptm",recPtr->r724ptm,TRUE);
    fprintEbcdicStr(fp,"r724lcnm",8,recPtr->r724lcnm,TRUE,TRUE);
    fprintf(fp,",\"r724per_\":%u",recPtr->r724per_);
    fprintf(fp,",\"r724user\":%u",*(int *)recPtr->r724user);
    fprintf(fp,",\"r724actv\":%u",*(int *)recPtr->r724actv);
    fprintf(fp,",\"r724acts\":%u",*(int *)recPtr->r724acts);
    fprintf(fp,",\"r724idls\":%u",*(int *)recPtr->r724idls);
    fprintf(fp,",\"r724page\":%u",*(int *)recPtr->r724page);
    fprintf(fp,",\"r724swap\":%u",*(int *)recPtr->r724swap);
    fprintf(fp,",\"r724outr\":%u",*(int *)recPtr->r724outr);
    fprintf(fp,",\"r724pgin\":%u",*(int *)recPtr->r724pgin);
    fprintf(fp,",\"r724divs\":%u",*(int *)recPtr->r724divs);
    fprintf(fp,",\"r724lssa\":%u",*(int *)recPtr->r724lssa);
    fprintf(fp,",\"r724pssa\":%u",*(int *)recPtr->r724pssa);
    fprintf(fp,",\"r724upro\":%u",*(int *)recPtr->r724upro);
    fprintf(fp,",\"r724udev\":%u",*(int *)recPtr->r724udev);
    fprintf(fp,",\"r724dpro\":%u",*(int *)recPtr->r724dpro);
    fprintf(fp,",\"r724ddev\":%u",*(int *)recPtr->r724ddev);
    fprintf(fp,",\"r724dsto\":%u",*(int *)recPtr->r724dsto);
    fprintf(fp,",\"r724djes\":%u",*(int *)recPtr->r724djes);
    fprintf(fp,",\"r724dhsm\":%u",*(int *)recPtr->r724dhsm);
    fprintf(fp,",\"r724dxcf\":%u",*(int *)recPtr->r724dxcf);
    fprintf(fp,",\"r724denq\":%u",*(int *)recPtr->r724denq);
    fprintf(fp,",\"r724dmnt\":%u",*(int *)recPtr->r724dmnt);
    fprintf(fp,",\"r724dmsg\":%u",*(int *)recPtr->r724dmsg);
    fprintf(fp,",\"r724unkn\":%u",*(int *)recPtr->r724unkn);
    fprintf(fp,",\"r724vald\":%u",*(int *)recPtr->r724vald);
    fprintf(fp,",\"r724lsct\":%u",*(int *)recPtr->r724lsct);
    fprintf(fp,",\"r724esct\":%u",*(int *)recPtr->r724esct);
    fprintf(fp,",\"r724psct\":%u",*(int *)recPtr->r724psct);
    fprintf(fp,",\"r724actf\":%le",*(double *)recPtr->r724actf);
    fprintf(fp,",\"r724idle\":%le",*(double *)recPtr->r724idle);
    fprintf(fp,",\"r724slot\":%le",*(double *)recPtr->r724slot);
    fprintf(fp,",\"r724div\":%le",*(double *)recPtr->r724div);
    fprintf(fp,",\"r724fix\":%le",*(double *)recPtr->r724fix);
    fprintf(fp,",\"r724lscf\":%le",*(double *)recPtr->r724lscf);
    fprintf(fp,",\"r724lsef\":%le",*(double *)recPtr->r724lsef);
    fprintf(fp,",\"r724psef\":%le",*(double *)recPtr->r724psef);
    fprintf(fp,",\"r724vect\":%le",*(double *)recPtr->r724vect);
    fprintf(fp,",\"r724et\":%le",*(double *)recPtr->r724et);
    fprintf(fp,",\"r724qt\":%le",*(double *)recPtr->r724qt);
    fprintf(fp,",\"r724end\":%le",*(double *)recPtr->r724end);
    fprintf(fp,",\"r724tsv\":%le",*(double *)recPtr->r724tsv);
    fprintf(fp,",\"r724vin\":%le",*(double *)recPtr->r724vin);
    fprintf(fp,",\"r724vlc\":%le",*(double *)recPtr->r724vlc);
    fprintf(fp,",\"r724gpi\":%le",*(double *)recPtr->r724gpi);
    fprintf(fp,",\"r724etx\":%le",*(double *)recPtr->r724etx);
    fprintf(fp,",\"r724qtx\":%le",*(double *)recPtr->r724qtx);

    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR724swre(struct r724swre *swre,short recLen,short count,
                   FILE *fp)
{
  struct r724swre *recPtr;

  fprintf(fp,",\"r724swre\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r724swre *)((void *)swre + i*recLen);
    fprintf(fp,"\"r724or1\":%u",*(int *)recPtr->r724or1);
    fprintf(fp,",\"r724or2\":%u",*(int *)recPtr->r724or2);
    fprintf(fp,",\"r724or3\":%u",*(int *)recPtr->r724or3);
    fprintf(fp,",\"r724or4\":%u",*(int *)recPtr->r724or4);
    fprintf(fp,",\"r724or5\":%u",*(int *)recPtr->r724or5);
    fprintf(fp,",\"r724or6\":%u",*(int *)recPtr->r724or6);
    fprintf(fp,",\"r724or7\":%u",*(int *)recPtr->r724or7);
    fprintf(fp,",\"r724or8\":%u",*(int *)recPtr->r724or8);
    fprintf(fp,",\"r724or9\":%u",*(int *)recPtr->r724or9);
    fprintf(fp,",\"r724or10\":%u",*(int *)recPtr->r724or10);
    fprintf(fp,",\"r724or11\":%u",*(int *)recPtr->r724or11);
    fprintf(fp,",\"r724or12\":%u",*(int *)recPtr->r724or12);
    fprintf(fp,",\"r724or13\":%u",*(int *)recPtr->r724or13);
    fprintf(fp,",\"r724or14\":%u",*(int *)recPtr->r724or14);
    fprintf(fp,",\"r724or15\":%u",*(int *)recPtr->r724or15);
    fprintf(fp,",\"r724or16\":%u",*(int *)recPtr->r724or16);
    fprintf(fp,",\"r724or17\":%u",*(int *)recPtr->r724or17);
    fprintf(fp,",\"r724or18\":%u",*(int *)recPtr->r724or18);
    fprintf(fp,",\"r724or7a\":%u",*(int *)recPtr->r724or7a);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR725sctl(struct r725sctl *sctl,short recLen,short count,
                   FILE *fp)
{
  struct r725sctl *recPtr;

  fprintf(fp,",\"r725sctl\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r725sctl *)((void *)sctl + i*recLen);
    fprintf(fp,"\"r725sgmo\":\"0x%2.2X\"",recPtr->r725sgmo);
    fprintf(fp,",\"r725scms\":%llu",*(ull)recPtr->r725scms);
    fprintf(fp,",\"r725scma\":%llu",*(ull)recPtr->r725scma);
    fprintMilliLongTime(fp,"r725scmt",recPtr->r725scmt,1,TRUE);
    fprintf(fp,",\"r725seds\":%llu",*(ull)recPtr->r725seds);
    fprintf(fp,",\"r725seda\":%llu",*(ull)recPtr->r725seda);
    fprintMilliLongTime(fp,"r725sedt",recPtr->r725sedt,1,TRUE);
    fprintf(fp,",\"r725slas\":%llu",*(ull)recPtr->r725slas);
    fprintf(fp,",\"r725slaa\":%llu",*(ull)recPtr->r725slaa);
    fprintMilliLongTime(fp,"r725slat",recPtr->r725slat,1,TRUE);
    fprintf(fp,",\"r725ssms\":%llu",*(ull)recPtr->r725ssms);
    fprintf(fp,",\"r725ssma\":%llu",*(ull)recPtr->r725ssma);
    fprintMilliLongTime(fp,"r725ssmt",recPtr->r725ssmt,1,TRUE);
    fprintf(fp,",\"r725slos\":%llu",*(ull)recPtr->r725slos);
    fprintf(fp,",\"r725sloa\":%llu",*(ull)recPtr->r725sloa);
    fprintMilliLongTime(fp,"r725slot",recPtr->r725slot,1,TRUE);
    fprintf(fp,",\"r725scls\":%llu",*(ull)recPtr->r725scls);
    fprintf(fp,",\"r725scla\":%llu",*(ull)recPtr->r725scla);
    fprintMilliLongTime(fp,"r725sclt",recPtr->r725sclt,1,TRUE);
    fprintf(fp,",\"r725slrs\":%llu",*(ull)recPtr->r725slrc);
    fprintMilliLongTime(fp,"r725slrt",recPtr->r725slrt,1,TRUE);
    fprintHexString(fp,"r725slrq",16,recPtr->r725slrq,FALSE,TRUE);
    fprintf(fp,",\"r725sstr\":%llu",*(ull)recPtr->r725sstr);
    fprintf(fp,",\"r725ssts\":%llu",*(ull)recPtr->r725ssts);
    fprintMilliLongTime(fp,"r725sstt",recPtr->r725sstt,1,TRUE);
    fprintHexString(fp,"r725sstq",16,recPtr->r725sstq,FALSE,TRUE);
    fprintf(fp,",\"r725ssyr\":%llu",*(ull)recPtr->r725ssyr);
    fprintf(fp,",\"r725ssys\":%llu",*(ull)recPtr->r725ssys);
    fprintMilliLongTime(fp,"r725ssyt",recPtr->r725ssyt,1,TRUE);
    fprintHexString(fp,"r725ssyq",16,recPtr->r725ssyq,FALSE,TRUE);
    fprintf(fp,",\"r725sssr\":%llu",*(ull)recPtr->r725sssr);
    fprintf(fp,",\"r725ssss\":%llu",*(ull)recPtr->r725ssss);
    fprintMilliLongTime(fp,"r725ssst",recPtr->r725ssst,1,TRUE);
    fprintHexString(fp,"r725sssq",16,recPtr->r725sssq,FALSE,TRUE);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR725cmsd(struct r725cmsd *cmsd,short recLen,short count,
                   FILE *fp)
{
  struct r725cmsd *recPtr;

  switch (cmsd->r725cmty) {
    case CMS_LOCK:
      fprintf(fp,",\"r725cmss\":");
      break;
    case CMS_ENQDEQ_LOCK:
      fprintf(fp,",\"r725ceds\":");
      break;
    case CMS_LATCH_LOCK:
      fprintf(fp,",\"r725clas\":");
      break;
    case CMS_SMF_LOCK:
      fprintf(fp,",\"r725csms\":");
      break;
    default:
      fprintf(fp,",\"r725csmd\":");
      break;
  }
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r725cmsd *)((void *)cmsd + i*recLen);
    fprintEbcdicStr(fp,"r725cmjn",8,recPtr->r725cmjn,TRUE,FALSE);
    fprintf(fp,",\"r725cmsp\":%u",recPtr->r725cmsp);
    fprintHexString(fp,"r725cmas",2,recPtr->r725cmas,FALSE,TRUE);
    fprintHexString(fp,"r725cmst",8,recPtr->r725cmst,FALSE,TRUE);
    fprintEbcdicStr(fp,"r725cmsn",8, recPtr->r725cmsn,TRUE,TRUE);
    fprintf(fp,",\"r725cmty\":%u",recPtr->r725cmty);
    fprintf(fp,",\"r725cmsu\":%llu",*(ull)recPtr->r725cmsu);
    fprintf(fp,",\"r725cmal\":%llu",*(ull)recPtr->r725cmal);
    fprintMilliLongTime(fp,"r725cmti",recPtr->r725cmti,1,TRUE);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR725lotd(struct r725lotd *lotd,short recLen,short count,
                   FILE *fp)
{
  struct r725lotd *recPtr;

  fprintf(fp,",\"r725lotd\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r725lotd *)((void *)lotd + i*recLen);
    fprintEbcdicStr(fp,"r725lojn",8,recPtr->r725lojn,TRUE,FALSE);
    fprintf(fp,",\"r725losp\":%u",recPtr->r725losp);
    fprintHexString(fp,"r725loas",2,recPtr->r725loas,FALSE,TRUE);
    fprintHexString(fp,"r725lost",8,recPtr->r725lost,FALSE,TRUE);
    fprintEbcdicStr(fp,"r725losn",8,recPtr->r725losn,TRUE,TRUE);
    fprintf(fp,",\"r725losu\":%llu",*(ull)recPtr->r725losu);
    fprintf(fp,",\"r725loal\":%llu",*(ull)recPtr->r725loal);
    fprintMilliLongTime(fp,"r725loti",recPtr->r725loti,1,TRUE);
    fprintf(fp,",\"r725lcsu\":%llu",*(ull)recPtr->r725lcsu);
    fprintf(fp,",\"r725lcal\":%llu",*(ull)recPtr->r725lcal);
    fprintMilliLongTime(fp,"r725lcti",recPtr->r725lcti,1,TRUE);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR725clod(struct r725clod *clod,short recLen,short count,
                   FILE *fp)
{
  struct r725clod *recPtr;

  fprintf(fp,",\"r725clod\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r725clod *)((void *)clod + i*recLen);
    fprintEbcdicStr(fp,"r725cojn",8,recPtr->r725cojn,TRUE,FALSE);
    fprintf(fp,",\"r725cosp\":%u",recPtr->r725cosp);
    fprintHexString(fp,"r725coas",2,recPtr->r725coas,FALSE,TRUE);
    fprintHexString(fp,"r725cost",8,recPtr->r725cost,FALSE,TRUE);
    fprintEbcdicStr(fp,"r725cosn",8, recPtr->r725cosn,TRUE,TRUE);
    fprintf(fp,",\"r725cosu\":%llu",*(ull)recPtr->r725cosu);
    fprintf(fp,",\"r725coal\":%llu",*(ull)recPtr->r725coal);
    fprintMilliLongTime(fp,"r725coti",recPtr->r725coti,1,TRUE);
    fprintf(fp,",\"r725clsu\":%llu",*(ull)recPtr->r725clsu);
    fprintf(fp,",\"r725clal\":%llu",*(ull)recPtr->r725clal);
    fprintMilliLongTime(fp,"r725clti",recPtr->r725clti,1,TRUE);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR725clrd(struct r725clrd *clrd,short recLen,short count,
                   FILE *fp)
{
  struct r725clrd *recPtr;

  fprintf(fp,",\"r725clrd\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r725clrd *)((void *)clrd + i*recLen);
    fprintEbcdicStr(fp,"r725crjn",8,recPtr->r725crjn,TRUE,FALSE);
    fprintf(fp,",\"r725crsp\":%u",recPtr->r725crsp);
    fprintHexString(fp,"r725cras",2,recPtr->r725cras,FALSE,TRUE);
    fprintHexString(fp,"r725crst",8,recPtr->r725crst,FALSE,TRUE);
    fprintEbcdicStr(fp,"r725crsn",8, recPtr->r725crsn,TRUE,TRUE);
    fprintf(fp,",\"r725crsu\":%llu",*(ull)recPtr->r725crsu);
    fprintf(fp,",\"r725cral\":%llu",*(ull)recPtr->r725cral);
    fprintMilliLongTime(fp,"r725crti",recPtr->r725crti,1,TRUE);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR725latd(struct r725latd *latd,short recLen,short count,
                   FILE *fp)
{
  struct r725latd *recPtr;

  switch (latd->r725laty) {
    case LATCH_CREATOR:
      fprintf(fp,",\"r725lasc\":");
      break;
    case LATCH_REQUESTOR:
      fprintf(fp,",\"r725lare\":");
      break;
    default:
      fprintf(fp,",\"r725latd\":");
      break;
  }
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r725latd *)((void *)latd + i*recLen);
    fprintEbcdicStr(fp,"r725lajn",8, recPtr->r725lajn,TRUE,FALSE);
    fprintf(fp,",\"r725lasp\":%u",recPtr->r725lasp);
    fprintHexString(fp,"r725laas",2,recPtr->r725laas,FALSE,TRUE);
    fprintHexString(fp,"r725last",8,recPtr->r725last,FALSE,TRUE);
    fprintEbcdicStr(fp,"r725lasn",8, recPtr->r725lasn,TRUE,TRUE);
    fprintf(fp,",\"r725laty\":%u",recPtr->r725laty);
    fprintf(fp,",\"r725lasu\":%llu",*(ull)recPtr->r725lasu);
    fprintMilliLongTime(fp,"r725lati",recPtr->r725lati,1,TRUE);
    fprintHexString(fp,"r725lasq",16,recPtr->r725lasq,FALSE,TRUE);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR725entd(struct r725entd *entd,short recLen,short count,
                   FILE *fp)
{
  struct r725entd *recPtr;

  switch (entd->r725ensc) {
    case SCOPE_STEP:
      fprintf(fp,",\"r725ense\":");
      break;
    case SCOPE_SYSTEM:
      fprintf(fp,",\"r725ensy\":");
      break;
    case SCOPE_SYSTEMS:
      fprintf(fp,",\"r725enss\":");
      break;
    default:
      fprintf(fp,",\"r725entd\":");
      break;
  }
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r725entd *)((void *)entd + i*recLen);
    fprintEbcdicStr(fp,"r725enjn",8,recPtr->r725enjn,TRUE,FALSE);
    fprintf(fp,",\"r725ensp\":%u",recPtr->r725ensp);
    fprintHexString(fp,"r725enas",2,recPtr->r725enas,FALSE,TRUE);
    fprintHexString(fp,"r725enst",8,recPtr->r725enst,FALSE,TRUE);
    fprintEbcdicStr(fp,"r725ensn",8, recPtr->r725ensn,TRUE,TRUE);
    fprintf(fp,",\"r725ensc\":%u",recPtr->r725ensc);
    fprintf(fp,",\"r725enrc\":%llu",*(ull)recPtr->r725enrc);
    fprintf(fp,",\"r725ensu\":%llu",*(ull)recPtr->r725ensu);
    fprintMilliLongTime(fp,"r725enti",recPtr->r725enti,1,TRUE);
    fprintHexString(fp,"r725ensq",16,recPtr->r725ensq,FALSE,TRUE);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

void printR725qsad(struct r725qsad *qsad,short recLen,short count,
                   FILE *fp)
{
  struct r725qsad *recPtr;

  fprintf(fp,",\"r725qsad\":");
  if (count > 1)
    fprintf(fp,"[");
  for (short i=0;i < count;i++) {
    if (i > 0)
      fprintf(fp,",{");
    else
      fprintf(fp,"{");
    recPtr=(struct r725qsad *)((void *)qsad + i*recLen);
    fprintEbcdicStr(fp,"r725qsjn",8, recPtr->r725qsjn,TRUE,FALSE);
    fprintf(fp,",\"r725qssp\":%u",recPtr->r725qssp);
    fprintHexString(fp,"r725qsas",2,recPtr->r725qsas,FALSE,TRUE);
    fprintHexString(fp,"r725qsst",8,recPtr->r725qsst,FALSE,TRUE);
    fprintEbcdicStr(fp,"r725qssn",8, recPtr->r725qssn,TRUE,TRUE);
    fprintf(fp,",\"r725qsrc\":%llu",*(ull)recPtr->r725qsrc);
    fprintf(fp,",\"r725qssc\":%llu",*(ull)recPtr->r725qssc);
    fprintf(fp,",\"r725qsrr\":%llu",*(ull)recPtr->r725qsrr);
    fprintHexString(fp,"r725qsrq",16,recPtr->r725qsrq,FALSE,TRUE);
    fprintMilliLongTime(fp,"r725qsti",recPtr->r725qsti,1,TRUE);
    fprintHexString(fp,"r725qstq",16,recPtr->r725qstq,FALSE,TRUE);
    fprintf(fp,"}");
  }
  if (count > 1)
    fprintf(fp,"]");
}

int parse_rec(struct smf72hdr *p,FILE *fp)
{
  struct smf72pro *pro;
  struct r723wms  *wms;
  struct r723sss  *sss;
  struct r723rgs  *rgs;
  struct r723scs  *scs;
  struct r723rts  *rts;
  struct r723wrs  *wrs;
  struct r723dns  *dns;
  struct r724data *data;
  struct r724swre *swre;
  struct r725sctl *sctl;
  struct r725cmsd *cmsd;
  struct r725lotd *lotd;
  struct r725clod *clod;
  struct r725clrd *clrd;
  struct r725latd *latd;
  struct r725entd *entd;
  struct r725qsad *qsad;

  /* SMF Header */
  printSMFHeader(p ,fp);

  if(*(short *)p->smf72prn ==1)
  {
    pro = (struct smf72pro *)((void *)p + *(int *)(p->smf72prs));

    /* Product Section */
    printProdSect(pro, fp);

  }
  switch(*(short *)p->smf72sty) {
    case SMF72ST3:
      if(*(short *)p->smf72wmn > 0) {
        wms = (struct r723wms *)((void *)p + *(int *)(p->smf72wms));
        printR723wms(wms,*(short*)p->smf72wml,*(short*)p->smf72wmn,fp);
      }
      if(*(short *)p->smf72ssn > 0) {
        sss = (struct r723sss *)((void *)p + *(int *)(p->smf72sss));
        printR723sss(sss,*(short*)p->smf72ssl,*(short*)p->smf72ssn,fp);
      }
      if(*(short *)p->smf72rgn > 0) {
        rgs = (struct r723rgs *)((void *)p + *(int *)(p->smf72rgs));
        printR723rgs(rgs,*(short*)p->smf72rgl,*(short*)p->smf72rgn,fp);
      }
      if(*(short *)p->smf72scn > 0) {
        scs = (struct r723scs *)((void *)p + *(int *)(p->smf72scs));
        printR723scs(scs,*(short*)p->smf72scl,*(short*)p->smf72scn,fp);
      }
      if(*(short *)p->smf72rtn > 0) {
        rts = (struct r723rts *)((void *)p + *(int *)(p->smf72rts));
        printR723rts(rts,*(short*)p->smf72rtl,*(short*)p->smf72rtn,fp);
      }
      if(*(short *)p->smf72wrn > 0) {
        wrs = (struct r723wrs *)((void *)p + *(int *)(p->smf72wrs));
        printR723wrs(wrs,*(short*)p->smf72wrl,*(short*)p->smf72wrn,fp);
      }
      if(*(short *)p->smf72dnn > 0) {
        dns = (struct r723dns *)((void *)p + *(int *)(p->smf72dns));
        printR723dns(dns,*(short*)p->smf72dnl,*(short*)p->smf72dnn,fp);
      }
      break;
    case SMF72ST4:
      if(*(short *)p->smf72cpn > 0) {
        data = (struct r724data *)((void *)p + *(int *)(p->smf72cps));
        printR724data(data,*(short*)p->smf72cpl,*(short*)p->smf72cpn,fp);
      }
      if(*(short *)p->smf72spn > 0) {
        swre = (struct r724swre *)((void *)p + *(int *)(p->smf72sps));
        printR724swre(swre,*(short*)p->smf72spl,*(short*)p->smf72spn,fp);
      }
      break;
    case SMF72ST5:
      if(*(short *)p->smf72sen > 0) {
        sctl = (struct r725sctl *)((void *)p + *(int *)(p->smf72ses));
        printR725sctl(sctl,*(short*)p->smf72sel,*(short*)p->smf72sen,fp);
      }
      if(*(short *)p->smf72cmn > 0) {
        cmsd = (struct r725cmsd *)((void *)p + *(int *)(p->smf72cms));
        printR725cmsd(cmsd,*(short*)p->smf72cml,
                           *(short*)p->smf72cmn,fp);
      }
      if(*(short *)p->smf72edn > 0) {
        cmsd = (struct r725cmsd *)((void *)p + *(int *)(p->smf72eds));
        printR725cmsd(cmsd,*(short*)p->smf72edl,
                           *(short*)p->smf72edn,fp);
      }
      if(*(short *)p->smf72lan > 0) {
        cmsd = (struct r725cmsd *)((void *)p + *(int *)(p->smf72las));
        printR725cmsd(cmsd,*(short*)p->smf72lal,
                           *(short*)p->smf72lan,fp);
      }
      if(*(short *)p->smf72smn > 0) {
        cmsd = (struct r725cmsd *)((void *)p + *(int *)(p->smf72sms));
        printR725cmsd(cmsd,*(short*)p->smf72sml,
                           *(short*)p->smf72smn,fp);
      }
      if(*(short *)p->smf72lon > 0) {
        lotd = (struct r725lotd *)((void *)p + *(int *)(p->smf72los));
        printR725lotd(lotd,*(short*)p->smf72lol,
                           *(short*)p->smf72lon,fp);
      }
      if(*(short *)p->smf72con > 0) {
        clod = (struct r725clod *)((void *)p + *(int *)(p->smf72cos));
        printR725clod(clod,*(short*)p->smf72col,
                           *(short*)p->smf72con,fp);
      }
      if(*(short *)p->smf72crn > 0) {
        clrd = (struct r725clrd *)((void *)p + *(int *)(p->smf72crs));
        printR725clrd(clrd,*(short*)p->smf72crl,
                           *(short*)p->smf72crn,fp);
      }
      if(*(short *)p->smf72lcn > 0) {
        latd = (struct r725latd *)((void *)p + *(int *)(p->smf72lcs));
        printR725latd(latd,*(short*)p->smf72lcl,
                           *(short*)p->smf72lcn,fp);
      }
      if(*(short *)p->smf72lrn > 0) {
        latd = (struct r725latd *)((void *)p + *(int *)(p->smf72lrs));
        printR725latd(latd,*(short*)p->smf72lrl,
                           *(short*)p->smf72lrn,fp);
      }
      if(*(short *)p->smf72tdn > 0) {
        entd = (struct r725entd *)((void *)p + *(int *)(p->smf72tds));
        printR725entd(entd,*(short*)p->smf72tdl,
                           *(short*)p->smf72tdn,fp);
      }
      if(*(short *)p->smf72ydn > 0) {
        entd = (struct r725entd *)((void *)p + *(int *)(p->smf72yds));
        printR725entd(entd,*(short*)p->smf72ydl,
                           *(short*)p->smf72ydn,fp);
      }
      if(*(short *)p->smf72sdn > 0) {
        entd = (struct r725entd *)((void *)p + *(int *)(p->smf72sds));
        printR725entd(entd,*(short*)p->smf72sdl,
                           *(short*)p->smf72sdn,fp);
      }
      if(*(short *)p->smf72qsn > 0) {
        qsad = (struct r725qsad *)((void *)p + *(int *)(p->smf72qss));
        printR725qsad(qsad,*(short*)p->smf72qsl,
                           *(short*)p->smf72qsn,fp);
      }
      break;
  }
  return 0;
}

#pragma pack(reset)
