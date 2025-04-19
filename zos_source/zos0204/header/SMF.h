/* SPDX-License-Identifier: GPL-3.0-only or GPL-3.0-or-later */
/*
 * Header file: Helper functions.
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
#define SECS_100       100
#define MINS_100       6000
#define HOURS_100      360000
#define DAYS_100       8640000
#define SECS_1000      1000
#define MINS_1000      60000
#define HOURS_1000     3600000
#define DAYS_1000      86400000
#define MICS_1000K     1000000
#define SECS_1000K     60000000
#define MINS_1000K     3600000000
#define MICS_4096M     0x1000
#define SECS_4096M     0xF4240000
#define MINS_4096M     0x3938700000ull
#define HOURS_4096M    0xD693A400000ull
#define DAYS_4096M     0x141DD76000000ull
#define CLOCK_UNIT     244
#define MICS_RES       1000000
#define SECS_RES       60
#define MINS_RES       60
#define HOURS_RES      24
#define DAYS_IN_4Y     1461
#define DAYS_IN_YEAR   365
#define DAYS_IN_LYEAR  366
#define FIRST_DAY_IN_LY 1096
#define EPOCH_YEAR     1900
#define EPOCH_YEAR_1970 1970
#define DAYS_IN_JAN    31
#define DAYS_IN_FEB_NLY 28
#define DAYS_IN_FEB_LY 29
#define DAYS_IN_MAR    31
#define DAYS_IN_APR    30
#define DAYS_IN_MAY    31
#define DAYS_IN_JUN    30
#define DAYS_IN_JUL    31
#define DAYS_IN_AUG    31
#define DAYS_IN_SEP    30
#define DAYS_IN_OCT    31
#define DAYS_IN_NOV    30
#define DAYS_IN_DEC    31
#define HEX            1
#define NODELIM        0xEE
#define TRUE           1
#define FALSE          0
#define SMF_REC_MAX_SIZE 32760

typedef unsigned long long * ull;

int getEbcdicStringSize(char *ebcdicString, int maxSize) {
  int index = 0;
  int counter = 0;

  for (counter = maxSize; counter > 0; counter--) {
    index = counter -1;
    if (ebcdicString[index] != 0x40 &&
        ebcdicString[index] != 0x00) {
       break;
     }
  }
  return counter;
}

int getHexStringSize(char *hexString, int maxSize) {
  int index = 0;
  int counter = 0;

  for (counter = maxSize; counter > 0; counter--) {
    index = counter -1;
    if (hexString[index] != 0x00) {
       break;
     }
  }
  return counter;
}

int getVarStringSize(unsigned char *varString,int maxSize,
                     unsigned char delimiter) {
  int counter = 0;
  int index = 0;
  for (counter = maxSize; counter > 0; counter--) {
    index = counter -1;
    if ((varString[index] != delimiter) &&
        (varString[index] != 0x00)) {
       break;
     }
  }
  return counter;
}

void fprintEbcdicStr(FILE *fp,char *fieldName,int length,char *buff,
                     int trim, int isAppend){
  unsigned char *pbuff = (unsigned char*) buff;
  int size = length;

  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName != NULL)
    fprintf(fp,"\"%s\":\"", fieldName);
  else
    fprintf(fp,"\"");

  if (trim == TRUE) {
    size = getEbcdicStringSize(buff, length);
  }

  for (int j=0; j<size; j++) {
    if ( (*(pbuff + j) == 0x7F) || (*(pbuff + j) == 0xE0) ) {
      fprintf(fp, "\\");
    }
    if ( (*(pbuff + j) == 0x40) ||
       ( (*(pbuff + j) >= 0x4A) && (*(pbuff + j) <= 0x50) ) ||
       ( (*(pbuff + j) >= 0x5A) && (*(pbuff + j) <= 0x61) ) ||
       ( (*(pbuff + j) >= 0x6A) && (*(pbuff + j) <= 0x6F) ) ||
       ( (*(pbuff + j) >= 0x79) && (*(pbuff + j) <= 0x7F) ) ||
       ( (*(pbuff + j) >= 0x81) && (*(pbuff + j) <= 0x89) ) ||
       ( (*(pbuff + j) >= 0x91) && (*(pbuff + j) <= 0x99) ) ||
       ( (*(pbuff + j) >= 0xA1) && (*(pbuff + j) <= 0xA9) ) ||
       ( (*(pbuff + j) >= 0xC0) && (*(pbuff + j) <= 0xC9) ) ||
       ( (*(pbuff + j) >= 0xD0) && (*(pbuff + j) <= 0xD9) ) ||
         (*(pbuff + j) == 0xE0) ||
       ( (*(pbuff + j) >= 0xE2) && (*(pbuff + j) <= 0xE9) ) ||
       ( (*(pbuff + j) >= 0xF0) && (*(pbuff + j) <= 0xF9) ) ) {
      fprintf(fp, "%c", *(pbuff + j));
    }
    else {
      printf("Unsupported char in %s: %c\n", fieldName, *(pbuff + j));
    }
  }
  fprintf(fp,"\"");
}

int fprintLong(FILE* fp, char* fieldName, long value, int isAppend)
{
   if (value >= 0) {
     if (isAppend == TRUE) {
       fprintf(fp,",");
     }
     if (fieldName == NULL) {
       fprintf(fp, "%ld", value);
     }
     else {
       fprintf(fp, "\"%s\":%ld",fieldName,value);
     }
   }
   else if (isAppend != TRUE) {
     return 0;
   }
   return 1;
}

unsigned short hex2Int(const unsigned short i)
{
  return i;
}

void fprintByteAsBits(FILE* fp, char val) {
  for (int i=7; 0<=i; i--) {
    fprintf(fp, "%c", (val & (1<<i)) ? '1': '0');
  }
}

void fprintBits(FILE* fp, char *fieldName, unsigned char *bytes,
               size_t num_bytes, int isAppend)
{
  if (isAppend == TRUE)
    fprintf(fp,",");
  fprintf(fp,"\"%s\":\"", fieldName);
  for (size_t i=0; i<num_bytes; i++) {
    fprintByteAsBits(fp,bytes[i]);
  }
  fprintf(fp,"\"");
}

void frompd(char *pd,int len,int *num)
{
  int i,j,n1;
  j=1;
  *num = 0;
  for (i=len-1;i>=0;i--)
  {
    n1 = (i%2) ? pd[i/2] % 16 : pd[i/2] / 16;
    *num += n1*j;
    j*=10;
  }
}

void printHexString(char *fieldName, int length,char *buff,int trim){
  unsigned char *pbuff = (unsigned char*) buff;
  int size = length;

  if (fieldName != NULL)
    printf("\"%s\":\"", fieldName);
  else
    printf("\"");
  if (length > 0)
    printf("0x");

  if (trim == TRUE) {
    size = getHexStringSize(buff, length);
    if (size == 0)
      size = 1;
  }
  for (int j=0; j<size; j++) {
    printf("%2.2X", *(pbuff + j));
  }
  printf("\"");
}

void fprintHexString(FILE *fp,char *fieldName, int length,char *buff,
                     int trim, int isAppend){
  unsigned char *pbuff = (unsigned char*) buff;
  int size = length;

  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName != NULL)
    fprintf(fp,"\"%s\":\"", fieldName);
  else
    fprintf(fp,"\"");
  if (length > 0)
    fprintf(fp,"0x");

  if (trim == TRUE) {
    size = getHexStringSize(buff, length);
    if (size == 0)
      size = 1;
  }

  for (int j=0; j<size; j++) {
    fprintf(fp,"%2.2X", *(pbuff + j));
  }
  fprintf(fp,"\"");
}

void fprintVarString(FILE *fp,char *fieldName,int length,
      unsigned char* buff,unsigned char delimiter,int stringType,
      int isAppend){
  int size = length;

  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName != NULL)
    fprintf(fp,"\"%s\":\"", fieldName);
  else
    fprintf(fp,"\"");

  if (delimiter != NODELIM) {
    size = getVarStringSize(buff, length, delimiter);
    if (size == 0)
      size = 1;
  }

  if (length > 0 && stringType == HEX) {
    fprintf(fp,"0x");

    for (int j=0; j<size; j++) {
      fprintf(fp,"%2.2X", *(buff + j));
    }
  }
  else if (length > 0) {
    fprintf(fp, "%.*s", size, buff); \
  }
  fprintf(fp,"\"");
}

void calcDM(int dayOfTheYear, int isLeapYear,
            int * months, int * dayOfMonth)
{
  if(dayOfTheYear <= DAYS_IN_JAN)
  {
    *months = 1;
    *dayOfMonth = dayOfTheYear;
    return;
  }
  dayOfTheYear -= DAYS_IN_JAN;
  if(isLeapYear)
  {
    if(dayOfTheYear <= DAYS_IN_FEB_LY)
    {
      *months = 2;
      *dayOfMonth = dayOfTheYear;
      return;
    }
    dayOfTheYear -= DAYS_IN_FEB_LY;
  }
  else
  {
    if(dayOfTheYear <= DAYS_IN_FEB_NLY)
    {
      *months = 2;
      *dayOfMonth = dayOfTheYear;
      return;
    }
    dayOfTheYear -= DAYS_IN_FEB_NLY;
  }
  if(dayOfTheYear <= DAYS_IN_MAR)
  {
    *months = 3;
    *dayOfMonth = dayOfTheYear;
    return;
  }
  dayOfTheYear -= DAYS_IN_MAR;

  if(dayOfTheYear <= DAYS_IN_APR)
  {
    *months = 4;
    *dayOfMonth = dayOfTheYear;
    return;
  }
  dayOfTheYear -= DAYS_IN_APR;

  if(dayOfTheYear <= DAYS_IN_MAY)
  {
    *months = 5;
    *dayOfMonth = dayOfTheYear;
    return;
  }
  dayOfTheYear -= DAYS_IN_MAY;

  if(dayOfTheYear <= DAYS_IN_JUN)
  {
    *months = 6;
    *dayOfMonth = dayOfTheYear;
    return;
  }
  dayOfTheYear -= DAYS_IN_JUN;

  if(dayOfTheYear <= DAYS_IN_JUL)
  {
    *months = 7;
    *dayOfMonth = dayOfTheYear;
    return;
  }
  dayOfTheYear -= DAYS_IN_JUL;

  if(dayOfTheYear <= DAYS_IN_AUG)
  {
    *months = 8;
    *dayOfMonth = dayOfTheYear;
    return;
  }
  dayOfTheYear -= DAYS_IN_AUG;

  if(dayOfTheYear <= DAYS_IN_SEP)
  {
    *months = 9;
    *dayOfMonth = dayOfTheYear;
    return;
  }
  dayOfTheYear -= DAYS_IN_SEP;

  if(dayOfTheYear <= DAYS_IN_OCT)
  {
    *months = 10;
    *dayOfMonth = dayOfTheYear;
    return;
  }
  dayOfTheYear -= DAYS_IN_OCT;

  if(dayOfTheYear <= DAYS_IN_NOV)
  {
    *months = 11;
    *dayOfMonth = dayOfTheYear;
    return;
  }
  dayOfTheYear -= DAYS_IN_NOV;

  if(dayOfTheYear <= DAYS_IN_DEC)
  {
    *months = 12;
    *dayOfMonth = dayOfTheYear;
    return;
  }
}

void fprintCentiTime(FILE *fp,char *fieldName, unsigned int time,
                     int isAppend){
  int hours=0;
  int mins=0;
  int secs=0;
  int centis=0;

  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null timestamp value into a formatted string */
  if (time == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"00:00:00.00\"");
    else {
      fprintf(fp,"\"%s\":\"00:00:00.00\"",fieldName);
    }
    return;
  }
  centis = time % SECS_100;
  secs = (time/SECS_100) % SECS_RES;
  mins = (time/MINS_100) % MINS_RES;
  hours = time / HOURS_100;
  if (fieldName == NULL)
    fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%02.2d\"",
      hours, mins, secs, centis);
  else {
    fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%02.2d\"",
      fieldName, hours, mins, secs, centis);
  }
}

void fprintMilliLongTime(FILE *fp,char *fieldName,char * ptime,
                     int multiplier, int isAppend) {
  unsigned long long time = *(ull)ptime;
  int hours=0;
  int mins=0;
  int secs=0;
  int millis=0;
  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null timestamp value into a formatted string */
  if (time == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"00:00:00.000\"");
    else {
      fprintf(fp,"\"%s\":\"00:00:00.000\"",fieldName);
    }
    return;
  }
  time = time * multiplier;
  millis = time % SECS_1000;
  secs = (time/SECS_1000) % SECS_RES;
  mins = (time/MINS_1000) % MINS_RES;
  hours = time / HOURS_1000;
  if (fieldName == NULL)
    fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%03.3d\"",
      hours, mins, secs, millis);
  else {
    fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%03.3d\"",
      fieldName, hours, mins, secs, millis);
  }
}

void fprintMilliFloatTime(FILE *fp,char *fieldName,char * ptime,
                     float multiplier, int isAppend) {
  float ftime = *(float *)ptime;
  int hours=0;
  int mins=0;
  int secs=0;
  int micros = 0;
  unsigned long long time = (unsigned long long)(ftime * multiplier * SECS_1000);
  micros = time % MICS_1000K;
  secs = (time/MICS_1000K) % SECS_RES;
  mins = (time/SECS_1000K) % MINS_RES;
  hours = time / MINS_1000K;
  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL)
    fprintf(fp,"\"%02.2u:%02.2u:%02.2u.%06.6u\"",
      hours, mins, secs, micros);
  else {
    fprintf(fp,"\"%s\":\"%02.2u:%02.2u:%02.2u.%06.6u\"",
      fieldName, hours, mins, secs, micros);
  }
}

void fprintMilliLFloatTime(FILE *fp,char *fieldName,char * ptime,
                     float multiplier, int isAppend) {
  long float ftime = *(long float*)ptime;
  int hours=0;
  int mins=0;
  int secs=0;
  int micros = 0;
  unsigned long long time = (unsigned long long)(ftime * multiplier * SECS_1000);
  micros = time % MICS_1000K;
  secs = (time/MICS_1000K) % SECS_RES;
  mins = (time/SECS_1000K) % MINS_RES;
  hours = time / MINS_1000K;
  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL)
    fprintf(fp,"\"%02.2u:%02.2u:%02.2u.%06.6u\"",
      hours, mins, secs, micros);
  else {
    fprintf(fp,"\"%s\":\"%02.2u:%02.2u:%02.2u.%06.6u\"",
      fieldName, hours, mins, secs, micros);
  }
}

void fprintMilliTime(FILE *fp,char *fieldName,unsigned int time,
                     int multiplier, int isAppend) {
  int hours=0;
  int mins=0;
  int secs=0;
  int millis=0;
  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null timestamp value into a formatted string */
  if (time == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"00:00:00.000\"");
    else {
      fprintf(fp,"\"%s\":\"00:00:00.000\"",fieldName);
    }
    return;
  }
  time = time * multiplier;
  millis = time % SECS_1000;
  secs = (time/SECS_1000) % SECS_RES;
  mins = (time/MINS_1000) % MINS_RES;
  hours = time / HOURS_1000;
  if (fieldName == NULL)
    fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%03.3d\"",
      hours, mins, secs, millis);
  else {
    fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%03.3d\"",
      fieldName, hours, mins, secs, millis);
  }
}

void fprintSecTime(FILE *fp,char *fieldName,unsigned int time,
                     int isAppend) {
  int hours=0;
  int mins=0;
  int secs=0;
  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null timestamp value into a formatted string */
  if (time == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"00:00:00\"");
    else {
      fprintf(fp,"\"%s\":\"00:00:00\"",fieldName);
    }
    return;
  }
  secs = time % SECS_RES;
  mins = (time/SECS_RES) % MINS_RES;
  hours = time / 3600;
  if (fieldName == NULL)
    fprintf(fp,"\"%02.2d:%02.2d:%02.2d\"",
      hours, mins, secs);
  else {
    fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d\"",
      fieldName, hours, mins, secs);
  }
}

void fprintMicsCTime(FILE *fp,char *fieldName,char *dTime,
             int multiplier,int isAppend) {
  unsigned int time = *(int *)dTime;
  int hours=0;
  int mins=0;
  int secs=0;
  int micros=0;
  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null timestamp value into a formatted string */
  if (time == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"00:00:00.000000\"");
    else {
      fprintf(fp,"\"%s\":\"00:00:00.000000\"",fieldName);
    }
    return;
  }
  time = time * multiplier;
  micros = time % MICS_1000K;
  secs = (time/MICS_1000K) % SECS_RES;
  mins = (time/SECS_1000K) % MINS_RES;
  hours = time / MINS_1000K;
  if (fieldName == NULL)
    fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%06.6d\"",
      hours, mins, secs, micros);
  else {
    fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%06.6d\"",
      fieldName, hours, mins, secs, micros);
  }
}

void fprintMicsTime(FILE *fp,char *fieldName,unsigned int time,
             int multiplier,int isAppend) {
  int hours=0;
  int mins=0;
  int secs=0;
  int micros=0;
  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null timestamp value into a formatted string */
  if (time == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"00:00:00.000000\"");
    else {
      fprintf(fp,"\"%s\":\"00:00:00.000000\"",fieldName);
    }
    return;
  }
  time = time * multiplier;
  micros = time % MICS_1000K;
  secs = (time/MICS_1000K) % SECS_RES;
  mins = (time/SECS_1000K) % MINS_RES;
  hours = time / MINS_1000K;
  if (fieldName == NULL)
    fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%06.6d\"",
      hours, mins, secs, micros);
  else {
    fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%06.6d\"",
      fieldName, hours, mins, secs, micros);
  }
}

void fprintMicsLongTime(FILE *fp,char *fieldName,char *dTime,
                        int multiplier, int isAppend) {
  unsigned long long time = *(ull)dTime;
  int days=0;
  int hours=0;
  int mins=0;
  int secs=0;
  int micros=0;
  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null timestamp value into a formatted string */
  if (time == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"00:00:00.000000\"");
    else {
      fprintf(fp,"\"%s\":\"00:00:00.000000\"",fieldName);
    }
    return;
  }
  time *= multiplier;
  micros = time % MICS_1000K;
  secs = (time/MICS_1000K) % SECS_RES;
  mins = (time/SECS_1000K) % MINS_RES;
  hours = time / MINS_1000K;
  if (hours > 23) {
    days = hours / HOURS_RES;
    hours = hours % HOURS_RES;
    if (fieldName == NULL) {
      fprintf(fp,"\"%dD %02.2d:%02.2d:%02.2d.%06.6d\"",
        days, hours, mins, secs, micros);
    }
    else {
      fprintf(fp,"\"%s\":\"%dD %02.2d:%02.2d:%02.2d.%06.6d\"",
        fieldName, days, hours, mins, secs, micros);
    }
  }
  else {
    if (fieldName == NULL)
      fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%06.6d\"",
        hours, mins, secs, micros);
    else {
      fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%06.6d\"",
        fieldName, hours, mins, secs, micros);
    }
  }
}

void fprintMicsFloatTime(FILE *fp,char *fieldName,char *dTime,
                      float multiplier, int isAppend) {
  float fTime = *(float *)dTime;
  int days=0;
  int hours=0;
  int mins=0;
  int secs=0;
  int micros=0;
  unsigned long long time = (unsigned long long)(fTime * multiplier);
  micros = time % MICS_1000K;
  secs = (time/MICS_1000K) % SECS_RES;
  mins = (time/SECS_1000K) % MINS_RES;
  hours = time / MINS_1000K;
  if (isAppend == TRUE)
    fprintf(fp,",");
  if (hours > 23) {
    days = hours / HOURS_RES;
    hours = hours % HOURS_RES;
    if (fieldName == NULL) {
      fprintf(fp,"\"%dD %02.2d:%02.2d:%02.2d.%06.6d\"",
        days, hours, mins, secs, micros);
    }
    else {
      fprintf(fp,"\"%s\":\"%dD %02.2d:%02.2d:%02.2d.%06.6d\"",
        fieldName, days, hours, mins, secs, micros);
    }
  }
  else {
    if (fieldName == NULL)
      fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%06.6d\"",
        hours, mins, secs, micros);
    else {
      fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%06.6d\"",
        fieldName, hours, mins, secs, micros);
    }
  }
}

void fprintMicsLFloatTime(FILE *fp,char *fieldName,char *dTime,
                      float multiplier, int isAppend) {
  long float fTime = *(long float *)dTime;
  int days=0;
  int hours=0;
  int mins=0;
  int secs=0;
  int micros=0;
  unsigned long long time = (unsigned long long)(fTime * multiplier);
  micros = time % MICS_1000K;
  secs = (time/MICS_1000K) % SECS_RES;
  mins = (time/SECS_1000K) % MINS_RES;
  hours = time / MINS_1000K;
  if (isAppend == TRUE)
    fprintf(fp,",");
  if (hours > 23) {
    days = hours / HOURS_RES;
    hours = hours % HOURS_RES;
    if (fieldName == NULL) {
      fprintf(fp,"\"%dD %02.2d:%02.2d:%02.2d.%06.6d\"",
        days, hours, mins, secs, micros);
    }
    else {
      fprintf(fp,"\"%s\":\"%dD %02.2d:%02.2d:%02.2d.%06.6d\"",
        fieldName, days, hours, mins, secs, micros);
    }
  }
  else {
    if (fieldName == NULL)
      fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%06.6d\"",
        hours, mins, secs, micros);
    else {
      fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%06.6d\"",
        fieldName, hours, mins, secs, micros);
    }
  }
}

void fprintPkMilliTime(FILE *fp,char *fieldName,char *timebuff,
                    int isAppend)
{
  int hours=0;
  int mins=0;
  int secs=0;
  int millis=0;
  int time=0;
  frompd(timebuff,7,&time);   /* mmsstttF format */
  mins = time / 100000;
  secs = (time - mins * 100000) / 1000;
  millis = time % 1000;

  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL)
    fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%03.3d\"",hours,mins,secs,millis);
  else {
    fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%03.3d\"",
      fieldName, hours, mins, secs, millis);
  }
}

void fprintPkTime(FILE *fp,char *fieldName,char *timebuff,int isAppend)
{
  int hours=0;
  int mins=0;
  int secs=0;
  int time=0;
  frompd(timebuff,7,&time);   /* 0hhmmssF format */
  hours = time / 10000;
  mins = (time - hours * 10000) / 100;
  secs = time % 100;

  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL)
    fprintf(fp,"\"%02.2d:%02.2d:%02.2d\"",hours,mins,secs);
  else {
    fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d\"",
      fieldName, hours, mins, secs);
  }
}

void fprintPkDateOnly(FILE *fp,char *fieldName,
                     char *datebuff,int isAppend){
  int years = 0;
  int dayOfYear = 0;
  int months = 0;
  int dayOfMonth = 0;
  int isLeapYear = 0;
  frompd(datebuff+1,2,&years);
  frompd(datebuff+2,3,&dayOfYear);
  if (dayOfYear > 0) {
    years += 1900 + (*datebuff)*100;
    if (((years%4==0)&&(years%100!=0)) || (years%400==0))
      isLeapYear = TRUE;
    else
      isLeapYear = FALSE;

    calcDM(dayOfYear, isLeapYear, &months, &dayOfMonth);
  }
  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL)
    fprintf(fp,"\"%4.4d-%02.2d-%02.2d\"",
      years, months, dayOfMonth);
  else {
    fprintf(fp,"\"%s\":\"%4.4d-%02.2d-%02.2d\"",
      fieldName, years, months, dayOfMonth);
  }
}

void fprintPkDate(FILE *fp,char *fieldName,char *timebuff,
                     char *datebuff,int isAppend){
  int years = 0;
  int dayOfYear = 0;
  int months = 0;
  int dayOfMonth = 0;
  int isLeapYear = 0;
  int hours=0;
  int mins=0;
  int secs=0;
  int time=0;
  frompd(timebuff,7,&time);   /* 0hhmmssF format */
  hours = time / 10000;
  mins = (time - hours * 10000) / 100;
  secs = time % 100;
  frompd(datebuff+1,2,&years);
  frompd(datebuff+2,3,&dayOfYear);
  if (dayOfYear > 0) {
    years += 1900 + (*datebuff)*100;
    if (((years%4==0)&&(years%100!=0)) || (years%400==0))
      isLeapYear = TRUE;
    else
      isLeapYear = FALSE;

    calcDM(dayOfYear, isLeapYear, &months, &dayOfMonth);
  }
  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL)
    fprintf(fp,"\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d\"",
      years, months, dayOfMonth, hours, mins, secs);
  else {
    fprintf(fp,"\"%s\":\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d\"",
      fieldName, years, months, dayOfMonth, hours, mins, secs);
  }
}

void fprintPkChTDate(FILE *fp,char *fieldName,char *timebuff,
                     char *datebuff,int isAppend){
  int years = 0;
  int dayOfYear = 0;
  int months = 0;
  int dayOfMonth = 0;
  int isLeapYear = 0;
  int hours=0;
  int mins=0;
  int secs=0;
  int centis=0;
  int time=0;
  time = *(int *)timebuff;
  frompd(datebuff+1,2,&years);
  frompd(datebuff+2,3,&dayOfYear);
  if (dayOfYear > 0) {
    years += 1900 + (*datebuff)*100;
    if (((years%4==0)&&(years%100!=0)) || (years%400==0))
      isLeapYear = TRUE;
    else
      isLeapYear = FALSE;

    calcDM(dayOfYear, isLeapYear, &months, &dayOfMonth);

    centis = time % SECS_100;
    secs = (time/SECS_100) % SECS_RES;
    mins = (time/MINS_100) % MINS_RES;
    hours = time / HOURS_100;
  }
  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL)
    fprintf(fp,"\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%02.2d\"       ",
      years, months, dayOfMonth, hours, mins, secs, centis);
  else {
  fprintf(fp,"\"%s\":\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%02.2d\"",
    fieldName, years, months, dayOfMonth, hours, mins, secs, centis);
  }
}

void fprintPkInTDate(FILE *fp,char *fieldName,int timeT,char *datebuff,
                     int isAppend) {
  int years = 0;
  int months = 0;
  int dayOfMonth =0;
  int dayOfYear = 0;
  int isLeapYear=0;
  int hours=0;
  int mins=0;
  int secs=0;
  int centis=0;
  int time = timeT;

  frompd(datebuff+1,2,&years);
  frompd(datebuff+2,3,&dayOfYear);
  if (dayOfYear > 0) {
    years += 1900 + (*datebuff)*100;
    if (((years%4==0)&&(years%100!=0)) || (years%400==0))
      isLeapYear = TRUE;
    else
      isLeapYear = FALSE;

    calcDM(dayOfYear, isLeapYear, &months, &dayOfMonth);

    centis = time % SECS_100;
    secs = (time/SECS_100) % SECS_RES;
    mins = (time/MINS_100) % MINS_RES;
    hours = time / HOURS_100;
  }
  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL)
    fprintf(fp,"\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%02.2d\"       ",
      years, months, dayOfMonth, hours, mins, secs, centis);
  else {
  fprintf(fp,"\"%s\":\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%02.2d\"",
    fieldName, years, months, dayOfMonth, hours, mins, secs, centis);
  }
}

void fprintPkTimestamp(FILE *fp,char *fieldName,char *tmsbuff,
                     int isAppend) {
  int years = 0;
  int months = 0;
  int dayOfMonth =0;
  int hours=0;
  int mins=0;
  int secs=0;
  int micros=0;

  frompd(tmsbuff,4,&years);
  frompd(tmsbuff+2,2,&months);
  frompd(tmsbuff+3,2,&dayOfMonth);
  frompd(tmsbuff+4,2,&hours);
  frompd(tmsbuff+5,2,&mins);
  frompd(tmsbuff+6,2,&secs);
  frompd(tmsbuff+7,6,&micros);

  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL)
    fprintf(fp,"\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%06.6d\"       ",
      years, months, dayOfMonth, hours, mins, secs, micros);
  else {
  fprintf(fp,"\"%s\":\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%06.6d\"",
    fieldName, years, months, dayOfMonth, hours, mins, secs, micros);
  }
}

void fprintPkDateThTime(FILE *fp,char *fieldName,char *timebuff,
                     char *datebuff,int isAppend){
  int years = 0;
  int dayOfYear = 0;
  int months = 0;
  int dayOfMonth = 0;
  int isLeapYear = 0;
  int hours=0;
  int mins=0;
  int secs=0;
  int ths= 0;
  int time=0;
  frompd(timebuff,2,&hours);   /* hhmmsstt format */
  frompd(timebuff+1,2,&mins);
  frompd(timebuff+2,2,&secs);
  frompd(timebuff+3,2,&ths);
  frompd(datebuff+1,2,&years);
  frompd(datebuff+2,3,&dayOfYear);
  if (dayOfYear > 0) {
    years += 1900 + (*datebuff)*100;
    if (((years%4==0)&&(years%100!=0)) || (years%400==0))
      isLeapYear = TRUE;
    else
      isLeapYear = FALSE;

    calcDM(dayOfYear, isLeapYear, &months, &dayOfMonth);
  }
  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL)
    fprintf(fp,"\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%02.2d\"",
      years, months, dayOfMonth, hours, mins, secs, ths);
  else {
    fprintf(fp,"\"%s\":\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%02.2d\"",
      fieldName, years, months, dayOfMonth, hours, mins, secs, ths);
  }
}

void fprintMilliTimestamp(FILE *fp,char *fieldName,char * ptime,
                     int isAppend) {
  unsigned long long time = *(ull)ptime;
  int hours=0;
  int mins=0;
  int secs=0;
  int millis=0;
  int days,years,numberOfFourYearPeriods;
  int remainingYears, dayOfYear,months,dayOfMonth,temp;

  int isLeapYear = FALSE;

  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null timestamp value into a formatted string */
  if (time == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"0000-00-00 00:00:00\"");
    else {
      fprintf(fp,"\"%s\":\"0000-00-00 00:00:00\"",fieldName);
    }
    return;
  }

  millis = time % SECS_1000;
  secs = (time/SECS_1000) % SECS_RES;
  mins = (time/MINS_1000) % MINS_RES;
  hours = (time/HOURS_1000) % HOURS_RES;
  days = (time/DAYS_1000) + 1;

  if(days <= DAYS_IN_YEAR)
  {
    years = EPOCH_YEAR_1970;
    dayOfYear = days;
  }
  else
  {
    numberOfFourYearPeriods = (days - DAYS_IN_YEAR) / DAYS_IN_4Y;

    temp = (days - DAYS_IN_YEAR) % DAYS_IN_4Y;

    if(temp >= FIRST_DAY_IN_LY)
    {
      numberOfFourYearPeriods++;
      remainingYears = 0;
      isLeapYear = TRUE;
    }
    else
    {
      if(temp % DAYS_IN_YEAR == 0)
      {
        remainingYears = temp / DAYS_IN_YEAR;
      }
      else
      {
       remainingYears = (temp / DAYS_IN_YEAR) + 1;
      }
    }
    years = EPOCH_YEAR_1970 + (numberOfFourYearPeriods * 4)
            + remainingYears;

    dayOfYear = days - DAYS_IN_YEAR;
    dayOfYear -= (numberOfFourYearPeriods * DAYS_IN_4Y);
    dayOfYear -= (remainingYears * DAYS_IN_YEAR);

    if(isLeapYear)
    {
      dayOfYear += DAYS_IN_LYEAR;
    }
    else
    {
      dayOfYear += DAYS_IN_YEAR;
    }
  }
  calcDM(dayOfYear, isLeapYear, &months, &dayOfMonth);

  if (isAppend == TRUE)
    fprintf(fp,",");
  if (fieldName == NULL) {
    fprintf(fp,"\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%03.3d\"",
      years, months, dayOfMonth, hours, mins, secs, millis);
  }
  else {
    fprintf(fp,"\"%s\":\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%03.3d\"",
      fieldName, years, months, dayOfMonth, hours, mins, secs, millis);
  }
  return;
}

void fprintStck4Conv(FILE *fp,const char *fieldName, char *pData,
                    int isAppend) {
  unsigned long long stck = *(unsigned int *)pData;
  stck = stck << 32;
  int secs,mins,hours,days,years,numberOfFourYearPeriods;
  int remainingYears, dayOfYear,months,dayOfMonth,temp;

  int isLeapYear = FALSE;

  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null stck value into a formatted string */
  if (stck == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"0000-00-00 00:00:00\"");
    else {
      fprintf(fp,"\"%s\":\"0000-00-00 00:00:00\"",fieldName);
    }
    return;
  }

  secs = (stck/SECS_4096M) % SECS_RES;
  mins = (stck/MINS_4096M) % MINS_RES;
  hours = (stck/HOURS_4096M) % HOURS_RES;
  days = (stck/DAYS_4096M) + 1;

  if(days <= DAYS_IN_YEAR)
  {
    years = EPOCH_YEAR;
    dayOfYear = days;
  }
  else
  {
    numberOfFourYearPeriods = (days - DAYS_IN_YEAR) / DAYS_IN_4Y;

    temp = (days - DAYS_IN_YEAR) % DAYS_IN_4Y;

    if(temp >= FIRST_DAY_IN_LY)
    {
      numberOfFourYearPeriods++;
      remainingYears = 0;
      isLeapYear = TRUE;
    }
    else
    {
      if(temp % DAYS_IN_YEAR == 0)
      {
        remainingYears = temp / DAYS_IN_YEAR;
      }
      else
      {
       remainingYears = (temp / DAYS_IN_YEAR) + 1;
      }
    }
    years = EPOCH_YEAR + (numberOfFourYearPeriods * 4)
            + remainingYears;

    dayOfYear = days - DAYS_IN_YEAR;
    dayOfYear -= (numberOfFourYearPeriods * DAYS_IN_4Y);
    dayOfYear -= (remainingYears * DAYS_IN_YEAR);

    if(isLeapYear)
    {
      dayOfYear += DAYS_IN_LYEAR;
    }
    else
    {
      dayOfYear += DAYS_IN_YEAR;
    }
  }
  calcDM(dayOfYear, isLeapYear, &months, &dayOfMonth);

  if (fieldName == NULL) {
    fprintf(fp,"\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d\"",
      years, months, dayOfMonth, hours, mins, secs);
  }
  else {
    fprintf(fp,"\"%s\":\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d\"",
      fieldName, years, months, dayOfMonth, hours, mins, secs);
  }
  return;
}

void fprintStckConv(FILE *fp,const char *fieldName, char *pData,
                    int isAppend) {
  unsigned long long stck = *(ull)pData;
  int picos,mics,secs,mins,hours,days,years,numberOfFourYearPeriods;
  int remainingYears, dayOfYear,months,dayOfMonth,temp;

  int isLeapYear = FALSE;

  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null STCK value into a formatted string */
  if (stck == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"0000-00-00 00:00:00.000000\"");
    else {
      fprintf(fp,"\"%s\":\"0000-00-00 00:00:00.000000\"",fieldName);
    }
    return;
  }
  picos = (stck*CLOCK_UNIT) % MICS_RES;
  mics = (stck/MICS_4096M) % MICS_RES;
  secs = (stck/SECS_4096M) % SECS_RES;
  mins = (stck/MINS_4096M) % MINS_RES;
  hours = (stck/HOURS_4096M) % HOURS_RES;
  days = (stck/DAYS_4096M) + 1;

  if(days <= DAYS_IN_YEAR)
  {
    years = EPOCH_YEAR;
    dayOfYear = days;
  }
  else
  {
    numberOfFourYearPeriods = (days - DAYS_IN_YEAR) / DAYS_IN_4Y;

    temp = (days - DAYS_IN_YEAR) % DAYS_IN_4Y;

    if(temp >= FIRST_DAY_IN_LY)
    {
      numberOfFourYearPeriods++;
      remainingYears = 0;
      isLeapYear = TRUE;
    }
    else
    {
      if(temp % DAYS_IN_YEAR == 0)
      {
        remainingYears = temp / DAYS_IN_YEAR;
      }
      else
      {
       remainingYears = (temp / DAYS_IN_YEAR) + 1;
      }
    }
    years = EPOCH_YEAR + (numberOfFourYearPeriods * 4)
            + remainingYears;

    dayOfYear = days - DAYS_IN_YEAR;
    dayOfYear -= (numberOfFourYearPeriods * DAYS_IN_4Y);
    dayOfYear -= (remainingYears * DAYS_IN_YEAR);

    if(isLeapYear)
    {
      dayOfYear += DAYS_IN_LYEAR;
    }
    else
    {
      dayOfYear += DAYS_IN_YEAR;
    }
  }
  calcDM(dayOfYear, isLeapYear, &months, &dayOfMonth);

  if (fieldName == NULL) {
    if (picos == 0)
      fprintf(fp,"\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%06.6d\"",
        years, months, dayOfMonth, hours, mins, secs, mics);
    else
      fprintf(fp,"\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%06.6d%06.6d\"",
        years, months, dayOfMonth, hours, mins, secs, mics,picos);
  }
  else {
    if (picos == 0)
      fprintf(fp,"\"%s\":\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%06.6d\"",
        fieldName, years, months, dayOfMonth, hours, mins, secs, mics);
    else
      fprintf(fp,"\"%s\":\"%4.4d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d.%06.6d%06.6d\"",
        fieldName, years, months, dayOfMonth, hours, mins, secs, mics,picos);
  }
  return;
}

void fprintStckTimeConv(FILE *fp,const char *fieldName, char *pData,
                    int printSign, int isAppend) {
  unsigned long long stck = 0;
  int picos, mics, secs, mins, hours, days;
  signed long long signedStck = *(signed long long *)pData;
  if (signedStck < 0)
    stck = (unsigned long long)llabs(signedStck);
  else
    stck = (unsigned long long)signedStck;

  if (isAppend == TRUE)
    fprintf(fp,",");
  /* Convert a null STCK value into a formatted string */
  if (stck == 0)
  {
    if (fieldName == NULL)
      fprintf(fp,"\"00:00:00.000000\"");
    else {
      fprintf(fp,"\"%s\":\"00:00:00.000000\"",fieldName);
    }
    return;
  }
  picos = (stck * CLOCK_UNIT) % MICS_RES;
  mics = (stck/MICS_4096M) % MICS_RES;
  secs = (stck/SECS_4096M) % SECS_RES;
  mins = (stck/MINS_4096M) % MINS_RES;
  hours = (stck/HOURS_4096M) % HOURS_RES;
  days = (stck/DAYS_4096M) ;

  if (printSign == TRUE){
    if (fieldName == NULL) {
      if (days == 0) {
        if (picos == 0)
          fprintf(fp,"\"%s%02.2d:%02.2d:%02.2d.%06.6d\"",
            signedStck<0 ? "-":"+", hours, mins, secs, mics);
        else
          fprintf(fp,"\"%s%02.2d:%02.2d:%02.2d.%06.6d%06.6d\"",
            signedStck<0 ? "-":"+", hours, mins, secs, mics,picos);
      }
      else {
        if (picos == 0)
          fprintf(fp,"\"%s%dD %02.2d:%02.2d:%02.2d.%06.6d\"",
            signedStck<0 ? "-":"+", days, hours, mins, secs, mics);
        else
          fprintf(fp,"\"%s%dD %02.2d:%02.2d:%02.2d.%06.6d%06.6d\"",
            signedStck<0 ? "-":"+",days,hours,mins,secs,mics,picos);
      }
    }
    else {
      if (days ==0) {
        if (picos == 0)
          fprintf(fp,"\"%s\":\"%s%02.2d:%02.2d:%02.2d.%06.6d\"",
            fieldName,signedStck<0 ? "-":"+",hours,mins,secs,mics);
        else
          fprintf(fp,"\"%s\":\"%s%02.2d:%02.2d:%02.2d.%06.6d%06.6d\"",
            fieldName,signedStck<0 ? "-":"+",hours,mins,secs,mics,picos);
      }
      else {
        if (picos == 0)
          fprintf(fp,"\"%s\":\"%s%dD %02.2d:%02.2d:%02.2d.%06.6d\"",
            fieldName,signedStck<0 ? "-":"+",days,hours,mins,secs,mics);
        else
          fprintf(fp,"\"%s\":\"%s%dD %02.2d:%02.2d:%02.2d.%06.6d%06.6d\"",
            fieldName,signedStck<0 ? "-":"+",days,hours,mins,secs,mics,picos);
      }
    }
  }
  else {
    if (fieldName == NULL) {
      if (days ==0) {
        if (picos == 0)
          fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%06.6d\"",
            hours, mins, secs, mics);
        else
          fprintf(fp,"\"%02.2d:%02.2d:%02.2d.%06.6d%06.6d\"",
            hours, mins, secs, mics,picos);
      }
      else {
        if (picos == 0)
          fprintf(fp,"\"%dD %02.2d:%02.2d:%02.2d.%06.6d\"",
            days, hours, mins, secs, mics);
        else
          fprintf(fp,"\"%dD %02.2d:%02.2d:%02.2d.%06.6d%06.6d\"",
            days, hours, mins, secs, mics,picos);
      }
    }
    else {
      if (days ==0) {
        if (picos == 0)
          fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%06.6d\"",
            fieldName, hours, mins, secs, mics);
        else
          fprintf(fp,"\"%s\":\"%02.2d:%02.2d:%02.2d.%06.6d%06.6d\"",
            fieldName, hours, mins, secs, mics, picos);
      }
      else {
        if (picos == 0)
          fprintf(fp,"\"%s\":\"%dD %02.2d:%02.2d:%02.2d.%06.6d\"",
            fieldName, days, hours, mins, secs, mics);
        else
          fprintf(fp,"\"%s\":\"%dD %02.2d:%02.2d:%02.2d.%06.6d%06.6d\"",
            fieldName, days, hours, mins, secs, mics,picos);
      }
    }
  }
  return;
}

#pragma pack(reset)
