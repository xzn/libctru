#ifndef SHDR_H
#define SHDR_H

typedef enum{
	VERTEX_SHDR=0x0,
	GEOMETRY_SHDR=0x1
}SHDR_type;

typedef enum{
	RESULT_POSITION = 0x0,
	RESULT_COLOR = 0x2,
	RESULT_TEXCOORD0 = 0x3,
	RESULT_TEXCOORD1 = 0x5,
	RESULT_TEXCOORD2 = 0x6
}SHDR_outType;

typedef struct{
	u32 codeSize;
	u32* codeData;
	u32 opdescSize;
	u32* opcdescData;
}DVLP_s;

typedef struct{
	u32 header;
	u32 data[4];
}DVLE_constEntry_s;

typedef struct{
	u32 header;
	u16 type;
	u16 regID;
}DVLE_outEntry_s;

typedef struct{
	SHDR_type type;
	u32 mainOffset, endmainOffset;
	u32 constTableSize;
	DVLE_constEntry_s* constTableData;
	u32 outTableSize;
	DVLE_outEntry_s* outTableData;
}DVLE_s;

typedef struct{
	u32 numDVLE;
	DVLP_s DVLP;
	DVLE_s* DVLE;
}DVLB_s;


DVLB_s* SHDR_ParseSHBIN(u32* shbinData, u32 shbinSize);
void SHDR_FreeDVLB(DVLB_s* dvlb);

void DVLP_SendCode(DVLP_s* dvlp);
void DVLP_SendOpDesc(DVLP_s* dvlp);

void DVLE_SendOutmap(DVLE_s* dvle);

#endif
