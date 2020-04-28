/*****************************************************
 * Author : Esraa Awad
 * Date*/



typedef struct
{
	u8 jobType;
	u8* DataBuffer;
	u8 Length;
	void (*callBack) (void);


}URTM_JobRequest;



#define URTM_SEND_SYNC 		1
#define URTM_SEND_ASYNCH	2
#define URTM_REC_SYNC	  	3
#define URTM_REC_ASYNCH 	4

extern u8 URTM_u8PerformJobRequest (URTM_JobRequest Copy_jobInfo);
