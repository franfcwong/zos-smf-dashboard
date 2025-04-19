/* SPDX-License-Identifier: GPL-3.0-only or GPL-3.0-or-later */
/*
 * This program is to convert SMF72 raw data to JSON format.
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
#pragma csect(code, "S072JSON")
#pragma csect(static, "SMF")
#pragma runopts(POSIX(ON))

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "smf.h"
#include "smf72.h"

struct SMFHeader {
    unsigned char SMFLEN[2];
    unsigned char SMFSEG[2];
    unsigned char SMFFLAG;
    unsigned char SMFRECTYPE;
    unsigned char SMFTIME[4];
    unsigned char SMFDATE[4];
    unsigned char SMFSID[4];
    unsigned char SMFSSI[4];
    unsigned char SMFSUBTYPE;
};

int main(void)
{
  FILE *SMFIN,*fout;
  int ret=0;
  unsigned short int recLength = 0;
  unsigned short int blkLength = 0;
  __amrc_type save_amrc;   /* File return code information */

  struct SMFHeader *recbuf;

  int numrec = 0;

  if((SMFIN = fopen("dd:SMFIN","rb,recfm=U,byteseek")) == NULL)
  {
     save_amrc = *__amrc;
     printf(" Error opening SMFIN ");
     printf(" %s \n", strerror(errno)); /* text of the errno */
     printf(" fopen errno=%d lastop=%d syscode=%X rc=%d\n", errno,
              save_amrc.__last_op,
              save_amrc.__code.__abend.__syscode,
              save_amrc.__code.__abend.__rc);
     return 1;
  }

  if((fout = fopen("dd:JSOUT", "wb")) == NULL)
  {
     save_amrc = *__amrc;
     printf(" Error opening JSOUT ");
     printf(" %s \n", strerror(errno)); /* text of the errno */
     printf(" fopen errno=%d lastop=%d syscode=%X rc=%d\n", errno,
              save_amrc.__last_op,
              save_amrc.__code.__abend.__syscode,
              save_amrc.__code.__abend.__rc);
     fclose(SMFIN); return 2;
  }

  if((recbuf=__malloc31(SMF_REC_MAX_SIZE))==NULL)
  {
     printf("Failed to allocate memory\n");
     fclose(SMFIN); fclose(fout); return -1;
  }

  fread(&blkLength,2,1,SMFIN);
  printf("Block Length: %d\n", blkLength);
  fseek(SMFIN, 2, SEEK_CUR);
  fprintf(fout,"[");

  while(!feof(SMFIN))
  {
     fread(&recLength,2,1,SMFIN);

     fseek(SMFIN, -2, SEEK_CUR);

     memset(recbuf,0,sizeof(SMF_REC_MAX_SIZE));

     if((ret=fread(recbuf,recLength,1,SMFIN))>0)
     {
       if(TARGET_SMF_TYPE == recbuf->SMFRECTYPE)
       {
         numrec += 1;
         /* Handle SMF header */
         if (numrec == 1)
           fprintf(fout,"{");
         else
           fprintf(fout,",{");
        /* fprintf(fout,"\n{"); */

         if((ret=parse_rec((void*)recbuf,fout))==0)
         {
           fprintf(fout, "}");
         }
         else
         {
          printf("ERR::%s %4d parse error %d\\n",
                 __FILE__,__LINE__,ret);
          break;
         }
       }
       else
       {
         printf("Other Type: %d\n ",recbuf->SMFRECTYPE);
       }
       blkLength -= recLength;
       if(blkLength<= 4)
       {
          fread(&blkLength,2,1,SMFIN);
          fseek(SMFIN, 2, SEEK_CUR);
       }
     }
     else
     {
       break;
     }
  }
  fprintf(fout,"]");
  printf("Total number of records written = %d.\n",numrec);
  free(recbuf);fclose(fout); fclose(SMFIN);
  return ret;
}

