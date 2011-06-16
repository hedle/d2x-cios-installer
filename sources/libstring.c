#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "libmath.h"
#include "libmatrice.h"
char **getSplitStrings(const char *strValue,const char *strSeparator,unsigned int *intItemsCount) {
size_t intSeparatorSize=strlen(strSeparator),intSplitStringSize;
char **varout=NULL,*pPreviousOffset,*pCurrentOffset;
unsigned int intSplitItemsCount=0;
    pPreviousOffset=(char *) &strValue[0];
    if (*intItemsCount) {
        if ((varout=(char **) malloc(*intItemsCount*sizeof(char *)))!=NULL) {
            while (((pCurrentOffset=strstr(pPreviousOffset,strSeparator))!=NULL) && (intSplitItemsCount<*intItemsCount)) {
                intSplitStringSize=pCurrentOffset-pPreviousOffset;
                varout[intSplitItemsCount]=getCharsVector(intSplitStringSize+1,0);
                memcpy(varout[intSplitItemsCount],pPreviousOffset,intSplitStringSize);
                pPreviousOffset=pCurrentOffset+intSeparatorSize;
                intSplitItemsCount++;
            }
            if (intSplitItemsCount<*intItemsCount) {
                varout[intSplitItemsCount]=strdup(pPreviousOffset);
                *intItemsCount=intSplitItemsCount+1;
                varout=(char **) realloc(varout,*intItemsCount*sizeof(char *));
            }
        }
    }
    return varout;
}
char *getBreakString(const char *strValue,const char chBreakChar,size_t intMaxStringSize) {
char *varout=NULL,*chLastSpace;
    if ((strlen(strValue)>intMaxStringSize) && (intMaxStringSize)) {
        varout=getCharsVector(intMaxStringSize+1,0);
        varout=strncpy(varout,strValue,intMaxStringSize);
        if (strValue[intMaxStringSize]!=' ') {
            if ((chLastSpace=strrchr(varout,chBreakChar))!=NULL) {
                memset((void *) chLastSpace,0,1);
                varout=(char *) realloc((void *) varout,chLastSpace-&varout[0]+1);
            }
        }
    }
    else {
        varout=strdup(strValue);
    }
    return varout;
}
char **getBreakStrings(const char *strValue,const char chBreakChar,size_t intMaxLineSize,unsigned int *intBreakStringsCount) {
char **varout=NULL;
char *chCurrentOffset;
unsigned int intItemsCount=0;
    if (*intBreakStringsCount) {
        if ((varout=(char **) malloc(*intBreakStringsCount*sizeof(char *)))!=NULL) {
            chCurrentOffset=(char *) &strValue[0];
            while ((strlen(chCurrentOffset)) && (intItemsCount<*intBreakStringsCount)) {
                varout[intItemsCount]=getBreakString(chCurrentOffset,chBreakChar,intMaxLineSize);
                chCurrentOffset=chCurrentOffset+strlen(varout[intItemsCount]);
                intItemsCount++;
                if (*chCurrentOffset==chBreakChar) {
                    chCurrentOffset=chCurrentOffset+1;
                }
            }
            if (intItemsCount<*intBreakStringsCount) {
                *intBreakStringsCount=intItemsCount;
                varout=(char **) realloc(varout,intItemsCount*sizeof(char *));
            }
        }
    }
    return varout;
}
unsigned int getLinesCount(const char *strValue,unsigned int *intMaxLineSize) {
unsigned int varout=0;
char *pCurrentOffset,*pPreviousOffset;
    *intMaxLineSize=0;
    pPreviousOffset=(char *) &strValue[0];
    while ((pCurrentOffset=strstr(pPreviousOffset,"\n"))!=NULL) {
        varout++;
        *intMaxLineSize=getMaxValue(*intMaxLineSize,pCurrentOffset-pPreviousOffset);
        pPreviousOffset=pCurrentOffset+1;
    }
    *intMaxLineSize=getMaxValue(*intMaxLineSize,strlen(pPreviousOffset));
    return varout+1;
}
