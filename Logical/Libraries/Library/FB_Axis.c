
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void FB_Axis(struct FB_Axis* inst)
{
	handleEncoder(inst);
	handleEndSwitches(inst);
	setPwm(inst);
}

void handleEncoder(struct FB_Axis* inst){
	inst->counter_buffer += inst->counter - inst->last_counter;
	inst->last_counter = inst->counter;
	inst->sdc_enc->iActPos = inst->counter;
	if((inst->sdc_enc->iLifeCnt) % COUNTER_BUFFER_CYCLES == 0){
		inst->speed = (inst->counter_buffer) / (0.002 * COUNTER_BUFFER_CYCLES);
		inst->counter_buffer = 0;
	}
}

void handleEndSwitches(struct FB_Axis* inst){
	inst->sdc_dido->iNegHwEnd = inst->endswitch_a_reached;
	inst->sdc_dido->iPosHwEnd = inst->endswitch_b_reached;
}

void setPwm(struct FB_Axis* inst){
	inst->desired_speed = inst->sdc_drv->oSetPos * UNITS_PER_ROTATION / 32767;
	inst->regulator.e = inst->desired_speed - inst->speed;
	FB_Regulator(&(inst->regulator));
	inst->pwm_value = (inst->regulator.u) / (inst->regulator.max_abs_value) * (inst->pwm_period);
}
