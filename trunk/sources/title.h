#ifndef _TITLE_H_
#define _TITLE_H_
#include <gctypes.h>
#include <ogc/es.h>
u8 *getContentCryptParameter(u8 *chCryptParameter,u16 intTmdModuleId);
void decryptContent(u8 *chCryptParameter, u8 *chEncryptedBuffer, u8 *chDecryptedBuffer,u32 intContentSize);
void encryptContent(u8 *chCryptParameter,u8 *chDecryptedBuffer,u8 *chEncryptedBuffer,u32 intContentSize);
s32 installTmdContent(tmd *pTmd,u16 intTmdModuleId,const char *strNandContentLocation);
u8 *getTitleKey(signed_blob *sTik,u8 *key);
void changeTicketTitleId(signed_blob *sTik,u32 intMajorTitleId,u32 intMinorTitleId);
void changeTmdTitleId(signed_blob *sTmd,u32 intMajorTitleId,u32 intMinorTitleId);
void setZeroSignature(signed_blob *sSig);
void bruteTmd(tmd *pTmd);
void bruteTicket(tik *pTik);
void forgeTmd(signed_blob *sTmd);
void forgeTicket(signed_blob *sTik);
s32 installTicket(const signed_blob *sTik, const signed_blob *sCerts,u32 intCertsSize,const signed_blob *sCrl,u32 intCrlsize);
s32 installTmdContents(const signed_blob *sTmd,const signed_blob *sCerts,u32 intCertsSize,const signed_blob *sCrl,u32 intCrlsize,const char *strNandContentLocation,bool blnProgressBar);
u64 *getTitles(u32 *intTitlesCount);
u8 getSlotsMap(u8 *intSlotsMap);
#endif