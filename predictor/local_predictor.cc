
#include "local_predictor.h"

Local_predictor::Local_predictor(){
	for(count=0;count<LOCAL_PREDICTOR_SIZE;count++){
		local_predictor_table[count] = WEAKLY_NOT_TAKEN_3b;
	}
}
Local_predictor::~Local_predictor(){

}
/********************** returns the predicted values *****************************/
bool Local_predictor::get_local_prediction(const branch_record_c* br_obj){
	unsigned int temp_address = br_obj->instruction_addr;
	if(DEBUG)
		printf("Prediction State in local history : %d \n", local_predictor_table[mask(temp_address,LOCAL_HISTORY_MASK_9_0)]);
	return check(local_predictor_table[mask(temp_address,LOCAL_HISTORY_MASK_9_0)],2);
}

/************************ update the local history ***********************************************/
void Local_predictor::update_local_predictor(const branch_record_c* br_obj,bool taken){
	unsigned int temp_address = br_obj->instruction_addr;
	unsigned int result = mask(temp_address,LOCAL_HISTORY_MASK_9_0);
	char predictionState = local_predictor_table[result];
	if(taken){
		if(predictionState < MAX_COUNTER_VAL_3b)
			predictionState++;
	}
	else{
		if(predictionState > MIN_COUNTER_VAL_3b)
			predictionState--;
	}
	if(DEBUG)
		printf("Updated prediction State of local history at %d is %d\n",temp_address,predictionState);
	local_predictor_table[result] = predictionState;
}
