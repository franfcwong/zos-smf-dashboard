//*
//*        Compile and Linkedit job for C program
//*
//PROCS    JCLLIB ORDER=(CBC.SCCNPRC)                                   
//DOCLG    EXEC  PROC=EDCQCB,                                           
//         INFILE='<your C program source library(member)>',            
//         OUTFILE='<your program loadlib(member)>,DISP=SHR',
//         CPARM='OPTFILE(DD:OPTIONS)'                   
//OPTIONS  DD  *
  LONGNAME FLOAT(HEX)
  LANGLVL(EXTENDED) sscom dll
  DEFINE(_ALL_SOURCE)
  SEARCH(//'<your C header file library>')
/*
//COMPILE.SYSLIN DD DISP=SHR,DSN=<your object lib(member)>
//BIND.SYSLIB  DD DISP=SHR,DSN=CEE.SCEEBND2
//             DD DISP=SHR,DSN=<your object lib(member)>
//BIND.SYSLIN  DD DSN=CEE.SCEELIB(CELQS003),DISP=SHR
//BIND.SYSIN   DD *
  ENTRY CELQSTRT
  INCLUDE SYSLIB(<member>)
  NAME <member>(R)
//
